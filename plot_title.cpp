#include "plot_title.h"

namespace R {



	plot_title::plot_title(wxString title, figure_t& fig, theme_t& theme) :
		plot_component(), 
		title(title),
		fig(fig),
		theme(theme)
	{}

	void plot_title::render(wxDC& dc) {
		auto box = draw_text(dc, { 0.5, 0.0 }, title, fig, theme.plot.title, theme);
		fig.box.top += box.bottom;

	}

}