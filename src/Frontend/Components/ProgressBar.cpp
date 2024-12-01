//
// Created by Taco on 6/28/2024.
//

#include "ProgressBar.h"

#include <cstdio>

ProgressBar::ProgressBar(const float x, const float y, const float width, const float height): m_Location(ImVec2(x, y)),
                                                                                               m_Size(ImVec2(width, height)),
                                                                                               m_percentage(0),
                                                                                               m_color(ImColor(0.0f, 0.0f, 0.0f, 1.0f)),
                                                                                               m_bgColor(ImColor(1.0f, 0.0f, 0.0f, 1.0f)),
                                                                                               m_rounding(3.0f) {
}

void ProgressBar::UpdateProgress(const float percentage) {
    m_percentage = percentage;
}

void ProgressBar::RenderProgressBar(ImDrawList *dl) {
    const float width = m_Size.x - 2.0f;
    const float percentageWidth = width * (m_percentage / 100.0f);
    dl->AddRectFilled(m_Location, ImVec2(m_Location.x + m_Size.x, m_Location.y + m_Size.y), m_bgColor, m_rounding); // bg
    dl->AddRectFilled(ImVec2(m_Location.x + 2.0, m_Location.y + 2.0), ImVec2(m_Location.x + percentageWidth, m_Location.y + m_Size.y - 2.0f), m_color, m_rounding); // progress bar

    char percentageText[16];
    snprintf(percentageText, sizeof(percentageText), "%.1f%%", m_percentage);

    dl->AddText(ImVec2(m_Location.x + m_Size.x + 10.0f, m_Location.y + (m_Size.y / 2 - 10.0f)), ImColor(1.0f, 1.0f, 1.0f, 1.0f), percentageText);
}


