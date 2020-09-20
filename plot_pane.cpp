#include "plot_pane.h"

namespace R {

	plot_pane::plot_pane(point_t& position, element_rect_t& element_rect, rect_t& margin, figure_t& fig) :
		plot_component(fig.box),
		position(position),
		element_rect(element_rect),
		margin(margin),
		fig(fig) 
	{}

	void plot_pane::render(wxDC& gdc) {
		draw_rect(gdc, { 0, 0 }, { 1, 1 }, element_rect, fig);
		shrink_by_margin(box, margin);
	}

}
