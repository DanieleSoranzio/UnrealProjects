// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GP3SoranzioDanieleST : ModuleRules
{
	public GP3SoranzioDanieleST(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","AIPlugin", });
	}
}
