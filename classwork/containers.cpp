#include <array>
#include <chrono>
#include <cstring>          // for memcpy()
#include <forward_list>		// use push_front() and pop_front() for it
#include <iostream>
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

template<class TimePoint>
double timediff(const TimePoint &start, const TimePoint &end) {
    duration<double> d(end - start);
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
        delete[] numbers_c;
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
    cout << "C array: " << timediff(start , time_c) << " secs" << endl;
    cout << "array: "   << timediff(time_c, time_a) << " secs" << endl;
    cout << "vector: "  << timediff(time_a, time_v) << " secs" << endl;
    cout << "list: "    << timediff(time_v, time_l) << " secs" << endl;

    start = high_resolution_clock::now();

    for (size_t i = 0; i < container_size; i++)
        numbers_v.erase(numbers_v.begin());
    time_v = high_resolution_clock::now();

    for (size_t i = 0; i < container_size; i++)
        numbers_l.pop_front();
    time_l = high_resolution_clock::now();

	cout << endl;
	cout << "Removal:" << endl;
    cout << "vector removal: " << timediff(start , time_v) << " secs" << endl;
    cout << "list removal: "   << timediff(time_v, time_l) << " secs" << endl;

	return 0;
}
