#include "r_data_frame.h"

namespace R {

	variant_vector as_dates(std::vector<std::string> dates) {
		R::variant_vector tm_dates;
		for (const auto& date : dates) {
			std::stringstream ss;
			ss << date + "T00:00:00Z ";
		std:tm tm;
			ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S");
			tm_dates.push_back(tm);
		}
		return tm_dates;
	}

}

std::ostream& operator<<(std::ostream& os, const std::tm& tm) {
	os << std::put_time(&tm, "%Y-%m-%d");
	return os;
}

std::ostream& operator<<(std::ostream& os, const R::data_frame& df) {
	size_t sz;
	for (const auto& [key, vctr] : df) {
		os << '\t' << key;
		sz = vctr.size();	// TODO: check each column contains same number of data items
	}
	std::cout << '\n';
	for (size_t i{ 0 }; i < sz; ++i) {
		std::cout << i;
		for (const auto& [key, vctr] : df) {
			std::visit([](auto&& arg) {std::cout << '\t' << arg; }, vctr[i]);
		}
		os << '\n';
	}
	return os;
}
