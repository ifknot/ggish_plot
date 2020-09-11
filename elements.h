#pragma once

#include <utility>
#include <vector>
#include <string>

#include "wx/wx.h"

namespace R {

	static enum colour_mode_t { RGB, grayscale };

	using point = std::pair<double, double>;

	struct element_line {

		wxColour	colour;
		double		size;
		wxPenStyle  linetype;
		wxPenCap	lineend;

	};

	struct element_rect {

		wxColour	fill;
		wxColour	colour;
		double		size;
		wxPenStyle  linetype;

	};


	/*
	wxFont::wxFont	(	int 	pointSize,
	wxFontFamily 	family,
	wxFontStyle 	style,
	wxFontWeight 	weight,
	bool 	underline = false,
	const wxString & 	faceName = wxEmptyString,
	wxFontEncoding 	encoding = wxFONTENCODING_DEFAULT
	)
	*/
	struct element_text {



	};

}