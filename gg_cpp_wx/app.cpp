#include "app.h"

#include "rpp\read_csv.h"

wxIMPLEMENT_APP(app);

app::app() {
}

bool app::OnInit() {

	if (!wxApp::OnInit()) {
		return false;
	}
	setlocale(LC_NUMERIC, "English");

	fig.title = "A Title";
	fig.subtitle = "subtitle";
	fig.caption = "caption";

	auto win = new plot_window(fig, theme);

	auto mpg = R::read_csv("mpg.csv");

	f.reset(win);
	f->Show();

	return true;
}
