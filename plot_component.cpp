#include "plot_component.h"

#include <assert.h>

#include "conversions.h"

namespace R {

	plot_component::plot_component(rect_t box) :
		box(box)
	{}

	void plot_component::align_text_box(rect_t box, point_t p) {
		if (p.y == 0) { // topleft, top, topright

		}
	}

	void plot_component::draw_line(wxDC& gdc, R::point_t a, R::point_t b, R::element_line_t& element_line, R::figure_t fig) {
		assert((a.x >= 0) && (a.x <= 1));
		assert((a.y >= 0) && (a.y <= 1));
		assert((b.x >= 0) && (b.x <= 1));
		assert((b.y >= 0) && (b.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * as_dimension(fig.box).width;
		auto scale_y = fig.dpi * as_dimension(fig.box).height;
		auto x = fig.dpi * as_position(fig.box).x;
		auto y = fig.dpi * as_position(fig.box).y;

		gdc.SetPen(
			wxPen(
				element_line.colour,
				std::round(fig.pixels_per_pt * element_line.size),
				as_penstyle(element_line.linetype)
			)
		);
		gdc.DrawLine(
			std::round(x + (a.x * scale_x)),
			std::round(y + (a.y * scale_y)),
			std::round(x + (b.x * scale_x)),
			std::round(y + (b.y * scale_y))
		);
	}

	void plot_component::draw_rect(wxDC& gdc, R::point_t p, R::dimension_t d, R::element_rect_t& element_rect, R::figure_t fig) {
		assert((p.x >= 0) && (p.x <= 1));
		assert((p.y >= 0) && (p.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * as_dimension(fig.box).width;
		auto scale_y = fig.dpi * as_dimension(fig.box).height;
		auto x = fig.dpi * as_position(fig.box).x;
		auto y = fig.dpi * as_position(fig.box).y;

		gdc.SetPen(
			wxPen(
				element_rect.colour,
				std::round(fig.pixels_per_pt * element_rect.size),
				as_penstyle(element_rect.linetype)
			)
		);
		gdc.SetBrush(
			wxBrush(
				element_rect.fill,
				wxBRUSHSTYLE_SOLID
			)
		);
		gdc.DrawRectangle(
			std::round(x + (p.x * scale_x)),
			std::round(y + (p.y * scale_y)),
			std::round((p.x + d.width) * scale_x),
			std::round((p.y + d.height) * scale_y)
		);
	}

	void plot_component::draw_circle(wxDC& gdc, R::point_t o, double r, R::element_circle_t& element_circle, R::figure_t fig) {
		assert((o.x >= 0) && (o.x <= 1));
		assert((o.y >= 0) && (o.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * as_dimension(fig.box).width;
		auto scale_y = fig.dpi * as_dimension(fig.box).height;
		auto x = fig.dpi * as_position(fig.box).x;
		auto y = fig.dpi * as_position(fig.box).y;

		auto rr = r + r;
		gdc.SetPen(
			wxPen(
				element_circle.colour,
				std::round(fig.pixels_per_pt * element_circle.size),
				as_penstyle(element_circle.linetype)
			)
		);
		gdc.SetBrush(
			wxBrush(
				element_circle.fill,
				wxBRUSHSTYLE_SOLID
			)
		);
		gdc.DrawEllipse(
			std::round(x + ((o.x - r) * scale_x)),
			std::round(y + ((o.y - r) * scale_y)),
			std::round(rr * scale_x),
			std::round(rr * scale_y)
		);
	}

	// multipurpose private helper 
	rect_t plot_component::do_text(wxDC& gdc, R::point_t p, wxString text, R::element_text_t& element_text, R::figure_t fig, bool draw) {
		assert((p.x >= 0) && (p.x <= 1));
		assert((p.y >= 0) && (p.y <= 1));
		//calculate the width & height and x, y origin of the display bounding box
		auto scale_x = fig.dpi * as_inch({ fig.box.right - fig.box.left, fig.box.unit }).val;
		auto scale_y = fig.dpi * as_inch({ fig.box.bottom - fig.box.top, fig.box.unit }).val;
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
			text_width,
			text_height,
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

		double w{ rotated_image.GetWidth() / (double)fig.dpi };
		double h{ rotated_image.GetHeight() / (double)fig.dpi };

		mdc.SelectObject(wxNullBitmap);

		return rect_t{p.x, p.y, w, h , R::units::inch};

	}

}