#include "plot_pane.h"

namespace R {

	plot_pane::plot_pane(point_t& position, element_rect_t& element_rect, figure_t& fig) :
		plot_composite(fig.box),
		position(position),
		element_rect(element_rect),
		margin(margin),
		fig(fig) 
	{}

	void plot_pane::render(wxDC& gdc) {
		draw_rect(gdc, { 0, 0 }, { 1, 1 }, element_rect, fig);
		plot_composite::render(gdc);
	}

}
