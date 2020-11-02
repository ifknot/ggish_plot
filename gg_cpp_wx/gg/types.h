#pragma once

#include <utility>

#include "rectangle.h"

namespace gg {

	using dpi_t = int;

	enum class colour_mode_t{ RGB, grayscale };

	using ratio_t = std::pair<double, double>;

	struct point_t {
		double x; 
		double y;
	};

	struct dimension_t {
		double width;
		double height;
	};
	
}