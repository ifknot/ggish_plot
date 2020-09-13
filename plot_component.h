#pragma once

#include "wx/wx.h"
#include "theme.h"

namespace R {

	class plot_component {

	public:


		virtual void render(wxDC& dc) = 0;

	protected:

		//static void element_text(wxDC& dc, R::point_t p, R::element_text_t& text);

		//static void element_line(wxDC& dc,R::point_t a, R::point_t b, R::element_line_t& line);

		static void element_rect(wxDC& dc, R::point_t p, R::dimension_t d, R::theme_t& theme);

		//static void element_circle(wxDC& dc, R::point_t o, double r, R::R::element_circle_t& circle);

	};

}