# <h1 align="center">Evalusasi Algoritma dan Struktur Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>


# SubCPMK 2
## 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 


### 1. Bubble Sort 

Alur dari algoritma sorting bubble sort adalah dengan melakukan proses pengulangan sebanyak n-1,  proses pembandingan antara elemen di posisi i dengan elemen di posisi i + 1 di tiap-tiap elemen array dan menukarnya apabila urutannya salah. Pembandingan elemen-elemen ini akan terus diulang hingga tidak perlu dilakukan penukaran lagi.

-  Untuk runtime dari algoritma bubble sort adalah sebagai berikut; 

Best Case: O(n) akan terjadi ketika array sudah terurut dari awal. Maka tidak ada pertukaran yang dilakukan, sehingga algoritma selesai dalam satu perulangan.

Worst Case: O(n^2) akan terjadi ketika array tidak terurut diawal. Maka, setiap perulangan akan melakukan n - 1 perbandingan dan n - 1 pertukaran, sehingga total perbandingan dan pertukaran adalah n(n-1) yang setara dengan O(n^2).

### 2. Selection Sort

Alur dari algirtma selection sort yaitu melakukan perulangan yang melakukan pemilihan dari elemen yang terkecil dalam array dan kemudian menukarnya dengan elemen paling awal (i), lalu membandingkan dengan elemen yang sekarang dengan elemen berikutnya sampai dengan elemen terakhir, perbandingan dilakukan terus sampai tidak ada lagi pertukaran data

- Runtime dari algoritma selection sort yaitu:

Best Case: O(n) akan terjadi ketika array sudah terurut dari awal. Maka, elemen terkecil telah ditemukan pada posisi yang benar, sehingga tidak ada pertukaran yang dilakukan.

Worst Case: O(n^2) akan terjadi ketika array tidak terurut. Maka, harus dilakukan  perulangan dahulu dengan mencari elemen terkecil di seluruh array, sehingga total perbandingan adalah n(n-1)/2 yang setara dengan O(n^2).

### 3. Merge Sort

Alur dari algoritma merge sort yaitu menentuka titik tengah untuk  membagi array menjadi dua subarray dengan ukuran yang sama, kemudian bandingkan bagian pertama dengan bagian kedua manakah yang jumlah elemennya lebih kecil, bandingkan elemen untuk setiap daftar lalu gabungkan ke dalam daftar lain secara terurut. Setelah itu gabungkan dua bagian yang diurutkan.

- Alur dari algoritma merge sort yaitu :

Best Case: O(n log n) akan terjadi ketika array sudah terbagi menjadi dua subarray yang terurut. Maka, penggabungan dua subarray yang terurut hanya membutuhkan n log n operasi.

Worst Case: O(n log n) akan terjadi ketika array tidak terurut. Maka, setiap pembagian array akan menghasilkan dua subarray yang tidak terurut, dan penggabungan dua subarray tersebut membutuhkan n log n operasi.


## 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut !

```C++
#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int arr[] = {12, 4, 7, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen array

  cout << "Array sebelum sorting: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  bubbleSort(arr, n); // Melakukan sorting array

  cout << "Array setelah dilakukan sorting: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}


```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/55654620-c5bf-49de-b4af-5d482795ac87)


### Full Code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/7bf3df8f-2005-40e5-af8b-8ee2e6a219f6)


Kode diatas merupakan contoh program algortima sorting dengan metode bubble sort yang berguna untuk mengurutkan array dari elemen terkecil hingga terbesar. Dalam program ini terdapat fungsi bubblesort(int arr[], int n), fungsi ini untuk mengurutkan elemen dalam array arr dengan bubble sort. Dalam fungsi ini juga terdapat perulangan  i yang akan menjalankan sebanya n - 1 kali, variabel i sebagai indeks untuk melacak iterasi pengurutan, dan juga perulangan j yang dijalankan sebanyak n - i - 1 kali, variabel j sebagai indeks untuk membandingkan semua elemen di array. Jika kondisi if bernilai benar, fungsi swap digunakan untuk menukar posisi kedua elemen tersebut.


## 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram”  


```C++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi untuk mengurutkan karakter dalam string
string sortString(string str) {
    sort(str.begin(), str.end());
    return str;
}

// Fungsi untuk memeriksa apakah dua string adalah anagram
bool areAnagrams(string str1, string str2) {
    // Mengurutkan kedua string
    str1 = sortString(str1);
    str2 = sortString(str2);
    
    // Memeriksa apakah kedua string sama setelah diurutkan
    return (str1 == str2);
}

int main() {
    string str1, str2;

    cout << "Masukkan string pertama: ";
    getline(cin, str1);

    cout << "Masukkan string kedua: ";
    getline(cin, str2);

    // Memeriksa apakah kedua string adalah anagram
    if (areAnagrams(str1, str2)) {
        cout << "Kedua string adalah anagram." << endl;
    } else {
        cout << "Kedua string bukan anagram." << endl;
    }

    return 0;
}



```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/4eeb85c0-b440-4cc4-a5a0-7fa061dde2b1)

### Full Code Screenshots
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/4dd95033-9a04-42b0-af6e-4071980d4ebe)


## 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut!


```C++
#include <iostream>
#include <algorithm>

using namespace std;

void mergeAndSortArrays(int A[], int n, int B[], int m) {
    int i = n - 1; // Pointer untuk array A
    int j = m - 1; // Pointer untuk array B
    int k = n + m - 1; // Pointer untuk array hasil gabungan

    // Mulai dari elemen terakhir, gabungkan A dan B secara terurut
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }

    // Salin sisa elemen dari B ke A jika ada
    while (j >= 0) {
        A[k--] = B[j--];
    }

    // Urutkan array gabungan A
    sort(A, A + n + m);
}

int main() {
    int A[10] = {4, 6, 1, 10, 22}; // Array A yang sudah diurutkan
    int B[] = {5, 2, 3, 15, 33}; // Array B yang sudah diurutkan
    int n = 5; // Ukuran array A
    int m = 5; // Ukuran array B

    mergeAndSortArrays(A, n, B, m);

    cout << "Kedua array setelah digabungkan dan diurutkan: ";
    for (int i = 0; i < n + m; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/292c3d3e-867f-49a7-bea5-adf518f62141)

### Full Code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/8320beec-5918-4cc2-ab21-69ec79f6af46)




