//
// Created by Taco on 6/27/2024.
//

#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H


class FPSCounter {
public:
    void setLastFrameTime(double frameTime) { m_lastFrameTime = frameTime; }
    void setCurrentFrameTime(double frameTime) { m_currentFrameTime = frameTime; }

    double GetFps() const;

private:
    double m_lastFrameTime;
    double m_currentFrameTime;
};


#endif //FPSCOUNTER_H
