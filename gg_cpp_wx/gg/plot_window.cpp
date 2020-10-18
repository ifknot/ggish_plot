#include "plot_window.h"
#include "conversions.h"

#include "..\rpp\read_csv.h"

plot_window::plot_window(gg::figure_t& fig, gg::theme_t& theme) :
	wxFrame(nullptr, wxID_ANY, "test_wx"),
	fig(fig),
	theme(theme)
{
	auto mpg = R::read_csv("mpg.csv");

	pp = new gg::plot_figure(this, mpg, {"displ", "hwy"}, fig, theme);
	Fit();
	Centre();
}
