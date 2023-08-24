project "Game"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"
    systemversion "latest"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    libdirs { "%{VULKAN_SDK}/Lib" }
    links {
        "Engine",
        "glfw"    
    }

    files {
        "src/**.cpp",
        "include/**.h",
        "include/**.hpp",
    }

    includedirs {
        "include",
        "../Engine/include",
	    "%{IncludeDir.glfw}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.vulkansdk}",
    }

    defines {
        "WINDOWS",
    }

    filter { "configurations:Debug" }
        buildoptions "/MTd"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "on"
        
    filter { "configurations:Release" }
        buildoptions "/MT"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "on"
