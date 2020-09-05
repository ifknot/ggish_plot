#include "plot_paper.h"

namespace R {

	BEGIN_EVENT_TABLE(plot_paper, wxPanel)

		 // catch paint events
		EVT_PAINT(plot_paper::paintEvent)

		END_EVENT_TABLE()

	plot_paper::plot_paper(wxFrame* parent) : wxPanel(parent) {
	}

	void plot_paper::paintEvent(wxPaintEvent& evt) {
		wxPaintDC dc(this);
		render(dc);
	}

	void plot_paper::paintNow() {
		wxClientDC dc(this);
		render(dc);
	}

	void plot_paper::render(wxDC& dc) {

		// draw some text
		dc.DrawText(wxT("Testing"), 40, 60);

		// draw a circle
		dc.SetBrush(*wxGREEN_BRUSH); // green filling
		dc.SetPen(wxPen(wxColor(255, 0, 0), 5)); // 5-pixels-thick red outline
		dc.DrawCircle(wxPoint(200, 100), 25 /* radius */);

		// draw a rectangle
		dc.SetBrush(*wxBLUE_BRUSH); // blue filling
		dc.SetPen(wxPen(wxColor(255, 175, 175), 10)); // 10-pixels-thick pink outline
		dc.DrawRectangle(300, 100, 400, 200);

		// draw a line
		dc.SetPen(wxPen(wxColor(0, 0, 0), 3)); // black line, 3 pixels thick
		dc.DrawLine(300, 100, 700, 300); // draw line across the rectangle

	}

}