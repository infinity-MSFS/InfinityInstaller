#pragma once

#include "imgui.h"
#include "vector"
#include "Backend/Installer/Installer.h"
#include <string>

static std::vector<ImVec2> m_circlePos;

bool RenderInstallButton(ImVec2 pos, ImVec2 size, const char *label);

void RenderPathSelectBox(ImVec2 pos, ImVec2 size);

class InfinityUI {
public:
	InfinityUI();

	void Renderbackground();

private:
	void RenderBackgroundDotsLayer();

	void RenderBackgroundGradientLayer();

	void RenderBackgroundBaseLayer();

	void RenderGradientCircle(ImVec2 center, float radius, float maxOpacity, ImU32 color);

private:
	// 5 circles

	static void InitializeCirclePosition(int index, ImVec2 position) {
		if (index >= 0 && index < m_circlePos.size() && m_circlePos[index].x == 0 && m_circlePos[index].y == 0) {
			m_circlePos[index] = position;
		}
	}

	void TrySetDefaultPositions();

	static ImVec2 GetCircleCoords(float radius, float theta, ImVec2 center) {
		float radians = (3.141592f / 180.0f) * theta;
		float x = center.x + radius * cos(radians);
		float y = center.y + radius * sin(radians);

		return ImVec2(x, y);
	}
};

