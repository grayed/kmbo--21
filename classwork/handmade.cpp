#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

template<class TimePoint>
double timediff(const TimePoint &start, const TimePoint &end) {
    duration<double> d(end - start);
    return d.count();
}

struct Item { int data[10]; Item() { for (auto i = 0; i < 100000; i++) data[1] += i; } };

class PrimitiveArray {
    Item *p;
    size_t size;
public:
    PrimitiveArray(size_t initialSize = 10) : size(initialSize) { p = new Item[initialSize]; }
    Item& operator[] (size_t idx) { if (idx >= size) throw exception(); return p[idx]; }
    size_t getSize() const { return size; }
    void add(const Item &item) {
        auto t = new Item[size+1];
        for (size_t i = 0; i < size; i++)
            t[i] = p[i];
        t[size++] = item;
        delete[] p;
        p = t;
    }
    void remove(size_t idx) {
        if (idx >= size)
            throw exception();
        auto t = new Item[size-1];
        for (size_t i = 0; i < idx; i++)
            t[i] = p[i];
        for (size_t i = idx + 1; i < size; i++)
            t[i-1] = p[i];
        size--;
        delete[] p;
        p = t;
    }
};

class Array {
    Item *p;
    size_t size /* количество помещённых объектов */, capacity /* количество объектов, под которые выделена память */;
public:
    Array(size_t initialCapacity = 10) : size(0), capacity(initialCapacity) { p = (Item*)calloc(initialCapacity, sizeof(Item)); }
    Item& operator[] (size_t idx) { if (idx >= size) throw exception(); return p[idx]; }
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    void add(const Item &item) {
        if (size < capacity)
            p[size++] = item;
        else {
            if (capacity > SIZE_MAX /* максимальное значение size_t */ / 4 / sizeof(Item))
                throw bad_alloc();
            auto ncapacity = capacity * 4;  // проверка выше гарантирует, что умножение здесь и ниже будет корректным
            auto t = (Item*)realloc(p, ncapacity * sizeof(Item));
            if (!t)
                throw bad_alloc();
            t[size++] = item;
            p = t;
            capacity = ncapacity;
        }
    }
    void remove(size_t idx) {
        if (idx >= size)
            throw exception();
        for (size_t i = idx + 1; i < size; i++)
            p[i-1] = p[i];
        size--;
    }
    void shrink() {     // приводит потребление памяти от capacity к size
        if (size < capacity) {
            p = (Item*)realloc(p, size * sizeof(Item));
            capacity = size;
        }
    }
};

const size_t test_size = 100000;
int main() {
    Item item;
    PrimitiveArray primarr;
    Array arr;

//    auto prim_start = high_resolution_clock::now();
//    for (size_t i = 0; i < test_size; i++) {
//        item.data[0] = (int)i;
//        primarr.add(item);
//    }
//    auto prim_end = high_resolution_clock::now();

    auto arr_start = high_resolution_clock::now();
    for (size_t i = 0; i < test_size; i++) {
        item.data[0] = (int)i;
        arr.add(item);
    }
    auto arr_end = high_resolution_clock::now();

    auto v_start = high_resolution_clock::now();
    vector<Item> v(test_size);
    for (size_t i = 0; i < test_size; i++) {
        item.data[0] = (int)i;
        v[i] = item;
        //v.push_back(item);
    }
    auto v_end = high_resolution_clock::now();

    //cout << "primitive array addition: " << timediff(prim_start, prim_end) << " secs" << endl;
    cout << "improved array addition: " << timediff(arr_start, arr_end) << " secs"
         << ", final capacity is " << arr.getCapacity() << endl;
    cout << "std::vector addition: " << timediff(v_start, v_end) << " secs" << endl
         << ", final capacity is " << v.capacity() << endl;

    return 0;
}
