#include "plot_paper.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

namespace R {

	BEGIN_EVENT_TABLE(plot_paper, wxPanel)

		// catch paint events
		EVT_PAINT(plot_paper::paintEvent)

		END_EVENT_TABLE()

	plot_paper::plot_paper(wxFrame* parent) : wxPanel(parent) {}

	plot_paper::plot_paper(wxFrame* parent, unit width, unit height) {
		theme.width = width;
		theme.height = height;
	}

	void plot_paper::paintEvent(wxPaintEvent& evt) {

		wxPaintDC pdc(this);

#if wxUSE_GRAPHICS_CONTEXT
		wxGCDC gdc(pdc);
		wxDC& dc = use_gcdc ? (wxDC&)gdc : (wxDC&)pdc;
		render(pdc, gdc);
#else
		wxDC& dc = pdc;
		render(dc);
#endif

	}

	void plot_paper::paintNow() {
		wxPaintDC pdc(this);

#if wxUSE_GRAPHICS_CONTEXT
		wxGCDC gdc(pdc);
		wxDC& dc = use_gcdc ? (wxDC&)gdc : (wxDC&)pdc;
		render(pdc, gdc);
#else
		wxDC& dc = pdc;
		render(dc);
#endif
	}

	void plot_paper::render(wxDC& dc, wxGCDC& gdc) {

		draw_rect(gdc, { 0, 0 }, { 1, 1 }, theme.element_rect, theme);
		draw_text(dc, { 1, 1 }, wxT("testing"), theme.element_text, theme);
		draw_line(gdc, { 0, 0 }, { 1, 1 }, theme.element_line, theme);
		draw_circle(gdc, { 0.5, 0.5 }, 0.3, theme.element_circle, theme);

		//int dpi = 300;

		//create an image of correct size and use that dc 
			//convert to greyscale if needed

		// draw a circle
		//dc.SetBrush(*wxGREEN_BRUSH); // green filling
		//dc.SetPen(wxPen(wxColor(255, 0, 0), 5)); // 5-pixels-thick red outline
		//dc.DrawCircle(wxPoint(200, 100), 25 /* radius */);

		// draw a rectangle
		//dc.SetBrush(*wxBLUE_BRUSH); // blue filling
		/*
		dc.SetPen(wxPen(wxColor(0, 0, 0), 1)); 
		dc.DrawRectangle(50, 50, dpi, dpi);
		dc.DrawRectangle(50, 50 + dpi, dpi, dpi);
		dc.DrawRectangle(50 + dpi, 50 + dpi, dpi, dpi);
		dc.DrawRectangle(50 + dpi, 50, dpi, dpi);
		// draw a line
		dc.SetPen(wxPen(wxColor(0, 0, 0), 3)); // black line, 3 pixels thick
		dc.DrawLine(300, 100, 700, 300); 
		*/
		// draw some text
		/*
		wxFontInfo info(text.base_size);
		info.FaceName(text.base_family);
		info.AllFlags(text.face);
		wxCoord w, h;
		dc.SetFont(wxFont(info));
		dc.GetMultiLineTextExtent(wxT("Rotated Testing"), &w, &h);
		dc.SetTextForeground(text.colour);
		dc.SetTextBackground(text.background_colour);

		dc.DrawRotatedText(wxT("Rotated Testing"), 50 - h, 50 + dpi + dpi, text.angle);
		*/

	}

}