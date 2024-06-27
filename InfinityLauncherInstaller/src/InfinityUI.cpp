#include "InfinityUI.h"
#include <unordered_map>
#include <string>


const std::unordered_map<std::string, ImVec2> defaultCirclePositions = {
	{"Circle1", ImVec2(100, 100)},
	{"Circle2", ImVec2(200, 200)},
	{"Circle3", ImVec2(300, 300)},
	{"Circle4", ImVec2(400, 400)},
	{"Circle5", ImVec2(500, 500)}
};


InfinityUI::InfinityUI(ImVec2 windowSize, ImVec2 windowPos, ImDrawList* drawList) :
	m_drawList(drawList),
	m_windowSize(windowSize),
	m_windowPos(windowPos)
{
	if (m_circlePos.empty()) {
		m_circlePos.resize(5);
	}
}

void InfinityUI::Renderbackground() {
	RenderBackgroundBaseLayer();
	RenderBackgroundGradientLayer();
	RenderBackgroundDotsLayer();
}


void InfinityUI::RenderBackgroundBaseLayer() {

	m_drawList->AddRectFilled(m_windowPos, ImVec2(m_windowPos.x + m_windowSize.x, m_windowPos.y + m_windowSize.y), ImColor(0.0f, 0.0f, 0.0f, 1.0f));

	m_drawList->AddRectFilledMultiColor(m_windowPos, ImVec2(m_windowPos.x + m_windowSize.x, m_windowPos.y + m_windowSize.y), ImColor(108.0f/255.0f,0.0f,162.0f/255.0f,0.2f), ImColor(108.0f / 255.0f, 0.0f, 162.0f / 255.0f, 0.2f), ImColor(0.0f,17.0f/255.0f,82.0f/255.0f,0.2f), ImColor(0.0f, 17.0f / 255.0f, 82.0f / 255.0f, 0.2f));
}

void InfinityUI::RenderGradientCircle(ImVec2 center, float radius, float maxOpacity, ImU32 color)
{
	const int segments = 100;
	const int layers = 60;

	ImVec4 colorVec = ImGui::ColorConvertU32ToFloat4(color);

	for (int i = 0; i < layers; i++) {
		float layerRadius = radius * (layers - i) / layers;
		float alpha = colorVec.w * (i + 1) / layers;

		if (alpha > maxOpacity) {
			alpha = maxOpacity;
		}

		ImU32 layerColor = ImGui::ColorConvertFloat4ToU32(ImVec4(colorVec.x, colorVec.y, colorVec.z, alpha));

		m_drawList->AddCircleFilled(center, layerRadius, layerColor, segments);
	}
}

void InfinityUI::TrySetDefaultPositions()
{
	if (m_circlePos.size() == 5) {
		int i = 0;
		for (const auto& pair : defaultCirclePositions) {
			InitializeCirclePosition(i++, pair.second);
			if (i >= 5) break;
			
		}
	}
}

void InfinityUI::RenderBackgroundDotsLayer() {
	const ImVec2 offsetPosition = ImVec2(m_windowPos.x + 10, m_windowPos.y + 10);
	const ImVec2 dotCount2D = ImVec2(40, 40);
	const int radius = 1;
	const ImColor color = ImColor(1.0f, 1.0f, 1.0f, 0.3f);
	const float spacing = 20.0f;

	for (int y = 0; y < dotCount2D.y; y++) {
		for (int x = 0; x < dotCount2D.x; x++) {
			ImVec2 pos = ImVec2(offsetPosition.x + x * spacing, offsetPosition.y + y * spacing);
			m_drawList->AddCircleFilled(pos, radius, color);
		}
	}

}

void InfinityUI::RenderBackgroundGradientLayer()
{
	static float circle1angle = 0.0f;
	static float circle2angle = 0.0f;
	static float circle3angle = 0.0f;
	static float circle4angle = 0.0f;
	static float circle5angle = 0.0f;


	TrySetDefaultPositions();
	
	RenderGradientCircle(ImVec2(m_windowPos.x + m_circlePos[0].x, m_windowPos.y + m_circlePos[0].y), 400.0f, 0.01f, ImColor(18.0f/255.0f, 113.0f/255.f, 1.0f, 0.01f));
	RenderGradientCircle(ImVec2(m_windowPos.x + m_circlePos[1].x, m_windowPos.y + m_circlePos[1].y), 600.0f, 0.01f, ImColor(221.0f/255.f, 74.0f/255.f, 1.0f, 0.01f));
	RenderGradientCircle(ImVec2(m_windowPos.x + m_circlePos[2].x, m_windowPos.y + m_circlePos[2].y), 300.0f, 0.01f, ImColor(100.0f / 255.f, 220.0f / 255.f, 1.0f, 0.01f));
	RenderGradientCircle(ImVec2(m_windowPos.x + m_circlePos[3].x, m_windowPos.y + m_circlePos[3].y), 200.0f, 0.01f, ImColor(200.0f / 255.f, 50.0f / 255.f, 50.0f / 255.f, 0.01f));
	RenderGradientCircle(ImVec2(m_windowPos.x + m_circlePos[4].x, m_windowPos.y + m_circlePos[4].y), 400.0f, 0.01f, ImColor(180.0f / 255.f, 180.0f / 255.f, 50.0f / 255.f, 0.01f));

	if (circle1angle-0.05f < 0.0f) {
		circle1angle = 360.0f;
	}
	else {
		circle1angle-=0.05f;
	}
	if (circle2angle + 0.05f > 360) {
		circle2angle = 0;
	}
	else {
		circle2angle += 0.05f;
	}
	if (circle3angle - 0.05f < 0.0f) {
		circle3angle = 360.0f;
	}
	else {
		circle3angle -= 0.05f;
	}
	if (circle4angle + 0.05f > 360) {
		circle4angle = 0;
	}
	else {
		circle4angle += 0.05f;
	}
	if (circle5angle + 0.05f > 360) {
		circle5angle = 0;
	}
	else {
		circle5angle += 0.05f;
	}

	m_circlePos[0] = GetCircleCoords(200.0f, circle1angle, ImVec2( 400.0f,  400.0f));
	m_circlePos[1] = GetCircleCoords(100.0f, circle2angle, ImVec2(100.0f, 400.0f));
	m_circlePos[2] = GetCircleCoords(445.0f, circle3angle, ImVec2(200.0f, 100.0f));
	m_circlePos[3] = GetCircleCoords(809.0f, circle4angle, ImVec2(0.0f, 200.0f));
	m_circlePos[4] = GetCircleCoords(381.0f, circle5angle, ImVec2(-100.0f, 300.0f));
}


