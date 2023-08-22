project "glfw"
    --location "glfw"
    kind "StaticLib"
    language "C"
    
    targetdir("../../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../../bin-int/" .. outputdir .. "/%{prj.name}")
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        runtime "Release"
        optimize "on"
    
    includedirs { "glfw/include", "glfw/src" }
    
    files {
        "glfw/include/GLFW/glfw3.h",
        "glfw/include/GLFW/glfw3native.h",
        "glfw/src/internal.h",
        "glfw/src/platform.h",
        "glfw/src/mappings.h",
        "glfw/src/context.c",
        "glfw/src/init.c",
        "glfw/src/input.c",
        "glfw/src/monitor.c",
        "glfw/src/platform.c",
        "glfw/src/vulkan.c",
        "glfw/src/window.c",
        "glfw/src/egl_context.c",
        "glfw/src/osmesa_context.c",
        "glfw/src/null_platform.h",
        "glfw/src/null_init.c",
        "glfw/src/null_joystick.h",
        "glfw/src/null_monitor.c",
        "glfw/src/null_window.c",
        "glfw/src/null_joystick.c"
        --"glfw_config.h"
    }
    
    filter "system:macosx"
        files {
            "glfw/src/cocoa_time.h",
            "glfw/src/cocoa_time.c",
            "glfw/src/posix_thread.h",
            "glfw/src/posix_thread.c",
            "glfw/src/posix_module.c",
        }
        defines { "_GLFW_COCOA" }
    
    filter "system:windows"
        files {
            "glfw/src/win32_time.h",
            "glfw/src/win32_thread.h",
            --"glfw/src/win32_module.c",
            "glfw/src/win32_time.c",
            "glfw/src/win32_thread.c"
        }
        defines { "_GLFW_WIN32" }
    
    
    filter "system:linux"
        files {
            "glfw/src/posix_time.h",
            "glfw/src/posix_thread.h",
            "glfw/src/posix_time.c",
            "glfw/src/posix_module.c",
            "glfw/src/posix_thread.c"
        }
        defines { "_GLFW_X11" }

project "imgui"
    kind "StaticLib"
    language "C++"

    targetdir("../../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../../bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "imgui/imconfig.h",
        "imgui/imgui.cpp",
        "imgui/imgui.h",
        "imgui/imgui_demo.cpp",
        "imgui/imgui_draw.cpp",
        "imgui/imgui_internal.h",
        "imgui/imgui_tables.cpp",
        "imgui/imgui_widgets.cpp",
        "imgui/imgui_rectpack.h",
        "imgui/imgui_textedit.h",
        "imgui/imgui_truetype.h"
    }

    filter "system:windows"
        systemversion "latest"
        cppdialect "C++17"
        staticruntime "on"

    filter {"system:windows", "configurations:Release"}
        buildoptions "/MT"
