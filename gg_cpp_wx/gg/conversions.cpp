#include "conversions.h"

namespace gg {

	point_t as_position(rect_t r) {
		return point_t{ as_inch({r.left, r.unit}).val, as_inch({r.top, r.unit}).val };
	}

	dimension_t as_dimension(rect_t r) {
		return { as_inch({r.right - r.left, r.unit}).val, as_inch({r.bottom - r.top, r.unit}).val };
	}

	wxPenStyle as_penstyle(linetypes linetype) {
		//ggplot2 linetype integer - blank, solid, dashed, dotted, dotdash, longdash, twodash
		switch (linetype) {
		case linetypes::blank:
			return wxPENSTYLE_TRANSPARENT;
		case linetypes::solid:
			return wxPENSTYLE_SOLID;
		case linetypes::dashed:
			return wxPENSTYLE_SHORT_DASH;
		case linetypes::dotted:
			return wxPENSTYLE_DOT;
		case linetypes::dotdash:
			return wxPENSTYLE_DOT_DASH;
			break;
		case linetypes::longdash:
			return wxPENSTYLE_LONG_DASH;
			/*	TODO: translate twodash
					case linetype::twodash:
						return wxPENSTYLE_USER_DASH;
			*/
		default:
			return wxPENSTYLE_SOLID;
		}
	}

	int as_fontflag(element_text_t::face_t face) {
		switch (face) { // plain, italic, bold, bold_italic};
		case element_text_t::face_t::plain:
			return wxFONTFLAG_DEFAULT;
		case element_text_t::face_t::italic:
			return wxFONTFLAG_ITALIC;
		case element_text_t::face_t::bold:
			return wxFONTFLAG_BOLD;
		case element_text_t::face_t::bold_italic:
			return wxFONTFLAG_BOLD | wxFONTFLAG_ITALIC;
		default:
			return wxFONTFLAG_DEFAULT;
		}
	}

}