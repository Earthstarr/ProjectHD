// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapon/Stratagem/StratagemBeacon.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PROJECTHD_StratagemBeacon_generated_h
#error "StratagemBeacon.generated.h already included, missing '#pragma once' in StratagemBeacon.h"
#endif
#define PROJECTHD_StratagemBeacon_generated_h

#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAStratagemBeacon(); \
	friend struct Z_Construct_UClass_AStratagemBeacon_Statics; \
public: \
	DECLARE_CLASS(AStratagemBeacon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AStratagemBeacon)


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AStratagemBeacon(AStratagemBeacon&&); \
	AStratagemBeacon(const AStratagemBeacon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AStratagemBeacon); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AStratagemBeacon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AStratagemBeacon) \
	NO_API virtual ~AStratagemBeacon();


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_11_PROLOG
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_14_INCLASS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AStratagemBeacon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
