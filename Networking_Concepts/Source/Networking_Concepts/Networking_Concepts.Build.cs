// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Networking_Concepts : ModuleRules
{
	public Networking_Concepts(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
