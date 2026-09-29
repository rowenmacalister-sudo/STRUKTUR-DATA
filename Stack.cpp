#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
};

void tambah(Node*& top , char kata){
    Node* node = new Node();
    node -> data = kata;
    node -> next = top;
    top = node;
}

void tampilkan(Node* top){
    while (top != nullptr) {
        cout << top -> data;
        top = top -> next;
    }
}

int main(){
    char kata;
    Node* top = nullptr;
    Node* node = nullptr;

    cout << "masukkan kata (0 = stop): "; cin >> kata;

    while(kata != '0'){
        tambah(top ,kata);
        cin >> kata;
    }

    tampilkan(top);

}
