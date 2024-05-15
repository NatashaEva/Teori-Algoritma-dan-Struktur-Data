# <h1 align="center">Evalusasi Algoritma dan Struktur Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>




# SubCPMK 3

## 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!


1. Binary Search

Alur dari algortma searching ini yaitu dengan membagi rentang pencarian menjadi dua bagian secara berulang, kemudian elemen di tengah rentang pencarian akan dibandingkan dengan elemen yang dicari, lalu jika elemen tengah sama dengan elemen yang dicari, pencarian selesai dan elemen ditemukan, namun jika elemen tengah lebih kecil dari elemen yang dicari, maka pencarian dilanjutkan pada bagian kanan rentang, kemudian jika elemen tengah lebih besar dari elemen yang dicari, maka pencarian dilanjutkan pada bagian kiri rentang. Hal ini akan dilakukan secara terus menerus hingga hingga elemen ditemukan atau seluruh rentang telah diperiksa.

- Untuk runtime algoritma binary search adalah sebagai berikut :

Best Case: O(1) akan terjadi ketika elemen yang dicari ditemukan pada pemeriksaan pertama. Maka tidak ada pertukaran yang dilakukan, sehingga algoritma selesai dalam satu perulangan.

Worst Case: O(log n) akan terjadi ketika Elemen yang dicari tidak ada dalam daftar. waktu eksekusi meningkat seiring bertambahnya data. Maka harus dilakukan perulangan hingga elemen yang dicari telah ditemukan.

2. Linear Search

Alur dari algoritma searching linear search yaitu  memeriksa setiap elemen dalam array secara berurutan, kemudian setiap elemen dibandingkan dengan elemen yang dicari, lalu jika elemen yang dicari ditemukan, posisinya dicatat dan pencarian selesai. Algoritma terus memeriksa elemen berikutnya sampai elemen yang dicari ditemukan atau seluruh daftar telah diperiksa.

- Runtime algoritma linear search yaitu:

Best Case: O(1) akan terjadi bila elemen yang dicari ditemukan pada elemen pertama yang diperiksa. Maka algoritma ini tidak perlu melakukan perulangan lagui.

Worst Case: O(n) akan terjadi apabila elemen yang dicari tidak ada dalam daftar. Linear dengan jumlah elemen (n), waktu eksekusi meningkat seiring bertambahnya data.


## 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut!
   

```C++
#include <iostream>
using namespace std;

// Fungsi untuk melakukan pencarian biner
int binarySearch(int arr[], int size, int target) {
    int left = 0; // Inisialisasi indeks kiri
    int right = size - 1; // Inisialisasi indeks kanan

    while (left <= right) { // Lanjutkan selama bagian array masih valid
        int mid = left + (right - left) / 2; // Hitung indeks tengah untuk menghindari overflow

        // Jika elemen target ditemukan di tengah
        if (arr[mid] == target) {
            return mid; // Kembalikan indeks elemen yang ditemukan
        }

        // Jika elemen target lebih besar dari elemen tengah
        if (arr[mid] < target) {
            left = mid + 1; // Pindahkan batas kiri ke kanan dari indeks tengah
        }
        // Jika elemen target lebih kecil dari elemen tengah
        else {
            right = mid - 1; // Pindahkan batas kanan ke kiri dari indeks tengah
        }
    }

    return -1; // Kembalikan -1 jika elemen tidak ditemukan
}

int main() {
    int arr[] = {1, 7, 21, 42, 60}; // Array contoh yang sudah diurutkan
    int size = sizeof(arr) / sizeof(arr[0]); // Menghitung ukuran array
    int target = 42; // Elemen yang akan dicari

    int result = binarySearch(arr, size, target); // Panggil fungsi binarySearch

    // Cek hasil pencarian
    if (result != -1) {
        cout << "Elemen ditemukan pada indeks ke " << result << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}



```
 ### Output:
![image](https://github.com/NatashaEva/Teori-Algoritma-Struktur-Data/assets/161322715/5dd56606-1ef3-49ec-9498-49e09703200b)
### Full Code ScreenShots
![image](https://github.com/NatashaEva/Teori-Algoritma-Struktur-Data/assets/161322715/236ef17f-e54e-46fe-9c08-0d6c88cebc65)

Kode diatas merupakan program binary searching yang digunakan untuk mencari elemen tertentu dalam array. Dalam program ini terdapat beberapa fungsi yaitu fungsi arr yang merupakan array yang akan dicari elemennya, fungsi size merupakan ukuran array, fungsi target sebagai elemen yang akan dicari dalam array, fungsi left sebagai inisialisasi indeks batas kiri, fungsi right sebagai inisialisasi indeks batas kanan. Proses perulangan dalam program ini yaitu pertama menghitung indeks tengah, jika elemen tengah adalah elemen yang dicari, kembali ke indeks tengah. Namun, bila elemen tengah kurang dari target, geser batas kiri ke kanan dari tengah, sebaliknya jika elemen tengah lebih besar dari target, geser batas kanan ke kiri tengah.
 

## 3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}
Output: 6

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binarySearch(vector<string>& arr, const string& target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Temukan indeks yang tidak kosong di sekitar mid
        int nonEmptyMid = mid;
        while (arr[nonEmptyMid] == "" && nonEmptyMid >= left) nonEmptyMid--;

        // Jika ada string kosong di sekitar mid, perbaiki mid
        if (arr[nonEmptyMid] == "") {
            // Pindah left ke nonEmptyMid + 1
            if (arr[mid] != "") left = nonEmptyMid + 1;
            // Pindah right ke nonEmptyMid - 1
            else right = nonEmptyMid - 1;
            continue;
        }

        // Bandingkan target dengan string non-kosong di mid
        int cmp = target.compare(arr[nonEmptyMid]);

        // Jika target lebih kecil, cari di sebelah kiri
        if (cmp < 0) right = nonEmptyMid - 1;
        // Jika target lebih besar, cari di sebelah kanan
        else if (cmp > 0) left = nonEmptyMid + 1;
        // Jika target sama dengan string non-kosong di mid, kembalikan indeks mid
        else return nonEmptyMid;
    }

    // Jika tidak ditemukan, kembalikan -1
    return -1;
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"}; // Array yang sudah diurutkan
    string target = "bola"; // Kata yang dicari

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Indeks dari kata \"" << target << "\" adalah: " << index << endl;
    else
        cout << "Kata \"" << target << "\" tidak ditemukan dalam array." << endl;

    return 0;
}

```




