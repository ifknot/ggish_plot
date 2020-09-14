#pragma once

#include "metrics.h"

namespace R {

	struct strip_t {

	};

	struct tick_t : public element_line_t {

		double	x{ 0 };
		double	y{ 0 };
		unit	length{ 0.1, cm };	// length of tick marks (unit)

	};

	struct axis_ticks_t : public tick_t {	
		
		tick_t top{ colour, size, linetype, lineend, arrow, x, y, length };
		tick_t bottom{ colour, size, linetype, lineend, arrow, x, y, length };
		tick_t left{ colour, size, linetype, lineend, arrow, x, y, length };
		tick_t right{ colour, size, linetype, lineend, arrow, x, y, length };

	};

	struct axis_label_t: public element_text_t {

		element_text_t top{ family, face, colour, size, hjust, vjust, angle, lineheight, linewidth, margin, debug, x };
		element_text_t bottom{ family, face, colour, size, hjust, vjust, angle, lineheight, linewidth, margin, debug, x };
		element_text_t left{ family, face, colour, size, hjust, vjust, angle, lineheight, linewidth, margin, debug, x };
		element_text_t right{ family, face, colour, size, hjust, vjust, angle, lineheight, linewidth, margin, debug, x };

	};	

	struct axis_line_t : public element_line_t {

		element_line_t top{ colour, size, linetype, lineend, arrow };
		element_line_t bottom{ colour, size, linetype, lineend, arrow };
		element_line_t left{ colour, size, linetype, lineend, arrow };
		element_line_t right{ colour, size, linetype, lineend, arrow };

	};

	struct legend_t {

		enum position_t { none, left, right, bottom, top };
		enum direction_t { horizontal, vertical };

		point_t			centre{ 0, 0 };

		element_rect_t	background;		// background of legend (element_rect(); inherits from rect)
		margin_t		margin;			// the margin around each legend (margin())
		unit			spacing;		// the spacing between legends (unit).legend.spacing.x& legend.spacing.y inherit from legend.spacing or can be specified separately
		unit			spacing_x{ spacing }; 
		unit			spacing_y{ spacing };
		element_rect_t	key;			// background underneath legend keys (element_rect(); inherits from rect)
		unit			key_size;		// size of legend keys (unit); key background height & width inherit from legend.key.size or can be specified separately 
		unit			key_size_width{ key_size };
		unit			key_size_height{ key_size };
		element_text_t	text;			// legend item labels (element_text(); inherits from text)
		int				text_align;		// alignment of legend labels (number from 0 (left)to 1 (right))
		element_text_t	title;			// style title of legend (element_text(); inherits from title)
		int				title_align;	// alignment of legend title (number from 0 (left)to 1 (right))
		position_t		legend_position;// the position of legends ("none", "left", "right", "bottom", "top")
		direction_t		direction;		// layout of items in legends ("horizontal" or "vertical")
		point_t			justification{ centre };	// anchor point for positioning legend inside plot ("center" or two - element numeric vector) or the justification according to the plot area when positioned outside the plot
		direction_t		box;			// arrangement of multiple legends ("horizontal" or "vertical")
		position_t		box_just;		// justification of each legend within the overall bounding box, when there are multiple legends ("top", "bottom", "left", or "right")
		margin_t		box_margin;		// margins around the full legend area, as specified using margin()
		element_rect_t	box_background;	// background of legend area (element_rect(); inherits from rect)
		unit			box_spacing;	//The spacing between the plotting area and the legend box (unit)

	};

	struct grid_t : public element_line_t {

		element_line_t major{ colour, size, linetype, lineend, arrow };
		element_line_t minor{ colour, size, linetype, lineend, arrow };
		element_line_t major_x{ major };		// vertical
		element_line_t minor_x{ minor };		// vertical
		element_line_t major_y{ major };		// horizontal
		element_line_t minor_y{ minor };		// horizontal

	};

	struct panel_t {

		element_rect_t background;			// background of plotting area, drawn underneath plot (element_rect(); inherits from rect)
		element_rect_t border;				// border around plotting area, drawn on top of plot so that it covers tick marks and grid lines.This should be used with fill = NA (element_rect(); inherits from rect)
		unit_t spacing;						// spacing between facet panels (unit). panel.spacing.x & panel.spacing.y inherit from panel.spacing or can be specified separately.
		unit_t spacing_x{ spacing };		// or specify x spacing
		unit_t spacing_y{ spacing };		// and y spacing separately

	};

	struct plot_t {

		enum position_t { topleft, top, topright, left, right, bottomleft, bottom, bottomright};
		enum caption_position_t { panel, plot };

		element_rect_t		background;		// background of the entire plot
		element_text_t		title;			// plot title (text appearance)
		std::vector<position_t>	title_position{ left, left, right };	// alignment of the plot title/subtitle and caption.
		caption_position_t  caption_position{ panel };	// applies to both the title and the subtitle. A value of "panel" (the default) means that titles and/or caption are aligned to the plot panels. A value of "plot" means that titles and/or caption are aligned to the entire plot (minus any space for margins and plot tag)
		element_text_t		subtitle;		// plot subtitle (text appearance) - left aligned default
		element_text_t		caption;		// caption below the plot (text appearance) - right aligned default
		element_text_t		tag;			// upper - left label to identify a plot (text appearance)
		position_t			tag_position;	// position of the tag 
		margin_t			margin;			// margin around entire plot (unit with the sizes of the top, right, bottom, and left margins)
		
	};

	struct strip {

/*
		
strip.background, strip.background.x, strip.background.y
background of facet labels (element_rect(); inherits from rect). Horizontal facet background (strip.background.x) & vertical facet background (strip.background.y) inherit from strip.background or can be specified separately

strip.placement
placement of strip with respect to axes, either "inside" or "outside". Only important when axes and strips are on the same side of the plot.

strip.text, strip.text.x, strip.text.y
facet labels (element_text(); inherits from text). Horizontal facet labels (strip.text.x) & vertical facet labels (strip.text.y) inherit from strip.text or can be specified separately

strip.switch.pad.grid
space between strips and axes when strips are switched (unit)

strip.switch.pad.wrap
space between strips and axes when strips are switched (unit)
		
*/

	};
	
	struct theme_t {

		dpi_t				dpi{ 72 };				// dpi/ppi of the paper
		ratio_t				aspect_ratio{ 1, 1 };	// aspect ratio of the paper
		unit				width{ 1, inch };				// width of the paper
		unit				height{ 1, inch };			// height of the paper 
		double				pixels_per_cm = dpi / cm_per_inch; 
		double				pixels_per_pt = dpi / pt_per_inch;
		double				font_scale = dpi / pt_per_inch;
		wxFontFamily		wx_font_family{ wxFONTFAMILY_DEFAULT };

		double				base_size{ 11 };		// base font size, given in pts
		wxString			base_family{ "Ariel" };	// base font family name e.g. "Ariel"
		double				base_line_size = base_size / 22;	// base size for line elements
		double				base_rect_size = base_size / 22;	// base size for rect elements


		element_line_t		element_line{ wxColor(0, 0, 0, wxALPHA_OPAQUE), 0.5, 1, 0 }; // all line elements
		element_rect_t		element_rect{ wxColor(255, 255, 255, wxALPHA_OPAQUE),  wxColor(0, 0, 0, wxALPHA_OPAQUE), 0.5, 1 }; // all rectangular elements
		element_text_t		element_text{ base_family, element_text_t::plain, wxColor(0, 0, 0, wxALPHA_OPAQUE), base_size, 0.5, 0.5, 0, 0.9 }; // all text elements
		element_circle_t	element_circle{ wxColor(255, 255, 255, wxALPHA_OPAQUE),  wxColor(0, 0, 0, wxALPHA_OPAQUE), 0.5, 1 }; // all circular elements

		axis_label_t		title;			// specify style all axes' title labels or individually for each axis by top, bottom, left and right
		axis_label_t		text;			// specify style all axes' tick labels or individually for each axis by top, bottom, left and right
		axis_ticks_t		ticks;			// specify style all axes ticks or individually for each axis by top, bottom, left and right
		axis_line_t			line;			// specify lines along all axes or individually for each axis by top, bottom, left and right

		legend_t			legend;
		panel_t				panel;
		plot_t				plot;
		strip_t				strip;

		// complete // set this to TRUE if this is a complete theme, such as the one returned by theme_grey().Complete themes behave differently when added to a ggplot object.Also, when setting complete = TRUE all elements will be set to inherit from blank elements.

		// validate // TRUE to run validate_element(), FALSE to bypass checks.
		
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


