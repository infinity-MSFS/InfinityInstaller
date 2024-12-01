#pragma once

#include "imgui.h"
#include "Frontend/Components/ProgressBar.h"
#include <vector>


namespace Pages {
	static int s_currentPage = 0;

	enum Page {
		Welcome = 0,
		License,
		Path,
		Download,
		Complete,
		PageCount
	};

	class Pages {
	public:
		Pages();

		void NextPage();

		void PrevPage();

		void RenderPageContent();

	private:
		void GetPageContent(Page page);

		Page intToPage(int page);
	};
}

std::vector<ImVec2> CalculateNormals(const ImVec2 *points, int num_points);

void DrawPolygonWithDynamicShadow(ImDrawList *draw_list, const ImVec2 *points, const int num_points, ImColor color);

