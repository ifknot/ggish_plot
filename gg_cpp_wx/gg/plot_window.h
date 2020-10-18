#pragma once

#include "wx/wx.h"

#include "plot_figure.h"

class plot_window : public wxFrame {

public:

	plot_window(gg::figure_t& fig, gg::theme_t& theme);

	~plot_window() = default;

	gg::plot_figure* pp;

	wxBoxSizer* sz;

private:

	gg::figure_t&	fig;
	gg::theme_t&	theme ;

};

