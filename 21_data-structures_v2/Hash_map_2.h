#pragma once

#include <typeinfo>
#include "pair.h"
#include "single_linked_list.h"


template <typename T, typename S>
class unordered_map {
private:
	int sz;
	//array for the hashmap its gonna be a single linked list with value of a pair and 
	single_linked_list<my_pair<T, S>>* arr;
	int hash_index(T);

public:
	bool delete_val(T, S);
	bool find(T,S);
	void insert(T, S);
	unordered_map();
	unordered_map(int);
	~unordered_map();
};

template<typename T, typename S>
inline int unordered_map<T, S>::hash_index(T val)
{

	string temp = typeid(val).name();

	int hash_key=0;
	if (temp == "int") {
		hash_key = val*val + 6 * val + 18;
	}
	else {
		hash_key = 5;
		/*
		char* ptr = &val;
		while (*ptr != '/0') {
			hash_key += *ptr - '0';
			ptr++;
		}
		*/
	}
	return hash_key;
}


template<typename T, typename S>
inline void unordered_map<T, S>::insert(T key , S value)
{
	//T is the key value we need to calc the hash func off and S is where we score our value?
	//hash values calculations
	int hash_key = hash_index(key)%sz;

	single_linked_list<my_pair<T, S>>* ptr = &arr[hash_key];

	pair<T, S> temp(key, value);

	if (ptr->next == nullptr && ptr->getVal().second->id ==0) {
		ptr->setVal(&temp);
	}
	else {
		while (ptr->next != nullptr) {
			ptr = ptr->next();
			

		}
		single_linked_list<my_pair<T, S>>* temp = new single_linked_list<my_pair<T, S>>(temp);
		ptr->next = temp;
	}

}



template<typename T, typename S>
inline unordered_map<T, S>::unordered_map()
{
	sz = 10;
	arr = new single_linked_list<my_pair<T, S>>[sz];


}
template<typename T, typename S>
inline unordered_map<T, S>::unordered_map(int _size)
{
	sz = _size;
	arr = new single_linked_list<my_pair<T, S>>[sz];
}

template<typename T, typename S>
inline unordered_map<T, S>::~unordered_map()
{
	cout << "hash map destructor" << endl;

	for (int i = 0; i < sz; i++) {
		single_linked_list<my_pair<T,S>>* ptr = &arr[i];

		if (ptr->next != NULL /* && ptr->getVal() != 0*/) {
			ptr = ptr->next;
			while (ptr->next != NULL) {
				single_linked_list<my_pair<T, S>>* temp = ptr;
				ptr = ptr->next;
				delete temp;
			}
			delete ptr;
		}
	}
	delete[] arr;

}