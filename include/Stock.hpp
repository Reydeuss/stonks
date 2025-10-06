#pragma once

#include <string>
#include <vector>

struct Stock {
	std::string code;
	int price;
};

inline std::vector<Stock> get_default_stocks() {
	return std::vector<Stock>({
		{"BACA", 0},
		{"PANIKBANG", 0},
		{"DANAMAN", 0},
		{"BIN", 0}
	});
}
