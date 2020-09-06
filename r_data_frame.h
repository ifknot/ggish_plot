#pragma once

#include <variant>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <optional>
#include <math.h>

namespace R {

	using r_char	=	char;		// unint8_t
	using r_int		=	int;		// int32_t
	using r_float	=	double;		// float, double, long double
	using r_string	=	std::string;
	using r_date	=	std::tm;	// time_t

	using basic_data_types = std::variant<r_char, r_float, r_int, r_string, r_date>;

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
	 * @brief (R-ish) Sort (or order) a vector into ascending or descending order.
	 * 
	 * @param x				variant vector of values to sort
	 * @param decreasing	bool should the sort be increasing or decreasing?
	 */
	template<typename T>
	void sort (variant_vector& x, bool decreasing = false) {
		// lambda compare functor that works with source variant type 
		auto compare = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) < std::get<T>(b);
		};
		if(decreasing) {
			std::sort(x.rbegin(), x.rend(), compare);
		}
		else {
			std::sort(x.begin(), x.end(), compare);
		}
	}

	//(R-ish) Unique returns a variant vector like x but with duplicate elements removed.
	template<typename T>
	variant_vector unique(variant_vector& x) {
		// lambda equality functor that works with source variant type
		auto equals = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) == std::get<T>(b);
		};
		variant_vector r{ x };
		r.erase(std::unique(r.begin(), r.end(), equals), r.end());
		return r;
	}

	/**
	 * @brief (R-ish) Range returns a pair containing the minimum and maximum of all the given argument
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
	 * @brief (R-ish) Rescale numeric vector to have specified minimum and maximum.
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
	 * @brief (R-ish) Floor converts numeric vector to largest integers not greater than the given numbers.
	 * 
	 * @param x		numeric vector of values to manipulate
	 */
	template<typename T = double>
	void floor(variant_vector& x) {
		for (auto& i : x) {
			i = std::floor(std::get<T>(i));
		}
	}
	

	template<typename T, typename U = T>
	variant_vector factor(variant_vector& x, variant_vector&& levels = {}, variant_vector&& labels = {}, variant_vector&& exclude = {}) {
		std::set<r_string> s;
		// if levels defined use it to build a new unique levels vector otherwise build it from x
		variant_vector lvls{ levels.size() ? R::unique<U>(levels) : R::unique<U>(x) };
		R::sort<U>(lvls);	// sort levels

		// read out all of the source levels using a string stream for conversion then insert into levels set
		/*
		for (const auto& i : source) {
			std::stringstream ss;
			r_string w;
			ss << std::get<U>(i);
			ss >> w;	// buggy sorts number as a string which numerically can be wrong order e.g. 200, 25
			s.insert(w);
		}
		*/
		// modify the x vector to categories 1st, 2nd, ... nth

		// return a string representation of the levels 
		return lvls;//variant_vector{ s.begin(), s.end() };
	}

}

std::ostream& operator<<(std::ostream& os, const std::tm& tm);

std::ostream& operator<<(std::ostream& os, const R::variant_vector& vv);

std::ostream& operator<<(std::ostream& os, const R::data_frame& df);