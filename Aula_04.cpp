#include <iostream>

using namespace std;

struct Node{ // Definindo a estrutura do nó
    int data;
    Node* next;
    Node* prev;
};

Node* build(); // Função para construir a lista duplamente encadeada

int main() {
    cout << "Hello, World!" << endl;
    cout << endl;
    Node* head = build(); // Construindo a lista duplamente encadeada

    return 0;
}

Node* build() {
    Node* head = new Node; // Criando o primeiro nó
    head->next = nullptr; // Inicializando o próximo nó como nulo
    head->prev = nullptr; // Inicializando o nó anterior como nulo

    Node* n1 = new Node; // Criando o segundo nó

    return head;
}