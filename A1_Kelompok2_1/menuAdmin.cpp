#include "menuAdmin.h"
#include "pesanan.h"
#include <iostream>
#include <fstream>
#include <iomanip> //menggunakan setfill
#include <stack>
#include <cmath> //menggunakan searching Fibonnaci
#include <sstream>
#include <queue> //untuk antrian pesanan


using namespace std;

queue<Pesanan*> pesananQueue;

AdminMenu::AdminMenu()
{
    head = NULL;
    nextId = 1; // Dimulai dari id 1
    bacaDataDariFile();
}

// proses.cpp
AdminMenu::~AdminMenu()
{
    simpanDataKeFile();
    // Implementasi penghapusan linked list 
}

// MENU ADMIN
void AdminMenu::menuAdmin()
{
    int choice;
    cout << "Selamat Datang di Sistem, Admin!" << endl;
    system("pause");
    system("cls");
    do
    {
        cout << setfill('-') << setw(60) << "\n";
        cout << "\n\t\t Menu Admin \n";
        cout << setfill('-') << setw(60) << "\n";
        cout << endl;
        cout << left << setw(2) << "\t [1] " << setw(40) << "Tambah Barang"
                  << "\n";
        cout << left << setw(2) << "\t [2] " << setw(40) << "Lihat List Barang"
                  << "\n";
        cout << left << setw(2) << "\t [3] " << setw(40) << "Edit Barang"
                  << "\n";
        cout << left << setw(2) << "\t [4] " << setw(40) << "Hapus Barang"
                  << "\n";
        cout << left << setw(2) << "\t [5] " << setw(40) << "Mengurutkan Data Barang"
                  << "\n";
        cout << left << setw(2) << "\t [6] " << setw(40) << "Cari Barang"
                  << "\n";
        cout << left << setw(2) << "\t [7] " << setw(40) << "Melihat Data Pesanan"
                  << "\n";
        cout << left << setw(2) << "\t [8] " << setw(40) << "Melihat Data Pegunjung"
                  << "\n";
        cout << left << setw(2) << "\t [9] " << setw(40) << "Status Pesanan"
                  << "\n";
        cout << left << setw(2) << "\t [10] " << setw(40) << "Log Out"
                  << "\n";
        cout << setfill('-') << setw(60) << "\n";
        cout << setfill(' ');
        cout << endl;
        cout << "Pilih menu (1-10) --->> ";
        cin >> choice;
        cout << setfill('-') << setw(60) << "\n";

        // PILIH MENU
        if (choice == 1)
        {
            tambahBarang();
        }
        else if (choice == 2)
        {
            lihatListBarang();
        }
        else if (choice == 3)
        {
            lihatListBarang();
            editBarang();
        }
        else if (choice == 4)
        {
            lihatListBarang();
            hapusBarang();
        }
        else if (choice == 5)
        {
            urutkanDataBarang();
        }
        else if (choice == 6)
        {
            cariBarang();
        }
        else if (choice == 7)
        {
            lihatDataPesanan();
        }
        else if (choice == 8)
        {
            lihatDataPengunjung();
        }
        else if (choice == 9)
        {
            ubahStatusPesanan();
        }
        else if (choice == 10)
        {
            if (logOut())
            {
                cout << "Log out berhasil.\n";
            }
            else
            {
                cout << "Tidak dapat melakukan log out.\n";
            }
        }
        else
        {
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
    } while (choice != 10);
}

// CREATE
void AdminMenu::tambahBarang()
{
    Barang *newBarang = new Barang;
    newBarang->idBarang = nextId++;
    cin.ignore();
    cout << "Masukkan nama barang: ";
    getline(cin, newBarang->namaBarang);
    cout << "Masukkan harga barang (Rp.): ";
    cin >> newBarang->harga;
    cout << "Masukkan jumlah stock barang: ";
    cin >> newBarang->stock;

    // Tambahkan ke linked list di bagian bawah
    if (head == NULL)
    {
        // Jika linked list kosong, tambahkan sebagai elemen pertama
        head = newBarang;
    }
    else
    {
        // Temukan elemen terakhir dan tambahkan di bawahnya
        Barang *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newBarang;
    }

    cout << "Barang berhasil ditambahkan!\n";

    lihatListBarang();
}

// READ
void AdminMenu::lihatListBarang()
{

    if (head == NULL)
    {
        cout << "\n=================================================================\n";
        cout << "||               List Barang Gwenchanna Merchandise            ||\n";
        cout << "-----------------------------------------------------------------\n";
        cout << "||                    BELUM ADA LIST BARANG.                   ||\n";
        cout << "=================================================================\n";

        return;
    }
    cout << "\n=================================================================\n";
    cout << "||              List Barang Gwenchanna Merchandise             ||\n";
    cout << "||-------------------------------------------------------------||\n";
    cout << "||  ID   ||        Nama Barang         || Harga (Rp)  || Stock ||\n";
    cout << "||=============================================================||\n";

    Barang *current = head;
    while (current != NULL)
    {
        cout << "||" << setw(6) << current->idBarang << " || "
                  << left << setw(26) << current->namaBarang << " || "
                  << left << setw(11) << current->harga << " || "
                  << left << setw(5) << current->stock << " ||\n";
        current = current->next;
    }
    cout << "=================================================================\n";
}

// UPDATE
void AdminMenu::editBarang()
{
    int idToEdit;
    cout << "Masukkan ID barang yang ingin di edit: ";
    cin >> idToEdit;

    Barang *current = head;
    while (current != NULL)
    {
        if (current->idBarang == idToEdit)
        {
            int editChoice;
            cout << "Pilih atribut yang ingin diubah:\n";
            cout << "1. Edit Nama Barang\n";
            cout << "2. Edit Harga Barang\n";
            cout << "3. Edit Stock Barang\n";
            cout << "4. Edit Semua\n";
            cout << "Pilih (1-4): ";
            cin >> editChoice;

            switch (editChoice)
            {
            case 1:
            {
                cin.ignore();
                cout << "Edit Nama: ";
                getline(cin, current->namaBarang);
                break;
            }
            case 2:
            {
                cout << "Edit Harga (Rp.): ";
                cin >> current->harga;
                break;
            }
            case 3:
            {
                cout << "Edit Stock: ";
                cin >> current->stock;
                break;
            }
            case 4:
            {
                cin.ignore();
                cout << "Edit Nama: ";
                getline(cin, current->namaBarang);
                cout << "Edit Harga (Rp.): ";
                cin >> current->harga;
                cout << "Edit Stock: ";
                cin >> current->stock;
                break;
            }
            default:
            {
                cout << "Pilihan tidak valid.\n";
                break;
            }
            }

            cout << "Barang berhasil di edit!\n";
            lihatListBarang();
            return;
        }
        current = current->next;
    }

    cout << "ID barang tidak ditemukan.\n";
}

// DELETE
void AdminMenu::hapusBarang()
{
    int idToDelete;
    cout << "Masukkan ID barang yang ingin dihapus: ";
    cin >> idToDelete;

    Barang *current = head;
    Barang *prev = NULL;

    while (current != NULL)
    {
        if (current->idBarang == idToDelete)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
            cout << "Barang berhasil dihapus!\n";

            lihatListBarang();
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "ID barang tidak ditemukan.\n";
}

// SORTING
void AdminMenu::urutkanDataBarang()
{
    int sortChoice;
    cout << "Pilih jenis pengurutan:\n";
    cout << "1. Berdasarkan Harga\n";
    cout << "2. Berdasarkan Nama\n";
    cout << "3. Berdasarkan ID\n";
    cout << "4. Berdasarkan Stock\n";
    cout << "Pilih (1-4): ";
    cin >> sortChoice;

    bool ascendingOrder;
    cout << "Pilih urutan:\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Pilih (1-2): ";
    int orderChoice;
    cin >> orderChoice;
    ascendingOrder = (orderChoice == 1);

    switch (sortChoice)
    {
    case 1:
        mergeSortByHarga(ascendingOrder);
        lihatListBarang();
        break;
    case 2:
        mergeSortByNama(ascendingOrder);
        lihatListBarang();
        break;
    case 3:
        mergeSortByID(ascendingOrder);
        lihatListBarang();
        break;
    case 4:
        mergeSortByStock(ascendingOrder);
        lihatListBarang();
        break;
    default:
        cout << "Pilihan tidak valid.\n";
        return;
    }

    cout << "Data barang berhasil diurutkan.\n";
}

// SORTING BERDASARKAN HARGA
void AdminMenu::mergeSortByHarga(bool ascending)
{
    head = mergeSortByHargaUtil(head, ascending);
}

Barang *AdminMenu::mergeSortByHargaUtil(Barang *headRef, bool ascending)
{
    if (headRef == NULL || headRef->next == NULL)
    {
        return headRef;
    }

    Barang *front;
    Barang *back;
    splitList(headRef, &front, &back);

    front = mergeSortByHargaUtil(front, ascending);
    back = mergeSortByHargaUtil(back, ascending);

    return mergeByHarga(front, back, ascending);
}

Barang *AdminMenu::mergeByHarga(Barang *front, Barang *back, bool ascending)
{
    Barang dummy;
    Barang *current = &dummy;

    while (front != NULL && back != NULL)
    {
        if ((ascending && front->harga < back->harga) || (!ascending && front->harga > back->harga))
        {
            current->next = front;
            front->prev = current;
            front = front->next;
        }
        else
        {
            current->next = back;
            back->prev = current;
            back = back->next;
        }
        current = current->next;
    }

    current->next = (front != NULL) ? front : back;
    if (current->next != NULL)
    {
        current->next->prev = current;
    }

    return dummy.next;
}

// SORTING BERDASARKAN NAMA BARANG
void AdminMenu::mergeSortByNama(bool ascending)
{
    head = mergeSortByNamaUtil(head, ascending);
}

Barang *AdminMenu::mergeSortByNamaUtil(Barang *headRef, bool ascending)
{
    if (headRef == NULL || headRef->next == NULL)
    {
        return headRef;
    }

    Barang *front;
    Barang *back;
    splitList(headRef, &front, &back);

    front = mergeSortByNamaUtil(front, ascending);
    back = mergeSortByNamaUtil(back, ascending);

    return mergeByNama(front, back, ascending);
}

Barang *AdminMenu::mergeByNama(Barang *front, Barang *back, bool ascending)
{
    Barang dummy;
    Barang *current = &dummy;

    while (front != NULL && back != NULL)
    {
        if ((ascending && front->namaBarang.compare(back->namaBarang) < 0) ||
            (!ascending && front->namaBarang.compare(back->namaBarang) > 0))
        {
            current->next = front;
            front->prev = current;
            front = front->next;
        }
        else
        {
            current->next = back;
            back->prev = current;
            back = back->next;
        }
        current = current->next;
    }

    current->next = (front != NULL) ? front : back;
    if (current->next != NULL)
    {
        current->next->prev = current;
    }

    return dummy.next;
}

// SORTING BERDASARKAN ID BARANG
void AdminMenu::mergeSortByID(bool ascending)
{
    head = mergeSortByIDUtil(head, ascending);
}

Barang *AdminMenu::mergeSortByIDUtil(Barang *headRef, bool ascending)
{
    if (headRef == NULL || headRef->next == NULL)
    {
        return headRef;
    }

    Barang *front;
    Barang *back;
    splitList(headRef, &front, &back);

    front = mergeSortByIDUtil(front, ascending);
    back = mergeSortByIDUtil(back, ascending);

    return mergeByID(front, back, ascending);
}

Barang *AdminMenu::mergeByID(Barang *front, Barang *back, bool ascending)
{
    Barang dummy;
    Barang *current = &dummy;

    while (front != NULL && back != NULL)
    {
        if ((ascending && front->idBarang < back->idBarang) || (!ascending && front->idBarang > back->idBarang))
        {
            current->next = front;
            front->prev = current;
            front = front->next;
        }
        else
        {
            current->next = back;
            back->prev = current;
            back = back->next;
        }
        current = current->next;
    }

    current->next = (front != NULL) ? front : back;
    if (current->next != NULL)
    {
        current->next->prev = current;
    }

    return dummy.next;
}

// SORTING BERDASARKAN STOCK
void AdminMenu::mergeSortByStock(bool ascending)
{
    head = mergeSortByStockUtil(head, ascending);
}

Barang *AdminMenu::mergeSortByStockUtil(Barang *headRef, bool ascending)
{
    if (headRef == NULL || headRef->next == NULL)
    {
        return headRef;
    }

    Barang *front;
    Barang *back;
    splitList(headRef, &front, &back);

    front = mergeSortByStockUtil(front, ascending);
    back = mergeSortByStockUtil(back, ascending);

    return mergeByStock(front, back, ascending);
}

Barang *AdminMenu::mergeByStock(Barang *front, Barang *back, bool ascending)
{
    Barang dummy;
    Barang *current = &dummy;

    while (front != NULL && back != NULL)
    {
        if ((ascending && front->stock < back->stock) || (!ascending && front->stock > back->stock))
        {
            current->next = front;
            front->prev = current;
            front = front->next;
        }
        else
        {
            current->next = back;
            back->prev = current;
            back = back->next;
        }
        current = current->next;
    }

    current->next = (front != NULL) ? front : back;
    if (current->next != NULL)
    {
        current->next->prev = current;
    }

    return dummy.next;
}

// SPLITLIST UNTUK PROSES MEMBAGI DUA PADA MERGESORT
void AdminMenu::splitList(Barang *source, Barang **frontRef, Barang **backRef)
{
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        Barang *slow = source;
        Barang *fast = source->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;

        if (*backRef != NULL)
        {
            (*backRef)->prev = NULL;
        }
    }
}

// SEARCHING
void AdminMenu::cariBarang()
{
    int searchChoice;
    cout << "Pilih jenis pencarian:\n";
    cout << "1. Berdasarkan ID\n";
    cout << "2. Berdasarkan Nama\n";
    cout << "Pilih (1-2): ";
    cin >> searchChoice;

    if (searchChoice == 1)
    {
        int idToSearch;
        cout << "Masukkan ID barang yang ingin dicari: ";
        cin >> idToSearch;
        cariBarangByID(idToSearch);
    }
    else if (searchChoice == 2)
    {
        cin.ignore();
        cout << "Masukkan nama barang yang ingin dicari: ";
        string namaToSearch;
        getline(cin, namaToSearch);
        cariBarangByNama(namaToSearch);
    }
    else
    {
        cout << "Pilihan tidak valid.\n";
    }
}

void AdminMenu::cariBarangByID(int idToSearch)
{
    Barang *result = fibonacciSearchByID(head, idToSearch);
    if (result != NULL)
    {
        cout << "Barang ditemukan!\n";
        cout << "ID: " << result->idBarang << "\n";
        cout << "Nama: " << result->namaBarang << "\n";
        cout << "Harga: Rp. " << result->harga << "\n";
        cout << "Stock: " << result->stock << "\n\n";
    }
    else
    {
        cout << "Barang dengan ID " << idToSearch << " tidak ditemukan.\n";
    }
}

void AdminMenu::cariBarangByNama(const string &namaToSearch)
{
    Barang *result = fibonacciSearchByNama(head, namaToSearch);
    if (result != NULL)
    {
        cout << "Barang ditemukan!\n";
        cout << "ID: " << result->idBarang << "\n";
        cout << "Nama: " << result->namaBarang << "\n";
        cout << "Harga: Rp. " << result->harga << "\n";
        cout << "Stock: " << result->stock << "\n\n";
    }
    else
    {
        cout << "Barang dengan nama \"" << namaToSearch << "\" tidak ditemukan.\n";
    }
}

Barang *AdminMenu::fibonacciSearchByID(Barang *head, int idToSearch)
{
    int fibMMinus2 = 0;
    int fibMMinus1 = 1;
    int fibM = fibMMinus2 + fibMMinus1;

    while (fibM < idToSearch)
    {
        fibMMinus2 = fibMMinus1;
        fibMMinus1 = fibM;
        fibM = fibMMinus2 + fibMMinus1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMinus2, idToSearch - 1);

        if (head != NULL && head->idBarang == idToSearch)
        {
            return head;
        }
        else if (head != NULL && head->idBarang < idToSearch)
        {
            head = head->next;
            offset = i;
            fibM = fibMMinus1;
            fibMMinus1 = fibMMinus2;
            fibMMinus2 = fibM - fibMMinus1;
        }
        else
        {
            fibM = fibMMinus2;
            fibMMinus1 = fibMMinus1 - fibMMinus2;
            fibMMinus2 = fibM - fibMMinus1;
        }
    }

    if (fibMMinus1 && head != NULL && head->idBarang == idToSearch)
    {
        return head;
    }

    return NULL;
}

Barang *AdminMenu::fibonacciSearchByNama(Barang *head, const string &namaToSearch)
{
    int fibMMinus2 = 0;
    int fibMMinus1 = 1;
    int fibM = fibMMinus2 + fibMMinus1;

    while (fibM < namaToSearch.length())
    {
        fibMMinus2 = fibMMinus1;
        fibMMinus1 = fibM;
        fibM = fibMMinus2 + fibMMinus1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMinus2, static_cast<int>(namaToSearch.length()) - 1);

        if (head != NULL && head->namaBarang == namaToSearch)
        {
            return head;
        }
        else if (head != NULL && head->namaBarang < namaToSearch)
        {
            head = head->next;
            offset = i;
            fibM = fibMMinus1;
            fibMMinus1 = fibMMinus2;
            fibMMinus2 = fibM - fibMMinus1;
        }
        else
        {
            fibM = fibMMinus2;
            fibMMinus1 = fibMMinus1 - fibMMinus2;
            fibMMinus2 = fibM - fibMMinus1;
        }
    }

    if (fibMMinus1 && head != NULL && head->namaBarang == namaToSearch)
    {
        return head;
    }

    return NULL;
}

void AdminMenu::lihatDataPesanan()
{
    ifstream file("pesanan.txt");

    // Display orders from the queue
    if (pesananQueue.empty())
    {
        cout << "Tidak ada pesanan.\n";
    } else {
        if (file.is_open())
        {
            string line;

            while (getline(file, line))
            {
                istringstream iss(line);

                string label;
                iss >> label;
                cout << "\n";
                if (label == "ID") {
                    int idValue;
                    string nextLabel;
                    iss >> nextLabel >> idValue;
                    cout << label << " " << nextLabel << ": " << idValue << "\n";
                } else if (label == "Nama") {
                    string customerLabel, customerName;
                    iss >> customerLabel >> customerName;
                    cout << customerLabel << " " << customerName << "\n";
                } else {
                    string value;
                    iss >> value;
                    cout << label << " " << value << "\n";
                }

                if (label == "Status") {
                    cout << "-----------------------------------\n";
                }
            }

            file.close();
        }
        else
        {
            cout << "Tidak dapat membuka file pesanan.txt\n";
        }
    }
}


void AdminMenu::lihatDataPengunjung()
{

    ifstream file("user_data.txt");

    if (file.is_open())
    {
        string line;
        int count = 1;

        while (getline(file, line))
        {
            istringstream iss(line);
            string namaPengguna;
            iss >> namaPengguna; // Membaca suku kata pertama dari setiap baris

            cout << "\t\t----------------------\n";
            cout << "\t\t||Daftar Pengunjung ||\n";
            cout << "\t\t----------------------\n";
            cout << "\t\t  Data Pengguna ke-" << count << ":\n";
            cout << "\t\t  Nama Pengguna: " << namaPengguna << "\n";
            cout << "\t\t----------------------\n";

            count++;
        }
        file.close();
    }
    else
    {
        cout << "Tidak dapat membuka file user_data.txt\n";
    }
}

bool AdminMenu::logOut()
{
    return true;
}

void AdminMenu::tampilDataPesanan()
{   
    lihatDataPesanan();
    // Display orders from the queue
    if (pesananQueue.empty())
    {
        cout << "Tidak ada pesanan.\n";
    }
    else
    {
        cout << "\n=============================================\n";
        cout << "||            Data Pesanan                  ||\n";
        cout << "=============================================\n";

        int i = 1;
        queue<Pesanan*> tempQueue = pesananQueue;

        while (!tempQueue.empty())
        {
            Pesanan* pesanan = tempQueue.front();
            tempQueue.pop();

            cout << "Pesanan ke-" << i << ":\n";
            cout << "ID Pesanan: " << pesanan->idPesanan << "\n";
            cout << "Nama Pemesan: " << pesanan->namaCustomer << "\n";
            cout << "Barang Dipesan: " << pesanan->namaBarang << "\n";
            cout << "Status: " << pesanan->status << "\n";
            cout << "---------------------------------------------\n";

            i++;
        }
    }
}

void AdminMenu::ubahStatusPesanan()
{
    tampilDataPesanan();
    // Change the status of an order
    if (pesananQueue.empty())
    {
        cout << "Tidak ada pesanan yang dapat diubah statusnya.\n";
        return;
    }

    int idPesanan;
    cout << "Masukkan ID Pesanan yang akan diubah statusnya: ";
    cin >> idPesanan;

    // Find the order with the specified ID
    queue<Pesanan*> tempQueue = pesananQueue;
    while (!tempQueue.empty())
    {
        Pesanan* pesanan = tempQueue.front();
        tempQueue.pop();

        if (pesanan->idPesanan == idPesanan)
        {
            cout << "Pesanan ditemukan!\n";
            cout << "Status saat ini: " << pesanan->status << "\n";

            string newStatus;
            cout << "Masukkan status baru (pending/selesai): ";
            cin >> newStatus;

            // Update the status
            pesanan->status = newStatus;

            cout << "Status pesanan berhasil diubah!\n";
            return;
        }
    }

    cout << "Pesanan dengan ID " << idPesanan << " tidak ditemukan.\n";
}

void AdminMenu::simpanDataKeFile()
{
    ofstream file("data_barang.txt");

    if (!file.is_open())
    {
        cerr << "Gagal membuka file untuk penyimpanan data.\n";
        return;
    }
    Barang *current = head;
    while (current != NULL)
    {
        file << current->idBarang << "\n";
        file << current->namaBarang << "\n";
        file << current->harga << "\n";
        file << current->stock << "\n";
        current = current->next;
    }

    file.close();
}

void AdminMenu::bacaDataDariFile()
{
    ifstream file("data_barang.txt");

    if (!file.is_open())
    {
        cerr << "File data_barang.txt tidak ditemukan. Membuat file baru.\n";
        return;
    }

    int id, stock;
    double harga;
    string nama;

    while (file >> id >> ws && getline(file, nama) && file >> harga >> stock)
    {
        Barang *newBarang = new Barang{id, nama, harga, stock, NULL};

        if (head == NULL)
        {
            head = newBarang;
        }
        else
        {
            Barang *last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newBarang;
        }

        if (id >= nextId)
        {
            nextId = id + 1;
        }
    }
    file.close();
}

