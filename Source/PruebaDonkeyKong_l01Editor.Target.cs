// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PruebaDonkeyKong_l01EditorTarget : TargetRules
{
	public PruebaDonkeyKong_l01EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("PruebaDonkeyKong_l01");
	}
}
