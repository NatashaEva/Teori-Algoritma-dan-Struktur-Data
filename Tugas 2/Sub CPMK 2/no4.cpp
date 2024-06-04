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
