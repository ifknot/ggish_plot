#include "plot_component.h"

#include <assert.h>

#include "conversions.h"

namespace gg {

	plot_component::plot_component(rect_t box) :
		box(box)
	{}

	void plot_component::shrink_rect(rect_t& a, rect_t& b) {
		a.left += as_inch({ b.left, b.unit }).val;
		a.right -= as_inch({ b.right, b.unit }).val;
		a.top += as_inch({ b.top, b.unit }).val;
		a.bottom -= as_inch({ b.bottom, b.unit }).val;
	}

	rect_t plot_component::draw_text(wxDC& gdc, point_t p, wxString text, element_text_t& element_text, rect_t box, const figure_t& fig) {
		assert((p.x >= 0) && (p.x <= 1));
		assert((p.y >= 0) && (p.y <= 1));
		// calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_inch({ box.right - box.left, box.unit }).val;
		auto h = fig.dpi * as_inch({ box.bottom - box.top, box.unit }).val;
		auto x = fig.dpi * as_inch({ box.left, box.unit }).val;
		auto y = fig.dpi * as_inch({ box.top, box.unit }).val;
		
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
		mdc.SetBackground(wxColour(transparent.r, transparent.g, transparent.b, transparent.a));
		mdc.Clear();
		mdc.SetFont(font);
		mdc.SetTextBackground(wxColour(element_text.background.r, element_text.background.g, element_text.background.b, element_text.background.a));
		mdc.SetTextForeground(wxColour(element_text.colour.r, element_text.colour.g, element_text.colour.b, element_text.colour.a));
		mdc.DrawText(text, 0, 0);

		auto text_image = bitmap.ConvertToImage();
		text_image.SetAlpha(0);
		text_image.Rescale(
			text_width,
			text_height,
			wxIMAGE_QUALITY_HIGH
		);
		auto rotated_image = text_image.Rotate(
			as_radians(element_text.angle),
			{ 0, 0 }
		);

		auto tw{ (double)rotated_image.GetWidth() }; 
		auto th{ (double)rotated_image.GetHeight() }; 
		auto tx = std::round(x + (p.x * w) - (tw * element_text.hjust));
		auto ty = std::round(y + (p.y * h) - (th * element_text.vjust));
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

	void plot_component::draw_line(wxDC& gdc, point_t a, point_t b, element_line_t& element_line, rect_t box, const figure_t& fig) {
		assert((a.x >= 0) && (a.x <= 1));
		assert((a.y >= 0) && (a.y <= 1));
		assert((b.x >= 0) && (b.x <= 1));
		assert((b.y >= 0) && (b.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_dimension(box).width;
		auto h = fig.dpi * as_dimension(box).height;
		auto x = fig.dpi * as_position(box).x;
		auto y = fig.dpi * as_position(box).y;

		gdc.SetPen(
			wxPen(
				wxColour(element_line.colour.r, element_line.colour.g, element_line.colour.b, element_line.colour.a),
				std::round(fig.pixels_per_pt * element_line.size),
				as_penstyle(element_line.linetype)
			)
		);
		gdc.DrawLine(
			std::round(x + (a.x * w)),
			std::round(y + (a.y * h)),
			std::round(x + (b.x * w)),
			std::round(y + (b.y * h))
		);
	}

	void plot_component::draw_rect(wxDC& gdc, point_t p, dimension_t d, element_rect_t& pane, rect_t box, const figure_t& fig) {
		assert((p.x >= 0) && (p.x <= 1));
		assert((p.y >= 0) && (p.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_dimension(box).width;
		auto h = fig.dpi * as_dimension(box).height;
		auto x = fig.dpi * as_position(box).x;
		auto y = fig.dpi * as_position(box).y;

		gdc.SetPen(
			wxPen(
				wxColour(pane.colour.r, pane.colour.g, pane.colour.b, pane.colour.a),
				std::round(fig.pixels_per_pt * pane.size),
				as_penstyle(pane.linetype)
			)
		);
		gdc.SetBrush(
			wxBrush(
				wxColour(pane.fill.r, pane.fill.g, pane.fill.b, pane.fill.a),
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

	void plot_component::draw_circle(wxDC& gdc, point_t o, double r, element_circle_t& element_circle, rect_t box, const figure_t& fig) {
		assert((o.x >= 0) && (o.x <= 1));
		assert((o.y >= 0) && (o.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto w = fig.dpi * as_dimension(box).width;
		auto h = fig.dpi * as_dimension(box).height;
		auto x = fig.dpi * as_position(box).x;
		auto y = fig.dpi * as_position(box).y;

		auto rr = r + r;
		gdc.SetPen(
			wxPen(
				wxColour(element_circle.colour.r, element_circle.colour.g, element_circle.colour.b, element_circle.colour.a),
				std::round(fig.pixels_per_pt * element_circle.size),
				as_penstyle(element_circle.linetype)
			)
		);
		gdc.SetBrush(
			wxBrush(
				wxColour(element_circle.fill.r, element_circle.fill.g, element_circle.fill.b, element_circle.fill.a),
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