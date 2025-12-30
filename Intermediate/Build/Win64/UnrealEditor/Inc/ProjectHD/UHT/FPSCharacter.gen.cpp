// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/FPSCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSCharacter() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AFPSCharacter();
PROJECTHD_API UClass* Z_Construct_UClass_AFPSCharacter_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AHDProjectile_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AStratagemBeacon_NoRegister();
PROJECTHD_API UEnum* Z_Construct_UEnum_ProjectHD_EStratagemDirection();
PROJECTHD_API UEnum* Z_Construct_UEnum_ProjectHD_EStratagemType();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature();
PROJECTHD_API UScriptStruct* Z_Construct_UScriptStruct_FStratagemData();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_ProjectHD();
// End Cross Module References

// Begin Enum EStratagemDirection
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EStratagemDirection;
static UEnum* EStratagemDirection_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EStratagemDirection.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EStratagemDirection.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ProjectHD_EStratagemDirection, (UObject*)Z_Construct_UPackage__Script_ProjectHD(), TEXT("EStratagemDirection"));
	}
	return Z_Registration_Info_UEnum_EStratagemDirection.OuterSingleton;
}
template<> PROJECTHD_API UEnum* StaticEnum<EStratagemDirection>()
{
	return EStratagemDirection_StaticEnum();
}
struct Z_Construct_UEnum_ProjectHD_EStratagemDirection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1. \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "Down.Name", "EStratagemDirection::Down" },
		{ "Left.Name", "EStratagemDirection::Left" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
		{ "None.Name", "EStratagemDirection::None" },
		{ "Right.Name", "EStratagemDirection::Right" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1. \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
		{ "Up.Name", "EStratagemDirection::Up" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStratagemDirection::None", (int64)EStratagemDirection::None },
		{ "EStratagemDirection::Up", (int64)EStratagemDirection::Up },
		{ "EStratagemDirection::Down", (int64)EStratagemDirection::Down },
		{ "EStratagemDirection::Left", (int64)EStratagemDirection::Left },
		{ "EStratagemDirection::Right", (int64)EStratagemDirection::Right },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ProjectHD_EStratagemDirection_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ProjectHD,
	nullptr,
	"EStratagemDirection",
	"EStratagemDirection",
	Z_Construct_UEnum_ProjectHD_EStratagemDirection_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHD_EStratagemDirection_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHD_EStratagemDirection_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ProjectHD_EStratagemDirection_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ProjectHD_EStratagemDirection()
{
	if (!Z_Registration_Info_UEnum_EStratagemDirection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EStratagemDirection.InnerSingleton, Z_Construct_UEnum_ProjectHD_EStratagemDirection_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EStratagemDirection.InnerSingleton;
}
// End Enum EStratagemDirection

// Begin Enum EStratagemType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EStratagemType;
static UEnum* EStratagemType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EStratagemType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EStratagemType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ProjectHD_EStratagemType, (UObject*)Z_Construct_UPackage__Script_ProjectHD(), TEXT("EStratagemType"));
	}
	return Z_Registration_Info_UEnum_EStratagemType.OuterSingleton;
}
template<> PROJECTHD_API UEnum* StaticEnum<EStratagemType>()
{
	return EStratagemType_StaticEnum();
}
struct Z_Construct_UEnum_ProjectHD_EStratagemType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Bomb500kg.Name", "EStratagemType::Bomb500kg" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 2. \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd8\xbe\xef\xbf\xbd \xef\xbf\xbd\xcf\xb9\xc7\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xbe\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd)\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
		{ "Supply.Name", "EStratagemType::Supply" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "2. \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd8\xbe\xef\xbf\xbd \xef\xbf\xbd\xcf\xb9\xc7\xb7\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd6\xbe\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd)" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStratagemType::Bomb500kg", (int64)EStratagemType::Bomb500kg },
		{ "EStratagemType::Supply", (int64)EStratagemType::Supply },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ProjectHD_EStratagemType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ProjectHD,
	nullptr,
	"EStratagemType",
	"EStratagemType",
	Z_Construct_UEnum_ProjectHD_EStratagemType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHD_EStratagemType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHD_EStratagemType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ProjectHD_EStratagemType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ProjectHD_EStratagemType()
{
	if (!Z_Registration_Info_UEnum_EStratagemType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EStratagemType.InnerSingleton, Z_Construct_UEnum_ProjectHD_EStratagemType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EStratagemType.InnerSingleton;
}
// End Enum EStratagemType

// Begin ScriptStruct FStratagemData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_StratagemData;
class UScriptStruct* FStratagemData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_StratagemData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_StratagemData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStratagemData, (UObject*)Z_Construct_UPackage__Script_ProjectHD(), TEXT("StratagemData"));
	}
	return Z_Registration_Info_UScriptStruct_StratagemData.OuterSingleton;
}
template<> PROJECTHD_API UScriptStruct* StaticStruct<FStratagemData>()
{
	return FStratagemData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FStratagemData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 3. \xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "3. \xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Command_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeaconColor_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Command;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BeaconColor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStratagemData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner = { "Command", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ProjectHD_EStratagemDirection, METADATA_PARAMS(0, nullptr) }; // 3802363231
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, Command), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Command_MetaData), NewProp_Command_MetaData) }; // 3802363231
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_BeaconColor = { "BeaconColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, BeaconColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeaconColor_MetaData), NewProp_BeaconColor_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, Type), Z_Construct_UEnum_ProjectHD_EStratagemType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 2109228470
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStratagemData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_BeaconColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStratagemData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStratagemData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
	nullptr,
	&NewStructOps,
	"StratagemData",
	Z_Construct_UScriptStruct_FStratagemData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStratagemData_Statics::PropPointers),
	sizeof(FStratagemData),
	alignof(FStratagemData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStratagemData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FStratagemData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FStratagemData()
{
	if (!Z_Registration_Info_UScriptStruct_StratagemData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_StratagemData.InnerSingleton, Z_Construct_UScriptStruct_FStratagemData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_StratagemData.InnerSingleton;
}
// End ScriptStruct FStratagemData

// Begin Delegate FOnAmmoChangedSignature
struct Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnAmmoChangedSignature_Parms
	{
		int32 NewAmmo;
		int32 NewMag;
		int32 MaxMag;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 4. \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd)\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "4. \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc3\xbc\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc7\xb0\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewMag;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMag;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::NewProp_NewAmmo = { "NewAmmo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnAmmoChangedSignature_Parms, NewAmmo), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::NewProp_NewMag = { "NewMag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnAmmoChangedSignature_Parms, NewMag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::NewProp_MaxMag = { "MaxMag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnAmmoChangedSignature_Parms, MaxMag), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::NewProp_NewAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::NewProp_NewMag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::NewProp_MaxMag,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnAmmoChangedSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::_Script_ProjectHD_eventOnAmmoChangedSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::_Script_ProjectHD_eventOnAmmoChangedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAmmoChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnAmmoChangedSignature, int32 NewAmmo, int32 NewMag, int32 MaxMag)
{
	struct _Script_ProjectHD_eventOnAmmoChangedSignature_Parms
	{
		int32 NewAmmo;
		int32 NewMag;
		int32 MaxMag;
	};
	_Script_ProjectHD_eventOnAmmoChangedSignature_Parms Parms;
	Parms.NewAmmo=NewAmmo;
	Parms.NewMag=NewMag;
	Parms.MaxMag=MaxMag;
	OnAmmoChangedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnAmmoChangedSignature

// Begin Delegate FOnHitEnemySignature
struct Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnHitEnemySignature_Parms
	{
		bool bIsHeadshot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsHeadshot_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHeadshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::NewProp_bIsHeadshot_SetBit(void* Obj)
{
	((_Script_ProjectHD_eventOnHitEnemySignature_Parms*)Obj)->bIsHeadshot = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::NewProp_bIsHeadshot = { "bIsHeadshot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_ProjectHD_eventOnHitEnemySignature_Parms), &Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::NewProp_bIsHeadshot_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::NewProp_bIsHeadshot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnHitEnemySignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::_Script_ProjectHD_eventOnHitEnemySignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::_Script_ProjectHD_eventOnHitEnemySignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnHitEnemySignature_DelegateWrapper(const FMulticastScriptDelegate& OnHitEnemySignature, bool bIsHeadshot)
{
	struct _Script_ProjectHD_eventOnHitEnemySignature_Parms
	{
		bool bIsHeadshot;
	};
	_Script_ProjectHD_eventOnHitEnemySignature_Parms Parms;
	Parms.bIsHeadshot=bIsHeadshot ? true : false;
	OnHitEnemySignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnHitEnemySignature

// Begin Delegate FOnStratagemStepUpdated
struct Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnStratagemStepUpdated_Parms
	{
		int32 NewStep;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewStep;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::NewProp_NewStep = { "NewStep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnStratagemStepUpdated_Parms, NewStep), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::NewProp_NewStep,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnStratagemStepUpdated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::_Script_ProjectHD_eventOnStratagemStepUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::_Script_ProjectHD_eventOnStratagemStepUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnStratagemStepUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnStratagemStepUpdated, int32 NewStep)
{
	struct _Script_ProjectHD_eventOnStratagemStepUpdated_Parms
	{
		int32 NewStep;
	};
	_Script_ProjectHD_eventOnStratagemStepUpdated_Parms Parms;
	Parms.NewStep=NewStep;
	OnStratagemStepUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnStratagemStepUpdated

// Begin Delegate FOnStratagemUpdate
struct Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnStratagemUpdate_Parms
	{
		int32 StratagemIndex;
		int32 CurrentStep;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StratagemIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStep;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::NewProp_StratagemIndex = { "StratagemIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnStratagemUpdate_Parms, StratagemIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::NewProp_CurrentStep = { "CurrentStep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnStratagemUpdate_Parms, CurrentStep), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::NewProp_StratagemIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::NewProp_CurrentStep,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnStratagemUpdate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::_Script_ProjectHD_eventOnStratagemUpdate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::_Script_ProjectHD_eventOnStratagemUpdate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnStratagemUpdate_DelegateWrapper(const FMulticastScriptDelegate& OnStratagemUpdate, int32 StratagemIndex, int32 CurrentStep)
{
	struct _Script_ProjectHD_eventOnStratagemUpdate_Parms
	{
		int32 StratagemIndex;
		int32 CurrentStep;
	};
	_Script_ProjectHD_eventOnStratagemUpdate_Parms Parms;
	Parms.StratagemIndex=StratagemIndex;
	Parms.CurrentStep=CurrentStep;
	OnStratagemUpdate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnStratagemUpdate

// Begin Delegate FOnStratagemStackUpdated
struct Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnStratagemStackUpdated_Parms
	{
		TArray<EStratagemDirection> InputStack;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputStack_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InputStack_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InputStack_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InputStack;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack_Inner = { "InputStack", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ProjectHD_EStratagemDirection, METADATA_PARAMS(0, nullptr) }; // 3802363231
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack = { "InputStack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnStratagemStackUpdated_Parms, InputStack), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputStack_MetaData), NewProp_InputStack_MetaData) }; // 3802363231
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnStratagemStackUpdated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::_Script_ProjectHD_eventOnStratagemStackUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::_Script_ProjectHD_eventOnStratagemStackUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnStratagemStackUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnStratagemStackUpdated, TArray<EStratagemDirection> const& InputStack)
{
	struct _Script_ProjectHD_eventOnStratagemStackUpdated_Parms
	{
		TArray<EStratagemDirection> InputStack;
	};
	_Script_ProjectHD_eventOnStratagemStackUpdated_Parms Parms;
	Parms.InputStack=InputStack;
	OnStratagemStackUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnStratagemStackUpdated

// Begin Class AFPSCharacter Function FinishReload
struct Z_Construct_UFunction_AFPSCharacter_FinishReload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_FinishReload_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "FinishReload", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_FinishReload_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_FinishReload_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFPSCharacter_FinishReload()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_FinishReload_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execFinishReload)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FinishReload();
	P_NATIVE_END;
}
// End Class AFPSCharacter Function FinishReload

// Begin Class AFPSCharacter Function FireWeapon
struct Z_Construct_UFunction_AFPSCharacter_FireWeapon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_FireWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "FireWeapon", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_FireWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_FireWeapon_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFPSCharacter_FireWeapon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_FireWeapon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execFireWeapon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FireWeapon();
	P_NATIVE_END;
}
// End Class AFPSCharacter Function FireWeapon

// Begin Class AFPSCharacter Function OnAimCompleted
static FName NAME_AFPSCharacter_OnAimCompleted = FName(TEXT("OnAimCompleted"));
void AFPSCharacter::OnAimCompleted()
{
	ProcessEvent(FindFunctionChecked(NAME_AFPSCharacter_OnAimCompleted),NULL);
}
struct Z_Construct_UFunction_AFPSCharacter_OnAimCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_OnAimCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "OnAimCompleted", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_OnAimCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_OnAimCompleted_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFPSCharacter_OnAimCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_OnAimCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execOnAimCompleted)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAimCompleted_Implementation();
	P_NATIVE_END;
}
// End Class AFPSCharacter Function OnAimCompleted

// Begin Class AFPSCharacter Function OnAimStarted
static FName NAME_AFPSCharacter_OnAimStarted = FName(TEXT("OnAimStarted"));
void AFPSCharacter::OnAimStarted()
{
	ProcessEvent(FindFunctionChecked(NAME_AFPSCharacter_OnAimStarted),NULL);
}
struct Z_Construct_UFunction_AFPSCharacter_OnAimStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_OnAimStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "OnAimStarted", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_OnAimStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_OnAimStarted_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFPSCharacter_OnAimStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_OnAimStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execOnAimStarted)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAimStarted_Implementation();
	P_NATIVE_END;
}
// End Class AFPSCharacter Function OnAimStarted

// Begin Class AFPSCharacter
void AFPSCharacter::StaticRegisterNativesAFPSCharacter()
{
	UClass* Class = AFPSCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "FinishReload", &AFPSCharacter::execFinishReload },
		{ "FireWeapon", &AFPSCharacter::execFireWeapon },
		{ "OnAimCompleted", &AFPSCharacter::execOnAimCompleted },
		{ "OnAimStarted", &AFPSCharacter::execOnAimStarted },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFPSCharacter);
UClass* Z_Construct_UClass_AFPSCharacter_NoRegister()
{
	return AFPSCharacter::StaticClass();
}
struct Z_Construct_UClass_AFPSCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FPSCharacter.h" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalWalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xcc\xb5\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xcc\xb5\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimWalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadWalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAiming_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimRotationRecoveryTime_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecoilPitch_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecoilYaw_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireCameraShakeClass_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainHUDWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainHUDWidget_MetaData[] = {
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MuzzleFlashFX_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmoInMag_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xc5\xba\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xc5\xba\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc3\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAmmo_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMagCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMagCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadMontage_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimPitch_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadSound_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeaconClass_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ----------------\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd---------------------\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "----------------\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\xef\xbf\xbd\xef\xbf\xbd\xc5\xb8\xef\xbf\xbd\xef\xbf\xbd---------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrowForce_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ThrowBeacon\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd ThrowBeacon\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSelectingStratagem_MetaData[] = {
		{ "Category", "Stratagem" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemList_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xdf\xba\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd: StratagemList\xef\xbf\xbd\xef\xbf\xbd FStratagemData \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd.\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xdf\xba\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xb8\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd: StratagemList\xef\xbf\xbd\xef\xbf\xbd FStratagemData \xc5\xb8\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd5\xb4\xcf\xb4\xef\xbf\xbd." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThirdPersonCamera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xd4\xb7\xef\xbf\xbd \xef\xbf\xbd\xc3\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xd4\xb7\xef\xbf\xbd \xef\xbf\xbd\xc3\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemMenuAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemInputAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStratagemStepUpdated_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae\n" },
#endif
		{ "ModuleRelativePath", "FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xc6\xae" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAmmoChanged_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHitEnemy_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStratagemUpdate_MetaData[] = {
		{ "Category", "Stratagem" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStratagemStackUpdated_MetaData[] = {
		{ "Category", "Stratagem" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseSensitivity_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRange_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalWalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimWalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReloadWalkSpeed;
	static void NewProp_bIsAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAiming;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimRotationRecoveryTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecoilPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecoilYaw;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FireCameraShakeClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainHUDWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MainHUDWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MuzzleFlashFX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmoInMag;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentMagCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMagCount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadMontage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimPitch;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadSound;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BeaconClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrowForce;
	static void NewProp_bIsSelectingStratagem_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSelectingStratagem;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StratagemList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StratagemList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThirdPersonCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AimAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemMenuAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemInputAction;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStratagemStepUpdated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAmmoChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHitEnemy;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStratagemUpdate;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStratagemStackUpdated;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MouseSensitivity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponMesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRange;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AFPSCharacter_FinishReload, "FinishReload" }, // 1804282448
		{ &Z_Construct_UFunction_AFPSCharacter_FireWeapon, "FireWeapon" }, // 2155339219
		{ &Z_Construct_UFunction_AFPSCharacter_OnAimCompleted, "OnAimCompleted" }, // 2757603695
		{ &Z_Construct_UFunction_AFPSCharacter_OnAimStarted, "OnAimStarted" }, // 154043665
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_NormalWalkSpeed = { "NormalWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, NormalWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalWalkSpeed_MetaData), NewProp_NormalWalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimWalkSpeed = { "AimWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimWalkSpeed_MetaData), NewProp_AimWalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadWalkSpeed = { "ReloadWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ReloadWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadWalkSpeed_MetaData), NewProp_ReloadWalkSpeed_MetaData) };
void Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming_SetBit(void* Obj)
{
	((AFPSCharacter*)Obj)->bIsAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming = { "bIsAiming", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSCharacter), &Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAiming_MetaData), NewProp_bIsAiming_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimRotationRecoveryTime = { "AimRotationRecoveryTime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimRotationRecoveryTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimRotationRecoveryTime_MetaData), NewProp_AimRotationRecoveryTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRate_MetaData), NewProp_FireRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilPitch = { "RecoilPitch", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, RecoilPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecoilPitch_MetaData), NewProp_RecoilPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilYaw = { "RecoilYaw", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, RecoilYaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecoilYaw_MetaData), NewProp_RecoilYaw_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireCameraShakeClass = { "FireCameraShakeClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireCameraShakeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireCameraShakeClass_MetaData), NewProp_FireCameraShakeClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidgetClass = { "MainHUDWidgetClass", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MainHUDWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainHUDWidgetClass_MetaData), NewProp_MainHUDWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidget = { "MainHUDWidget", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MainHUDWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainHUDWidget_MetaData), NewProp_MainHUDWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ProjectileClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHDProjectile_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectileClass_MetaData), NewProp_ProjectileClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MuzzleFlashFX = { "MuzzleFlashFX", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MuzzleFlashFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MuzzleFlashFX_MetaData), NewProp_MuzzleFlashFX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxAmmoInMag = { "MaxAmmoInMag", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MaxAmmoInMag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmoInMag_MetaData), NewProp_MaxAmmoInMag_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentAmmo = { "CurrentAmmo", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAmmo_MetaData), NewProp_CurrentAmmo_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentMagCount = { "CurrentMagCount", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentMagCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMagCount_MetaData), NewProp_CurrentMagCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxMagCount = { "MaxMagCount", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MaxMagCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMagCount_MetaData), NewProp_MaxMagCount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadMontage = { "ReloadMontage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ReloadMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadMontage_MetaData), NewProp_ReloadMontage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimPitch = { "AimPitch", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimPitch_MetaData), NewProp_AimPitch_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireSound_MetaData), NewProp_FireSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadSound = { "ReloadSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ReloadSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadSound_MetaData), NewProp_ReloadSound_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_BeaconClass = { "BeaconClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, BeaconClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AStratagemBeacon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeaconClass_MetaData), NewProp_BeaconClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThrowForce = { "ThrowForce", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ThrowForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrowForce_MetaData), NewProp_ThrowForce_MetaData) };
void Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem_SetBit(void* Obj)
{
	((AFPSCharacter*)Obj)->bIsSelectingStratagem = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem = { "bIsSelectingStratagem", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSCharacter), &Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSelectingStratagem_MetaData), NewProp_bIsSelectingStratagem_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList_Inner = { "StratagemList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FStratagemData, METADATA_PARAMS(0, nullptr) }; // 3073176403
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList = { "StratagemList", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemList_MetaData), NewProp_StratagemList_MetaData) }; // 3073176403
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThirdPersonCamera = { "ThirdPersonCamera", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ThirdPersonCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThirdPersonCamera_MetaData), NewProp_ThirdPersonCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMappingContext = { "StratagemMappingContext", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemMappingContext_MetaData), NewProp_StratagemMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireAction = { "FireAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireAction_MetaData), NewProp_FireAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimAction = { "AimAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimAction_MetaData), NewProp_AimAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadAction = { "ReloadAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ReloadAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadAction_MetaData), NewProp_ReloadAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMenuAction = { "StratagemMenuAction", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemMenuAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemMenuAction_MetaData), NewProp_StratagemMenuAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemInputAction = { "StratagemInputAction", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemInputAction_MetaData), NewProp_StratagemInputAction_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStepUpdated = { "OnStratagemStepUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStratagemStepUpdated), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStratagemStepUpdated_MetaData), NewProp_OnStratagemStepUpdated_MetaData) }; // 432582159
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnAmmoChanged = { "OnAmmoChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnAmmoChanged), Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAmmoChanged_MetaData), NewProp_OnAmmoChanged_MetaData) }; // 2151632710
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnHitEnemy = { "OnHitEnemy", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnHitEnemy), Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHitEnemy_MetaData), NewProp_OnHitEnemy_MetaData) }; // 2146306063
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemUpdate = { "OnStratagemUpdate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStratagemUpdate), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStratagemUpdate_MetaData), NewProp_OnStratagemUpdate_MetaData) }; // 235073054
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStackUpdated = { "OnStratagemStackUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStratagemStackUpdated), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStratagemStackUpdated_MetaData), NewProp_OnStratagemStackUpdated_MetaData) }; // 1711578276
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MouseSensitivity = { "MouseSensitivity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MouseSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseSensitivity_MetaData), NewProp_MouseSensitivity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponMesh = { "WeaponMesh", nullptr, (EPropertyFlags)0x00200800000b0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, WeaponMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponMesh_MetaData), NewProp_WeaponMesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireRange = { "FireRange", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRange_MetaData), NewProp_FireRange_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFPSCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_NormalWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimRotationRecoveryTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireCameraShakeClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ProjectileClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MuzzleFlashFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxAmmoInMag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentMagCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxMagCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_BeaconClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThrowForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThirdPersonCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMenuAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemInputAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStepUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnAmmoChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnHitEnemy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemUpdate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStackUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MouseSensitivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireRange,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFPSCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFPSCharacter_Statics::ClassParams = {
	&AFPSCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AFPSCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AFPSCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AFPSCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFPSCharacter()
{
	if (!Z_Registration_Info_UClass_AFPSCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFPSCharacter.OuterSingleton, Z_Construct_UClass_AFPSCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFPSCharacter.OuterSingleton;
}
template<> PROJECTHD_API UClass* StaticClass<AFPSCharacter>()
{
	return AFPSCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSCharacter);
AFPSCharacter::~AFPSCharacter() {}
// End Class AFPSCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EStratagemDirection_StaticEnum, TEXT("EStratagemDirection"), &Z_Registration_Info_UEnum_EStratagemDirection, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3802363231U) },
		{ EStratagemType_StaticEnum, TEXT("EStratagemType"), &Z_Registration_Info_UEnum_EStratagemType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2109228470U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FStratagemData::StaticStruct, Z_Construct_UScriptStruct_FStratagemData_Statics::NewStructOps, TEXT("StratagemData"), &Z_Registration_Info_UScriptStruct_StratagemData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStratagemData), 3073176403U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFPSCharacter, AFPSCharacter::StaticClass, TEXT("AFPSCharacter"), &Z_Registration_Info_UClass_AFPSCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFPSCharacter), 3803439528U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_4236775218(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_JW_Unreal_ProjectHD_Source_ProjectHD_FPSCharacter_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
