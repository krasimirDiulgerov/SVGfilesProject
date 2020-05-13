#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <cstdlib>
#include <iostream>
#include <cassert>

template <typename T>
class myVector
{
public:
	myVector();
	myVector(int);
	myVector(const myVector&);
	myVector& operator = (const myVector&);
	~myVector();

	const T& operator [] (int index) const;
	T& operator [] (int);

	void push_back(const T&);
	void remove(int);

	int getCapacity() const;
	int getSize() const;

	void clear();

	friend std::ostream& operator << (std::ostream& out, const myVector<T>& a)
	{
		out << a.capacity << '\t' << a.size << std::endl;

		for (int i = 0; i < a.size; ++i)
		{
			/// записваме (извеждаме) отделните елементи с разделите табулаци€
			/// за конкретни€ тип T тр€бва да е предефиниран operator <<
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
	for (size_t i = 0; i < this->size; ++i)
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


