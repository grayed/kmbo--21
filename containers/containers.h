#pragma once
#include <iostream>
#include <array>
#include <forward_list>
#include <list>
#include <vector>
#include <cstring>

const size_t  cont_size = 10000;

struct large_item { char data[10000]; };

large_item* num_c;
array<large_item, cont_size> *num_a;
vector<large_item> num_v;
list<large_item> num_l;
forward_list<large_item> num_f;

int main() {
	
	
	num_c = new large_item[0];
	for (size_t i = 0; i < cont_size;i++) {
		auto t = new large_item[i + 1];
		memcpy(t, num_c, sizeof(*t) * i);
		t[i] = large_item();
		delete num_c;
		num_c = t;
	}

	num_a = new array<large_item, cont_size>;
	for (size_t i = 0;i < cont_size;i++) {
		(*num_a)[i] = large_item();
	}
	for (size_t i = 0;i < cont_size;i++) {
		num_v.push_back(large_item());
	}
	for (size_t i = 0;i < cont_size;i++) {
		num_l.push_back(large_item());
	}

}

