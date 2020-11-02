#include "plot_subject.h"

namespace gg {
	
	plot_subject::plot_subject(rect_t bounding_box, const element_rect_t rect, const figure_t& fig, const layer_t& layer):
		plot_background(bounding_box, rect, fig),
		rect(rect),
		layer(layer)
	{}

	void plot_subject::render(wxDC& gdc) {
		plot_background::render(gdc);
	}

}