#pragma once

#include "wx/wx.h"

#include <memory>

#include "gg/plot_window.h"

class app : public wxApp {

public:

	app();

	~app() = default;

	virtual bool OnInit() override final;

private:

	std::unique_ptr<plot_window> f;

	gg::figure_t fig{ 150, { 0, 5.2, 0, 5.2, gg::units::inch } };
	gg::theme_t theme { fig.maximum_pt.val, fig.valid_fonts[1] };
	gg::plot_figure* pp;

};

