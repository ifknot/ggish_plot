#include "plot_component.h"

#include <assert.h>

#include "conversions.h"

namespace gg {

	plot_component::plot_component(rect_t bounding_box, const figure_t& fig) :
		bounding_box(bounding_box),
		fig(fig)
	{}

	void plot_component::shrink_bounds(const rect_t& margin) {
		bounding_box.left += as_inch({ margin.left, margin.unit }).val;
		bounding_box.right -= as_inch({ margin.right, margin.unit }).val;
		bounding_box.top += as_inch({ margin.top, margin.unit }).val;
		bounding_box.bottom -= as_inch({ margin.bottom, margin.unit }).val;
	}

	rect_t plot_component::draw_text(wxDC& gdc, const point_t p, const wxString& s, const element_text_t& text) {
		assert((p.x >= 0) && (p.x <= 1));
		assert((p.y >= 0) && (p.y <= 1));
		// calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_inch({ bounding_box.right - bounding_box.left, bounding_box.unit }).val;
		auto h = fig.dpi * as_inch({ bounding_box.bottom - bounding_box.top, bounding_box.unit }).val;
		auto x = fig.dpi * as_inch({ bounding_box.left, bounding_box.unit }).val;
		auto y = fig.dpi * as_inch({ bounding_box.top, bounding_box.unit }).val;
		
		wxFontInfo info(std::round(text.size * fig.font_scale));
		info.FaceName(text.family);
		info.AllFlags(as_fontflag(text.face));
		info.AntiAliased(true);
	
		wxFont font(info);
		gdc.SetFont(font);
		wxCoord text_width, text_height;
		gdc.GetTextExtent(s, &text_width, &text_height);
		wxBitmap bitmap(text_width, text_height, wxBITMAP_SCREEN_DEPTH);
		bitmap.UseAlpha();

		wxMemoryDC mdc;
		mdc.SelectObject(bitmap);
		mdc.SetBackground(wxColour(transparent.r, transparent.g, transparent.b, transparent.a));
		mdc.Clear();
		mdc.SetFont(font);
		mdc.SetTextBackground(wxColour(text.background.r, text.background.g, text.background.b, text.background.a));
		mdc.SetTextForeground(wxColour(text.colour.r, text.colour.g, text.colour.b, text.colour.a));
		mdc.DrawText(s, 0, 0);

		auto text_image = bitmap.ConvertToImage();
		text_image.SetAlpha(0);
		text_image.Rescale(
			text_width,
			text_height,
			wxIMAGE_QUALITY_HIGH
		);
		auto rotated_image = text_image.Rotate(
			as_radians(text.angle),
			{ 0, 0 }
		);

		auto tw{ (double)rotated_image.GetWidth() }; 
		auto th{ (double)rotated_image.GetHeight() }; 
		auto tx = std::round(x + (p.x * w) - (tw * text.hjust));
		auto ty = std::round(y + (p.y * h) - (th * text.vjust));
		// adjust if text image strays out of bounds
		if (ty + th >= y + h) {
			ty -= (ty + th) - (y + h);
		}
		if (tx + tw >= x + w) {
			tx -= (tx + tw) - (x + w);
		}
		if (tx < x) {
			tx = x;
		}
		gdc.DrawBitmap(rotated_image, tx, ty);
		
		mdc.SelectObject(wxNullBitmap);

		return rect_t{ p.x, tw / (double)fig.dpi, p.y, th / (double)fig.dpi , units::inch };
	}

	void plot_component::draw_line(wxDC& gdc, const point_t a, const point_t b, const element_line_t& line) {
		assert((a.x >= 0) && (a.x <= 1));
		assert((a.y >= 0) && (a.y <= 1));
		assert((b.x >= 0) && (b.x <= 1));
		assert((b.y >= 0) && (b.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_dimension(bounding_box).width;
		auto h = fig.dpi * as_dimension(bounding_box).height;
		auto x = fig.dpi * as_position(bounding_box).x;
		auto y = fig.dpi * as_position(bounding_box).y;

		gdc.SetPen(
			wxPen(
				wxColour(line.colour.r, line.colour.g, line.colour.b, line.colour.a),
				std::round(fig.pixels_per_pt * line.size),
				as_penstyle(line.linetype)
			)
		);
		gdc.DrawLine(
			std::round(x + (a.x * w)),
			std::round(y + (a.y * h)),
			std::round(x + (b.x * w)),
			std::round(y + (b.y * h))
		);
	}

	void plot_component::draw_rect(wxDC& gdc, const point_t p, const dimension_t d, const element_rect_t& rect) {
		assert((p.x >= 0) && (p.x <= 1));
		assert((p.y >= 0) && (p.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_dimension(bounding_box).width;
		auto h = fig.dpi * as_dimension(bounding_box).height;
		auto x = fig.dpi * as_position(bounding_box).x;
		auto y = fig.dpi * as_position(bounding_box).y;

		gdc.SetPen(
			wxPen(
				wxColour(rect.colour.r, rect.colour.g, rect.colour.b, rect.colour.a),
				std::round(fig.pixels_per_pt * rect.size),
				as_penstyle(rect.linetype)
			)
		);
		gdc.SetBrush(
			wxBrush(
				wxColour(rect.fill.r, rect.fill.g, rect.fill.b, rect.fill.a),
				wxBRUSHSTYLE_SOLID
			)
		);
		gdc.DrawRectangle(
			std::round(x + (p.x * w)),
			std::round(y + (p.y * h)),
			std::round((p.x + d.width) * w),
			std::round((p.y + d.height) * h)
		);
	}

	void plot_component::draw_circle(wxDC& gdc, const point_t o, const double r, const element_circle_t& circle) {
		assert((o.x >= 0) && (o.x <= 1));
		assert((o.y >= 0) && (o.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_dimension(bounding_box).width;
		auto h = fig.dpi * as_dimension(bounding_box).height;
		auto x = fig.dpi * as_position(bounding_box).x;
		auto y = fig.dpi * as_position(bounding_box).y;

		auto rr = r + r;
		gdc.SetPen(
			wxPen(
				wxColour(circle.colour.r, circle.colour.g, circle.colour.b, circle.colour.a),
				std::round(fig.pixels_per_pt * circle.size),
				as_penstyle(circle.linetype)
			)
		);
		gdc.SetBrush(
			wxBrush(
				wxColour(circle.fill.r, circle.fill.g, circle.fill.b, circle.fill.a),
				wxBRUSHSTYLE_SOLID
			)
		);
		gdc.DrawEllipse(
			std::round(x + ((o.x - r) * w)),
			std::round(y + ((o.y - r) * h)),
			std::round(rr * w),
			std::round(rr * h)
		);
	}

}