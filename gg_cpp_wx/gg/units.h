#pragma once

#include "constants.h"

namespace gg {

	enum class units { pt, cm, inch, line };

	struct unit_t {
		double	val;
		units	type;
	};

	/**
	 * convert a unit to inches
	 *
	 * Line spacing is commonly measured as a percentage of font size.
	 * Conventional wisdom is that line spacing of 130%-150% is ideal for readability.
	 * In fact, anything from about 120% up to 200% is acceptable but 140% tends to be the most quoted sweet spot.
	 * @param u
	 * @param lineheight (default to 1.4)
	 * @return
	 */
	unit_t as_inch(unit_t u, double lineheight = 1.4);

}