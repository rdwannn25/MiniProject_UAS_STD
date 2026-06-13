# Smart Campus Navigation System

## Deskripsi Proyek

Smart Campus Navigation System merupakan aplikasi berbasis bahasa pemrograman C++ yang dirancang untuk membantu pengelolaan informasi lingkungan kampus. Sistem ini menyediakan fitur pengelolaan data gedung, pencarian dan pengurutan data, pengelolaan antrean shuttle mahasiswa, pencatatan histori aktivitas, serta representasi hubungan antar gedung menggunakan berbagai struktur data.

Proyek ini dibuat sebagai implementasi konsep Struktur Data, di antaranya Array, Struct, Single Linked List, Double Linked List, Stack, Queue, Tree, Graph, serta algoritma Searching dan Sorting.

---

## Fitur Program

Aplikasi memiliki beberapa fitur utama sebagai berikut:

- Menambahkan data gedung kampus.
- Menampilkan daftar data gedung.
- Melakukan pencarian data gedung berdasarkan nama.
- Mengurutkan data gedung secara alfabetis.
- Menampilkan data menggunakan Single Linked List.
- Menampilkan data menggunakan Double Linked List (maju dan mundur).
- Mengelola antrean shuttle mahasiswa menggunakan Queue.
- Menampilkan riwayat aktivitas menggunakan Stack.
- Menampilkan struktur fakultas menggunakan Tree.
- Mengelola jalur antar gedung menggunakan Graph.
- Mengubah (edit) dan menghapus data gedung.

---

## Struktur Data yang Digunakan

| Struktur Data | Fungsi |
|---------------|--------|
| Array & Struct | Menyimpan data gedung kampus |
| Single Linked List | Menampilkan data gedung satu arah |
| Double Linked List | Menampilkan data gedung maju dan mundur |
| Stack | Menyimpan histori aktivitas |
| Queue | Mengelola antrean shuttle mahasiswa |
| Tree | Menampilkan struktur universitas dan fakultas |
| Graph | Menyimpan hubungan jalur antar gedung |
| Searching | Mencari data gedung berdasarkan nama |
| Sorting | Mengurutkan data gedung secara alfabetis |

---

## Struktur Repository

```
Smart-Campus-Navigation-System/
│
├── UAS.cpp          # Source code utama aplikasi
├── README.md        # Dokumentasi proyek
└── .gitignore       # File konfigurasi Git (opsional)
```

---

## Prasyarat

Sebelum menjalankan program, pastikan perangkat telah memiliki compiler C++ yang mendukung standar C++17 seperti GCC/G++.

Untuk mengecek versi compiler, gunakan perintah berikut:

```bash
g++ --version
```

---

## Cara Kompilasi Program

Kompilasi source code menggunakan compiler g++ dengan perintah berikut:

```bash
g++ -std=c++17 UAS.cpp -o smart_campus
```

Keterangan:
- `-std=c++17` menggunakan standar bahasa C++17.
- `UAS.cpp` merupakan file source code utama program.
- `-o smart_campus` menghasilkan file executable dengan nama `smart_campus`.

---

## Cara Menjalankan Program

### Linux / macOS

```bash
./smart_campus
```

### Windows (Command Prompt)

```bash
smart_campus.exe
```

---

## Tampilan Menu Program

Saat aplikasi dijalankan, pengguna akan melihat tampilan menu seperti berikut:

```
===== SMART CAMPUS NAVIGATION SYSTEM =====
1. Tambah Gedung
2. Tampilkan Gedung
3. Cari Gedung
4. Sorting Gedung
5. Tampilkan Single Linked List
6. Tampilkan Double Linked List
7. Tambah Antrean Shuttle
8. Proses Antrean Shuttle
9. Tampilkan Antrean
10. Tampilkan Histori Stack
11. Tambah Jalur Graph
12. Tampilkan Graph
13. Tampilkan Tree Fakultas
14. Edit Gedung
15. Hapus Gedung
0. Keluar
```

---

## Teknologi yang Digunakan

- Bahasa Pemrograman: C++
- Compiler: GCC / G++
- Standar Bahasa: C++17
- Version Control: Git
- Repository: GitHub

---

## Pengembang

Proyek ini dibuat sebagai tugas akhir mata kuliah Struktur Data dengan tujuan mengimplementasikan berbagai konsep struktur data ke dalam sebuah aplikasi berbasis C++.

---

**Smart Campus Navigation System © 2026**
