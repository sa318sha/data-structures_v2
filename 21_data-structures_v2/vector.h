#pragma once

#include <iostream>

using namespace std;

template <typename T>
class my_vector {
private:
	int sz;
	int cap;
	T* arr;
	void reallocate(int);
public:
	void iterate();
	int size2();
	int capacity();
	bool empty();
	void push_back(T);
	void pop_back();
	bool remove(T);
	void resize(int);
	~my_vector();
	my_vector();
	my_vector(int);
	T& operator[] (int);
};

template<typename T>
inline void my_vector<T>::iterate()
{
	for (int i = 0; i < sz; i++) {
		//temp[i] = arr[i];
		cout << arr[i] << endl;

	}

}

template <typename T>
inline void my_vector<T>::resize(int a) {
	if (a < sz) {
		sz = a;
		//both capacity and sz shrink
	}
	reallocate(a);
}


template <typename T>
inline T& my_vector<T>::operator[](int a) {
	if (a > sz) {
		cout << "index passed greater then max size return first index" << endl;
		return arr[0];
	}
	else if (a < 0) {
		cout << " index passed is negative return first index" << endl;
		return arr[0];
	}
	else {
		return arr[a];
	}
}

template<typename T>
inline void my_vector<T>::reallocate(int _size)
{

	cout << "reallocating" << endl;
	cap = _size;

	T* temp = new T[cap];

	for (int i = 0; i < sz; i++) {
		temp[i] = arr[i];
		//cout << temp[i] << endl;

	}
	delete arr;
	arr = temp;
}




template<typename T>
inline void my_vector<T>::push_back(T a)
{

	arr[sz] = a;
	sz++;

	if (sz == cap) reallocate((sz*2));
}

template<typename T>
inline void my_vector<T>::pop_back()
{

	sz--;
}

template<typename T>
inline bool my_vector<T>::remove(T _elem) {

	T* ptr1 = arr;
	T* ptr2 = arr;
	int counter = 0;
	bool val = true;
	while(counter != sz) {
		if (*ptr2 != _elem && val == true) {
			ptr2++;
			val = false;
		}
		ptr1 = ptr2;
		ptr1++;
		ptr2++;
		counter++;
	}

	return val;
}

template<typename T>
inline my_vector<T>::~my_vector()
{
	cout << "inside destructor" << endl;
	delete arr;
}

template<typename T>
inline my_vector<T>::my_vector()
{
	sz = 0;
	cap = 5;
	arr = new T[cap];
}

template<typename T>
inline my_vector<T>::my_vector(int a)
{
	//arr = NULL;
	sz = a;
	cap = a * 1.5;
	arr = new T[cap];
}

template<typename T>
inline int my_vector<T>::size2()
{
	return sz;
}


template<typename T>
inline int my_vector<T>::capacity()
{
	return cap;
}

template<typename T>
inline bool my_vector<T>::empty()
{
	for (int i = 0; i < sz; i++) {
		if (arr[i] == NULL || arr[i] == 0)  return true;
	}
	return false;
}

