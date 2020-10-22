#pragma once

#include "plot_component.h"
#include "figure.h"
#include "theme.h"

namespace gg {

	class plot_label : public plot_component {

	public:

		plot_label(rect_t bounding_box, const wxString& s, const point_t position, const element_text_t& text, const figure_t& fig);

		void render(wxDC& gdc) override final;

	private:

		const wxString s;
		const point_t& position;
		const element_text_t& text;
		
	};

}

