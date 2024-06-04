# <h1 align="center">Evalusasi Algoritma dan Struktur Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>


# SubCPMK 5
## 1. Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) 




```C++
#include <iostream>
using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

// Fungsi untuk menghilangkan duplikasi dari linked list
void removeDuplicates(Node* head) {
    Node* current = head;
    Node* prev = nullptr;
    Node* temp;

    while (current != nullptr && current->next != nullptr) {
        prev = current;
        while (prev->next != nullptr) {
            if (current->data == prev->next->data) {
                temp = prev->next;
                prev->next = prev->next->next;
                delete temp;
            } else {
                prev = prev->next;
            }
        }
        current = current->next;
    }
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;

    // Tambahkan elemen-elemen ke linked list
    append(&head, 22);
    append(&head, 15);
    append(&head, 71);
    append(&head, 15);
    append(&head, 22);
    append(&head, 99);
    append(&head, 71);

    cout << "Linked list sebelum dihilangkan duplikasi: ";
    printList(head);

    // Hilangkan duplikasi
    removeDuplicates(head);

    cout << "Linked list setelah dihilangkan duplikasi: ";
    printList(head);

    return 0;
}



```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/ab2a5eac-478a-4608-8c02-55c2855d50f0)

### Full Code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/c587710d-1c11-4da6-8e5a-8902ac688980)

Kode diatas merupakan program yang digunakan untuk menghilangkan data duplikat dari sebuah linked list. Dalam program ini memiliki beberapa fungsi yaitu fungsi append yang digunakan untuk menambahkan elemen baru ('new_data') ke akhir linked list, fungsi removeDuplicates untuk menghapus node yang memiliki elemen nilai yang duplikat dalam linked list, fungsi printList yang digunakan untuk mencetak semua elemen dalam link list. 


## 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 


```C++
#include <iostream>
using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddle(Node** head_ref) {
    if (*head_ref == nullptr) return; // Jika linked list kosong

    int length = getLength(*head_ref);
    int middle = length / 2;

    // Jika linked list hanya memiliki satu elemen
    if (length == 1) {
        delete *head_ref;
        *head_ref = nullptr;
        return;
    }

    Node* temp = *head_ref;
    for (int i = 0; i < middle - 1; i++) {
        temp = temp->next;
    }

    Node* middleNode = temp->next;
    temp->next = middleNode->next;
    delete middleNode;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;

    // Tambahkan elemen-elemen ke linked list
    append(&head, 12);
    append(&head, 1);
    append(&head, 7);
    append(&head, 25);
    append(&head, 91);

    cout << "Linked list sebelum dihapus node tengahnya: ";
    printList(head);

    // Hapus node di tengah
    deleteMiddle(&head);

    cout << "Linked list setelah dihapus node tengahnya: ";
    printList(head);

    return 0;
}




```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/1e9833ec-0438-48b6-8166-b2c1013aba7f)

### Full Code Screenshots

![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/2a08fcb6-f097-4cea-a2f4-baac1d4afce5)

Kode diatas merupakan program yang digunakan untuk node tengah dalam sebuah linked list. Dalam program ini terdapat fungsi lain yaitu fungsi append untuk menambahkan elemen baru ('new_node') dalam linked list, fungsi getLength untuk menghitung panjang linked list, fungsi deleteMiddle untuk menghapus node ditengah linked list, dan fungsi printList untuk mencetak keseluruhan elemen dalam linked list.




## 3. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 


```C++
#include <iostream>
using namespace std;

// Definisi struktur Node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan elemen ke linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
}

// Fungsi untuk membalikkan linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Fungsi untuk memeriksa apakah linked list adalah palindrom
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) return true;

    // Temukan tengah linked list
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Balikkan bagian kedua linked list
    Node* secondHalf = reverse(slow);
    Node* firstHalf = head;

    // Bandingkan kedua bagian
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;

    // Tambahkan elemen-elemen ke linked list
    append(&head, 8);
    append(&head, 1);
    append(&head, 0);
    append(&head, 1);
    append(&head, 8);

    cout << "Linked list: ";
    printList(head);

    if (isPalindrome(head)) {
        cout << "Linked list adalah palindrom" << endl;
    } else {
        cout << "Linked list bukan palindrom" << endl;
    }

    return 0;
}


```

### Output:

![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/5157f613-8ac5-4c56-adbc-54d5a3e6710c)

### Full Code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/7a569f73-c212-4902-af2a-0849bd0078fc)

kode diatas merupakan program yang digunakan untuk memeriksa apakah elemen termasuk palindrom atau bukan, palindrom adalah sebuah kata, angka, atau urutan karakter yang memiliki kesamaan urutan saat dibaca dari depan maupun dari belakang. Program ini memiliki beberapa fungsi yaitu fungsi append untuk menambahakan elemen baru ('new_data') kedalam akhir linked list, fungsi reverse untuk membalik linked list, fungsi isPalindrome untuk memeriksa apakah linked list palindrom, fungsi printList untuk mencetak keseluruhan linked list.


