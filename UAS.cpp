#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

const int MAX_GEDUNG = 20;

struct Gedung {
    int id;
    string nama;
};

Gedung dataGedung[MAX_GEDUNG];
int jumlahGedung = 0;

// ================= SINGLE LINKED LIST =================
struct SingleNode {
    Gedung data;
    SingleNode* next;
};

SingleNode* headSingle = NULL;

void tambahSingleList(Gedung g) {
    SingleNode* baru = new SingleNode;
    baru->data = g;
    baru->next = NULL;

    if (headSingle == NULL) {
        headSingle = baru;
    } else {
        SingleNode* temp = headSingle;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void resetSingleList() {
    while (headSingle != NULL) {
        SingleNode* del = headSingle;
        headSingle = headSingle->next;
        delete del;
    }
}

void tampilSingleList() {
    SingleNode* temp = headSingle;

    cout << "\n=== SINGLE LINKED LIST GEDUNG ===\n";

    while (temp != NULL) {
        cout << temp->data.id << " - " << temp->data.nama << endl;
        temp = temp->next;
    }
}

// ================= DOUBLE LINKED LIST =================
struct DoubleNode {
    Gedung data;
    DoubleNode* prev;
    DoubleNode* next;
};

DoubleNode* headDouble = NULL;
DoubleNode* tailDouble = NULL;

void tambahDoubleList(Gedung g) {
    DoubleNode* baru = new DoubleNode;
    baru->data = g;
    baru->next = NULL;
    baru->prev = NULL;

    if (headDouble == NULL) {
        headDouble = tailDouble = baru;
    } else {
        tailDouble->next = baru;
        baru->prev = tailDouble;
        tailDouble = baru;
    }
}

void resetDoubleList() {
    while (headDouble != NULL) {
        DoubleNode* del = headDouble;
        headDouble = headDouble->next;
        delete del;
    }
    tailDouble = NULL;
}

void tampilDoubleListMaju() {
    DoubleNode* temp = headDouble;

    cout << "\n=== DOUBLE LINKED LIST (MAJU) ===\n";

    while (temp != NULL) {
        cout << temp->data.nama << endl;
        temp = temp->next;
    }
}

void tampilDoubleListMundur() {
    DoubleNode* temp = tailDouble;

    cout << "\n=== DOUBLE LINKED LIST (MUNDUR) ===\n";

    while (temp != NULL) {
        cout << temp->data.nama << endl;
        temp = temp->prev;
    }
}

// ================= STACK =================
stack<string> histori;

void tambahHistori(string aktivitas) {
    histori.push(aktivitas);
}

void tampilHistori() {
    stack<string> temp = histori;

    cout << "\n=== HISTORI STACK ===\n";

    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
}

// ================= QUEUE =================
queue<string> antreanBus;

void tambahAntrean(string nama) {
    antreanBus.push(nama);
}

void prosesAntrean() {
    if (!antreanBus.empty()) {
        cout << "\nMahasiswa diproses: " << antreanBus.front() << endl;
        antreanBus.pop();
    } else {
        cout << "\nAntrean kosong\n";
    }
}

void tampilAntrean() {
    queue<string> temp = antreanBus;

    cout << "\n=== ANTREAN SHUTTLE ===\n";

    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }
}

// ================= TREE =================
struct TreeNode {
    string nama;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* buatNode(string nama) {
    TreeNode* baru = new TreeNode;
    baru->nama = nama;
    baru->left = NULL;
    baru->right = NULL;

    return baru;
}

void tampilTree(TreeNode* root, int level = 0) {
    if (root != NULL) {
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }

        cout << "- " << root->nama << endl;

        tampilTree(root->left, level + 1);
        tampilTree(root->right, level + 1);
    }
}

// ================= GRAPH =================
int graph[MAX_GEDUNG][MAX_GEDUNG];

void tambahJalur(int asal, int tujuan) {
    graph[asal][tujuan] = 1;
    graph[tujuan][asal] = 1;
}

void resetGraph() {
    for (int i = 0; i < MAX_GEDUNG; i++) {
        for (int j = 0; j < MAX_GEDUNG; j++) {
            graph[i][j] = 0;
        }
    }
}

void tampilGraph() {
    cout << "\n=== GRAPH JALUR GEDUNG ===\n\n";

    for (int i = 0; i < jumlahGedung; i++) {
        cout << dataGedung[i].nama << " -> ";

        for (int j = 0; j < jumlahGedung; j++) {
            if (graph[i][j] == 1) {
                cout << dataGedung[j].nama << ", ";
            }
        }

        cout << endl;
    }
}

// ================= HELPERS REBUILD =================
void rebuildListsFromArray() {
    resetSingleList();
    resetDoubleList();

    for (int i = 0; i < jumlahGedung; i++) {
        tambahSingleList(dataGedung[i]);
        tambahDoubleList(dataGedung[i]);
    }
}

// ================= SEARCHING =================
void cariGedung(string namaCari) {
    bool ditemukan = false;

    for (int i = 0; i < jumlahGedung; i++) {
        if (dataGedung[i].nama == namaCari) {
            cout << "\nGedung ditemukan!\n";
            cout << "ID : " << dataGedung[i].id << endl;
            cout << "Nama : " << dataGedung[i].nama << endl;

            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nGedung tidak ditemukan\n";
    }
}

// ================= SORTING =================
void sortingGedung() {
    for (int i = 0; i < jumlahGedung - 1; i++) {
        for (int j = 0; j < jumlahGedung - i - 1; j++) {
            if (dataGedung[j].nama > dataGedung[j + 1].nama) {
                swap(dataGedung[j], dataGedung[j + 1]);
            }
        }
    }

    // keep lists consistent
    rebuildListsFromArray();

    cout << "\nData berhasil diurutkan\n";
}

// ================= ARRAY + STRUCT =================
void tambahGedung() {
    if (jumlahGedung >= MAX_GEDUNG) {
        cout << "\nKapasitas penuh\n";
        return;
    }

    Gedung g;

    cout << "\nID Gedung : ";
    cin >> g.id;
    cin.ignore();

    cout << "Nama Gedung : ";
    getline(cin, g.nama);

    dataGedung[jumlahGedung] = g;
    jumlahGedung++;

    rebuildListsFromArray();
    tambahHistori("Menambah gedung: " + g.nama);

    cout << "\nGedung berhasil ditambahkan\n";
}

void tampilGedung() {
    cout << "\n=== DATA GEDUNG ===\n";
    cout << left << setw(10) << "Index" << setw(10) << "ID" << setw(25) << "Nama Gedung" << endl;

    for (int i = 0; i < jumlahGedung; i++) {
        cout << left << setw(10) << i
             << setw(10) << dataGedung[i].id
             << setw(25) << dataGedung[i].nama << endl;
    }
}

// ================= EDIT & DELETE GEDUNG =================
void hapusGedung(int index) {
    if (index < 0 || index >= jumlahGedung) {
        cout << "\nIndex tidak valid\n";
        return;
    }

    string namaHapus = dataGedung[index].nama;

    for (int i = index; i < jumlahGedung - 1; i++) {
        dataGedung[i] = dataGedung[i + 1];
    }

    jumlahGedung--;

    rebuildListsFromArray();
    resetGraph();
    tambahHistori("Menghapus gedung: " + namaHapus);

    cout << "\nGedung berhasil dihapus\n";
}

void editGedung(int index) {
    if (index < 0 || index >= jumlahGedung) {
        cout << "\nIndex tidak valid\n";
        return;
    }

    string namaLama = dataGedung[index].nama;

    cout << "\nMasukkan ID Gedung baru : ";
    cin >> dataGedung[index].id;
    cin.ignore();

    cout << "Masukkan Nama Gedung baru : ";
    getline(cin, dataGedung[index].nama);

    rebuildListsFromArray();
    resetGraph();
    tambahHistori("Mengedit gedung: " + namaLama + " -> " + dataGedung[index].nama);

    cout << "\nGedung berhasil diubah\n";
}

// ================= MENU =================
void menu() {
    cout << "\n===== SMART CAMPUS NAVIGATION SYSTEM =====\n";
    cout << "1. Tambah Gedung\n";
    cout << "2. Tampilkan Gedung\n";
    cout << "3. Cari Gedung\n";
    cout << "4. Sorting Gedung\n";
    cout << "5. Tampilkan Single Linked List\n";
    cout << "6. Tampilkan Double Linked List\n";
    cout << "7. Tambah Antrean Shuttle\n";
    cout << "8. Proses Antrean Shuttle\n";
    cout << "9. Tampilkan Antrean\n";
    cout << "10. Tampilkan Histori Stack\n";
    cout << "11. Tambah Jalur Graph\n";
    cout << "12. Tampilkan Graph\n";
    cout << "13. Tampilkan Tree Fakultas\n";
    cout << "14. Edit Gedung\n";
    cout << "15. Hapus Gedung\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu : ";
}

int main() {

    TreeNode* root = buatNode("Universitas");
    root->left = buatNode("Fakultas Teknik");
    root->right = buatNode("Fakultas Ekonomi");

    root->left->left = buatNode("Lab Komputer");
    root->left->right = buatNode("Ruang Dosen");

    int pilih;

    // init graph to 0
    resetGraph();

    do {
        menu();
        cin >> pilih;
        cin.ignore();

        switch (pilih) {

        case 1:
            tambahGedung();
            break;

        case 2:
            tampilGedung();
            break;

        case 3: {
            string cari;
            cout << "\nMasukkan nama gedung : ";
            getline(cin, cari);
            cariGedung(cari);
            break;
        }

        case 4:
            sortingGedung();
            break;

        case 5:
            tampilSingleList();
            break;

        case 6:
            tampilDoubleListMaju();
            tampilDoubleListMundur();
            break;

        case 7: {
            string nama;
            cout << "\nNama mahasiswa : ";
            getline(cin, nama);
            tambahAntrean(nama);
            break;
        }

        case 8:
            prosesAntrean();
            break;

        case 9:
            tampilAntrean();
            break;

        case 10:
            tampilHistori();
            break;

        case 11: {
            int a, b;

            tampilGedung();

            cout << "\nIndex asal : ";
            cin >> a;
            cout << "Index tujuan : ";
            cin >> b;

            // basic bound check
            if (a < 0 || a >= jumlahGedung || b < 0 || b >= jumlahGedung) {
                cout << "\nIndex tidak valid\n";
            } else {
                tambahJalur(a, b);
                cout << "\nJalur berhasil ditambahkan\n";
            }
            break;
        }

        case 12:
            tampilGraph();
            break;

        case 13:
            cout << "\n=== TREE FAKULTAS ===\n";
            tampilTree(root);
            break;

        case 14: {
            int idx;
            tampilGedung();
            cout << "\nMasukkan Index gedung yang akan di-edit : ";
            cin >> idx;
            cin.ignore();
            editGedung(idx);
            break;
        }

        case 15: {
            int idx;
            tampilGedung();
            cout << "\nMasukkan Index gedung yang akan dihapus : ";
            cin >> idx;
            cin.ignore();
            hapusGedung(idx);
            break;
        }

        case 0:
            cout << "\nProgram selesai\n";
            break;

        default:
            cout << "\nMenu tidak tersedia\n";
        }

    } while (pilih != 0);

    return 0;
}

