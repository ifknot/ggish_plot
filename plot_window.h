#pragma once

#include "wx/wx.h"

#include "plot_figure.h"

class plot_window : public wxFrame {

public:

	plot_window();

	~plot_window() = default;

	R::plot_figure* pp;

	wxButton* btn;

	wxBoxSizer* sz;

};

