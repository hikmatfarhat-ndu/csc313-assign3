# CSC 313 programming assignment 3

You are to implement a `map` data structures similar to `std::map`. You can use the `bst` class found in the file `bst.h` in the __inclass__ repository [here](https://github.com/NDU-CSC313/inclass.git) since it implements many of the required methods, all you needis to modify them. Note that `std::map` is implemented as a __balanced__ binary search tree (red black tree) but this assignment does not require the bst to be balanced. An important difference between `bst` and `map` is that map takes two types as parameters: the _key_ and the _value_. The ordering of the nodes is based on the _key_. Please review our usage of `std::map`.
1. Modify the tree nodes to include a _key_ and _value_ instead of just a value. Also the _key_ and _value_ are not necessarily of the same type. Modify your `map` accordingly.
1. Your `map` class should contain the following method
```
template<typename Tk, typename Tv>
void map<Tk, Tv>::inorder(const Node<Tk, Tv>* t,std::ostream& os) {

	if (t == nullptr)return;
	inorder(t->left,os);
	os << t->key << "=>";
	inorder(t->right,os);

}
```
where `ostream` is an output stream, e.g. `std::cout`
1. Implement the methods

```
template <typename Tk,typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::prev(Node<Tk, Tv>* ) ;
template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::next(Node<Tk, Tv>* );

```
Where `next`  and `prev` return a pointer to the "next" and "previous" nodes respectivly. The meaning of next and previous is the next and previous "in order". For example, if your map stores the values (regardless of the order) {17,8,7,12,5} then
1. next of 5 is 7 and next of 7 is 8 etc
1. prev of 17 is 12 and prev of 12 is 8.
1. Implement 

