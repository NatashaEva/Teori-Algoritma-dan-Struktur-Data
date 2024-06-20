#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    list<int> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    bool searchItem(int key) {
        int index = hashFunction(key);
        for (auto i : table[index]) {
            if (i == key)
                return true;
        }
        return false;
    }

    void displayHash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    int keys[] = {27, 45, 1, 15, 10, 33};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        ht.insertItem(keys[i]);

    ht.displayHash();

    int key = 33;
    if (ht.searchItem(key))
        cout << key << " ditemukan di tabel hash." << endl;
    else
        cout << key << " tidak ditemukan di tabel hash." << endl;

    return 0;
}
