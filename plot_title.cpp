#include "plot_title.h"

namespace R {



	plot_title::plot_title(wxString& title, wxString& subtitle, figure_t& fig, theme_t& theme) :
		plot_component(fig.box),
		fig(fig),
		theme(theme)
	{}

	void plot_title::render(wxDC& dc) {
		

	}

}