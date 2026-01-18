using UnrealBuildTool;

public class ProjectHD : ModuleRules
{
    public ProjectHD(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "UMG",
            "Slate",
            "SlateCore",
            "Niagara",
            "GameplayCameras",
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks",
            "AIModule",
        });

        PrivateDependencyModuleNames.AddRange(new string[] { "EngineCameras", "EngineCameras", "GameplayStateTreeModule" });
    }
}