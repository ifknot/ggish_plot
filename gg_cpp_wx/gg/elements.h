#pragma once

#include <vector>
#include <string>

#include "types.h"
#include "colours.h"

namespace gg {

	static const colour_t transparent{ 255, 255, 255, wxALPHA_TRANSPARENT };

	enum class linetypes { blank, solid, dashed, dotted, dotdash, longdash, twodash };
	enum class endstyles { round, butt, square };

	const dimension_t halfsize{ 0.5, 0.5 };
	const dimension_t fullsize{ 1,1 };

	const point_t topleft{ 0, 0 };
	const point_t top{ 0.5, 0 };
	const point_t topright{ 1, 0 };
	const point_t left{ 0, 0.5 };
	const point_t right{ 1, 0.5 };
	const point_t bottomleft{ 0, 1 };
	const point_t bottom{ 0.5, 1 };
	const point_t bottomright{ 1, 1 };

	struct font_t {
		double				size;
		wxString			family;
	};

	/**
	 * description of what arrows to add to a line
	 * the result can be passed to grid::lines
	 */
	struct element_arrow_t {

		enum class arrow_end_t { last, first, both };
		enum class arrow_type_t { open, closed };

		double		angle{ 45 };		// the angle of the arrow head in degrees (smaller numbers produce narrower, pointier arrows).Essentially describes the width of the arrow head.length
		unit_t		length{ 1, units::pt };	// unit specifying the length of the arrow head (from tip to base).
		arrow_end_t		ends{ arrow_end_t::last };	// one of "last", "first", or "both", indicating which ends of the line to draw arrow heads.
		arrow_type_t	type{ arrow_type_t::open };	// one of "open" or "closed" indicating whether the arrow head should be a closed triangle.

	};

	/**
	 * @brief element_line: lines
	 * @url https://ggplot2.tidyverse.org/reference/element.html
	 */
	struct element_line_t {

		colour_t	colour{ black };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		linetypes	linetype{ linetypes::solid };	// line type blank, solid, dashed, dotted, dotdash, longdash, twodash
		endstyles	lineend{ endstyles::butt };	// line end style round, butt, square
		element_arrow_t arrow;		// arrow specification
	
	};

	/**
	* @brief element_rect: borders and backgrounds
	*/
	struct element_rect_t {

		colour_t	fill{ white };	// fill colour default white
		colour_t	colour{ black };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		linetypes	linetype{ linetypes::solid };	// line type integer 0:8 blank, solid, dashed, dotted, dotdash, longdash, twodash

	};

	/**
	 * @brief element_circle: circles
	 */
	struct element_circle_t {

		colour_t	fill{ white };	// fill colour default white
		colour_t	colour{ black };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		linetypes	linetype{ linetypes::solid };	// line type integer 0:8 blank, solid, dashed, dotted, dotdash, longdash, twodash

	};

	/**
	 * @brief element_text: text
	 */
	struct element_text_t {

		enum class face_t { plain, italic, bold, bold_italic};

		wxString	family{ "Ariel" };
		face_t		face{ face_t::plain };
		colour_t	colour{ black };	// line / border colour
		double		size{ 1 };		// line / border size in mm; text size in pts.
		double		hjust{ 0 };		// horizontal justification (in [0,1])
		double		vjust{ 0 };		// vertical justification (in [0,1])
		double		angle{ 0 };		// angle (in [0,360])
		double		lineheight{ 1.4 };	// line height as factor of font size 
		// Line spacing is commonly measured as a percentage of font size. 
		// Conventional wisdom is that line spacing of 130%-150% is ideal for readability. 
		// In fact, anything from about 120% up to 200% is acceptable
		// but 140% tends to be the most quoted sweet spot.
		colour_t	background{ transparent };
		rect_t		margin{ 0, 0, 0, 0, units::inch };	// margins around the text = when creating a theme, the margins should be placed on the side of the text facing towards the center of the plot.
	};

}