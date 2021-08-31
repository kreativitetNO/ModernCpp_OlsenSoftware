#ifndef BOUNDED_BUFFER_H
#define BOUNDED_BUFFER_H

#include <cstddef>
#include <iterator>

template <typename T, int SIZE>
class BoundedBuffer
{
public:
	static_assert(SIZE >= 6, "Bounded array size must be at least 6");
	static_assert(sizeof(T) < 100, "Bounded array value type must be less than 100");

	using value_type = T;

	class iterator
	{
	public:
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using difference_type = std::ptrdiff_t;
		using pointer = T*;
		using reference = T&;

		iterator(pointer b);
		reference operator*();
		bool operator==(BoundedBuffer::iterator const& other) const;
		bool operator!=(BoundedBuffer::iterator const& other) const;
		iterator const& operator++();
	private:
		pointer valuePtr_;
	};

	BoundedBuffer::iterator begin();
	BoundedBuffer::iterator end();
	constexpr size_t allocsize() const
	{
		return SIZE * sizeof(T);
	}

private:
	T values_[SIZE];
};

template<typename T, int SIZE>
inline BoundedBuffer<T, SIZE>::iterator::iterator(pointer p)
	: valuePtr_ { p }
{
}

template <typename T, int SIZE>
inline typename BoundedBuffer<T, SIZE>::iterator BoundedBuffer<T, SIZE>::begin()
{
	return BoundedBuffer<T, SIZE>::iterator(values_);
}

template <typename T, int SIZE>
inline typename BoundedBuffer<T, SIZE>::iterator BoundedBuffer<T, SIZE>::end()
{
	return BoundedBuffer::iterator(values_ + SIZE);
}


template<typename T, int SIZE>
inline T& BoundedBuffer<T, SIZE>::iterator::operator*()
{
	return *valuePtr_;
}

template<typename T, int SIZE>
inline bool BoundedBuffer<T, SIZE>::iterator::operator==(BoundedBuffer<T, SIZE>::iterator const& other) const
{
	return this->valuePtr_ == other.valuePtr_;
}

template<typename T, int SIZE>
inline bool BoundedBuffer<T, SIZE>::iterator::operator!=(BoundedBuffer<T, SIZE>::iterator const& other) const
{
	return !(*this == other);
}

template<typename T, int SIZE>
inline typename BoundedBuffer<T, SIZE>::iterator const& BoundedBuffer<T, SIZE>::iterator::operator++()
{
	++valuePtr_;
	return *this;
}

#endif