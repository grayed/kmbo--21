#include <array>
#include <chrono>
#include <cstring>          //
#include <iostream>
#include <forward_list>		// push_front(), pop_front()
#include <list>
#include <vector>

using namespace std;

const size_t cont_size = 100000;

struct item { char data[4]; };

static item *numbers_c;
static array<item, cont_size> *numbers_a;
static vector<item> numbers_v;
static list<item> numbers_l;
static forward_list<item> numbers_f;

double timediff(const chrono::time_point<chrono::high_resolution_clock> &till, const chrono::time_point<chrono::high_resolution_clock> &from) {
    std::chrono::duration<double> d(till - from);
    return d.count();
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    numbers_c = new item[cont_size];
	for (size_t i = 0; i < cont_size; i++) {
        auto t = new item[i+1];
		memcpy(t, numbers_c, sizeof(*t) * i);
        t[i] = item();
		delete numbers_c;
		numbers_c = t;
	}
    auto time_c = chrono::high_resolution_clock::now();
    numbers_a = new array<item, cont_size>;
	for (size_t i = 0; i < cont_size; i++) {
        (*numbers_a)[i] = item();
	}
    auto time_a = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < cont_size; i++)
        numbers_v.push_back(item());
    auto time_v = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < cont_size; i++)
        numbers_l.push_back(item());
    auto time_l = chrono::high_resolution_clock::now();

	cout << "Addition:" << endl;
    cout << "C array: " << timediff(time_c, start ) << endl;
    cout << "array: "   << timediff(time_a, time_c) << endl;
    cout << "vector: "  << timediff(time_v, time_a) << endl;
    cout << "list: "    << timediff(time_l, time_v) << endl;

    start = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < cont_size; i++)
		numbers_v.pop_back();
    time_v = chrono::high_resolution_clock::now();
    for (size_t i = 0; i < cont_size; i++)
		numbers_l.pop_back();
    time_l = chrono::high_resolution_clock::now();

	cout << endl;
	cout << "Removal:" << endl;
    cout << "vector removal: " << timediff(time_v, start ) << " secs" << endl;
    cout << "list removal: "   << timediff(time_l, time_v) << " secs" << endl;

	return 0;
}
