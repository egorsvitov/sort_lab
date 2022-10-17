#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <random>

std::vector<int> bubble_sort(std::vector<int> array) {
	for (int i = 0; i < array.size(); i++) {
		for (int j = 1; j < array.size(); j++) {
			if (array[j] < array[j - 1]) {
				array[j] = array[j - 1] + array[j];
				array[j - 1] = array[j] - array[j - 1];
				array[j] = array[j] - array[j - 1];
			}
		}
	}
	return array;
}

std::vector<int> merge(const std::vector<int>& lhs, const std::vector<int>& rhs) {
	std::vector<int> merged;
	int i = 0, j = 0;
	for (;i < lhs.size() && j < rhs.size();) {
		if (lhs[i] < rhs[j]) {
			merged.push_back(lhs[i++]);
		}
		else {
			merged.push_back(rhs[j++]);
		}
	}
	for (; i < lhs.size(); merged.push_back(lhs[i++]));
	for (; j < rhs.size(); merged.push_back(rhs[j++]));
	return merged;
}

std::vector<int> merge_sort(std::vector<int> array) {
	if (array.size() > 1) {
		auto middle = array.size() / 2;
		std::vector<int> left, right;
		for (int i = 0; i < middle; i++) left.push_back(array[i]);
		for (int i = middle; i < array.size(); i++) right.push_back(array[i]);
		auto sorted_left = merge_sort(left), sorted_right = merge_sort(right);
		return merge(sorted_left, sorted_right);
	}
	return array;
}



int main() {
	std::ofstream n;
	n.open("bubble_sort_output.txt");
	n << '\n';
	n.close();
	std::ofstream out;
    out.open("bubble_sort_output.txt", std::ios::app);
    std::vector<std::vector<int>> arr_of_arrs;
    for (int i = 0; i < 10; i++){
		std::cout << i << std::endl;
        std::vector<int> curr_arr;
        for (int u = 0; u < i * 1000000; u++) {
            curr_arr.push_back(rand());
        }
        arr_of_arrs.push_back(curr_arr);
		std::cout << i << ' ' << arr_of_arrs[i].size() << std::endl;
    }
	char s;
	std::cin >> s;
	if (s == 'b') {
		std::ofstream n;
		n.open("bubble_sort_output.txt");
		n << '\n';
		n.close();
		std::ofstream out;
		out.open("bubble_sort_output.txt", std::ios::app);
		for (int i = 1; i < 100; i+= 10) {
			std::cout << i << std::endl;
			auto start = std::chrono::high_resolution_clock::now();
			bubble_sort(arr_of_arrs[i]);
			auto end = std::chrono::high_resolution_clock::now();
			out << std::to_string(i) << " " << std::to_string((end-start).count()) << std::endl;
	}
	} else if (s == 'm') {
		std::ofstream n;
		n.open("merge_sort_output.txt");
		n << '\n';
		n.close();
		std::ofstream out;
    	out.open("merge_sort_output.txt", std::ios::app);
		for (int i = 0; i < 10; i+= 1) {
			std::cout << i << std::endl;
			auto start = std::chrono::high_resolution_clock::now();
			merge_sort(arr_of_arrs[i]);
			auto end = std::chrono::high_resolution_clock::now();
			out << std::to_string(i) << " " << std::to_string((end-start).count()) << std::endl;
		}
	}
	out.close();
	
}