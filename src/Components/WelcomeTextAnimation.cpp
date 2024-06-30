//
// Created by Taco on 6/29/2024.
//

#include "WelcomeTextAnimation.h"
#include "ApplicationGUI.h"

using namespace WelcomeText;

WelcomeTextAnimation::WelcomeTextAnimation(): m_position(0) {
}

std::vector<std::string> g_welcomeTranslations = {
    "Welcome", // English
    "Bienvenido", // Spanish
    "Bienvenue", // French
    "Willkommen", // German
    "Benvenuto", // Italian
    "Bem-vindo", // Portuguese
    "Welkom", // Dutch
    "Välkommen", // Swedish
    "Velkommen", // Norwegian/Danish
    "Tervetuloa", // Finnish
    "Chào mừng", // Vietnamese
    "Witaj", // Polish
    "Vítejte", // Czech
    "Bun venit", // Romanian
    "Vitajte", // Slovak
    "Teretulemast", // Estonian
    "Selamat datang", // Malay/Indonesian
    "Maligayang pagdating", // Filipino
    "Karibu", // Swahili
    "Amukelekile", // Zulu
    "You can press the button now"
};
static float s_elapsedTime = 0.0f;
static std::chrono::steady_clock::time_point s_lastTimestamp = std::chrono::steady_clock::now();
static int s_position = 0;

void WelcomeTextAnimation::getText(ImDrawList *drawList, ImVec2 pos) {
    auto start = std::chrono::steady_clock::now();

    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(start - s_lastTimestamp).count() / 1000.0f;

    s_lastTimestamp = start;

    ImColor fontColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

    ImGui::PushFont(Walnut::Application::GetFont("DefaultLarge"));
    ImVec2 textSize = ImGui::CalcTextSize(g_welcomeTranslations[s_position].c_str());
    ImGui::PopFont();
    ImVec2 windowSize = ImGui::GetWindowSize();

    float threashold;
    if (s_position == 0) {
        threashold = 10.0f;
    } else {
        threashold = 6.0f;
    }

    if (s_elapsedTime < 1.0f) {
        fontColor.Value.w = s_elapsedTime;
    } else if (s_elapsedTime > threashold - 1.0f) {
        fontColor.Value.w = threashold - s_elapsedTime;
    } else {
        fontColor.Value.w = 1.0f;
    }


    drawList->AddText(Walnut::Application::GetFont("DefaultLarge"), 40.0f, ImVec2((windowSize.x / 2) - (textSize.x / 2), pos.y), fontColor, g_welcomeTranslations[s_position].c_str());


    if (s_elapsedTime > threashold) {
        s_position = (s_position + 1) % g_welcomeTranslations.size();

        s_elapsedTime = 0.0f;
    } else {
        s_elapsedTime += elapsedTime;
    }
}
