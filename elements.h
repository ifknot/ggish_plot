#pragma once

#include <utility>
#include <vector>
#include <string>

#include "wx/wx.h"

namespace R {

	static enum colour_mode_t { RGB, grayscale };

	using point_t = std::pair<double, double>;

	using dimension_t = std::pair<double, double>;

	struct element_line_t {

		wxColour	colour;
		double		size;
		wxPenStyle  linetype;
		wxPenCap	lineend;

	};

	struct element_rect_t {

		wxColour	fill;
		wxColour	colour;
		dimension_t	size;
		wxPenStyle  linetype;

	};

	struct element_circle_t {
	
		wxColour	fill;
		wxColour	colour;
		double		radius;
		wxPenStyle  linetype;

	};

	struct element_text_t {

		wxFontFamily	font_family = wxFONTFAMILY_DEFAULT;
		wxString	 	base_family;
		int	 			face;
		wxColour		colour;
		wxColour		background_colour;
		size_t			base_size;
		double			h_just;
		double			v_just;
		double			angle;
		double			line_height;
		double			margin;
		bool			debug;

	};

}