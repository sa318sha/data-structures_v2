#pragma once
#include <iostream>
#include "node.h"
#include "avl_node.h"


//avl tree
template <typename T>

class balanced_binary_search_tree {

private:
	Node<T>* root;


public:
	balanced_binary_search_tree();
	~balanced_binary_search_tree();

};

template<typename T>
inline balanced_binary_search_tree<T>::balanced_binary_search_tree()
{
	root = new Node<T>;
}

template<typename T>
inline balanced_binary_search_tree<T>::~balanced_binary_search_tree()
{
	delete root
}