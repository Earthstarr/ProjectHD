// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraShake_Fire.h"

UCameraShake_Fire::UCameraShake_Fire()
{
    // 1. 기본 설정값 초기화 (에디터에서 보일 기본값)
    ShakeDuration = 0.15f;
    ShakeFrequency = 25.0f;

    RotShakeIntensityPitch = 1.5f;
    RotShakeIntensityYaw = 0.8f;
    LocShakeIntensityZ = 1.0f;
    
    // 2. 부모 클래스(Legacy)의 변수에 내가 만든 변수들을 연결
    OscillationDuration = ShakeDuration;
    OscillationBlendInTime = 0.05f;
    OscillationBlendOutTime = 0.1f;

    // 회전 흔들림 연결
    RotOscillation.Pitch.Amplitude = RotShakeIntensityPitch;
    RotOscillation.Pitch.Frequency = ShakeFrequency;

    RotOscillation.Yaw.Amplitude = RotShakeIntensityYaw;
    RotOscillation.Yaw.Frequency = ShakeFrequency;

    // 위치 흔들림 연결
    LocOscillation.Z.Amplitude = LocShakeIntensityZ;
    LocOscillation.Z.Frequency = ShakeFrequency;
    
}
