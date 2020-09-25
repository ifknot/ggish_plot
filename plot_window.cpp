#include "plot_window.h"
#include "conversions.h"

plot_window::plot_window() : 
	wxFrame(nullptr, wxID_ANY, "test_wx", { 100, 100 }, { 900, 900 }),
	fig({ 150, { 0, 5.2, 0, 5.2, R::units::inch } }),
	theme({ fig.maximum_pt.val, fig.valid_fonts[1] })
{

	fig.title = "Title";
	fig.subtitle = "subtitle";
	fig.caption = "caption";

	auto mpg = R::read_csv("mpg.csv");

	pp = new R::plot_figure(this, mpg, {"displ", "hwy"}, fig, theme);
	sz = new wxBoxSizer(wxHORIZONTAL);
	sz->Add(pp, 1, wxEXPAND);
	SetSizer(sz);
	SetAutoLayout(true);

}
