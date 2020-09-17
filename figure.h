#pragma once

#include <vector>

#include "wx/wx.h"

#include "types.h"

namespace R {

	

	/**  
	 * PLOS_ONE defaults
	 * @url https://journals.plos.org/plosone/s/figures#loc-captions
	 */
	struct figure_t {

		figure_t(dpi_t dpi, rect_t bounding_box) : 
			dpi(dpi),
			box(bounding_box)
		{}

		dpi_t		dpi;	// pixels per inch of the paper - 12-pt font is 1/6 inch in height
		// the available drawing space bounding box
		// this will shrink if items are added e.g. margin, title, axes, legend
		// before finally displaying the plot itself
		rect_t		box;

		wxString	title{ "" };

		// calculate screen metrics
		double				pixels_per_cm = dpi / cm_per_inch;
		double				pixels_per_pt = dpi / pt_per_inch;
		double				font_scale = dpi / pt_per_inch;

		//PLOS_ONE defaults
		colour_mode_t colour_mode{ colour_mode_t::RGB };
		unit_t		white_space_border{ 2, units::pt };
		unit_t		column_width{ 5.2, units::inch };
		unit_t		minimum_width{ 2.63, units::inch };
		unit_t		maximum_width{ 7.5, units::inch };
		unit_t		minimum_height{ 2.63, units::inch };
		unit_t		maximum_height{ 8.75, units::inch };

		unit_t		minimum_pt{ 8, units::pt };
		unit_t		maximum_pt{ 12, units::pt };
		std::vector<wxString>	valid_fonts{ "Ariel", "Times", "Symbol" };

	};

	/**
	 * PLOS_ONE defaults
	 * @url https://journals.plos.org/plosone/s/figures#loc-captions
	 */
	struct caption_t {

		caption_t(dpi_t dpi, rect_t bounding_box) :
			dpi(dpi),
			box(bounding_box) {
		}

		dpi_t		dpi;	// pixels per inch of the paper - 12-pt font is 1/6 inch in height
		// the available drawing space bounding box
		// this will shrink if items are added e.g. margin, title, axes, legend
		// before finally displaying the plot itself
		rect_t		box;

		//PLOS_ONE defaults
		colour_mode_t colour_mode{ colour_mode_t::RGB };
		unit_t		white_space_border{ 2, units::pt };
		wxString		figure_label{ "" };
		wxString		figure_title{ "" };
		wxString		legend{ "" };					
														//	cm	   inches
		unit_t		column_width{ 13.2, units::cm };	// 13.2 	5.2 
		unit_t		minimum_width{ 6.68, units::cm };	// 6.68		2.63
		unit_t		maximum_width{ 19.05, units::cm };	// 19.05	7.5
		unit_t		minimum_height{ 13.2, units::cm };	// 13.2		5.2 
		unit_t		maximum_height{ 22.23, units::cm }; // 22.23	8.75

		unit_t		minimum_pt{ 8, units::pt };
		unit_t		maximum_pt{ 12, units::pt };
		std::vector<wxString>	valid_fonts{ "Ariel", "Times", "Symbol" };
		

	};



}

