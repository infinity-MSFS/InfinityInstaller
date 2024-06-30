#include "Pages.h"
#include "ApplicationGUI.h"
#include "InfinityUI.h"
#include "Components/WelcomeTextAnimation.h"


Pages::Pages::Pages() {
}

void Pages::Pages::NextPage() {
	s_currentPage++;
}

void Pages::Pages::PrevPage() {
	s_currentPage--;
}

void Pages::Pages::RenderPageContent() {
	GetPageContent(intToPage(s_currentPage));
}

static float percentage = 0.0;
static std::string path;


void Pages::Pages::GetPageContent(Page page) {
	switch (page) {
		case Page::Welcome: {
			static auto prevTime = std::chrono::steady_clock::now();
			auto now = std::chrono::steady_clock::now();
			ImDrawList *drawList = ImGui::GetWindowDrawList();
			WelcomeTextAnimation cumAnimation;


			RenderPathSelectBox(ImVec2((ImGui::GetWindowSize().x / 2.0f - 480.0f / 2.0f), 150.0f), ImVec2(480.0f, 45.0f));

			RenderInstallButton(ImVec2((ImGui::GetWindowSize().x / 2.0f - 480.0f / 2.0f), 220.0f), ImVec2(480.0f, 45.0f), "Install Launcher");

			cumAnimation.getText(drawList, ImVec2(200.0f, 70.0f)); // x position isnt going to do anything here

			ImGui::SetCursorPos(ImVec2(60.0f, 12.0f));
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
			ImGui::Text("Infinity Launcher");
			ImGui::PopStyleColor();
		}
		break;

		default:
			break;
	}
}

Pages::Page Pages::Pages::intToPage(int page) {
	switch (page) {
		case 0: return Page::Welcome;
		case 1: return Page::License;
		case 2: return Page::Path;
		case 3: return Page::Download;
		case 4: return Page::Complete;
		default: return Page::Welcome;
	}
}

