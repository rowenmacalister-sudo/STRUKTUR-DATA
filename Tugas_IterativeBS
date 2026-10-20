#include <iostream>
using namespace std;

int binary_search(int data[], int lower, int high, int target){
    
    while(lower <= high){
        int mid = lower + (high-lower)/2;
        
        if(data[mid] == target){
            return mid;
        }else if(data[mid]<target){
            lower = mid+1;
        }else{
            high = mid -1;
        }
    }
    return -1;
    
}

void input_array(int data[], int n){
    int posisi = 0;
    
    while(posisi < n){
        int angka = 0;
        cout << "masukkan angka ke" << posisi << ": "; cin >> angka;
    if(posisi==0){
        data[posisi] = angka;
        posisi++;
    }
    
    else if(data[posisi-1] < angka){
        data[posisi] = angka;
        posisi++;
    }
    else{
        cout << "input angka yang lebih besar dan tidak boleh minus";
    }
    }
}

int main()
{
    int n = 0;
    cout << "mau berapa input berapa angak: ";cin >> n;
    int data[n];
    int target = 0;
    int lower = 0;
    int high = n-1;
    input_array(data, n);
    
    cout << "masukkan target: "; cin >> target;

    int hasil = binary_search(data, lower, high, target);
    
    if(hasil == -1){
        cout << "gak nemu";
    }else {
        cout << hasil;
    }
    return 0;
}
