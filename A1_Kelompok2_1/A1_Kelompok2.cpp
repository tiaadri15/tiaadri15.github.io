#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
#include "mainUser.cpp"
#include "mainAdmin.cpp"
#include <cctype> // Diperlukan untuk isdigit dan isupper
#include <limits> // Diperlukan untuk membersihkan buffer input

using namespace std;

// Inisialisasi nama file menjadi FILENAME
const string FILENAME = "user_data.txt";
// username dan password admin
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "admin123";

// Struct Data User
struct DataPengguna
{
    int id;
    string namaPengguna;
    string kataSandi;
    DataPengguna *next;
};


// MEMBACA DATA DARI FILE
DataPengguna *bacaDataPenggunaDariFile(const string &namaFile)
{
    // membaca file user_data.txt
    ifstream file(namaFile);
    string line;
    DataPengguna *daftarPengguna = NULL;
    DataPengguna *currentUser = NULL;
    int i = 1;

    while (getline(file, line))
    {
        istringstream iss(line);
        DataPengguna *newNode = new DataPengguna;
        if (iss >> newNode->namaPengguna >> newNode->kataSandi)
        {
            newNode->id = i++;
            newNode->next = NULL;

            if (!daftarPengguna)
            {
                daftarPengguna = newNode;
                currentUser = daftarPengguna;
            }
            else
            {
                currentUser->next = newNode;
                currentUser = newNode;
            }
        }
    }

    file.close();
    return daftarPengguna;
}

// MENULIS DATA KE FILE
void tulisDataPenggunaKeFile(const string &namaFile, DataPengguna *daftarPengguna)
{
    ofstream file(namaFile);
    DataPengguna *current = daftarPengguna;

    while (current)
    {
        file << current->id << " " << current->namaPengguna << " " << current->kataSandi << endl;
        current = current->next;
    }

    file.close();
}

// ERROR HANDLING USERNAME
bool isValidNamaPengguna(const string &namaPengguna)
{
    if (namaPengguna.length() > 0 && namaPengguna.length() <= 8)
    {
        bool hasDigit = false;
        bool hasUpper = false;
        bool hasLetters = false;
        for (char c : namaPengguna)
        {
            if (isdigit(c))
            {
                hasDigit = true;
            }
            if (isupper(c))
            {
                hasUpper = true;
            }
            if (isalnum(c))
            {
                hasLetters = true;
            }
        }
        return hasDigit && hasUpper;
    }
    return !namaPengguna.empty();
}

// ERROR HANDING PASSWORD
bool isValidKataSandi(const string &namaPengguna, const string &kataSandi)
{
    if (kataSandi.length() <= 8 && kataSandi != namaPengguna)
    {
        bool hasDigit = false;
        bool hasUpper = false;
        for (char c : kataSandi)
        {
            if (isdigit(c))
            {
                hasDigit = true;
            }
            if (isupper(c))
            {
                hasUpper = true;
            }
        }
        return hasDigit && hasUpper;
    }
    return !kataSandi.empty();
}

// REGISTRASI
DataPengguna *daftarPenggunaBaru(DataPengguna *daftarPengguna)
{
    string namaPengguna;
    string kataSandi;
    system("cls");

    cout << "+-------------------------------------+" << endl;
    cout << "|         R E G I S T R A S I         |" << endl;
    cout << "+-------------------------------------+" << endl
         << endl;
    cout << "Masukkan nama pengguna: ";
    cin >> namaPengguna;

    if (!isValidNamaPengguna(namaPengguna))
    {
        cout << "Nama pengguna tidak valid. Pendaftaran gagal." << endl;
        return daftarPengguna;
    }

    cout << "Masukkan kata sandi: ";
    cin >> kataSandi;

    if (!isValidKataSandi(namaPengguna, kataSandi))
    {
        cout << "Kata sandi tidak valid. Pendaftaran gagal." << endl;
        return daftarPengguna;
    }

    // Generate ID for the new user
    int newId = 0;
    if (daftarPengguna)
    {
        DataPengguna *lastUser = daftarPengguna;
        while (lastUser->next)
        {
            lastUser = lastUser->next;
        }
        newId = lastUser->id + 1;
    }
    else
    {
        newId = 1;
    }

    // Membuat Akun user baru
    DataPengguna *newUser = new DataPengguna{newId, namaPengguna, kataSandi, NULL};

    if (!daftarPengguna)
    {
        daftarPengguna = newUser;
    }
    else
    {
        DataPengguna *lastUser = daftarPengguna;
        while (lastUser->next)
        {
            lastUser = lastUser->next;
        }
        lastUser->next = newUser;
    }

    // Menyimpan data pengguna ke file eksternal
    tulisDataPenggunaKeFile(FILENAME, daftarPengguna);

    cout << "Registrasi Berhasil, Silahkan Login untuk Melanjutkan" << endl;
    system("pause");

    return daftarPengguna;
}

// LOGIN ADMIN
bool loginAdmin()
{
    system("cls");
    string namaPengguna, kataSandi;

    cout << "+-------------------------------------+" << endl;
    cout << "|         L O G I N  A D M I N        |" << endl;
    cout << "+-------------------------------------+" << endl
         << endl;
    cout << "Masukkan nama pengguna: ";
    cin >> namaPengguna;
    cout << "Masukkan kata sandi: ";
    cin >> kataSandi;

    if (namaPengguna == ADMIN_USERNAME && kataSandi == ADMIN_PASSWORD)
    {
        cout << "\nAnda Berhasil Login sebagai Admin!" << endl;
        AdminMenu adminMenu;
        adminMenu.menuAdmin();
        return true;
    }

    cout << "\nLogin gagal. Nama pengguna atau kata sandi salah atau bukan admin." << endl;
    system("pause");
    return false;
}

// LOGIN USER
bool loginPengguna(DataPengguna *daftarPengguna)
{
    system("cls");
    string namaPengguna, kataSandi;

    cout << "+--------------------------------------+" << endl;
    cout << "|     L O G I N   P E N G G U N A      |" << endl;
    cout << "+--------------------------------------+" << endl
         << endl;
    cout << "Masukkan nama pengguna: ";
    cin >> namaPengguna;
    cout << "Masukkan kata sandi: ";
    cin >> kataSandi;

    DataPengguna *currentUser = daftarPengguna;

    while (currentUser)
    {
        if (currentUser->namaPengguna == namaPengguna && currentUser->kataSandi == kataSandi)
        {
            cout << "\nAnda Berhasil Login sebagai Pengguna!" << endl;
            mainUser();
            return true;
        }
        currentUser = currentUser->next;
    }

    cout << "\nLogin gagal. Nama pengguna atau kata sandi salah." << endl;
    system("pause");
    return false;
}

// ERROR HANDLING MENU
bool isInputValid()
{
    if (cin.fail())
    {
        cin.clear();                                         // Menghapus flag kesalahan
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan buffer input
        return false;
    }
    return true;
}

// MENU LOGIN
void menuLogin()
{
    DataPengguna *daftarPengguna = bacaDataPenggunaDariFile(FILENAME);
    while (true)
    {
        system("cls");

        int pilihan_2;
        cout << "+-------------------------------------+" << endl;
        cout << "|          M E N U  L O G I N         |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|          [1]. Login User            |" << endl;
        cout << "|          [2]. Login Admin           |" << endl;
        cout << "|          [0]. Back                  |" << endl;
        cout << "+-------------------------------------+" << endl;

        cout << "\nMasukkan pilihan Anda (1/2/0) : ";
        cin >> pilihan_2;

        if (isInputValid())
        {
            switch (pilihan_2)
            {
            case 1:
                if (loginPengguna(daftarPengguna))
                {
                    system("cls");
                }
                break;
            case 2:
                if (loginAdmin())
                {
                    system("cls");
                }
                break;
            case 0:
                return; // Kembali ke pemanggilan fungsi sebelumnya (main)
            default:
                cout << "\nPilihan Tidak Valid. Silahkan Masukkan Pilihan yang Valid." << endl;
                system("pause");
            }
        }
        else
        {
            cout << "\nPilihan Tidak Valid. Silahkan Masukkan Pilihan yang Valid." << endl;
            system("pause");
        }
    }
}

int main()
{
    DataPengguna *daftarPengguna = bacaDataPenggunaDariFile(FILENAME);

    // Add admin user if the list is empty
    if (!daftarPengguna)
    {
        daftarPengguna = new DataPengguna{1, "admin", "Admin123", NULL};
        tulisDataPenggunaKeFile(FILENAME, daftarPengguna);
    }

    int pilihan;
    do
    {
        system("cls");
        cout << "+---------------------------------------------------------+" << endl;
        cout << "|   W E L L C O M E  T O  G W E N C H A N A  M E R C H A N  |" << endl;
        cout << "+---------------------------------------------------------+" << endl;
        cout << "|                   M E N U  U T A M A                    |" << endl;
        cout << "|                                                         |" << endl;
        cout << "|                        1. Login                         |" << endl;
        cout << "|                        2. Register                      |" << endl;
        cout << "|                        3. Exit                          |" << endl;
        cout << "+---------------------------------------------------------+" << endl;

        cout << " Masukkan pilihan Anda (1/2/3) : ";
        cin >> pilihan;

        if (!isInputValid())
        {
            cout << "\nPilihan Tidak Valid. Silahkan Masukkan Pilihan yang Valid." << endl;
            system("pause");
            continue; // Lanjut ke iterasi berikutnya jika input tidak valid
        }

        switch (pilihan)
        {
        case 1:
            menuLogin();
            break;
        case 2:
            daftarPengguna = daftarPenggunaBaru(daftarPengguna);
            tulisDataPenggunaKeFile(FILENAME, daftarPengguna);
            break;
        case 3:
            break;
        default:
            cout << "\nPilihan Anda Tidak Valid. Silahkan Masukkan Pilihan yang Valid." << endl;
            system("pause");
        }
    } while (pilihan != 3);

    return 0;
}
