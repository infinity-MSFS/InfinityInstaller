
#include <filesystem>
#include <iostream>

#include "Backend/Application/Application.hpp"
#include "Frontend/InfinityUI/InfinityUI.hpp"
#include "Frontend/Pages/Pages.h"
#include "imgui_internal.h"


bool g_ApplicationRunning = true;


Pages::Pages page;

static double lastFrameTime = 0.0;

class PageRenderLayer final : public Infinity::Layer {
public:
    virtual void OnUIRender() override {
        ImDrawList *drawList = ImGui::GetWindowDrawList();
        InfinityUI infUi;


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



        //ImGui::Text("FPS: %.2f", fps);



        page.RenderPageContent();
    }
};

Infinity::Application *Infinity::CreateApplication(int argc, char **argv) {
    const std::filesystem::path path = "Assets/Images/Logo.h";
    const ApplicationSpecifications specifications = ApplicationSpecifications{"Infinity Installer",
                                                                               std::make_pair(500, 300),
                                                                               std::make_pair(500, 300),
                                                                               std::make_pair(500, 300),
                                                                               path,
                                                                               false,
#ifdef WIN32
            true,
#else
                                                                               false,
#endif
                                                                               true};
    const auto app = new Application{specifications};
    app->PushLayer<PageRenderLayer>();

    return app;
}


namespace Infinity {
    int Main(const int argc, char **argv) {
        while (g_ApplicationRunning) {
            const auto app = CreateApplication(argc, argv);
            app->Run();
            delete app;
            g_ApplicationRunning = false;
        }
        return 0;
    }
} // namespace Infinity


#if defined(RELEASE_DIST) && WIN32

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nShowCmd) { Infinity::Main(__argc, __argv); }

#else

int main(const int argc, char **argv) { Infinity::Main(argc, argv); }

#endif