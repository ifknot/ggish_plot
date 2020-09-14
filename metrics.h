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
		unit		white_space_border{ 2, pt };
		point_t		place{ 0, 0 };
		dimension_t dimensions{ 1, 1 };
		unit		column_width{ 13.2, cm };
		unit		minimum_width{ 6.68, cm };
		unit		maximum_width{ 19.05, cm };
		unit		minimum_height{ 22.23, cm };
		unit		maximum_height{ 22.23, cm };
		std::vector<wxString>	valid_fonts{ "Ariel", "Times", "Symbol" };
		unit		minimum_pt{ 8, pt };
		unit		maximum_pt{ 12, pt };

	};

	/**
	 * PLOS_ONE defaults
	 * @url https://journals.plos.org/plosone/s/figures#loc-captions
	 */
	struct caption_t {

		dpi_t dpi{ 300 };
		colour_mode_t colour_mode{ RGB };
		unit		white_space_border{ 2, pt };
		point_t		place{ 0, 0 };
		wxString		figure_label{ "" };
		wxString		figure_title{ "" };
		wxString		legend{ "" };
		unit		column_width{ 13.2, cm };
		unit		minimum_width{ 6.68, cm };
		unit		maximum_width{ 19.05, cm };
		unit		minimum_height{ 22.23, cm };
		unit		maximum_height{ 22.23, cm };
		std::vector<wxString>	valid_fonts{ "Ariel", "Times", "Symbol" };
		unit		minimum_pt{ 8, pt };
		unit		maximum_pt{ 12, pt };

	};



}

