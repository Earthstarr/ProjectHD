// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/Player/FPSCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWeaponDataAsset;
enum class EStratagemDirection : uint8;
#ifdef PROJECTHD_FPSCharacter_generated_h
#error "FPSCharacter.generated.h already included, missing '#pragma once' in FPSCharacter.h"
#endif
#define PROJECTHD_FPSCharacter_generated_h

#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStratagemData_Statics; \
	PROJECTHD_API static class UScriptStruct* StaticStruct();


template<> PROJECTHD_API UScriptStruct* StaticStruct<struct FStratagemData>();

#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_71_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWeaponInstance_Statics; \
	PROJECTHD_API static class UScriptStruct* StaticStruct();


template<> PROJECTHD_API UScriptStruct* StaticStruct<struct FWeaponInstance>();

#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_107_DELEGATE \
PROJECTHD_API void FOnAmmoChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnAmmoChangedSignature, int32 NewAmmo, int32 NewMag, int32 MaxMag);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_108_DELEGATE \
PROJECTHD_API void FOnHitEnemySignature_DelegateWrapper(const FMulticastScriptDelegate& OnHitEnemySignature, bool bIsHeadshot);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_109_DELEGATE \
PROJECTHD_API void FOnStratagemStepUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnStratagemStepUpdated, int32 NewStep);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_110_DELEGATE \
PROJECTHD_API void FOnStratagemUpdate_DelegateWrapper(const FMulticastScriptDelegate& OnStratagemUpdate, int32 StratagemIndex, int32 CurrentStep);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_111_DELEGATE \
PROJECTHD_API void FOnStratagemStackUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnStratagemStackUpdated, TArray<EStratagemDirection> const& InputStack);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_112_DELEGATE \
PROJECTHD_API void FOnAttributeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAttributeChanged, float CurrentValue, float MaxValue);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_113_DELEGATE \
PROJECTHD_API void FOnGrenadeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnGrenadeChanged, int32 Current, int32 Max);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_114_DELEGATE \
PROJECTHD_API void FOnStimChanged_DelegateWrapper(const FMulticastScriptDelegate& OnStimChanged, int32 CurrentCount, int32 MaxCount);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSwitchWeapon); \
	DECLARE_FUNCTION(execFireWeapon); \
	DECLARE_FUNCTION(execOnAimCompleted); \
	DECLARE_FUNCTION(execOnAimStarted); \
	DECLARE_FUNCTION(execFinishReload); \
	DECLARE_FUNCTION(execEquipWeapon); \
	DECLARE_FUNCTION(execOnGrenadeCompleted); \
	DECLARE_FUNCTION(execApplyStimEffect); \
	DECLARE_FUNCTION(execOnStimCompleted);


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_CALLBACK_WRAPPERS
#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSCharacter(); \
	friend struct Z_Construct_UClass_AFPSCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AFPSCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<AFPSCharacter*>(this); }


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AFPSCharacter(AFPSCharacter&&); \
	AFPSCharacter(const AFPSCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSCharacter) \
	NO_API virtual ~AFPSCharacter();


#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_116_PROLOG
#define FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_CALLBACK_WRAPPERS \
	FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_INCLASS_NO_PURE_DECLS \
	FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_119_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AFPSCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h


#define FOREACH_ENUM_ESTRATAGEMDIRECTION(op) \
	op(EStratagemDirection::None) \
	op(EStratagemDirection::Up) \
	op(EStratagemDirection::Down) \
	op(EStratagemDirection::Left) \
	op(EStratagemDirection::Right) 

enum class EStratagemDirection : uint8;
template<> struct TIsUEnumClass<EStratagemDirection> { enum { Value = true }; };
template<> PROJECTHD_API UEnum* StaticEnum<EStratagemDirection>();

#define FOREACH_ENUM_ESTRATAGEMTYPE(op) \
	op(EStratagemType::Bomb500kg) \
	op(EStratagemType::Supply) \
	op(EStratagemType::EagleCluster) \
	op(EStratagemType::Sentry) 

enum class EStratagemType : uint8;
template<> struct TIsUEnumClass<EStratagemType> { enum { Value = true }; };
template<> PROJECTHD_API UEnum* StaticEnum<EStratagemType>();

#define FOREACH_ENUM_EABILITYINPUTID(op) \
	op(EAbilityInputID::None) \
	op(EAbilityInputID::Confirm) \
	op(EAbilityInputID::Cancel) \
	op(EAbilityInputID::Aim) \
	op(EAbilityInputID::Fire) \
	op(EAbilityInputID::Reload) \
	op(EAbilityInputID::Jump) \
	op(EAbilityInputID::Sprint) \
	op(EAbilityInputID::Grenade) 

enum class EAbilityInputID : uint8;
template<> struct TIsUEnumClass<EAbilityInputID> { enum { Value = true }; };
template<> PROJECTHD_API UEnum* StaticEnum<EAbilityInputID>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
