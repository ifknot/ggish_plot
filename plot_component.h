#pragma once

namespace R {

	struct plot_component {

		virtual void render() = 0;

		virtual ~plot_component() = default;

	};

}