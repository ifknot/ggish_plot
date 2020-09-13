#pragma once

#include "metrics.h"

namespace R {

	struct strip_t {

	};

	struct tick_t : public element_line_t {

		double	x{ 0 };
		double	y{ 0 };
		unit	length{ 0, cm };	// length of tick marks (unit)

	};

	struct axis_ticks_t : public tick_t {	
		
		tick_t top;
		tick_t bottom;
		tick_t left;
		tick_t right;

	};

	struct axis_label_t: public element_text_t {

		element_text_t top;
		element_text_t bottom;
		element_text_t left;
		element_text_t right;

	};	

	struct axis_line_t : public element_line_t {

		element_line_t top;
		element_line_t bottom;
		element_line_t left;
		element_line_t right;

	};

	struct legend_t {



	};

	struct panel_t {



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

	struct 
	
	struct theme_t {

		dpi_t				dpi;			// pixels per inch of the paper - 12-pt font is 1/6 inch in height
		ratio_t				aspect_ratio;	// aspect ratio of the paper
		wxFontFamily		wx_font_family{ wxFONTFAMILY_DEFAULT };

		double				base_size;		// base font size, given in pts
		wxString			base_family;	// base font family name e.g. "Ariel"
		double				base_line_size = base_size / 22;	// base size for line elements
		double				base_rect_size = base_size / 22;	// base size for rect elements
		
		element_text_t		theme_text;		// all text elements
		element_line_t		them_line;		// all line elements
		element_rect_t		theme_rect;		// all rectangular elements
		element_circle_t	theme_circle;	// all circular elements

		axis_label_t		title;			// specify style all axes' title labels or individually for each axis by top, bottom, left and right
		axis_label_t		text;			// specify style all axes' tick labels or individually for each axis by top, bottom, left and right
		axis_ticks_t		ticks;			// specify style all axes ticks or individually for each axis by top, bottom, left and right
		axis_line_t			line;			// specify lines along all axes or individually for each axis by top, bottom, left and right

		panel_t				panel;
		
		

	};

}

/*

legend.background
background of legend (element_rect(); inherits from rect)

legend.margin
the margin around each legend (margin())

legend.spacing, legend.spacing.x, legend.spacing.y
the spacing between legends (unit). legend.spacing.x & legend.spacing.y inherit from legend.spacing or can be specified separately

legend.key
background underneath legend keys (element_rect(); inherits from rect)

legend.key.size, legend.key.height, legend.key.width
size of legend keys (unit); key background height & width inherit from legend.key.size or can be specified separately

legend.text
legend item labels (element_text(); inherits from text)

legend.text.align
alignment of legend labels (number from 0 (left) to 1 (right))

legend.title
title of legend (element_text(); inherits from title)

legend.title.align
alignment of legend title (number from 0 (left) to 1 (right))

legend.position
the position of legends ("none", "left", "right", "bottom", "top", or two-element numeric vector)

legend.direction
layout of items in legends ("horizontal" or "vertical")

legend.justification
anchor point for positioning legend inside plot ("center" or two-element numeric vector) or the justification according to the plot area when positioned outside the plot

legend.box
arrangement of multiple legends ("horizontal" or "vertical")

legend.box.just
justification of each legend within the overall bounding box, when there are multiple legends ("top", "bottom", "left", or "right")

legend.box.margin
margins around the full legend area, as specified using margin()

legend.box.background
background of legend area (element_rect(); inherits from rect)

legend.box.spacing
The spacing between the plotting area and the legend box (unit)

*/

/*

line,
  rect,
  text,
  title,
  aspect.ratio,
  axis.title,
  axis.title.x,
  axis.title.x.top,
  axis.title.x.bottom,
  axis.title.y,
  axis.title.y.left,
  axis.title.y.right,
  axis.text,
  axis.text.x,
  axis.text.x.top,
  axis.text.x.bottom,
  axis.text.y,
  axis.text.y.left,
  axis.text.y.right,
  
  axis.line,
  axis.line.x,
  axis.line.x.top,
  axis.line.x.bottom,
  axis.line.y,
  axis.line.y.left,
  axis.line.y.right,
  legend.background,
  legend.margin,
  legend.spacing,
  legend.spacing.x,
  legend.spacing.y,
  legend.key,
  legend.key.size,
  legend.key.height,
  legend.key.width,
  legend.text,
  legend.text.align,
  legend.title,
  legend.title.align,
  legend.position,
  legend.direction,
  legend.justification,
  legend.box,
  legend.box.just,
  legend.box.margin,
  legend.box.background,
  legend.box.spacing,
  panel.background,
  panel.border,
  panel.spacing,
  panel.spacing.x,
  panel.spacing.y,
  panel.grid,
  panel.grid.major,
  panel.grid.minor,
  panel.grid.major.x,
  panel.grid.major.y,
  panel.grid.minor.x,
  panel.grid.minor.y,
  panel.ontop,
  plot.background,
  plot.title,
  plot.title.position,
  plot.subtitle,
  plot.caption,
  plot.caption.position,
  plot.tag,
  plot.tag.position,
  plot.margin,
  strip.background,
  strip.background.x,
  strip.background.y,
  strip.placement,
  strip.text,
  strip.text.x,
  strip.text.y,
  strip.switch.pad.grid,
  strip.switch.pad.wrap,
  
  complete = FALSE,
  validate = TRUE

*/

/*

Arguments
line
all line elements (element_line())

rect
all rectangular elements (element_rect())

text
all text elements (element_text())

title
all title elements: plot, axes, legends (element_text(); inherits from text)

aspect.ratio
aspect ratio of the panel

axis.title, axis.title.x, axis.title.y, axis.title.x.top, axis.title.x.bottom, axis.title.y.left, axis.title.y.right
labels of axes (element_text()). Specify all axes' labels (axis.title), labels by plane (using axis.title.x or axis.title.y), or individually for each axis (using axis.title.x.bottom, axis.title.x.top, axis.title.y.left, axis.title.y.right). axis.title.*.* inherits from axis.title.* which inherits from axis.title, which in turn inherits from text

axis.text, axis.text.x, axis.text.y, axis.text.x.top, axis.text.x.bottom, axis.text.y.left, axis.text.y.right
tick labels along axes (element_text()). Specify all axis tick labels (axis.text), tick labels by plane (using axis.text.x or axis.text.y), or individually for each axis (using axis.text.x.bottom, axis.text.x.top, axis.text.y.left, axis.text.y.right). axis.text.*.* inherits from axis.text.* which inherits from axis.text, which in turn inherits from text

axis.ticks, axis.ticks.x, axis.ticks.x.top, axis.ticks.x.bottom, axis.ticks.y, axis.ticks.y.left, axis.ticks.y.right
tick marks along axes (element_line()). Specify all tick marks (axis.ticks), ticks by plane (using axis.ticks.x or axis.ticks.y), or individually for each axis (using axis.ticks.x.bottom, axis.ticks.x.top, axis.ticks.y.left, axis.ticks.y.right). axis.ticks.*.* inherits from axis.ticks.* which inherits from axis.ticks, which in turn inherits from line

axis.ticks.length, axis.ticks.length.x, axis.ticks.length.x.top, axis.ticks.length.x.bottom, axis.ticks.length.y, axis.ticks.length.y.left, axis.ticks.length.y.right
length of tick marks (unit)

axis.line, axis.line.x, axis.line.x.top, axis.line.x.bottom, axis.line.y, axis.line.y.left, axis.line.y.right
lines along axes (element_line()). Specify lines along all axes (axis.line), lines for each plane (using axis.line.x or axis.line.y), or individually for each axis (using axis.line.x.bottom, axis.line.x.top, axis.line.y.left, axis.line.y.right). axis.line.*.* inherits from axis.line.* which inherits from axis.line, which in turn inherits from line

legend.background
background of legend (element_rect(); inherits from rect)

legend.margin
the margin around each legend (margin())

legend.spacing, legend.spacing.x, legend.spacing.y
the spacing between legends (unit). legend.spacing.x & legend.spacing.y inherit from legend.spacing or can be specified separately

legend.key
background underneath legend keys (element_rect(); inherits from rect)

legend.key.size, legend.key.height, legend.key.width
size of legend keys (unit); key background height & width inherit from legend.key.size or can be specified separately

legend.text
legend item labels (element_text(); inherits from text)

legend.text.align
alignment of legend labels (number from 0 (left) to 1 (right))

legend.title
title of legend (element_text(); inherits from title)

legend.title.align
alignment of legend title (number from 0 (left) to 1 (right))

legend.position
the position of legends ("none", "left", "right", "bottom", "top", or two-element numeric vector)

legend.direction
layout of items in legends ("horizontal" or "vertical")

legend.justification
anchor point for positioning legend inside plot ("center" or two-element numeric vector) or the justification according to the plot area when positioned outside the plot

legend.box
arrangement of multiple legends ("horizontal" or "vertical")

legend.box.just
justification of each legend within the overall bounding box, when there are multiple legends ("top", "bottom", "left", or "right")

legend.box.margin
margins around the full legend area, as specified using margin()

legend.box.background
background of legend area (element_rect(); inherits from rect)

legend.box.spacing
The spacing between the plotting area and the legend box (unit)

panel.background
background of plotting area, drawn underneath plot (element_rect(); inherits from rect)

panel.border
border around plotting area, drawn on top of plot so that it covers tick marks and grid lines. This should be used with fill = NA (element_rect(); inherits from rect)

panel.spacing, panel.spacing.x, panel.spacing.y
spacing between facet panels (unit). panel.spacing.x & panel.spacing.y inherit from panel.spacing or can be specified separately.

panel.grid, panel.grid.major, panel.grid.minor, panel.grid.major.x, panel.grid.major.y, panel.grid.minor.x, panel.grid.minor.y
grid lines (element_line()). Specify major grid lines, or minor grid lines separately (using panel.grid.major or panel.grid.minor) or individually for each axis (using panel.grid.major.x, panel.grid.minor.x, panel.grid.major.y, panel.grid.minor.y). Y axis grid lines are horizontal and x axis grid lines are vertical. panel.grid.*.* inherits from panel.grid.* which inherits from panel.grid, which in turn inherits from line

panel.ontop
option to place the panel (background, gridlines) over the data layers (logical). Usually used with a transparent or blank panel.background.

plot.background
background of the entire plot (element_rect(); inherits from rect)

plot.title
plot title (text appearance) (element_text(); inherits from title) left-aligned by default

plot.title.position, plot.caption.position
Alignment of the plot title/subtitle and caption. The setting for plot.title.position applies to both the title and the subtitle. A value of "panel" (the default) means that titles and/or caption are aligned to the plot panels. A value of "plot" means that titles and/or caption are aligned to the entire plot (minus any space for margins and plot tag).

plot.subtitle
plot subtitle (text appearance) (element_text(); inherits from title) left-aligned by default

plot.caption
caption below the plot (text appearance) (element_text(); inherits from title) right-aligned by default

plot.tag
upper-left label to identify a plot (text appearance) (element_text(); inherits from title) left-aligned by default

plot.tag.position
The position of the tag as a string ("topleft", "top", "topright", "left", "right", "bottomleft", "bottom", "bottomright) or a coordinate. If a string, extra space will be added to accommodate the tag.

plot.margin
margin around entire plot (unit with the sizes of the top, right, bottom, and left margins)

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

...
additional element specifications not part of base ggplot2. In general, these should also be defined in the element tree argument.

complete
set this to TRUE if this is a complete theme, such as the one returned by theme_grey(). Complete themes behave differently when added to a ggplot object. Also, when setting complete = TRUE all elements will be set to inherit from blank elements.

validate
TRUE to run validate_element(), FALSE to bypass checks.



*/


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


