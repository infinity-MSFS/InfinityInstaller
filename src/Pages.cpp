#include "Pages.h"

Pages::Pages::Pages()
{
}

void Pages::Pages::NextPage()
{
	s_currentPage++;
}

void Pages::Pages::PrevPage()
{
	s_currentPage--;
}

void Pages::Pages::RenderPageContent()
{
	GetPageContent(intToPage(s_currentPage));
}

void Pages::Pages::GetPageContent(Page page)
{
	switch (page)
	{
	case Page::Welcome:
	{
		ImGui::Text("Welcum to Infinity Launcher");

		if (ImGui::Button("Next")) {
			NextPage();
		}
	}
		break;
	case Page::License:
	{
		ImGui::Text("License Agreement");
		if (ImGui::Button("Back")) {
			PrevPage();
		}
		if (ImGui::Button("Next")) {
			NextPage();
		}
	}
		break;
	case Page::Path:
	{
		ImGui::Text("Path");
		if (ImGui::Button("Back")) {
			PrevPage();
		}
		if (ImGui::Button("Next")) {
			NextPage();
		}
	}
		break;
	case Page::Download:

	{
		ImGui::Text("Downloading");
		if (ImGui::Button("Back")) {
			PrevPage();
		}
		if (ImGui::Button("Next")) {
			NextPage();
		}
	}
		break;
	case Page::Complete:
	{
		ImGui::Text("Complete");
		if (ImGui::Button("Back")) {
			PrevPage();
		}
		if (ImGui::Button("Finish")) {
			NextPage();
		}
	}
		break;
	default:
		break;
	}
}

Pages::Page Pages::Pages::intToPage(int page)
{
	switch (page) {
	case 0: return Page::Welcome;
	case 1: return Page::License;
	case 2: return Page::Path;
	case 3: return Page::Download;
	case 4: return Page::Complete;
	default: return Page::Welcome;
	}
}
