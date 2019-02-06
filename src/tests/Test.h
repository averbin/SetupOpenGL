#pragma once

namespace test {

    class Test
    {
    public:
        Test() = default;
        virtual ~Test() = default;

        virtual void OnUpdate(float delta) {}
        virtual void OnRender() {}
        virtual void OnImGuiRender() {}
    };

}