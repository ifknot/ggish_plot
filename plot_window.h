#pragma once

#include "wx/wx.h"

#include "plot_paper.h"

class plot_window : public wxFrame {

public:

	plot_window();

	~plot_window() = default;

	R::plot_paper* pp;

	wxButton* btn;

	wxBoxSizer* sz;

};

