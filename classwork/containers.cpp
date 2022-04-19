#include <sys/time.h>
#include <array>
#include <cstring>
#include <iostream>
#include <forward_list>		// push_front(), pop_front()
#include <list>
#include <vector>

using namespace std;

const size_t cont_size = 1000;

struct large_item { char data[10000]; };

large_item *numbers_c;
array<large_item, cont_size> *numbers_a;
vector<large_item> numbers_v;
list<large_item> numbers_l;
forward_list<large_item> numbers_f;

time_t timediff(const timeval &from, const timeval &till) {
	auto delta = till.tv_usec - from.tv_usec;
	delta += (till.tv_sec - from.tv_sec) * 1000000;
	return delta;
}

int main(int argc, char **argv) {
	timeval start, time_c, time_a, time_v, time_l;

	gettimeofday(&start, nullptr);
	numbers_c = new large_item[cont_size];
	for (size_t i = 0; i < cont_size; i++) {
		auto t = new large_item[i+1];
		memcpy(t, numbers_c, sizeof(*t) * i);
		t[i] = large_item();
		delete numbers_c;
		numbers_c = t;
	}
	gettimeofday(&time_c, nullptr);
	numbers_a = new array<large_item, cont_size>;
	for (size_t i = 0; i < cont_size; i++) {
		(*numbers_a)[i] = large_item();
	}
	gettimeofday(&time_a, nullptr);
	for (size_t i = 0; i < cont_size; i++)
		numbers_v.push_back(large_item());
	gettimeofday(&time_v, nullptr);
	for (size_t i = 0; i < cont_size; i++)
		numbers_l.push_back(large_item());
	gettimeofday(&time_l, nullptr);

	cout << "Addition:" << endl;
	cout << "C array: " << timediff(start, time_c) << endl;
	cout << "array: " << timediff(time_c, time_a) << endl;
	cout << "vector: " << timediff(time_a, time_v) << endl;
	cout << "list: " << timediff(time_v, time_l) << endl;

	gettimeofday(&start, nullptr);
	for (size_t i = 0; i < cont_size; i++)
		numbers_v.pop_back();
	gettimeofday(&time_v, nullptr);
	for (size_t i = 0; i < cont_size; i++)
		numbers_l.pop_back();
	gettimeofday(&time_l, nullptr);

	cout << endl;
	cout << "Removal:" << endl;
	cout << "vector removal: " << timediff(start, time_v) << endl;
	cout << "list removal: " << timediff(time_v, time_l) << endl;

	return 0;
}
