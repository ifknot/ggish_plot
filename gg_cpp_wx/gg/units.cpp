#include "units.h"

namespace gg {

	unit_t as_inch(unit_t u, double lineheight) {
		switch (u.type) {
		case units::pt:
			return unit_t{ u.val / pt_per_inch, units::inch };
		case units::cm:
			return unit_t{ u.val / cm_per_inch, units::inch };
		case units::line:
			return  unit_t{ (u.val / pt_per_inch) * lineheight , units::inch };
		case units::inch:
		default:
			return unit_t{ u };
		}
	}

}
