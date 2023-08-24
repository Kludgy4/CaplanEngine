#include "engpch.h"
#include "GameApp.h"

//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>
//#include <algorithm>
//#include <cstdlib>
//#include <iostream>
//#include <stdexcept>
//#include <vector>
//
//#define WIDTH 800
//#define HEIGHT 600
//
//const std::vector<const char*> validationLayersToEnable = {
//    "VK_LAYER_KHRONOS_validation"
//};
//
//#ifdef NDEBUG
//const bool enableValidationLayers = false;
//#else
//const bool enableValidationLayers = true;
//#endif
//
//class Application {
//public:
//    void run() {
//        initWindow();
//        initVulkan();
//        mainLoop();
//        cleanup();
//    }
//
//private:
//    GLFWwindow* window;
//    VkInstance instance;
//
//    void initWindow() {
//        glfwInit();
//        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
//        window = glfwCreateWindow(WIDTH, HEIGHT, "Caplan", nullptr, nullptr);
//    }
//
//    void initVulkan() {
//        createInstance();
//    }
//
//    void createInstance() {
//        auto appInfo = VkApplicationInfo{};
//        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
//        appInfo.pApplicationName = "Hello Triangle";
//        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
//        appInfo.pEngineName = "No Engine";
//        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
//        appInfo.apiVersion = VK_API_VERSION_1_0;
//        appInfo.pNext = nullptr;
//
//        uint32_t glfwExtensionCount = 0;
//        const char** glfwRequiredExtensions;
//        glfwRequiredExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
//
//        auto createInfo = VkInstanceCreateInfo{};
//        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
//        createInfo.pApplicationInfo = &appInfo;
//        createInfo.enabledExtensionCount = glfwExtensionCount;
//        createInfo.ppEnabledExtensionNames = glfwRequiredExtensions;
//        createInfo.enabledLayerCount = 0;
//        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
//            // TODO: Remove error throwing once have a good idea of starting code structure
//            throw std::runtime_error("Failed to create a Vulkan instance");
//        }
//
//        uint32_t extensionCount = 0;
//        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
//        auto availableExtensions = std::vector<VkExtensionProperties>(extensionCount);
//        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, availableExtensions.data());
//
//        checkGLFWExtensionsAvailable(availableExtensions, glfwRequiredExtensions, glfwExtensionCount);
//    }
//
//    void checkGLFWExtensionsAvailable(std::vector<VkExtensionProperties>& availableExtensions, const char**& glfwRequiredExtensions, uint32_t& glfwExtensionCount) {
//        std::cout << "Available Extensions:" << std::endl;
//        for (const auto& extension : availableExtensions) {
//            std::cout << "\t" << extension.extensionName << std::endl;
//        }
//
//        std::cout << "\nChecking Required GLFW Extensions:" << std::endl;
//        // TODO: Should use a trie so not spam checking all available extensions?
//        for (auto i = 0u; i < glfwExtensionCount; ++i) {
//            std::cout << "\t" << glfwRequiredExtensions[i] << " - ";
//            auto extensionAvailable = false;
//            for (const auto& extension : availableExtensions) {
//                if (strcmp(extension.extensionName, glfwRequiredExtensions[i])) {
//                    extensionAvailable = true;
//                    break;
//                }
//            }
//
//            if (!extensionAvailable) {
//                throw std::runtime_error("GLFW Required Extension " + std::string(glfwRequiredExtensions[i]) + " is not available");
//            }
//            std::cout << "Found" << std::endl;
//        }
//    }
//
//    bool checkValidationLayerSupport() {
//        uint32_t layerCount;
//        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
//
//        auto availableLayers = std::vector<VkLayerProperties>(layerCount);
//        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
//
//        for (const char* layerName : validationLayersToEnable) {
//            bool layerFound = false;
//            for (const auto& layerProperties : availableLayers) {
//                if (strcmp(layerName, layerProperties.layerName) == 0) {
//                    layerFound = true;
//                    break;
//                }
//            }
//
//            if (!layerFound) return false;
//        }
//
//        return true;
//    }
//
//    void mainLoop() {
//        while (!glfwWindowShouldClose(window)) {
//            glfwPollEvents();
//        }
//    }
//
//    void cleanup() {
//        vkDestroyInstance(instance, nullptr);
//        glfwDestroyWindow(window);
//        glfwTerminate();
//    }
//};

GameApp::GameApp() {

}

GameApp::~GameApp() {

}

void GameApp::run() {
	while (true) 1;
}
