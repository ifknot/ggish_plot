#include "plot_background.h"

namespace gg {

	plot_background::plot_background(rect_t bounding_box, const element_rect_t rect, rect_t margin, const figure_t& fig) :
		plot_composite(bounding_box, fig),
		rect(rect),
		margin(margin)
	{}

	void plot_background::render(wxDC& gdc) {
		draw_rect(gdc, topleft, fullsize, rect);
		shrink_bounds(margin);
		plot_composite::render(gdc);
	}

}
