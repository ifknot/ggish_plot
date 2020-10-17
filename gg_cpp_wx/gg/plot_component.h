#pragma once

#include "wx/wx.h"
#include "figure.h"
#include "theme.h"
#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

namespace gg {

	class plot_component {

	public:

		plot_component(rect_t box);

		virtual void render(wxDC& gdc) = 0;

	protected:

		rect_t box;			// the screen coordinates bounding box of the component

		static rect_t draw_text(wxDC& gdc, point_t p, wxString text, element_text_t& element_text, figure_t fig);

		static void draw_line(wxDC& gdc, point_t a, point_t b, element_line_t& element_line, figure_t fig);

		static void draw_rect(wxDC& gdc, point_t p, dimension_t d, element_rect_t& element_rect, figure_t fig);

		static void draw_circle(wxDC& gdc, point_t o, double r, element_circle_t& element_circle, figure_t fig);

	};

}