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
		plot_composite(fig.box),
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

		draw_rect(gdc, { 0, 0 }, { 1, 1 }, theme.plot.background, fig);
		R::shrink_by_margin(fig.box, theme.plot.margin);

		if (!fig.title.empty()) {
			auto box = draw_text(gdc, theme.plot.title.position, fig.title, theme.plot.title, fig);
			if (theme.plot.title.position.y == 0) { // topleft, top, topright
				fig.box.top += box.bottom;
			}
			else if (theme.plot.title.position.y == 1) {} // bottomleft, bottom, bottomright
			else if (theme.plot.title.position.y == 0.5) {} // left, right
			else {} // floating coordinate
		}
		if (!fig.subtitle.empty()) {
			auto box = draw_text(gdc, theme.plot.title.position, fig.subtitle, theme.plot.subtitle, fig);
			if (theme.plot.subtitle.position.y == 0) { // topleft, top, topright
				fig.box.top += box.bottom;
			}
			else if (theme.plot.subtitle.position.y == 1) {} // bottomleft, bottom, bottomright
			else if (theme.plot.subtitle.position.y == 0.5) {} // left, right
			else {} // floating coordinate
		}
		draw_rect(gdc, { 0, 0 }, { 1, 1 }, theme.panel.background, fig);
		R::shrink_by_margin(fig.box, theme.panel.margin);
		draw_line(gdc, { 0, 0.5 }, { 1, 0.5 }, theme.panel.grid.major.x, fig);
		draw_line(gdc, { 0, 0.6 }, { 1, 0.6 }, theme.panel.grid.minor.x, fig);
		draw_circle(gdc, { 0.5, 0.505 }, 0.008, theme.circle, fig);

	}

}

/*


		if (!fig.caption.empty()) {
			if (theme.plot.caption.position.y == 0) { // topleft, top, topright
				auto box = draw_text(gdc, theme.plot.caption.position, fig.caption, fig, theme.plot.title, theme);
				fig.box.top += box.bottom;
			}
			else if (theme.plot.caption.position.y == 1) { // bottomleft, bottom, bottomright
				auto box = get_text_bounding_box(gdc, theme.plot.caption.position, fig.caption, fig, theme.plot.caption, theme);
				fig.box.bottom -= box.bottom;
				box = draw_text(gdc, theme.plot.caption.position, fig.caption, fig, theme.plot.caption, theme);
			}
			else if (theme.plot.caption.position.y == 0.5) {} // left, right
			else {} // floating coordinate
		}
		if (!fig.tag.empty()) {
			auto box = draw_text(gdc, theme.plot.title.position, fig.tag, fig, theme.plot.title, theme);
			if (theme.plot.title.position.y == 0) { // topleft, top, topright
				fig.box.top += box.bottom;
			}
			else if (theme.plot.title.position.y == 1) { // bottomleft, bottom, bottomright
				fig.box.bottom -= box.bottom;
			}
			else if (theme.plot.title.position.y == 0.5) {} // left, right
			else {} // floating coordinate
		}

*/