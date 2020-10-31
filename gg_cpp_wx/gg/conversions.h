#pragma once

#include <math.h>

#include "wx/wx.h"

#include "elements.h"

namespace gg {

	static inline double as_radians(double x) {
		return x * half_circle;
	}

	point_t as_position(rect_t r);
	
	dimension_t as_dimension(rect_t r);

	wxPenStyle as_penstyle(linetypes linetype);

	int as_fontflag(element_text_t::face_t face);



}

