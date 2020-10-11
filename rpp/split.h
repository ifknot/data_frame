#pragma once

#include "data_structures.h"
#include "factor.h"
#include "as_string.h"

#include <map>
#include <string>

namespace R {

	/**
	 * @ brief Divide into groups.
	 * split divides the data in the data frame x into the groups defined by vector f.  
	 * @note unsplit reverses the effect of split.
	 *
	 * @tparam T	variant type
	 * @param x		data frame containing values to be divided into groups
	 * @param f		a �factor� in the sense that factor(f) defines the grouping
	 * @return		list of data frames containing the values for the groups, named by the levels of f (after converting to a factor)
	 */
	template<typename T>
	data_frame_list split(data_frame& x, variant_vector& v) {
		data_frame_list split_list;
		const auto& [ordinal, levels] = factor<T>(v);			// define the groups by the factor levels
		for (int rank{ first }; const auto & level : levels) {
			data_frame df;
			for (const auto& [key, vec] : x) {
				for (auto row{ 0u }; const auto & v : vec) {
					if (ordinal[row++] == rank) {
						df[key].push_back(v);
					}
				}
			}
			split_list[level] = df;
			++rank;
		}
		return split_list;
	}

	/**
	 * @ brief Divide into groups.
	 * split divides the data in the data frame x into the groups defined by vector f.
	 * @note unsplit reverses the effect of split.
	 *
	 * @tparam T	variant type
	 * @param x		data frame containing values to be divided into groups
	 * @param f		a �factor� in the sense that factor(f) defines the grouping
	 * @return		list of data frames containing the values for the groups, named by the levels of f (after converting to a factor)
	 */
	template<typename T>
	data_frame_list split(data_frame& x, variant_vector&& v) {
		data_frame_list split_list;
		const auto& [ordinal, levels] = factor<T>(v);			// define the groups by the factor levels
		for (int rank{ first }; const auto & level : levels) {
			data_frame df;
			for (const auto& [key, vec] : x) {
				for (auto row{ 0u }; const auto & v : vec) {
					if (ordinal[row++] == rank) {
						df[key].push_back(v);
					}
				}
			}
			split_list[level] = df;
			++rank;
		}
		return split_list;
	}

}