/*  File        : Spkasir.h 
    Deskripsi   : Header untuk program antrian pelanggan di kassa
    Identitas   : Alisha Nara Chandrakirana     (221524033)
                  Keanu Rayhan Harits           (221524043)
                  Niqa Nabila Nur Ihsani        (221524054)
    Kelompok    : 2C
    Kelas       : 1B-D4IT
    Mata Kuliah : Struktur Data dan Algoritma
    Tugas       : Tugas Besar membuat program antrian pelanggan pada kassa di minimarket
    Tanggal     : 27 Maret 2023 s.d. 7 Mei 2023
                  Update 9 Mei 2023
*/

#ifndef spkasir_H
#define spkasir_H
#include <stdbool.h>
#include <stdio.h>
#define jmlK 3
#define NAMA 30
#define Max_Barang 100
#define Max_Nama_Barang 30

typedef char* infotype;
typedef struct tElmtListP *addressP;
typedef struct tElmtListB *addressB;

/*--STRUKTUR DATA KASIR--*/
// berbentuk array, sehingga jumlahnya sudah pasti, di program ini kasirnya 2.
typedef struct{
    char infoK[8];
    addressP cust;   // pointer next dari kasir ke pelanggan pertama
}ElmtListK;

ElmtListK ListK[jmlK];

/*--STRUKTUR DATA PELANGGAN--*/
// berbentuk double linked list nrll. Memiliki head dan tail, serta pointer before dan after.
typedef struct tElmtListP{
    infotype infoP;
    addressP before; // pointer untuk menunjuk ke pelanggan sebelumnya
    addressP after; // pointer untuk menunjuk ke pelanggan setelahnya
    addressB cart; // pointer untuk menunjuk barang belanjaannya
} ElmtListP;

typedef struct{
    addressP head;   
    addressP tail;
} ListP;

/*--STRUKTUR DATA BARANG BELANJA--*/
// berbentuk double linked list nrll. memiliki first dan last, serta pointer prev dan next.
typedef struct tElmtListB{
    infotype infoB;
    int qtyB;   
    addressB prev;
    addressB next;
} ElmtListB;

typedef struct{
    addressB first;
    addressB last;
} ListB;

/*--STRUKTUR DATA FILE BARANG BELANJA--*/
typedef struct {
    char nama[Max_Nama_Barang];
    int harga;
    int stok;
} Barang;

Barang listBarang[Max_Barang];
int jumlahBarang=0;

// kalau list pakai inisial (K, P, B)
// kalau infotype pakai inisial (ksr, plgn, brg)
// kalau address pakai inisial (kas, pel, bar)
/*********** PROTOTYPE ****************/

/**** Display ****/
void warnateks(int warna);
// void gotoxy(int x, int y);
// void DisplayLoading();
// void loading(int bg, int fg, int panjang, int delay, int simbol[20]);
void DisplayMenuAwal();     //alisha & niqa
void DisplayMenuMasuk();    //alisha
void DisplayMenuLanjutan(); //alisha
void DisplayBelanja();      //keanu
void DisplayAturan();       //alisha
void DisplayMenuBelanja();  //alisha
void DisplayAntri();        //alisha
void DisplayThank();        //keanu

/* ==================== KEBUTUHAN KASSA ==================== */
/* IS : elemen dari array belum terisi */
/* FS : Terbentuk List dengan array yang sudah terisi elemen */
void CreateListK();                                             //alisha

/* IS : Terdapat ListK yang sudah dibuat */
/* FS : menampilkan pada layar info dari ListK */
void PrintInfoK();                                              //alisha

/* IS : Terdapat ListK dan ListP yang sudah dibuat */
/* FS : menampilkan pada layar info dari salah satu ListK */
void PrintCustK (ListP P, int id);                              //keanu

/* IS : sudah ada elemen pada list lain dengan tipe struct yang sama */
/* FS : elemen dari list lain berpindah ke list tujuan untuk dihubungkan dengan ListK[id].cust */
void InsertToK(ListP *P, addressP pel, int id);                 //alisha


/* ==================== KEBUTUHAN PELANGGAN ==================== */
// mengirim true jika kosong
bool ListEmptyP (ListP P);                                      //niqa

/* IS : P sembarang */
/* FS : Terbentuk List Kosong */
void CreateListP (ListP *P);                                    //keanu

/* Mengirimkan addressP hasil alokasi sebuah elemen */
addressP AlokasiP (infotype plgn);                              //keanu

/* Mencari apakah ada elemen list dengan infoP = plgn */
/* Jika ada, mengirimkan address elemen tsb. */
addressP SearchP (ListP P, infotype plgn);                      //alisha

/* IS : P mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
void InsVLastP (ListP *P, infotype plgn);                       //alisha

/* IS : P sembarang, pel sudah dialokasi */
/* FS : pel ditambahkan sebagai elemen terakhir yang baru */
void InsertLastP (ListP *P, addressP pel);                      //alisha

/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke plgn */
/* 	dan alamat elemen pertama di dealokasi */
void DelVFirstP (ListP *P, int id);                             //keanu

// void DelAnyP (ListP *P, infotype plgn)

/* ==================== KEBUTUHAN BARANG ==================== */
// mengirim true jika kosong
bool ListEmptyB (ListB B);                                      //niqa

/* IS : B sembarang */
/* FS : Terbentuk List Kosong */
void CreateListB (ListB *B);                                    //niqa

/* Mengirimkan addressB hasil alokasi sebuah elemen */
addressB AlokasiB (infotype brg, int qty);                      //keanu

/* Mencari apakah ada elemen list dengan infoB = brg  */
/* Jika ada, mengirimkan address elemen tsb. */
addressB SearchB (addressP pel, infotype brg);                  //alisha

/* IS : mendapatkan alamat pelanggan */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
void InsVLastB(addressP pel, infotype brg, int qty);            //alisha

/* IS : mendapatkan alamat pelanggan, bar sudah dialokasi */
/* FS : bar ditambahkan sebagai elemen terakhir yang baru */
void InsertLastB(addressP pel, addressB bar);                   //alisha

/* IS : barang pada pelanggan tidak kosong */
/* FS : barang dengan infotype brg didealokasi */
void DelAnyB(addressP pel, infotype brg);                       //keanu

/* IS : barang pada pelanggan tidak kosong */
/* FS : Delete semua elemen barang dan di dealokasi*/
void DelAllB(addressP pel);                                     //keanu

/* IS : sudah ada barang dengan jumlah yang dipilih */
/* FS : jumlah barang atau qty berubah */
void updateQty(addressP pel, infotype brg, int qty);            //keanu


/* ==================== KEBUTUHAN LAINNYA ==================== */
/* Mengirimkan infotype hasil alokasi sebuah elemen */
infotype AlokasiInfo();                                         //alisha

/* IS : Terdapat ListK dan ListP yang sudah dibuat */
/* FS : menampilkan pada layar info dari ListK dan ListP */
void PrintInfoKP (ListP P1, ListP P2, ListP P3, ListP temp);    //alisha

/* IS : Terdapat ListP dan ListB yang sudah dibuat */
/* FS : menampilkan pada layar info dari ListP dan ListB */
void PrintInfoPB (ListP P, int id);                             //keanu

/* IS : terdapat file txt yang akan dibuka */
/* FS : melakukan pemisahan string */
void LoadBFromFile();                                           //niqa

/* IS : terdapat file txt yang stringnya sudah di format */
/* FS : menampilkan pada layar, info dari file txt */
void PrintB();                                                  //niqa

// int CountQtyB
// int CountP(ListP P, int indexK);

#endif