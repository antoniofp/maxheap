#include "/.Heap.hpp"
#include <iostream>
using namespace std;

int height(heap_node* node) {
    if (!node) return 0;  // Si el nodo es nulo o no existe, la altura dará 0
    int left_height = height(node->left);
    int right_height = height(node->right);
    return std::max(left_height, right_height) + 1;  // Devuelve la altura máxima entre los dos subárboles más uno
}
