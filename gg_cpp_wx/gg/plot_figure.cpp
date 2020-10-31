#include "plot_figure.h"

#if wxUSE_GRAPHICS_CONTEXT
	#include <wx/dcgraph.h>
#endif

#include "conversions.h"
#include "plot_background.h"
#include "plot_subject.h"

namespace gg {

	BEGIN_EVENT_TABLE(plot_figure, wxPanel)

		// catch paint events
		EVT_PAINT(plot_figure::paintEvent)

		END_EVENT_TABLE()

		plot_figure::plot_figure(wxFrame* parent, const R::data_frame& data, const aesthetics_t aes, const figure_t& fig, const theme_t& theme) :
		wxPanel(parent, wxID_ANY,wxDefaultPosition, 
			{	// width & height
				(int)std::round(fig.dpi * gg::as_inch({ fig.bounding_box.right + fig.bounding_box.left, fig.bounding_box.unit }).val),
				(int)std::round(fig.dpi * gg::as_inch({ fig.bounding_box.bottom + fig.bounding_box.top, fig.bounding_box.unit }).val)
			}),
		data(data),
		aes(aes),
		fig(fig),
		theme(theme),
		plot(fig.bounding_box, fig)
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
		auto background = new plot_background(fig.bounding_box.shrink(theme.plot.margin), theme.plot.background, fig);
		layer_t base_layer{ "geom_point", "default", &data, &aes, "default", false, "default" };
		// TODO: give rect the shrink method 
		// TODO: remove margins fomr plot comp ctrs
		auto subject = new plot_subject(background->bounds().shrink(theme.panel.margin), theme.panel.background, fig, base_layer);
		background->add(subject);
		plot.add(background);
	}

}