#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <string>

using vector = std::vector<int>;

vector fast_sort(const vector& v);
vector bubble_sort(const vector& v);
void merge_sort(vector& v, size_t left, size_t right, size_t depth = 0);
void print_result(const std::string& sort_name, const vector& vec);

#endif
