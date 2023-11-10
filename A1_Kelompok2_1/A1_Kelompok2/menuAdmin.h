#ifndef PROSES_H
#define PROSES_H

#include <string>

class Barang
{
public:
    int idBarang;
    std::string namaBarang;
    double harga;
    int stock;
    Barang *next;
    Barang *prev;

};

class AdminMenu
{
private:
    Barang *head;
    int nextId;

    // Deklarasi fungsi sorting yang belum ada
    

public:
    AdminMenu();
    ~AdminMenu();

    // Fungsi-fungsi lainnya
    
    void menuAdmin();
    void tambahBarang();
    void lihatListBarang();
    void editBarang();
    void hapusBarang();
    void urutkanDataBarang();
    void mergeSortByHarga(bool ascending);
    void mergeSortByNama(bool ascending);
    void mergeSortByID(bool ascending);
    void mergeSortByStock(bool ascending);
    void splitList(Barang *source, Barang **frontRef, Barang **backRef);
    Barang *mergeSortByHargaUtil(Barang *headRef, bool ascending);
    Barang *mergeByHarga(Barang *front, Barang *back, bool ascending);
    Barang *mergeSortByNamaUtil(Barang *headRef, bool ascending);
    Barang *mergeByNama(Barang *front, Barang *back, bool ascending);
    Barang *mergeSortByIDUtil(Barang *headRef, bool ascending);
    Barang *mergeByID(Barang *front, Barang *back, bool ascending);
    Barang *mergeSortByStockUtil(Barang *headRef, bool ascending);
    Barang *mergeByStock(Barang *front, Barang *back, bool ascending);
    void cariBarang();
    void cariBarangByID(int idToSearch);
    void cariBarangByNama(const std::string &namaToSearch);
    Barang *fibonacciSearchByID(Barang *head, int idToSearch);
    Barang *fibonacciSearchByNama(Barang *head, const std::string &namaToSearch);
    void lihatDataPengunjung();
    void lihatDataPesanan();
    bool logOut();
    void simpanDataKeFile();
    void bacaDataDariFile();
    void ubahStatusPesanan();
    void tampilDataPesanan();
    

    // Tambahkan deklarasi fungsi sorting
};

#endif // PROSES_H