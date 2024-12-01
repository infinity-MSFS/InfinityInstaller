//
// Created by Taco on 6/27/2024.
//

#include "FPSCounter.h"


double FPSCounter::GetFps() const {
    const double frameTime = m_currentFrameTime - m_lastFrameTime;
    const double fps = 1.0 / frameTime;
    return fps;
}
