#pragma once

#include "../rpp/data_types.h"
#include "../rpp/data_frame.h"
#include "aesthetics.h"

namespace gg {

	/**
	 * A layer is a combination of data, stat and geom with a potential position adjustment.
	 */
	struct layer_t {

		R::r_string		geom;					// name in the geom function dictionary 
		R::r_string		stat;					// name in the stat function dictionary
		R::data_frame*	data{ nullptr };		// data_frame 
		aesthetics_t*	mapping{ nullptr };		// aesthetic struct 
		R::r_string		position;				// name in the position function dictionary e.g. jitter
		bool			show_legend{ true };	// include this layer in the legends
		R::r_string		key_glyph;				// name in the glyph drawing function dictionary
	};

}

/*

A layer is a combination of data, stat and geom with a potential position adjustment. Usually layers are created using geom_* or stat_* calls but it can also be created directly using this function.

layer(
  geom = NULL,
  stat = NULL,
  data = NULL,
  mapping = NULL,
  position = NULL,
  params = list(),
  inherit.aes = TRUE,
  check.aes = TRUE,
  check.param = TRUE,
  show.legend = NA,
  key_glyph = NULL,
  layer_class = Layer
)
Arguments
geom
The geometric object to use display the data

stat
The statistical transformation to use on the data for this layer, as a string.

data
The data to be displayed in this layer. There are three options:

If NULL, the default, the data is inherited from the plot data as specified in the call to ggplot().

A data.frame, or other object, will override the plot data. All objects will be fortified to produce a data frame. See fortify() for which variables will be created.

A function will be called with a single argument, the plot data. The return value must be a data.frame, and will be used as the layer data. A function can be created from a formula (e.g. ~ head(.x, 10)).

mapping
Set of aesthetic mappings created by aes() or aes_(). If specified and inherit.aes = TRUE (the default), it is combined with the default mapping at the top level of the plot. You must supply mapping if there is no plot mapping.

position
Position adjustment, either as a string, or the result of a call to a position adjustment function.

params
Additional parameters to the geom and stat.

inherit.aes
If FALSE, overrides the default aesthetics, rather than combining with them. This is most useful for helper functions that define both data and aesthetics and shouldn't inherit behaviour from the default plot specification, e.g. borders().

check.aes, check.param
If TRUE, the default, will check that supplied parameters and aesthetics are understood by the geom or stat. Use FALSE to suppress the checks.

show.legend
logical. Should this layer be included in the legends? NA, the default, includes if any aesthetics are mapped. FALSE never includes, and TRUE always includes. It can also be a named logical vector to finely select the aesthetics to display.

key_glyph
A legend key drawing function or a string providing the function name minus the draw_key_ prefix. See draw_key for details.

layer_class
The type of layer object to be constructued. This is intended for ggplot2 internal use only

*/