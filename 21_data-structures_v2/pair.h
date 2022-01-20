#pragma once
template <typename T, typename S>
class my_pair {
public:
	T* first;
	S* second;
	my_pair();
	my_pair(T, S);
	~my_pair();
	my_pair(my_pair& obj);
	
};

template<typename T, typename S>
inline my_pair<T, S>::~my_pair()
{	
	delete first, second;
}


template<typename T, typename S>
inline my_pair<T, S>::my_pair(my_pair& obj)
{
	first = new T(obj.first);
	second = new S(obj.second);
}

template<typename T, typename S>
inline my_pair<T, S>::my_pair(T key, S value)
{
	first = new T(key);
	second = new S(value);
}

template<typename T, typename S>
inline my_pair<T, S>::my_pair()
{
	first = new T;
	second = new S;
	*first = NULL;
	*second = NULL;
}