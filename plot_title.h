#pragma once

#include "plot_component.h"
#include "figure.h"
#include "theme.h"

namespace R {
	class plot_title : public plot_component {

	public:

		plot_title(wxString title, figure_t& fig, theme_t& theme);

		void render(wxDC& dc) override final;

	private:

		wxString title;
		figure_t& fig;
		theme_t& theme;

	};

}

