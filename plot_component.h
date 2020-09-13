#pragma once

namespace R {

	struct plot_component {

		virtual void render(wxDC& dc) = 0;

		virtual ~plot_component() = default;

	};

}