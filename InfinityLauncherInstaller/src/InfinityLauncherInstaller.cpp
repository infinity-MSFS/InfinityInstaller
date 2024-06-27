#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"
#include "Walnut/UI/UI.h"

#include <iostream>

#include "InfinityUI.h"

class MainLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender(ImVec2 windowPos, ImVec2 windowSize) override
	{
		ImDrawList* drawList = ImGui::GetWindowDrawList();
		InfinityUI infUi(windowSize, windowPos, drawList);

		infUi.Renderbackground();
		
		ImGui::Text("Sah");
		

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

