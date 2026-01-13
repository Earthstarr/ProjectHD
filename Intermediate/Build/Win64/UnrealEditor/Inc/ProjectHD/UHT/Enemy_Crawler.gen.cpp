// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Character/Enemy/Enemy_Crawler.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy_Crawler() {}

// Begin Cross Module References
PROJECTHD_API UClass* Z_Construct_UClass_AEnemy_Crawler();
PROJECTHD_API UClass* Z_Construct_UClass_AEnemy_Crawler_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AEnemyBase();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AEnemy_Crawler
void AEnemy_Crawler::StaticRegisterNativesAEnemy_Crawler()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemy_Crawler);
UClass* Z_Construct_UClass_AEnemy_Crawler_NoRegister()
{
	return AEnemy_Crawler::StaticClass();
}
struct Z_Construct_UClass_AEnemy_Crawler_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/Enemy/Enemy_Crawler.h" },
		{ "ModuleRelativePath", "Character/Enemy/Enemy_Crawler.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_pouncingSpeed_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Enemy/Enemy_Crawler.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_pouncingSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy_Crawler>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemy_Crawler_Statics::NewProp_pouncingSpeed = { "pouncingSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemy_Crawler, pouncingSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_pouncingSpeed_MetaData), NewProp_pouncingSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemy_Crawler_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Crawler_Statics::NewProp_pouncingSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Crawler_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemy_Crawler_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemyBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Crawler_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Crawler_Statics::ClassParams = {
	&AEnemy_Crawler::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEnemy_Crawler_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Crawler_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Crawler_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemy_Crawler_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemy_Crawler()
{
	if (!Z_Registration_Info_UClass_AEnemy_Crawler.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemy_Crawler.OuterSingleton, Z_Construct_UClass_AEnemy_Crawler_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemy_Crawler.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AEnemy_Crawler>()
{
	return AEnemy_Crawler::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy_Crawler);
AEnemy_Crawler::~AEnemy_Crawler() {}
// End Class AEnemy_Crawler

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Enemy_Enemy_Crawler_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemy_Crawler, AEnemy_Crawler::StaticClass, TEXT("AEnemy_Crawler"), &Z_Registration_Info_UClass_AEnemy_Crawler, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemy_Crawler), 1689313854U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Enemy_Enemy_Crawler_h_897163111(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Enemy_Enemy_Crawler_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Enemy_Enemy_Crawler_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
