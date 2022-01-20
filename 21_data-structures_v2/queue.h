#pragma once
#include <iostream>
//#include "D_linked_list.h"
#include "single_linked_list.h"

//can be implemented using single linked list 
// queue and stack are very similar they just go in diff direction 


template <typename T>
class queue {
public:

	
	void push(T);
	void pop();
	T front();
	T back();
	void iterate();
	queue<T>();
	queue<T>(T);
	~queue<T>();
	int getSize();
	bool empty();

private:
	//node<T>;
	int counter;
	single_linked_list<T>* tail;
	single_linked_list<T>* head;

};

template<typename T>
inline T queue<T>::back()
{
	return (tail->getVal());
}

template<typename T>
inline T queue<T>::front()
{
	return (head->getVal());
}


template<typename T>
inline void queue<T>::iterate()
{
	single_linked_list<T>* temp = head;
	while (temp != nullptr) {
		std::cout << *temp->val << std::endl;
		temp = temp->next;
	}

}

template<typename T>
inline int queue<T>::getSize()
{
	return counter;
}

template<typename T>
inline bool queue<T>::empty()
{
	return (counter==0);
}


template <class T>
inline void queue<T>::push(T a)
{

	std::cout << "inside enqueue" << std::endl;
	single_linked_list<T>* temp = new single_linked_list<T>(a);
	if (tail == NULL) {
		head = temp;
	}
	else {
		tail->next = temp;

	}
	tail = temp;
	counter++;

}

template<typename T>
inline void queue<T>::pop()
{

	single_linked_list<T>* temp = head;


	if (head != NULL) {
		head = head->next;
		temp->next = NULL;
		//temp->prev = NULL;
		delete temp;
		counter--;
	}
	
	/*
	head = head->prev;
	head->next = NULL;
	temp->prev = NULL;
	delete temp;
	*/
}

template<typename T>
inline queue<T>::queue()
{
	/*
	tail->next = NULL;
	tail->prev = NULL;
	tail->val = NULL;
	head->val = NULL;
	head->next = NULL;
	head->prev = NULL;
	*/
	head = NULL;
	tail = NULL;
}

template<typename T>
inline queue<T>::queue(T a)
{

	single_linked_list<T>* temp = new single_linked_list<T>(a);
	counter = 1;
	tail = temp;
	head = temp;
	//	head->next = NULL;
	//	head->prev = NULL;
	//head->val = a;
	//	tail->next = NULL;
	//	tail->prev = NULL;
	//*tail->val = a;


	//*head->val = a;

}

template<typename T>
inline queue<T>::~queue()
{
	std::cout << "inside destructor" << std::endl;
	

}