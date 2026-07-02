#include "core.h"

#include <raylib.h>

class DemoLayer final : public Layer {
public:
    DemoLayer()
        : Layer(1) {}

    void OnUpdate() override {}

    void OnStartup() override {}

    void OnEachDraw() override {
        ClearBackground(RAYWHITE);
        DrawText("Window Basics", 40, 40, 30, DARKGRAY);
    }
};

int main() {
    CoreConfiguration config;
    config.width = 800;
    config.height = 450;
    config.resizable = true;
    config.name = "Window Basics";

    DemoLayer layer;
    Core core(config, &layer);
    core.Begin();

    return 0;
}