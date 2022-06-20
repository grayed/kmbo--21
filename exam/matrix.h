#ifndef EXAM_MATRIX_H
#define EXAM_MATRIX_H

#include <stdexcept>

#include "magic.h"


template<typename T, size_t W, size_t H>
class Matrix : SizeMultiplicationOverflowCheck<W, H> {
	T *data;

public:
	Matrix() : data(new T[Size]) {}

	virtual ~Matrix() {
		delete[] data;
	}

	const T& operator () (size_t row, size_t col) const {
		if (row >= H)
			throw std::out_of_range("row");
		if (col >= H)
			throw std::out_of_range("col");
		return data[W * row + col];
	}

	T& operator () (size_t row, size_t col) {
		return const_cast<T&>((*const_cast<const Matrix<T, W, H>(this))(row, col));
	}
};

#endif
