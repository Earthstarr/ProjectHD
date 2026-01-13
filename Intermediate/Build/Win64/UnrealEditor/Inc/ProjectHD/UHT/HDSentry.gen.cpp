// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/Stratagem/HDSentry.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHDSentry() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDProjectile_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDSentry();
PROJECTHD_API UClass* Z_Construct_UClass_AHDSentry_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AHDSentry Function OnDeployFinished
struct Z_Construct_UFunction_AHDSentry_OnDeployFinished_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xeb\x81\x9d\xeb\x82\xa0 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c (\xec\xa0\x84\xea\xb0\x9c \xec\x99\x84\xeb\xa3\x8c \xec\xb2\x98\xeb\xa6\xac)\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xeb\x81\x9d\xeb\x82\xa0 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c (\xec\xa0\x84\xea\xb0\x9c \xec\x99\x84\xeb\xa3\x8c \xec\xb2\x98\xeb\xa6\xac)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSentry_OnDeployFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSentry, nullptr, "OnDeployFinished", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSentry_OnDeployFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSentry_OnDeployFinished_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AHDSentry_OnDeployFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSentry_OnDeployFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHDSentry::execOnDeployFinished)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDeployFinished();
	P_NATIVE_END;
}
// End Class AHDSentry Function OnDeployFinished

// Begin Class AHDSentry Function OnRetractFinished
struct Z_Construct_UFunction_AHDSentry_OnRetractFinished_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x87\xb4\xea\xb0\x81\xec\x9d\xb4 \xeb\x81\x9d\xeb\x82\xac\xec\x9d\x84 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x87\xb4\xea\xb0\x81\xec\x9d\xb4 \xeb\x81\x9d\xeb\x82\xac\xec\x9d\x84 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSentry_OnRetractFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSentry, nullptr, "OnRetractFinished", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSentry_OnRetractFinished_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSentry_OnRetractFinished_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AHDSentry_OnRetractFinished()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSentry_OnRetractFinished_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHDSentry::execOnRetractFinished)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRetractFinished();
	P_NATIVE_END;
}
// End Class AHDSentry Function OnRetractFinished

// Begin Class AHDSentry Function StartDeploySequence
static const FName NAME_AHDSentry_StartDeploySequence = FName(TEXT("StartDeploySequence"));
void AHDSentry::StartDeploySequence()
{
	UFunction* Func = FindFunctionChecked(NAME_AHDSentry_StartDeploySequence);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AHDSentry_StartDeploySequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa0\x84\xea\xb0\x9c \xec\x8b\x9c\xec\x9e\x91 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa0\x84\xea\xb0\x9c \xec\x8b\x9c\xec\x9e\x91 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSentry_StartDeploySequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSentry, nullptr, "StartDeploySequence", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSentry_StartDeploySequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSentry_StartDeploySequence_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AHDSentry_StartDeploySequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSentry_StartDeploySequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AHDSentry Function StartDeploySequence

// Begin Class AHDSentry Function StartRetractSequence
static const FName NAME_AHDSentry_StartRetractSequence = FName(TEXT("StartRetractSequence"));
void AHDSentry::StartRetractSequence()
{
	UFunction* Func = FindFunctionChecked(NAME_AHDSentry_StartRetractSequence);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AHDSentry_StartRetractSequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x87\xb4\xea\xb0\x81 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x87\xb4\xea\xb0\x81 \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSentry_StartRetractSequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSentry, nullptr, "StartRetractSequence", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSentry_StartRetractSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSentry_StartRetractSequence_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AHDSentry_StartRetractSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSentry_StartRetractSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AHDSentry Function StartRetractSequence

// Begin Class AHDSentry
void AHDSentry::StaticRegisterNativesAHDSentry()
{
	UClass* Class = AHDSentry::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnDeployFinished", &AHDSentry::execOnDeployFinished },
		{ "OnRetractFinished", &AHDSentry::execOnRetractFinished },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHDSentry);
UClass* Z_Construct_UClass_AHDSentry_NoRegister()
{
	return AHDSentry::StaticClass();
}
struct Z_Construct_UClass_AHDSentry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapon/Stratagem/HDSentry.h" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BodyMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 ---\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8 ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PillarMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x80\xeb\xa9\xb4\xec\x97\x90 \xeb\xb0\x95\xed\x9e\x88\xeb\x8a\x94 \xeb\xb2\xa0\xec\x9d\xb4\xec\x8a\xa4 (Root)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x80\xeb\xa9\xb4\xec\x97\x90 \xeb\xb0\x95\xed\x9e\x88\xeb\x8a\x94 \xeb\xb2\xa0\xec\x9d\xb4\xec\x8a\xa4 (Root)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurretMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9c\x84\xeb\xa1\x9c \xec\x98\xac\xeb\x9d\xbc\xec\x98\xa4\xeb\x8a\x94 \xea\xb8\xb0\xeb\x91\xa5\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9c\x84\xeb\xa1\x9c \xec\x98\xac\xeb\x9d\xbc\xec\x98\xa4\xeb\x8a\x94 \xea\xb8\xb0\xeb\x91\xa5" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DetectionRadius_MetaData[] = {
		{ "Category", "Sentry|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xec\x84\xa4\xec\xa0\x95 ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xec\x84\xa4\xec\xa0\x95 ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationSpeed_MetaData[] = {
		{ "Category", "Sentry|Settings" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[] = {
		{ "Category", "Sentry|Settings" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmo_MetaData[] = {
		{ "Category", "Sentry|Settings" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Sentry|Settings" },
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactSound_MetaData[] = {
		{ "Category", "Sentry|Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c ---\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeploySound_MetaData[] = {
		{ "Category", "Sentry|Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x80\xeb\xa9\xb4 \xec\xb6\xa9\xeb\x8f\x8c \xec\x8b\x9c\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x80\xeb\xa9\xb4 \xec\xb6\xa9\xeb\x8f\x8c \xec\x8b\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationSound_MetaData[] = {
		{ "Category", "Sentry|Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb8\xb0\xeb\x91\xa5 \xec\x83\x81\xec\x8a\xb9 \xec\x8b\x9c (BP \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xec\x97\xb0\xea\xb2\xb0\xec\x9a\xa9)\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb8\xb0\xeb\x91\xa5 \xec\x83\x81\xec\x8a\xb9 \xec\x8b\x9c (BP \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98 \xec\x97\xb0\xea\xb2\xb0\xec\x9a\xa9)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[] = {
		{ "Category", "Sentry|Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x9a\x8c\xec\xa0\x84 \xec\xa4\x91 (\xeb\xa3\xa8\xed\x94\x84 \xea\xb6\x8c\xec\x9e\xa5)\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x9a\x8c\xec\xa0\x84 \xec\xa4\x91 (\xeb\xa3\xa8\xed\x94\x84 \xea\xb6\x8c\xec\x9e\xa5)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MuzzleFlashFX_MetaData[] = {
		{ "Category", "Sentry|Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb0\x9c\xec\x82\xac \xec\x8b\x9c\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x9c\xec\x82\xac \xec\x8b\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTarget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb8\xb0\xeb\x91\xa5 \xec\x98\xac\xeb\x9d\xbc\xec\x98\xa4\xeb\x8a\x94 \xec\xa4\x91\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/HDSentry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb8\xb0\xeb\x91\xa5 \xec\x98\xac\xeb\x9d\xbc\xec\x98\xa4\xeb\x8a\x94 \xec\xa4\x91" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BodyMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PillarMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TurretMesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DetectionRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRate;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmo;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ImpactSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeploySound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RotationSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MuzzleFlashFX;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTarget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AHDSentry_OnDeployFinished, "OnDeployFinished" }, // 3667981550
		{ &Z_Construct_UFunction_AHDSentry_OnRetractFinished, "OnRetractFinished" }, // 3318831713
		{ &Z_Construct_UFunction_AHDSentry_StartDeploySequence, "StartDeploySequence" }, // 1682787757
		{ &Z_Construct_UFunction_AHDSentry_StartRetractSequence, "StartRetractSequence" }, // 1657124664
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHDSentry>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_BodyMesh = { "BodyMesh", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, BodyMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BodyMesh_MetaData), NewProp_BodyMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_PillarMesh = { "PillarMesh", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, PillarMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PillarMesh_MetaData), NewProp_PillarMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_TurretMesh = { "TurretMesh", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, TurretMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurretMesh_MetaData), NewProp_TurretMesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_DetectionRadius = { "DetectionRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, DetectionRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DetectionRadius_MetaData), NewProp_DetectionRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_RotationSpeed = { "RotationSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, RotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationSpeed_MetaData), NewProp_RotationSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, FireRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRate_MetaData), NewProp_FireRate_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_MaxAmmo = { "MaxAmmo", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, MaxAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmo_MetaData), NewProp_MaxAmmo_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, ProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHDProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileClass_MetaData), NewProp_ProjectileClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_ImpactSound = { "ImpactSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, ImpactSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactSound_MetaData), NewProp_ImpactSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_DeploySound = { "DeploySound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, DeploySound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeploySound_MetaData), NewProp_DeploySound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_RotationSound = { "RotationSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, RotationSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationSound_MetaData), NewProp_RotationSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireSound_MetaData), NewProp_FireSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_MuzzleFlashFX = { "MuzzleFlashFX", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, MuzzleFlashFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MuzzleFlashFX_MetaData), NewProp_MuzzleFlashFX_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSentry_Statics::NewProp_CurrentTarget = { "CurrentTarget", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSentry, CurrentTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTarget_MetaData), NewProp_CurrentTarget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHDSentry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_BodyMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_PillarMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_TurretMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_DetectionRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_RotationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_FireRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_MaxAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_ProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_ImpactSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_DeploySound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_RotationSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_FireSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_MuzzleFlashFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSentry_Statics::NewProp_CurrentTarget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDSentry_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHDSentry_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDSentry_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHDSentry_Statics::ClassParams = {
	&AHDSentry::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AHDSentry_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AHDSentry_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHDSentry_Statics::Class_MetaDataParams), Z_Construct_UClass_AHDSentry_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHDSentry()
{
	if (!Z_Registration_Info_UClass_AHDSentry.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHDSentry.OuterSingleton, Z_Construct_UClass_AHDSentry_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHDSentry.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AHDSentry>()
{
	return AHDSentry::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHDSentry);
AHDSentry::~AHDSentry() {}
// End Class AHDSentry

// Begin Registration
struct Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHDSentry, AHDSentry::StaticClass, TEXT("AHDSentry"), &Z_Registration_Info_UClass_AHDSentry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHDSentry), 3079618558U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_72095128(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
