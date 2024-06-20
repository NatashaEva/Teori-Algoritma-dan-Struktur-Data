#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int numVertices; // Jumlah simpul (vertex) dalam graf
    vector<list<int>> adjLists; // Array dari list untuk adjacency list

public:
    Graph(int vertices); // Konstruktor
    void addEdge(int src, int dest); // Fungsi untuk menambahkan edge
    void printGraph(); // Fungsi untuk mencetak graf
};

// Konstruktor
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists.resize(vertices); // Mengubah ukuran adjacency list sesuai jumlah simpul
}

// Fungsi untuk menambahkan edge ke graf
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest); // Menambahkan edge dari src ke dest
    adjLists[dest].push_back(src); // Jika graf tidak berarah, tambahkan edge dari dest ke src
}

// Fungsi untuk mencetak graf
void Graph::printGraph() {
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ":";
        for (auto x : adjLists[i])
            cout << " -> " << x;
        cout << endl;
    }
}

int main() {
    Graph g(5); // Membuat graf dengan 5 simpul

    // Menambahkan edge ke graf
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Mencetak graf
    g.printGraph();

    return 0;
}
