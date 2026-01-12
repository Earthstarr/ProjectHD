// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/Grenade.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGrenade() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AGrenade();
PROJECTHD_API UClass* Z_Construct_UClass_AGrenade_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDProjectile();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AGrenade Function Explode
struct Z_Construct_UFunction_AGrenade_Explode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Weapon/Grenade.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGrenade_Explode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrenade, nullptr, "Explode", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGrenade_Explode_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGrenade_Explode_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AGrenade_Explode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGrenade_Explode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AGrenade::execExplode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Explode();
	P_NATIVE_END;
}
// End Class AGrenade Function Explode

// Begin Class AGrenade
void AGrenade::StaticRegisterNativesAGrenade()
{
	UClass* Class = AGrenade::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Explode", &AGrenade::execExplode },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGrenade);
UClass* Z_Construct_UClass_AGrenade_NoRegister()
{
	return AGrenade::StaticClass();
}
struct Z_Construct_UClass_AGrenade_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Weapon/Grenade.h" },
		{ "ModuleRelativePath", "Weapon/Grenade.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Weapon/Grenade.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionRadius_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Weapon/Grenade.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeToExplode_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Weapon/Grenade.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionEffect_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Grenade.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosionSound_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Grenade.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExplosionRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeToExplode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExplosionEffect;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExplosionSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGrenade_Explode, "Explode" }, // 4160740499
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGrenade>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGrenade_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenade, Damage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Damage_MetaData), NewProp_Damage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGrenade_Statics::NewProp_ExplosionRadius = { "ExplosionRadius", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenade, ExplosionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionRadius_MetaData), NewProp_ExplosionRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGrenade_Statics::NewProp_TimeToExplode = { "TimeToExplode", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenade, TimeToExplode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeToExplode_MetaData), NewProp_TimeToExplode_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGrenade_Statics::NewProp_ExplosionEffect = { "ExplosionEffect", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenade, ExplosionEffect), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionEffect_MetaData), NewProp_ExplosionEffect_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGrenade_Statics::NewProp_ExplosionSound = { "ExplosionSound", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGrenade, ExplosionSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosionSound_MetaData), NewProp_ExplosionSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGrenade_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenade_Statics::NewProp_Damage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenade_Statics::NewProp_ExplosionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenade_Statics::NewProp_TimeToExplode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenade_Statics::NewProp_ExplosionEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrenade_Statics::NewProp_ExplosionSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGrenade_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AGrenade_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHDProjectile,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGrenade_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGrenade_Statics::ClassParams = {
	&AGrenade::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AGrenade_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AGrenade_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGrenade_Statics::Class_MetaDataParams), Z_Construct_UClass_AGrenade_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGrenade()
{
	if (!Z_Registration_Info_UClass_AGrenade.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGrenade.OuterSingleton, Z_Construct_UClass_AGrenade_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGrenade.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AGrenade>()
{
	return AGrenade::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGrenade);
AGrenade::~AGrenade() {}
// End Class AGrenade

// Begin Registration
struct Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGrenade, AGrenade::StaticClass, TEXT("AGrenade"), &Z_Registration_Info_UClass_AGrenade, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGrenade), 2791082683U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_2378895640(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Grenade_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
