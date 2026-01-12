// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Effect/CameraShake_Fire.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCameraShake_Fire() {}

// Begin Cross Module References
ENGINECAMERAS_API UClass* Z_Construct_UClass_ULegacyCameraShake();
PROJECTHD_API UClass* Z_Construct_UClass_UCameraShake_Fire();
PROJECTHD_API UClass* Z_Construct_UClass_UCameraShake_Fire_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class UCameraShake_Fire
void UCameraShake_Fire::StaticRegisterNativesUCameraShake_Fire()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCameraShake_Fire);
UClass* Z_Construct_UClass_UCameraShake_Fire_NoRegister()
{
	return UCameraShake_Fire::StaticClass();
}
struct Z_Construct_UClass_UCameraShake_Fire_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "CameraShakePattern" },
		{ "IncludePath", "Effect/CameraShake_Fire.h" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShakeDuration_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShakeFrequency_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocShakeIntensityX_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocShakeIntensityY_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocShakeIntensityZ_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotShakeIntensityPitch_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotShakeIntensityYaw_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotShakeIntensityRoll_MetaData[] = {
		{ "Category", "Shake" },
		{ "ModuleRelativePath", "Effect/CameraShake_Fire.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShakeDuration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShakeFrequency;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LocShakeIntensityX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LocShakeIntensityY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LocShakeIntensityZ;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotShakeIntensityPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotShakeIntensityYaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotShakeIntensityRoll;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraShake_Fire>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_ShakeDuration = { "ShakeDuration", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, ShakeDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShakeDuration_MetaData), NewProp_ShakeDuration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_ShakeFrequency = { "ShakeFrequency", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, ShakeFrequency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShakeFrequency_MetaData), NewProp_ShakeFrequency_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_LocShakeIntensityX = { "LocShakeIntensityX", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, LocShakeIntensityX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocShakeIntensityX_MetaData), NewProp_LocShakeIntensityX_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_LocShakeIntensityY = { "LocShakeIntensityY", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, LocShakeIntensityY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocShakeIntensityY_MetaData), NewProp_LocShakeIntensityY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_LocShakeIntensityZ = { "LocShakeIntensityZ", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, LocShakeIntensityZ), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocShakeIntensityZ_MetaData), NewProp_LocShakeIntensityZ_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_RotShakeIntensityPitch = { "RotShakeIntensityPitch", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, RotShakeIntensityPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotShakeIntensityPitch_MetaData), NewProp_RotShakeIntensityPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_RotShakeIntensityYaw = { "RotShakeIntensityYaw", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, RotShakeIntensityYaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotShakeIntensityYaw_MetaData), NewProp_RotShakeIntensityYaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_RotShakeIntensityRoll = { "RotShakeIntensityRoll", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraShake_Fire, RotShakeIntensityRoll), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotShakeIntensityRoll_MetaData), NewProp_RotShakeIntensityRoll_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCameraShake_Fire_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_ShakeDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_ShakeFrequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_LocShakeIntensityX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_LocShakeIntensityY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_LocShakeIntensityZ,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_RotShakeIntensityPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_RotShakeIntensityYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraShake_Fire_Statics::NewProp_RotShakeIntensityRoll,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraShake_Fire_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCameraShake_Fire_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULegacyCameraShake,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraShake_Fire_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCameraShake_Fire_Statics::ClassParams = {
	&UCameraShake_Fire::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCameraShake_Fire_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCameraShake_Fire_Statics::PropPointers),
	0,
	0x009010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraShake_Fire_Statics::Class_MetaDataParams), Z_Construct_UClass_UCameraShake_Fire_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCameraShake_Fire()
{
	if (!Z_Registration_Info_UClass_UCameraShake_Fire.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCameraShake_Fire.OuterSingleton, Z_Construct_UClass_UCameraShake_Fire_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCameraShake_Fire.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<UCameraShake_Fire>()
{
	return UCameraShake_Fire::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCameraShake_Fire);
UCameraShake_Fire::~UCameraShake_Fire() {}
// End Class UCameraShake_Fire

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Effect_CameraShake_Fire_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCameraShake_Fire, UCameraShake_Fire::StaticClass, TEXT("UCameraShake_Fire"), &Z_Registration_Info_UClass_UCameraShake_Fire, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCameraShake_Fire), 639382061U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Effect_CameraShake_Fire_h_97173983(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Effect_CameraShake_Fire_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Effect_CameraShake_Fire_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
