#pragma once

#include <vector>
#include <string>

#include "wx/wx.h"

#include "types.h"
#include "colours.h"

namespace R {

	static const wxColour transparent{ wxColor(255, 255, 255, wxALPHA_TRANSPARENT) };

	enum class linetypes { blank, solid, dashed, dotted, dotdash, longdash, twodash };
	enum class endstyles { round, butt, square };

	using margin_t = rect_t;

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

		wxColour	colour{ black };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		linetypes	linetype{ linetypes::solid };	// line type blank, solid, dashed, dotted, dotdash, longdash, twodash
		endstyles	lineend{ endstyles::butt };	// line end style round, butt, square
		element_arrow_t arrow;		// arrow specification
	
	};

	/**
	* @brief element_rect: borders and backgrounds
	*/
	struct element_rect_t {

		wxColour	fill{ white };	// fill colour default white
		wxColour	colour{ black };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		linetypes	linetype{ linetypes::solid };	// line type integer 0:8 blank, solid, dashed, dotted, dotdash, longdash, twodash

	};

	/**
	 * @brief element_circle: circles
	 */
	struct element_circle_t {

		wxColour	fill{ white };	// fill colour default white
		wxColour	colour{ black };		// line / border colour default black
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
		wxColour	colour{ black };	// line / border colour
		double		size{ 1 };		// line / border size in mm; text size in pts.
		double		hjust{ 0 };		// horizontal justification (in [0,1])
		double		vjust{ 0 };		// vertical justification (in [0,1])
		double		angle{ 0 };		// angle (in [0,360])
		double		lineheight{ 0 };	// line height as of fontcase
		wxColour	background{ transparent };
		margin_t	margin{ 0, 0, 0, 0, units::inch };	// margins around the text = when creating a theme, the margins should be placed on the side of the text facing towards the center of the plot.
	
	};

}