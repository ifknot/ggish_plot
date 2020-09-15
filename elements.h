#pragma once

#include <vector>
#include <string>

#include "wx/wx.h"

#include "types.h"

namespace R {

	struct rect_t {		

		double top{ 0 };
		double bottom{ 1 };
		double left{ 0 };
		double right{ 1 };

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

		wxColour	colour{ wxColor(0, 0, 0, wxALPHA_OPAQUE) };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		int			linetype{ 1 };	// line type integer 0:8 blank, solid, dashed, dotted, dotdash, longdash, twodash
		int			lineend{ 0 };	// line end style 0:3 round, butt, square
		element_arrow_t arrow;		// arrow specification
	
	};

	/**
	* @brief element_rect: borders and backgrounds
	*/
	struct element_rect_t {

		wxColour	fill{ wxColor(255, 255, 255, wxALPHA_OPAQUE) };	// fill colour default white
		wxColour	colour{ wxColor(0, 0, 0, wxALPHA_OPAQUE) };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		int			linetype{ 1 };	// line type integer 0:8 blank, solid, dashed, dotted, dotdash, longdash, twodash

	};

	/**
	 * @brief element_circle: circles
	 */
	struct element_circle_t {

		wxColour	fill{ wxColor(255, 255, 255, wxALPHA_OPAQUE) };	// fill colour default white
		wxColour	colour{ wxColor(0, 0, 0, wxALPHA_OPAQUE) };		// line / border colour default black
		double		size{ 1 };		// line / border size in mm; text size in pts.
		int			linetype{ 1 };	// line type integer 0:8 blank, solid, dashed, dotted, dotdash, longdash, twodash

	};

	struct margin_t {

		double		t{ 0 };
		double		r{ 0 };
		double		b{ 0 };
		double		l{ 0 }; 
		units		unit{ units::pt };

	};

	/**
	 * @brief element_text: text
	 */
	struct element_text_t {

		enum class face_t { plain, italic, bold, bold_italic};

		wxString	family{ "Ariel" };
		face_t		face{ face_t::plain };
		wxColour	colour{ wxColor(0, 0, 0, wxALPHA_OPAQUE) };	// line / border colour
		double		size{ 1 };		// line / border size in mm; text size in pts.
		double		hjust{ 0 };		// horizontal justification (in [0,1])
		double		vjust{ 0 };		// vertical justification (in [0,1])
		double		angle{ 0 };		// angle (in [0,360])
		double		lineheight{ 0 };	// line height 
		wxColour	background{ wxColor(255, 255, 255, wxALPHA_TRANSPARENT) };
		margin_t	margin;			// margins around the text = when creating a theme, the margins should be placed on the side of the text facing towards the center of the plot.
		bool		debug{ false };	// aids visual debugging by drawing a solid rectangle behind the complete text area, and a point where each label is anchored.
		double		x{ 0 };			// single number specifying size relative to parent element
		
	};

}