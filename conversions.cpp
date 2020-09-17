#include "conversions.h"

namespace R {

	// TODO: fix lines to use base_line_size - ?pass a theme to as_inch
	unit_t as_inch(unit_t u) {
		switch (u.second) {
		case units::pt:
			return unit_t{ u.first / pt_per_inch, units::inch };
		case units::cm:
			return unit_t{ u.first / cm_per_inch, units::inch };
		case units::line: // TODO: improve
			return unit_t{ u.first / 22, units::inch };
		case units::inch:
		default:
			return unit_t{ u };
		}
	}

	void shrink_by_margin(rect_t& r, const rect_t& margin) {
		r.left += R::as_inch({ margin.left, margin.unit }).first;
		r.right -= R::as_inch({ margin.right, margin.unit }).first;
		r.top += R::as_inch({ margin.top, margin.unit }).first;
		r.bottom -= R::as_inch({ margin.bottom, margin.unit }).first;
	}

}