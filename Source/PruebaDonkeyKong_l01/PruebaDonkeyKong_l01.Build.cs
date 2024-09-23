// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PruebaDonkeyKong_l01 : ModuleRules
{
	public PruebaDonkeyKong_l01(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
