// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapon/WeaponDataAsset.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTHD_WeaponDataAsset_generated_h
#error "WeaponDataAsset.generated.h already included, missing '#pragma once' in WeaponDataAsset.h"
#endif
#define PROJECTHD_WeaponDataAsset_generated_h

#define FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWeaponDataAsset(); \
	friend struct Z_Construct_UClass_UWeaponDataAsset_Statics; \
public: \
	DECLARE_CLASS(UWeaponDataAsset, UDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(UWeaponDataAsset)


#define FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWeaponDataAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UWeaponDataAsset(UWeaponDataAsset&&); \
	UWeaponDataAsset(const UWeaponDataAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWeaponDataAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWeaponDataAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWeaponDataAsset) \
	NO_API virtual ~UWeaponDataAsset();


#define FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_17_PROLOG
#define FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_20_INCLASS_NO_PURE_DECLS \
	FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class UWeaponDataAsset>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
