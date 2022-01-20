#include <iostream>
#include "node.h"


template <typename T>
class binary_search_tree {

private:

	int nodeCounter;
	Node<T>* root;

	Node<T>* remove(Node<T>*, T);
	bool contains(Node<T>*, T);
	int height(Node<T>*);
	Node<T>* insert(Node<T>*, T);
	Node<T>* findLeftMost(Node<T>*);

public:
	int height();
	bool contains(T);
	bool insert(T);
	bool remove(T);
	//void find(T);
	binary_search_tree();
	~binary_search_tree();
	binary_search_tree(T);
};


template<typename T>
inline int binary_search_tree<T>::height(Node<T>* parentNode)
{
	if (parentNode == NULL) return 0;
	return 1;
	
}

template<typename T>
inline int binary_search_tree<T>::height()
{
	return height(root);
}

template<typename T>
inline bool binary_search_tree<T>::contains(Node<T>* node, T _val)
{
	if (node == NULL) return false;	//reached bottom value not found

	if (_val  < node->getVal()) return contains(node->left, _val);

	else if (_val > node->getVal()) return contains(node->right, _val);

	else return true;
	
}

template<typename T>
inline bool binary_search_tree<T>::contains( T _val)
{
	return contains(root, _val);
}

template<typename T>
inline bool binary_search_tree<T>::remove(T _val)
{
	if (contains(_val)) {
		root = remove(root, _val);
		nodeCounter--;
		return true;
	}
	return false;
}


template<typename T>
Node<T>* binary_search_tree<T>::remove(Node<T>* parentNode, T _val)
{
	//4 cases 1. node is a leaf node ie no child node		//can just remove it
	//2. node is a parent node of right subtree				//remove the parent node and connect the child node and the parent of the parent ndoe
	//3. node is parent node left subtree					//same thing
	//4. node is parent of both								//



	if (parentNode == NULL) return NULL;	// base case

	else if(_val < parentNode->getVal()) {
			parentNode->left = remove(parentNode->left, _val);
	}
	else if(_val > parentNode->getVal()) {
			parentNode->right = remove(parentNode->right, _val);
	}
	else {
		// we found the node
		if (parentNode->left == NULL && parentNode->right == NULL) {
			delete parentNode;	// first case;
			return NULL;
		}
		else if (parentNode->left == NULL && parentNode->right != NULL) {
	
			//right side of tree is not null while left is null
			Node<T>* temp = parentNode->right;
			parentNode->right = NULL;
			delete parentNode;
			return temp;
		}
		else if (parentNode->left != NULL && parentNode->right == NULL) {
			//left side of tree is not null while right is null
			Node<T>* temp = parentNode->left;
			parentNode->left = NULL;
			delete parentNode;
			return temp;
		}
		else {
			//right side of tree is not null and left is not null

			Node<T>* temp = findLeftMost(parentNode->right);

			parentNode->swapValue(&temp->getVal());

			parentNode->right = remove(parentNode->right, _val);
			//std::cout << "need to include this case" << std::endl;
		}
	}
	return parentNode;
	
}

template<typename T>
inline Node<T>* binary_search_tree<T>::findLeftMost(Node<T>* node)
{
	if (node->left == NULL) return node;
	else {
		return findLeftMost(node->left);
	}
	
	
}
/*
template<typename T>
void binary_search_tree<T>::find(T elem)
{
	

}
*/
/*
template<typename T>
inline Node<T>* binary_search_tree<T>::traverse(Node<T>* parentNode,T elem)
{



	
	
	if (parentNode->getVal()> elem) {//go left
		if (parentNode->left != NULL) {
			return traverse(parentNode->left, elem);
		}
		else {
			return parentNode;
			//return parentNode->left;
		}
	}
	else if (parentNode->getVal() < elem) { //gro right if its the same as the parent or greater
		if (parentNode->right != NULL) {
			return traverse(parentNode->right, elem);
		}
		else {
			return parentNode;
			//return parentNode->right;
		}
	}
	else {
		return parentNode;
	}

}
*/

template<typename T>
inline Node<T>* binary_search_tree<T>::insert(Node<T>* parentNode, T _val) {
	if (parentNode == NULL) {
		parentNode = new Node<T>(_val);
	}
	else {
		if (_val < parentNode->getVal() ) {
			parentNode->left = insert(parentNode->left, _val);
		}
		else {
			parentNode->right = insert(parentNode->right, _val);
		}
	}
	return parentNode;
	
}

template<typename T>
bool binary_search_tree<T>::insert(T _val)
{
	//Node<T>* temp = new Node<T>(_val);

	if (contains(_val)) {
		return false;
	}
	else {
		root = insert(root, _val);
		nodeCounter++;
		return true;
	}
	/*
	else {
		//if both left and right calues exist insert

		Node<T>* temp = traverse(root, _val);
		Node<T> next = new Node<T>(_val);


		if (temp->getVal()> _val) {//left side
			
			temp->left = next;
		}
		else if (temp->getVal() < _val) {
			temp->right = next;
		}

	}
	*/

}


template<typename T>
binary_search_tree<T>::binary_search_tree()
{
	nodeCounter = 0;
	root = nullptr;
}

template<typename T>
binary_search_tree<T>::binary_search_tree(T _val)
{
	nodeCounter = 1;
	root = new Node<T>(_val);
}

template<typename T>
binary_search_tree<T>::~binary_search_tree()
{
	delete root;
}
