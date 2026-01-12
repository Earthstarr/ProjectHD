// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapon/Projectile/HDRocketProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTHD_HDRocketProjectile_generated_h
#error "HDRocketProjectile.generated.h already included, missing '#pragma once' in HDRocketProjectile.h"
#endif
#define PROJECTHD_HDRocketProjectile_generated_h

#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHDRocketProjectile(); \
	friend struct Z_Construct_UClass_AHDRocketProjectile_Statics; \
public: \
	DECLARE_CLASS(AHDRocketProjectile, AHDProjectile, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AHDRocketProjectile)


#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AHDRocketProjectile(AHDRocketProjectile&&); \
	AHDRocketProjectile(const AHDRocketProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHDRocketProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHDRocketProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHDRocketProjectile) \
	NO_API virtual ~AHDRocketProjectile();


#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_7_PROLOG
#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_10_INCLASS_NO_PURE_DECLS \
	FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AHDRocketProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
