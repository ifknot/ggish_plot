#pragma once

#include <utility>

namespace R {

	static constexpr double pi = 3.141593;
	static constexpr double	half_circle = pi / 180;
	static const double cm_per_inch = 2.54;
	static const double inch_per_cm = 0.393701;
	static const double pt_per_inch = 72.27;	// There are 72.27 points per inch (but note the closely related "bigpts" Big Points. 72 bp = 1 in.)

	using dpi_t = int;

	enum class units { pt, cm, inch, line };

	using unit_t = std::pair<double, units>;

	enum class colour_mode_t{ RGB, grayscale };

	using point_t = std::pair<double, double>;

	using ratio_t = std::pair<double, double>;

	using dimension_t = std::pair<double, double>;

	struct rect_t {

		rect_t(double top, double bottom, double left, double right, units unit) :
			top(top),
			bottom(bottom),
			left(left),
			right(right),
			unit(unit) {
		}

		double	top;
		double	bottom;
		double	left;
		double	right;
		units	unit;

	};

}