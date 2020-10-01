#pragma once

#include <functional>
template<typename T>
class DynArr {
public:
	T* data = nullptr;
	size_t allocSize = 0;

	DynArr(int size)
	{
		this->allocSize = size;
		//data = new T[size];
		data = (T*)malloc(size * sizeof(T));
		for (int i = 0; i < size; i++)
		{
			data[i] = {};
		}

	}

	virtual ~DynArr() {
		free(data);
	}

	T& get(int index) {
		if (index >= allocSize) throw "assert :: out of bound";
		if (index < 0) throw "out of bound min";
		return data[index];
	}

	void set(int index, const T & toto) {

		if (index >= allocSize)
			resize((index + 1));

		data[index] = toto;

	}

	void resize(int newAllocSize)
	{
		if (newAllocSize < allocSize)
			return;

		int allocSizeByte = newAllocSize * sizeof(T);
		data = (T*)realloc(data, allocSizeByte);

		for (int i = allocSize; i < newAllocSize; i++)
		{
			data[i] = {};
		}

		allocSize = newAllocSize;
	}

	void reverse() {
		//renverser les elements du tableau

		//pour i de 0 a allocsize
		//mettre val(i) dans temp
		//mettre val (allocsize -i) dans val[0]
		//mettre temp dans (allocsize -i -1)
		T temp;
		for (int i = 0; i < allocSize/2; ++i) {
			temp = data[i];
			data[i] = data[allocSize - 1 - 1];
			data[allocSize - i - 1] = temp;
		}
		
	}
	
	
	int length() const {
		return allocSize;
	}

	void push_back(const T & elem) {
		//ajouter l'element a la fin de ce tableau

		//adds elements to the end of the array
		set(length(), elem);

	}

	void append(DynArr<T> & arr) {
		//ajouter les element d'un autre tableau a celui ci

		//pour chaque element de arr
		//mettre cet element dans ce tableau 

		for (int i = 0; i < arr.length(); i++) {
			push_back(arr.data[i]);
		}
		
	}

	void iter(std::function<void(T) > _iter) {
		for (int i = 0; i < length(); i++)
			_iter(data[i]);
	}
};

