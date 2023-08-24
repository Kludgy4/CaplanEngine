include "dependencies.lua"

workspace "Caplan"
    architecture "x86_64"
    startproject "Game"
    
    configurations {
        "Debug",
        "Release"
    }

    filter "system:Windows"
        defines { "CP_WINDOWS" }

    -- filter "system:Unix"
    --     defines { "CP_LINUX" }
    -- 
    -- filter "system:Mac"
    --     defines { "CP_MAC" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include premake compilation for vendor projects
include "vendor"
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
	
	local function removeFiles(pattern)
            local excludedFolders = { "glfw", "imgui", "glm", "spdlog", "premake" }
            local files = os.matchfiles(pattern)
            for _, file in ipairs(files) do
                local skip = false
                for _, folder in ipairs(excludedFolders) do
                    if file:match("/" .. folder .. "/") then
                        skip = true
                        break
                    end
                end
                if not skip then
                    os.remove(file)
                end
            end
        end
	
        removeFiles("**.sln")
        removeFiles("**.vcxproj")
        removeFiles("**.vcxproj.filters")
        removeFiles("**.vcxproj.user")
        print("Done")
    end
}
