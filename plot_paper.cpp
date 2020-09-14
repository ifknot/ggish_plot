#include "plot_paper.h"

namespace R {

	BEGIN_EVENT_TABLE(plot_paper, wxPanel)

		// catch paint events
		EVT_PAINT(plot_paper::paintEvent)

		END_EVENT_TABLE()

		plot_paper::plot_paper(wxFrame* parent) : wxPanel(parent) {}

	void plot_paper::paintEvent(wxPaintEvent& evt) {
		wxPaintDC dc(this);
		render(dc);
	}

	void plot_paper::paintNow() {
		wxClientDC dc(this);
		render(dc);
	}

	void plot_paper::render(wxDC& dc) {

		draw_rect(dc, { 0, 0 }, { 50, 50 }, theme.element_rect, theme);
		draw_text(dc, { 50, 50 }, wxT("testing"), theme.element_text, theme);
		draw_line(dc, { 0, 0 }, { 50, 50 }, theme.element_line, theme);
		draw_circle(dc, { 25, 25 }, 20, theme.element_circle, theme);

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