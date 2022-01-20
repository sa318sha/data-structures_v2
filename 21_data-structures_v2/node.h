#pragma once
#pragma once

template <typename T>
struct Node {

private:

	T* val;
public:
	Node<T>(Node<T>*, Node<T>*, T);
	Node<T>(T);
	Node<T>();
	Node<T>* left;
	Node<T>* right;
	~Node<T>();
	void swapValue(T*);
	T& getVal();
	void setVal(T);
	

};

template<typename T>
inline void Node<T>::setVal(T _val)
{
	*val = _val;
}

template<typename T>
inline T& Node<T>::getVal()
{
	return *val;
}

template<typename T>
inline void Node<T>::swapValue(T* _val)
{

		T temp = *val;
		*val = *_val;
		*_val = temp;

	
}

template<typename T>
inline Node<T>::~Node()
{
	delete val;
}

template<typename T>
inline Node<T>::Node(Node<T>* _left, Node<T>* _right, T _val)
{
	left = _left;
	right = right;
	val = new T;
	*val = _val;
}
template<typename T>
inline Node<T>::Node(T _val)
{
	left = nullptr;
	right = nullptr;
	val = new T(_val);
}

template<typename T>
inline Node<T>::Node()
{
	left = nullptr;
	right = nullptr;
	val = new T;
	*val = NULL;


}