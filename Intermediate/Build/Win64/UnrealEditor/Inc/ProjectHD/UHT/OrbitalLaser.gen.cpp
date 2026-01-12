// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/Stratagem/OrbitalLaser.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOrbitalLaser() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AOrbitalLaser();
PROJECTHD_API UClass* Z_Construct_UClass_AOrbitalLaser_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AOrbitalLaser
void AOrbitalLaser::StaticRegisterNativesAOrbitalLaser()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOrbitalLaser);
UClass* Z_Construct_UClass_AOrbitalLaser_NoRegister()
{
	return AOrbitalLaser::StaticClass();
}
struct Z_Construct_UClass_AOrbitalLaser_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapon/Stratagem/OrbitalLaser.h" },
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LaserFX_MetaData[] = {
		{ "Category", "Laser" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 ---\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactFX_MetaData[] = {
		{ "Category", "Laser" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x95\x98\xeb\x8a\x98\xec\x97\x90\xec\x84\x9c \xeb\x82\xb4\xeb\xa0\xa4\xec\x98\xa4\xeb\x8a\x94 \xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80 \xeb\xb3\xb8\xec\xb2\xb4\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x95\x98\xeb\x8a\x98\xec\x97\x90\xec\x84\x9c \xeb\x82\xb4\xeb\xa0\xa4\xec\x98\xa4\xeb\x8a\x94 \xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80 \xeb\xb3\xb8\xec\xb2\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SearchRadius_MetaData[] = {
		{ "Category", "Laser|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xec\x84\xa4\xec\xa0\x95 ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xec\x84\xa4\xec\xa0\x95 ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "Laser|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa0\x81 \xed\x83\x90\xec\xa7\x80 \xeb\xb2\x94\xec\x9c\x84\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa0\x81 \xed\x83\x90\xec\xa7\x80 \xeb\xb2\x94\xec\x9c\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DamagePerSecond_MetaData[] = {
		{ "Category", "Laser|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80 \xec\x9d\xb4\xeb\x8f\x99 \xec\x86\x8d\xeb\x8f\x84\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80 \xec\x9d\xb4\xeb\x8f\x99 \xec\x86\x8d\xeb\x8f\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "Laser|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xb4\x88\xeb\x8b\xb9 \xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb4\x88\xeb\x8b\xb9 \xeb\x8d\xb0\xeb\xaf\xb8\xec\xa7\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BurnDecal_MetaData[] = {
		{ "Category", "Laser|Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80 \xec\xa7\x80\xec\x86\x8d \xec\x8b\x9c\xea\xb0\x84\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80 \xec\xa7\x80\xec\x86\x8d \xec\x8b\x9c\xea\xb0\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LaserLoopSound_MetaData[] = {
		{ "Category", "Laser|Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x80\xeb\xa9\xb4\xec\x9d\xb4 \xed\x83\x80\xeb\x8a\x94 \xeb\x8d\xb0\xec\xb9\xbc \xeb\xa8\xb8\xed\x8b\xb0\xeb\xa6\xac\xec\x96\xbc\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x80\xeb\xa9\xb4\xec\x9d\xb4 \xed\x83\x80\xeb\x8a\x94 \xeb\x8d\xb0\xec\xb9\xbc \xeb\xa8\xb8\xed\x8b\xb0\xeb\xa6\xac\xec\x96\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTarget_MetaData[] = {
		{ "ModuleRelativePath", "Weapon/Stratagem/OrbitalLaser.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LaserFX;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ImpactFX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SearchRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DamagePerSecond;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BurnDecal;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LaserLoopSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOrbitalLaser>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_LaserFX = { "LaserFX", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, LaserFX), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LaserFX_MetaData), NewProp_LaserFX_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_ImpactFX = { "ImpactFX", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, ImpactFX), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactFX_MetaData), NewProp_ImpactFX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_SearchRadius = { "SearchRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, SearchRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SearchRadius_MetaData), NewProp_SearchRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, MoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveSpeed_MetaData), NewProp_MoveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_DamagePerSecond = { "DamagePerSecond", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, DamagePerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DamagePerSecond_MetaData), NewProp_DamagePerSecond_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_BurnDecal = { "BurnDecal", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, BurnDecal), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BurnDecal_MetaData), NewProp_BurnDecal_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_LaserLoopSound = { "LaserLoopSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, LaserLoopSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LaserLoopSound_MetaData), NewProp_LaserLoopSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_CurrentTarget = { "CurrentTarget", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitalLaser, CurrentTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTarget_MetaData), NewProp_CurrentTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOrbitalLaser_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_LaserFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_ImpactFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_SearchRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_MoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_DamagePerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_Duration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_BurnDecal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_LaserLoopSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitalLaser_Statics::NewProp_CurrentTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitalLaser_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOrbitalLaser_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitalLaser_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOrbitalLaser_Statics::ClassParams = {
	&AOrbitalLaser::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AOrbitalLaser_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitalLaser_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitalLaser_Statics::Class_MetaDataParams), Z_Construct_UClass_AOrbitalLaser_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOrbitalLaser()
{
	if (!Z_Registration_Info_UClass_AOrbitalLaser.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOrbitalLaser.OuterSingleton, Z_Construct_UClass_AOrbitalLaser_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOrbitalLaser.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AOrbitalLaser>()
{
	return AOrbitalLaser::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOrbitalLaser);
AOrbitalLaser::~AOrbitalLaser() {}
// End Class AOrbitalLaser

// Begin Registration
struct Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_OrbitalLaser_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOrbitalLaser, AOrbitalLaser::StaticClass, TEXT("AOrbitalLaser"), &Z_Registration_Info_UClass_AOrbitalLaser, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOrbitalLaser), 1148070689U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_OrbitalLaser_h_3917382330(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_OrbitalLaser_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_OrbitalLaser_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
