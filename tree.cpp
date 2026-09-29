#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* kiri;
    Node* kanan;
};

Node* tambah(Node* root, int angka){
    if(root == NULL){
        root = new Node();
        root -> data = angka;
        root -> kiri = NULL;
        root -> kanan = NULL;
        return root;
    }

    if(angka > root -> data){
        root -> kanan = tambah(root->kanan, angka);
    }

    if(angka < root-> data){
        root -> kiri = tambah(root-> kiri, angka);
    }

    return root;

}

//pre order
void preOrder(Node* root){
    if(root != NULL){
        cout << root -> data << " ";
        preOrder(root -> kiri);
        preOrder(root -> kanan);
    }
}

void inOrder(Node* root){
    if(root != NULL){
        inOrder(root-> kiri);
        cout << root -> data << "";
        inOrder(root -> kanan);
    }
}

void postOrder(Node* root){
    if(root != NULL){
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root -> data << " ";
    }
}

int main(){
    int number;
    Node* root = NULL;
    cout << "masukkan angka (0 = stop): "; cin >> number;

    while(number != 0){
        root = tambah(root, number);
        cin >> number;
    }

    preOrder(root);
    inOrder(root);
    postOrder(root);
}