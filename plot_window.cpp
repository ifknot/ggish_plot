#include "plot_window.h"

plot_window::plot_window() : wxFrame(nullptr, wxID_ANY, "test_wx") {

	pp = new R::plot_paper(this);
	pp->text.base_family = "Ariel";
	pp->text.face = wxFONTFLAG_ITALIC | wxFONTFLAG_BOLD;
	pp->text.colour = wxColour("RED");
	pp->text.background_colour = wxColour("YELLOW");
	pp->text.base_size = 14;
	pp->text.h_just = 0;
	pp->text.v_just = 0;
	pp->text.angle = 90;
	pp->text.line_height = 0;
	pp->text.margin = 0;
	pp->text.debug = true;
	sz = new wxBoxSizer(wxHORIZONTAL);
	sz->Add(pp, 1, wxEXPAND);
	SetSizer(sz);
	SetAutoLayout(true);

}
