#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <queue>
#include <algorithm>

struct heap_node {
    int value;
    heap_node* left = nullptr;
    heap_node* right = nullptr;
    heap_node* parent = nullptr;

    heap_node(int val) : value(val) {}
};

#endif // HEAP_HPP

