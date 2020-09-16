#include "plot_paper.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

namespace R {

	BEGIN_EVENT_TABLE(plot_paper, wxPanel)

		// catch paint events
		EVT_PAINT(plot_paper::paintEvent)

		END_EVENT_TABLE()

		plot_paper::plot_paper(wxFrame* parent) : 
			wxPanel(parent)
			//,theme({fig.dpi / 2, 12, fig.valid_fonts[2]}) 
	{
		theme.width = fig.column_width;
		theme.height = fig.column_width;
	}

	plot_paper::plot_paper(wxFrame* parent, unit_t width, unit_t height) {
		theme.width = width;
		theme.height = height;
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

		draw_rect(gdc, { 0, 0 }, { 1, 1 }, theme.plot_background, theme);
		draw_rect(gdc, { 0, 0 }, { 1, 1 }, theme.element_rect, theme);
		draw_text(gdc, { 1, 1 }, wxT("a text element"), theme.element_text, theme);
		draw_line(gdc, { 0, 0 }, { 1, 1 }, theme.element_line, theme);
		draw_circle(gdc, { 0.5, 0.5 }, 0.3, theme.element_circle, theme);

	}

}