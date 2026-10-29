#include <iostream>
#include <string>
#include <vector>
using namespace std;

void insertionSort(vector<string>& arr){
    
    for(int i =1; i < arr.size(); i++){
        string temp = arr[i];
        int j = i - 1;
        
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;

            for(string& k : arr){
                cout << k << " ";
            }
            cout << endl;
            
        }
        arr[j+1] = temp;
        
        for(string& k : arr){
                cout << k << " ";
        }
        cout << endl;
    }
}



int main(){
    vector<string> kata;
    
    int jumlah;
    cout<< "mau masukan berapa kata: "; cin >> jumlah;
    
    for(int i = 0; i < jumlah; i++){
        string inputKata;
        cout << "masukkan kata ke "<< i <<" : "; cin >> inputKata;
        kata.push_back(inputKata);
    }
    
    
    insertionSort(kata);

    //sesudah sort
    for(string& k : kata){
        cout << k << " ";
    }
}

