#pragma once
//this is implented with a linked/list/array method?
//min heap

//binary heaps can be easily implemented as arrays or linked lists but i wanted to make an actual data structure clearly representing a binary tree

//#include "node.h"
//#include "queue.h"
//implementing min heap
#include "vector.h"
template <typename T>
class Binary_Heap_v2 {	//implementation of a priority queue

private:
	int heap_size;
	int heap_capacity;
	my_vector<T> list;		//vector is dynamically allocated so we do not need to change that
	void bubbleUp(int);
	void swap(T*, T*);

public:

	void iterate();
	bool poll();
	bool remove(T);
	void insert(T);

	Binary_Heap_v2();
	Binary_Heap_v2(T);
	~Binary_Heap_v2();
	int Heapsize();
	bool isEmpty();

};
template<typename T>
inline void Binary_Heap_v2<T>::swap(T* a , T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;

}

template <typename T>
inline void Binary_Heap_v2<T>::bubbleUp(int elem) {

	//std::cout << "value of the list is " <<list[elem] << elem << endl;


	if(elem%2){//left side side
		//if its an odd
		
		
		if (list[elem] < list[(elem-1)/2]) {
			//T's are object so we may need to swap them accodingly
			swap(&list[elem], &list[(elem - 1) / 2]);
			bubbleUp((elem - 1) / 2);
		}
		

	
	}
	else if(elem % 2 ==0 && elem > 1) {//right side
		if (list[elem] < list[(elem - 2) / 2]) {
			swap(&list[elem], &list[(elem - 2) / 2]);
			bubbleUp((elem - 2) / 2);
		}
	//	if its even
	}
	
	//			0
	//		   / \
	//		  1   2
	//		 / |  | \
	//		1  4  5  3



	//			0
	//		   / \
	//		  1   2
	//		 / |  | \
	//		3  4  5  6

}


template <typename T>
inline bool Binary_Heap_v2<T>::isEmpty() {

	return (heap_size == 0);
}

template<typename T>
inline int Binary_Heap_v2<T>::Heapsize()
{
	return heap_size;
}

template<typename T>
inline void Binary_Heap_v2<T>::iterate()
{
	list.iterate();
}



template <typename T>
inline bool Binary_Heap_v2<T>::poll() {


	return true;
}


template <typename T>
inline void Binary_Heap_v2<T>::insert(T elem) {
	if (heap_capacity == heap_size) {
		list.resize(2 * heap_size + 1);
		heap_capacity = 2 * heap_size + 1;
	}
	list.push_back(elem);


	bubbleUp(heap_size);
	heap_size++;
	
//	list.iterate();

}


template <typename T>
Binary_Heap_v2<T>::Binary_Heap_v2() {

	//heap size is the amount of node while capacity is the max number of nodes needed support x amount of layers
	//for instance for 3 layers the capacity will be 7 but the heap size can range from 4-7
	heap_capacity = 0;
	heap_size = 0;
	list;


}
/*
template <typename T>
Binary_Heap_v2<T>::Binary_Heap_v2(T _val) {

	heap_capacity = 1;
	heap_size = 1;
	list = new my_vector<T>(heap_capacity);
	list->push_back(_val);

}
*/
template <typename T>
Binary_Heap_v2<T>::~Binary_Heap_v2() {
	//delete list;
	std::cout << "inside binary heap destructor" << endl;
}
