// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
template < typename T >
class BST {
  friend BST<std::string> makeTree(const char*);
 public:
    struct Node {
      T value;
      int count;
      Node *left;
      Node *right;
    };
 private:
    Node *root;
    Node *addNode(Node *, const T&);
    int depthTree(Node *);
    int searchNode(Node *, const T&);
    void delTree(Node *);
 public:
    BST();
    ~BST();
    void add(const T&);
    int depth();
    int search(T);
};
template <typename T>
BST <T>::BST() : root(nullptr) { }
template <typename T>
BST <T>::~BST() {
    if (root) {
        delTree(root);
    }
}
template < typename T >
typename BST <T>::Node *BST <T>::addNode(Node *root , const T &value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (strcmp(root->value.c_str(), value.c_str()) > 0) {
        root->left = addNode(root->left , value);
    } else if (strcmp(root->value.c_str(), value.c_str()) < 0) {
        root->right = addNode(root->right, value);
    } else {
         root->count++;
    }
    return root;
}
template <typename T>
void BST <T>::add(const T &value) {
  root = addNode(root, value);
}
template <typename T>
void BST <T>::delTree(Node *root) {
  if (root == nullptr) {
    return;
  } else {
      delTree(root->left);
      delTree(root->right);
      delete root;
  }
}
template <typename T>
int BST<T>::depthTree(Node *root) {
  BST<std::string> tree;
  if (nullptr == root) {
    return 0;
  } else {
      int l = depthTree(root->left);
      int r = depthTree(root->right);
      if (l > r) {
        return ++l;
      } else {
          return ++r;
      }
  }
}
template <typename T>
int BST<T>::depth() {
  return depthTree(root);
}
template <typename T>
int BST<T>::searchNode(Node *root, const T& val) {
  if (nullptr == root) {
    return 0;
  } else if ((strcmp(root->value.c_str(), val.c_str()) == 0)) {
      return root->count;
  } else if ((strcmp(root->value.c_str(), val.c_str()) > 0)) {
      return searchNode(root->left, val);
  } else {
      return searchNode(root->right, val);
  }
}
template <typename T>
int BST<T>::search(T value) {
  return searchNode(root, value);
}

#endif  // INCLUDE_BST_H_
