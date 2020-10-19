#include "plot_background.h"

namespace gg {

	plot_background::plot_background(rect_t box, element_rect_t pane, rect_t margin, const figure_t& fig) :
		plot_composite(box),
		pane(pane),
		margin(margin),
		fig(fig) 
	{}

	void plot_background::render(wxDC& gdc) {
		draw_rect(gdc, topleft, fullsize, pane, box, fig);
		shrink_rect(box, margin);
		plot_composite::render(gdc);
	}

}
