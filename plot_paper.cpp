#include "plot_paper.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

#include "conversions.h"
#include "plot_title.h"

namespace R {

	BEGIN_EVENT_TABLE(plot_paper, wxPanel)

		// catch paint events
		EVT_PAINT(plot_paper::paintEvent)

	END_EVENT_TABLE()

	plot_paper::plot_paper(wxFrame* parent, figure_t& fig, theme_t& theme) :
		wxPanel(parent),
		fig(fig),
		theme(theme)
	{
		init_plot();
	}

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
		for (const auto& c : components) {
			c->render(gdc);
		}

		draw_rect(gdc, { 0, 0 }, { 1, 1 }, fig, theme.element_rect, theme);
		draw_text(gdc, { 1, 1 }, wxT("a text element"), fig, theme.element_text, theme);
		draw_line(gdc, { 0, 0 }, { 1, 1 }, fig, theme.element_line, theme);
		draw_circle(gdc, { 0.5, 0.5 }, 0.3, fig, theme.element_circle, theme);
	}

	void R::plot_paper::init_plot() {
		if (fig.title != "") {
			add(new plot_title(fig.title, fig, theme));
		}
	}

}