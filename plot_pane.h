#pragma once

#include "plot_composite.h"
#include "figure.h"
#include "theme.h"
#include "conversions.h"

namespace R {

	class plot_pane : public plot_composite {

	public:

		plot_pane(point_t position, dimension_t dim, element_rect_t element_rect, figure_t& fig);

		void render(wxDC& gdc) override final;

	private:

		data_frame					data;

		point_t position;
		dimension_t dim;
		element_rect_t element_rect;
		rect_t& margin;
		figure_t& fig;

	};

}



