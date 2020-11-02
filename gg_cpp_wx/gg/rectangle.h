#pragma once

#include "units.h"

namespace gg {

	struct rect_t {

		double	left;
		double	right;
		double	top;
		double	bottom;
		units	unit;

		rect_t() = default;

		rect_t(double left, double right, double top, double bottom, units unit) :
			left(left),
			right(right),
			top(top),
			bottom(bottom),
			unit(unit) {
		}

		rect_t(const rect_t& other) = default;

		rect_t& operator=(const rect_t& other) = default;

		unit_t x();

		unit_t y();

		unit_t width();

		unit_t height();

		rect_t shrink(const rect_t& margin) const;

;

	};

}