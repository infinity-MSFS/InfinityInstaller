-- premake5.lua
workspace "InfinityLauncherInstaller"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "InfinityLauncherInstaller"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/Build-Walnut.lua"

include "InfinityLauncherInstaller"