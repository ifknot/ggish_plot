#pragma once

#include <variant>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <sstream>

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

}

std::ostream& operator<<(std::ostream& os, const std::tm& tm);

std::ostream& operator<<(std::ostream& os, const R::data_frame& df);
