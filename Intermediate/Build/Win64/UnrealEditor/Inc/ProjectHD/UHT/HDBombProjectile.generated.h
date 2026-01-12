// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapon/Projectile/HDBombProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTHD_HDBombProjectile_generated_h
#error "HDBombProjectile.generated.h already included, missing '#pragma once' in HDBombProjectile.h"
#endif
#define PROJECTHD_HDBombProjectile_generated_h

#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHDBombProjectile(); \
	friend struct Z_Construct_UClass_AHDBombProjectile_Statics; \
public: \
	DECLARE_CLASS(AHDBombProjectile, AHDProjectile, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AHDBombProjectile)


#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AHDBombProjectile(AHDBombProjectile&&); \
	AHDBombProjectile(const AHDBombProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHDBombProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHDBombProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHDBombProjectile) \
	NO_API virtual ~AHDBombProjectile();


#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_9_PROLOG
#define FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_12_INCLASS_NO_PURE_DECLS \
	FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AHDBombProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
