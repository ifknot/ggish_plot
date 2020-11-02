#pragma once

namespace gg {

	static constexpr double pi = 3.141593;

	static constexpr double	half_circle = pi / 180;

	static const double cm_per_inch = 2.54;

	static const double inch_per_cm = 0.393701;

	/**
	 * There are 72.27 points per inch 
	 * @note but the closely related "bigpts" Big Points. 72 bp = 1 in.
	 */
	static const double pt_per_inch = 72.27;

	/**
	 * Line spacing is commonly measured as a percentage of font size.
	 * Conventional wisdom is that line spacing of 130%-150% is ideal for readability.
	 * In fact, anything from about 120% up to 200% is acceptable but 140% tends to be the most quoted sweet spot.
	 */
	static const double line_height = 1.4;

}
