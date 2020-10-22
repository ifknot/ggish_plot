#pragma once

#include "../rpp/data_types.h"

namespace gg {

	/**
	 * Holds the 5 field names that are used to draw the geometric objects (geoms) that represent a data point
	 * Empty strings are permitted for size, colour and shape resulting in the defaults for a particular geom
	 */
	struct aesthetics_t {

		R::r_string		x;
		R::r_string		y;
		R::r_string		size;
		R::r_string		colour;
		R::r_string		shape;

	};

}