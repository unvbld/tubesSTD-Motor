#include "tubes.h"

void createListPengendara(listPengendara &L) {
     first(L) = NULL;
}

void createListMotor(listMotor &L) {
     first(L) = NULL;
}

bool isPengendaraEmpty(listPengendara L) {
    if (first(L) == NULL) {
        return true;
    }
    return false;
}

bool isMotorEmpty(listMotor L) {
    if (first(L) == NULL) {
        return true;
    }
    return false;
}

adrPengendara createElmPengendara(infoPengendara x) {
    listMotor L;

    adrPengendara P = new elmPengendara;
    createListMotor(L);

    info(P) = x;
    next(P) = NULL;
    P->motor = L;
    return P;
}

adrMotor createElmMotor(infoMotor x) {
    adrMotor P = new elmMotor;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirstPengendara(listPengendara &L, adrPengendara P) {
    next(P) = first(L);
    first(L) = P;
}

void insertFirstMotor(listMotor &L, adrMotor P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLastPengendara(listPengendara &L, adrPengendara P) {
    adrPengendara last;

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

void insertLastMotor(listMotor &L, adrMotor P) {
    adrMotor last;

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

adrPengendara searchPengendara(listPengendara L, string nik) {
    adrPengendara P = first(L);

    while (P != NULL) {
        if (info(P).nik == nik) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

adrMotor searchMotor(listPengendara L, string nik, string namaMotor) {
    adrMotor Q;
    adrPengendara P = searchPengendara(L, nik);

    if (P == NULL) {
        return NULL;
    }

    Q = P->motor.first;

    while (Q != NULL) {
        if (info(Q).nama == namaMotor) {
            return Q;
        }

        Q = next(Q);
    }

    return NULL;
}

void deletePengendara(listPengendara &L, string nik, adrPengendara &P) {
    adrPengendara prec;

    P = searchPengendara(L, nik);

    if (P != NULL) {
        if (first(L) == P) {
            first(L) = next(P);
        } else {
            prec = first(L);

            while (next(prec) != P) {
                prec = next(prec);
            }

            next(prec) = next(P);
        }

        next(P) = NULL;
    }
}

void deleteMotor(listPengendara &L, string nik, string namaMotor, adrMotor &P) {
    adrPengendara PP;
    adrMotor prec;

    P = searchMotor(L, nik, namaMotor);

    if (P != NULL) {
        PP = searchPengendara(L, nik);

        if (first(PP->motor) == P) {
            first(PP->motor) = next(P);
        } else {
            prec = first(PP->motor);

            while (next(prec) != P) {
                prec = next(prec);
            }

            next(prec) = next(P);
        }

        next(P) = NULL;
    }
}

int countPengendara(listPengendara L) {
    int n = 0;
    adrPengendara P = first(L);

    while (P != NULL) {
        P = next(P);
        n++;
    }
    return n;
}

int countMotor(listMotor L) {
    int n = 0;
    adrMotor P = first(L);

    while (P != NULL) {
        P = next(P);
        n++;
    }
    return n;
}

void showAllPengendara(listPengendara L) {
    adrPengendara P = first(L);

    if (first(L) == NULL) {
        cout << "Tidak ada data" << endl;
        cout << endl;
    } else {
        cout << "========= Data Pengendara =========" << endl;

        while (P != NULL) {
            cout << "Nama   : " << info(P).nama << endl;
            cout << "NIK    : " << info(P).nik << endl;
            cout << "Umur   : " << info(P).umur << endl;
            cout << "Alamat : " << info(P).alamat << endl;
            cout << endl;

            P = next(P);
        }

        cout << "===================================" << endl;
    }
}

void showAllMotor(listMotor L) {
    adrMotor P = first(L);

    if (first(L) == NULL) {
        cout << "Tidak ada data" << endl;
        cout << endl;
    } else {
        cout << "=========== Data Motor ===========" << endl;

        while (P != NULL) {
            cout << "Nama        : " << info(P).nama << endl;
            cout << "Merk        : " << info(P).merk << endl;
            cout << "Harga Sewa  : " << info(P).hargaSewa << endl;
            cout << "Nomor Plat  : " << info(P).nomorPlat << endl;
            cout << endl;

            P = next(P);
        }

        cout << "==================================" << endl;
    }
}

void clearScreen() {
    cout << "\033[H\033[2J" << flush;
}

void enterUntukLanjut() {
    cout << "Tekan Enter untuk lanjut...";
    fflush(stdin);
    getchar();
    cout << endl;
}
