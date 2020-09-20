#pragma once

#include "plot_component.h"
#include "figure.h"
#include "theme.h"

namespace R {

	class plot_title : public plot_component {

	public:

		plot_title(wxString& title, wxString& subtitle, figure_t& fig, theme_t& thememe);

		void render(wxDC& dc) override final;

	private:

		// reference to the parental figure data
		figure_t& fig;
		// reference to the parental theme data
		theme_t& theme;

	};

}

