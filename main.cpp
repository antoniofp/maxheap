#include "./Heap.hpp"
#include "./InsertAndDelete.cpp"
using namespace std;

int main(){
    heap_node* root =nullptr;
    insert_in_mheap(root, 30);
    insert_in_mheap(root, 15);
    insert_in_mheap(root, 2);
    insert_in_mheap(root, 10);
    insert_in_mheap(root, 25);
    insert_in_mheap(root, 20);

    cout<<"El valor maximo del heap es: "<< find_max(root)<<endl;
    cout<<"El valor minimo del heap es: "<< find_min(root)<<endl;
    return 0;
}