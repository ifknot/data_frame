#pragma once

#include "types.h"

namespace R {

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 *
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector& x) {
		// lambda equality functor that works with source variant type
		auto equals = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) == std::get<T>(b);
		};
		variant_vector v{ x };
		v.erase(std::unique(v.begin(), v.end(), equals), v.end());
		return v;
	}

	/**
	 * @brief (R-ish) unique returns a variant vector like x but with duplicate elements removed.
	 *
	 * @param x		variant vector of r_string values to convert
	 * @return		variant vector of unique values
	 */
	template<typename T>
	variant_vector unique(variant_vector&& x) {
		// lambda equality functor that works with source variant type
		auto equals = [&](const basic_data_types& a, const basic_data_types& b) {
			return std::get<T>(a) == std::get<T>(b);
		};
		variant_vector v{ x };
		v.erase(std::unique(v.begin(), v.end(), equals), v.end());
		return v;
	}

}