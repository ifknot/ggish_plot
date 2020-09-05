#include "main_window.h"

plot_window::plot_window() : wxFrame(nullptr, wxID_ANY, "test_wx") {

	pp = new R::plot_paper(this);
	sz = new wxBoxSizer(wxHORIZONTAL);
	sz->Add(pp, 1, wxEXPAND);
	SetSizer(sz);
	SetAutoLayout(true);

}
