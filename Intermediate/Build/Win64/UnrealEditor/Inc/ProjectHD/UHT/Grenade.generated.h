// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapon/Grenade.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTHD_Grenade_generated_h
#error "Grenade.generated.h already included, missing '#pragma once' in Grenade.h"
#endif
#define PROJECTHD_Grenade_generated_h

#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExplode);


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGrenade(); \
	friend struct Z_Construct_UClass_AGrenade_Statics; \
public: \
	DECLARE_CLASS(AGrenade, AHDProjectile, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AGrenade)


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AGrenade(AGrenade&&); \
	AGrenade(const AGrenade&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGrenade); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGrenade); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGrenade) \
	NO_API virtual ~AGrenade();


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_12_PROLOG
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_15_INCLASS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AGrenade>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
