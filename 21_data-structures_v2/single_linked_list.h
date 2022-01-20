#pragma once
#include <iostream>

template < typename T>
class single_linked_list
{
public:

	static int counter;
	~single_linked_list<T>();
	void setVal(T);
	const T& getVal();
	void swap(T*);
	single_linked_list<T>* next;

	single_linked_list<T>();
	single_linked_list<T>(T);
	//int hash_func();

private:
	T* val;

protected:


};


template<typename T>
inline void single_linked_list<T>::swap(T* _val)
{
	T temp = *val;
	*val = *_val;
	*_val = temp;

}

template <typename T>
int single_linked_list<T>::counter = 0;


template<typename T>
inline void single_linked_list<T>::setVal(T val)//T is a pair in hash_map_2
{

	*this->val = val;


}
template<typename T>
inline const T& single_linked_list<T>::getVal()
{
	return *this->val;

}

template<typename T>
inline single_linked_list<T>::single_linked_list(T a)
{
	next = nullptr;
	val = new T(a);
	counter++;
}
template<typename T>
inline single_linked_list<T>::single_linked_list()
{
	next = nullptr;
	val = new T;
	counter++;


}

template<typename T>
inline single_linked_list<T>::~single_linked_list()
{

	std::cout << "inside single list destructor deleting value " << std::endl;
	delete this->val;
	counter--;
}