#pragma once

#include "core_configuration.h"
#include "layer.h"
#include <vector>

class Core {
    public:
        Core(
            CoreConfiguration config,
            Layer* base_layer
        );

        void AddLayer(
            Layer* newLayer
        );

        void PopLayer(
            const int layer_id
        );
        
        void Begin();
    private:
        void Startup();
        void Update();
        void OnEachDraw();
        
        CoreConfiguration m_config;
        std::vector<Layer*> m_layers;
};