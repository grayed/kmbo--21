#ifndef EXAM_ARRAY_H
#define EXAM_ARRAY_H

#include <stdexcept>

template<typename T>
class Array {
	T* data;
	size_t nitems;
	size_t nallocated;

public:
	Array() : data(nullptr), nitems(0), nallocated(0) { }
	
	template<typename SrcIter>
	Array(size_t initialSize, SrcIter src)
	{
		data = new T[initialSize];
		nallocated = nitems = initialSize;
		for (size_t i = 0; i < initialSize; i++)
			data[i] = *src++;
	}

	virtual ~Array() {
		delete[] data;
	}

	T& operator [] (size_t idx) {
		if (idx >= nitems)
			throw std::out_of_range("idx");
		return data[idx];
	}

	const T& operator [] (size_t idx) const {
		if (idx >= nitems)
			throw std::out_of_range("idx");
		return data[idx];
	}

	void add(const T& item) {
		if (nitems == nallocated) {
			size_t newSize = nallocated * sizeof(T);

			T* tmp = realloc(data, )
		}
		data[nitems++] = item;
	}

	void remove(size_t idx) {
		if (idx >= nitems)
			throw std::out_of_range("idx");
		for (size_t i = idx; idx < nitems - 1; idx++)
			data[i] = data[i + 1];
		nitems--;
	}
};

#endif
