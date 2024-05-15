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
    cout << shelter.dequeueDog() << endl; // Anjing izzy telah berhasil teradopsi=
    cout << shelter.dequeueAny() << endl; // Kucing cimeng telah berhasil teradopsi
    cout << shelter.dequeueAny() << endl; // Tidak ada hewan yang tersedia

    return 0;
}
