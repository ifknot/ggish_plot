#pragma once

#include <vector>
#include <memory>

#include "plot_component.h"
#include "data_frame.h"

namespace R {

	class plot_composite : public plot_component {

	public:

		using plot_component::plot_component;

		inline void add(plot_component* p) {
			components.emplace_back(p);
		}

		inline void render(wxDC& gdc) override {
			for (auto& c : components) {
				c->render(gdc);
			}
		}

	protected:

		data_frame data;

		std::vector<std::unique_ptr<plot_component>> components;

	};

}
