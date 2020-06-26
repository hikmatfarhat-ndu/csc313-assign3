#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <exception>
#include <stdexcept>
template<typename Tk, typename Tv>
struct Node {
	std::pair<Tk,Tv> _myval;
	Node* parent;
	Node* left;
	Node* right;
	char is_nil = 0;
	Node(Tk k, Tv v, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr)
		:_myval(k,v), parent(p), left(l), right(r) ,is_nil(0){}
};

template<typename Tk, typename Tv>
class map {
private:
	Node<Tk, Tv>* head;
	void insert(Node<Tk, Tv>*&, std::pair<Tk, Tv>);
	void inorder(const Node<Tk, Tv>*,std::ostream&);
	Node<Tk, Tv>* findMin(Node<Tk, Tv>*);
	Node<Tk, Tv>* findMax(Node<Tk, Tv>*);
	Node<Tk, Tv>* find(Tk, Node<Tk, Tv>*);
	void erase(Node<Tk, Tv>* &, Tk);

public:
	// Implement the iterator class here

	class iterator {
		map<Tk, Tv>* _mymap;
		Node<Tk, Tv>* _current;

	public:

		iterator(map<Tk, Tv>* mymap,Node<Tk,Tv>* node) :_mymap(mymap),_current(node) {}
		iterator operator++() {
			_current = _mymap->next(_current);
			return *this;
		}
		iterator operator++(int v) {
			_current = _mymap->next(_current);
			return *this;
		}
		iterator operator--() {
			_current = _mymap->prev(_current);
			return *this;
		}
		iterator operator--(int v) {
			_current = _mymap->prev(_current);
			return *this;
		}
		std::pair< Tk,Tv>* operator->() {
			return std::addressof(_current->_myval);
		}
		std::pair<Tk, Tv>& operator*() {
			
			return _current->_myval;
		}
		bool operator==(const iterator& rhs) {
			return _current == rhs._current;
		}
		bool operator!=(const iterator& rhs) {
			return _current != rhs._current;
		}

	};
	map() {
		head = new Node<Tk, Tv>(Tk{}, Tv{});
		head->is_nil = 1;
		head->parent = head;
		head->left = head;
		head->right = head;
	}
	void insert(std::pair<Tk, Tv>);
	std::string inorder();
	void erase(Tk);
	Node<Tk, Tv>* next(Node<Tk, Tv>* t);
	Node<Tk, Tv>* prev(Node<Tk, Tv>* t);
	//notice the dummy integer to distinguish
	// between begin that returns a node* and the 
	// one that returns an iterator. The same for end
	Node<Tk, Tv>& operator[](Tk );
	Node<Tk, Tv>* begin();
	map<Tk,Tv>::iterator begin(int);
	Node<Tk, Tv>* end();
	map<Tk, Tv >::iterator end(int);
	iterator find(Tk);
	Tv& operator[](Tk);
};


template <typename Tk,typename Tv>
Tv & map<Tk, Tv>::operator[](Tk key) {
	Node<Tk,Tv>* res=find(key,head->parent);
	return (res->_myval).second;
}
template<typename Tk, typename Tv>
Node<Tk,Tv>* map<Tk, Tv>::find(Tk key,Node<Tk,Tv>* t) {
	if (t == nullptr) return head;
	if (key == t->_myval.first)return t;
	else if (key < t->_myval.first)return find(key,t->left);
	else return find(key,t->right);

}
template<typename Tk,typename Tv>
typename map<Tk, Tv>::iterator map<Tk, Tv>::find(Tk key) {
	auto node=find(key, head->parent);
	return iterator(this, node);

}
template<typename Tk, typename Tv>
void map<Tk, Tv>::inorder(const Node<Tk, Tv>* t,std::ostream& os) {

	if (t == nullptr)return;
	inorder(t->left,os);
	os << t->_myval.first << "=>";
	inorder(t->right,os);

}


// begin that returns a node pointer. Don't change
template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::begin() {
	return head->left;
}

// end that returns a node pointer. Don't change
template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::end() {
	return head;
}

template<typename Tk, typename Tv>
void map<Tk, Tv>::insert(Node<Tk, Tv>*& t, std::pair<Tk, Tv> p) {
	if (t == nullptr) {
		std::cout << "error\n"; return;
	}
	if (p.first > t->_myval.first) {
		if (t->right == nullptr) {
			t->right = new Node<Tk, Tv>(p.first, p.second, t);
			if (head->right == t)head->right = t->right;
		}
		else insert(t->right, p);

	}
	else {
		if (t->left == nullptr) {
			t->left = new Node<Tk, Tv>(p.first, p.second, t);
			if (head->left == t)head->left = t->left;
		}
		else insert(t->left, p);

	}
}


//This is the public insert.Don't change
template<typename Tk, typename Tv>
void map<Tk, Tv>::insert(std::pair<Tk, Tv> v) {
	if (head->parent == head) {
		head->parent = new Node < Tk, Tv>(v.first, v.second, head);
		head->left = head->parent;
		head->right = head->parent;
	}
	else insert(head->parent, v);
}


template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::findMin(Node<Tk, Tv>* t) {
	if (t==nullptr || t->left == nullptr) return t;
	else return findMin(t->left);

}

template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::findMax(Node<Tk, Tv>* t) {
	if (t==nullptr || t->right == nullptr) return t;
	else return findMax(t->right);

}
template <typename Tk,typename Tv>
bool constexpr is_leaf(Node<Tk, Tv>*& t) {
	if (t->left == nullptr && t->right == nullptr)
		return true;
	else return false;
}

	template <typename Tk, typename Tv>
	void map<Tk, Tv>::erase(Node<Tk, Tv>*& t, Tk key) {

		if (t == nullptr) return;

		if (t->_myval.first < key)erase(t->right, key);
		else if (t->_myval.first > key) erase(t->left, key);
		// found the node
		//if it has two children
		else if (t->left != nullptr && t->right != nullptr) {
			Node<Tk, Tv>* min = findMin(t->right);
			t->_myval = min->_myval;
			erase(t->right, min->_myval.first);
		}
		//if it has at most one  child
		else {
			Node<Tk, Tv>* old = t;
			if (t->left != nullptr) {
				t->left->parent = t->parent;

			}
			if (t->right != nullptr) {
				t->right->parent = t->parent;
			}
			t = (t->left != nullptr) ? t->left : t->right;
			if (head->left == old)head->left = findMin(head->parent);
			if (head->right == old) head->right = findMax(head->parent);
			delete old;
		}

	}


template <typename Tk, typename Tv>
void map<Tk, Tv>::erase(Tk key) {
	// head->parent is the root of the tree
	erase(head->parent, key);
}
//This is the public inorder. Don't change
template<typename Tk, typename Tv>
std::string map<Tk, Tv>::inorder() {
	std::stringstream ss;
	//head->parent is the root of the tree
	inorder(head->parent,ss);
	return ss.str();
}

