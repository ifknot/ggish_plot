#pragma once

#include "plot_component.h"
#include "aesthetics.h"
#include "../rpp/data_frame.h"

namespace gg {

	// geom interface
	class geom : public plot_component {

	public:

		geom(rect_t bounding_box, const figure_t& fig, const R::data_frame& data, const aesthetics_t aes );

	private:

		const R::data_frame& data;
		const aesthetics_t aes;

	};

}