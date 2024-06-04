#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binarySearch(vector<string>& arr, const string& target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Temukan indeks yang tidak kosong di sekitar mid
        int nonEmptyMid = mid;
        while (arr[nonEmptyMid] == "" && nonEmptyMid >= left) nonEmptyMid--;

        // Jika ada string kosong di sekitar mid, perbaiki mid
        if (arr[nonEmptyMid] == "") {
            // Pindah left ke nonEmptyMid + 1
            if (arr[mid] != "") left = nonEmptyMid + 1;
            // Pindah right ke nonEmptyMid - 1
            else right = nonEmptyMid - 1;
            continue;
        }

        // Bandingkan target dengan string non-kosong di mid
        int cmp = target.compare(arr[nonEmptyMid]);

        // Jika target lebih kecil, cari di sebelah kiri
        if (cmp < 0) right = nonEmptyMid - 1;
        // Jika target lebih besar, cari di sebelah kanan
        else if (cmp > 0) left = nonEmptyMid + 1;
        // Jika target sama dengan string non-kosong di mid, kembalikan indeks mid
        else return nonEmptyMid;
    }

    // Jika tidak ditemukan, kembalikan -1
    return -1;
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"}; // Array yang sudah diurutkan
    string target = "bola"; // Kata yang dicari

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Indeks dari kata \"" << target << "\" adalah: " << index << endl;
    else
        cout << "Kata \"" << target << "\" tidak ditemukan dalam array." << endl;

    return 0;
}
