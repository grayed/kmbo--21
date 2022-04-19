#include <array>
#include <chrono>
#include <cstring>          // for memcpy()
#include <iostream>
#include <forward_list>		// use push_front() and pop_front() for it
#include <list>
#include <vector>

using namespace std;
using namespace std::chrono;

const size_t container_size = 3000;

struct item { char data[40000]; };

static item *numbers_c;
static array<item, container_size> *numbers_a;
static vector<item> numbers_v;
static list<item> numbers_l;
static forward_list<item> numbers_f;

double timediff(const time_point<high_resolution_clock> &till, const time_point<high_resolution_clock> &from) {
    duration<double> d(till - from);
    return d.count();
}

int main() {
    cout << "Starting..." << endl;
    auto start = high_resolution_clock::now();

    numbers_c = new item[0];
    for (size_t i = 0; i < container_size; i++) {
        auto t = new item[i+1];
        memcpy(t, numbers_c, sizeof(*t) * i);
        t[i] = item();
        delete numbers_c;
        numbers_c = t;
    }
    auto time_c = high_resolution_clock::now();

    numbers_a = new array<item, container_size>;
    for (size_t i = 0; i < container_size; i++)
        (*numbers_a)[i] = item();
    auto time_a = high_resolution_clock::now();

    for (size_t i = 0; i < container_size; i++)
        numbers_v.insert(numbers_v.begin(), item());
    auto time_v = high_resolution_clock::now();

    for (size_t i = 0; i < container_size; i++)
        numbers_l.push_front(item());
    auto time_l = high_resolution_clock::now();

    cout << "Addition:" << endl;
    cout << "C array: " << timediff(time_c, start ) << " secs" << endl;
    cout << "array: "   << timediff(time_a, time_c) << " secs" << endl;
    cout << "vector: "  << timediff(time_v, time_a) << " secs" << endl;
    cout << "list: "    << timediff(time_l, time_v) << " secs" << endl;

    start = high_resolution_clock::now();

    for (size_t i = 0; i < container_size; i++)
        numbers_v.erase(numbers_v.begin());
    time_v = high_resolution_clock::now();

    for (size_t i = 0; i < container_size; i++)
        numbers_l.pop_front();
    time_l = high_resolution_clock::now();

	cout << endl;
	cout << "Removal:" << endl;
    cout << "vector removal: " << timediff(time_v, start ) << " secs" << endl;
    cout << "list removal: "   << timediff(time_l, time_v) << " secs" << endl;

	return 0;
}
