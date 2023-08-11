project "Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"
    systemversion "latest"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    libdirs { "%{VULKAN_SDK}/Lib" }
    links {
        "vulkan-1.lib",
		"glfw"
	}

    includedirs {
        "include",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.vulkansdk}"
    }
    
    files {
        "src/**.cpp",
        "include/**.h",
        "include/**.hpp",
    }

    defines {
        "WINDOWS",
    }

    filter { "configurations:Debug" }
        buildoptions "/MTd"
        defines { "CP_DEBUG", "_DEBUG" }
        runtime "Debug"
        symbols "on"
        
    filter { "configurations:Release" }
        buildoptions "/MT"
        defines { "CP_RELEASE", "NDEBUG" }
        runtime "Release"
        optimize "on"
