#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>
#include <exception>
#include <stdexcept>
template<typename Tk, typename Tv>
struct Node {
	Tk key;
	Tv val;
	Node* parent;
	Node* left;
	Node* right;
	char is_nil = 0;
	Node(Tk k, Tv v, Node* p = nullptr, Node* l = nullptr, Node* r = nullptr)
		:key(k), val(v), parent(p), left(l), right(r) ,is_nil(0){}
};

template<typename Tk, typename Tv>
class map {
private:
	Node<Tk, Tv>* head;
	void insert(Node<Tk, Tv>*&, std::pair<Tk, Tv>);
	void inorder(const Node<Tk, Tv>*,std::ostream&);
	Node<Tk, Tv>* findMin(Node<Tk, Tv>*);
	Node<Tk, Tv>* findMax(Node<Tk, Tv>*);
	void erase(Node<Tk, Tv>*&, Tk);
public:
	
	map() {
		head = new Node<Tk, Tv>(Tk{}, Tv{});
		head->is_nil = 1;
	}
	void insert(std::pair<Tk, Tv>);
	std::string inorder();
	void erase(Tk);
	Node<Tk, Tv>* next(Node<Tk, Tv>* t);
	Node<Tk, Tv>* prev(Node<Tk, Tv>* t);
	//notice the dummy integer to distinguish
	// between begin that returns a node* and the 
	// one that returns an iterator. The same for end
	Node<Tk, Tv>* begin();
	map<Tk,Tv>::iterator begin(int);
	Node<Tk, Tv>* end();
	map<Tk, Tv >::iterator end(int);

};
template<typename Tk, typename Tv>
void map<Tk, Tv>::inorder(const Node<Tk, Tv>* t,std::ostream& os) {

	if (t == nullptr)return;
	inorder(t->left,os);
	os << t->key << "=>";
	inorder(t->right,os);

}



template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::begin() {
	return head->left;
}
template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::end() {
	return head;
}


template<typename Tk, typename Tv>
void map<Tk, Tv>::insert(std::pair<Tk, Tv> v) {
	if (head->parent == nullptr) {
		head->parent = new Node < Tk, Tv>(v.first, v.second, head);
		head->left = head->parent;
		head->right = head->parent;
	}

	else insert(head->parent, v);
}





template <typename Tk, typename Tv>
void map<Tk, Tv>::erase(Tk key) {
	erase(head->parent, key);
}
template<typename Tk, typename Tv>
std::string map<Tk, Tv>::inorder() {
	std::stringstream ss;
	inorder(head->parent,ss);
	return ss.str();
}

