#pragma once

#include "elements.h"

namespace R {

	static const double cm_per_inch = 2.54;
	static const double inch_per_cm = 0.393701;

	static enum unit_t { cm, inch, lines, pixels };

	using dpi_t = int;

	using unit = std::pair<double, unit_t>;

	struct figure_t {

		colour_mode_t colour_mode;
		unit_t		white_space_border;
		point		place;
		unit		minimum_width;
		unit		maximum_width;
		unit		minimum_height;
		unit		maximum_height;
		unit		column_width;
		std::vector<element_text>	valid_fonts;
		element_text text_within_figure;

	};

	struct legend_t {

		point			place;
		std::string		legend;
		std::vector<element_text>	valid_fonts;
		element_text	text_within_caption;

	};

	struct caption_t {

		point			place;
		std::string		figure_label;
		std::string		figure_title;
		std::vector<element_text>	valid_fonts;
		element_text	text_within_caption;

		legend_t legend;

	};



}

