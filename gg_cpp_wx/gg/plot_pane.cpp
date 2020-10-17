#include "plot_pane.h"

namespace gg {

	plot_pane::plot_pane(point_t position, dimension_t dim, element_rect_t element_rect, figure_t& fig) :
		plot_composite(fig.box),
		position(position),
		dim(dim),
		element_rect(element_rect),
		margin(margin),
		fig(fig) 
	{}

	void plot_pane::render(wxDC& gdc) {
		draw_rect(gdc, position, dim, element_rect, fig);
		plot_composite::render(gdc);
	}

}
