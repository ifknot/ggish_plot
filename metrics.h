#pragma once

#include "elements.h"

namespace R {

	using dpi_t = int;

	using unit = std::pair<double, unit_t>;

	struct figure_t {

		colour_mode_t colour_mode;
		unit_t		white_space_border;
		point_t		place;
		unit		column_width;
		unit		minimum_width;
		unit		maximum_width;
		unit		minimum_height;
		unit		maximum_height;
		std::vector<element_text_t>	valid_fonts;
		element_text_t element_text;	
		element_line_t element_line;
		element_rect_t element_rect;
		element_circle_t element_circle;

	};

	struct caption_legend_t {

		point_t			place;
		std::string		legend;
		std::vector<element_text_t>	valid_fonts;
		element_text_t	element_text;

	};

	struct caption_t {

		point_t			place;
		std::string		figure_label;
		std::string		figure_title;
		std::vector<element_text_t>	valid_fonts;
		element_text_t	element_text;

		caption_legend_t legend;

	};



}

