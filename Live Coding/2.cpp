#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int n;

    cout << "Input bilangan bulat: ";
    cin >> n;

    if (n < 0) {
        cout << "Harap masukkan bilangan bulat!" << endl;
    } else {
        cout << "Faktorial " << n << " yaitu: " << faktorial(n) << endl;
    }

    return 0;
}
