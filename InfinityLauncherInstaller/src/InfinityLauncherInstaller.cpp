#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"
#include "Walnut/UI/UI.h"
#include "Installer.h"
#include "Pages.h"

#include "utils.h"

#include <iostream>

#include "InfinityUI.h"

static std::wstring localAppdataPath = Installer::GetLocalAppDataPath();


Pages::Pages page;


class MainLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender(ImVec2 windowPos, ImVec2 windowSize) override
	{
		ImDrawList* drawList = ImGui::GetWindowDrawList();
		InfinityUI infUi(windowSize, windowPos, drawList);

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

		page.RenderPageContent();
		

	}
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Infinity Installer";
	spec.CustomTitlebar = false;
	spec.CenterWindow = true;
	spec.Width = 500;
	spec.Height = 400;

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<MainLayer>();
	
	return app;
}

