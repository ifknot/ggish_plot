#pragma once

#include "plot_background.h"
#include "layer.h"

namespace gg {

	class plot_subject : public plot_background {

	public:

		plot_subject(rect_t bounding_box, const element_rect_t rect, const figure_t& fig, const layer_t& layer);

		void render(wxDC& gdc) override;

	private:

		const element_rect_t		rect;
		const layer_t&				layer;

		//composite a bunch of labels with this bounds

	};

}