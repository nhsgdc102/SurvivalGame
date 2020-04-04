// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SurvivalGameEditorTarget : TargetRules
{
	public SurvivalGameEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
        //To suppress "PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs" message
        DefaultBuildSettings = BuildSettingsVersion.V2;

        ExtraModuleNames.AddRange( new string[] { "SurvivalGame" } );

    }
}
