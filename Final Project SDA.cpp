#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string prodi;
    float ipk;
};

void bubbleSort(Mahasiswa data[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j].ipk < data[j + 1].ipk) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void tampilkanRankingPerProdi(Mahasiswa data[], int n) {
    cout << "\n=== Ranking Mahasiswa Berdasarkan IPK per Prodi ===\n";
    string prodiDitampilkan[100];
    int jumlahProdi = 0;

    for (int i = 0; i < n; ++i) {
        bool sudahAda = false;
        for (int j = 0; j < jumlahProdi; ++j) {
            if (prodiDitampilkan[j] == data[i].prodi) {
                sudahAda = true;
                break;
            }
        }

        if (!sudahAda) {
            prodiDitampilkan[jumlahProdi++] = data[i].prodi;

            Mahasiswa sementara[100];
            int jumlah = 0;
            for (int j = 0; j < n; ++j) {
                if (data[j].prodi == data[i].prodi) {
                    sementara[jumlah++] = data[j];
                }
            }

            bubbleSort(sementara, jumlah);

            cout << "\n>> Prodi: " << data[i].prodi << endl;
            for (int r = 0; r < jumlah; ++r) {
                cout << "Ranking " << r + 1 << ": " << sementara[r].nama
                     << " - IPK: " << sementara[r].ipk << endl;
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    Mahasiswa data[100];
    cin.ignore(); // untuk membersihkan newline sisa dari cin sebelumnya

    for (int i = 0; i < n; ++i) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        getline(cin, data[i].nama);
        cout << "Prodi: ";
        getline(cin, data[i].prodi);
        cout << "IPK: ";
        cin >> data[i].ipk;
        cin.ignore(); // membersihkan newline sebelum getline berikutnya
    }

    tampilkanRankingPerProdi(data, n);
    return 0;
}
    