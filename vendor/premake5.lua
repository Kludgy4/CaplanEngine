--[=====[
project "spdlog"
    kind "StaticLib"
    language "C++"
    staticruntime "on"
    
    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    includedirs {
        "spdlog/include"
    }
    
    files {
        "spdlog/include/spdlog/**.h",
	"spdlog/src/**.cpp"
    }
    
    filter "system:windows"
        systemversion "latest"
	
	defines {
	    "SPDLOG_COMPILED_LIB",
	    "_CRT_SECURE_NO_WARNINGS"
	}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        runtime "Release"
        optimize "on"
--]=====]