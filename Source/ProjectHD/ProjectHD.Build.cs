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
            "GameplayCameras"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}