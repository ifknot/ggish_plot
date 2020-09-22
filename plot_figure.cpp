#include "plot_figure.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

#include "conversions.h"
#include "plot_pane.h"
#include "plot_label.h"

namespace R {

	BEGIN_EVENT_TABLE(plot_figure, wxPanel)

		// catch paint events
		EVT_PAINT(plot_figure::paintEvent)

		END_EVENT_TABLE()

		plot_figure::plot_figure(wxFrame* parent, data_frame& data, figure_t& fig, theme_t& theme) :
		wxPanel(parent),
		plot_composite(fig.box),
		data(data),
		fig(fig),
		theme(theme)
	{
		init_paper();
	}

	void plot_figure::paintEvent(wxPaintEvent& evt) {
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

	void plot_figure::paintNow() {

	}

	void plot_figure::init_paper() {
		
		auto plot = new plot_pane(fig.position, theme.plot.background, fig);
		if (!fig.title.empty()) {
			plot->add(new plot_label(fig.title, theme.plot.title.position, theme.plot.title, fig));
		}
		if (!fig.subtitle.empty()) {
			plot->add(new plot_label(fig.subtitle, theme.plot.subtitle.position, theme.plot.subtitle, fig));
		}
		if (!fig.caption.empty()) {
			plot->add(new plot_label(fig.caption, theme.plot.caption.position, theme.plot.caption, fig));
		}
		if (!fig.tag.empty()) {
			plot->add(new plot_label(fig.tag, theme.plot.tag.position, theme.plot.tag, fig));
		}
		auto p = topleft;
		auto panel = new plot_pane(p, theme.panel.background, fig);
		plot->add(panel);
		add(plot);
	}

}