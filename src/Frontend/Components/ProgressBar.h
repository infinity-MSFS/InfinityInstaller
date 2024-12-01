//
// Created by Taco on 6/28/2024.
//

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <imgui.h>


class ProgressBar {
public:
    ProgressBar(float x, float y, float width, float height);


    void UpdateProgress(float percentage);

    void SetColor(const ImColor color) { m_color = color; }
    void SetBgColor(const ImColor color) { m_bgColor = color; }
    void SetRounding(const float rounding) { m_rounding = rounding; }

    void RenderProgressBar(ImDrawList *dl);

private:
    ImVec2 m_Location;
    ImVec2 m_Size;
    float m_percentage;
    ImColor m_color;
    ImColor m_bgColor;
    float m_rounding;
};


#endif //PROGRESSBAR_H
