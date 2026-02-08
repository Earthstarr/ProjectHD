# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

ProjectHD는 UE 5.6 기반 TPS 전술 슈터 게임. 스트라타젬 시스템으로 궤도 지원을 호출하여 미션 수행.

## Build Commands

```bash
# 프로젝트 파일 생성 (Windows)
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\GenerateProjectFiles.bat" ProjectHD.uproject

# Development 빌드
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat" ProjectHD Win64 Development
```

## Architecture

### 모듈 구조: `Source/ProjectHD/`

```
Character/
├── Player/     # AFPSCharacter, APodActor (리스폰 포드)
└── Enemy/      # AEnemyBase, Crawler, Siren, Chimera, EggActor

Weapon/
├── Stratagem/  # AStratagemBeacon, AEagle, AHDSentry, AOrbitalLaser, AHDSupplyPod
└── Projectile/ # HDProjectile, HDBombProjectile, HDRocketProjectile

Mission/        # AMissionManager, AMissionBase, AEggDestructionMission, ADataLinkMission, ADataLinkTerminal, AExtractionTerminal, AExtractionShip, AIntroCutsceneManager, ACinematicPod
Spawn/          # AEnemyPoolManager, AEnemySpawnManager, ASpawnZone
Effect/         # 카메라 쉐이크
Core/           # UHDGameInstance (BGM 관리, 레벨 전환 플래그)
(Root)          # ALevelTransitionTrigger (레벨 전환 트리거)
```

### 핵심 시스템

**AFPSCharacter** (`Character/Player/FPSCharacter.h`)
- GAS (Gameplay Ability System) 통합
- 3슬롯 무기 인벤토리 (`UWeaponDataAsset`)
- 스트라타젬 입력: 방향키 커맨드 시퀀스 (`FStratagemData`)
- `UPlayerAttributeSet`으로 Health/Stamina 관리

**스트라타젬** (`Weapon/Stratagem/`)
- `EStratagemType`: Bomb500kg, Supply, EagleCluster, OrbitalLaser, Sentry, Rearm
- `AStratagemBeacon` - 비콘 투척 후 딜레이 후 스트라이크 발동
- 쿨다운/스택 관리

**적 시스템** (`Character/Enemy/`)
- `AEnemyBase` - 체력, 데미지, 사망 처리, 풀 통합
- 적 타입: Crawler(근접), Siren, Chimera
- `AEggActor` - 파괴 가능한 미션 타겟

**스폰 시스템** (`Spawn/`)
- `AEnemyPoolManager` - 오브젝트 풀링
- `AEnemySpawnManager` - 패트롤 스폰 (30초 간격, 플레이어 8000 유닛 거리)
- `ASpawnZone` - MissionArea 또는 PatrolRoute

**미션 시스템** (`Mission/`)
- `AMissionManager` - 미션 등록/완료 추적
- 상태: NotStarted, InProgress, Completed, Failed

**컷씬 시스템** (`Mission/`)

*인트로 컷씬:*
- `AIntroCutsceneManager` - 레벨 시퀀서 재생, 워밍업 에셋 프리로드
- `ACinematicPod` - 컷씬용 낙하 포드 (Tick에서 Z축 하강, 나이아가라 궤적)
- 흐름: BeginPlay → 플레이어 숨김 → 시퀀서 재생 → 완료 시 `Player->SpawnWithPod()`

*탈출 컷씬:*
- `AExtractionTerminal` - 모든 미션 완료 시 활성화, 커맨드 입력 → 방어전(150초) → 수송선 호출
- `AExtractionShip` - 비행 상태머신 (Arriving → Landing → Waiting → Departing → Gone)
- 흐름: 방어전 완료 → 수송선 도착 → 플레이어 탑승(오버랩) → 탈출 컷씬 → 결과 화면
- `EaseInOutCubic()` 보간으로 부드러운 비행

### 주요 인터페이스

- `IAbilitySystemInterface` - 플레이어 GAS 통합
- `IInteractableInterface` - 보급 포드 등 상호작용

### 로딩 최적화 (`AIntroCutsceneManager`)

**Preload vs Warmup 차이**
| 구분 | Preload (TSoftPtr) | Warmup (하드 레퍼런스) |
|------|-------------------|----------------------|
| 동작 | 메모리에 비동기 로드 | 실제 스폰/재생 |
| 효과 | 디스크 I/O 방지 | 셰이더 컴파일, 디코딩 완료 |
| 에디터 | 이미 로드된 경우 즉시 완료 | 항상 효과 있음 |

**에셋 타입별 권장 방법**
| 에셋 | 권장 배열 | 비고 |
|------|----------|------|
| Actor/BP | `PreloadActorClasses` + `WarmupActorClasses` | 둘 다 사용 |
| Niagara | `WarmupNiagaraSystems`만 | GPU 셰이더 컴파일 필요 |
| Sound | `WarmupSounds`만 | 볼륨 0 재생으로 디코딩 |
| Material | `PreloadMiscAssets` | 안전하게 프리로드 가능 |
| SkeletalMesh | **직접 프리로드 금지** | MeshBuilder 크래시, BP로 대체 |

**흐름**
```
BeginPlay → 플레이어 숨김 → StartAsyncPreload()
    → OnPreloadComplete() → StartCutscene()
    → SpawnWarmupActors() (실제 워밍업) → 시퀀서 재생
```

**Unreal Insights 사용법**
```bash
# 콘솔에서
trace.start default,cpu,gpu,frame,loadtime
# 렉 구간 플레이 후
trace.stop
# UnrealInsights.exe로 Saved/Profiling/*.utrace 파일 분석
```

## Branch Strategy

| 브랜치 | 용도 |
|--------|------|
| main | 안정 버전 |
| feature/* | 기능 개발 |

## Commit Convention

```
feat:     새로운 기능
fix:      버그 수정
asset:    에셋 추가/수정
refactor: 코드 정리
docs:     문서 수정
chore:    설정 등 기타
```

## Claude 지시사항

- 새로운 기능 구현 완료 시 "진행 상황" 섹션 업데이트할 것
- 중요한 아키텍처 변경이나 새 클래스 추가 시 "Architecture" 섹션도 업데이트할 것
- 버그 수정이나 작은 변경은 기록 불필요

## 진행 상황

- 2026-02-07: 로딩 최적화 시스템 구현 (`IntroCutsceneManager` 비동기 프리로드, Warmup 배열)
- 2026-02-05: 컷씬 시스템 아키텍처 정리 (`IntroCutsceneManager`, `CinematicPod`, `ExtractionTerminal`, `ExtractionShip`)
- 2026-02-03: 레벨 전환 트리거 및 POD 강하 스폰 시스템 (`LevelTransitionTrigger`, `SpawnWithPod`)
- 2026-02-02: 데이터 링크 미션 구현 (`DataLinkMission`, `DataLinkTerminal`)
- 2026-02-02: `HDGameInstance` 추가 (BGM 관리)
- 2026-02-02: 미션 클리어 자막/소리, 밸런스 조정
- 2026-02-02: 탈출 터미널 시스템 구현 (`ExtractionTerminal`) - 모든 미션 완료 시 활성화, 3분 방어전
