#pragma once

#include  "elements.h"

namespace R {
	
	/**
	 * @brief exercise fine control over the non-data elements of a plot
	 * + helps make a plot aesthetically pleasing or match an existing style guide
	 * + separation of control into data and non-data parts avoids large numbers of function arguments
	 */
	struct theme_t {

		/**
		 * @note all themes have a base_size that controls the base font size
		 * the base font size is the size that the axis titles use, the plot title is usually bigger (1.2x)
		 * the tick and strip labels are smaller (0.8x)
		 * 
		 * @param ppi			pixels per inch resolution 
		 * @param base_size		base font size
		 * @param base_family	base font family name @note look out for cross platform issues here
		 */
		theme_t(dpi_t ppi = 72, double base_size = 11, wxString base_family = "Times") :
			dpi(ppi),
			base_size(base_size),		
			base_family(base_family) 
		{}

		dpi_t				dpi;							// dpi/ppi of the digital paper or physical printer paper
		ratio_t				aspect_ratio{ 1, 1 };			// aspect ratio of the paper
		unit_t				width{ 1, units::inch };		// width of the paper
		unit_t				height{ 1, units::inch };		// height of the paper 
		double				pixels_per_cm = dpi / cm_per_inch; 
		double				pixels_per_pt = dpi / pt_per_inch;
		double				font_scale = dpi / pt_per_inch;

		double				base_size;							// base font size, given in pts
		wxString			base_family;						// base font family name e.g. "Ariel"
		double				base_line_size = base_size / 22;	// base size for line elements
		double				base_rect_size = base_size / 22;	// base size for rect elements

		// styles lines parameterized by colour, size and line type 
		element_line_t		element_line{ black, 0.5, linetypes::solid, endstyles::butt }; 
		// styles rectangles, mostly used for backgrounds, parameterized bill fill and border colours, size and line type
		element_rect_t		element_rect{ white, black, 0.5, linetypes::solid }; 
		// styles general text elements on plot font size is the base font 
		element_text_t		element_text{ base_family, element_text_t::face_t::plain, black, base_size, 0.5, 0, 0.0, 0.9 }; 
		// styles circles 
		element_circle_t	element_circle{ white,  black, 0.5, linetypes::solid }; 

		element_rect_t		plot_background{ white,  white, 0.5, linetypes::solid };
		element_text_t		plot_title{ base_family, element_text_t::face_t::plain, black, base_size * 1.2, 0.5, 0.5, 0.0, 0.9 };
		margin_t			plot_margin{ 1, 1, 0.5, 0.5, units::lines };

	};

}


/*

theme_gray

function (base_size = 12, base_family = "")
{
  theme(
	line = element_line(colour = "black", size = 0.5, linetype = 1, lineend = "butt"),
	rect = element_rect(fill = "white", colour = "black", size = 0.5, linetype = 1),
	text = element_text(family = base_family, face = "plain", colour = "black", size = base_size, hjust = 0.5, vjust = 0.5, angle = 0, lineheight = 0.9),

	axis.text = element_text(size = rel(0.8), colour = "grey50"),
	axis.line = element_blank(),
	axis.text.x = element_text(vjust = 1),
	axis.text.y = element_text(hjust = 1),
	axis.ticks = element_line(colour = "grey50"),
	axis.title.x = element_text(),
	axis.title.y = element_text(angle = 90),
	axis.ticks.length = unit(0.15, "cm"),
	axis.ticks.margin = unit(0.1, "cm"),

	legend.background = element_rect(colour = NA),
	legend.margin = unit(0.2, "cm"),
	legend.key = element_rect(fill = "grey95", colour = "white"),
	legend.key.size = unit(1.2, "lines"),
	legend.key.height = NULL,
	legend.key.width = NULL,
	legend.text = element_text(size = rel(0.8)),
	legend.text.align = NULL,
	legend.title = element_text(size = rel(0.8), face = "bold", hjust = 0),
	legend.title.align = NULL,
	legend.position = "right",
	legend.direction = NULL,
	legend.justification = "center",
	legend.box = NULL,

	panel.background = element_rect(fill = "grey90", colour = NA),
	panel.border = element_blank(),
	panel.grid.major = element_line(colour = "white"),
	panel.grid.minor = element_line(colour = "grey95", size = 0.25),
	panel.margin = unit(0.25, "lines"),
	panel.margin.x = NULL,
	panel.margin.y = NULL,

	strip.text = element_text(size = rel(0.8)),
	strip.background = element_rect(fill = "grey80", colour = NA),
	strip.text.x = element_text(),
	strip.text.y = element_text(angle = -90),

	plot.background = element_rect(colour = "white"),
	plot.title = element_text(size = rel(1.2)),
	plot.margin = unit(c(1, 1, 0.5, 0.5), "lines"), complete = TRUE)
}

*/


