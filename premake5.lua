include "dependencies.lua"

workspace "Caplan"
    architecture "x86_64"
    startproject "Engine"
    
    configurations {
        "Debug",
        "Release"
    }    

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include premake compilation for vendor projects
include "Engine/vendor"
--include "vendor/spdlog"
--include "vendor/imgui"
--include "vendor/glm"

-- Compile my stuff
include "Engine"
include "Game"

newaction {
    trigger = "clean",
    description = "Remove all binaries, intermediates, and VStudio files",
    execute = function()
        print("Removing binaries")
        os.rmdir("./bin")
        print("Removing intermediates")
        os.rmdir("./bin-int")
        print("Removing VStudio files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}
