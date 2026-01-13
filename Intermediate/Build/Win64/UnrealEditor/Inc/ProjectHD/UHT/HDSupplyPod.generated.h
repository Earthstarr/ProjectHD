// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "HDSupplyPod.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PROJECTHD_HDSupplyPod_generated_h
#error "HDSupplyPod.generated.h already included, missing '#pragma once' in HDSupplyPod.h"
#endif
#define PROJECTHD_HDSupplyPod_generated_h

#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleSphereEndOverlap); \
	DECLARE_FUNCTION(execHandleSphereBeginOverlap);


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_CALLBACK_WRAPPERS
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHDSupplyPod(); \
	friend struct Z_Construct_UClass_AHDSupplyPod_Statics; \
public: \
	DECLARE_CLASS(AHDSupplyPod, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(AHDSupplyPod) \
	virtual UObject* _getUObject() const override { return const_cast<AHDSupplyPod*>(this); }


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AHDSupplyPod(AHDSupplyPod&&); \
	AHDSupplyPod(const AHDSupplyPod&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHDSupplyPod); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHDSupplyPod); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHDSupplyPod) \
	NO_API virtual ~AHDSupplyPod();


#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_8_PROLOG
#define FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_CALLBACK_WRAPPERS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_INCLASS_NO_PURE_DECLS \
	FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class AHDSupplyPod>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_JW_Unreal_ProjectHD_Source_ProjectHD_HDSupplyPod_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
