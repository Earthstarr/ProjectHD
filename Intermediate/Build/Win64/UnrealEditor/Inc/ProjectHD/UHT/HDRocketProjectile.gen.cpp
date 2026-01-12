// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/Projectile/HDRocketProjectile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHDRocketProjectile() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDProjectile();
PROJECTHD_API UClass* Z_Construct_UClass_AHDRocketProjectile();
PROJECTHD_API UClass* Z_Construct_UClass_AHDRocketProjectile_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AHDRocketProjectile
void AHDRocketProjectile::StaticRegisterNativesAHDRocketProjectile()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHDRocketProjectile);
UClass* Z_Construct_UClass_AHDRocketProjectile_NoRegister()
{
	return AHDRocketProjectile::StaticClass();
}
struct Z_Construct_UClass_AHDRocketProjectile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapon/Projectile/HDRocketProjectile.h" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDRocketProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionRadius_MetaData[] = {
		{ "Category", "Explosion" },
		{ "ModuleRelativePath", "Weapon/Projectile/HDRocketProjectile.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionShakeClass_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Projectile/HDRocketProjectile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExplosionRadius;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ExplosionShakeClass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHDRocketProjectile>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDRocketProjectile_Statics::NewProp_ExplosionRadius = { "ExplosionRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDRocketProjectile, ExplosionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionRadius_MetaData), NewProp_ExplosionRadius_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AHDRocketProjectile_Statics::NewProp_ExplosionShakeClass = { "ExplosionShakeClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDRocketProjectile, ExplosionShakeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionShakeClass_MetaData), NewProp_ExplosionShakeClass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHDRocketProjectile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDRocketProjectile_Statics::NewProp_ExplosionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDRocketProjectile_Statics::NewProp_ExplosionShakeClass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDRocketProjectile_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHDRocketProjectile_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHDProjectile,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDRocketProjectile_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHDRocketProjectile_Statics::ClassParams = {
	&AHDRocketProjectile::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AHDRocketProjectile_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AHDRocketProjectile_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHDRocketProjectile_Statics::Class_MetaDataParams), Z_Construct_UClass_AHDRocketProjectile_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHDRocketProjectile()
{
	if (!Z_Registration_Info_UClass_AHDRocketProjectile.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHDRocketProjectile.OuterSingleton, Z_Construct_UClass_AHDRocketProjectile_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHDRocketProjectile.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AHDRocketProjectile>()
{
	return AHDRocketProjectile::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHDRocketProjectile);
AHDRocketProjectile::~AHDRocketProjectile() {}
// End Class AHDRocketProjectile

// Begin Registration
struct Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHDRocketProjectile, AHDRocketProjectile::StaticClass, TEXT("AHDRocketProjectile"), &Z_Registration_Info_UClass_AHDRocketProjectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHDRocketProjectile), 4072386083U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_3756053166(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Projectile_HDRocketProjectile_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
