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
		: data(nullptr)
		, nitems(0)
		, nallocated(0)
	{
		
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
};

#endif
