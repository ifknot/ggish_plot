#include "plot_label.h"

namespace R {

	plot_label::plot_label(wxString& text, point_t& position, element_text_t& element_text, figure_t& fig) :
		plot_component(fig.box),
		text(text),
		position(position),
		element_text(element_text),
		fig(fig)
	{}

	void plot_label::render(wxDC& gdc) {
		if (!text.empty()) {
			if (position.y == 0) { // topleft, top, topright
				auto box = draw_text(gdc, position, text, element_text, fig);
				fig.box.top += box.bottom;
			}
			else if (position.y == 1) { // bottomleft, bottom, bottomright
				auto box = get_text_bounding_box(gdc, position, text, element_text, fig);
				fig.box.bottom -= box.bottom;
				box = draw_text(gdc, position, text, element_text, fig);
			}
			else if (position.y == 0.5) {} // left, right
			else {} // floating coordinate
		}
	}

}