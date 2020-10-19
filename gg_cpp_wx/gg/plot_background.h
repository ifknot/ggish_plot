#pragma once

#include "plot_composite.h"
#include "figure.h"
#include "theme.h"
#include "conversions.h"

namespace gg {

	class plot_background : public plot_composite {

	public:

		plot_background(rect_t box, element_rect_t pane, rect_t margin, const figure_t& fig);

		void render(wxDC& gdc) override final;

	private:

		element_rect_t		pane;
		rect_t				margin;
		const figure_t&		fig;

	};

}



