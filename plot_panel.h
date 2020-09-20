#pragma once

#include "plot_composite.h"
#include "figure.h"
#include "theme.h"

namespace R {

	class plot_panel : public plot_component {

	public:

		plot_panel(point_t& position, element_rect_t& element_rect, figure_t& fig);

		void render(wxDC& gdc) override final;

	private:

		point_t& position;
		element_text_t& element_rect;
		figure_t& fig;

	};

}



