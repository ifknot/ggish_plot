#include "plot_window.h"
#include "plot_title.h"

plot_window::plot_window() : wxFrame(nullptr, wxID_ANY, "test_wx", { 100, 100 }, { 500, 500 }) {

	R::figure_t	fig({ 72, { 0, 5.2, 0, 5.2, R::units::inch } });
	R::theme_t theme({ fig.maximum_pt.first, fig.valid_fonts[1] });

	fig.title = "hello world";

	pp = new R::plot_paper(this, fig, theme);
	sz = new wxBoxSizer(wxHORIZONTAL);
	sz->Add(pp, 1, wxEXPAND);
	SetSizer(sz);
	SetAutoLayout(true);

}
