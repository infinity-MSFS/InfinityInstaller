#pragma once

#include "imgui.h"
#include "vector"

static std::vector<ImVec2> m_circlePos;

class InfinityUI
{
public:
	InfinityUI(ImVec2 windowSize, ImVec2 windowPos ,ImDrawList* drawList);
	
	void Renderbackground();


private:
	void RenderBackgroundDotsLayer();
	void RenderBackgroundGradientLayer();
	void RenderBackgroundBaseLayer();
	void RenderGradientCircle(ImVec2 center, float radius,float maxOpacity, ImU32 color);


private:
	ImDrawList* m_drawList;
	ImVec2 m_windowPos;
	ImVec2 m_windowSize;
	 // 5 circles

	static void InitializeCirclePosition(int index, ImVec2 position) {
		if (index >= 0 && index < m_circlePos.size() && m_circlePos[index].x == 0 && m_circlePos[index].y == 0) {
			m_circlePos[index] = position;
		}
	}

	void TrySetDefaultPositions();

	ImVec2 GetCircleCoords(float radius, float theta, ImVec2 center) {
		float radians = (3.141592 / 180) * theta;
		float x = center.x + radius * cos(radians);
		float y = center.y + radius * sin(radians);

		return ImVec2(x, y);
	}
};

