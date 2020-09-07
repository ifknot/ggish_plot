#pragma once

#include <utility>
#include <vector>
#include <string>

#include "wx/wx.h"

namespace R {

	static const double cm_per_inch = 2.54;
	static const double inch_per_cm = 0.393701;

	static enum unit_t { cm, inch, lines, pixels };

	static enum colour_mode_t { RGB, grayscale};

	using dpi_t = int;

	using unit = std::pair<double, unit_t>;

	using point = std::pair<double, double>;

	struct element_line {

		wxColour	colour;
		double		size;
		wxPenStyle  linetype;
		wxPenCap	lineend;

	};

	struct element_rect {
	
		wxColour	fill;
		wxColour	colour;
		double		size;
		wxPenStyle  linetype;

	};


/* 
wxFont::wxFont	(	int 	pointSize,
wxFontFamily 	family,
wxFontStyle 	style,
wxFontWeight 	weight,
bool 	underline = false,
const wxString & 	faceName = wxEmptyString,
wxFontEncoding 	encoding = wxFONTENCODING_DEFAULT 
)	
*/
	struct element_text {
	
	

	};

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

	struct theme_t {

		element_line line;

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
	strip.text = element_text(size = rel(0.8)),
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

	strip.background = element_rect(fill = "grey80", colour = NA),
	strip.text.x = element_text(),
	strip.text.y = element_text(angle = -90),

	plot.background = element_rect(colour = "white"),
	plot.title = element_text(size = rel(1.2)),
	plot.margin = unit(c(1, 1, 0.5, 0.5), "lines"), complete = TRUE)
}

*/
