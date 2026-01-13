// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Weapon/Stratagem/StratagemBeacon.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStratagemBeacon() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AEagle_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDProjectile_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDSentry_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDSupplyPod_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AOrbitalLaser_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AStratagemBeacon();
PROJECTHD_API UClass* Z_Construct_UClass_AStratagemBeacon_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AStratagemBeacon Function OnHit
struct Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics
{
	struct StratagemBeacon_eventOnHit_Parms
	{
		UPrimitiveComponent* HitComp;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		FVector NormalImpulse;
		FHitResult Hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb0\x94\xeb\x8b\xa5\xec\x97\x90 \xeb\xb6\x80\xeb\x94\xaa\xed\x98\x94\xec\x9d\x84 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c\xeb\x90\xa0 \xed\x95\xa8\xec\x88\x98\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x94\xeb\x8b\xa5\xec\x97\x90 \xeb\xb6\x80\xeb\x94\xaa\xed\x98\x94\xec\x9d\x84 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c\xeb\x90\xa0 \xed\x95\xa8\xec\x88\x98" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_HitComp = { "HitComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StratagemBeacon_eventOnHit_Parms, HitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitComp_MetaData), NewProp_HitComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StratagemBeacon_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StratagemBeacon_eventOnHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StratagemBeacon_eventOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StratagemBeacon_eventOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_HitComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_NormalImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::NewProp_Hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AStratagemBeacon, nullptr, "OnHit", nullptr, nullptr, Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::StratagemBeacon_eventOnHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C80401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::StratagemBeacon_eventOnHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AStratagemBeacon_OnHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AStratagemBeacon_OnHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AStratagemBeacon::execOnHit)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit);
	P_NATIVE_END;
}
// End Class AStratagemBeacon Function OnHit

// Begin Class AStratagemBeacon
void AStratagemBeacon::StaticRegisterNativesAStratagemBeacon()
{
	UClass* Class = AStratagemBeacon::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnHit", &AStratagemBeacon::execOnHit },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AStratagemBeacon);
UClass* Z_Construct_UClass_AStratagemBeacon_NoRegister()
{
	return AStratagemBeacon::StaticClass();
}
struct Z_Construct_UClass_AStratagemBeacon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Weapon/Stratagem/StratagemBeacon.h" },
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionComp_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xac\xbc\xeb\xa6\xac\xec\xa0\x81 \xed\x98\x95\xed\x83\x9c\xec\x99\x80 \xec\xb6\xa9\xeb\x8f\x8c\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9 (\xeb\xa3\xa8\xed\x8a\xb8 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xac\xbc\xeb\xa6\xac\xec\xa0\x81 \xed\x98\x95\xed\x83\x9c\xec\x99\x80 \xec\xb6\xa9\xeb\x8f\x8c\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9 (\xeb\xa3\xa8\xed\x8a\xb8 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb9\x84\xec\xbb\xa8\xec\x9d\x98 \xec\x99\xb8\xed\x98\x95 (\xec\x9e\x91\xec\x9d\x80 \xec\x9b\x90\xed\x86\xb5\xec\x9d\xb4\xeb\x82\x98 \xea\xb5\xac\xec\xb2\xb4 \xec\x97\x90\xec\x85\x8b)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb9\x84\xec\xbb\xa8\xec\x9d\x98 \xec\x99\xb8\xed\x98\x95 (\xec\x9e\x91\xec\x9d\x80 \xec\x9b\x90\xed\x86\xb5\xec\x9d\xb4\xeb\x82\x98 \xea\xb5\xac\xec\xb2\xb4 \xec\x97\x90\xec\x85\x8b)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovement_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x88\xac\xec\x82\xac\xec\xb2\xb4 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x88\xac\xec\x82\xac\xec\xb2\xb4 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Eagle500kgProjectileClass_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 500kg \xed\x8f\xac\xed\x83\x84\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "500kg \xed\x8f\xac\xed\x83\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EagleClusterProjectileClass_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x91\xec\x86\x8d\xed\x83\x84\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x91\xec\x86\x8d\xed\x83\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SupplyClass_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb3\xb4\xea\xb8\x89\xed\x92\x88\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb3\xb4\xea\xb8\x89\xed\x92\x88" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SentryClass_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x84\xbc\xed\x8a\xb8\xeb\xa6\xac\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x84\xbc\xed\x8a\xb8\xeb\xa6\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrbitalLaserClass_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb6\xa4\xeb\x8f\x84 \xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb6\xa4\xeb\x8f\x84 \xeb\xa0\x88\xec\x9d\xb4\xec\xa0\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeaconActivateSound_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb0\x94\xeb\x8b\xa5\xec\x97\x90 \xeb\xb6\x80\xec\xb0\xa9\xec\x8b\x9c \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb0\x94\xeb\x8b\xa5\xec\x97\x90 \xeb\xb6\x80\xec\xb0\xa9\xec\x8b\x9c \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DelayToStrike_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x8f\xad\xea\xb2\xa9 \xeb\x8c\x80\xea\xb8\xb0 \xec\x8b\x9c\xea\xb0\x84\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x8f\xad\xea\xb2\xa9 \xeb\x8c\x80\xea\xb8\xb0 \xec\x8b\x9c\xea\xb0\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeamEffect_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb9\xa8\xea\xb0\x84 \xeb\xb9\x9b\xea\xb8\xb0\xeb\x91\xa5 \xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb9\xa8\xea\xb0\x84 \xeb\xb9\x9b\xea\xb8\xb0\xeb\x91\xa5 \xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FallingSound_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb3\xb4\xea\xb8\x89\xed\x92\x88, \xec\x84\xbc\xed\x8a\xb8\xeb\xa6\xac \xeb\x96\xa8\xec\x96\xb4\xec\xa7\x80\xeb\x8a\x94 \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb3\xb4\xea\xb8\x89\xed\x92\x88, \xec\x84\xbc\xed\x8a\xb8\xeb\xa6\xac \xeb\x96\xa8\xec\x96\xb4\xec\xa7\x80\xeb\x8a\x94 \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedBeam_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x83\x9d\xec\x84\xb1\xeb\x90\x9c \xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8\xeb\xa5\xbc \xea\xb4\x80\xeb\xa6\xac\xed\x95\xa0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x83\x9d\xec\x84\xb1\xeb\x90\x9c \xec\x9d\xb4\xed\x8e\x99\xed\x8a\xb8\xeb\xa5\xbc \xea\xb4\x80\xeb\xa6\xac\xed\x95\xa0 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClusterExplosionFX_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x91\xec\x86\x8d\xed\x83\x84 \xeb\x82\x98\xec\x9d\xb4\xec\x95\x84\xea\xb0\x80\xeb\x9d\xbc\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x91\xec\x86\x8d\xed\x83\x84 \xeb\x82\x98\xec\x9d\xb4\xec\x95\x84\xea\xb0\x80\xeb\x9d\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClusterExplosionSound_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x91\xec\x86\x8d\xed\x83\x84 \xed\x8f\xad\xeb\xb0\x9c \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x91\xec\x86\x8d\xed\x83\x84 \xed\x8f\xad\xeb\xb0\x9c \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EagleClass_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb9\x84\xed\x96\x89\xea\xb8\xb0 \xec\x95\xa1\xed\x84\xb0\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb9\x84\xed\x96\x89\xea\xb8\xb0 \xec\x95\xa1\xed\x84\xb0" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FighterSound_MetaData[] = {
		{ "Category", "Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb9\x84\xed\x96\x89\xea\xb8\xb0 \xec\x86\x8c\xeb\xa6\xac\n" },
#endif
		{ "ModuleRelativePath", "Weapon/Stratagem/StratagemBeacon.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb9\x84\xed\x96\x89\xea\xb8\xb0 \xec\x86\x8c\xeb\xa6\xac" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovement;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Eagle500kgProjectileClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EagleClusterProjectileClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SupplyClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SentryClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_OrbitalLaserClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BeaconActivateSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DelayToStrike;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BeamEffect;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FallingSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedBeam;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClusterExplosionFX;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClusterExplosionSound;
	static const UECodeGen_Private::FClassPropertyParams NewProp_EagleClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FighterSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AStratagemBeacon_OnHit, "OnHit" }, // 2723546696
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStratagemBeacon>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_CollisionComp = { "CollisionComp", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, CollisionComp), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionComp_MetaData), NewProp_CollisionComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, MeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComp_MetaData), NewProp_MeshComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_ProjectileMovement = { "ProjectileMovement", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, ProjectileMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileMovement_MetaData), NewProp_ProjectileMovement_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_Eagle500kgProjectileClass = { "Eagle500kgProjectileClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, Eagle500kgProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHDProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Eagle500kgProjectileClass_MetaData), NewProp_Eagle500kgProjectileClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_EagleClusterProjectileClass = { "EagleClusterProjectileClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, EagleClusterProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHDProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EagleClusterProjectileClass_MetaData), NewProp_EagleClusterProjectileClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_SupplyClass = { "SupplyClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, SupplyClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHDSupplyPod_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SupplyClass_MetaData), NewProp_SupplyClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_SentryClass = { "SentryClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, SentryClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHDSentry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SentryClass_MetaData), NewProp_SentryClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_OrbitalLaserClass = { "OrbitalLaserClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, OrbitalLaserClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AOrbitalLaser_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrbitalLaserClass_MetaData), NewProp_OrbitalLaserClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_BeaconActivateSound = { "BeaconActivateSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, BeaconActivateSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeaconActivateSound_MetaData), NewProp_BeaconActivateSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_DelayToStrike = { "DelayToStrike", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, DelayToStrike), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DelayToStrike_MetaData), NewProp_DelayToStrike_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_BeamEffect = { "BeamEffect", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, BeamEffect), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeamEffect_MetaData), NewProp_BeamEffect_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_FallingSound = { "FallingSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, FallingSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FallingSound_MetaData), NewProp_FallingSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_SpawnedBeam = { "SpawnedBeam", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, SpawnedBeam), Z_Construct_UClass_UNiagaraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnedBeam_MetaData), NewProp_SpawnedBeam_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_ClusterExplosionFX = { "ClusterExplosionFX", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, ClusterExplosionFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClusterExplosionFX_MetaData), NewProp_ClusterExplosionFX_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_ClusterExplosionSound = { "ClusterExplosionSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, ClusterExplosionSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClusterExplosionSound_MetaData), NewProp_ClusterExplosionSound_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_EagleClass = { "EagleClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, EagleClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AEagle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EagleClass_MetaData), NewProp_EagleClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_FighterSound = { "FighterSound", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AStratagemBeacon, FighterSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FighterSound_MetaData), NewProp_FighterSound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AStratagemBeacon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_CollisionComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_MeshComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_ProjectileMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_Eagle500kgProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_EagleClusterProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_SupplyClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_SentryClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_OrbitalLaserClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_BeaconActivateSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_DelayToStrike,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_BeamEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_FallingSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_SpawnedBeam,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_ClusterExplosionFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_ClusterExplosionSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_EagleClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AStratagemBeacon_Statics::NewProp_FighterSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStratagemBeacon_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AStratagemBeacon_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStratagemBeacon_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStratagemBeacon_Statics::ClassParams = {
	&AStratagemBeacon::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AStratagemBeacon_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AStratagemBeacon_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStratagemBeacon_Statics::Class_MetaDataParams), Z_Construct_UClass_AStratagemBeacon_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStratagemBeacon()
{
	if (!Z_Registration_Info_UClass_AStratagemBeacon.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStratagemBeacon.OuterSingleton, Z_Construct_UClass_AStratagemBeacon_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStratagemBeacon.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AStratagemBeacon>()
{
	return AStratagemBeacon::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AStratagemBeacon);
AStratagemBeacon::~AStratagemBeacon() {}
// End Class AStratagemBeacon

// Begin Registration
struct Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStratagemBeacon, AStratagemBeacon::StaticClass, TEXT("AStratagemBeacon"), &Z_Registration_Info_UClass_AStratagemBeacon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStratagemBeacon), 4222527823U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_1028835644(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_StratagemBeacon_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
