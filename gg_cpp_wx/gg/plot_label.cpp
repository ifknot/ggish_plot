#include "plot_label.h"

namespace gg {

	plot_label::plot_label(rect_t bounding_box, const wxString& s, const point_t position, const element_text_t& text, const figure_t& fig) :
		plot_component(bounding_box, fig),
		s(s),
		position(position),
		text(text)
	{}

	void plot_label::render(wxDC& gdc) {

		element_rect_t		debug{ transparent, red, 0.5, linetypes::solid };

		if (!s.empty()) {
			if (position.y == 0) { // topleft{ 0, 0 }, top{ 0.5, 0 }, topright{ 1, 0 }
				auto text_box = draw_text(gdc, position, s, text);
				shrink_bounds({0.0, 0.0, text_box.bottom, 0.0, text_box.unit});
			}
			else if (position.y == 1) { // bottomleft{ 0, 1 }, bottom{ 0.5, 1 }, bottomright{ 1, 1 }
				auto text_box = draw_text(gdc, position, s, text);
				shrink_bounds({ 0.0, 0.0, 0.0, text_box.bottom, text_box.unit});
			}
			else if (position.y == 0.5) { // left, right
				if (position.x == 0) { // left
					auto text_box = draw_text(gdc, position, s, text);
					shrink_bounds({ text_box.right, 0.0, 0.0, 0.0, text_box.unit });
				}
				else if (position.x == 1) { // right
					auto text_box = draw_text(gdc, position, s, text);
					shrink_bounds({ 0.0, text_box.right, 0.0, 0.0, text_box.unit });
				}
			} 
			else {} // floating coordinate
		}
	}

}