/*  File        : display.c 
    Deskripsi   : Display untuk program antrian pelanggan di kassa
    Identitas   : Alisha Nara Chandrakirana     (221524033)
                  Keanu Rayhan Harits           (221524043)
                  Niqa Nabila Nur Ihsani        (221524054)
    Kelompok    : 2C
    Kelas       : 1B-D4IT
    Mata Kuliah : Struktur Data dan Algoritma
    Tugas       : Tugas Besar membuat program antrian pelanggan pada kassa di minimarket
    Tanggal     : 27 Maret 2023 s.d. 7 Mei 2023
                  Update 9 Mei 2023 s.d.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "spkasir.h"

#define LIGHT_BLUE 11
#define WHITE 15
#define	RED 12
#define DARK_GREEN 3
#define	YELLOW 14

void warnateks(int warna) //modul yang berfungsi untuk memberi warna ke karakter
{ 
	HANDLE hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

// void gotoxy(int x, int y) {
//     COORD coord;
     
//     coord.X = x;
//     coord.Y = y;
     
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
// }

// void DisplayLoading(){
// 	int bg, fg, delay, panjang;
// 	int simbol[20] = {2,3,4,5,6,14,16,22,35,36,62,64,158,174,175,176,177,178,219};
// 	warnateks(LIGHT_BLUE);
//    	loading(20 - 1, 19 - 1, 30 , 1, simbol);
//    	gotoxy(48,10);
// }

// void loading(int bg, int fg, int panjang, int delay, int simbol[20]){
//  int k, l;
//    for (k=0; k<=panjang; k+=2)
//    {
//       gotoxy(48,10);
//       printf("\n\n\n\n\t\t\t\t\t\tPlease Wait \n\t");
//       printf("\n\t\t\t\t\t");
//       for (l=0; l<k; l++){
//          printf("%c", simbol[fg]);
//       }
//       printf("\t\t\t\t\t\t");
//       for (l=0; l<panjang-1; l++){
//          printf("%c", simbol[bg]);
//       Sleep(delay);
//       }
//    }
// }

void DisplayMenuAwal(){
    printf("\n\n\n"); 
    printf("   =====================================================================================\n");
    printf("  |                                                                                     |\n");
    printf("  |      CCCCCCC   CCCCCC   CCCCCC         CCCCC CCCCC   CCCCCC   CCCCC    CCCCCCC      |\n");
    printf("  |            C  C     C  C     C         C   CCC   C  C      C  C    C      C         |\n");
    printf("  |      CCCCCCC  C        C        CCCCC  C         C  C      C  C     C     C         |\n");
    printf("  |      C        C     C  C     C         C CCC CCC C  C CCCC C  CCCCCCC     C         |\n");
    printf("  |      CCCCCCC   CCCCCC   CCCCCC         CCC CCC CCC  CCC  CCC  C     C     C         |\n");
    printf("  |                                                                                     |\n");
    printf("   =====================================================================================\n");
    printf("  /     /     /     /     /     /     /     2CC     \\     \\     \\     \\     \\     \\     \\\n");
    printf(" /____ /____ /____ /____ /____ /____ /____ -MART ____\\ ____\\ ____\\ ____\\ ____\\ ____\\ ____\\\n");
    printf("[_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____]\n");
    printf("     |                                                                               |\n");
    printf("     |                         ============================                          |\n");
    printf("     |                        |   !!  SELAMAT DATANG  !!   |                         |\n");
    printf("     |                        |                            |                         |\n");
    printf("     |                        |         1. MASUK           |                         |\n");
    printf("     |                        |         2. ATURAN          |                         |\n");
    printf("     |                        |         0. KELUAR          |                         |\n");
    printf("     |                        |                            |                         |\n");
    printf("     |________________________|____________________________|_________________________|\n");
    printf("                                                                By: Alisha-Keanu-Niqa \n");
    printf("     PILIH OPSI: ");
}

void DisplayMenuMasuk(){
    // system("cls");
   printf("\n\n\n"); 
    printf(" --------------------------------\n");
    printf("|           2CC - MART           |\n");
    printf("|       - SELAMAT DATANG -       |\n");
    printf("|                                |\n");
    printf("|  1. Tambah pelanggan           |\n");
    printf("|  2. Tampilkan daftar pelanggan |\n");
    printf("|  3. Aktivitas antrian          |\n");
    printf("|  0. Kembali                    |\n");
    printf(" --------------------------------\n");
    printf("Pilih opsi: ");
}

void DisplayMenuLanjutan(){     // belum dibuat alurnya
    // system("cls");
    printf("\n"); 
    printf("[digunakan ketika pelanggan ingin melakukan\n   suatu perilaku saat sedang mengantri]\n\n");
    printf("        --------------------------\n");
    printf("       |  1. Selesai transaksi    |\n");
    printf("       |  2. Keluar dari antrian  |\n");
    printf("       |  0. Kembali              |\n");
    printf("        --------------------------\n");
    printf("       Pilih opsi: ");
    getch();
}

void DisplayPelangganKeluar(){     // belum dibuat alurnya
    // system("cls");
    printf("\n\n\n"); 
    printf(" ------------------------------\n");
    printf("|    1. Batal Belanja          |\n");
    printf("|    2. Kembali Berbelanja     |\n");
    printf("|    0. Kembali                |\n");
    printf(" ------------------------------\n");
    printf("Pilih opsi: ");
}

void DisplayBelanja(){
    printf("\n\n\n"); 
    printf("CCC\n");
	printf("  CC   CCCCCCCCCCCCCCC\n");
	printf("   CC              CC\n");
	printf("    CC            CC\n");
	printf("     CC          CC\n");
	printf("      CCCCCCCCCCCC\n");
	printf("      CC       CC\n");
	printf("     C  C     C  C\n");
	printf("      CC       CC\n\n");
	printf("------------------------\n");	
    printf(" ! SELAMAT BERBELANJA ! \n");
	printf("------------------------\n");
    printf("Tekan apapun untuk melanjutkan...");
    getch();
}

void DisplayMenuBelanja(){
    // ambil kode customer
    // system("cls");
    printf("\n\n\n"); 
    printf("MENU BELANJA\n");
	printf(" -------------------------------------\n");
    printf("|   1. Tambah barang belanja          |\n");
    printf("|   2. Ubah jumlah barang belanja     |\n");
    printf("|   3. Mengembalikan barang belanja   |\n");
    printf("|   4. Tampilkan keranjang belanja    |\n");
    printf("|   5. Selesai belanja                |\n");
	printf(" -------------------------------------\n");
    printf("Pilih opsi: ");
}

void DisplayAturan(){
    // system("cls");
    printf("\n\n\n"); 
    printf("    ! ! ! ! !  Aturan Berbelanja di 2CC-Mart  ! ! ! ! !\n");
    printf(" ---------------------------------------------------------\n");
    printf("|    1. Pelanggan tidak boleh menyela antrian pelanggan   |\n");
    printf("|       lain di kassa                                     |\n");
    printf("|    2. Pelanggan yang sudah antri dan belum didepan      |\n");
    printf("|       kasir, boleh mengubah barang belanja dengan       |\n");
    printf("|       konsekuensi akan kembali antri dari belakang      |\n");
    printf(" ---------------------------------------------------------\n\n");
    printf("Tekan apapun untuk melanjutkan...");
}

void DisplayAntri(){
    // system("cls");
    printf("\n\n\n"); 
    printf("     CCCC\t     CCCC\t     CCCC\n");
    printf("   CCCCCCCC\t   CCCCCCCC\t   CCCCCCCC\n");
    printf("   CCCCCCCC\t   CCCCCCCC\t   CCCCCCCC\n");
    printf("    CCCCCC\t    CCCCCC\t    CCCCCC\n");
    printf("  CCCCCCCCCC\t  CCCCCCCCCC\t  CCCCCCCCCC\n");
    printf(" CCCCCCCCCCCC\t CCCCCCCCCCCC\t CCCCCCCCCCCC\n");
    printf("CCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\n");
    printf("CCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\n\n");
    printf("       -------------------------------\n");
    printf("           SILAKAN ANTRI DI KASSA\n");
    printf("       -------------------------------\n");
    printf("Tekan apapun untuk melanjutkan...");
    getch();
}

void DisplayThank(){
    // system("cls");
    printf("\n\n\n"); 
    printf(" 	             CCC\n");
	printf(" 	            C  C\n");
	printf("          CCCC  C  CCCCCC\n");
	printf("          C  C  C        C\n");
	printf("          C  C  C        C\n");
	printf("          C  C  C        C\n");
	printf("          CCCC   CCCCCCCC\n\n");
	printf(" ---------------------------------\n");
	printf("   TERIMA KASIH SUDAH BERBELANJA\n");
	printf("    	    DI 2CC-MART\n");
	printf(" ---------------------------------\n");
    printf("Tekan apapun untuk melanjutkan...");
    getch();
}