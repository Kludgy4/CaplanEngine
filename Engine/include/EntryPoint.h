#include "engpch.h"
#include "GameApp.h"
#include <memory>
#include "Log.h"

extern std::unique_ptr<GameApp> CreateGameApp();

int main(int argc, char** argv) {
    Log::InitLoggers();
    Log::getClientLogger()->info("Hello");
    //LOG_ENGINE_TRACE("Test");

    auto app = CreateGameApp();
    app->run();
}
