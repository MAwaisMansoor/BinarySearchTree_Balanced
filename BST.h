#pragma once
#include<iostream>
#include"Node.h"
using namespace std;

template <class T>
class BST
{
	Node<T>* root;
	int size;
	bool del(Node<T>*);
	Node<T>* insert(T d, Node<T>*);
	void createlevelOrder(Node<T>*, int);
	void gstSum(Node<T>*, T*);
	void setRoot(Node<T>*);
	void setSize(int);
	Node<T>* rr_leftRotation(Node<T>*);
	Node<T>* ll_rightRotation(Node<T>*);
	Node<T>* lr_doubleRightRotation(Node<T>*);
	Node<T>* rl_doubleLeftRotation(Node<T>*);
public:
	BST<T>();
	int getSize();
	Node<T>* getRoot();
	void insert(T);
	Node<T>* search(T);
	T maxx(Node<T>*);
	T minn(Node<T>*);
	void walkInOrder(Node<T>*);
	void walkPreOrder(Node<T>*);
	void walkPostOrder(Node<T>*);
	void levelOrder(Node<T>*);
	T sum(Node<T>*);
	void gst();
	int high(Node<T>*);
	bool remove(T);
	void allLeafsDisplay(Node<T>*);
	void allInterDisplay(Node<T>*);
	T parentDisplay(T);
	void successor(T);
	void predecessor(T);
	void mirror(Node<T>*, BST<T>*);
	bool balanceFactor(T);
	~BST<T>();
};

template <class T>
BST<T>::BST()
{
	root = NULL;
	size = 0;
}
template<class T>
inline void BST<T>::gst()
{
	if (this->root == NULL)
	{
		return;
	}
	int sum = 0;
	gstSum(this->root, &sum);
}

template<class T>
inline void BST<T>::gstSum(Node<T>* tmp1, T* sum)
{
	if (tmp1 == NULL)	return;

	gstSum(tmp1->getRight(), sum);
	*sum += tmp1->getData();
	tmp1->setData(*sum - tmp1->getData());
	gstSum(tmp1->getLeft(), sum);
}

template<class T>
inline void BST<T>::insert(T d)
{
	root = insert(d, root);
}
template<class T>
inline Node<T>* BST<T>::insert(T d, Node<T>* tmp)
{
	if (tmp == NULL) {
		size++;
		tmp = new Node<T>(d);
	}
	else if (d < tmp->getData()) {
		tmp->setLeft(insert(d, tmp->getLeft()));
		tmp->getLeft()->setParent(tmp);
		if (high(tmp->getLeft()) - high(tmp->getRight()) == 2)
		{
			if (d < tmp->getLeft()->getData())
				tmp = ll_rightRotation(tmp);
			else
				tmp = lr_doubleRightRotation(tmp);
		}
	}
	
	else if (d > tmp->getData())
	{
		tmp->setRight(insert(d, tmp->getRight()));
		tmp->getRight()->setParent(tmp);
		if (high(tmp->getRight()) - high(tmp->getLeft()) == 2)
		{
			if (d > tmp->getRight()->getData())
				tmp = rr_leftRotation(tmp);
			else
				tmp = rl_doubleLeftRotation(tmp);
		}
	}
	return tmp;
}

template<class T>
inline Node<T>* BST<T>::ll_rightRotation(Node<T>* t)
{
	Node<T>* u = t->getLeft();
	
	t->setLeft(u->getRight());

	if (u->getRight())
		u->getRight()->setParent(t);

	u->setRight(t);
	t->setParent(u);
	
	return u;
}

template<class T>
inline Node<T>* BST<T>::rr_leftRotation(Node<T>* t)
{
	Node<T>* u = t->getRight();
	
	t->setRight(u->getLeft());
	
	if (u->getLeft())
		u->getLeft()->setParent(t);
	
	u->setLeft(t);
	t->setParent(u);
	
	return u;
}

template<class T>
inline Node<T>* BST<T>::rl_doubleLeftRotation(Node<T>* tmp)
{
	tmp->setRight(ll_rightRotation(tmp->getRight()));
	return rr_leftRotation(tmp);
}

template<class T>
inline Node<T>* BST<T>::lr_doubleRightRotation(Node<T>* tmp)
{
	tmp->setLeft(rr_leftRotation(tmp->getLeft()));
	return ll_rightRotation(tmp);
}

template<class T>
inline bool BST<T>::balanceFactor(T tmp)
{
	Node<T>* toCheck = search(tmp);
	if (!tmp) return false;
	
	int left = high(toCheck->getLeft());
	int right = high(toCheck->getRight());
	if (left - right == 1 || left - right == -1 || left - right == 0)
		return true;
	else
		return false;
}

template<class T>
inline void BST<T>::setSize(int s)
{
	size = s;
}

template<class T>
inline int BST<T>::getSize()
{
	return size;
}

template<class T>
inline void BST<T>::levelOrder(Node<T>* tmp)
{
	int h = high(tmp);
	for (int i = 1; i <= h + 1; i++)
	{
		createlevelOrder(tmp, i);
		cout << endl;
	}
}

template<class T>
inline void BST<T>::createlevelOrder(Node<T>* tmp, int level)
{
	if (tmp == NULL)
		return;
	if (level == 1)
		cout << tmp->getData() << " ";
	else if (level > 1)
	{
		createlevelOrder(tmp->getLeft(), level - 1);
		createlevelOrder(tmp->getRight(), level - 1);
	}
}
template<class T>
inline void BST<T>::successor(T val)
{
	levelOrder(search(val));
}
template<class T>
inline void BST<T>::mirror(Node<T>* tmp1, BST<T>* tmp2)
{
	if (!tmp1) return;

	Node<T>* node = new Node<T>(tmp1->getData());
	if (tmp2->getRoot() == NULL) {
		tmp2->setRoot(node);
	}
	else {
		Node<T>* temp = tmp2->getRoot();
		while (temp != NULL)
		{
			if (temp->getData() > tmp1->getData())
			{
				if (temp->getRight() == NULL)
				{
					temp->setRight(node);
					node->setParent(temp);
					break;
				}
				temp = temp->getRight();
			}
			else if (temp->getData() < tmp1->getData())
			{
				if (temp->getLeft() == NULL)
				{
					temp->setLeft(node);
					node->setParent(temp);
					break;
				}
				temp = temp->getLeft();
			}
			else
			{
				break;
			}
		}
	}
	
	mirror(tmp1->getLeft(), tmp2);
	mirror(tmp1->getRight(), tmp2);
}
template<class T>
inline void BST<T>::predecessor(T val)
{
	Node<T>* tmp = search(val);
	do {
		cout << tmp->getParent()->getData() << " ";
		tmp = tmp->getParent();
	} while (tmp->getParent() != NULL);
}

template<class T>
inline T BST<T>::parentDisplay(T val)
{
	Node<T>* tmp = search(val);
	return tmp->getParent()->getData();
}


template<class T>
inline void BST<T>::allInterDisplay(Node<T>* tmp)
{
	if (!tmp) return;

	if ((tmp->getLeft() || tmp->getRight()) && tmp != root)
		cout << tmp->getData() << " ";
	allInterDisplay(tmp->getLeft());
	allInterDisplay(tmp->getRight());
}



template<class T>
inline void BST<T>::allLeafsDisplay(Node<T>* tmp)
{
	if (!tmp) return;

	if (!tmp->getLeft() && !tmp->getRight())
		cout << tmp->getData() << " ";
	allLeafsDisplay(tmp->getLeft());
	allLeafsDisplay(tmp->getRight());
}


template<class T>
inline int BST<T>::high(Node<T>* tmp)
{
	if (tmp == NULL)	return -1;

	int lft = high(tmp->getLeft());
	int rht = high(tmp->getRight());
	if (lft < rht)
	{
		return rht + 1;
	}
	return lft + 1;
}

template<class T>
inline bool BST<T>::remove(T toFind) 
{
	return del(search(toFind));
}

template<class T>
inline bool BST<T>::del(Node<T>* toDel)
{
	if (!toDel) return false;

	// Case 1: leaf node.
	if (!toDel->getLeft() && !toDel->getRight()) {
		if (root == toDel) root = NULL;
		else if (toDel->getParent()->getLeft() == toDel) {
			toDel->getParent()->setLeft(NULL);
		}
		else {
			toDel->getParent()->setRight(0);
		}
	}

	// Case 2: both childs
	else if (toDel->getLeft() && toDel->getRight()) {
		Node<T>* maxNode = new Node<T>(this->maxx(toDel->getLeft()));
		int v = maxNode->getData();
		this->del(maxNode);
		toDel->setData(v);
		toDel = NULL;
	}

	// Case 3: one child
	else if (toDel->getLeft() || toDel->getRight()) {
		Node<T>* toShift = toDel->getLeft() ? toDel->getLeft() : toDel->getRight();

		if (root == toDel) {
			root = toShift;
		}

		Node<T>* futureParent = toDel->getParent();

		if (futureParent) {
			if (futureParent->getLeft() == toDel) {
				futureParent->setLeft(toShift);
			}
			else if (futureParent->getRight() == toDel) {
				futureParent->setRight(toShift);
			}
		}
		else {
			toShift->setParent(NULL);
		}
	}
	return true;
}





template<class T>
inline void BST<T>::setRoot(Node<T>* r)
{
	root = r;
}

template<class T>
inline Node<T>* BST<T>::getRoot()
{
	return root;
}

template<class T>
inline Node<T>* BST<T>::search(T d)
{
	if (root == NULL) {
		return NULL;
	}
	else {
		Node<T>* temp = root;
		while (temp != NULL)
		{
			if (temp->getData() < d)
			{
				if (temp->getRight() == NULL)
				{
					return NULL;
				}
				temp = temp->getRight();
			}
			else if (temp->getData() > d)
			{
				if (temp->getLeft() == NULL)
				{
					return NULL;
				}
				temp = temp->getLeft();
			}
			else
			{
				return temp;
			}
		}
	}
}

template<class T>
inline T BST<T>::maxx(Node<T>* tmp)
{
	if (tmp == NULL)
	{
		return T();
	}
	while (tmp != NULL)
	{
		if (tmp->getRight() == NULL)
		{
			return tmp->getData();
		}
		tmp = tmp->getRight();
	}
	return T();
}

template<class T>
inline T BST<T>::minn(Node<T>* tmp)
{
	if (tmp == NULL)
	{
		return T();
	}
	while (tmp != NULL)
	{
		if (tmp->getLeft() == NULL)
		{
			return tmp->getData();
		}
		tmp = tmp->getLeft();
	}
	return T();
}

template<class T>
inline void BST<T>::walkInOrder(Node<T>* tmp)
{
	if (tmp == NULL)
	{
		return;
	}

	walkInOrder(tmp->getLeft());
	cout << tmp->getData() << " ";
	walkInOrder(tmp->getRight());
}

template<class T>
inline void BST<T>::walkPreOrder(Node<T>* tmp)
{
	if (tmp == NULL)
	{
		return;
	}

	cout << tmp->getData() << " ";
	walkPreOrder(tmp->getLeft());
	walkPreOrder(tmp->getRight());
}

template<class T>
inline void BST<T>::walkPostOrder(Node<T>* tmp)
{
	if (tmp == NULL)
	{
		return;
	}

	walkPostOrder(tmp->getLeft());
	walkPostOrder(tmp->getRight());
	cout << tmp->getData() << " ";
}


template<class T>
inline T BST<T>::sum(Node<T>* tmp)
{
	if (tmp == NULL)
	{
		return T();
	}
	return sum(tmp->getLeft()) + tmp->getData() + sum(tmp->getRight());
}

template <class T>
BST<T>::~BST()
{
}
