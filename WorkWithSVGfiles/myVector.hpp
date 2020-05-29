#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <cstdlib>
#include <iostream>
#include <cassert>
///my own vector class I use for FigureArray
template <typename T>
class myVector
{
public:
	///constructor
	myVector();
	///constructor
	myVector(int);
	///copy-constructor
	myVector(const myVector&);
	///operator =
	myVector& operator = (const myVector&);
	///destructor
	~myVector();
	///operator []
	const T& operator [] (int index) const;
	///operator []
	T& operator [] (int);
	///adds new items in the vector
	void push_back(const T&);
	///removes item on a specific position from the vector
	void remove(int);
	///returns capacity
	int getCapacity() const;
	///returns size
	int getSize() const;
	///clears the vector
	void clear();
	///operator << used to save vector to a file
	friend std::ostream& operator << (std::ostream& out, const myVector<T>& a)
	{
		out << a.capacity << '\t' << a.size << std::endl;

		for (int i = 0; i < a.size; ++i)
		{
			
			out << a.elements[i] << '\t';
		}

		return out;
	}

private:
	T* elements;
	int size;
	int capacity;
};

template <typename T>
myVector<T>::myVector() : elements(nullptr), size(0), capacity(0)
{}

template <typename T>
myVector<T>::myVector(int n) : size(0)
{
	this->capacity = (n == 0) ? 1 : n;
	this->elements = new T[this->capacity];
}

template <typename T>
myVector<T>::myVector(const myVector<T>& other)
{
	this->capacity = other.capacity;
	this->size = other.size;

	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; ++i)
	{
		this->elements[i] = other.elements[i];
	}
}

template <typename T>
myVector<T>& myVector<T>::operator = (const myVector<T>& other)
{
	if (this != &other)
	{
		delete[] this->elements;

		this->capacity = other.capacity;
		this->size = other.size;

		this->elements = new T[this->capacity];
		for (size_t i = 0; i < this->size; ++i)
		{
			this->elements[i] = other.elements[i];
		}
	}

	return *this;
}

template <typename T>
myVector<T>::~myVector()
{
	delete[] this->elements;
}

template <typename T>
const T& myVector<T>::operator [] (int index) const
{
	assert(index < this->size);
	return this->elements[index];
}

template <typename T>
T& myVector<T>::operator [] (int index)
{
	
	if (index < size) {
		return this->elements[index];
	}
}

template <typename T>
void myVector<T>::push_back(const T& newElem)
{
	if (this->size >= this->capacity)
	{
		int newCapacity = (this->capacity == 0) ? 1 : 2 * this->capacity;

		T* temp = new (std::nothrow) T[newCapacity];
		if (!temp) return;

		/// паметта е заделена успешно
		this->capacity = newCapacity;
		for (int i = 0; i < this->size; ++i)
		{
			temp[i] = this->elements[i];
		}

		delete[] this->elements;
		this->elements = temp;
	}

	this->elements[this->size] = newElem;
	++ this->size;
}

template <typename T>
void myVector<T>::remove(int index)
{
	if (index >= this->size)
		return;
	this->elements[index] = this->elements[this->size - 1];
	-- this->size;
}

template <typename T>
int myVector<T>::getCapacity() const
{
	return this->capacity;
}

template <typename T>
int myVector<T>::getSize() const
{
	return this->size;
}

template<typename T>
void myVector<T>::clear() {
	size = 0;
}

#endif


