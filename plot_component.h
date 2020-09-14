#pragma once

#include "wx/wx.h"
#include "theme.h"

namespace R {

	class plot_component {

	public:


		virtual void render(wxDC& dc) = 0;

	protected:

		static void draw_text(wxDC& gdc, R::point_t p, wxString s, R::element_text_t& element_text, R::theme_t& theme);

		static void draw_line(wxDC& gdc,R::point_t a, R::point_t b, R::element_line_t& element_line, R::theme_t& theme);

		static void draw_rect(wxDC& gdc, R::point_t p, R::dimension_t d, R::element_rect_t& element_rect, R::theme_t& theme);

		static void draw_circle(wxDC& gdc, R::point_t o, double r, R::element_circle_t& element_circle, R::theme_t& theme);

		// TODO: define an enum linetype
		static wxPenStyle as_penstyle(int linetype);

		static int as_fontflag(element_text_t::face_t face);

	};

}