#pragma once

#include "wx/wx.h"
#include "figure.h"
#include "theme.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

namespace R {

	class plot_component {

	public:

		virtual void render(wxDC& dc) = 0;

	protected:

		static rect_t draw_text(wxDC& gdc, R::point_t p, wxString s, R::figure_t fig, R::element_text_t& element_text, R::theme_t& theme);

		static void draw_line(wxDC& gdc, R::point_t a, R::point_t b, R::figure_t fig, R::element_line_t& element_line, R::theme_t& theme);

		static void draw_rect(wxDC& gdc, R::point_t p, R::dimension_t d, R::figure_t fig, R::element_rect_t& element_rect, R::theme_t& theme);

		static void draw_circle(wxDC& gdc, R::point_t o, double r, R::figure_t fig, R::element_circle_t& element_circle, R::theme_t& theme);

		static wxPenStyle as_penstyle(linetypes linetype);

		static int as_fontflag(element_text_t::face_t face);

	};

}