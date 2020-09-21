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

		plot_component(rect_t box);

		virtual void render(wxDC& gdc) = 0;

	protected:

		rect_t box;

		static inline rect_t text_box(wxDC& gdc, R::point_t p, wxString text, R::element_text_t& element_text, R::figure_t fig) {
			return do_text(gdc, p, text, element_text, fig, false);
		}

		static inline rect_t draw_text(wxDC& gdc, R::point_t p, wxString text, R::element_text_t& element_text, R::figure_t fig) {
			return do_text(gdc, p, text, element_text, fig, true);
		}

		static void align_text_box(rect_t box, point_t p);

		static void draw_line(wxDC& gdc, R::point_t a, R::point_t b, R::element_line_t& element_line, R::figure_t fig);

		static void draw_rect(wxDC& gdc, R::point_t p, R::dimension_t d, R::element_rect_t& element_rect, R::figure_t fig);

		static void draw_circle(wxDC& gdc, R::point_t o, double r, R::element_circle_t& element_circle, R::figure_t fig);

	private:

		static rect_t do_text(wxDC& gdc, R::point_t p, wxString text, R::element_text_t& element_text, R::figure_t fig, bool draw);

	};

}