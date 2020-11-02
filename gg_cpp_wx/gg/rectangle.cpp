#include "rectangle.h"

namespace gg {



	unit_t rect_t::x() {
		return unit_t({ left, unit });
	}

	unit_t rect_t::y() {
		return unit_t({ top, unit });
	}

	unit_t rect_t::width() {
		return unit_t({ right - left, unit });
	}

	unit_t rect_t::height() {
		return unit_t({ bottom - top, unit });
	}

	rect_t rect_t::shrink(const rect_t& margin) const {
		rect_t r(*this);
		r.left += as_inch({ margin.left, margin.unit }).val;
		r.right -= as_inch({ margin.right, margin.unit }).val;
		r.top += as_inch({ margin.top, margin.unit }).val;
		r.bottom -= as_inch({ margin.bottom, margin.unit }).val;
		return r;
	}

}