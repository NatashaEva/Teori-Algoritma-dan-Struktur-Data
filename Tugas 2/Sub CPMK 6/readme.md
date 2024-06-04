# <h1 align="center">Evalusasi Algoritma dan Struktur Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>


# SubCPMK 6
## 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)!

```C++
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



```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/d7c59de4-5465-479f-a80c-35f906431af6)


### Full Code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/104139d0-b445-4728-9419-a2ef711134d0)




## 2. Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty.  


```C++
#include <iostream>
#include <stack>
using namespace std;

// Fungsi untuk mensortir stack sehingga item dengan nilai terkecil menjadi top
void sortStack(stack<int>& s) {
    stack<int> tempStack;

    while (!s.empty()) {
        // Ambil elemen teratas dari stack
        int temp = s.top();
        s.pop();

        // Pindahkan elemen dari stack sementara ke tempStack
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    // Pindahkan kembali elemen dari tempStack ke stack asli
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Fungsi untuk mencetak isi stack
void printStack(stack<int> s) {
    cout << "Isi stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;
    myStack.push(33);
    myStack.push(-2);
    myStack.push(9);
    myStack.push(10);
    myStack.push(-4);

    cout << "Stack sebelum disortir: ";
    printStack(myStack);

    // Mensortir stack
    sortStack(myStack);

    cout << "Stack setelah disortir: ";
    printStack(myStack);

    return 0;
}



```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/69acc1cc-4c55-47b5-b837-68e526ad8a4a)

### Full Code Screenshots
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/3de48a25-85c0-4adc-b4c4-667567b1019d)



 