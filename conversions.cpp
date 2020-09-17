#include "conversions.h"

namespace R {

	// TODO: fix lines to use base_line_size - ?pass a theme to as_inch
	unit_t as_inch(unit_t u) {
		switch (u.second) {
		case units::pt:
			return unit_t{ u.first / pt_per_inch, units::inch };
		case units::cm:
			return unit_t{ u.first / cm_per_inch, units::inch };
		case units::lines: // TODO: improve
			return unit_t{ u.first / 22, units::inch };
		case units::inch:
		default:
			return unit_t{ u };
		}
	}

}