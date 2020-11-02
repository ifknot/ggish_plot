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

		plot_component(rect_t bounding_box, const figure_t& fig);

		virtual void render(wxDC& gdc) = 0;		

		inline rect_t bounds() const {
			return bounding_box;
		}

	protected:

		void shrink_bounds(const rect_t& margin);

		rect_t draw_text(wxDC& gdc, const point_t p, const wxString& s, const element_text_t& text);

		void draw_line(wxDC& gdc, const point_t a, const point_t b, const element_line_t& line);

		void draw_rect(wxDC& gdc, const point_t p, const dimension_t d, const element_rect_t& rect);

		void draw_circle(wxDC& gdc, const point_t o, const double r, const element_circle_t& circle);

	private:

		static inline double as_radians(double x) {
			return x * half_circle;
		}

		/**
		 * convert element line types to wxWidgets penstyle.
		 * 
		 * @param linetype
		 * @return 
		 */
		wxPenStyle as_penstyle(linetypes linetype);

		/**
		 * convert element text face to wxWidgets fontflag.
		 * 
		 * @param face
		 * @return 
		 */
		int as_fontflag(element_text_t::face_t face);

		rect_t bounding_box;

		const figure_t&  fig;

	};

}