#include "app.h"

wxIMPLEMENT_APP(app);

app::app() {
}

bool app::OnInit() {

	if (!wxApp::OnInit()) {
		return false;
	}
	setlocale(LC_NUMERIC, "English");
	f.reset(new plot_window);
	f->Show();

	return true;
}
