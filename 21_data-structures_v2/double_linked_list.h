#pragma once
#pragma once

template < typename T>
class double_linked_list
{
public:
	static int counter;

	~double_linked_list<T>();
	void setVal(T);
	const T& getVal();
	double_linked_list<T>* next;
	double_linked_list<T>* prev;
	T* val;
	double_linked_list<T>();
	double_linked_list<T>(T);

private:


protected:


};

template <typename T>
int double_linked_list<T>::counter = 0;


template<typename T>
inline void double_linked_list<T>::setVal(T val)
{
	*this->val = val;
}


//if we do not reutnr as reference it will create a new copy of object T if this is an int its fine but we do not want copy of objects
template<typename T>
inline const T& double_linked_list<T>::getVal()
{
	return T(*this->val);
}

template<typename T>
inline double_linked_list<T>::double_linked_list(T a)
{
	next = nullptr;
	prev = nullptr;
	val = new T;
	*val = a;
	counter++;

}
template<typename T>
inline double_linked_list<T>::double_linked_list()
{
	next = nullptr;
	prev = nullptr;
	val = new T;
	*val = NULL;
	counter++;
}

template<typename T>
inline double_linked_list<T>::~double_linked_list()
{
	cout << "inside single list destructor deleting value " << *this->val << endl;
	delete this->val;
	counter--;
}