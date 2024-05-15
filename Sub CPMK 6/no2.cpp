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
