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

    return -1; // Kembalikan -1 jika elemen tidak ditemukanaa
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
