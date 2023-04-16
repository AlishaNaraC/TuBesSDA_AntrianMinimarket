/*  File        : Spkasir.h 
    Deskripsi   : Header untuk program antrian pelanggan di kassa
    Identitas   : Alisha Nara Chandrakirana     (221524033)
                  Keanu Rayhan Harits           (221524043)
                  Niqa Nabila Nur Ihsani        (221524054)
    Kelompok    : 2C
    Kelas       : 1B-D4IT
    Mata Kuliah : Struktur Data dan Algoritma
    Tugas       : Tugas Besar membuat program antrian pelanggan pada kassa di minimarket
    Tanggal     : 27 Maret 2023 s.d. 
*/

#ifndef spkasir_H
#define spkasir_H
#include <stdbool.h>
#include <stdio.h>
#define jmlK 3

typedef char *infotype;
/*Start: */
/*--STRUKTUR DATA KASIR--*/
// berbentuk array, sehingga jumlahnya sudah pasti, di program ini kasirnya 2.
typedef struct tElmtListK *addressK;
typedef struct tElmtListK{
    infotype infoK;
    addressK cust;   // pointer next dari kasir ke pelanggan pertama
}ElmtListK;

typedef ElmtListK ListK[jmlK];

/*--STRUKTUR DATA PELANGGAN--*/
// berbentuk double linked list nrll. Memiliki head dan tail, serta pointer before dan after.
typedef struct tElmtListP *addressP;
typedef struct tElmtListP{
    infotype infoP;
    addressP before; // pointer untuk menunjuk ke pelanggan sebelumnya
    addressP after; // pointer untuk menunjuk ke pelanggan setelahnya
    addressP cart; // pointer untuk menunjuk barang belanjaannya
} ElmtListP;

typedef struct{
    addressP head;   
    addressP tail;
} ListP;

/*--STRUKTUR DATA BARANG BELANJA--*/
// berbentuk double linked list nrll. memiliki first dan last, serta pointer prev dan next.
typedef struct tElmtListB *addressB;
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
/*Finish, dikerjakan pada tanggal: 28/03/2023*/

// kalau list pakai inisial (K, P, B)
// kalau infotype pakai inisial (ksr, plgn, brg)
// kalau address pakai inisial (kas, pel, bar)
/*********** PROTOTYPE ****************/

/**** Display ****/
void DisplayMenuAwal();
void DisplayMenuMasuk();
void DisplayMenuKeluar();
void DisplayMenuLanjutan();
void DisplayMenuBelanja();
void DisplayMenuKassa();
void DisplayAturan();

/**** Predikat untuk test keadaan LIST  ****/
// untuk pelanggan, mengecek apakah node pelanggan ada/tidak ada
// untuk barang, mengecek apakah node barang pada seorang pelanggan ada/tidak ada
bool ListEmptyP (ListP P);
bool ListEmptyB (ListB B);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
// untuk membentuk list statis bagi kasir, dengan sudah terbentuk arraynya
// untuk membentuk suatu list yang pointernya belum menunjuk kemana-mana bagi pelanggan dan barang
void CreateListK (ListK *K);
void CreateListP (ListP *P);
void CreateListB (ListB *B);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
// memori alokasi untuk pelanggan dan barang setiap ditambahkan
addressP AlokasiP (infotype plgn);
addressB AlokasiB (infotype brg, int qty);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

// dealokasi memori untuk pelanggan dan barang setiap dikurangi
void DeAlokasiP (addressP pel);
void DeAlokasiB (addressB bar);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

/**** Pencarian sebuah elemen List ****/
// bagi kasir, ketika mencari kasir untuk mendealokasi pelanggan paling depan, 
// untuk menghitung seberapa banyak antrian barang dan customer di kasir tersebut
// bagi pelanggan dan barang, jika ingin mencari node di tengah-tengah
int SearchK (ListK K, infotype ksr);
addressP SearchP (ListP P, infotype plgn);
addressB SearchB (ListB B, infotype brg);
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

bool FSearchK (ListK K, addressK kas);
bool FSearchP (ListP P, addressP pel);
bool FSearchB (ListB B, addressB bar);
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

addressK SearchPrecK (ListK K, infotype ksr);
addressP SearchPrecP (ListP P, infotype plgn);
addressB SearchPrecB (ListB B, infotype brg);
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
// untuk pelanggan dan barang, memasukkan node dari belakang
void InsVLastP (ListP *P, infotype plgn);
void InsVLastB (ListB *B, infotype brg, int qty);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
 
/**** Penghapusan Elemen ****/
// untuk pelanggan dan barang, mengeluarkan node dari depan
// delete awal untuk pelanggan, berarti sudah selesai transaksi di kassa
void DelVFirstP (ListP *P, infotype *plgn);
void DelVFirstB (ListB *B, infotype *brg);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

// untuk pelanggan dan barang
// delete akhir untuk pelanggan, bisa jadi ingin mengubah belanjaan atau tidak jadi belanja
void DelVLastP (ListP *P, infotype *plgn);
void DelVLastB (ListB *B, infotype *brg);
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
// untuk pelanggan dan barang antri dari belakang
void InsertLastP (ListP *P, addressP pel);
void InsertLastB (ListB *B, addressB bar);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

/**** Penghapusan sebuah elemen ****/
// untuk pelanggan paling depan dan barang pertama dalam keranjang
// bagi pelanggan ketika transaksi dengan kassa sudah selesai
void DelFirstP (ListP *P, addressP *pel);
void DelFirstB (ListB *B, addressB *bar);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

// barang ditengah node tidak jadi dibeli
// customer di tengah antrian tidak jadi belanja atau ingin mengubah barang belanjaan
void DelAnyP (ListP *P, infotype plgn);
void DelAnyB (ListB *B, infotype brg);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

//  berkaitan dengan DelVLast
// bagi pelanggan jika ingin mengubah barang belanja atau tidak jadi belanja
void DelLastP (ListP *P, addressP *pel);
void DelLastB (ListB *B, addressB *bar);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */


/**** PROSES SEMUA ELEMEN LIST  ****/
// hanya menampilkan list kasir
void PrintInfoK (ListK K);  
// hanya menampilkan list pelanggan yang terdapat di minimarket dari kassa tertentu
void PrintInfoP (ListP P);
// hanya menampilkan list barang yang sudah dipilih oleh pelanggan tertentu
void PrintInfoB (ListB B);
// menampilkan seluruh kasir serta seluruh pelanggan pada setiap kasir
void PrintInfoKP (ListK K, ListP P);
// menampilkan seluruh pelanggan serta seluruh barang belanja
void PrintInfoPB (ListP P, ListB B);
// menampilkan seluruh kasir, seluruh pelanggan yang antri beserta barang belanja yang sudah dipilih
void PrintAll (ListK K, ListP P, ListB B);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

// update jumlah barang dari node barang yang sudah ada pada suatu pelanggan
void UpdateQtyB(ListB B, addressB bar, int qty);
// menghitung jumlah atau kuantitas dari barang
int CountQtyB(ListB B, addressB bar);
// menghitung jumlah pelanggan dari kassa
int CountP(ListP P, int indexK);
// jangan lupa untuk menyimpan data barang di minimarket ke dalam file. dapat dibaca, ditambah, dihapus, diubah

/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/

#endif
