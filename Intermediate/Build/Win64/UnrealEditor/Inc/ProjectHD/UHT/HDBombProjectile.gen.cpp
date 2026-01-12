// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/Projectile/HDBombProjectile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHDBombProjectile() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDBombProjectile();
PROJECTHD_API UClass* Z_Construct_UClass_AHDBombProjectile_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDProjectile();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AHDBombProjectile
void AHDBombProjectile::StaticRegisterNativesAHDBombProjectile()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHDBombProjectile);
UClass* Z_Construct_UClass_AHDBombProjectile_NoRegister()
{
	return AHDBombProjectile::StaticClass();
}
struct Z_Construct_UClass_AHDBombProjectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapon/Projectile/HDBombProjectile.h" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionRadius_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LandImpactEffect_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x95\x85\xec\x97\x90 \xeb\xb6\x80\xeb\x94\xaa\xed\x9e\x90\xeb\x95\x8c \xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8\xec\x99\x80 \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x95\x85\xec\x97\x90 \xeb\xb6\x80\xeb\x94\xaa\xed\x9e\x90\xeb\x95\x8c \xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8\xec\x99\x80 \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LandImpactSound_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FallingAudioComp_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x95\x85\xec\x9c\xbc\xeb\xa1\x9c \xeb\x96\xa8\xec\x96\xb4\xec\xa7\x80\xeb\x8a\x94 \xec\x86\x8c\xeb\xa6\xac\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x95\x85\xec\x9c\xbc\xeb\xa1\x9c \xeb\x96\xa8\xec\x96\xb4\xec\xa7\x80\xeb\x8a\x94 \xec\x86\x8c\xeb\xa6\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FallingSound_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionShakeClass_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc \xed\x9d\x94\xeb\x93\xa4\xeb\xa6\xbc\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc \xed\x9d\x94\xeb\x93\xa4\xeb\xa6\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShakeInnerRadius_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x9d\x94\xeb\x93\xa4\xeb\xa6\xbc\xec\x9d\xb4 \xec\xa0\x84\xeb\x8b\xac\xeb\x90\xa0 \xec\xb5\x9c\xeb\x8c\x80 \xea\xb1\xb0\xeb\xa6\xac\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x9d\x94\xeb\x93\xa4\xeb\xa6\xbc\xec\x9d\xb4 \xec\xa0\x84\xeb\x8b\xac\xeb\x90\xa0 \xec\xb5\x9c\xeb\x8c\x80 \xea\xb1\xb0\xeb\xa6\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShakeOuterRadius_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionDelay_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x80\xec\x97\xb0 \xec\x8b\x9c\xea\xb0\x84 \xec\x84\xa4\xec\xa0\x95 (0.5\xec\xb4\x88)\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Projectile/HDBombProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x80\xec\x97\xb0 \xec\x8b\x9c\xea\xb0\x84 \xec\x84\xa4\xec\xa0\x95 (0.5\xec\xb4\x88)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExplosionRadius;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LandImpactEffect;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LandImpactSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FallingAudioComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FallingSound;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ExplosionShakeClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShakeInnerRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShakeOuterRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExplosionDelay;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHDBombProjectile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ExplosionRadius = { "ExplosionRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, ExplosionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionRadius_MetaData), NewProp_ExplosionRadius_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_LandImpactEffect = { "LandImpactEffect", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, LandImpactEffect), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LandImpactEffect_MetaData), NewProp_LandImpactEffect_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_LandImpactSound = { "LandImpactSound", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, LandImpactSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LandImpactSound_MetaData), NewProp_LandImpactSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_FallingAudioComp = { "FallingAudioComp", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, FallingAudioComp), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FallingAudioComp_MetaData), NewProp_FallingAudioComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_FallingSound = { "FallingSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, FallingSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FallingSound_MetaData), NewProp_FallingSound_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ExplosionShakeClass = { "ExplosionShakeClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, ExplosionShakeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionShakeClass_MetaData), NewProp_ExplosionShakeClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ShakeInnerRadius = { "ShakeInnerRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, ShakeInnerRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShakeInnerRadius_MetaData), NewProp_ShakeInnerRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ShakeOuterRadius = { "ShakeOuterRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, ShakeOuterRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShakeOuterRadius_MetaData), NewProp_ShakeOuterRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ExplosionDelay = { "ExplosionDelay", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDBombProjectile, ExplosionDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionDelay_MetaData), NewProp_ExplosionDelay_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHDBombProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ExplosionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_LandImpactEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_LandImpactSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_FallingAudioComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_FallingSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ExplosionShakeClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ShakeInnerRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ShakeOuterRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDBombProjectile_Statics::NewProp_ExplosionDelay,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDBombProjectile_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHDBombProjectile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHDProjectile,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDBombProjectile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHDBombProjectile_Statics::ClassParams = {
	&AHDBombProjectile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AHDBombProjectile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AHDBombProjectile_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHDBombProjectile_Statics::Class_MetaDataParams), Z_Construct_UClass_AHDBombProjectile_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHDBombProjectile()
{
	if (!Z_Registration_Info_UClass_AHDBombProjectile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHDBombProjectile.OuterSingleton, Z_Construct_UClass_AHDBombProjectile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHDBombProjectile.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AHDBombProjectile>()
{
	return AHDBombProjectile::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHDBombProjectile);
AHDBombProjectile::~AHDBombProjectile() {}
// End Class AHDBombProjectile

// Begin Registration
struct Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHDBombProjectile, AHDBombProjectile::StaticClass, TEXT("AHDBombProjectile"), &Z_Registration_Info_UClass_AHDBombProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHDBombProjectile), 3752214901U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_1990126616(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDBombProjectile_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
