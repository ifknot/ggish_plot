#include "app.h"

wxIMPLEMENT_APP(app);

app::app() {
}

bool app::OnInit() {

	if (!wxApp::OnInit()) {
		return false;
	}
	setlocale(LC_NUMERIC, "English");
	auto plot = new plot_window(fig, theme);
	f.reset(plot);
	f->Show();

	return true;
}
