#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* build123();
void print_List(Node* L);
void pop_front(Node* &H);
void pop_back(Node* &H);
Node* get_prev_last(Node* L);
void pop_at(Node* &H, int idx);
int size_list(Node* L);
Node* get_prev(Node* L, int idx); // Function to get the previous node of the node at index idx

int main(){
    Node* L = build123();
    print_List(L);
    pop_front(L);
    print_List(L);
    pop_back(L);
    print_List(L);
    pop_at(L, 1);
    print_List(L);
    return 0;
}

void pop_at(Node* &H, int idx){ 
    if (H == nullptr || idx > size_list(H) || idx < 0) return; // Check if the list is empty or if the index is out of bounds
    

}

Node* get_prev(Node* L, int idx){
    if (inx>size_list(L) || idx < 0) return nullptr;
}

int size_list(Node* L){
    int cont = 0;
    while(L != nullptr){
        cont++;
        L = L->next;
    }
    return cont;
}

Node* get_prev_last(Node* L){
    if (L == nullptr || L->next == nullptr) return nullptr;
    Node* anterior = nullptr;
    Node* atual = L;
    while(atual->next != nullptr){
        anterior = atual;
        atual = atual->next;
    }
    return anterior;
}

void pop_back(Node* &H){
    if (H == nullptr) return;
    if (H->next == nullptr) {
        delete H;
        H = nullptr;
        return;
    }
    Node* prev = get_prev_last(H);
    Node* target = prev->next;
    prev->next = nullptr;
    delete target;
}

void pop_front(Node* &H){
    if (H == nullptr){
        return;
    }  
    Node* target = H;
    H = H->next;

    delete target;
}

void print_List(Node* L){
    cout << " * => ";
    while(L != nullptr){
        cout << L->data << " => ";
        L = L->next;
    }
    cout << "NULL" << endl;
}

Node* build123(){
    Node* n1 = new Node();
    n1->data = 1;
    n1->next = nullptr;

    Node* n2 = new Node();
    n2->data = 2;
    n2->next = nullptr;

    Node* n3 = new Node();
    n3->data = 3;
    n3->next = nullptr;

    Node* n4 = new Node();
    n4->next = nullptr;
    n4->data = 4;
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    return n1;
}