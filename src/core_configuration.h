#pragma once

#include <string>

struct CoreConfiguration {
    int width;
    int height;
    bool resizable = false;
    std::string name = "Window";
};