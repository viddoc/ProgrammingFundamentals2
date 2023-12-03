#ifndef _VECTOR_H_
#define _VECTOR_H_

#include<stdexcept>
#include<string>

namespace cosc1437
{
	template<class T>
	class Vector
	{
	public:
		using size_type = unsigned long;
		using iterator = T*;
		using const_iterator = const T*;

	private:
		size_type size;
		size_type capacity;
		T* pElems;

		void checkSize();

	public:
		//Constructors
		Vector<T>();
		Vector<T>(size_type capacity);
		Vector<T>(size_type size, T val);
		//Copy Constructor
		Vector<T>(const Vector<T>& rhs);
		//Destructor
		virtual ~Vector<T>();

		//Overloaded operators
		Vector<T>& operator=(const Vector<T>& rhs);
		T& operator[](const int index);
		Vector<T> operator+(const Vector<T>& rhs);
		Vector<T> operator+(const T& rhs);
		bool operator==(const Vector<T>& rhs);
		bool operator!=(const Vector<T>& rhs);

		//Getters
		int getSize() const;
		int getCapacity() const;

		//Other methods
		T add(const T elem); //Add element to end of vector
		T remove(); //Remove the last element of vector
		T& at(const int index); //Return the or set the element at position index
		bool contains(const T elem); //Is element in vector?
		bool isEmpty(); //True if vector has no elements
		void clear(); //Removes all elements

		//Iterator methods
		iterator begin()
		{
			return pElems;
		}

		const_iterator begin() const
		{
			return pElems;
		}

		iterator end()
		{
			return &pElems[size];
		}

		const_iterator end() const
		{
			return &pElems[size];
		}
	};

	//Start of code implementation
	template<class T>
	inline Vector<T>::Vector() : Vector<T>(10) {}

	template<class T>
	inline Vector<T>::Vector(size_type capacity) : size(0)
	{
		if (capacity < 1)
		{
			throw std::runtime_error("Cannot create a vector of 0 capacity");
		}
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		pElems = new T[capacity];
	}

	template<class T>
	inline Vector<T>::Vector(size_type size, T val)
		:Vector<T>(size), size(size)
	{
		for (size_type i{ 0 }; i < size; i++)
		{
			pElems[i] = val;
		}
	}

	template<class T>
	inline Vector<T>::Vector(const Vector<T>& rhs)
		:Vector<T>(rhs.capacity)
	{
		this->size = rhs.size;
		for (size_type i{ 0 }; i < size; i++)
		{
			pElems[i] = rhs.pElems[i];
		}
	}

	template<class T>
	inline Vector<T>::~Vector()
	{
		delete[] pElems;
	}

	template<class T>
	inline Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
	{
		if (pElems)
		{
			delete[] pElems;
		}

		size = rhs.size;
		capacity = rhs.capacity;
		pElems = new T[capacity];
		for (size_type i{ 0 }; i < size; i++)
		{
			pElems[i] = rhs.pElems[i];
		}
		return *this;
	}

	template<class T>
	inline T& Vector<T>::operator[](const int index)
	{
		return pElems[index];
	}

	//v3 = v1 + v2
	template<class T>
	inline Vector<T> Vector<T>::operator+(const Vector<T>& rhs)
	{
		Vector<T> tempVec = *this;
		for (size_type i{ 0 }; i < rhs.size; i++)
		{
			tempVec.add(rhs.pElems[i]);
		}
		return tempVec;
	}

	//v3 = v1 + T
	template<class T>
	inline Vector<T> Vector<T>::operator+(const T& rhs)
	{
		Vector<T> tempVec = *this;
		tempVec.add(rhs);
		return tempVec;
	}

	template<class T>
	inline bool Vector<T>::operator==(const Vector<T>& rhs)
	{
		if (size != rhs.size)
		{
			return false;
		}
		for (size_type i{ 0 }; i < size; i++)
		{
			if (pElems[i] != rhs.pElems[i])
			{
				return false;
			}
		}
		return true;
	}

	template<class T>
	inline bool Vector<T>::operator!=(const Vector<T>& rhs)
	{
		return !(operator == (rhs));
	}

	template<class T>
	inline int Vector<T>::getSize() const
	{
		return size;
	}

	template<class T>
	inline int Vector<T>::getCapacity() const
	{
		return capacity;
	}

	template<class T>
	inline T Vector<T>::add(const T elem)
	{
		checkSize();
		pElems[size] = elem;
		size++;
		return elem;
	}

	template<class T>
	inline T Vector<T>::remove()
	{
		if (size == 0)
		{
			throw std::runtime_error("Cannot remove element from empty Vector");
		}
		T temp = pElems[size - 1];
		size--;
		return temp;
	}

	template<class T>
	inline T& Vector<T>::at(const int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::runtime_error("Index out of bounds: size is " + std::to_string(size));
		}
		return operator[](index);
	}

	template<class T>
	inline bool Vector<T>::contains(const T elem)
	{
		for (auto e : pElems)
		{
			if (elem == e)
			{
				return true;
			}
		}
		return false;
	}

	template<class T>
	inline bool Vector<T>::isEmpty()
	{
		return size == 0;
	}

	template<class T>
	inline void Vector<T>::clear()
	{
		size = 0;
	}

	//Private Method
	//Checks if size < capacity, if not then increases capacity
	template<class T>
	inline void Vector<T>::checkSize()
	{
		//Check if the array is large enough to add another element
		if (size < capacity)
		{
			return;
		}
		//Resize the capacity
		
		capacity *= 2;
		

		//Create a new array of type T with capacity
		T* temp = new T[capacity];
		//Copy the elements in pElem to temp
		for (size_type i{ 0 }; i < size; i++)
		{
			temp[i] = pElems[i];
		}
		//Delete pElems so that there is no memory leak
		if (pElems)
		{
			delete[] pElems;
		}
		//Assign the value of temp to pElems
		pElems = temp;
	}
} //End of namespace

#endif // !_VECTOR_H_

