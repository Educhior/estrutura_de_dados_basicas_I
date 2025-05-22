#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* build123();
void print_List(Node* L);
void pop_front(Node* $H);
void pop_back(Node* $H);
Node* get_prev_last(Node* L);

int main(){
    Node* L = build123();
    print_List(L);
    pop_front(L);
    print_List(L);
    pop_back(L);
    print_List(L);
    return 0;
}

Node* get_prev_last(Node* L){
    if (L == nullptr){
      return nullptr;
    }
    Node* anterior = new Node();
    anterior = nullptr;
    Node* atual = new Node();
    atual = L;
    Node* frente = new Node();
    frente = L->next;

    while(frente != nullptr){
        anterior = atual;
        atual = frente;
        frente = frente->next;    
    }
    return anterior;
}

void pop_back(Node* $H){
    if (H == nullptr){
        return;
    }
    Node* prev = get_prev_last(H);
    prev = prev->next;
    
}

void pop_front(Node* $H){
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
};