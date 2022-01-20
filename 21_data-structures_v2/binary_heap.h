#pragma once
//min heap

//binary heaps can be easily implemented as arrays or linked lists but i wanted to make an actual data structure clearly representing a binary tree

#include "node.h"
#include "queue.h"
template <typename T>
class Binary_Heap {	//implementation of a priority queue

private:
	Node<T>* root;
	int count(Node<T>*);
	Node<T>*& referenceOfLastNode();
	Node<T>* referenceOfSpecificNode();
	void siftDown(Node<T>*);
public:


	bool poll();
	bool remove(T);
	bool insert(T);

	Binary_Heap();
	Binary_Heap(T);
	~Binary_Heap();
	int getCount();

};


template <typename T>
inline bool Binary_Heap<T>::remove(T elem) {

	return true;
}



template<typename T>
inline void Binary_Heap<T>::siftDown(Node<T>* parentNode)
{

	if (parentNode->right != nullptr) {
		
		int right = parentNode->getVal() - parentNode->right->getVal();
		int left = parentNode->getVal() - parentNode->left->getVal();
		if (right > 0 || left > 0) {
			if (right > left) {
				parentNode->swapValue(&parentNode->right->getVal());
				siftDown(parentNode->right);
			}
			else if (left >= right) {
				parentNode->swapValue(&parentNode->left->getVal());
				siftDown(parentNode->left);
			}
		}

	}
	else if (parentNode->right == nullptr && parentNode->left != nullptr) {

		int left = parentNode->getVal() - parentNode->left->getVal();
		if (left > 0) {
			parentNode->swapValue(&parentNode->left->getVal());
			siftDown(parentNode->left);
		}
	}
	//int left_diff = parentNode->getVal()
	// the strcuture will never allow the left node to be null when right null is filled so we can check
	// so we can check if the left node is null is

	
}


template<typename T>
inline int Binary_Heap<T>::getCount()
{
	return count(root);
}


template<typename T>
inline Node<T>*& Binary_Heap<T>::referenceOfLastNode()
{
	if (count(root) == 0) {
		return root;
	}
	queue<Node<T>*>* queue_temp = new queue<Node<T>*>(root);
	Node<T>* node_temp = new Node<T>;
	//iterative approach i can try to make 

	while (!queue_temp->empty()) {

		if (queue_temp->front()->left != nullptr) {
			queue_temp->push(queue_temp->front()->left);
		}
		
		if (queue_temp->front()->right != nullptr) {
			queue_temp->push(queue_temp->front()->right);
		}
		node_temp = queue_temp->front();
		queue_temp->pop();

	}
	//idea

	return node_temp;
}

template <typename T>
inline bool Binary_Heap<T>::poll() {
	Node<T>* temp = referenceOfLastNode();

	root->swapValue(&temp->getVal());
	delete temp;		//removes the top value that was just swa[[ed;

	siftDown(root);

	return true;
}






template <typename T>
inline bool Binary_Heap<T>::insert(T elem) {
	//want to do this with a recursive method/queue before i move on to using the linked list method

	//new idea is to implement a queue and go through each element/node starting at the root and then add it child to the queue until we get out first null then that is the next node to be inserted
	
	queue<Node<T>*>* queue_temp = new queue<Node<T>*>(root);
	Node<T>* temp = new Node<T>(elem);
	//T* T_temp = new T;
	//iterative approach i can try to make 
	while (!queue_temp->empty()) {

		if (queue_temp->front()->getVal() > temp->getVal()) {//getVal returns the actual value not a pointer
			//swap
			queue_temp->front()->swapValue(&temp->getVal());

		}

		if (queue_temp->front()->left != nullptr) {
			queue_temp->push(queue_temp->front()->left);
		}
		else {
			queue_temp->front()->left = temp;
			
			break;
		}
		if (queue_temp->front()->right != nullptr) {
			queue_temp->push(queue_temp->front()->right);
		}
		else {
			queue_temp->front()->right = temp;

			break;
		}
		queue_temp->pop();

	}

	

	delete queue_temp;
	/*
	*/

	return true;


}

template <typename T>
inline int Binary_Heap<T>::count(Node<T>* temp) {

	int counter = 0;

	if (temp == nullptr) return 0;
	//	Node<T>* temp = node;

	if (temp->left != nullptr) {
		counter += count(temp->left);
	}
	if (temp->right != nullptr) {
		counter += count(temp->right);
	}

	return counter += 1;


}


template <typename T>
Binary_Heap<T>::Binary_Heap() {
	root = nullptr;
}

template <typename T>
Binary_Heap<T>::Binary_Heap(T _val) {
	root = new Node<T>(_val);

}

template <typename T>
Binary_Heap<T>::~Binary_Heap() {
	delete root;
}
