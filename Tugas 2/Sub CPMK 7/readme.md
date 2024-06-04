# <h1 align="center">Evalusasi Algoritma dan Struktur Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>


# SubCPMK 7
## 1. Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)!



```C++
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
    }
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


```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/5c5524d8-3122-45bc-9293-f698db73ec5d)

### Full Code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/ccee876d-2073-4802-a7b5-93fd8e375074)



## 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut: 1. mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2. memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat  


```C++
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Animal {
    string type;
    string name;
    int order;

    Animal(string t, string n, int o) : type(t), name(n), order(o) {}
};

class Shelter {
private:
    queue<Animal> dogs;
    queue<Animal> cats;
    int order;

public:
    Shelter() : order(0) {}

    void enqueue(string type, string name) {
        if (type == "anjing") {
            dogs.push(Animal(type, name, order++));
        } else if (type == "kucing") {
            cats.push(Animal(type, name, order++));
        }
    }

    string dequeueAny() {
        if (dogs.empty() && cats.empty()) return "Tidak ada hewan tersedia";

        if (dogs.empty()) return dequeueCat();
        if (cats.empty()) return dequeueDog();

        Animal dog = dogs.front();
        Animal cat = cats.front();

        if (dog.order < cat.order) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

    string dequeueDog() {
        if (dogs.empty()) return "Tidak ada anjing tersedia";
        Animal dog = dogs.front();
        dogs.pop();
        return dog.name + " anjing telah berhasil teradopsi";
    }

    string dequeueCat() {
        if (cats.empty()) return "Tidak ada kucing yang tersedia";
        Animal cat = cats.front();
        cats.pop();
        return cat.name + " kucing telah berhasil teradpsi";
    }
};

int main() {
    Shelter shelter;

    shelter.enqueue("anjing", "Husky");
    shelter.enqueue("kucing", "Maxi");
    shelter.enqueue("anjing", "Izzy");
    shelter.enqueue("kucing", "Cimeng");

    cout << shelter.dequeueAny() << endl; // Anjing husky telah berhasil teradopsi
    cout << shelter.dequeueCat() << endl; // Kucing maxi telah berhasil teradopsi
    cout << shelter.dequeueDog() << endl; // Anjing izzy telah berhasil teradopsi
    cout << shelter.dequeueAny() << endl; // Kucing cimeng telah berhasil teradopsi
    cout << shelter.dequeueAny() << endl; // Tidak ada hewan yang tersedia

    return 0;
}




```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/74cd95b9-18d6-4ccb-88d1-011d9319ac0a)

### Full Code Screenshots
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/80916202-2b62-42a0-abd1-6111d4aab58f)

