#include "./Heap.hpp"

void bubble_up(heap_node* node){
    if (!node->parent) return;

    if (node->value > node->parent->value) {
        std::swap(node, node->parent);
        bubble_up(node->parent);
    }
}

void bubble_down(heap_node* node) {
    if (!node) return;

    heap_node* largest = node;

    if (node->right && node->right->value > largest->value) {
        largest = node->right;
    } else if (node->left && node->left->value > largest->value) {
        largest = node->left;
    }else return;

    std::swap(largest -> value, node -> value);
    bubble_down(largest);
}

void insert_in_mheap(heap_node*& root, int value) {
    heap_node* new_node = new heap_node(value);

    if (root) {
        std::queue<heap_node*> node_queue;
        node_queue.push(root);

        while (!node_queue.empty()) {
            heap_node* current = node_queue.front();

            if (!current->left) {
                current->left = new_node;
                new_node->parent = current;
                bubble_up(new_node);
                return;
            } else {
                node_queue.push(current->left);
            }

            if (!current->right) {
                current->right = new_node;
                new_node->parent = current;
                bubble_up(new_node);
                return;
            } else {
                node_queue.push(current->right);
            }

            node_queue.pop();
        }
    } else{
        root = new_node;
    }
}

heap_node* find_in_mheap(heap_node*& node, int val){
    if(!node) return nullptr;
    if(node->value < val) return nullptr;
    if(node->value == val) return node;

    heap_node* left_node = find_in_mheap(node -> left, val);
    if(left_node) return left_node;
    return find_in_mheap(node -> right, val);
}

heap_node* last_node(heap_node* root) {
    std::queue<heap_node*> q;
    q.push(root);

    heap_node* last = nullptr;
    while (!q.empty()) {
        last = q.front();
        q.pop();

        if (last->left) q.push(last->left);
        if (last->right) q.push(last->right);
    }
    return last;
}

void delete_from_mhead(heap_node*& root, int val){
    heap_node* to_delete = find_in_mheap(root, val);
    if(!to_delete){
        std::cout << "no value " << val << " to delete." << "\n";
        return;
    }
    heap_node* last = last_node(root);
    to_delete -> value = last -> value;
    
    if (last->parent){
        if (last->parent->left == last) {
            last->parent->left = nullptr;
        } else {
            last->parent->right = nullptr;
        }
    }
    delete last;

    bubble_down(to_delete);
}