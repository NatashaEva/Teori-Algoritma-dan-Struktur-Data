# <h1 align="center">Evalusasi Algoritma dan Struktur Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>


# SubCPMK 4
## 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 


Struct adalah struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda. Tipe data yang baru, dapat dibentuk di luar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan kebutuhan program atau aplikasi yang dirancang. Struct memungkinkan para pengembang untuk mengelompokkan data dengan karakteristik serupa ke dalam satu entitas. Setiap elemen pada struct dapat memiliki variasi jenis data yang berbeda, sebuah struktur dinyatakan dengan memanfaatkan keyword yaitu 'struct' atau dalam penulisannya pada bahasa C++ dikenal dengan nama struct.

- Manfaat Struct:

1. Membuat Kode Lebih Terorganisir

2. Memungkinkan user membuat berbagai objek dengan struktur data yang sama, meningkatkan fleksibilitas kode.

3. Membantu mengelola data yang terkait erat dengan cara yang terstruktur dan efisien.


```C++
#include <iostream>
#include <string>
using namespace std;

// Definisikan sebuah struct untuk buku
struct Book {
    string judul;
    string penulis;
    double harga;
};

int main() {
    // Deklarasikan sebuah variabel dengan tipe Book
    Book book1;

    // Mengisi data ke dalam struct
    book1.judul = "Hujan";
    book1.penulis = "Tere Liye";
    book1.harga = 94500;

    // Deklarasikan dan inisialisasi variabel struct lainnya
    Book book2 = {"Pembunuhan di Rumah Miring", "Soji Shimada", 84000};

    // Menampilkan data dari struct book1
    cout << "Buku 1 :" << endl;
    cout << "Judul Buku: " << book1.judul << endl;
    cout << "Penulis Buku: " << book1.penulis << endl;
    cout << "Harga: Rp." << book1.harga << endl;

    // Menampilkan data dari struct book2
    cout << "Book 2 Details:" << endl;
    cout << "Judul Buku: " << book2.judul << endl;
    cout << "Penulis Buku: " << book2.penulis << endl;
    cout << "Harga: Rp." << book2.harga << endl;

    return 0;
}


```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/ed7126e1-ca52-41f0-882e-9f1260c3480c)



### Full Code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/b404b880-e9aa-44bf-a870-f8f8cff3d109)



Kode diatas merupakan contoh program struct yang digunakan untuk mengelola data informasi buku yang terdiri dari judul buku dan nama penulis buku yang bertipe data string dan harga buku yang bertipe data double. Program ini akan mendeklarasikan variabel book1 dengan data book untuk menyimpan informasi buku pertama, kemudian mengisi data kedalam struct book1. Lalu mendeklarasikan variabel book2 dalam book untuk menyimpan informasi buku kedua, lalu mengisi informasi nya secara langsung.


