#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi untuk mengurutkan karakter dalam string
string sortString(string str) {
    sort(str.begin(), str.end());
    return str;
}

// Fungsi untuk memeriksa apakah dua string adalah anagram
bool areAnagrams(string str1, string str2) {
    // Mengurutkan kedua string
    str1 = sortString(str1);
    str2 = sortString(str2);
    
    // Memeriksa apakah kedua string sama setelah diurutkan
    return (str1 == str2);
}

int main() {
    string str1, str2;

    cout << "Masukkan string pertama: ";
    getline(cin, str1);

    cout << "Masukkan string kedua: ";
    getline(cin, str2);

    // Memeriksa apakah kedua string adalah anagram
    if (areAnagrams(str1, str2)) {
        cout << "Kedua string adalah anagram." << endl;
    } else {
        cout << "Kedua string bukan anagram." << endl;
    }

    return 0;
}
