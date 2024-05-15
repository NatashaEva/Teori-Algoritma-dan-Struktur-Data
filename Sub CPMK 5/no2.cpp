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
