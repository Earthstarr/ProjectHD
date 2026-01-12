// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/Player/PlayerAttributeSet.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTHD_PlayerAttributeSet_generated_h
#error "PlayerAttributeSet.generated.h already included, missing '#pragma once' in PlayerAttributeSet.h"
#endif
#define PROJECTHD_PlayerAttributeSet_generated_h

#define FID_ProjectHD_Source_ProjectHD_Character_Player_PlayerAttributeSet_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlayerAttributeSet(); \
	friend struct Z_Construct_UClass_UPlayerAttributeSet_Statics; \
public: \
	DECLARE_CLASS(UPlayerAttributeSet, UAttributeSet, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ProjectHD"), NO_API) \
	DECLARE_SERIALIZER(UPlayerAttributeSet)


#define FID_ProjectHD_Source_ProjectHD_Character_Player_PlayerAttributeSet_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UPlayerAttributeSet(UPlayerAttributeSet&&); \
	UPlayerAttributeSet(const UPlayerAttributeSet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlayerAttributeSet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlayerAttributeSet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPlayerAttributeSet) \
	NO_API virtual ~UPlayerAttributeSet();


#define FID_ProjectHD_Source_ProjectHD_Character_Player_PlayerAttributeSet_h_20_PROLOG
#define FID_ProjectHD_Source_ProjectHD_Character_Player_PlayerAttributeSet_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectHD_Source_ProjectHD_Character_Player_PlayerAttributeSet_h_23_INCLASS_NO_PURE_DECLS \
	FID_ProjectHD_Source_ProjectHD_Character_Player_PlayerAttributeSet_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTHD_API UClass* StaticClass<class UPlayerAttributeSet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectHD_Source_ProjectHD_Character_Player_PlayerAttributeSet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
