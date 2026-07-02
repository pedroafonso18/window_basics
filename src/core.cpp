#include "core.h"

#include <raylib.h>

Core::Core(
    CoreConfiguration config,
    Layer* base_layer
)
    : m_config(config)
{
    m_layers.push_back(base_layer);
}

void Core::AddLayer(
    Layer* newLayer
)
{
    m_layers.push_back(newLayer);
}

void Core::PopLayer(
    const int layer_id
)
{
    for (int i = 0; i < m_layers.size(); i++) {
        if (m_layers.at(i)->GetId() == layer_id) {
            m_layers.erase(m_layers.begin() + i);
            return;
        }
    }
}

void Core::Begin()
{
    InitWindow(m_config.width, m_config.height, m_config.name.c_str());

    if (m_config.resizable) {
        SetWindowState(FLAG_WINDOW_RESIZABLE);
    }

    Startup();

    while (!WindowShouldClose()) {
        Update();

        BeginDrawing();
            OnEachDraw();
        EndDrawing();
    }

    CloseWindow();
}

void Core::Startup()
{
    for (Layer* layer : m_layers) {
        layer->OnStartup();
    }
}

void Core::Update() 
{
    for (Layer* layer : m_layers) {
        layer->OnUpdate();
    }
}

void Core::OnEachDraw()
{
    for (Layer* layer : m_layers) {
        layer->OnEachDraw();
    }
}