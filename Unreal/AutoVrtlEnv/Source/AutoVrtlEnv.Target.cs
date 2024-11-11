// Copyright 2018-2024 The MathWorks, Inc.

using UnrealBuildTool;
using System.Collections.Generic;

public class AutoVrtlEnvTarget : TargetRules
{
    public AutoVrtlEnvTarget(TargetInfo Target) : base(Target)
    {
        DefaultBuildSettings = BuildSettingsVersion.V4;
        Type = TargetType.Game;

        ExtraModuleNames.AddRange( new string[] { "AutoVrtlEnv" } );

        if (Target.Platform == UnrealTargetPlatform.Linux) {
            bForceEnableExceptions = true;
        }

        bOverrideBuildEnvironment = true;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        // To enable the USD SDK (https://docs.unrealengine.com/5.1/en-US/universal-scene-description-in-unreal-engine/)
        GlobalDefinitions.Add("FORCE_ANSI_ALLOCATOR=1");
        GlobalDefinitions.Add("UE_USE_MALLOC_FILL_BYTES=0");
    }
}