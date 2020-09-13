#include "plot_component.h"
#include <math.h>

namespace R {
	void plot_component::element_text(wxDC& dc, R::point_t p, wxString s, R::theme_t& theme) {
		wxFontInfo info(theme.element_text.size);
		info.FaceName(theme.element_text.family); 
		int face;
		switch (theme.element_text.face) { // plain, italic, bold, bold_italic};
		case element_text_t::plain:
			face = wxFONTFLAG_DEFAULT;
			break;
		case element_text_t::italic:
			face = wxFONTFLAG_ITALIC;
			break;
		case element_text_t::bold:
			face = wxFONTFLAG_BOLD;
			break;
		case element_text_t::bold_italic:
			face = wxFONTFLAG_BOLD | wxFONTFLAG_ITALIC;
			break;
		default:
			face = wxFONTFLAG_DEFAULT;
		}
		info.AllFlags(face);
		dc.SetFont(wxFont(info));
		wxCoord w, h;
		dc.GetMultiLineTextExtent(s, &w, &h);
		dc.SetTextForeground(theme.element_text.colour);
		dc.DrawRotatedText(s, p.first, p.second - h, theme.element_text.angle);
	}

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
		int size = std::round(theme.pixels_per_mm * theme.element_line.size);
		dc.SetPen(wxPen(theme.element_rect.colour, size));
		dc.SetBrush(wxBrush(theme.element_rect.fill, wxBRUSHSTYLE_SOLID));
		dc.DrawRectangle(p.first, p.second, p.first + d.first, p.second + d.second);

	}

}