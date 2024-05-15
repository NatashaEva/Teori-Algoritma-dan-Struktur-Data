#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    // Fungsi untuk menambahkan elemen ke stack (push)
    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh" << endl;
            return;
        }
        arr[++top] = value;
        cout << "Elemen " << value << " berhasil ditambahkan." << endl;
    }

    // Fungsi untuk menghapus elemen dari stack (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak ada elemen untuk dihapus." << endl;
            return;
        }
        cout << "Elemen " << peek() << " berhasil dihapus." << endl;
        top--;
    }

    // Fungsi untuk mendapatkan elemen teratas dari stack (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak ada elemen yang dapat diambil." << endl;
            return -1;
        }
        return arr[top];
    }

    // Fungsi untuk memeriksa apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }

    // Fungsi untuk memeriksa apakah stack penuh
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Fungsi untuk mencetak isi stack
    void printStack() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return;
        }
        cout << "Isi stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(3);
    stack.push(7);
    stack.push(12);
    stack.push(20);
    stack.push(27);

    stack.printStack();

    cout << "Elemen teratas: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    stack.printStack();

    return 0;
}
