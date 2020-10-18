#include "plot_window.h"
#include "conversions.h"

#include "..\rpp\read_csv.h"

plot_window::plot_window(gg::figure_t& fig, gg::theme_t& theme) :
	wxFrame(nullptr, wxID_ANY, "test_wx", { (int)fig.position.x, (int)fig.position.y }, { 900, 900 }),
	fig(fig),
	theme(theme)
{

	fig.title = "Title";
	fig.subtitle = "subtitle";
	fig.caption = "caption";

	auto mpg = R::read_csv("mpg.csv");

	pp = new gg::plot_figure(this, mpg, {"displ", "hwy"}, fig, theme);
	sz = new wxBoxSizer(wxHORIZONTAL);
	sz->Add(pp, 1, wxEXPAND);
	SetSizer(sz);
	SetAutoLayout(true);

}
