#pragma once

#include "plot_component.h"
#include "figure.h"
#include "theme.h"

namespace R {

	class plot_label : public plot_component {

	public:

		plot_label(wxString& text, point_t& position, element_text_t& element_text, figure_t& fig);

		void render(wxDC& gdc) override final;

	private:

		wxString& text;
		point_t& position;
		element_text_t& element_text;
		figure_t& fig;
		
	};

}

