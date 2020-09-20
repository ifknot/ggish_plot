#include "plot_panel.h"

namespace R {



	plot_panel::plot_panel(point_t& position, element_rect_t& element_rect, figure_t& fig) :
		plot_component(fig.box),
		position(position),
		element_rect(element_rect),
		fig(fig) 
	{}

	void plot_panel::render(wxDC& gdc) {
	}

}
