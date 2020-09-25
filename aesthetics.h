#pragma once

#include <string>
#include <array>

namespace R {

	/**
	 * Holds the 5 field names that are used to draw the geometric objects (geoms) that represent a data point
	 * Empty strings are permitted for size, colour and shape resulting in the defaults for a particular geom
	 */
	struct aesthetics_t {

		std::string		x;
		std::string		y;
		std::string		size;
		std::string		colour;
		std::string		shape;

	};

}