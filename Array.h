#pragma once
#include<iostream>
#include<exception>
#include<string>

class NoSix : public std::exception
{
public:
	const char* what() const
	{
		return "666 is a wrong number.\n";
	}
};

class Array
{
public:

	class ErrorIndex : public std::exception
	{
	public:
		size_t ind;

		ErrorIndex(size_t ind_) : ind(ind_) {}

		const char* what() const
		{
			return "There is no elements with such index.\n";
		}
	};

	Array() :Size(0), data(nullptr) {};
	explicit Array(size_t _Size) :Size(_Size), data(new int[Size]) {};
	Array(const Array& a);

	~Array() { delete[]data; };

	size_t getSize() const { return Size; }

	void set(size_t, int);

	Array& operator=(const Array& a);
	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);

private:
	size_t Size;
	int* data;
};

Array::Array(const Array& a)
{
	Size = a.Size;
	data = new int[Size];

	for (size_t i = 0; i < a.Size; i++)
		data[i] = a.data[i];
}

Array& Array::operator=(const Array& a)
{
	if (this != &a)//if try to assign to itself
	{
		delete[]data;

		Size = a.Size;
		data = new int[Size];

		for (size_t i = 0; i < a.Size; i++)
			data[i] = a.data[i];
	}
	return *this;
}
int& Array::operator[](size_t index)
{
	if (index >= this->Size)
	{
		throw ErrorIndex(index);
	}
	return this->data[index];
}
const int& Array::operator[](size_t index) const
{
	if (index >= this->Size)
	{
		throw ErrorIndex(index);
	}
	return this->data[index];
}

void Array::set(size_t index, int element)
{
	if (index >= this->Size)
	{
		throw std::exception();
	}
	if (element == 666) throw NoSix();

	data[index] = element;
}


std::ostream& operator<<(std::ostream& out, const Array& a)
{
	for (size_t i = 0; i < a.getSize(); i++)
		out << a[i] << " ";

	return out;
}
std::istream& operator>>(std::istream& in, Array& a)
{
	std::cout << "Enter array elements";
	for (size_t i = 0; i < a.getSize(); i++)
		in >> a[i];

	return in;
}
