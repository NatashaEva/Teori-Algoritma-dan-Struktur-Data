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
    Node* last = *head_ref;-

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
