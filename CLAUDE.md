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

Mission/        # AMissionManager, AMissionBase, AEggDestructionMission
Spawn/          # AEnemyPoolManager, AEnemySpawnManager, ASpawnZone
Effect/         # 카메라 쉐이크
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

### 주요 인터페이스

- `IAbilitySystemInterface` - 플레이어 GAS 통합
- `IInteractableInterface` - 보급 포드 등 상호작용

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
