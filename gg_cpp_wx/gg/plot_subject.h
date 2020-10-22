#pragma once

#include "plot_composite.h"
#include "layer.h"

namespace gg {

	class plot_subject : public plot_composite {

	public:

		// needs a layer of data& and aesthetic& etc from parent 
		plot_subject(rect_t bounding_box, const element_rect_t rect, const rect_t margin, const figure_t& fig, const layer_t& layer);

		void render(wxDC& gdc) override final;

	private:

		const element_rect_t		rect;
		const rect_t				margin;

		//composite a bunch of labels with this bounds

	};

}