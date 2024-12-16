#include <iostream>  
#include <vector>    
#include <fstream>   
#include <string>
#include <algorithm> 
using namespace std;

struct Tugas {
    string deskripsi;  
    string status;      
    string prioritas;   
};

vector<Tugas> daftarTugas;

//Modul Input Data Tugas
void tambahTugas () {
    cout << "Masukkan deskripsi tugas : ";
    cin.ignore(); 
    string deskripsi;
    getline(cin, deskripsi); 
    cout << "Masukkan Prioritas Tugas (rendah/sedang/tinggi): ";
    string prioritas;
    cin >> prioritas;
    
    Tugas tugas;
    tugas.deskripsi = deskripsi;
    tugas.status = "Belum Selesai";
    tugas.prioritas = prioritas;
    daftarTugas.push_back(tugas);
    cout << "--------------------------------------------------------" << endl;
    cout << "Tugas berhasil ditambahkan." << endl;
    cout << "--------------------------------------------------------" << endl;
}

//Modul Tampilkan Data Tugas
void tampilkanTugas () {
    if (daftarTugas.empty()) {
        cout << "--------------------------------------------------------" << endl;
        cout << "Daftar Tugas Kosong." << endl;
        cout << "--------------------------------------------------------" << endl;
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << "Daftar Tugas" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (int i = 0; i < daftarTugas.size(); i++) {
            cout << i + 1 << ". " << daftarTugas[i].deskripsi 
                 << ", Status: " << daftarTugas[i].status
                 << ", Prioritas: " << daftarTugas[i].prioritas << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }       
}

//Modul Pembaruan Tugas
void ubahStatus() {
    tampilkanTugas();
    if (daftarTugas.empty()) {//Jika daftar tugas kosong, maka tampilkan pesan "Tidak ada tugas untuk diubah statusnya."
        cout << "Tidak ada tugas untuk diubah statusnya." << endl;
        cout << "--------------------------------------------------------" << endl;
        return;
    }
    
    cout << "Masukkan Nomor Tugas Yang Ingin Diubah Statusnya : ";
    int indeks;
    cin >> indeks;
    if (indeks > 0 && indeks <= daftarTugas.size()) {
        Tugas& tugas = daftarTugas[indeks - 1];//Ambil referensi tugas dari daftar tugas pada indeks dikurangi satu
        tugas.status = (tugas.status == "Belum Selesai") ? "Sudah Selesai" : "Belum Seles ai";
        cout << "--------------------------------------------------------" << endl;
        cout << "Status Tugas Berhasil Diubah." << endl;
        cout << "--------------------------------------------------------" << endl;
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << "Nomor tugas tidak valid." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
}

void ubahPrioritas() {
    tampilkanTugas();
    if (daftarTugas.empty()) { //Jika daftar tugas kosong, maka tampilkan pesan "Tidak ada tugas untuk diubah prioritasnya."
        cout << "Tidak ada tugas untuk diubah prioritasnya." << endl;
        cout << "--------------------------------------------------------" << endl;
        return;
    }
    
    cout << "Masukkan Nomor Tugas Yang Ingin Diubah Prioritasnya : ";
    int indeks;
    cin >> indeks;
    if (indeks > 0 && indeks <= daftarTugas.size()) {
        cout << "Masukkan Prioritas Tugas (rendah/sedang/tinggi): ";
        string prioritas;
        cin >> prioritas;
        Tugas& tugas = daftarTugas[indeks - 1]; //Ambil referensi tugas dari daftar tugas pada indeks dikurangi satu.
        tugas.prioritas = prioritas;
        cout << "--------------------------------------------------------" << endl;
        cout << "Prioritas Tugas Berhasil Diubah." << endl;
        cout << "--------------------------------------------------------" << endl;
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << "Nomor tugas tidak valid." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
}

void ubahStatusDanPrioritas() {
    cout << "Pilih opsi:" << endl;
    cout << "1. Ubah Status" << endl;
    cout << "2. Ubah Prioritas" << endl;
    cout << "Opsi : ";
    int pilihan;
    cin >> pilihan;
    if (pilihan == 1) {
        ubahStatus();
    } else if (pilihan == 2) {
        ubahPrioritas();
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << "Pilihan tidak valid." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
}

//Modul Pencarian Tugas
void cariTugasByStatus() {
    cout << "Masukkan status yang ingin dicari (Belum Selesai/Sudah Selesai): ";
    cin.ignore();
    string status;
    getline(cin, status);
    cout << "--------------------------------------------------------" << endl;
    cout << "Hasil Pencarian Tugas dengan Status '" << status << "':" << endl;
    cout << "--------------------------------------------------------" << endl;
    bool found = false; //menandai apakah ada tugas yang ditemukan.
    for (const Tugas& tugas : daftarTugas) { //Melakukan iterasi melalui setiap objek tugas dalam daftarTugas.
        if (tugas.status == status) {
            cout << "Deskripsi: " << tugas.deskripsi 
                 << ", Prioritas: " << tugas.prioritas << endl;
            found = true;//Menandai bahwa setidaknya satu tugas ditemukan.
        }
    }
    if (!found) {
        cout << "Tidak ada tugas dengan status '" << status << "'." << endl;
    }
    cout << "--------------------------------------------------------" << endl;
}

void cariTugasByPrioritas() {
    cout << "Masukkan prioritas yang ingin dicari (rendah/sedang/tinggi): ";
    cin.ignore();
    string prioritas;
    getline(cin, prioritas);
    cout << "--------------------------------------------------------" << endl;
    cout << "Hasil Pencarian Tugas dengan Prioritas '" << prioritas << "':" << endl;
    cout << "--------------------------------------------------------" << endl;
    bool found = false; //menandai apakah ada tugas yang ditemukan.
    for (const Tugas& tugas : daftarTugas) { //Melakukan iterasi melalui setiap objek tugas dalam daftarTugas.
        if (tugas.prioritas == prioritas) {
            cout << "Deskripsi: " << tugas.deskripsi 
                 << ", Status: " << tugas.status << endl;
            found = true; //Menandai bahwa setidaknya satu tugas ditemukan.
        }
    }
    if (!found) {
        cout << "Tidak ada tugas dengan prioritas '" << prioritas << "'." << endl;
    }
    cout << "--------------------------------------------------------" << endl;
}

void cariTugas() {
    cout << "Pilih opsi:" << endl;
    cout << "1. Cari Berdasarkan Status" << endl;
    cout << "2. Cari Berdasarkan Prioritas" << endl;
    cout << "Opsi : ";
    int pilihan;
    cin >> pilihan;
    if (pilihan == 1) {
        cariTugasByStatus();
    } else if (pilihan == 2) {
        cariTugasByPrioritas();
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << "Pilihan tidak valid." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
}

//Modul Penghapusan Tugas
void hapusTugas () {
    cout << "Pilih opsi: " << endl;
    cout << "1. Hapus Tugas Tertentu" << endl;
    cout << "2. Hapus Semua Tugas" << endl;
    cout << "Opsi : ";
    int pilihan;
    cin >> pilihan;
    if (pilihan == 1) {
        tampilkanTugas ();
        if (daftarTugas.empty()) {
            cout << "Tidak ada tugas untuk dihapus." << endl;
            cout << "--------------------------------------------------------" << endl;
            return;
        }
        
        cout << "Masukkan Nomor Tugas Yang Ingin Dihapus : ";
        int indeks;
        cin >> indeks;
        /*Jika indeks lebih besar dari 0 dan indeks kurang dari atau sama dengan ukuran daftar tugas,
        maka hapus elemen pada daftar tugas di posisi indeks dikurangi satu.*/
        if (indeks > 0 && indeks <= daftarTugas.size()) {
            daftarTugas.erase(daftarTugas.begin() + (indeks - 1));
            cout << "--------------------------------------------------------" << endl;
            cout << "Tugas berhasil dihapus." << endl;
            cout << "--------------------------------------------------------" << endl;
        } else {
            cout << "--------------------------------------------------------" << endl;
            cout << "Nomor tugas tidak valid." << endl;
            cout << "--------------------------------------------------------" << endl;
        }
    } else if (pilihan == 2) {
        daftarTugas.clear ();
        cout << "--------------------------------------------------------" << endl;
        cout << "Semua tugas berhasil dihapus." << endl;
        cout << "--------------------------------------------------------" << endl;
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << "Pilihan tidak valid." << endl;
        cout << "--------------------------------------------------------" << endl;
    }
}

//Modul Penyimpanan
void simpanData(const string& namaFile) {
    ofstream file(namaFile);
    if (!file.is_open()) {
        cout << "--------------------------------------------------------" << endl;
        cout << "Gagal membuka file " << namaFile << endl;
        cout << "--------------------------------------------------------" << endl;
        return;
    }
    for (const Tugas& tugas : daftarTugas) { 
        file << tugas.deskripsi << "|" << tugas.status << "|" << tugas.prioritas << endl;
    }
    file.close();
    cout << "--------------------------------------------------------" << endl;
    cout << "Data berhasil disimpan ke file " << namaFile << endl;
    cout << "--------------------------------------------------------" << endl;
}

void muatData(const string& namaFile) {
    ifstream file(namaFile);
    if (!file.is_open()) {
        cout << "--------------------------------------------------------" << endl;
        cout << "Gagal membuka file " << namaFile << endl;
        cout << "--------------------------------------------------------" << endl;
        return;
    }
    daftarTugas.clear();
    string baris;
    while (getline(file, baris)) {
        size_t pos1 = baris.find('|');
        size_t pos2 = baris.rfind('|');
        if (pos1 != string::npos && pos2 != string::npos) {
            Tugas tugas;
            tugas.deskripsi = baris.substr(0, pos1);
            tugas.status = baris.substr(pos1 + 1, pos2 - pos1 - 1);
            tugas.prioritas = baris.substr(pos2 + 1);
            daftarTugas.push_back(tugas);
        }
    }
    file.close();
    cout << "--------------------------------------------------------" << endl;
    cout << "Data berhasil dimuat dari file " << namaFile << endl;
    cout << "--------------------------------------------------------" << endl;
}

void simpanTugas () {
    string namaFile;
    cout << "Masukkan nama file untuk menyimpan data : ";
    cin.ignore();
    getline(cin, namaFile);
    simpanData(namaFile);
}

void muatTugas () {
    string namaFile;
    cout << "Masukkan nama file untuk memuat data : ";
    cin.ignore();
    getline(cin, namaFile);
    muatData(namaFile);
}

void savedanload () {
    cout << "Pilih opsi: " << endl;
    cout << "1. Simpan Data" << endl;
    cout << "2. Muat Data" << endl;
    cout << "Opsi : ";
    int opsi;
    cin >> opsi;
    if (opsi == 1) {
        simpanTugas();
    } else if (opsi == 2) {
        muatTugas();
    } else {
        cout << "--------------------------------------------------------" << endl;
        cout << "Opsi tidak valid" << endl;
        cout << "--------------------------------------------------------" << endl;
    }
}

void tampilkanmenu () {
        cout << "Menu Aplikasi Manajemen Tugas" << endl;
        cout << "1. Tambah Tugas Baru" << endl;
        cout << "2. Tampilkan Daftar Tugas" << endl;
        cout << "3. Ubah Status dan Prioritas" << endl;
        cout << "4. Hapus Tugas" << endl;
        cout << "5. Cari Tugas" << endl;
        cout << "6. Save & Load Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
}

int main() {
    bool lanjut = true;
    
    while (lanjut) {
        tampilkanmenu ();
        int pilihan;
        cin >> pilihan;

        if (pilihan == 0) {
            lanjut = false;//Keluar Dari Program
        } else if (pilihan == 1) {
            tambahTugas();//Memanggil Fungsi Tambah Tugas
        } else if (pilihan == 2) {
            tampilkanTugas();//Memanggil Fungsi Tampilkan Tugas
        } else if (pilihan == 3) {
            ubahStatusDanPrioritas();//Memanggil Fungsi Ubah Status dan Prioritas
        } else if (pilihan == 4) {
            hapusTugas();//Memanggil Fungsi Hapus Tugas
        } else if (pilihan == 5) {
            cariTugas();//Memanggil Fungsi Cari Tugas
        } else if (pilihan == 6) {
            savedanload();//Memanggil Fungsi Save & Load Data
        } else {
            cout << "--------------------------------------------------------" << endl;
            cout << "Pilihan tidak valid. Silahkan coba lagi" << endl;
            cout << "--------------------------------------------------------" << endl;
        }
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "Terima kasih telah menggunakan Aplikasi Manajemen Tugas!" << endl;
    cout << "--------------------------------------------------------" << endl;
    return 0;
}
