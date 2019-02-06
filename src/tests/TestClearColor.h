#pragma once

#include "Test.h"

namespace test 
{
    class TestClearColor : public Test 
    {
    public:
        TestClearColor();
        ~TestClearColor();

        void OnUpdate(float delta) override;
        void OnRender() override;
        void OnImGuiRender() override;
    private:
        float clearColor_[4];
    };
}