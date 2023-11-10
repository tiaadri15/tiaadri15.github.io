#ifndef pesanan_H
#define pesanan_H
#include <string>

using namespace std;

struct Pesanan
{
    int idPesanan;
    int idBarang;
    string namaCustomer;
    string namaBarang;
    string alamat;
    string telepon;
    string status;
    Pesanan *next;
};

const int MAX_PESANAN = 100;
Pesanan DaftarPesanan[MAX_PESANAN];
int total_pesanan = 0;

#endif