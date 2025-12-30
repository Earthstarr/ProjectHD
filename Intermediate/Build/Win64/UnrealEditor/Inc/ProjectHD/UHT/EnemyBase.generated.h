// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EnemyBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTHD_EnemyBase_generated_h
#error "EnemyBase.generated.h already included, missing '#pragma once' in EnemyBase.h"
#endif
#define PROJECTHD_EnemyBase_generated_h

#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_EnemyBase_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyBase(); \
	friend struct Z_Construct_UClass_AEnemyBase_Statics; \
public: \
	DECLARE_CLASS(AEnemyBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AEnemyBase)


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_EnemyBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEnemyBase(AEnemyBase&&); \
	AEnemyBase(const AEnemyBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyBase) \
	NO_API virtual ~AEnemyBase();


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_EnemyBase_h_9_PROLOG
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_EnemyBase_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_EnemyBase_h_12_INCLASS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_EnemyBase_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AEnemyBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_JW_Unreal_ProjectHD_Source_ProjectHD_EnemyBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
