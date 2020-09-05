#include "app.h"

wxIMPLEMENT_APP(app);

app::app() {
}

bool app::OnInit() {

	f.reset(new plot_window);
	f->Show();

	return true;
}
