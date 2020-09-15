#pragma once

#include "types.h"

namespace R {

	unit_t as_inch(unit_t u);

	static inline double as_radians(double x) {
		return x * half_circle;
	}

}

