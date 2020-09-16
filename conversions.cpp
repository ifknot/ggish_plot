#include "conversions.h"

namespace R {

	unit_t as_inch(unit_t u) {
		switch (u.second) {
		case units::pt:
			return unit_t{ u.first / pt_per_inch, units::inch };
		case units::cm:
			return unit_t{ u.first / cm_per_inch, units::inch };
		case units::inch:
			return unit_t{ u };
		}
	}

}