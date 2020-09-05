#pragma once

#include <variant>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <optional>
#include <math.h>

namespace R {

	using basic_data_types = std::variant<char, double, int, std::string, std::tm>;

	using variant_vector = std::vector<basic_data_types>;

	/**
	 * As per R language definition the following are the characteristics of a data frame
	 * 
	 * - The column names should be non-empty.
	 * - The row names should be unique.
	 * - The data stored in a data frame can be of numeric, factor or character type.
	 * - Each column should contain same number of data items.
	 */
	using data_frame = std::unordered_map<std::string, variant_vector>;

	variant_vector as_dates(std::vector<std::string> dates);

	/**
	 * @brief returns a pair containing the minimum and maximum of all the given argument
	 * 
	 * @param x		numeric vector of values to summarize
	 * @return		std::pair<double, double> min, max
	 */
	template<typename T> 
	std::pair<double, double> range(variant_vector& x) {
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) < std::get<T>(b);
		};
		std::pair<double, double> r;
		r.first = std::get<T>(*std::min_element(x.begin(), x.end(), compare));
		r.second = std::get<T>(*std::max_element(x.begin(), x.end(), compare));
		return r;
	}

	/**
	 * @brief rescale numeric vector to have specified minimum and maximum.
	 *  
	 * Usage rescale(x, to = c(0, 1), from = range(x))
	 * 
	 * @param x		numeric vector of values to manipulate
	 * @param to	output range pair
	 * @param range	optional input range pair - if not given, is calculated from the range of x.
	 */
	template<typename T>
	void rescale(variant_vector& x, std::pair<double, double> to = std::pair(0.0, 1.0), std::pair<double, double> range = std::pair(0.0, 0.0) ) {
		if (range.first == range.second) {
			range = R::range<int>(x);
		}
		for (auto& i : x) {
			i = ((std::get<T>(i) - range.first) / (range.second - range.first)) * (to.second - to.first);
		}
	}

	/**
	 * @brief converts numeric vector to largest integers not greater than the given numbers.
	 * 
	 * @param x		numeric vector of values to manipulate
	 */
	template<typename T = double>
	void floor(variant_vector& x) {
		for (auto& i : x) {
			i = std::floor(std::get<T>(i));

		}
	}

}

std::ostream& operator<<(std::ostream& os, const std::tm& tm);

std::ostream& operator<<(std::ostream& os, const R::variant_vector& vv);

std::ostream& operator<<(std::ostream& os, const R::data_frame& df);