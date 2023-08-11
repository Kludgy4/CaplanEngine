#include <GameApp.h>
#include <memory>

extern std::unique_ptr<GameApp> CreateGameApp();

int main(int argc, char** argv) {
    auto app = CreateGameApp();
    app->run();
}
