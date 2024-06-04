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
