#pragma once
#include <string>
#include <functional>

class Button{
    public:
        Button(int x, int y, int w, int h, std::string label, std::function<void()> callback);

        void Update();
        void Draw();
        void Click();
    private:
        int m_X;
        int m_Y;
        int m_W;
        int m_H;
        std::string m_Label;
        std::function<void()> m_Callback;

};
