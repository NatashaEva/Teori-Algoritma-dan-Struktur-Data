#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Fungsi untuk menambahkan elemen ke queue (enqueue/add)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = value;
        cout << "Elemen " << value << " berhasil ditambahkan." << endl;
    }

    // Fungsi untuk menghapus elemen dari queue (dequeue/remove)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return;
        }
        cout << "Elemen " << peek() << " berhasil dihapus." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Fungsi untuk mendapatkan elemen terdepan dari queue (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return -1;
        }
        return arr[front];
    }

    // Fungsi untuk memeriksa apakah queue kosong
    bool isEmpty() {
        return front == -1;
    }

    // Fungsi untuk memeriksa apakah queue penuh
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Fungsi untuk mencetak isi queue
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return;
        }
        cout << "Isi queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }-
};

int main() {
    Queue q;

    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(12);
    q.enqueue(20);
    q.enqueue(56);

    q.printQueue();

    cout << "Elemen terdepan: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.printQueue();

    return 0;
}
