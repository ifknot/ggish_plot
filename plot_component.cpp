#include "plot_component.h"

#include "conversions.h"

namespace R {

	void plot_component::draw_line(wxDC& dc, R::point_t a, R::point_t b, R::figure_t fig, R::element_line_t& element_line, R::theme_t& theme) {
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * theme.aspect_ratio.first * as_inch({ fig.box.right - fig.box.left, fig.box.unit }).val;
		auto scale_y = fig.dpi * theme.aspect_ratio.second * as_inch({ fig.box.bottom - fig.box.top, fig.box.unit }).val;
		auto x = fig.dpi * as_inch({ fig.box.left, fig.box.unit }).val;
		auto y = fig.dpi * as_inch({ fig.box.top, fig.box.unit }).val;

		dc.SetPen(
			wxPen(
				element_line.colour,
				std::round(fig.pixels_per_pt * theme.line.size),
				as_penstyle(element_line.linetype)
			)
		);
		dc.DrawLine(
			std::round(x + (a.x * scale_x)),
			std::round(y + (a.y * scale_y)),
			std::round(x + (b.x * scale_x)),
			std::round(y + (b.y * scale_y))
		);
	}

	void plot_component::draw_rect(wxDC& dc, R::point_t p, R::dimension_t d, R::figure_t fig, R::element_rect_t& element_rect, R::theme_t& theme) {
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * theme.aspect_ratio.first * as_inch({ fig.box.right - fig.box.left, fig.box.unit }).val;
		auto scale_y = fig.dpi * theme.aspect_ratio.second * as_inch({ fig.box.bottom - fig.box.top, fig.box.unit }).val;
		auto x = fig.dpi * as_inch({ fig.box.left, fig.box.unit }).val;
		auto y = fig.dpi * as_inch({ fig.box.top, fig.box.unit }).val;

		dc.SetPen(
			wxPen(
				element_rect.colour,
				std::round(fig.pixels_per_pt * theme.rect.size),
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
			std::round(x + (p.x * scale_x)),
			std::round(y + (p.y * scale_y)),
			std::round((p.x + d.width) * scale_x),
			std::round((p.y + d.height) * scale_y)
		);
	}

	void plot_component::draw_circle(wxDC& dc, R::point_t o, double r, R::figure_t fig, R::element_circle_t& element_circle, R::theme_t& theme) {
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * theme.aspect_ratio.first * as_inch({ fig.box.right - fig.box.left, fig.box.unit }).val;
		auto scale_y = fig.dpi * theme.aspect_ratio.second * as_inch({ fig.box.bottom - fig.box.top, fig.box.unit }).val;
		auto x = fig.dpi * as_inch({ fig.box.left, fig.box.unit }).val;
		auto y = fig.dpi * as_inch({ fig.box.top, fig.box.unit }).val;

		auto rr = r + r;
		dc.SetPen(
			wxPen(
				element_circle.colour,
				std::round(fig.pixels_per_pt * theme.circle.size),
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
			std::round(x + ((o.x - r) * scale_x)),
			std::round(y + ((o.y - r) * scale_y)),
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

	// multipurpose private helper 
	rect_t plot_component::do_text(wxDC& gdc, R::point_t p, wxString text, R::figure_t fig, R::element_text_t& element_text, R::theme_t& theme, bool draw) {
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * theme.aspect_ratio.first * as_inch({ fig.box.right - fig.box.left, fig.box.unit }).val;
		auto scale_y = fig.dpi * theme.aspect_ratio.second * as_inch({ fig.box.bottom - fig.box.top, fig.box.unit }).val;
		auto x = fig.dpi * as_inch({ fig.box.left, fig.box.unit }).val;
		auto y = fig.dpi * as_inch({ fig.box.top, fig.box.unit }).val;

		wxFontInfo info(std::round(element_text.size * fig.font_scale));
		info.FaceName(element_text.family);
		info.AllFlags(as_fontflag(element_text.face));
		info.AntiAliased(true);

		wxFont font(info);
		gdc.SetFont(font);
		wxCoord text_width, text_height;
		gdc.GetTextExtent(text, &text_width, &text_height);
		wxBitmap bitmap(text_width, text_height, wxBITMAP_SCREEN_DEPTH);
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
			text_width * theme.aspect_ratio.second,
			text_height * theme.aspect_ratio.first,
			wxIMAGE_QUALITY_HIGH
		);
		auto rotated_image = image.Rotate(
			as_radians(element_text.angle),
			{ 0, 0 }
		);
		// draw_text can be used just to get the bound box
		if (draw) {
			gdc.DrawBitmap(
				rotated_image,
				std::round(x + (p.x * scale_x) - (rotated_image.GetWidth() * element_text.hjust)),
				std::round(y + (p.y * scale_y) - (rotated_image.GetHeight() * element_text.vjust))
			);
		}

		mdc.SelectObject(wxNullBitmap);

		double w{ rotated_image.GetWidth() / scale_x };
		double h{ rotated_image.GetHeight() / scale_y };

		return rect_t{
			p.x,
			rotated_image.GetWidth() / (double)fig.dpi,
			p.y,
			rotated_image.GetHeight() / (double)fig.dpi,
			R::units::inch
		};
	}

}