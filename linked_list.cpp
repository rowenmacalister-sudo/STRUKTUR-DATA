#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

int jlh;

void insertNode(node*& head ,int nilai){
        node* Node = new node();
        Node -> data = nilai;
        Node -> next = nullptr;

        if(head == nullptr){
            head = Node;
            return;
        }

        node* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }

        node* tail = temp;
        tail -> next = Node;
        
}

void tmbh_dpn(node*& head, int nilai){
    node* Node = new node();
    Node -> data = nilai;
    Node -> next = head;
    head = Node;
}

void tmbh_tngh(node*& head, int cari, int nilai){
    node* temp = head;
    while(temp -> next-> data != cari){
        temp = temp -> next;
    }
    node* Node = new node();
    Node -> data = nilai;
    Node -> next = temp -> next;
    temp -> next = Node;
}

void hapus_tngh(node*& head, int hps){
    node* temp = head;
    while(temp ->next -> data != hps){
        temp = temp -> next;
    }
    node* hapus = temp -> next;
    temp -> next = hapus -> next;
    delete hapus;
}

void display(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int main(){

    cout << "masukkan jumlah data yang ingin di masukkan ke linked list: "<< endl; cin >> jlh;

    node* head = nullptr;
    int pilih;
    int j = 0;
    while(true){
        if(j == jlh){
            break;
        }
        j++;
        cin >> pilih;
        insertNode(head ,pilih);
    }

    display(head);

    cout << "tambah depan: ";
    tmbh_dpn(head, 90);
    display(head);
    cout << endl;


    cout << "tambah belakang: ";
    insertNode(head, 70);
    display(head);
    cout << endl;

    cout << "tambah tengah: ";
    int cari;
    cout << "pilih setelah angka apa mau di tambah: "; cin >> cari;
    tmbh_tngh(head, cari, 0);
    display(head);
    cout << endl;

    cout << "hapus tengah: ";
    int hps;
    cout << "pilih angka mana yang mau di hapus: "; cin >> hps;
    hapus_tngh(head, hps);
    display(head);
    cout << endl;

}
