#include "tubes.h"
#include <stdio.h>

int main() {
    listPengendara L;
    string input, nik, namaMotor;
    adrPengendara PP;
    adrMotor PM;
    infoPengendara infoP;
    infoMotor infoM;
    int n;

    createListPengendara(L);

    while (true) {
        clearScreen();
        cout << "========== DATA PENGENDARA DAN MOTOR ==========" << endl;
        cout << "1. Insert Pengendara" << endl;
        cout << "2. Insert Motor" << endl;
        cout << "3. Search Pengendara" << endl;
        cout << "4. Search Motor" << endl;
        cout << "5. Delete Pengendara" << endl;
        cout << "6. Delete Motor" << endl;
        cout << "7. Show Jumlah Pengendara" << endl;
        cout << "8. Show Jumlah Motor" << endl;
        cout << "9. Show All Pengendara" << endl;
        cout << "10. Show All Motor" << endl;
        cout << "11. Exit" << endl;
        cout << "===============================================" << endl;

        cout << "Pilih: ";
        cin >> input;
        cout << endl;

        if (input == "1") {         // Insert Pengendara
            cout << "Masukkan Nama      : "; cin >> infoP.nama;
            cout << "Masukkan NIK       : "; cin >> infoP.nik;
            cout << "Masukkan Umur      : "; cin >> infoP.umur;
            cout << "Masukkan Alamat    : "; cin >> infoP.alamat;
            cout << endl;

            PP = createElmPengendara(infoP);
            insertFirstPengendara(L, PP);

            cout << "Insert Pengendara Baru berhasil" << endl;
            cout << endl;

            enterUntukLanjut();

        } else if (input == "2") {  // Insert Motor
            if (countPengendara(L) == 0) {
                cout << "List Pengendara Masih Kosong! Isikan dulu" << endl;
                cout << endl;

                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan NIK dari pengendara : "; cin >> nik;
            cout << endl;

            PP = searchPengendara(L, nik);

            if (PP == NULL) {
                cout << "Pengendara dengan NIK " << nik << " tidak dapat ditemukan!" << endl;
                cout << endl;

                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan Nama          : "; cin >> infoM.nama;
            cout << "Masukkan Merek         : "; cin >> infoM.merk;
            cout << "Masukkan Harga Sewa    : "; cin >> infoM.hargaSewa;
            cout << "Masukkan Nomor Plat    : "; cin >> infoM.nomorPlat;
            cout << endl;

            PM = createElmMotor(infoM);
            insertFirstMotor(PP->motor, PM);

            cout << "Insert Motor Baru berhasil" << endl;
            cout << endl;

            enterUntukLanjut();

        } else if (input == "3") {  // Search Pengendara
            if (countPengendara(L) == 0) {
                cout << "List Pengendara Masih Kosong! Isikan dulu" << endl;
                cout << endl;

                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan NIK : "; cin >> nik;
            cout << endl;

            PP = searchPengendara(L, nik);

            if (PP == NULL) {
                cout << "Data Pengendara dengan NIK " << nik << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama   : " << info(PP).nama << endl;
                cout << "NIK    : " << info(PP).nik << endl;
                cout << "Umur   : " << info(PP).umur << endl;
                cout << "Alamat : " << info(PP).alamat << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "4") {  // Search Motor
            if (countPengendara(L) == 0) {
                cout << "List Pengendara Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan NIK Pengendara : "; cin >> nik;

            PP = searchPengendara(L, nik);

            if (PP == NULL) {
                cout << "Data Pengendara dengan NIK " << nik << "tidak dapat ditemukan!" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan nama motor     : "; cin >> namaMotor;
            cout << endl;

            PM = searchMotor(L, nik, namaMotor);

            if (PM == NULL) {
                cout << "Data motor dengan nama " << namaMotor << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama        : " << info(PM).nama << endl;
                cout << "Merk        : " << info(PM).merk << endl;
                cout << "Harga Sewa  : " << info(PM).hargaSewa << endl;
                cout << "Nomor Plat  : " << info(PM).nomorPlat << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "5") {  // Delete Pengendara
            if (countPengendara(L) == 0) {
                cout << "List Pengendara Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan NIK : "; cin >> nik;
            cout << endl;

            deletePengendara(L, nik, PP);

            if (PP == NULL) {
                cout << "Data Pengendara dengan NIK " << nik << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Data Pengendara yang terhapus:" << endl;
                cout << "Nama   : " << info(PP).nama << endl;
                cout << "NIK    : " << info(PP).nik << endl;
                cout << "Umur   : " << info(PP).umur << endl;
                cout << "Alamat : " << info(PP).alamat << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "6") {  // Delete Motor
            if (countPengendara(L) == 0) {
                cout << "List Pengendara Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan NIK Pengendara : "; cin >> nik;

            PP = searchPengendara(L, nik);

            if (PP == NULL) {
                cout << "Data Pengendara dengan NIK " << nik << "tidak dapat ditemukan!" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan nama motor     : "; cin >> namaMotor;
            cout << endl;

            deleteMotor(L, nik, namaMotor, PM);

            if (PM == NULL) {
                cout << "Data motor dengan nama " << namaMotor << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama        : " << info(PM).nama << endl;
                cout << "Merk        : " << info(PM).merk << endl;
                cout << "Harga Sewa  : " << info(PM).hargaSewa << endl;
                cout << "Nomor Plat  : " << info(PM).nomorPlat << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "7") {  // Show Jumlah Pengendara
            n = countPengendara(L);
            cout << "Jumlah Pengendara dalam list adalah: " << n << endl;
            enterUntukLanjut();
        } else if (input == "8") {  // Show Jumlah Motor
            n = 0;

            PP = first(L);

            while (PP != NULL) {
                n += countMotor(PP->motor);
                PP = next(PP);
            }

            cout << "Jumlah Motor dalam list adalah: " << n << endl;
            cout << endl;

            enterUntukLanjut();

        } else if (input == "9") {  // Show All Pengendara
            if (countPengendara(L) == 0) {
                cout << "List Pengendara Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            showAllPengendara(L);
            enterUntukLanjut();
        } else if (input == "10") { // Show All Motor
            if (countPengendara(L) == 0) {
                cout << "List Pengendara Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan NIK : ";
            cin >> nik;
            PP = searchPengendara(L, nik);

            if (PP == NULL) {
                cout << "Data Pengendara dengan NIK " << nik << "tidak dapat ditemukan!" << endl;
                enterUntukLanjut();
                continue;
            }

            showAllMotor(PP->motor);
            cout << endl;

            enterUntukLanjut();

        } else if (input == "11") { // Exit
            break;
        } else {
            cout << "Input anda tidak valid." << endl;
            cout << endl;

            enterUntukLanjut();
        }
    }

    clearScreen();
    cout << "Bye!" << endl;

    return 0;
}
