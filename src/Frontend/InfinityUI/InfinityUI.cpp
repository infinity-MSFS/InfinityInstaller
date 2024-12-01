#include "InfinityUI.hpp"

#include <imgui_internal.h>
#include <unordered_map>


static std::wstring localAppdataPath = Installer::GetLocalAppDataPath();

const std::unordered_map<std::string, ImVec2> defaultCirclePositions = {
	{"Circle1", ImVec2(100, 100)},
	{"Circle2", ImVec2(200, 200)},
	{"Circle3", ImVec2(300, 300)},
	{"Circle4", ImVec2(400, 400)},
	{"Circle5", ImVec2(200, 50)}
};


InfinityUI::InfinityUI()  {
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
	ImGui::GetWindowDrawList()->AddRectFilled(ImGui::GetWindowPos(), ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x, ImGui::GetWindowPos().y + ImGui::GetWindowSize().y), ImColor(0.0f, 0.0f, 0.0f, 1.0f));

	ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImGui::GetWindowPos(), ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x, ImGui::GetWindowPos().y + ImGui::GetWindowSize().y), ImColor(108.0f / 255.0f, 0.0f, 162.0f / 255.0f, 0.2f),
	                                    ImColor(108.0f / 255.0f, 0.0f, 162.0f / 255.0f, 0.2f), ImColor(0.0f, 17.0f / 255.0f, 82.0f / 255.0f, 0.2f),
	                                    ImColor(0.0f, 17.0f / 255.0f, 82.0f / 255.0f, 0.2f));
}

void InfinityUI::RenderGradientCircle(ImVec2 center, float radius, float maxOpacity, ImU32 color) {
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

		ImGui::GetWindowDrawList()->AddCircleFilled(center, layerRadius, layerColor, segments);
	}
}

void InfinityUI::TrySetDefaultPositions() {
	if (m_circlePos.size() == 5) {
		int i = 0;
		for (const auto &pair: defaultCirclePositions) {
			InitializeCirclePosition(i++, pair.second);
			if (i >= 5) break;
		}
	}
}

void InfinityUI::RenderBackgroundDotsLayer() {
	const ImVec2 offsetPosition = ImVec2(ImGui::GetWindowPos().x + 10, ImGui::GetWindowPos().y + 10);
	const ImVec2 dotCount2D = ImVec2(40, 40);
	const int radius = 1;
	const ImColor color = ImColor(1.0f, 1.0f, 1.0f, 0.3f);
	const float spacing = 20.0f;

	for (int y = 0; y < dotCount2D.y; y++) {
		for (int x = 0; x < dotCount2D.x; x++) {
			ImVec2 pos = ImVec2(offsetPosition.x + x * spacing, offsetPosition.y + y * spacing);
			ImGui::GetWindowDrawList()->AddCircleFilled(pos, radius, color);
		}
	}
}

void InfinityUI::RenderBackgroundGradientLayer() {
	static float circle1angle = 0.0f;
	static float circle2angle = 0.0f;
	static float circle3angle = 0.0f;
	static float circle4angle = 0.0f;
	static float circle5angle = 0.0f;


	TrySetDefaultPositions();

	RenderGradientCircle(ImVec2(ImGui::GetWindowPos().x + m_circlePos[0].x, ImGui::GetWindowPos().y + m_circlePos[0].y), 300.0f, 0.01f, ImColor(18.0f / 255.0f, 113.0f / 255.f, 1.0f, 0.01f));
	RenderGradientCircle(ImVec2(ImGui::GetWindowPos().x + m_circlePos[1].x, ImGui::GetWindowPos().y + m_circlePos[1].y), 200.0f, 0.01f, ImColor(221.0f / 255.f, 74.0f / 255.f, 1.0f, 0.01f));
	RenderGradientCircle(ImVec2(ImGui::GetWindowPos().x + m_circlePos[2].x, ImGui::GetWindowPos().y + m_circlePos[2].y), 300.0f, 0.01f, ImColor(100.0f / 255.f, 220.0f / 255.f, 1.0f, 0.01f));
	RenderGradientCircle(ImVec2(ImGui::GetWindowPos().x + m_circlePos[3].x, ImGui::GetWindowPos().y + m_circlePos[3].y), 200.0f, 0.01f, ImColor(200.0f / 255.f, 50.0f / 255.f, 50.0f / 255.f, 0.01f));
	RenderGradientCircle(ImVec2(ImGui::GetWindowPos().x + m_circlePos[4].x, ImGui::GetWindowPos().y + m_circlePos[4].y), 300.0f, 0.01f, ImColor(180.0f / 255.f, 180.0f / 255.f, 50.0f / 255.f, 0.01f));

	if (circle1angle - 0.05f < 0.0f) {
		circle1angle = 360.0f;
	} else {
		circle1angle -= 0.05f;
	}
	if (circle2angle + 0.05f > 360) {
		circle2angle = 0;
	} else {
		circle2angle += 0.05f;
	}
	if (circle3angle - 0.05f < 0.0f) {
		circle3angle = 360.0f;
	} else {
		circle3angle -= 0.05f;
	}
	if (circle4angle + 0.05f > 360) {
		circle4angle = 0;
	} else {
		circle4angle += 0.05f;
	}
	if (circle5angle - 0.05f < 360) {
		circle5angle = 0;
	} else {
		circle5angle -= 0.05f;
	}

	m_circlePos[0] = GetCircleCoords(200.0f, circle1angle, ImVec2(100.0f, 200.0f));
	m_circlePos[1] = GetCircleCoords(100.0f, circle2angle, ImVec2(100.0f, 20.0f));
	m_circlePos[2] = GetCircleCoords(45.0f, circle3angle, ImVec2(200.0f, 100.0f));
	m_circlePos[3] = GetCircleCoords(209.0f, circle4angle, ImVec2(0.0f, 200.0f));
	m_circlePos[4] = GetCircleCoords(381.0f, circle5angle, ImVec2(-100.0f, 00.0f));
}


bool RenderInstallButton(ImVec2 pos, ImVec2 size, const char *label) {
	ImGuiWindow *window = ImGui::GetCurrentWindow();
	if (window->SkipItems) {
		return false;
	}
	ImGuiContext &ctx = *GImGui;
	const ImGuiStyle &style = ctx.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 labelSize = ImGui::CalcTextSize(label, NULL, NULL);

	ImVec2 innerSize = size;
	if (innerSize.x <= 0.0f) {
		innerSize.x = labelSize.x + style.FramePadding.x * 2.0f;
	}
	if (innerSize.y <= 0.0f) {
		innerSize.y = labelSize.y + style.FramePadding.y * 2.0f;
	}

	const ImRect rct(pos, ImVec2(pos.x + innerSize.x, pos.y + innerSize.y));
	ImGui::ItemSize(rct, style.FramePadding.y);
	if (!ImGui::ItemAdd(rct, id)) {
		return false;
	}
	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(rct, id, &hovered, &held);

	if (held || hovered) {
		window->DrawList->AddRect(rct.Min, rct.Max, ImColor(1.0f, 1.0f, 1.0f, 0.7f), 8, NULL, 2.0f);
	} else {
		window->DrawList->AddRect(rct.Min, rct.Max, ImColor(1.0f, 1.0f, 1.0f, 1.0f), 8,NULL, 2.0f);
	}

	ImGui::RenderTextClipped(ImVec2(rct.Min.x + style.FramePadding.x, rct.Min.y + style.FramePadding.y), ImVec2(rct.Max.x - style.FramePadding.x, rct.Max.y - style.FramePadding.y), label, NULL,
	                         &labelSize, style.ButtonTextAlign, &rct);


	return pressed;
}

#include <windows.h>

std::string WStringToUTF8(const std::wstring &wstr) {
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int) wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int) wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}

void RenderPathSelectBox(ImVec2 pos, ImVec2 size) {
	ImDrawList *drawList = ImGui::GetWindowDrawList();

	const ImVec2 textBoxSize = ImVec2(size.x - 50.0f, size.y);
	const ImRect rct(pos, ImVec2(textBoxSize.x + pos.x, textBoxSize.y + pos.y));

	drawList->AddRect(rct.Min, rct.Max, ImColor(1.0f, 1.0f, 1.0f, 1.0f), 8, NULL, 2.0f);

	std::string appdataPathString = WStringToUTF8(localAppdataPath);


	if (RenderInstallButton(ImVec2(pos.x - 45.0f + size.x, pos.y), ImVec2(40.0f, size.y), "O")) {
		std::wstring selectedPath = Installer::OpenFolderDialog(localAppdataPath);

		if (!selectedPath.empty()) {
			localAppdataPath = selectedPath;
		}
	}

	std::string finalLocation = appdataPathString + "\\InfinityLauncher";

	const ImVec2 labelSize = ImGui::CalcTextSize(finalLocation.c_str(), NULL, NULL);

	ImGui::RenderTextClipped(ImVec2(pos.x + 8.0f, pos.y + 11.0f), ImVec2(pos.x - 16.0f + textBoxSize.x, pos.y + 11.0f + textBoxSize.y), finalLocation.c_str(),NULL, &labelSize);
}
