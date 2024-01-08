#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <limits>

using namespace std;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) ((L).first)

typedef struct elmPengendara *adrPengendara;
typedef struct elmMotor *adrMotor;

struct listPengendara {
    adrPengendara first;
};

struct listMotor {
    adrMotor first;
};

struct infoPengendara {
    string nama;
    string nik;
    int umur;
    string alamat;
};

struct infoMotor {
    string nama;
    string merk;
    float hargaSewa;
    int nomorPlat;
};

struct elmPengendara {
    infoPengendara info;
    adrPengendara next;
    listMotor motor;
};

struct elmMotor {
    infoMotor info;
    adrMotor next;
};

void createListPengendara(listPengendara &L);
void createListMotor(listMotor &L);
bool isPengendaraEmpty(listPengendara L);
bool isMotorEmpty(listMotor L);
adrPengendara createElmPengendara(infoPengendara x);
adrMotor createElmMotor(infoMotor x);
void insertFirstPengendara(listPengendara &L, adrPengendara P);
void insertFirstMotor(listMotor &L, adrMotor P);
void insertLastPengendara(listPengendara &L, adrPengendara P);
void insertLastMotor(listMotor &L, adrMotor P);
void deletePengendara(listPengendara &L, string nik, adrPengendara &P);
void deleteMotor(listPengendara &L, string nik, string namaMotor, adrMotor &P);
adrPengendara searchPengendara(listPengendara L, string nik);
adrMotor searchMotor(listPengendara L, string nik, string namaMotor);
int countPengendara(listPengendara L);
int countMotor(listMotor L);
void showAllPengendara(listPengendara L);
void showAllMotor(listMotor L);
void clearScreen();
void enterUntukLanjut();

#endif // ADT_H_INCLUDED
