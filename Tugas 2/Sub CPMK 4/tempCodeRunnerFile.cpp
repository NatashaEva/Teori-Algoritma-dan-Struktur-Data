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
