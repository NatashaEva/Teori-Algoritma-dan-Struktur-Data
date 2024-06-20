#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Array yang akan diurutkan menggunakan priority queue
    int arr[6] = {50, 35, 10, 22, 1, 7};

    // Definisikan priority queue
    priority_queue<int> pq;

    // Cetak array sebelum dimasukkan ke dalam priority queue
    cout << "Array: ";
    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Memasukkan elemen array ke dalam priority queue
    for (int i = 0; i < 6; ++i) {
        pq.push(arr[i]);
    }

    // Cetak priority queue setelah semua elemen dimasukkan
    cout << "Priority Queue : ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
