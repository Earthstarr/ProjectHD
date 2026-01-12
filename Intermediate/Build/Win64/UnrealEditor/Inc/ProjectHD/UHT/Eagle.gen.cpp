// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/Stratagem/Eagle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEagle() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AEagle();
PROJECTHD_API UClass* Z_Construct_UClass_AEagle_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AEagle
void AEagle::StaticRegisterNativesAEagle()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEagle);
UClass* Z_Construct_UClass_AEagle_NoRegister()
{
	return AEagle::StaticClass();
}
struct Z_Construct_UClass_AEagle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapon/Stratagem/Eagle.h" },
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Eagle" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[] = {
		{ "Category", "Eagle" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EagleVoice_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlareTemplate_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlareAlpha1_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xc3\xb7\xef\xbf\xbd\xef\xbf\xbd\xee\xb8\xa6 \xef\xbf\xbd\xd1\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd (0.0 ~ 1.0)\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc3\xb7\xef\xbf\xbd\xef\xbf\xbd\xee\xb8\xa6 \xef\xbf\xbd\xd1\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd (0.0 ~ 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlareAlpha2_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlareAlpha3_MetaData[] = {
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VoiceStartAlpha_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xcc\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/Eagle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xcc\xb1\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcc\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EagleVoice;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FlareTemplate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlareAlpha1;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlareAlpha2;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlareAlpha3;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VoiceStartAlpha;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEagle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, MeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComp_MetaData), NewProp_MeshComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_EagleVoice = { "EagleVoice", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, EagleVoice), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EagleVoice_MetaData), NewProp_EagleVoice_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_FlareTemplate = { "FlareTemplate", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, FlareTemplate), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlareTemplate_MetaData), NewProp_FlareTemplate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_FlareAlpha1 = { "FlareAlpha1", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, FlareAlpha1), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlareAlpha1_MetaData), NewProp_FlareAlpha1_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_FlareAlpha2 = { "FlareAlpha2", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, FlareAlpha2), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlareAlpha2_MetaData), NewProp_FlareAlpha2_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_FlareAlpha3 = { "FlareAlpha3", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, FlareAlpha3), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlareAlpha3_MetaData), NewProp_FlareAlpha3_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEagle_Statics::NewProp_VoiceStartAlpha = { "VoiceStartAlpha", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEagle, VoiceStartAlpha), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VoiceStartAlpha_MetaData), NewProp_VoiceStartAlpha_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEagle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_MeshComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_EagleVoice,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_FlareTemplate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_FlareAlpha1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_FlareAlpha2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_FlareAlpha3,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEagle_Statics::NewProp_VoiceStartAlpha,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEagle_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEagle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEagle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEagle_Statics::ClassParams = {
	&AEagle::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEagle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEagle_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEagle_Statics::Class_MetaDataParams), Z_Construct_UClass_AEagle_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEagle()
{
	if (!Z_Registration_Info_UClass_AEagle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEagle.OuterSingleton, Z_Construct_UClass_AEagle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEagle.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AEagle>()
{
	return AEagle::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEagle);
AEagle::~AEagle() {}
// End Class AEagle

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_Eagle_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEagle, AEagle::StaticClass, TEXT("AEagle"), &Z_Registration_Info_UClass_AEagle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEagle), 3939503505U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_Eagle_h_666725079(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_Eagle_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_Eagle_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
