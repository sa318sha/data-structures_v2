#pragma once
#include <iostream>
#include "single_linked_list.h"

using namespace std;

template <class T>
class UnionFind {
private:
	int sz;
	single_linked_list<T>* arr;
	//int size_of_linked_list[];
	//int id[];
public:
	UnionFind();
	UnionFind(int);
	~UnionFind();
	void _union();
	void _find();

};

template <typename T>
inline UnionFind<T>::UnionFind() {
	sz = 10;
	arr = new single_linked_list<T>[sz];
	for (int i = 0; i < sz; i++)
		arr[i].next = &arr[i];
}


template <typename T>
inline UnionFind<T>::UnionFind(int _size) {
	sz = _size;
	arr = new single_linked_list<T>[sz];
	for (int i = 0; i < sz; i++)
		arr[i].next = &arr[i];

}


template<typename T>
inline UnionFind<T>::~UnionFind()
{
	std::cout << "deleting union find object" << std::endl;
	delete[] arr;
}
