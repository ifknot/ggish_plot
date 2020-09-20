#pragma once

#include "plot_composite.h"
#include "figure.h"
#include "theme.h"
#include "conversions.h"

namespace R {

	class plot_panel : public plot_component {

	public:

		plot_panel(point_t& position, element_rect_t& element_rect, rect_t& margin, figure_t& fig);

		void render(wxDC& gdc) override final;

	private:

		point_t& position;
		element_rect_t& element_rect;
		rect_t& margin;
		figure_t& fig;

	};

}



