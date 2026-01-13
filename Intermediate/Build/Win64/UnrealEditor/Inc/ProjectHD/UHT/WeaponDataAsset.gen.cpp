// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/WeaponDataAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponDataAsset() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDProjectile_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_UWeaponDataAsset();
PROJECTHD_API UClass* Z_Construct_UClass_UWeaponDataAsset_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class UWeaponDataAsset
void UWeaponDataAsset::StaticRegisterNativesUWeaponDataAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWeaponDataAsset);
UClass* Z_Construct_UClass_UWeaponDataAsset_NoRegister()
{
	return UWeaponDataAsset::StaticClass();
}
struct Z_Construct_UClass_UWeaponDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Weapon/WeaponDataAsset.h" },
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponMesh_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MuzzleFlashFX_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xde\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xde\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireAbility_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- GAS \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- GAS \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadAbility_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xbc\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimAbility_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xbc\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecoilPitch_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecoilYaw_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xb7\xef\xbf\xbd \xef\xbf\xbd\xdd\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa1\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xb7\xef\xbf\xbd \xef\xbf\xbd\xdd\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa1" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmoInMag_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xc2\xbf\xef\xbf\xbd \xef\xbf\xbd\xdd\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa1\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc2\xbf\xef\xbf\xbd \xef\xbf\xbd\xdd\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa1" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMag_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xc5\xba\xc3\xa2 \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xd1\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xc5\xba\xc3\xa2 \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xef\xbf\xbd\xd1\xbe\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimFOV_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xc5\xba\xc3\xa2 \xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xd6\xb4\xef\xbf\xbd \xc5\xba\xc3\xa2 \xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimWalkSpeed_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe2\xb8\xa6 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xbe\xdf\xb0\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe2\xb8\xa6 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xbe\xdf\xb0\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb5\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb5\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmmoSuppliedPerBox_MetaData[] = {
		{ "Category", "Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xc5\xba\xc8\xaf \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xc5\xba\xc8\xaf \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponAnimLayer_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- ABP ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- ABP ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadMontage_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xd8\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xef\xbf\xbd ABP \xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xd8\xb4\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xef\xbf\xbd ABP \xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireMontage_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe2\xba\xb0 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xe2\xba\xb0 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GripLocationOffset_MetaData[] = {
		{ "Category", "Grip Correction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xd1\xb1\xef\xbf\xbd \xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xd1\xb1\xef\xbf\xbd \xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GripRotationOffset_MetaData[] = {
		{ "Category", "Grip Correction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc4\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[] = {
		{ "Category", "Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/WeaponDataAsset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ---" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MuzzleFlashFX;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FireAbility;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ReloadAbility;
	static const UECodeGen_Private::FClassPropertyParams NewProp_AimAbility;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecoilPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecoilYaw;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmoInMag;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMag;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimFOV;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimWalkSpeed;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoSuppliedPerBox;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WeaponAnimLayer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireMontage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GripLocationOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GripRotationOffset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWeaponDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_WeaponMesh = { "WeaponMesh", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, WeaponMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponMesh_MetaData), NewProp_WeaponMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_MuzzleFlashFX = { "MuzzleFlashFX", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, MuzzleFlashFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MuzzleFlashFX_MetaData), NewProp_MuzzleFlashFX_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireAbility = { "FireAbility", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, FireAbility), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireAbility_MetaData), NewProp_FireAbility_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_ReloadAbility = { "ReloadAbility", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, ReloadAbility), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadAbility_MetaData), NewProp_ReloadAbility_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AimAbility = { "AimAbility", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, AimAbility), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimAbility_MetaData), NewProp_AimAbility_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, FireRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRate_MetaData), NewProp_FireRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_RecoilPitch = { "RecoilPitch", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, RecoilPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecoilPitch_MetaData), NewProp_RecoilPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_RecoilYaw = { "RecoilYaw", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, RecoilYaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecoilYaw_MetaData), NewProp_RecoilYaw_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_MaxAmmoInMag = { "MaxAmmoInMag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, MaxAmmoInMag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmoInMag_MetaData), NewProp_MaxAmmoInMag_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_MaxMag = { "MaxMag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, MaxMag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMag_MetaData), NewProp_MaxMag_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AimFOV = { "AimFOV", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, AimFOV), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimFOV_MetaData), NewProp_AimFOV_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AimWalkSpeed = { "AimWalkSpeed", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, AimWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimWalkSpeed_MetaData), NewProp_AimWalkSpeed_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, ProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHDProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileClass_MetaData), NewProp_ProjectileClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AmmoSuppliedPerBox = { "AmmoSuppliedPerBox", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, AmmoSuppliedPerBox), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmmoSuppliedPerBox_MetaData), NewProp_AmmoSuppliedPerBox_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_WeaponAnimLayer = { "WeaponAnimLayer", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, WeaponAnimLayer), Z_Construct_UClass_UClass, Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponAnimLayer_MetaData), NewProp_WeaponAnimLayer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_ReloadMontage = { "ReloadMontage", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, ReloadMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadMontage_MetaData), NewProp_ReloadMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireMontage = { "FireMontage", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, FireMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireMontage_MetaData), NewProp_FireMontage_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_GripLocationOffset = { "GripLocationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, GripLocationOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GripLocationOffset_MetaData), NewProp_GripLocationOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_GripRotationOffset = { "GripRotationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, GripRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GripRotationOffset_MetaData), NewProp_GripRotationOffset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponDataAsset, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireSound_MetaData), NewProp_FireSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWeaponDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_WeaponMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_MuzzleFlashFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_ReloadAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AimAbility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_RecoilPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_RecoilYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_MaxAmmoInMag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_MaxMag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AimFOV,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AimWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_ProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_AmmoSuppliedPerBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_WeaponAnimLayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_ReloadMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_GripLocationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_GripRotationOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponDataAsset_Statics::NewProp_FireSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponDataAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UWeaponDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWeaponDataAsset_Statics::ClassParams = {
	&UWeaponDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UWeaponDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UWeaponDataAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWeaponDataAsset()
{
	if (!Z_Registration_Info_UClass_UWeaponDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWeaponDataAsset.OuterSingleton, Z_Construct_UClass_UWeaponDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWeaponDataAsset.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<UWeaponDataAsset>()
{
	return UWeaponDataAsset::StaticClass();
}
UWeaponDataAsset::UWeaponDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWeaponDataAsset);
UWeaponDataAsset::~UWeaponDataAsset() {}
// End Class UWeaponDataAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWeaponDataAsset, UWeaponDataAsset::StaticClass, TEXT("UWeaponDataAsset"), &Z_Registration_Info_UClass_UWeaponDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWeaponDataAsset), 2811294718U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_3524098927(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_WeaponDataAsset_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
