#pragma once

#include "units.h"

namespace gg {

	struct rect_t {

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

		inline rect_t shrink(const rect_t& margin) const {
			rect_t r(*this);
			r.left += as_inch({ margin.left, margin.unit }).val;
			r.right -= as_inch({ margin.right, margin.unit }).val;
			r.top += as_inch({ margin.top, margin.unit }).val;
			r.bottom -= as_inch({ margin.bottom, margin.unit }).val;
			return r;
		}

		double	left;
		double	right;
		double	top;
		double	bottom;
		units	unit;

	};

}