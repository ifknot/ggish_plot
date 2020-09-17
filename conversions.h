#pragma once

#include <math.h>

#include "types.h"

namespace R {

	static inline double as_radians(double x) {
		return x * half_circle;
	}

	unit_t as_inch(unit_t u);

	void shrink(rect_t& r, const rect_t m);

}

