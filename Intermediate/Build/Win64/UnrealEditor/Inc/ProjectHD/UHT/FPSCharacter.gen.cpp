// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "GameplayAbilities/Public/GameplayAbilitySpecHandle.h"
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
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemComponent_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAbilitySystemInterface_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility_NoRegister();
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayEffect_NoRegister();
GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAbilitySpecHandle();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AFPSCharacter();
PROJECTHD_API UClass* Z_Construct_UClass_AFPSCharacter_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_AStratagemBeacon_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_UPlayerAttributeSet_NoRegister();
PROJECTHD_API UClass* Z_Construct_UClass_UWeaponDataAsset_NoRegister();
PROJECTHD_API UEnum* Z_Construct_UEnum_ProjectHD_EAbilityInputID();
PROJECTHD_API UEnum* Z_Construct_UEnum_ProjectHD_EStratagemDirection();
PROJECTHD_API UEnum* Z_Construct_UEnum_ProjectHD_EStratagemType();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature();
PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature();
PROJECTHD_API UScriptStruct* Z_Construct_UScriptStruct_FStratagemData();
PROJECTHD_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponInstance();
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
		{ "Comment", "// \xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xec\x9e\x85\xeb\xa0\xa5 \xed\x99\x94\xec\x82\xb4\xed\x91\x9c \xeb\xb0\xa9\xed\x96\xa5\n" },
#endif
		{ "Down.Name", "EStratagemDirection::Down" },
		{ "Left.Name", "EStratagemDirection::Left" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
		{ "None.Name", "EStratagemDirection::None" },
		{ "Right.Name", "EStratagemDirection::Right" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xec\x9e\x85\xeb\xa0\xa5 \xed\x99\x94\xec\x82\xb4\xed\x91\x9c \xeb\xb0\xa9\xed\x96\xa5" },
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
		{ "Comment", "// \xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xed\x83\x80\xec\x9e\x85\n" },
#endif
		{ "EagleCluster.Name", "EStratagemType::EagleCluster" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
		{ "Sentry.Name", "EStratagemType::Sentry" },
		{ "Supply.Name", "EStratagemType::Supply" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xed\x83\x80\xec\x9e\x85" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStratagemType::Bomb500kg", (int64)EStratagemType::Bomb500kg },
		{ "EStratagemType::Supply", (int64)EStratagemType::Supply },
		{ "EStratagemType::EagleCluster", (int64)EStratagemType::EagleCluster },
		{ "EStratagemType::Sentry", (int64)EStratagemType::Sentry },
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
		{ "Comment", "// \xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98 \xec\x9d\xb4\xeb\xaf\xb8\xec\xa7\x80\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xec\x95\x84\xec\x9d\xb4\xec\xbd\x98 \xec\x9d\xb4\xeb\xaf\xb8\xec\xa7\x80" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Command_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeaconColor_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "StratagemData" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCooldown_MetaData[] = {
		{ "Category", "StratagemData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xbf\xa8\xed\x83\x80\xec\x9e\x84 \xec\x84\xa4\xec\xa0\x95 (\xec\xb4\x9d \xec\x8b\x9c\xea\xb0\x84)\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xbf\xa8\xed\x83\x80\xec\x9e\x84 \xec\x84\xa4\xec\xa0\x95 (\xec\xb4\x9d \xec\x8b\x9c\xea\xb0\x84)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCooldown_MetaData[] = {
		{ "Category", "StratagemData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x98\x84\xec\x9e\xac \xeb\x82\xa8\xec\x9d\x80 \xec\xbf\xa8\xed\x83\x80\xec\x9e\x84 \xec\x8b\x9c\xea\xb0\x84\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xeb\x82\xa8\xec\x9d\x80 \xec\xbf\xa8\xed\x83\x80\xec\x9e\x84 \xec\x8b\x9c\xea\xb0\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsOnCooldown_MetaData[] = {
		{ "Category", "StratagemData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x98\x84\xec\x9e\xac \xec\xbf\xa8\xed\x83\x80\xec\x9e\x84 \xec\xa4\x91\xec\x9d\xb8\xec\xa7\x80 \xec\x97\xac\xeb\xb6\x80\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xec\xbf\xa8\xed\x83\x80\xec\x9e\x84 \xec\xa4\x91\xec\x9d\xb8\xec\xa7\x80 \xec\x97\xac\xeb\xb6\x80" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Command;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BeaconColor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCooldown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentCooldown;
	static void NewProp_bIsOnCooldown_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOnCooldown;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStratagemData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner = { "Command", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ProjectHD_EStratagemDirection, METADATA_PARAMS(0, nullptr) }; // 2109644036
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, Command), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Command_MetaData), NewProp_Command_MetaData) }; // 2109644036
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_BeaconColor = { "BeaconColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, BeaconColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeaconColor_MetaData), NewProp_BeaconColor_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, Type), Z_Construct_UEnum_ProjectHD_EStratagemType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 1496983112
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_MaxCooldown = { "MaxCooldown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, MaxCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCooldown_MetaData), NewProp_MaxCooldown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_CurrentCooldown = { "CurrentCooldown", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FStratagemData, CurrentCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCooldown_MetaData), NewProp_CurrentCooldown_MetaData) };
void Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_bIsOnCooldown_SetBit(void* Obj)
{
	((FStratagemData*)Obj)->bIsOnCooldown = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_bIsOnCooldown = { "bIsOnCooldown", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FStratagemData), &Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_bIsOnCooldown_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsOnCooldown_MetaData), NewProp_bIsOnCooldown_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStratagemData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_BeaconColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_MaxCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_CurrentCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStratagemData_Statics::NewProp_bIsOnCooldown,
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

// Begin ScriptStruct FWeaponInstance
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_WeaponInstance;
class UScriptStruct* FWeaponInstance::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_WeaponInstance.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_WeaponInstance.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWeaponInstance, (UObject*)Z_Construct_UPackage__Script_ProjectHD(), TEXT("WeaponInstance"));
	}
	return Z_Registration_Info_UScriptStruct_WeaponInstance.OuterSingleton;
}
template<> PROJECTHD_API UScriptStruct* StaticStruct<FWeaponInstance>()
{
	return FWeaponInstance::StaticStruct();
}
struct Z_Construct_UScriptStruct_FWeaponInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xac\xb4\xea\xb8\xb0 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xac\xb4\xea\xb8\xb0 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponData_MetaData[] = {
		{ "Category", "WeaponInstance" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAmmoCount_MetaData[] = {
		{ "Category", "WeaponInstance" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMagCount_MetaData[] = {
		{ "Category", "WeaponInstance" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponData;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAmmoCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentMagCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWeaponInstance>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FWeaponInstance_Statics::NewProp_WeaponData = { "WeaponData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponInstance, WeaponData), Z_Construct_UClass_UWeaponDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponData_MetaData), NewProp_WeaponData_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FWeaponInstance_Statics::NewProp_CurrentAmmoCount = { "CurrentAmmoCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponInstance, CurrentAmmoCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAmmoCount_MetaData), NewProp_CurrentAmmoCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FWeaponInstance_Statics::NewProp_CurrentMagCount = { "CurrentMagCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FWeaponInstance, CurrentMagCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMagCount_MetaData), NewProp_CurrentMagCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWeaponInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponInstance_Statics::NewProp_WeaponData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponInstance_Statics::NewProp_CurrentAmmoCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponInstance_Statics::NewProp_CurrentMagCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponInstance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWeaponInstance_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ProjectHD,
	nullptr,
	&NewStructOps,
	"WeaponInstance",
	Z_Construct_UScriptStruct_FWeaponInstance_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponInstance_Statics::PropPointers),
	sizeof(FWeaponInstance),
	alignof(FWeaponInstance),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponInstance_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FWeaponInstance_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FWeaponInstance()
{
	if (!Z_Registration_Info_UScriptStruct_WeaponInstance.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_WeaponInstance.InnerSingleton, Z_Construct_UScriptStruct_FWeaponInstance_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_WeaponInstance.InnerSingleton;
}
// End ScriptStruct FWeaponInstance

// Begin Enum EAbilityInputID
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAbilityInputID;
static UEnum* EAbilityInputID_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAbilityInputID.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAbilityInputID.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ProjectHD_EAbilityInputID, (UObject*)Z_Construct_UPackage__Script_ProjectHD(), TEXT("EAbilityInputID"));
	}
	return Z_Registration_Info_UEnum_EAbilityInputID.OuterSingleton;
}
template<> PROJECTHD_API UEnum* StaticEnum<EAbilityInputID>()
{
	return EAbilityInputID_StaticEnum();
}
struct Z_Construct_UEnum_ProjectHD_EAbilityInputID_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Aim.Name", "EAbilityInputID::Aim" },
		{ "BlueprintType", "true" },
		{ "Cancel.Name", "EAbilityInputID::Cancel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// GAS\n" },
#endif
		{ "Confirm.Name", "EAbilityInputID::Confirm" },
		{ "Fire.Name", "EAbilityInputID::Fire" },
		{ "Grenade.Name", "EAbilityInputID::Grenade" },
		{ "Jump.Comment", "// \xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84\xec\x9a\xa9 ID\n" },
		{ "Jump.Name", "EAbilityInputID::Jump" },
		{ "Jump.ToolTip", "\xec\x9e\xac\xec\x9e\xa5\xec\xa0\x84\xec\x9a\xa9 ID" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
		{ "None.Name", "EAbilityInputID::None" },
		{ "Reload.Comment", "// \xec\x82\xac\xea\xb2\xa9\xec\x9a\xa9 ID\n" },
		{ "Reload.Name", "EAbilityInputID::Reload" },
		{ "Reload.ToolTip", "\xec\x82\xac\xea\xb2\xa9\xec\x9a\xa9 ID" },
		{ "Sprint.Comment", "// \xec\xa0\x90\xed\x94\x84\xec\x9a\xa9 ID\n" },
		{ "Sprint.Name", "EAbilityInputID::Sprint" },
		{ "Sprint.ToolTip", "\xec\xa0\x90\xed\x94\x84\xec\x9a\xa9 ID" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GAS" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAbilityInputID::None", (int64)EAbilityInputID::None },
		{ "EAbilityInputID::Confirm", (int64)EAbilityInputID::Confirm },
		{ "EAbilityInputID::Cancel", (int64)EAbilityInputID::Cancel },
		{ "EAbilityInputID::Aim", (int64)EAbilityInputID::Aim },
		{ "EAbilityInputID::Fire", (int64)EAbilityInputID::Fire },
		{ "EAbilityInputID::Reload", (int64)EAbilityInputID::Reload },
		{ "EAbilityInputID::Jump", (int64)EAbilityInputID::Jump },
		{ "EAbilityInputID::Sprint", (int64)EAbilityInputID::Sprint },
		{ "EAbilityInputID::Grenade", (int64)EAbilityInputID::Grenade },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ProjectHD_EAbilityInputID_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ProjectHD,
	nullptr,
	"EAbilityInputID",
	"EAbilityInputID",
	Z_Construct_UEnum_ProjectHD_EAbilityInputID_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHD_EAbilityInputID_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ProjectHD_EAbilityInputID_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ProjectHD_EAbilityInputID_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ProjectHD_EAbilityInputID()
{
	if (!Z_Registration_Info_UEnum_EAbilityInputID.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAbilityInputID.InnerSingleton, Z_Construct_UEnum_ProjectHD_EAbilityInputID_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAbilityInputID.InnerSingleton;
}
// End Enum EAbilityInputID

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
		{ "Comment", "// \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 \xec\x84\xa0\xec\x96\xb8\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 \xec\x84\xa0\xec\x96\xb8" },
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
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
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
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
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
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
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
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
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
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack_Inner = { "InputStack", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_ProjectHD_EStratagemDirection, METADATA_PARAMS(0, nullptr) }; // 2109644036
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature_Statics::NewProp_InputStack = { "InputStack", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnStratagemStackUpdated_Parms, InputStack), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputStack_MetaData), NewProp_InputStack_MetaData) }; // 2109644036
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

// Begin Delegate FOnAttributeChanged
struct Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnAttributeChanged_Parms
	{
		float CurrentValue;
		float MaxValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentValue;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::NewProp_CurrentValue = { "CurrentValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnAttributeChanged_Parms, CurrentValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::NewProp_MaxValue = { "MaxValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnAttributeChanged_Parms, MaxValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::NewProp_CurrentValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::NewProp_MaxValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnAttributeChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::_Script_ProjectHD_eventOnAttributeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::_Script_ProjectHD_eventOnAttributeChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAttributeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnAttributeChanged, float CurrentValue, float MaxValue)
{
	struct _Script_ProjectHD_eventOnAttributeChanged_Parms
	{
		float CurrentValue;
		float MaxValue;
	};
	_Script_ProjectHD_eventOnAttributeChanged_Parms Parms;
	Parms.CurrentValue=CurrentValue;
	Parms.MaxValue=MaxValue;
	OnAttributeChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnAttributeChanged

// Begin Delegate FOnGrenadeChanged
struct Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnGrenadeChanged_Parms
	{
		int32 Current;
		int32 Max;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Current;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnGrenadeChanged_Parms, Current), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnGrenadeChanged_Parms, Max), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnGrenadeChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::_Script_ProjectHD_eventOnGrenadeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::_Script_ProjectHD_eventOnGrenadeChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnGrenadeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnGrenadeChanged, int32 Current, int32 Max)
{
	struct _Script_ProjectHD_eventOnGrenadeChanged_Parms
	{
		int32 Current;
		int32 Max;
	};
	_Script_ProjectHD_eventOnGrenadeChanged_Parms Parms;
	Parms.Current=Current;
	Parms.Max=Max;
	OnGrenadeChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnGrenadeChanged

// Begin Delegate FOnStimChanged
struct Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics
{
	struct _Script_ProjectHD_eventOnStimChanged_Parms
	{
		int32 CurrentCount;
		int32 MaxCount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::NewProp_CurrentCount = { "CurrentCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnStimChanged_Parms, CurrentCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::NewProp_MaxCount = { "MaxCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ProjectHD_eventOnStimChanged_Parms, MaxCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::NewProp_CurrentCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::NewProp_MaxCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ProjectHD, nullptr, "OnStimChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::_Script_ProjectHD_eventOnStimChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::_Script_ProjectHD_eventOnStimChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnStimChanged_DelegateWrapper(const FMulticastScriptDelegate& OnStimChanged, int32 CurrentCount, int32 MaxCount)
{
	struct _Script_ProjectHD_eventOnStimChanged_Parms
	{
		int32 CurrentCount;
		int32 MaxCount;
	};
	_Script_ProjectHD_eventOnStimChanged_Parms Parms;
	Parms.CurrentCount=CurrentCount;
	Parms.MaxCount=MaxCount;
	OnStimChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnStimChanged

// Begin Class AFPSCharacter Function ApplyStimEffect
struct Z_Construct_UFunction_AFPSCharacter_ApplyStimEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_ApplyStimEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "ApplyStimEffect", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_ApplyStimEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_ApplyStimEffect_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFPSCharacter_ApplyStimEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_ApplyStimEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execApplyStimEffect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyStimEffect();
	P_NATIVE_END;
}
// End Class AFPSCharacter Function ApplyStimEffect

// Begin Class AFPSCharacter Function EquipWeapon
struct Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics
{
	struct FPSCharacter_eventEquipWeapon_Parms
	{
		UWeaponDataAsset* NewWeaponData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xac\xb4\xea\xb8\xb0 \xec\x9e\xa5\xec\xb0\xa9\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xac\xb4\xea\xb8\xb0 \xec\x9e\xa5\xec\xb0\xa9" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewWeaponData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::NewProp_NewWeaponData = { "NewWeaponData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSCharacter_eventEquipWeapon_Parms, NewWeaponData), Z_Construct_UClass_UWeaponDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::NewProp_NewWeaponData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "EquipWeapon", nullptr, nullptr, Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::FPSCharacter_eventEquipWeapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::FPSCharacter_eventEquipWeapon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFPSCharacter_EquipWeapon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_EquipWeapon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execEquipWeapon)
{
	P_GET_OBJECT(UWeaponDataAsset,Z_Param_NewWeaponData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EquipWeapon(Z_Param_NewWeaponData);
	P_NATIVE_END;
}
// End Class AFPSCharacter Function EquipWeapon

// Begin Class AFPSCharacter Function FinishReload
struct Z_Construct_UFunction_AFPSCharacter_FinishReload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
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
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
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
static const FName NAME_AFPSCharacter_OnAimCompleted = FName(TEXT("OnAimCompleted"));
void AFPSCharacter::OnAimCompleted()
{
	UFunction* Func = FindFunctionChecked(NAME_AFPSCharacter_OnAimCompleted);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnAimCompleted_Implementation();
	}
}
struct Z_Construct_UFunction_AFPSCharacter_OnAimCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
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
static const FName NAME_AFPSCharacter_OnAimStarted = FName(TEXT("OnAimStarted"));
void AFPSCharacter::OnAimStarted()
{
	UFunction* Func = FindFunctionChecked(NAME_AFPSCharacter_OnAimStarted);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnAimStarted_Implementation();
	}
}
struct Z_Construct_UFunction_AFPSCharacter_OnAimStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x97\x90\xec\x9e\x84\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x97\x90\xec\x9e\x84" },
#endif
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

// Begin Class AFPSCharacter Function OnGrenadeCompleted
struct Z_Construct_UFunction_AFPSCharacter_OnGrenadeCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_OnGrenadeCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "OnGrenadeCompleted", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_OnGrenadeCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_OnGrenadeCompleted_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFPSCharacter_OnGrenadeCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_OnGrenadeCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execOnGrenadeCompleted)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnGrenadeCompleted();
	P_NATIVE_END;
}
// End Class AFPSCharacter Function OnGrenadeCompleted

// Begin Class AFPSCharacter Function OnStimCompleted
struct Z_Construct_UFunction_AFPSCharacter_OnStimCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_OnStimCompleted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "OnStimCompleted", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_OnStimCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_OnStimCompleted_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AFPSCharacter_OnStimCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_OnStimCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execOnStimCompleted)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnStimCompleted();
	P_NATIVE_END;
}
// End Class AFPSCharacter Function OnStimCompleted

// Begin Class AFPSCharacter Function SwitchWeapon
struct Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics
{
	struct FPSCharacter_eventSwitchWeapon_Parms
	{
		int32 SlotIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSCharacter_eventSwitchWeapon_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::NewProp_SlotIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSCharacter, nullptr, "SwitchWeapon", nullptr, nullptr, Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::FPSCharacter_eventSwitchWeapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::FPSCharacter_eventSwitchWeapon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AFPSCharacter_SwitchWeapon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSCharacter_SwitchWeapon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AFPSCharacter::execSwitchWeapon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SwitchWeapon(Z_Param_SlotIndex);
	P_NATIVE_END;
}
// End Class AFPSCharacter Function SwitchWeapon

// Begin Class AFPSCharacter
void AFPSCharacter::StaticRegisterNativesAFPSCharacter()
{
	UClass* Class = AFPSCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplyStimEffect", &AFPSCharacter::execApplyStimEffect },
		{ "EquipWeapon", &AFPSCharacter::execEquipWeapon },
		{ "FinishReload", &AFPSCharacter::execFinishReload },
		{ "FireWeapon", &AFPSCharacter::execFireWeapon },
		{ "OnAimCompleted", &AFPSCharacter::execOnAimCompleted },
		{ "OnAimStarted", &AFPSCharacter::execOnAimStarted },
		{ "OnGrenadeCompleted", &AFPSCharacter::execOnGrenadeCompleted },
		{ "OnStimCompleted", &AFPSCharacter::execOnStimCompleted },
		{ "SwitchWeapon", &AFPSCharacter::execSwitchWeapon },
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
		{ "IncludePath", "Character/Player/FPSCharacter.h" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHealthChanged_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStaminaChanged_MetaData[] = {
		{ "Category", "Attributes" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttributeSet_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 AttributeSet\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
		{ "NativeConst", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 AttributeSet" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComponent_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// GAS \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GAS \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponChangeAbilityClass_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// GAS \xeb\xac\xb4\xea\xb8\xb0\xea\xb5\x90\xec\xb2\xb4 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GAS \xeb\xac\xb4\xea\xb8\xb0\xea\xb5\x90\xec\xb2\xb4 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrenadeAbilityClass_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// GAS \xec\x88\x98\xeb\xa5\x98\xed\x83\x84 \xeb\x8d\x98\xec\xa7\x80\xea\xb8\xb0 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GAS \xec\x88\x98\xeb\xa5\x98\xed\x83\x84 \xeb\x8d\x98\xec\xa7\x80\xea\xb8\xb0 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAbilityClass_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// GAS \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GAS \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaminaRegenEffectClass_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// GAS \xec\x8a\xa4\xed\x83\x9c\xeb\xaf\xb8\xeb\x82\x98 \xeb\xa6\xac\xec\xa0\xa0 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "GAS \xec\x8a\xa4\xed\x83\x9c\xeb\xaf\xb8\xeb\x82\x98 \xeb\xa6\xac\xec\xa0\xa0 \xeb\x8a\xa5\xeb\xa0\xa5 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWeaponData_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x98\x84\xec\x9e\xac \xec\x9e\xa5\xec\xb0\xa9 \xec\xa4\x91\xec\x9d\xb8 \xeb\xac\xb4\xea\xb8\xb0\xec\x9d\x98 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xec\x97\x90\xec\x85\x8b\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xec\x9e\xa5\xec\xb0\xa9 \xec\xa4\x91\xec\x9d\xb8 \xeb\xac\xb4\xea\xb8\xb0\xec\x9d\x98 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xec\x97\x90\xec\x85\x8b" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FirstWeaponData_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SecondWeaponData_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThirdWeaponData_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponSlot1Action_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xac\xb4\xea\xb8\xb0 \xea\xb5\x90\xec\xb2\xb4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xac\xb4\xea\xb8\xb0 \xea\xb5\x90\xec\xb2\xb4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponSlot2Action_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponSlot3Action_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalWalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb4\xeb\x8f\x99 \xec\x86\x8d\xeb\x8f\x84\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb4\xeb\x8f\x99 \xec\x86\x8d\xeb\x8f\x84" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintWalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimWalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadWalkSpeed_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsReloading_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAiming_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimRotationRecoveryTime_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecoilPitch_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RecoilYaw_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireCameraShakeClass_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainHUDWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainHUDWidget_MetaData[] = {
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MuzzleFlashFX_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxAmmoInMag_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x83\x84\xec\x95\xbd \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x83\x84\xec\x95\xbd \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentAmmo_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMagCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMagCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentGrenadeCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxGrenadeCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentStimCount_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa3\xbc\xec\x82\xac\xea\xb8\xb0 \xea\xb0\x9c\xec\x88\x98 \xea\xb4\x80\xeb\xa6\xac\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa3\xbc\xec\x82\xac\xea\xb8\xb0 \xea\xb0\x9c\xec\x88\x98 \xea\xb4\x80\xeb\xa6\xac" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStimCount_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StimEffectClass_MetaData[] = {
		{ "Category", "GAS" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x9a\x8c\xeb\xb3\xb5\xec\x9a\xa9 Gameplay Effect \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x9a\x8c\xeb\xb3\xb5\xec\x9a\xa9 Gameplay Effect \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StimSound_MetaData[] = {
		{ "Category", "Combat" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa3\xbc\xec\x82\xac\xea\xb8\xb0 \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa3\xbc\xec\x82\xac\xea\xb8\xb0 \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponInventory_MetaData[] = {
		{ "Category", "Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xac\xb4\xea\xb8\xb0 \xea\xb5\x90\xec\xb2\xb4 \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xac\xb4\xea\xb8\xb0 \xea\xb5\x90\xec\xb2\xb4 \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWeaponIndex_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWeaponAbilityHandles_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x98\x84\xec\x9e\xac \xec\x9e\xa5\xec\xb0\xa9\xeb\x90\x9c \xeb\xac\xb4\xea\xb8\xb0\xea\xb0\x80 \xeb\xb6\x80\xec\x97\xac\xed\x95\x9c \xec\x96\xb4\xeb\xb9\x8c\xeb\xa6\xac\xed\x8b\xb0 \xed\x95\xb8\xeb\x93\xa4\xeb\x93\xa4\xec\x9d\x84 \xec\xa0\x80\xec\x9e\xa5 (\xec\xa7\x80\xec\x9a\xb0\xea\xb8\xb0 \xec\x9a\xa9\xeb\x8f\x84)\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xec\x9e\xa5\xec\xb0\xa9\xeb\x90\x9c \xeb\xac\xb4\xea\xb8\xb0\xea\xb0\x80 \xeb\xb6\x80\xec\x97\xac\xed\x95\x9c \xec\x96\xb4\xeb\xb9\x8c\xeb\xa6\xac\xed\x8b\xb0 \xed\x95\xb8\xeb\x93\xa4\xeb\x93\xa4\xec\x9d\x84 \xec\xa0\x80\xec\x9e\xa5 (\xec\xa7\x80\xec\x9a\xb0\xea\xb8\xb0 \xec\x9a\xa9\xeb\x8f\x84)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StimMontage_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98    \n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x95\xa0\xeb\x8b\x88\xeb\xa9\x94\xec\x9d\xb4\xec\x85\x98" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimPitch_MetaData[] = {
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadSound_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentReloadMontage_MetaData[] = {
		{ "Category", "FPSCharacter" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BeaconClass_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ----------------\xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac---------------------\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "----------------\xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac---------------------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrowForce_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb8\xb0\xec\xa1\xb4 ThrowBeacon\xec\x97\x90\xec\x84\x9c \xec\x9d\xb4\xeb\xa6\x84 \xeb\xb3\x80\xea\xb2\xbd \xea\xb6\x8c\xec\x9e\xa5\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb8\xb0\xec\xa1\xb4 ThrowBeacon\xec\x97\x90\xec\x84\x9c \xec\x9d\xb4\xeb\xa6\x84 \xeb\xb3\x80\xea\xb2\xbd \xea\xb6\x8c\xec\x9e\xa5" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSelectingStratagem_MetaData[] = {
		{ "Category", "Stratagem" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemInputSound_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// --- \xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c ---\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- \xec\x8a\xa4\xed\x8a\xb8\xeb\x9d\xbc\xed\x83\x80\xec\xa0\xac \xec\x82\xac\xec\x9a\xb4\xeb\x93\x9c ---" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemErrorSound_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9e\x85\xeb\xa0\xa5 \xec\x84\xb1\xea\xb3\xb5 (\xec\x86\x8c\xeb\xa6\xac 1)\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x85\xeb\xa0\xa5 \xec\x84\xb1\xea\xb3\xb5 (\xec\x86\x8c\xeb\xa6\xac 1)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemCompleteSound_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9e\x85\xeb\xa0\xa5 \xec\x8b\xa4\xed\x8c\xa8 (\xec\x86\x8c\xeb\xa6\xac 2)\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x85\xeb\xa0\xa5 \xec\x8b\xa4\xed\x8c\xa8 (\xec\x86\x8c\xeb\xa6\xac 2)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemList_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa4\x91\xeb\xb3\xb5 \xeb\xb0\x8f \xec\x9d\xb4\xeb\xa6\x84 \xec\x98\xa4\xeb\xa5\x98 \xec\x88\x98\xec\xa0\x95: StratagemList\xeb\x8a\x94 FStratagemData \xed\x83\x80\xec\x9e\x85\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa4\x91\xeb\xb3\xb5 \xeb\xb0\x8f \xec\x9d\xb4\xeb\xa6\x84 \xec\x98\xa4\xeb\xa5\x98 \xec\x88\x98\xec\xa0\x95: StratagemList\xeb\x8a\x94 FStratagemData \xed\x83\x80\xec\x9e\x85\xec\x9d\x84 \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThirdPersonCamera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9e\x85\xeb\xa0\xa5 \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x85\xeb\xa0\xa5 \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrenadeAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StimAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReloadAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemMenuAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StratagemInputAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStratagemStepUpdated_MetaData[] = {
		{ "Category", "Stratagem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAmmoChanged_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnHitEnemy_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStratagemUpdate_MetaData[] = {
		{ "Category", "Stratagem" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStratagemStackUpdated_MetaData[] = {
		{ "Category", "Stratagem" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnGrenadeChanged_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStimChanged_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MouseSensitivity_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRange_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "Character/Player/FPSCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHealthChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStaminaChanged;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttributeSet;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComponent;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WeaponChangeAbilityClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GrenadeAbilityClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SprintAbilityClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StaminaRegenEffectClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWeaponData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FirstWeaponData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SecondWeaponData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThirdWeaponData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponSlot1Action;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponSlot2Action;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponSlot3Action;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalWalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintWalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimWalkSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReloadWalkSpeed;
	static void NewProp_bIsReloading_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsReloading;
	static void NewProp_bIsAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAiming;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimRotationRecoveryTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecoilPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RecoilYaw;
	static const UECodeGen_Private::FClassPropertyParams NewProp_FireCameraShakeClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainHUDWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MainHUDWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MuzzleFlashFX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxAmmoInMag;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentAmmo;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentMagCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxMagCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentGrenadeCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxGrenadeCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentStimCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStimCount;
	static const UECodeGen_Private::FClassPropertyParams NewProp_StimEffectClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StimSound;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WeaponInventory_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_WeaponInventory;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentWeaponIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentWeaponAbilityHandles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CurrentWeaponAbilityHandles;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StimMontage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimPitch;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentReloadMontage;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BeaconClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrowForce;
	static void NewProp_bIsSelectingStratagem_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSelectingStratagem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemInputSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemErrorSound;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemCompleteSound;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StratagemList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_StratagemList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThirdPersonCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GrenadeAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StimAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FireAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AimAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemMenuAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StratagemInputAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStratagemStepUpdated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAmmoChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHitEnemy;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStratagemUpdate;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStratagemStackUpdated;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGrenadeChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStimChanged;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MouseSensitivity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponMesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRange;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AFPSCharacter_ApplyStimEffect, "ApplyStimEffect" }, // 3367017256
		{ &Z_Construct_UFunction_AFPSCharacter_EquipWeapon, "EquipWeapon" }, // 1022476391
		{ &Z_Construct_UFunction_AFPSCharacter_FinishReload, "FinishReload" }, // 4075837818
		{ &Z_Construct_UFunction_AFPSCharacter_FireWeapon, "FireWeapon" }, // 3766756378
		{ &Z_Construct_UFunction_AFPSCharacter_OnAimCompleted, "OnAimCompleted" }, // 66020629
		{ &Z_Construct_UFunction_AFPSCharacter_OnAimStarted, "OnAimStarted" }, // 2308506318
		{ &Z_Construct_UFunction_AFPSCharacter_OnGrenadeCompleted, "OnGrenadeCompleted" }, // 829505126
		{ &Z_Construct_UFunction_AFPSCharacter_OnStimCompleted, "OnStimCompleted" }, // 60915330
		{ &Z_Construct_UFunction_AFPSCharacter_SwitchWeapon, "SwitchWeapon" }, // 3882063085
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnHealthChanged = { "OnHealthChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnHealthChanged), Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHealthChanged_MetaData), NewProp_OnHealthChanged_MetaData) }; // 1466681521
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStaminaChanged = { "OnStaminaChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStaminaChanged), Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStaminaChanged_MetaData), NewProp_OnStaminaChanged_MetaData) }; // 1466681521
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AttributeSet = { "AttributeSet", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AttributeSet), Z_Construct_UClass_UPlayerAttributeSet_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttributeSet_MetaData), NewProp_AttributeSet_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AbilitySystemComponent = { "AbilitySystemComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AbilitySystemComponent), Z_Construct_UClass_UAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComponent_MetaData), NewProp_AbilitySystemComponent_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponChangeAbilityClass = { "WeaponChangeAbilityClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, WeaponChangeAbilityClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponChangeAbilityClass_MetaData), NewProp_WeaponChangeAbilityClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_GrenadeAbilityClass = { "GrenadeAbilityClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, GrenadeAbilityClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrenadeAbilityClass_MetaData), NewProp_GrenadeAbilityClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SprintAbilityClass = { "SprintAbilityClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, SprintAbilityClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayAbility_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAbilityClass_MetaData), NewProp_SprintAbilityClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StaminaRegenEffectClass = { "StaminaRegenEffectClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StaminaRegenEffectClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayEffect_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaminaRegenEffectClass_MetaData), NewProp_StaminaRegenEffectClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponData = { "CurrentWeaponData", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentWeaponData), Z_Construct_UClass_UWeaponDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWeaponData_MetaData), NewProp_CurrentWeaponData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FirstWeaponData = { "FirstWeaponData", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FirstWeaponData), Z_Construct_UClass_UWeaponDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FirstWeaponData_MetaData), NewProp_FirstWeaponData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SecondWeaponData = { "SecondWeaponData", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, SecondWeaponData), Z_Construct_UClass_UWeaponDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SecondWeaponData_MetaData), NewProp_SecondWeaponData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThirdWeaponData = { "ThirdWeaponData", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ThirdWeaponData), Z_Construct_UClass_UWeaponDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThirdWeaponData_MetaData), NewProp_ThirdWeaponData_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponSlot1Action = { "WeaponSlot1Action", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, WeaponSlot1Action), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponSlot1Action_MetaData), NewProp_WeaponSlot1Action_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponSlot2Action = { "WeaponSlot2Action", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, WeaponSlot2Action), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponSlot2Action_MetaData), NewProp_WeaponSlot2Action_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponSlot3Action = { "WeaponSlot3Action", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, WeaponSlot3Action), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponSlot3Action_MetaData), NewProp_WeaponSlot3Action_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_NormalWalkSpeed = { "NormalWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, NormalWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalWalkSpeed_MetaData), NewProp_NormalWalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SprintWalkSpeed = { "SprintWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, SprintWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintWalkSpeed_MetaData), NewProp_SprintWalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimWalkSpeed = { "AimWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimWalkSpeed_MetaData), NewProp_AimWalkSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadWalkSpeed = { "ReloadWalkSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ReloadWalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadWalkSpeed_MetaData), NewProp_ReloadWalkSpeed_MetaData) };
void Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsReloading_SetBit(void* Obj)
{
	((AFPSCharacter*)Obj)->bIsReloading = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsReloading = { "bIsReloading", nullptr, (EPropertyFlags)0x0020080000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSCharacter), &Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsReloading_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsReloading_MetaData), NewProp_bIsReloading_MetaData) };
void Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming_SetBit(void* Obj)
{
	((AFPSCharacter*)Obj)->bIsAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming = { "bIsAiming", nullptr, (EPropertyFlags)0x0020080000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSCharacter), &Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAiming_MetaData), NewProp_bIsAiming_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimRotationRecoveryTime = { "AimRotationRecoveryTime", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimRotationRecoveryTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimRotationRecoveryTime_MetaData), NewProp_AimRotationRecoveryTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRate_MetaData), NewProp_FireRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilPitch = { "RecoilPitch", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, RecoilPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecoilPitch_MetaData), NewProp_RecoilPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilYaw = { "RecoilYaw", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, RecoilYaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RecoilYaw_MetaData), NewProp_RecoilYaw_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireCameraShakeClass = { "FireCameraShakeClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireCameraShakeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireCameraShakeClass_MetaData), NewProp_FireCameraShakeClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidgetClass = { "MainHUDWidgetClass", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MainHUDWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainHUDWidgetClass_MetaData), NewProp_MainHUDWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidget = { "MainHUDWidget", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MainHUDWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainHUDWidget_MetaData), NewProp_MainHUDWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MuzzleFlashFX = { "MuzzleFlashFX", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MuzzleFlashFX), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MuzzleFlashFX_MetaData), NewProp_MuzzleFlashFX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxAmmoInMag = { "MaxAmmoInMag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MaxAmmoInMag), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxAmmoInMag_MetaData), NewProp_MaxAmmoInMag_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentAmmo = { "CurrentAmmo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentAmmo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentAmmo_MetaData), NewProp_CurrentAmmo_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentMagCount = { "CurrentMagCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentMagCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMagCount_MetaData), NewProp_CurrentMagCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxMagCount = { "MaxMagCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MaxMagCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMagCount_MetaData), NewProp_MaxMagCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentGrenadeCount = { "CurrentGrenadeCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentGrenadeCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentGrenadeCount_MetaData), NewProp_CurrentGrenadeCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxGrenadeCount = { "MaxGrenadeCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MaxGrenadeCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxGrenadeCount_MetaData), NewProp_MaxGrenadeCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentStimCount = { "CurrentStimCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentStimCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentStimCount_MetaData), NewProp_CurrentStimCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxStimCount = { "MaxStimCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MaxStimCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStimCount_MetaData), NewProp_MaxStimCount_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimEffectClass = { "StimEffectClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StimEffectClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UGameplayEffect_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StimEffectClass_MetaData), NewProp_StimEffectClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimSound = { "StimSound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StimSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StimSound_MetaData), NewProp_StimSound_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponInventory_Inner = { "WeaponInventory", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FWeaponInstance, METADATA_PARAMS(0, nullptr) }; // 2855800932
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponInventory = { "WeaponInventory", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, WeaponInventory), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponInventory_MetaData), NewProp_WeaponInventory_MetaData) }; // 2855800932
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponIndex = { "CurrentWeaponIndex", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentWeaponIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWeaponIndex_MetaData), NewProp_CurrentWeaponIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponAbilityHandles_Inner = { "CurrentWeaponAbilityHandles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayAbilitySpecHandle, METADATA_PARAMS(0, nullptr) }; // 3490030742
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponAbilityHandles = { "CurrentWeaponAbilityHandles", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentWeaponAbilityHandles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWeaponAbilityHandles_MetaData), NewProp_CurrentWeaponAbilityHandles_MetaData) }; // 3490030742
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimMontage = { "StimMontage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StimMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StimMontage_MetaData), NewProp_StimMontage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimPitch = { "AimPitch", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimPitch_MetaData), NewProp_AimPitch_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireSound_MetaData), NewProp_FireSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadSound = { "ReloadSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ReloadSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadSound_MetaData), NewProp_ReloadSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentReloadMontage = { "CurrentReloadMontage", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CurrentReloadMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentReloadMontage_MetaData), NewProp_CurrentReloadMontage_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_BeaconClass = { "BeaconClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, BeaconClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AStratagemBeacon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BeaconClass_MetaData), NewProp_BeaconClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThrowForce = { "ThrowForce", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ThrowForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrowForce_MetaData), NewProp_ThrowForce_MetaData) };
void Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem_SetBit(void* Obj)
{
	((AFPSCharacter*)Obj)->bIsSelectingStratagem = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem = { "bIsSelectingStratagem", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSCharacter), &Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSelectingStratagem_MetaData), NewProp_bIsSelectingStratagem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemInputSound = { "StratagemInputSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemInputSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemInputSound_MetaData), NewProp_StratagemInputSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemErrorSound = { "StratagemErrorSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemErrorSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemErrorSound_MetaData), NewProp_StratagemErrorSound_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemCompleteSound = { "StratagemCompleteSound", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemCompleteSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemCompleteSound_MetaData), NewProp_StratagemCompleteSound_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList_Inner = { "StratagemList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FStratagemData, METADATA_PARAMS(0, nullptr) }; // 2228000118
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList = { "StratagemList", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemList_MetaData), NewProp_StratagemList_MetaData) }; // 2228000118
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThirdPersonCamera = { "ThirdPersonCamera", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ThirdPersonCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThirdPersonCamera_MetaData), NewProp_ThirdPersonCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMappingContext = { "StratagemMappingContext", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemMappingContext_MetaData), NewProp_StratagemMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SprintAction = { "SprintAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintAction_MetaData), NewProp_SprintAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_GrenadeAction = { "GrenadeAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, GrenadeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrenadeAction_MetaData), NewProp_GrenadeAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimAction = { "StimAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StimAction_MetaData), NewProp_StimAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireAction = { "FireAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireAction_MetaData), NewProp_FireAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimAction = { "AimAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, AimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimAction_MetaData), NewProp_AimAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadAction = { "ReloadAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, ReloadAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReloadAction_MetaData), NewProp_ReloadAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMenuAction = { "StratagemMenuAction", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemMenuAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemMenuAction_MetaData), NewProp_StratagemMenuAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemInputAction = { "StratagemInputAction", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, StratagemInputAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StratagemInputAction_MetaData), NewProp_StratagemInputAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractAction_MetaData), NewProp_InteractAction_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStepUpdated = { "OnStratagemStepUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStratagemStepUpdated), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStratagemStepUpdated_MetaData), NewProp_OnStratagemStepUpdated_MetaData) }; // 514312301
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnAmmoChanged = { "OnAmmoChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnAmmoChanged), Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAmmoChanged_MetaData), NewProp_OnAmmoChanged_MetaData) }; // 528124855
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnHitEnemy = { "OnHitEnemy", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnHitEnemy), Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnHitEnemy_MetaData), NewProp_OnHitEnemy_MetaData) }; // 830381355
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemUpdate = { "OnStratagemUpdate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStratagemUpdate), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStratagemUpdate_MetaData), NewProp_OnStratagemUpdate_MetaData) }; // 989583050
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStackUpdated = { "OnStratagemStackUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStratagemStackUpdated), Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStratagemStackUpdated_MetaData), NewProp_OnStratagemStackUpdated_MetaData) }; // 1223200555
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnGrenadeChanged = { "OnGrenadeChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnGrenadeChanged), Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnGrenadeChanged_MetaData), NewProp_OnGrenadeChanged_MetaData) }; // 132338721
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStimChanged = { "OnStimChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, OnStimChanged), Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStimChanged_MetaData), NewProp_OnStimChanged_MetaData) }; // 2431528805
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MouseSensitivity = { "MouseSensitivity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, MouseSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MouseSensitivity_MetaData), NewProp_MouseSensitivity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponMesh = { "WeaponMesh", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, WeaponMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponMesh_MetaData), NewProp_WeaponMesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireRange = { "FireRange", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSCharacter, FireRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRange_MetaData), NewProp_FireRange_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFPSCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnHealthChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStaminaChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AttributeSet,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AbilitySystemComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponChangeAbilityClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_GrenadeAbilityClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SprintAbilityClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StaminaRegenEffectClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FirstWeaponData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SecondWeaponData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThirdWeaponData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponSlot1Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponSlot2Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponSlot3Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_NormalWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SprintWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadWalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsReloading,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsAiming,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimRotationRecoveryTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_RecoilYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireCameraShakeClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MainHUDWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MuzzleFlashFX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxAmmoInMag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentAmmo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentMagCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxMagCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentGrenadeCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxGrenadeCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentStimCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MaxStimCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimEffectClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponInventory_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_WeaponInventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponAbilityHandles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentWeaponAbilityHandles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CurrentReloadMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_BeaconClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThrowForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_bIsSelectingStratagem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemInputSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemErrorSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemCompleteSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ThirdPersonCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_SprintAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_GrenadeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_FireAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_AimAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_ReloadAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemMenuAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_StratagemInputAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_InteractAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStepUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnAmmoChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnHitEnemy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemUpdate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStratagemStackUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnGrenadeChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSCharacter_Statics::NewProp_OnStimChanged,
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
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AFPSCharacter_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UAbilitySystemInterface_NoRegister, (int32)VTABLE_OFFSET(AFPSCharacter, IAbilitySystemInterface), false },  // 2272790346
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFPSCharacter_Statics::ClassParams = {
	&AFPSCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AFPSCharacter_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AFPSCharacter_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
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
struct Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EStratagemDirection_StaticEnum, TEXT("EStratagemDirection"), &Z_Registration_Info_UEnum_EStratagemDirection, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2109644036U) },
		{ EStratagemType_StaticEnum, TEXT("EStratagemType"), &Z_Registration_Info_UEnum_EStratagemType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1496983112U) },
		{ EAbilityInputID_StaticEnum, TEXT("EAbilityInputID"), &Z_Registration_Info_UEnum_EAbilityInputID, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3725710570U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FStratagemData::StaticStruct, Z_Construct_UScriptStruct_FStratagemData_Statics::NewStructOps, TEXT("StratagemData"), &Z_Registration_Info_UScriptStruct_StratagemData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStratagemData), 2228000118U) },
		{ FWeaponInstance::StaticStruct, Z_Construct_UScriptStruct_FWeaponInstance_Statics::NewStructOps, TEXT("WeaponInstance"), &Z_Registration_Info_UScriptStruct_WeaponInstance, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWeaponInstance), 2855800932U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFPSCharacter, AFPSCharacter::StaticClass, TEXT("AFPSCharacter"), &Z_Registration_Info_UClass_AFPSCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFPSCharacter), 952153187U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_4014071350(TEXT("/Script/ProjectHD"),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectHD_Source_ProjectHD_Character_Player_FPSCharacter_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
