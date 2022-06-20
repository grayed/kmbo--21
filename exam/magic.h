#ifndef EXAM_MAGIC_H
#define EXAM_MAGIC_H

// No definition is needed here, partial instantination of
template<bool checkResult, size_t A, size_t B> struct MultiplicationCheckHelper;

// Used when check is passed
template<size_t A, size_t B>
struct MultiplicationCheckHelper<true, A, B> {
	enum {
		Size = A * B
	};
};

// Used when check is failed
template<size_t W, size_t H>
struct MultiplicationCheckHelper<false, W, H> {};

// Checks that width * height <= SIZE_MAX
template<size_t W, size_t H>
struct SizeMultiplicationOverflowCheck : MultiplicationCheckHelper<((SIZE_MAX / W) >= H), W, H> {};

#endif
