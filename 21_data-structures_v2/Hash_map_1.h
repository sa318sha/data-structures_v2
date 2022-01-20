#pragma once

//going to attempt to calculate hash value based on object given so the object itself will be the key value


using namespace std;
#include "node.h"

template<typename T>
class hash_map_1 {

private:

	//following STL's library T is the key type S is the linked list type so if S is an int its an int linked list if its a string a string an object linked list is an object
	int sz;
	node_h<T>* arr;

	//int hash_func(T);
public:
	hash_map_1();
	hash_map_1(int);
	~hash_map_1();
	void insert(T*);
	int bucket(const T* obj);
	void delete_node(T);
	bool findnode(T);
	void resize_rehash(int);
	T& operator[] (int);

};

/*
template<typename T>
inline int hash_map_revised<T>::hash_func(T index)
{


	return 0;
}
*/

template<typename T>
inline int hash_map_1<T>::bucket(const T* obj)
{
	int hash_index = obj->get_hash_value();

	hash_index = hash_index % sz;

	const node_h<T>* ptr = &arr[hash_index];

	while (ptr != NULL) {
		if (ptr->getVal().id == obj->id && ptr->getVal().name == obj->name && ptr->getVal().age == obj->age) {
			return hash_index;
		}
		ptr = ptr->next;

	}
	return -1;
}

template<typename T>
inline void hash_map_1<T>::insert(T* obj)
{
	int hash_index = obj->get_hash_value();

	hash_index = hash_index % sz;



	node_h<T>* ptr = &arr[hash_index];

	//bool test = ptr ? true : false;

	//since we allocate the value dynamically the val of the node is the address of the value instead of 0 so the node ptr is not actually NULL;

	if (ptr->val->id == 0 && ptr->next == NULL) {
		ptr->setVal(*obj);
	}
	else {

		while (ptr->next != NULL) {
			ptr = ptr->next;
		}

		node_h<T>* temp = new node_h<T>;
		ptr->next = temp;
		ptr = temp;
		ptr->setVal(*obj);
	}


}

template<typename T>
inline hash_map_1<T>::hash_map_1()
{
	sz = 10;
	arr = new node_h<T>[sz];
}

template<typename T>
inline hash_map_1<T>::hash_map_1(int _size)
{
	sz = _size;
	arr = new node_h<T>[sz];
}


//destructor
template<typename T>
inline hash_map_1<T>::~hash_map_revised()
{

	cout << "hash map destructor" << endl;

	for (int i = 0; i < sz; i++) {
		node_h<T>* ptr = &arr[i];

		if (ptr->next != NULL && ptr->val != 0) {
			ptr = ptr->next;
			while (ptr->next != NULL) {
				node_h<T>* temp = ptr;
				ptr = ptr->next;
				delete temp;
			}
			delete ptr;
		}
	}
	delete[] arr;




	//return 0;
}