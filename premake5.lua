-- premake5.lua
workspace "ProgramLauncher"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "ProgramLauncher"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "WalnutApp"