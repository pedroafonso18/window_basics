#include "layer.h"

Layer::Layer(
    const int id
)
    : m_id(id) {}

int Layer::GetId() {
    return m_id;
}