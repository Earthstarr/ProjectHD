// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/HDSupplyPod.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHDSupplyPod() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
PROJECTHD_API UClass* Z_Construct_UClass_AHDSupplyPod();
PROJECTHD_API UClass* Z_Construct_UClass_AHDSupplyPod_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_UInteractableInterface_NoRegister();
UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Class AHDSupplyPod Function EndDeploySequence
static const FName NAME_AHDSupplyPod_EndDeploySequence = FName(TEXT("EndDeploySequence"));
void AHDSupplyPod::EndDeploySequence()
{
	UFunction* Func = FindFunctionChecked(NAME_AHDSupplyPod_EndDeploySequence);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AHDSupplyPod_EndDeploySequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "HDSupplyPod.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSupplyPod_EndDeploySequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSupplyPod, nullptr, "EndDeploySequence", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_EndDeploySequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSupplyPod_EndDeploySequence_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AHDSupplyPod_EndDeploySequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSupplyPod_EndDeploySequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AHDSupplyPod Function EndDeploySequence

// Begin Class AHDSupplyPod Function HandleSphereBeginOverlap
struct Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics
{
	struct HDSupplyPod_eventHandleSphereBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x8b\xa4\xec\xa0\x9c \xec\xb6\xa9\xeb\x8f\x8c \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8 \xed\x95\xa8\xec\x88\x98\n" },
#endif
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8b\xa4\xec\xa0\x9c \xec\xb6\xa9\xeb\x8f\x8c \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8 \xed\x95\xa8\xec\x88\x98" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((HDSupplyPod_eventHandleSphereBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HDSupplyPod_eventHandleSphereBeginOverlap_Parms), &Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSupplyPod, nullptr, "HandleSphereBeginOverlap", nullptr, nullptr, Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::HDSupplyPod_eventHandleSphereBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::HDSupplyPod_eventHandleSphereBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHDSupplyPod::execHandleSphereBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSphereBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// End Class AHDSupplyPod Function HandleSphereBeginOverlap

// Begin Class AHDSupplyPod Function HandleSphereEndOverlap
struct Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics
{
	struct HDSupplyPod_eventHandleSphereEndOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "HDSupplyPod.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereEndOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereEndOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HDSupplyPod_eventHandleSphereEndOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::NewProp_OtherBodyIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSupplyPod, nullptr, "HandleSphereEndOverlap", nullptr, nullptr, Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::HDSupplyPod_eventHandleSphereEndOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::HDSupplyPod_eventHandleSphereEndOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHDSupplyPod::execHandleSphereEndOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSphereEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex);
	P_NATIVE_END;
}
// End Class AHDSupplyPod Function HandleSphereEndOverlap

// Begin Class AHDSupplyPod Function StartDeploySequence
static const FName NAME_AHDSupplyPod_StartDeploySequence = FName(TEXT("StartDeploySequence"));
void AHDSupplyPod::StartDeploySequence()
{
	UFunction* Func = FindFunctionChecked(NAME_AHDSupplyPod_StartDeploySequence);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AHDSupplyPod_StartDeploySequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xed\x83\x80\xec\x9e\x84\xeb\x9d\xbc\xec\x9d\xb8 \xec\x97\xb0\xec\xb6\x9c\xec\x9d\x84 \xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xed\x83\x80\xec\x9e\x84\xeb\x9d\xbc\xec\x9d\xb8 \xec\x97\xb0\xec\xb6\x9c\xec\x9d\x84 \xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHDSupplyPod_StartDeploySequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHDSupplyPod, nullptr, "StartDeploySequence", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHDSupplyPod_StartDeploySequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHDSupplyPod_StartDeploySequence_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AHDSupplyPod_StartDeploySequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHDSupplyPod_StartDeploySequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class AHDSupplyPod Function StartDeploySequence

// Begin Class AHDSupplyPod
void AHDSupplyPod::StaticRegisterNativesAHDSupplyPod()
{
	UClass* Class = AHDSupplyPod::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HandleSphereBeginOverlap", &AHDSupplyPod::execHandleSphereBeginOverlap },
		{ "HandleSphereEndOverlap", &AHDSupplyPod::execHandleSphereEndOverlap },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHDSupplyPod);
UClass* Z_Construct_UClass_AHDSupplyPod_NoRegister()
{
	return AHDSupplyPod::StaticClass();
}
struct Z_Construct_UClass_AHDSupplyPod_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HDSupplyPod.h" },
		{ "ModuleRelativePath", "HDSupplyPod.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BodyMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xa3\xa8\xed\x8a\xb8: \xeb\x95\x85\xec\x97\x90 \xeb\xb0\x95\xed\x9e\x88\xeb\x8a\x94 \xeb\xb3\xb8\xec\xb2\xb4\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa3\xa8\xed\x8a\xb8: \xeb\x95\x85\xec\x97\x90 \xeb\xb0\x95\xed\x9e\x88\xeb\x8a\x94 \xeb\xb3\xb8\xec\xb2\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PillarMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9c\x84\xeb\xa1\x9c \xec\x86\x9f\xec\x95\x84\xec\x98\xa4\xeb\xa5\xbc \xea\xb8\xb0\xeb\x91\xa5 (BodyMesh \xec\x9e\x90\xec\x8b\x9d)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9c\x84\xeb\xa1\x9c \xec\x86\x9f\xec\x95\x84\xec\x98\xa4\xeb\xa5\xbc \xea\xb8\xb0\xeb\x91\xa5 (BodyMesh \xec\x9e\x90\xec\x8b\x9d)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LeftSupplyMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x99\xbc\xec\xaa\xbd \xeb\xb3\xb4\xea\xb8\x89 \xec\x83\x81\xec\x9e\x90 (PillarMesh \xec\x9e\x90\xec\x8b\x9d)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x99\xbc\xec\xaa\xbd \xeb\xb3\xb4\xea\xb8\x89 \xec\x83\x81\xec\x9e\x90 (PillarMesh \xec\x9e\x90\xec\x8b\x9d)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightSupplyMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x98\xa4\xeb\xa5\xb8\xec\xaa\xbd \xeb\xb3\xb4\xea\xb8\x89 \xec\x83\x81\xec\x9e\x90 (PillarMesh \xec\x9e\x90\xec\x8b\x9d)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x98\xa4\xeb\xa5\xb8\xec\xaa\xbd \xeb\xb3\xb4\xea\xb8\x89 \xec\x83\x81\xec\x9e\x90 (PillarMesh \xec\x9e\x90\xec\x8b\x9d)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionSphere_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9 \xeb\xb2\x94\xec\x9c\x84\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x83\x81\xed\x98\xb8\xec\x9e\x91\xec\x9a\xa9 \xeb\xb2\x94\xec\x9c\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionWidget_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// E - \xec\x9e\xac\xeb\xb3\xb4\xea\xb8\x89\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "E - \xec\x9e\xac\xeb\xb3\xb4\xea\xb8\x89" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SupplyPickupSound_MetaData[] = {
		{ "Category", "Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb3\xb4\xea\xb8\x89 \xed\x9a\x8d\xeb\x93\x9d \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb3\xb4\xea\xb8\x89 \xed\x9a\x8d\xeb\x93\x9d \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImpactSound_MetaData[] = {
		{ "Category", "Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x95\x85 \xec\xb6\xa9\xeb\x8f\x8c \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x95\x85 \xec\xb6\xa9\xeb\x8f\x8c \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeploySound_MetaData[] = {
		{ "Category", "Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Deploy \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c - \xeb\xb8\x94\xed\x94\x84 Timeline\xec\x97\x90\xec\x84\x9c \xec\x9e\xac\xec\x83\x9d\n" },
#endif
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deploy \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c - \xeb\xb8\x94\xed\x94\x84 Timeline\xec\x97\x90\xec\x84\x9c \xec\x9e\xac\xec\x83\x9d" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnDeploySound_MetaData[] = {
		{ "Category", "Sound" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UnDeploy \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c - \xeb\xb8\x94\xed\x94\x84 Timeline\xec\x97\x90\xec\x84\x9c \xec\x9e\xac\xec\x83\x9d\n" },
#endif
		{ "ModuleRelativePath", "HDSupplyPod.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UnDeploy \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c - \xeb\xb8\x94\xed\x94\x84 Timeline\xec\x97\x90\xec\x84\x9c \xec\x9e\xac\xec\x83\x9d" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BodyMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PillarMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftSupplyMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RightSupplyMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionSphere;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SupplyPickupSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ImpactSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeploySound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UnDeploySound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AHDSupplyPod_EndDeploySequence, "EndDeploySequence" }, // 1323061218
		{ &Z_Construct_UFunction_AHDSupplyPod_HandleSphereBeginOverlap, "HandleSphereBeginOverlap" }, // 4294568502
		{ &Z_Construct_UFunction_AHDSupplyPod_HandleSphereEndOverlap, "HandleSphereEndOverlap" }, // 237657593
		{ &Z_Construct_UFunction_AHDSupplyPod_StartDeploySequence, "StartDeploySequence" }, // 2451599280
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHDSupplyPod>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_BodyMesh = { "BodyMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, BodyMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BodyMesh_MetaData), NewProp_BodyMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_PillarMesh = { "PillarMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, PillarMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PillarMesh_MetaData), NewProp_PillarMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_LeftSupplyMesh = { "LeftSupplyMesh", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, LeftSupplyMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LeftSupplyMesh_MetaData), NewProp_LeftSupplyMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_RightSupplyMesh = { "RightSupplyMesh", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, RightSupplyMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightSupplyMesh_MetaData), NewProp_RightSupplyMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_InteractionSphere = { "InteractionSphere", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, InteractionSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionSphere_MetaData), NewProp_InteractionSphere_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_InteractionWidget = { "InteractionWidget", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, InteractionWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionWidget_MetaData), NewProp_InteractionWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_SupplyPickupSound = { "SupplyPickupSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, SupplyPickupSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SupplyPickupSound_MetaData), NewProp_SupplyPickupSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_ImpactSound = { "ImpactSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, ImpactSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImpactSound_MetaData), NewProp_ImpactSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_DeploySound = { "DeploySound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, DeploySound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeploySound_MetaData), NewProp_DeploySound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_UnDeploySound = { "UnDeploySound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHDSupplyPod, UnDeploySound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnDeploySound_MetaData), NewProp_UnDeploySound_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHDSupplyPod_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_BodyMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_PillarMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_LeftSupplyMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_RightSupplyMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_InteractionSphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_InteractionWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_SupplyPickupSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_ImpactSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_DeploySound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHDSupplyPod_Statics::NewProp_UnDeploySound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDSupplyPod_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHDSupplyPod_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHDSupplyPod_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AHDSupplyPod_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(AHDSupplyPod, IInteractableInterface), false },  // 2613974763
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHDSupplyPod_Statics::ClassParams = {
	&AHDSupplyPod::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AHDSupplyPod_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AHDSupplyPod_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHDSupplyPod_Statics::Class_MetaDataParams), Z_Construct_UClass_AHDSupplyPod_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHDSupplyPod()
{
	if (!Z_Registration_Info_UClass_AHDSupplyPod.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHDSupplyPod.OuterSingleton, Z_Construct_UClass_AHDSupplyPod_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHDSupplyPod.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AHDSupplyPod>()
{
	return AHDSupplyPod::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHDSupplyPod);
AHDSupplyPod::~AHDSupplyPod() {}
// End Class AHDSupplyPod

// Begin Registration
struct Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHDSupplyPod, AHDSupplyPod::StaticClass, TEXT("AHDSupplyPod"), &Z_Registration_Info_UClass_AHDSupplyPod, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHDSupplyPod), 2777104382U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_219174517(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
