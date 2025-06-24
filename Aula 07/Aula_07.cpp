#include <iostream>

using namespace std;

// Definição de uma estrutura de nó para uma lista encadeada
struct Node {
    int info;
    int key;
    Node* next;
};

#define SIZE 3 //Tamanho da tabela hash
Node* ht[SIZE]; // Tabela hash

void printTable(){
    Node* aux;
    cout << "Tabela Hash:" << endl;
    cout << "------------------------" << endl;

    for(int i = 0; i < SIZE; i++) {
        cout << "[*] -> ";
        aux = ht[i];
        while (aux != nullptr) { 
            cout << "(" << aux->key << ", " << aux->info << ") -> ";
            aux = aux->next;
        }
        cout << "NULL" << endl;
    }
    cout << "------------------------" << endl;
}

void iniTablet(){
    for(int i = 0; i < SIZE; i++) {
        ht[i] = nullptr; // Inicializa a tabela hash com ponteiros nulos
    }
}

int hFunction(int key) {
    return key % SIZE; // Função hash simples que retorna o índice baseado na chave
}

void insert(Node* node){
    int index = hFunction(node->key); // Calcula o índice usando a função hash
    Node* atual;
    // Verifica se o índice já está ocupado
    if(ht[index] == nullptr) {
        ht[index] = node; // Insere o nó na tabela hash no índice calculado
    } else {
        atual = ht[index];
        while (atual->next != nullptr) {
            atual = atual->next; // Percorre a lista encadeada até o final
        }
        atual->next = node; // Insere o novo nó no final da lista encadeada
    }
}
    

int main(){
    iniTablet(); // Inicializa a tabela hash

    printTable(); // Imprime a tabela hash antes de inserir os nós

    // Criação de nós para a lista encadeada
    Node* n1 = new Node {0, 1, nullptr};
    Node* n2 = new Node {1, 2, nullptr};
    Node* n3 = new Node {2, 3, nullptr};
    Node* n4 = new Node {3, 4, nullptr};
    Node* n5 = new Node {4, 5, nullptr};
    Node* n6 = new Node {5, 6, nullptr};
    Node* n7 = new Node {6, 7, nullptr};

    // Insere os nós na tabela hash
    insert(n1);
    insert(n2);
    insert(n3);


    printTable(); // Imprime a tabela hash

    insert(n4);
    insert(n5);
    insert(n6);
    insert(n7);

    printTable(); // Imprime a tabela hash após inserir mais nós

    return 0;
}
