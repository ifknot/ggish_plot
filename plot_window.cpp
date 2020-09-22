#include "plot_window.h"
#include "conversions.h"

plot_window::plot_window() : wxFrame(nullptr, wxID_ANY, "test_wx", { 100, 100 }, { 900, 900 }) {

	R::figure_t	fig({ 150, { 0, 5.2, 0, 5.2, R::units::inch } });
	R::theme_t theme({ fig.maximum_pt.val, fig.valid_fonts[1] });

	fig.title = "Title";
	fig.subtitle = "subtitle";
	fig.caption = "caption";

	R::data_frame d;

	pp = new R::plot_figure(this, d, fig, theme);
	sz = new wxBoxSizer(wxHORIZONTAL);
	sz->Add(pp, 1, wxEXPAND);
	SetSizer(sz);
	SetAutoLayout(true);

}
