#include <iostream>
#include <algorithm>

using namespace std;

bool cekDuplikat(int arr[], int panjangArr) {
    // Urutkan array terlebih dahulu
    sort(arr, arr + panjangArr);
    
    // Cek elemen yang bersebelahan untuk mencari duplikat
    for(int i = 0; i < panjangArr - 1; i++) {
        if(arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    int arrA[]={2, 1, 3, 1};
    int panjangArr = sizeof(arrA) / sizeof(arrA[0]);
    cout << cekDuplikat(arrA, panjangArr);
    return 0;
}
