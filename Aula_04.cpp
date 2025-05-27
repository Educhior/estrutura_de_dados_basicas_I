#include <iostream>

using namespace std;

struct Node{ // Definindo a estrutura do nó
    int data;
    Node* next;
    Node* prev;
};

Node* build(); // Função para construir a lista duplamente encadeada
void printList(Node* L); // Função para imprimir a lista
void insertionSort(Node* L); // Função para ordenar a lista (não implementada)

int main() {
    cout << "Hello, World!" << endl;
    cout << endl;
    Node* head = build(); // Construindo a lista duplamente encadeada
    printList(head); // Imprimindo a lista
    insertionSort(head); // Chamando a função de ordenação (não implementada)

    return 0;
}

void insertionSort(Node* L) {
    if(L->next == nullptr || L == nullptr) { // Verifica se a lista está vazia ou tem apenas um nó
        cout << "Lista vazia ou com apenas um nó" << endl;
        return; // Retorna se a lista estiver vazia ou tiver apenas um nó
    }

    Node* o = L->next; // Inicializando o nó o com o próximo do head

    while (o->next != nullptr) { // Enquanto o próximo nó de o não for nulo
        Node* d = o->next; // Inicializando o nó d com o próximo de o
        Node* t = o; // Inicializando o nó t com o nó o

        while (t->data > d->data && t->prev != nullptr) { // Enquanto o valor de t for maior que o de d e t não for o head
            t = t->prev; // Move t para o nó anterior enquanto o valor de t for maior que d
        }
    }

    Node* o = L->next; // Inicializando o nó o com o próximo do head
    Node* d = o->next; // Inicializando o nó d com o próximo de o
    
    cout << o->data << " " << d->data << endl; // Imprimindo os dados dos nós o e d
}

void printList(Node* L) {
    cout << "L "; // Imprimindo a lista
    while (L != nullptr) { // Enquanto houver nós na lista
        if (L->prev == nullptr) {
            cout << "-|> h"; // Imprime se o nó anterior for nulo
        } else {
            cout << " <=> " << L->data; // Imprime o valor do nó atual
        }
        L = L->next; // Avança para o próximo nó
    }
    cout << " -> NULL" << endl;
}

Node* build() {
    Node* head = new Node; // Criando o primeiro nó
    head->next = nullptr; // Inicializando o próximo nó como nulo
    head->prev = nullptr; // Inicializando o nó anterior como nulo

    Node* n1 = new Node; // Criando o segundo nó
    head->next = n1; // Ligando o primeiro nó ao segundo
    n1->prev = head; // Ligando o segundo nó ao primeiro
    n1->data = 2; // Atribuindo valor ao segundo nó

    Node* n2 = new Node; 
    n1->next = n2; 
    n2->prev = n1; 
    n2->data = 6;

    Node* n3 = new Node;
    n2->next = n3;
    n3->prev = n2;
    n3->data = 5;

    Node* n4 = new Node;
    n3->next = n4;
    n4->prev = n3;
    n4->data = 3;

    Node* n5 = new Node;
    n4->next = n5;
    n5->prev = n4;
    n5->data = 4;

    Node* n6 = new Node;
    n5->next = n6;
    n6->prev = n5;
    n6->data = 1;
    n6->next = nullptr; // O último nó aponta para nulo
    
    return head;
}