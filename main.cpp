#include <iostream>

#include "r_data_frame.h"

using namespace R;

int main() {

	std::cout << "heterogeneous container\n\n";

	R::data_frame d;

	d["id"] = { 1, 2, 3, 4, 5 };
	d["name"] = { "Rick", "Dan", "Michell", "Ryan", "Gary" };
	d["salary"] = { 623.3, 515.2, 611.0, 729.0, 843.25 };
	d["start_date"] = as_dates({ "2012-01-01", "2013-09-23", "2014-11-15", "2014-05-11", "2015-03-27" });

	// print out data table 
	std::cout << d << '\n';

	// accessing data does need prior knowledge of the column data type
	auto money = std::get<r_double>(d["salary"][1]);

	// but C++ is strongly typed so there we go
	std::cout << std::get<r_string>(d["name"][1]) << " earns $" << money << "\n\n";

	//std::cout << d["name"] << "\n\n";

	//data_frame df;

	//df["x"] = { 2, 1, 4, 9 };
	//df["y"] = { 4, 1, 15, 80 };
	//df["shape"] = { 'b', 'b', 'a', 'a' };

	//std::cout << df << "\n\n";

	//sort<r_integer>(df["y"]);

	//std::cout << df << "\n\n";

	//rescale<r_integer>(df["x"], std::pair(0, 200));
	//rescale<r_integer>(df["y"], std::pair(0, 300));

	//std::cout << df << "\n\n";

	//floor(df["x"]);
	//floor(df["y"]);

	//std::cout << df << "\n\n";

	//sort<r_double>(df["x"], true);

	//std::cout << df << "\n\n";

	//auto t = df["x"];

	//std::cout << unique<r_raw>(df["shape"]) << "\n\n";

	//std::cout << factor<r_raw>(df["shape"]) << "\n\n";

	//std::cout << factor<r_double>(df["x"]) << "\n\n";

	//std::cout << factor<r_char, r_string>(df["shape"], {"BB", "AA"}) << "\n\n";

	//std::cout << factor<r_float>(df["x"]) << "\n\n";

	//std::cout << df << "\n\n";

	auto csv = read_csv("mtcars.csv");

	std::cout << csv["mpg"] << "\n\n";

	std::cout << csv << "\n\n";

}