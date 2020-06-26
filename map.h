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
	// Implement the iterator class here

	class iterator {
		map<Tk, Tv>* _mymap;
		Node<Tk, Tv>* current;
	public:
		iterator(map<Tk, Tv>* mymap, Node<Tk, Tv>* node)
			:_mymap(mymap), current(node) {}
		//implement here the usual operators 
		// for the iterator, i.e.: ++,--, ==,!=,*,->
	};
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

// Takes a dummy interger as input
// to distinguish it from begin that returns
// a node pointer. Don't change
template<typename Tk,typename Tv>
typename map<Tk, Tv>::iterator map<Tk,Tv>::begin(int v) {
	return iterator(this,head->left);
}
// Takes a dummy interger as input
// to distinguish it from end that returns
// a node pointer. Don't change
template<typename Tk, typename Tv>
typename map<Tk, Tv>::iterator map<Tk,Tv>::end(int v) {
	return iterator(this, head);
}

//implement this method
template<typename Tk,typename Tv>
void map<Tk,Tv>::insert(Node<Tk, Tv>*&, std::pair<Tk, Tv>) {
	//TODO: write your code here

}


//implement this method
template<typename Tk,typename Tv>
Node<Tk, Tv>* map<Tk,Tv>::findMin(Node<Tk, Tv>*) {
	//TODO: write you code here
	//Obviously replace head
	return head;
}
//implement this method
template <typename Tk,typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::findMax(Node<Tk, Tv>*) {
	//TODO: write your code here. 
	//Obviously replace head
	return head;
}
//implement this method
template <typename Tk, typename Tv>
void map<Tk,Tv>::erase(Node<Tk, Tv>*&, Tk) {
   //TODO: write your code here
}

//given a node pointer t returns the pointer
// to the next node in the inorder traversal
//implement this method
template <typename Tk,typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::next(Node<Tk, Tv>* t) {
	//TODO: write your code here
	//obviously replace head
	return head;
}
//given a node pointer t returns the pointer
// to the previous node in the inorder traversal
//implement this method
template <typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk,Tv>::prev(Node<Tk, Tv>* t) {
	//TODO: write your code here
	//obviously replace head
	return head;
}

//prints the inorder traversal to
//the chosen output stream
// Don't change
template<typename Tk, typename Tv>
void map<Tk, Tv>::inorder(const Node<Tk, Tv>* t,std::ostream& os) {

	if (t == nullptr)return;
	inorder(t->left,os);
	os << t->key << "=>";
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

//This is the public insert.Don't change
template<typename Tk, typename Tv>
void map<Tk, Tv>::insert(std::pair<Tk, Tv> v) {
	if (head->parent == nullptr) {
		head->parent = new Node < Tk, Tv>(v.first, v.second, head);
		head->left = head->parent;
		head->right = head->parent;
	}
	else insert(head->parent, v);
}

// This is the public erase. Don't change
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

