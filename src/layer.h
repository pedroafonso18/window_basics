#pragma once

class Layer {
    public:
        explicit Layer(
            const int id
        );
    
        virtual ~Layer() = default;

        virtual void OnUpdate() = 0;
        virtual void OnStartup() = 0;
        virtual void OnEachDraw() = 0;

        int GetId();
    private:
        const int m_id;
};