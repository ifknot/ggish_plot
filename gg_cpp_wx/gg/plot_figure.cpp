#include "plot_figure.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

#include "conversions.h"
#include "plot_background.h"
#include "plot_label.h"

namespace gg {

	BEGIN_EVENT_TABLE(plot_figure, wxPanel)

		// catch paint events
		EVT_PAINT(plot_figure::paintEvent)

		END_EVENT_TABLE()

		plot_figure::plot_figure(wxFrame* parent, R::data_frame& data, aesthetics_t aes, figure_t& fig, theme_t& theme) :
		wxPanel(parent, wxID_ANY,wxDefaultPosition, 
			{	// width & height
				(int)std::round(fig.dpi * gg::as_inch({ fig.box.right + fig.box.left, fig.box.unit }).val),
				(int)std::round(fig.dpi * gg::as_inch({ fig.box.bottom + fig.box.top, fig.box.unit }).val)
			}),
		data(data),
		aes(aes),
		fig(fig),
		theme(theme),
		plot(fig.box)
	{
		init_layout();
	}

	void plot_figure::paintEvent(wxPaintEvent& evt) {
		wxPaintDC pdc(this);

#if wxUSE_GRAPHICS_CONTEXT
		wxGCDC gdc(pdc);
		wxDC& dc = use_gcdc ? (wxDC&)gdc : (wxDC&)pdc;
		plot.render(dc);
#else
		wxDC& dc = pdc;
		plot.render(dc);
#endif

	}

	void plot_figure::paintNow() {

	}

	void plot_figure::init_layout() {
		auto background = new plot_background(fig.box, theme.plot.background, theme.plot.margin, fig);
		plot.add(background);
	}

}