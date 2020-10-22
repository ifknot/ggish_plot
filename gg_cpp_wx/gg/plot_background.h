#pragma once

#include "plot_composite.h"
#include "figure.h"
#include "theme.h"
#include "conversions.h"

namespace gg {

	class plot_background : public plot_composite {

	public:

		plot_background(rect_t bounding_box, const element_rect_t rect, const rect_t margin, const figure_t& fig);

		void render(wxDC& gdc) override final;

	private:

		const element_rect_t		rect;
		const rect_t				margin;

	};

}



