//
// Created by Taco on 6/29/2024.
//

#ifndef WELCOMETEXTANIMATION_H
#define WELCOMETEXTANIMATION_H

#include <vector>
#include <string>
#include <imgui.h>
#include <chrono>

namespace WelcomeText {
}

class WelcomeTextAnimation {
public:
    WelcomeTextAnimation();

    void getText(ImDrawList *drawList, ImVec2 pos);

private:
    int m_position;
};


#endif //WELCOMETEXTANIMATION_H
