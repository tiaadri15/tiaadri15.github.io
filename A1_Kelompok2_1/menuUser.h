#ifndef menuUser_H
#define menuUser_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <limits>
#include <functional>
#include <string>
#include <queue>
#include <sstream>
#include "menuAdmin.h"
#include "pesanan.h"

using namespace std;

// Inisialisasi linked list untuk barang dan pesanan
Barang* headBarang = NULL;
Pesanan* headPesanan = NULL;

// Queue untuk menyimpan pesanan yang akan diproses
queue<Pesanan*> orderQueue;

// Fungsi untuk menyimpan pesanan ke dalam file pesanan.txt
void simpanPesananKeFile(const Pesanan &pesanan)
{
    // Membuka file pesanan.txt untuk ditambahkan data pesanan baru
    ofstream file("pesanan.txt", ios::app);

    if (file.is_open())
    {
        // Menulis data pesanan ke dalam file
        file << pesanan.idPesanan << ",";
        file << pesanan.idBarang << ",";
        file << pesanan.namaCustomer << ",";
        file << pesanan.telepon << ",";
        file << pesanan.alamat << ",";
        file << pesanan.status << endl;

        // Menutup file setelah penulisan selesai
        file.close();

        cout << "Data pesanan berhasil disimpan ke pesanan.txt" << endl;
    }
    else
    {
        cout << "Gagal membuka file pesanan.txt" << endl;
    }
}

// Fungsi untuk membaca data barang dari file data_barang.txt
void BacaDataBarang()
{
    ifstream fileBarang("data_barang.txt");

    if (fileBarang.is_open())
    {
        // Membaca data barang dari file dan menyimpannya dalam linked list
        while (!fileBarang.eof())
        {
            Barang* baru = new Barang;
            fileBarang >> baru->idBarang;
            fileBarang.ignore();
            getline(fileBarang, baru->namaBarang);
            fileBarang >> baru->harga >> baru->stock;

            baru->next = headBarang;
            headBarang = baru;
        }

        // Menutup file setelah pembacaan selesai
        fileBarang.close();
    }
    else
    {
        cout << "Gagal membuka file data_barang.txt" << endl;
    }
}

// Fungsi untuk menampilkan data barang
void tampilDataBarang()
{
    cout << "=============================================" << endl;
    cout << "  > Daftar Barang" << endl;
    cout << "=============================================" << endl;

    Barang* current = headBarang;

    while (current != NULL)
    {
        // Menampilkan informasi setiap barang dalam daftar
        cout << "  > ID Barang  : " << current->idBarang << endl;
        cout << "  > Nama Barang: " << current->namaBarang << endl;
        cout << "  > Harga      : " << current->harga << endl;
        cout << "  > Stock      : " << current->stock << endl;
        cout << "---------------------------------------------" << endl;

        current = current->next;
    }
}

// Fungsi untuk memilih barang yang ingin dipesan
int PilihBarang()
{
    int pilihan;

    // Meminta input ID barang yang ingin dipesan
    cout << "  Pilih ID Barang yang ingin dipesan: ";
    cin >> pilihan;

    // Validasi pilihan barang
    Barang* current = headBarang;
    int count = 0;

    // Menghitung jumlah barang dalam daftar
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    // Memastikan pilihan berada dalam rentang yang valid
    while (pilihan < 1 || pilihan > count)
    {
        cout << "  Pilihan tidak valid. Ulangi input: ";
        cin >> pilihan;
    }

    return pilihan;
}


void BacaDataPesanan()
{
    // Clear existing linked list
    getche();
    ifstream filePesanan("pesanan.txt");
    if (filePesanan.is_open())
    {
        while (!filePesanan.eof())
        {
            Pesanan* pesananBaru = new Pesanan;

            // Membaca data pesanan dari file
            string line;
            getline(filePesanan, line);

            if (line == ""){
                continue;
            }
            stringstream ss(line);

             // Ignore "ID Pesanan: "
            ss >> pesananBaru->idPesanan;

             // Ignore "ID Barang: "
            ss >> pesananBaru->idBarang;

             // Ignore "Nama Customer: "
            getline(ss, pesananBaru->namaCustomer);

             // Ignore "Telepon: "
            getline(ss, pesananBaru->telepon);

             // Ignore "Alamat: "
            getline(ss, pesananBaru->alamat);

             // Ignore "Status: "
            getline(ss, pesananBaru->status);

            pesananBaru->next = headPesanan;
            headPesanan = pesananBaru;
        }
        filePesanan.close();
    }
    else
    {
        cout << "Gagal membuka file pesanan.txt" << endl;
    }
}

void TampilDetailPesanan(const Pesanan &pesanan)
{
    cout << "=============================================" << endl;
    cout << "  > Detail Pesanan" << endl;
    cout << "=============================================" << endl;

    cout << "  > ID Pesanan       : " << pesanan.idPesanan << endl;
    cout << "  > Nama Customer    : " << pesanan.namaCustomer << endl;
    cout << "  > Alamat           : " << pesanan.alamat << endl;
    cout << "  > Telepon          : " << pesanan.telepon << endl;
    cout << "  > Status           : " << pesanan.status << endl;

    // Mencari data barang berdasarkan idBarang pada pesanan
    Barang* currentBarang = headBarang;
    while (currentBarang != NULL)
    {
        if (currentBarang->idBarang == pesanan.idBarang)
        {
            cout << "  > Barang Dipesan   : " << currentBarang->namaBarang << endl;
            cout << "  > Harga Barang     : " << currentBarang->harga << endl;
            cout << "  > Stock Barang     : " << currentBarang->stock << endl;
            break;
        }
        currentBarang = currentBarang->next;
    }
}

void EditPesanan(int idPesanan)
{
    Pesanan* current = headPesanan;
    while (current != NULL)
    {
        if (current->idPesanan == idPesanan)
        {
            // Menampilkan informasi pesanan yang akan diedit
            cout << "Informasi Pesanan yang akan diedit:" << endl;
            cout << "ID Pesanan       : " << current->idPesanan << endl;
            cout << "ID Barang        : " << current->idBarang << endl;
            cout << "Nama Customer    : " << current->namaCustomer << endl;
            cout << "Alamat           : " << current->alamat << endl;
            cout << "Telepon          : " << current->telepon << endl;
            cout << "Status           : " << current->status << endl;

            // Meminta konfirmasi untuk mengedit
            char konfirmasi;
            cout << "\nApakah Anda ingin mengedit pesanan? (Y/N): ";
            cin >> konfirmasi;
            cin.ignore(); // Membersihkan newline yang masih tersisa di buffer

            if (toupper(konfirmasi) == 'Y')
            {
                // Memasukkan data baru
                cout << "Masukkan Nama Customer Baru : ";
                getline(cin, current->namaCustomer);

                cout << "Masukkan Alamat Baru        : ";
                getline(cin, current->alamat);

                cout << "Masukkan Telepon Baru       : ";
                getline(cin, current->telepon);

                // Tidak perlu menyimpan ke dalam file pesanan.txt, karena kita menggunakan linked list
                cout << "Pesanan berhasil diubah!" << endl;

                // Menyimpan pesanan yang telah diubah ke dalam file pesanan.txt
                ofstream filePesanan("pesanan.txt");
                if (filePesanan.is_open())
                {
                    Pesanan* temp = headPesanan;
                    while (temp != NULL)
                    {
                        filePesanan << "ID Pesanan: " << temp->idPesanan;
                        filePesanan << "ID Barang: " << temp->idBarang;
                        filePesanan << "Nama Customer: " << temp->namaCustomer;
                        filePesanan << "Telepon: " << temp->telepon;
                        filePesanan << "Alamat: " << temp->alamat;
                        filePesanan << "Status: " << temp->status;
                        filePesanan << "-----------------------------------" << endl;
                        temp = temp->next;
                    }
                    filePesanan.close();
                    cout << "Data pesanan berhasil disimpan ke pesanan.txt" << endl;
                }
                else
                {
                    cout << "Gagal membuka file pesanan.txt" << endl;
                }
            }
            else
            {
                // Jika pengguna menolak untuk mengedit, langsung keluar dari fungsi
                return;
            }
        }
        current = current->next;
    }

    // Jika ID Pesanan tidak ditemukan
    cout << "Pesanan dengan ID " << idPesanan << " tidak ditemukan." << endl;
}

void tambahPesanan()
{
    BacaDataBarang(); // Membaca data barang sebelum menambah pesanan

    // Menemukan ID pesanan terakhir
    int idPesananTerakhir = 0;
    Pesanan* currentPesanan = headPesanan;
    while (currentPesanan != nullptr)
    {
        if (currentPesanan->idPesanan > idPesananTerakhir)
        {
            idPesananTerakhir = currentPesanan->idPesanan;
        }
        currentPesanan = currentPesanan->next;
    }

    Pesanan* pesananBaru = new Pesanan;
    pesananBaru->idPesanan = idPesananTerakhir + 1; // Auto-increment idPesanan
    pesananBaru->status = "Pending";

    tampilDataBarang();
    int idBarang = PilihBarang();
    pesananBaru->idBarang = idBarang;

    system("cls");

    cout << "=============================================" << endl;
    cout << "  > Pesanan Baru" << endl;
    cout << "=============================================" << endl;

    cout << "  > ID Pesanan       : " << pesananBaru->idPesanan << endl;
    cin.ignore();
    cout << endl;

    cout << "  > Nama Customer    : "; getline(cin, pesananBaru->namaCustomer);
    cout << endl;

    cout << "  > Alamat           : ";  getline(cin, pesananBaru->alamat);
    cout << endl;

    cout << "  > Telepon          : ";  getline(cin, pesananBaru->telepon);
    cout << endl;

    cout << "  > Status           : " << pesananBaru->status << endl;

    // Menyimpan pesanan ke dalam queue
    orderQueue.push(pesananBaru);

    // Menampilkan detail pesanan sebelum menyimpan ke file
    TampilDetailPesanan(*pesananBaru);

    // Menyimpan pesanan ke dalam file pesanan.txt
    char konfirmasi;
    cout << "Apakah Anda ingin mengedit pesanan? (Y/N): ";
    cin >> konfirmasi;
    cin.ignore(); // Membersihkan newline yang masih tersisa di buffer

    if (toupper(konfirmasi) == 'Y')
    {
        EditPesanan(pesananBaru->idPesanan);
    }
    else
    {
        // Note: Don't save to file here, save in menuAdmin.cpp
        cout << "Pesanan berhasil ditambahkan ke queue." << endl;
    }

    // Setelah penyimpanan atau tidak, kembalikan ke menu utama atau tampilkan pesan berhasil ditambahkan
    cout << "Tekan apa saja untuk kembali ke menu utama." << endl;
    _getch();
}

// Fungsi untuk mencari barang berdasarkan nama menggunakan algoritma Boyer-Moore
Barang* cariBarang(const string& namaToSearch)
{
    BacaDataBarang();
    Barang* currentBarang = headBarang;

    // Selama barang masih tersedia dalam daftar
    while (currentBarang != NULL)
    {
        // Mencocokkan nama barang dengan pola pencarian menggunakan algoritma Boyer-Moore
        int m = namaToSearch.length();
        int n = currentBarang->namaBarang.length();

        int badChar[256];

        // Inisialisasi tabel bad character
        for (int i = 0; i < 256; i++)
            badChar[i] = -1;

        // Isi indeks terakhir dari setiap karakter dalam pola
        for (int i = 0; i < m; i++)
            badChar[(int)namaToSearch[i]] = i;

        int s = 0; // Geser karakter
        while (s <= n - m)
        {
            int j = m - 1;

            // Periksa karakter dari belakang
            while (j >= 0 && namaToSearch[j] == currentBarang->namaBarang[s + j])
                j--;

            // Jika pencarian berhasil
            if (j < 0)
                return currentBarang;

            // Geser karakter berdasarkan tabel bad character
            s += max(1, j - badChar[currentBarang->namaBarang[s + j]]);
        }

        // Pindah ke barang berikutnya dalam daftar
        currentBarang = currentBarang->next;
    }

    // Jika barang tidak ditemukan
    return NULL;
}

// Fungsi untuk memulai proses pencarian barang
void cariBarang()
{
    string namaBarang;
    system("cls");
    cout << "=============================================" << endl;
    cout << "             C A R I  B A R A N G            " << endl;
    cout << "=============================================" << endl << endl;
    cout << "  Masukkan Nama Barang yang ingin dicari: ";
    getline(cin, namaBarang);

    // Melakukan pencarian
    Barang* hasilPencarian = cariBarang(namaBarang);

    // Menampilkan hasil pencarian
    if (hasilPencarian != NULL)
    {
        cout << "  \nBarang ditemukan:" << endl;
        cout << "  > ID Barang  : " << hasilPencarian->idBarang << endl;
        cout << "  > Nama Barang: " << hasilPencarian->namaBarang << endl;
        cout << "  > Harga      : " << hasilPencarian->harga << endl;
        cout << "  > Stock      : " << hasilPencarian->stock << endl;
    }
    else
    {
        cout << "  Barang tidak ditemukan." << endl;
    }
}

void menuUser()
{
    int pilihan;
    Pesanan* currentPesanan = NULL;
    do
    {   cout << "Selamat Datang di Sistem, Pengguna Tercinta!" << endl;
        cout << "Tekan enter untuk melanjutkan ke menu user" << endl;
        _getch();
        system("cls");
        cout << "=============================================" << endl;
        cout << "               SISTEM PEMESANAN              " << endl;
        cout << "=============================================" << endl;
        cout << "  [1]. Tambah Pesanan" << endl;
        cout << "  [2]. Searching Barang" << endl;
        cout << "  [0]. Keluar" << endl;
        cout << "=============================================" << endl;
        cout << "  Masukkan pilihan (1/2/0): ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline yang masih tersisa di buffer

        switch (pilihan)
        {
        case 1:
            tambahPesanan();
            break;
        case 2:
            cariBarang();
            getche();
            break;
        case 0:
            cout << "Terima kasih! Program keluar." << endl;
            getche();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }

        cout << "  \nTekan apa saja untuk kembali ke menu utama.";
        _getch();

    } while (pilihan != 0);
}

#endif
