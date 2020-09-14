#pragma once

#include "elements.h"

namespace R {

	

	/**  
	 * PLOS_ONE defaults
	 * @url https://journals.plos.org/plosone/s/figures#loc-captions
	 */
	struct figure_t {

		dpi_t dpi{ 300 };	// pixels per inch of the paper - 12-pt font is 1/6 inch in height
		colour_mode_t colour_mode{ RGB };
		unit_t		white_space_border{ 2, pt };
		point_t		place{ 0, 0 };
		dimension_t dimensions{ 1, 1 };
		unit_t		column_width{ 5.2, inch };
		unit_t		minimum_width{ 2.63, inch };
		unit_t		maximum_width{ 7.5, inch };
		unit_t		minimum_height{ 2.63, inch };
		unit_t		maximum_height{ 8.75, inch };
		std::vector<wxString>	valid_fonts{ "Ariel", "Times", "Symbol" };
		unit_t		minimum_pt{ 8, pt };
		unit_t		maximum_pt{ 12, pt };

	};

	/**
	 * PLOS_ONE defaults
	 * @url https://journals.plos.org/plosone/s/figures#loc-captions
	 */
	struct caption_t {

		dpi_t dpi{ 300 };
		colour_mode_t colour_mode{ RGB };
		unit_t		white_space_border{ 2, pt };
		point_t		place{ 0, 0 };
		wxString		figure_label{ "" };
		wxString		figure_title{ "" };
		wxString		legend{ "" };
		unit_t		column_width{ 13.2, cm };
		unit_t		minimum_width{ 6.68, cm };
		unit_t		maximum_width{ 19.05, cm };
		unit_t		minimum_height{ 22.23, cm };
		unit_t		maximum_height{ 22.23, cm };
		std::vector<wxString>	valid_fonts{ "Ariel", "Times", "Symbol" };
		unit_t		minimum_pt{ 8, pt };
		unit_t		maximum_pt{ 12, pt };

	};



}

