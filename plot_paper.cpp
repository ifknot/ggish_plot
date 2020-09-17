#include "plot_paper.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

#include "conversions.h"

namespace R {

	BEGIN_EVENT_TABLE(plot_paper, wxPanel)

		// catch paint events
		EVT_PAINT(plot_paper::paintEvent)

	END_EVENT_TABLE()

	plot_paper::plot_paper(wxFrame* parent, figure_t& fig, theme_t& theme) :
		wxPanel(parent),
		fig(fig),
		theme(theme)
	{}

	void plot_paper::paintEvent(wxPaintEvent& evt) {

		wxPaintDC pdc(this);

#if wxUSE_GRAPHICS_CONTEXT
		wxGCDC gdc(pdc);
		wxDC& dc = use_gcdc ? (wxDC&)gdc : (wxDC&)pdc;
		render(dc);
#else
		wxDC& dc = pdc;
		render(dc);
#endif

	}

	void plot_paper::paintNow() {
		wxClientDC dc(this);
		render(dc);
	}

	void plot_paper::render(wxDC& gdc) {

		draw_rect(gdc, { 0, 0 }, { 1, 1 }, fig, theme.plot_background, theme);
		R::shrink_by_margin(fig.box, theme.plot_margin);
		if (!fig.title.empty()) {
			auto box = draw_text(gdc, theme.plot_title_position, fig.title, fig, theme.plot_title, theme);
			if (theme.plot_title_position.second == 0) { // topleft, top, topright
				fig.box.top += box.bottom;
			}
			else if (theme.plot_title_position.second == 1) {} // bottomleft, bottom, bottomright
			else if (theme.plot_title_position.second == 0.5) {} // left, right
			else {} // floating coordinate
		}
		draw_rect(gdc, { 0, 0 }, { 1, 1 }, fig, theme.panel_background, theme);
		R::shrink_by_margin(fig.box, theme.panel_margin);
		draw_line(gdc, { 0, 0.5 }, { 1, 0.5 }, fig, theme.panel_grid_major_x, theme);
		draw_line(gdc, { 0, 0.6 }, { 1, 0.6 }, fig, theme.panel_grid_minor_x, theme);
		draw_circle(gdc, { 0.5, 0.505 }, 0.008, fig, theme.element_circle, theme);

	}

}