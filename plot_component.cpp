#include "plot_component.h"

#include <math.h>

#include "conversions.h"

namespace R {

	void plot_component::draw_text(wxDC& gdc, R::point_t p, wxString text, R::element_text_t& element_text, R::theme_t& theme) {
		auto scale_x = theme.dpi * theme.aspect_ratio.first * as_inch(theme.width).first;
		auto scale_y = theme.dpi * theme.aspect_ratio.second * as_inch(theme.height).first;
		
		wxFontInfo info(std::round(element_text.size * theme.font_scale));
		info.FaceName(element_text.family);
		info.AllFlags(as_fontflag(element_text.face));
		info.AntiAliased(true);
		
		wxFont font(info);
		gdc.SetFont(font);
		wxCoord w, h;
		gdc.GetTextExtent(text, &w, &h);
		wxBitmap bitmap(w, h, wxBITMAP_SCREEN_DEPTH);
		bitmap.UseAlpha();
		
		wxMemoryDC mdc;
		mdc.SelectObject(bitmap);
		mdc.SetBackground(transparent);
		mdc.Clear();
		mdc.SetFont(font);
		mdc.SetTextBackground(element_text.background);
		mdc.SetTextForeground(element_text.colour);
		mdc.DrawText(text, 0, 0);
	
		auto image = bitmap.ConvertToImage();
		image.SetAlpha(0);
		image.Rescale(
			w * theme.aspect_ratio.second,
			h * theme.aspect_ratio.first,
			wxIMAGE_QUALITY_HIGH
		);
		auto rotated_image = image.Rotate(
			as_radians(element_text.angle),
			{ 0, 0 }
		);
		gdc.DrawBitmap(
			rotated_image,
			std::round(p.first * scale_x) - (rotated_image.GetWidth() * element_text.hjust),
			std::round(p.second * scale_y) - (rotated_image.GetHeight() * element_text.vjust)
		);

		mdc.SelectObject(wxNullBitmap);
	}

	void plot_component::draw_line(wxDC& dc, R::point_t a, R::point_t b, R::element_line_t& element_line, R::theme_t& theme) {
		auto scale_x = theme.dpi * theme.aspect_ratio.first * as_inch(theme.width).first;
		auto scale_y = theme.dpi * theme.aspect_ratio.second * as_inch(theme.height).first;
		dc.SetPen(
			wxPen(
				element_line.colour,
				std::round(theme.pixels_per_pt * theme.element_line.size),
				as_penstyle(element_line.linetype)
			)
		);
		dc.DrawLine(
			std::round(a.first * scale_x),
			std::round(a.second * scale_y),
			std::round(b.first * scale_x),
			std::round(b.second * scale_y)
		);
	}

	void plot_component::draw_rect(wxDC& dc, R::point_t p, R::dimension_t d, R::element_rect_t& element_rect, R::theme_t& theme) {
		auto scale_x = theme.dpi * theme.aspect_ratio.first * as_inch(theme.width).first;
		auto scale_y = theme.dpi * theme.aspect_ratio.second * as_inch(theme.height).first;
		dc.SetPen(
			wxPen(
				element_rect.colour,
				std::round(theme.pixels_per_pt * theme.element_rect.size),
				as_penstyle(element_rect.linetype)
			)
		);
		dc.SetBrush(
			wxBrush(
				element_rect.fill,
				wxBRUSHSTYLE_SOLID
			)
		);
		dc.DrawRectangle(
			std::round(p.first * scale_x),
			std::round(p.second * scale_y),
			std::round((p.first + d.first) * scale_x),
			std::round((p.second + d.second) * scale_y)
		);
	}

	void plot_component::draw_circle(wxDC& dc, R::point_t o, double r, R::element_circle_t& element_circle, R::theme_t& theme) {
		auto scale_x = theme.dpi * theme.aspect_ratio.first * as_inch(theme.width).first;
		auto scale_y = theme.dpi * theme.aspect_ratio.second * as_inch(theme.height).first;
		auto rr = r + r;
		dc.SetPen(
			wxPen(
				element_circle.colour,
				std::round(theme.pixels_per_pt * theme.element_circle.size),
				as_penstyle(element_circle.linetype)
			)
		);
		dc.SetBrush(
			wxBrush(
				element_circle.fill,
				wxBRUSHSTYLE_SOLID
			)
		);
		dc.DrawEllipse(
			std::round((o.first - r) * scale_x),
			std::round((o.second - r) * scale_y),
			std::round(rr * scale_x),
			std::round(rr * scale_y)
		);
	}

	wxPenStyle plot_component::as_penstyle(linetypes linetype) {
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

	int plot_component::as_fontflag(element_text_t::face_t face) {
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