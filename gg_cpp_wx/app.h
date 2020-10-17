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

	gg::plot_figure* pp;

};

