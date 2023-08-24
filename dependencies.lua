
VULKAN_SDK = os.getenv("VULKAN_SDK")

PackageDir = {}
IncludeDir = {}

PackageDir["glfw"] = "%{wks.location}/Engine/vendor/glfw"
IncludeDir["glfw"] = "%{wks.location}/Engine/vendor/glfw/include"

PackageDir["glm"] = "%{wks.location}/Engine/vendor/glm"
IncludeDir["glm"] = "%{wks.location}/Engine/vendor/glm/glm"

PackageDir["imgui"] = "%{wks.location}/Engine/vendor/imgui"
IncludeDir["imgui"] = "%{wks.location}/Engine/vendor/imgui"

PackageDir["spdlog"] = "%{wks.location}/vendor/spdlog"
IncludeDir["spdlog"] = "%{wks.location}/vendor/spdlog/include"

PackageDir["vulkansdk"] = "%{VULKAN_SDK}"
IncludeDir["vulkansdk"] = "%{VULKAN_SDK}/Include"
