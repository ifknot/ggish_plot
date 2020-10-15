#include "plot_label.h"

namespace gg {

	plot_label::plot_label(wxString& text, point_t& position, element_text_t& element_text, figure_t& fig) :
		plot_component(fig.box),
		text(text),
		position(position),
		element_text(element_text),
		fig(fig)
	{}

	void plot_label::render(wxDC& gdc) {

		element_rect_t		debug{ transparent, red, 0.5, linetypes::solid };

		if (!text.empty()) {
			if (position.y == 0) { // topleft{ 0, 0 }, top{ 0.5, 0 }, topright{ 1, 0 }
				auto box = draw_text(gdc, position, text, element_text, fig);
				fig.box.top += box.bottom;
			}
			else if (position.y == 1) { // bottomleft{ 0, 1 }, bottom{ 0.5, 1 }, bottomright{ 1, 1 }
				auto box = draw_text(gdc, position, text, element_text, fig);
				fig.box.bottom -= box.bottom;
			}
			else if (position.y == 0.5) { // left, right
				if (position.x == 0) { // left
					auto box = draw_text(gdc, position, text, element_text, fig);
					fig.box.left += box.right;
				}
				else if (position.x == 1) { // right
					auto box = draw_text(gdc, position, text, element_text, fig);
					fig.box.right -= box.right;
				}
			} 
			else {} // floating coordinate
		}
	}

}