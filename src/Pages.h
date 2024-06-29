#pragma once

#include "imgui.h"
#include "Components/ProgressBar.h"

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


