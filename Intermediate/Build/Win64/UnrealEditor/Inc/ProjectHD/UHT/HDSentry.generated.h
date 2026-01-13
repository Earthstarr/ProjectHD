// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Weapon/Stratagem/HDSentry.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTHD_HDSentry_generated_h
#error "HDSentry.generated.h already included, missing '#pragma once' in HDSentry.h"
#endif
#define PROJECTHD_HDSentry_generated_h

#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnDeployFinished); \
	DECLARE_FUNCTION(execOnRetractFinished);


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_CALLBACK_WRAPPERS
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHDSentry(); \
	friend struct Z_Construct_UClass_AHDSentry_Statics; \
public: \
	DECLARE_CLASS(AHDSentry, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AHDSentry)


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AHDSentry(AHDSentry&&); \
	AHDSentry(const AHDSentry&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHDSentry); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHDSentry); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHDSentry) \
	NO_API virtual ~AHDSentry();


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_9_PROLOG
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_CALLBACK_WRAPPERS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_INCLASS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AHDSentry>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_JW_Unreal_ProjectHD_Source_ProjectHD_Weapon_Stratagem_HDSentry_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
