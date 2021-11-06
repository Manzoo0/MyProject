using UnrealBuildTool;

public class MyProjectEditor : ModuleRules
{
	public MyProjectEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "TargetPlatform",
            }
         );

        PrivateDependencyModuleNames.AddRange(
           new string[]
           {
                "Projects",
                "Slate",
                "SlateCore",
                "InputCore",
                "UnrealEd",
           }
       );
    }
}
