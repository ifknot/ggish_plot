#include "plot_background.h"

namespace gg {

	plot_background::plot_background(rect_t bounding_box, const element_rect_t rect, const figure_t& fig) :
		plot_composite(bounding_box, fig),
		rect(rect)
	{}

	void plot_background::render(wxDC& gdc) {
		draw_rect(gdc, topleft, fullsize, rect);
		plot_composite::render(gdc);
	}

}
