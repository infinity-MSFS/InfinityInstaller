#include "Application.h"
#include "EntryPoint.h"
#include "Image.h"
#include "UI/UI.h"
#include "Installer.h"
#include "Pages.h"

#include "util/utils.h"

#include <iostream>

#include "InfinityUI.h"
#include "GLFW/glfw3.h"
#include "util/FPSCounter.h"

static std::wstring localAppdataPath = Installer::GetLocalAppDataPath();


Pages::Pages page;


static double lastFrameTime = 0.0;
FPSCounter fpsCounter;

class MainLayer : public Walnut::Layer {
public:
	virtual void OnUIRender(ImVec2 windowPos, ImVec2 windowSize) override {
		ImDrawList *drawList = ImGui::GetWindowDrawList();
		InfinityUI infUi(windowSize, windowPos, drawList);

		fpsCounter.setLastFrameTime(lastFrameTime);

		infUi.Renderbackground();

		//std::string localAppDataPathString = WStringToUTF8(localAppdataPath);

		//ImGui::Text("Install Directory: %s", localAppDataPathString.c_str());
		//if (ImGui::Button("Select another folder")) {
		//std::wstring selectedPath = Installer::OpenFolderDialog(localAppdataPath);

		//if (!selectedPath.empty()) {
		//	localAppdataPath = selectedPath;
		//}
		//}
		//ImGui::Text("Selected Path");

		double currentFrameTime = glfwGetTime();
		fpsCounter.setCurrentFrameTime(currentFrameTime);

		const double fps = fpsCounter.GetFps();

		ImGui::Text("FPS: %.2f", fps);

		lastFrameTime = currentFrameTime;


		page.RenderPageContent();
	}
};

Walnut::Application *Walnut::CreateApplication(int argc, char **argv) {
	Walnut::ApplicationSpecification spec;
	spec.Name = "Infinity Installer";
	spec.CustomTitlebar = true;
	spec.CenterWindow = true;
	spec.Width = 500;
	spec.Height = 400;

	Walnut::Application *app = new Walnut::Application(spec);
	app->PushLayer<MainLayer>();

	return app;
}

