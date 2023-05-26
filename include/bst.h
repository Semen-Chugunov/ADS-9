// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int c;
        Node* left, * right;
    };
    Node* rt;
    Node* addNode(Node* rt, const T& value) {
        if (rt == nullptr) {
            rt = new Node;
            rt->value = value;
		rt->left =  nullptr;
		rt->right = nullptr;
            rt->c = 1;
	  } else if (rt->value < value) {
            rt->right = addNode(rt->right, value);
        } else if (rt->value > value) {
            rt->left = addNode(rt->left, value);
        } else {
            rt->c += 1;
        }
        return rt;
    }
    Node* searchNode(Node* rt, const T& value) {
        if (rt == nullptr || rt->value == value) 
		return rt;
        if (value < rt->value) 
		return searchNode(rt->left, value);
        return searchNode(rt->right, value);
    }
    int getDepth(Node* rt) {
        if (rt == nullptr) return 0;
        return std::max(getDepth(rt->left), getDepth(rt->right));
    }

 public:
    BST() : rt(nullptr) {}
    int depth() {
        return getDepth(rt);
    void add(const T& value) {
        rt = addNode(rt, value);
    }
    int search(const T& value) {
       Node* t = searchNode(rt, value);
       if (t != nullptr) return t->c;
		else return  0;
    }
};
#endif  // INCLUDE_BST_H_
