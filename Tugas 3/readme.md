# <h1 align="center">Tugas 3 Algoritma dan Struktur Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>


## 1. Berikan penjelasan dan contoh program(beserta penjelasan alur program) dari masing-masing materi struktur data berikut:
a.Priority Queue

b.Hash Table

c.Rekursif

d.Graph & Tree


### a. Priority Queue 

Priority Queue  memiliki kemampuan yang sama dalam memasukkan elemen seperti antrian biasa, namun pada antrian jenis  ini  elemen dengan prioritas tertinggi dapat keluar terlebih dahulu [1].
 Struktur data ini menggunakan operasi 'Insert'  dan 'DeleteMin' (mengembalikan dan menghapus elemen minimum) atau  `DeleteMax' (mengembalikan dan menghapus elemen maksimum).
 Operasi ini setara dengan operasi antrian biasa EnQueue dan DeQueue.
 Bedanya, pada priority queue, urutan item yang masuk ke antrian mungkin tidak sesuai dengan urutan item yang diproses [2].

Priority queue dikatakan priority queue menaik jika elemen dengan nilai terkecil memiliki prioritas tertinggi (yaitu elemen terkecil selalu dihilangkan).  Demikian pula priority queue disebut priority queue menurun jika elemen dengan nilai terbesar memiliki prioritas tertinggi (selalu hapus elemen terbesar) [2].

#### Contoh Program


```C++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int arr[6] = {50, 35, 10, 22, 1, 7};

    priority_queue<int> pq;

    cout << "Array: ";
    for (int i = 0; i < 6; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 6; ++i) {
        pq.push(arr[i]);
    }

    cout << "Priority Queue : ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}



```

### Output :
![image](https://github.com/NatashaEva/Teori-Algoritma-dan-Struktur-Data/assets/161322715/a0b0c05c-2e1e-4f43-a049-89620aa71280)


Kode diatas merupakan contoh program priority queue yang berisi 6 elemen. 

Alur dari program ini yaitu pertama, dalam program ini akan membuat variabel arr yang berisi 6 elemen untuk menyimpan 6 angka yaitu 50, 35, 10, 22, 1, 7. Kemudian mendeklarasikan variabel 'priority_queue' untuk menyimpan elemen 'arr' yang akan secara default akan membuat elemen dengan nilai tertinggi akan menjadi prioritas tertinggi (max heap). Lalu program ini akan melakukan pencetakan isi 'arr' untuk menunjukan isi array yang akan dilakukan priority queue. Lalu melakukan loop untuk memasukan setiap elemen 'arr' ke priority queue 'pq' menggunakan fungsi push 'pq.push(arr[i])'. Setelah itu, array sudah dalam keadaaan terurutut nilai terbesar ke terkecil. Lalu setelah semua elemen dimasukan kedalam priority queue, program ini akan mengeluarkan elemen dari 'pq' dengan fungsi pop, menggunakan 'pq.top()' dahulu untuk mendapatkan elemen tertinggi, lalu dengan 'pq.pop()' untuk mengahapus elemen dari antrian. Maka hasil akan dicetak sesuai prioritas tertingginya.


### b. Hash Table

Hash table adalah struktur data yang digunakan untuk mengimplementasikan pemetaan  antara kunci (keys) dan nilai (values)  [3]. Struktur data ini menggunakan fungsi hash untuk menentukan lokasi dan jumlah bucket (slot, tabel) untuk menyimpan kunci dan nilai [4]. Dengan menggunakan fungsi hash, tabel hash dapat menghindari pencarian terus menerus dan memberikan waktu akses yang konstan ke data [3].
 
 Namun, aturan telah dibuat untuk mencegah tabrakan (collision handling), situasi dimana dua kunci  berbeda dalam hash menghasilkan indeks yang sama pada tabel hash [3].

 Ada beberapa teknik  untuk menangani tabrakan: 
 - Chaining (Open Hashing)
  : Setiap elemen dalam tabel hash yang berisi daftar yang semuanya memiliki nilai yang sama (daftar tertaut) dipindahkan ke lokasi berbeda.
 [4]. Karena tidak mungkin untuk mengurutkan dua rekaman data berbeda dalam ruang yang sama, lokasi penyimpanan alternatif baru harus ditemukan untuk semua  kecuali rekaman data pertama untuk indeks tertentu [5].
 Oleh karena itu, pencarian nama memerlukan langkah pencarian pada daftar topik [6] sehingga membuat pencarian menjadi lambat.

 - Open Addressing (Closed Hashing)  : Ketika terjadi tabrakan, sistem  mencari ruang kosong lain di tabel dan menempatkan nilai yang sesuai (probing) [3].
 Gunakan fungsi kuadrat (quadratic probing) untuk menentukan lokasi lompatan berikutnya.
 Posisi selanjutnya kemudian ditentukan oleh fungsi hash  (double hashing) [4].


#### Contoh Program :

```C++
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


```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/06a457a0-185f-452c-bf11-db7b7edc5ca5)


Kode diatas merupakan program hash table yang digunakan untuk mencari dan menyimpan  elemen elemen dengan efisien. 

Alur dari program ini yaitu pertama, program ini akan melakukan deklarasi variabel 'HashTable ht' untuk membuat objek 'HashTable', array 'keys' berisi elemen elemen yang akan dimasukan dalam hash table. Kemudian program ini akan membuat beberapa fungsi, yang pertama fungsi 'insertItem' untuk memasukan elemen array kedalam tabel. Proses dari fungsi ini yaitu fungsi ini akan menghitung indeks elemen yang akan dimasukan, lalu menambahkan elemen tsb kedalam linked list. Kedua yaitu fungsi 'searchItem' untuk mencari elemen dalam tabel, proses dari fungsi ini yaitu menghitung indeks elemen yang dicari, lalu menelusuri elemen elemen dalam tabel, kemudian jika elemen tsb ditemukan akan mengembalikan pesan 'true', jika tidak ditemukan mengembalikan pesan 'false'. Ketiga yaitu fungsi 'displayHash' untuk mencetak atau menampilkan hash table, fungsi ini memiliki proses yaitu menelusuri semua indeks dalam tabel, kemudian mencetak elemen sesuai jumlah indeksnya. 

Kemudian program ini akan menjalankan fungsi 'InsertItem' untuk menambahkan elemen dari array 'keys' ke dalam tabel hash, lalu menampilkan isi hash table dengan fungsi 'displayHash'. Kemudian mencari elemen yang diinginkan (33) dengan menggunakan fungsi 'searchItem' dan membuat pesan apakah elemen ditemukan atau tidak. 



## c. Rekursif

Dalam ilmu komputer, banyak algoritma bergantung pada konsep regresi. Rekursi adalah ketika sebuah fungsi dapat memecah masalah menjadi submasalah yang lebih kecil dan kemudian memanggil dirinya sendiri untuk menyelesaikan submasalah tersebut. Dengan membaginya menjadi bagian-bagian yang lebih kecil, prinsip ini menunjukkan cara yang seringkali digunakan untuk memecahkan masalah dalam kehidupan sehari-hari. Memecah masalah menjadi versi yang lebih sederhana dari masalah itu sendiri adalah ciri khas rekursi. Rekursi sangat efektif dalam menyampaikan algoritma dan konsep yang kompleks. Ia menawarkan pendekatan baru untuk menangani masalah dengan melihatnya dari perspektif yang lebih abstrak [7].

Rekursif memiliki dua jenis yaitu rekursif langsung dan tidak langsung. Jenis rekursif tidak langung terjadi ketika fungsi A memanggil fungsi B dan fungsi B memanggil kembali fungsi A [8]. Jenis rekursif langsung terjadi ketika fungsi secara langsunng memanggil dirinya sendiri.

Pemrograman rekursif memiliki banyak keunggulan dan kekurangan. Di sisi positif, program ini memiliki cara penulisan kode yang sederhana, tetapi di sisi negatif, program ini membutuhkan banyak ruang dan waktu [8].

#### Contoh Program :


```C++
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) 
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); 
}

int main() {
    int number = 15;
    cout << "Fibonacci ke-" << number << " adalah " << fibonacci(number) << endl;
    return 0;
}


```

### Output:
![image](https://github.com/NatashaEva/Teori-Algoritma-dan-Struktur-Data/assets/161322715/69e8e5eb-0443-444a-8f8e-3d2868fe3583)


Kode diatas merupakan contoh program rekursif untuk menghitung deret fibonacci, deret fibonacci dihitung dengan menjumlah dua suku sebelumnya dimulai dari 0 dan 1 sbg suku pertama dan kedua. 

Alur dari program ini yaitu pertama, program ini melakukan pembuatan fungsi rekursi 'fibonacci' yang berisi perulangan, jika n kurang dari atau sama dengan 1 (n <= 1), fungsi mengembalikan n. Namun, jika n lebih besar dari 1, fungsi memanggil dirinya sendiri dua kali; fibonacci(n - 1)untuk menghitung nilai fibonacci untuk n-1, fibonacci(n - 2)unruk menghitung nilai fibonacci untuk n-2. Hasil dari dua pemanggilan rekursif ini dijumlahkan dan dikembalikan sebagai hasil untuk fibonacci(n).

Kemudian untuk fungsi 'main' akan berisi pendeklarasikan elemen atau nilai yang diinginkan (15), lalu memanggil fungsi 'fibonacci'. 


## d. Graph and Tree

1.  Graph

Salah satu jenis struktur data adalah graph, yang terdiri dari berbagai node yang saling terhubung. Dalam struktur data nonlinier, graph terdiri dari simpul (vertex) (V) dan sisi (edge) (E). Grafik ini digambarkan dengan titik (vertex) [9] dan himpunan tak kosong yang masing-masing unsurnya disebut titik (vertex) [10], dan himpunan pasangan tak berurutan dari titik-titik tersebut disebut sisi (edge).

Graph terbagi menjadi dua kategori, yaitu [9]:

- Direct Graph
Direct graph adalah garis yang terhubung ke semua simpul (vertex). 

- Undirect Graph 
Undirect graph adalah garis yang tidak terhubung ke semua simpul (vertex).

2. Tree

Tree adalah struktur data non-linier yang menyerupai pohon terdiri dari serangkaian node (simpul) yang saling berhubungan yang dihubungkan oleh vektor [11]. Tree juga dapat digambarkan sebagai kumpulan simpul dengan elemen tertentu yang disebut akar dan node lainnya atau subpohon. Salah satu jenis tree yang khusus adalah binary tree, jenis tree ini dapat memiliki maksimal dua subtree di bawah tiap nodenya, dan kedua subtree tersebut harus terpisah satu sama lain [12].

#### Contoh Program Graph:

```C++
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int numVertices; 
    vector<list<int>> adjLists; 

public:
    Graph(int vertices);
    void addEdge(int src, int dest); 
    void printGraph(); 
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists.resize(vertices);
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src); 
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ":";
        for (auto x : adjLists[i])
            cout << " -> " << x;
        cout << endl;
    }
}

int main() {
    Graph g(5); 

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}


```

### Output :
![image](https://github.com/NatashaEva/Teori-Algoritma-dan-Struktur-Data/assets/161322715/9417253e-4923-4123-97ee-804c48fd4f23)


Kode diatas adalah contoh program graph menggunakan adjency list yang digunakan untuk melakukan pembambahan edge dan mencetak graf, yang berguna untuk menganalisis hubungan antar simpul dalam graf.

Alur dari program ini yaitu, pertama program akan membuat fungsi 'numVertices' untuk menyimpan jumlah vertex, fungsi 'addEdge()' untuk menambahkan edge atau sisi antara dua simpul (src dan dest) dan 'printGraph()' untuk mencetak adjacency list di setiap simpul. Kemudian pada bagian fungsi 'main()' terjadi pembuatan variabel 'Graph' dengan 5 simpul, lalu penambahan edge ke dalam graf dengan fungsi addEdge, dan mencetak seluruh adjacency di tiap simpul untuk menunjukan hubungan antar simpul di graf.


#### Contoh Program Tree


```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}
    void inorderTraversal(Node* node);
    void insert(int val);
    Node* insertRec(Node* node, int val);
};

void BinaryTree::inorderTraversal(Node* node) {
    if (node == nullptr)
        return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

Node* BinaryTree::insertRec(Node* node, int val) {
    if (node == nullptr) {
        node = new Node(val);
        return node;
    }

    if (val < node->data)
        node->left = insertRec(node->left, val);
    else if (val > node->data)
        node->right = insertRec(node->right, val);

    return node;
}

void BinaryTree::insert(int val) {
    root = insertRec(root, val);
}

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(1);
    tree.insert(27);
    tree.insert(12);
    tree.insert(54);
    tree.insert(2);

    cout << "Inorder dari binary tree: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}


```

### Output :
![image](https://github.com/NatashaEva/Teori-Algoritma-dan-Struktur-Data/assets/161322715/2c73b44e-ebe3-4bbc-af65-c124272e14e4)


Kode diatas merupakan contoh program binary tree yang digunakan untuk mengurutkan angka, dengan memanfaatkan sifar transversal inorder pada binary tree.

Alur dari program ini yaitu, pertama melakukan pembuatan variabel 'BinaryTree' yang mana 'root' akan diinisialisasi ke 'nullptr', kemudian akan memanggil fungsi 'insertRec' pada setiap pemanggilan 'insert' untuk memasukan value atau nilai dalam tree, fungsi ini akan mencari posisi sesuai berdasarkan perbandingan nilai dengan nilai node saat ini. Kemudian akan melakukan pemanggilan fungsi 'inorderTransversal' di 'root' untuk memulai transversal inorder, setelah itu fungsi rekursif 'inorderTranversal' akan menelusuri child di kiri, mencetak nilai node saat ini dan menelusuri child di kanan.

## Refrensi

[1] Bible, Paul W., and Moser, Lucas. An Open Guide to Data Structures and Algorithms. PALNI Press. 2023.

[2] Joseph Teguh Santoso. (2021). STRUKTUR DATA dan ALGORITMA (Bagian 1). Penerbit Yayasan Prima Agus Teknik, 7(1), 1-333.

[3] PENGANTAR ILMU KOMPUTER : Panduan Komprehensif bagi Pemula. (2023). (n.p.): PT. Sonpedia Publishing Indonesia.

[4] Algoritma dan Struktur Data menggunakan Golang, Bonus: Intro Pemrograman Web: untuk dosen, mahasiswa, ataupun hobbyist. (2014). (n.p.): Kiswono Prayogo.

[5] Siahaan, V., & Sianipar, R. H. (2018). C#.NET Teori dan Aplikasi untuk Mahasiswa. Balige: Balige Publishing

[6] Sistem Operasi: Buku Referensi Informatika dan Sistem Informasi. (2018). (n.p.): Sefa Bumi Persada.

[7] Purbasari, Wika, et al. ALGORITMA PEMROGRAMAN. Edited by Setiya Putra, Yusuf W., and Hanson P. Putro, CV WIDINA MEDIA UTAMA, 2024.

[8] Shofwan Hanief. M.T S. Kom and I. Wayan Jepiara. M.Cs S. Kom, Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi, 2020.

[9] Oki Arifin et al., DASAR PEMROGRAMAN : Teori & Aplikasi. PT. Sonpedia Publishing Indonesia, 2023.

[10] Erkamim Erkamim et al., Buku Ajar Algoritma dan Struktur Data. PT. Sonpedia Publishing Indonesia, 2024.

[11] Pastima Simanjuntak, S.Kom., M.SI, E. Elisa,. S.Kom, and Hotma Pangaribuan, S.Kom., M.SI, Pengantar Konsep Struktur Data. Pustaka Galeri Mandiri, 2020.

[12] Muhammad Benny Chaniago and Cecep Kurnia Sastradipraja, Buku Ajar Algoritma dan Struktur Data. Kaizen Media Publishing, 2022. ‌




