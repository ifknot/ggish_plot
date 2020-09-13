#include "plot_component.h"

namespace R {

	void plot_component::element_rect(wxDC& dc, R::point_t p, R::dimension_t d, R::theme_t& theme) {
	
		//linetype integer 0:6 blank, solid, dashed, dotted, dotdash, longdash, twodash
		wxPenStyle linetype;
		switch (theme.element_rect.linetype) {
		case 0:
			linetype = wxPENSTYLE_TRANSPARENT;
			break;
		case 1:
			linetype = wxPENSTYLE_SOLID;
			break;
		case 2:
			linetype = wxPENSTYLE_SHORT_DASH;
			break;
		case 3:
			linetype = wxPENSTYLE_DOT;
			break;
		case 4:
			linetype = wxPENSTYLE_DOT_DASH;
			break;
		case 5:
			linetype = wxPENSTYLE_LONG_DASH;
			break;
		//case 6:
			//linetype = wxPENSTYLE_USER_DASH;
			//break;
		default:
			linetype = wxPENSTYLE_SOLID;
		}
		dc.SetPen(wxPen(theme.element_rect.colour, static_cast<int>(theme.element_rect.size)));
		dc.SetBrush(wxBrush(theme.element_rect.fill, wxBRUSHSTYLE_SOLID));
		dc.DrawRectangle(p.first, p.second, p.first + d.first, p.second + d.second);

	}

}