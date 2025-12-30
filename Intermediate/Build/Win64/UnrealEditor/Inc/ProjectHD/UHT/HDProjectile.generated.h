// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HDProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PROJECTHD_HDProjectile_generated_h
#error "HDProjectile.generated.h already included, missing '#pragma once' in HDProjectile.h"
#endif
#define PROJECTHD_HDProjectile_generated_h

#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHDProjectile(); \
	friend struct Z_Construct_UClass_AHDProjectile_Statics; \
public: \
	DECLARE_CLASS(AHDProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AHDProjectile)


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AHDProjectile(AHDProjectile&&); \
	AHDProjectile(const AHDProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHDProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHDProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHDProjectile) \
	NO_API virtual ~AHDProjectile();


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_14_PROLOG
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_17_INCLASS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AHDProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
