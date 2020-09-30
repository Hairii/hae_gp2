#pragma once

template<typename T>

class Arr
{
public:

	T* data = nullptr;
	int size = 0;

	Arr(int _size) {
		data = new T[_size];
		for (int i = 0; i < _size; i++) 
			data[i] = {};
	}

	virtual ~Arr() {
		delete[] data;
		//std::cout << "deleted" << std::endl;
	}

	T & get(int idx) {
		if (idx >= size)throw " out of bound maj";
		if (idx < 0) throw"out of bound min";
		return data[idx];
	}

	void set(int idx, T val)
	{
		
		data[idx] = val;

		if ( idx >= size)throw " out of bound maj";
		if ( idx < 0) throw"out of bound min";
	}
};

