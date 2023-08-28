#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include <windows.h>
#include "Walnut/Image.h"
#include <iostream>

class ExampleLayer : public Walnut::Layer
{
public:
    virtual void OnUIRender() override
    {
        ImGui::Begin("Launch Games");

        //STEAM LAUNCHER
        (ImGui::TextWrapped("Steam Games"));

        if (ImGui::Button("CSGO"))
        {
            system("start steam://run/730");
        }

        //EPIC GAMES LAUNCHER
        (ImGui::TextWrapped("Epic Games"));
        if (ImGui::Button("Fortnite"))
        {

            std::cout << "Fortnite" << std::endl;
            system("start com.epicgames.launcher://apps/fn%3A4fe75bbc5a674f4f9b356b5c90567da5%3AFortnite?action=launch&silent=true");

        }

        //MISCELANEOUS GAMES
        (ImGui::TextWrapped("Misc"));
        if (ImGui::Button("Osu!"))
        {
            system("start C:\\Users\\nylo\\AppData\\Local\\osu!\\osu!.exe");
        }

        ImGui::End();

        UI_DrawAboutModal();
    }

    void UI_DrawAboutModal()
    {
        if (!m_AboutModalOpen)
            return;
    }

    void ShowAboutModal()
    {
        m_AboutModalOpen = true;
    }
private:
    bool m_AboutModalOpen = false;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
    Walnut::ApplicationSpecification spec;
    spec.Name = "nylo's Launcher";

    Walnut::Application* app = new Walnut::Application(spec);
    std::shared_ptr<ExampleLayer> exampleLayer = std::make_shared<ExampleLayer>();
    app->PushLayer(exampleLayer);
    app->SetMenubarCallback([app, exampleLayer]()
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Exit"))
                {
                    app->Close();
                }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Help"))
            {
                if (ImGui::MenuItem("About"))
                {
                    exampleLayer->ShowAboutModal();
                }
                ImGui::EndMenu();
            }
        });
    return app;
}