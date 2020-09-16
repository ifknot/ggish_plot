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
			wxPanel(parent),
			theme({ fig.column_width, fig.column_width, fig.dpi / 4, 12, fig.valid_fonts[2]})
	{}

	plot_paper::plot_paper(wxFrame* parent, unit_t width, unit_t height, dpi_t dpi, double font_size, wxString font_name) :
		wxPanel(parent),
		theme({ width, height, dpi, font_size, font_name }) 
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

		for (const auto& c : components) {
			c->render(gdc);
		}

		
		draw_rect(gdc, { 0, 0 }, { 1, 1 }, theme.plot_background, theme);
		draw_rect(gdc, { 0, 0 }, { 1, 1 }, theme.element_rect, theme);
		draw_text(gdc, { 1, 1 }, wxT("a text element"), theme.element_text, theme);
		draw_line(gdc, { 0, 0 }, { 1, 1 }, theme.element_line, theme);
		draw_circle(gdc, { 0.5, 0.5 }, 0.3, theme.element_circle, theme);
		

	}

}