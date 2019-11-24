#pragma once
#include<iostream>
using namespace std;

template <class T>
class Node
{
private:
	T data;
	Node<T>* right;
	Node<T>* left;
	Node<T>* parent;
public:
	Node<T>(T);
	void setData(T);
	void setRight(Node<T>*);
	void setLeft(Node<T>*);
	void setParent(Node<T>*);
	T getData();
	Node<T>* getRight();
	Node<T>* getLeft();
	Node<T>* getParent();
	~Node<T>();
};

template <class T>
Node<T>::Node(T d): data(d)
{
	right = left = parent = NULL;
}

template <class T>
void Node<T>::setData(T d)
{
	data = d;
}

template <class T>
void Node<T>::setRight(Node<T>* r)
{
	right = r;
}

template <class T>
void Node<T>::setLeft(Node<T>* l)
{
	left = l;
}

template <class T>
void Node<T>::setParent(Node<T>* p)
{
	parent = p;
}

template <class T>
T Node<T>::getData()
{
	return data;
}

template <class T>
Node<T>* Node<T>::getRight()
{
	return right;
}

template <class T>
Node<T>* Node<T>::getLeft()
{
	return left;
}

template <class T>
Node<T>* Node<T>::getParent()
{
	return parent;
}

template <class T>
Node<T>::~Node()
{
}