#pragma once
#pragma once

//#include "dynamic_linked_list.hpp"

#include "single_linked_list.h"

using namespace std;


template <typename T>
class Stack /*: public single_linked_List<T>*/ {

private:

	single_linked_list<T>* node_ptr;

	//dynamic_LL<T> node;
public:

	//static int stackCounter;
	int find(T);
	Stack<T>();
	Stack<T>(single_linked_list<T>& A);
	void pop();
	single_linked_list<T> peakTop();
	void push(single_linked_list<T>&);
	void push(T);
	void pop2();
	//~Stack<T>();

	void setVal(T);
	const T getVal();

};




template<typename T>
inline single_linked_list<T> Stack<T>::peakTop()
{

	return *node_ptr;
}


template<typename T>
inline int Stack<T>::find(T val)//single linked list can also be called node (with one connection) ig
{
	single_linked_list<T>* iterator = node_ptr;
	int count = 0;
	while (iterator != NULL) {
		cout << "inside iterator has value of " << *iterator->val << endl;
		if (*iterator->val == val) return count;


		count++;
		iterator = iterator->next;


	}

	return -1;

}


template<typename T>
inline Stack<T>::Stack(single_linked_list<T>& A)
{
	//root.val = A.val;
	//root.next = NULL;

	node_ptr->next = NULL;
	node_ptr->val = A.val;
	//node_ptr->next = NULL;
	//T* mem = new T;
	//node_ptr->val = new T;
	//node_ptr->val = A.val;

	cout << "inside constructor" << endl;
	//node_ptr->setVal(val);
	//node_ptr = &root;

}

template<typename T>
inline Stack<T>::Stack()
{
	//root.val = NULL;
	//root.next = NULL;

	node_ptr = NULL;
	//node_ptr->next = NULL;
	//T* mem = new T;
	//node_ptr->val = new T;
	//node_ptr->val = A.val;

	cout << "inside constructor" << endl;
	//node_ptr->setVal(val);
	//node_ptr = &root;

}

/*
template<typename T>
inline Stack<T>::Stack()
{
	cout << "inside constructor 2 " << endl;
	node_ptr = &root;
	node_ptr->setVal(node_ptr->counter);



}
*/

template<typename T>
inline void Stack<T>::push(T A)//single linked list can also be called node (with one connection) ig
{

	single_linked_list<T>* temp = new single_linked_list<T>;


	cout << "inside push" << endl;
	if (node_ptr == NULL) {


		temp->next = NULL;

	}
	else {
		temp->next = node_ptr;

	}

	*temp->val = A;
	node_ptr = temp;


	//A.next = node_ptr;
	//node_ptr = &A;

}

template<typename T>
inline void Stack<T>::pop2()
{

	single_linked_list<T>* temp = node_ptr;


	if (node_ptr->next != NULL) {
		node_ptr = node_ptr->next;
	}
	else {
		node_ptr = NULL;
	}


	temp->next = NULL; //ignore next comments // weird throws error is single_linked_list<T>::next is in public
	//delete temp->getVal();
	delete temp;
}


/*
template<typename T>
inline void Stack<T>::push(node<T>& A)//single linked list can also be called node (with one connection) ig
{
	cout << "inside push" << endl;
	if (node_ptr == NULL) {
		A.next = NULL;
		node_ptr = &A;
	}
	else {
		A.next = node_ptr;
		node_ptr = &A;
	}

	//A.next = node_ptr;
	//node_ptr = &A;

}

template<typename T>
inline void Stack<T>::pop()
{

	node<T>* temp = node_ptr;


	if (node_ptr->next != NULL) {
		node_ptr = node_ptr->next;
	}
	else {
		node_ptr = NULL;
	}


	temp->next = NULL; //ignore next comments // weird throws error is single_linked_list<T>::next is in public
	//delete temp->getVal();
	//delete temp;
}
*/