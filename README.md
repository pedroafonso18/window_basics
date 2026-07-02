# Window Basics

Biblioteca C++ estática para gerenciar uma janela Raylib com sistema de layers.

## English

Static C++ library for managing a Raylib window with a layer system.

## Build / Build

```bash
cmake -S . -B build
cmake --build build
```

## Targets / Targets

- `window_basics`: biblioteca estática reutilizável
- `Window_Basics_Test`: executável local de teste

## Install / Install

```bash
cmake --install build --prefix /tmp/window_basics-install
```

## Uso em outro projeto CMake / Use in another CMake project

### Via `add_subdirectory`

```cmake
add_subdirectory(path/to/window_basics)

target_link_libraries(my_app PRIVATE WindowBasics::window_basics)
```

### Via `find_package`

Depois de instalar a biblioteca:

After installing the library:

```cmake
find_package(WindowBasics CONFIG REQUIRED)

target_link_libraries(my_app PRIVATE WindowBasics::window_basics)
```

## Estrutura / Structure

- `src/`: implementação e headers públicos da biblioteca
- `cmake/`: arquivos de configuração do pacote CMake
