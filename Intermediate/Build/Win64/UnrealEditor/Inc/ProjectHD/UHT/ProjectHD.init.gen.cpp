// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectHD_init() {}
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature();
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature();
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature();
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature();
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature();
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature();
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature();
	PROJECTHD_API UFunction* Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectHD;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectHD()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectHD.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnAmmoChangedSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnAttributeChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnGrenadeChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnHitEnemySignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnStimChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStackUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnStratagemStepUpdated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectHD_OnStratagemUpdate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectHD",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x752520A1,
				0xCEC2FADE,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectHD.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectHD.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectHD(Z_Construct_UPackage__Script_ProjectHD, TEXT("/Script/ProjectHD"), Z_Registration_Info_UPackage__Script_ProjectHD, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x752520A1, 0xCEC2FADE));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
