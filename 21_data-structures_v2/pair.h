#pragma once
template <typename T, typename S>
class my_pair {
public:
	T first;
	S* second;
	my_pair();
	my_pair(T, S&);
	~my_pair();
	my_pair(const my_pair& obj);
	void operator=(const my_pair& obj);
	
};

template<typename T, typename S>
inline void my_pair<T, S>::operator=(const my_pair& obj)
{

	first = obj.first;
	second = new S;
	*second = *obj.second;

}

template<typename T, typename S>
inline my_pair<T, S>::~my_pair()
{	
	delete second;
}


template<typename T, typename S>
inline my_pair<T, S>::my_pair(const my_pair& obj)
{
	first = obj.first;
	second = new S;
	//second 
	*second = *obj.second;

}


template<typename T, typename S>
inline my_pair<T, S>::my_pair(T key, S& value)// t is not an object while s is
{
	first = key;
	second = new S(value);
}

template<typename T, typename S>
inline my_pair<T, S>::my_pair()
{
	first = 0;
	second = new S;
	/*
	*first = NULL;
	*second = NULL;
	*/
}