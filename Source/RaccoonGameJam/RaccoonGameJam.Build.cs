// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RaccoonGameJam : ModuleRules
{
	public RaccoonGameJam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
