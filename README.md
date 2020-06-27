# CSC 313 programming assignment 3

You are to implement a `map` data structures similar to `std::map`. You can use the `bst` class found in the file `bst.h` in the __inclass__ repository [here](https://github.com/NDU-CSC313/inclass.git) since it implements many of the required methods, all you need is to modify them. Note that `std::map` is implemented as a __balanced__ binary search tree (red black tree) but this assignment does not require the bst to be balanced. An important difference between `bst` and `map` is that map takes two types as parameters: the _key_ and the _value_. The ordering of the nodes is based on the _key_. Please review our usage of `std::map`. The nodes in the map contain more members than the ones in the bst. First each node has a pointer to its parent and there is a member to denote whether the node is nill or not. The only nill node is the __head__. The __head__ is a sentinel node that contains no value. An empty map contains one node the __head__. This special node is used to denote the end of the map when we iterate over it. When the map contains nodes with values the __head__ and root are both parents of each other. Furthermore, the left node of __head__ is the first node in the _inorder_ traversal and the right is the last node in the _inorder_ traversal. When we iterate over the elements of the map we start with the first node and stop when we reach the __head__. 

## part one
Implement the methods
1. insert
1. erase

You should take care that the version of begin that take a dummy value, just to distinguish it from the one that return an iterator, will work properly. For example, the 
implementation of begin below (which you must not change) the left of head must be the
"smallest" element. So once you insert or erase an element make sure to update head->left, head->right. Also since head->parent is the root if the root is added or delete ensure that
head->parent points to the right node.
```
template<typename Tk, typename Tv>
Node<Tk, Tv>* map<Tk, Tv>::begin(int d) {
	return head->left;
}
```

## part two
implement the methods
1. next
1. prev

Where `next`  and `prev` return a pointer to the "next" and "previous" nodes respectively. The meaning of next and previous is the next and previous "in order". For example, if your map stores the values (regardless of the order) {17,8,7,12,5} then
1. next of 5 is 7 and next of 7 is 8 etc
1. prev of 17 is 12 and prev of 12 is 8.

Note that the next of the last element is head and the previous of head is the last element.

## part three
implement
1. iterator operators: ++,--,*,->,!=

## part four
Implement the indexing operator. The code below should work with your implementation
```
map<std::string,int> m;
m.insert({"one",1});
m["two"]=2;
m["one"]=11;
Node<std::string,int>* itr=m.begin(10);//10 is dummy value
while(itr!=m.end(10))
  std::cout<<itr->_myval.first<<","<<itr->_myval.second<<std::endl;
```
the output should be
```
one,11
two,2
```


