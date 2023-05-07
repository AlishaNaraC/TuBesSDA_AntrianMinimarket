#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "spkasir.h"

#define LIGHT_BLUE 11
#define WHITE 15

void warnateks(int warna) //modul yang berfungsi untuk memberi warna ke karakter
{ 
	HANDLE hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
}

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DisplayLoading(){
	int bg, fg, delay, panjang;
	int simbol[20] = {2,3,4,5,6,14,16,22,35,36,62,64,158,174,175,176,177,178,219};
	warnateks(LIGHT_BLUE);
   	loading(20 - 1, 19 - 1, 30 , 1, simbol);
   	gotoxy(48,10);
}

void loading(int bg, int fg, int panjang, int delay, int simbol[20]){
 int k, l;
   for (k=0; k<=panjang; k+=2)
   {
      gotoxy(48,10);
      printf("\n\n\n\n\t\t\t\t\t\tPlease Wait \n\t");
      printf("\n\t\t\t\t\t");
      for (l=0; l<k; l++){
         printf("%c", simbol[fg]);
      }
      printf("\t\t\t\t\t\t");
      for (l=0; l<panjang-1; l++){
         printf("%c", simbol[bg]);
      Sleep(delay);
      }
   }
}

void DisplayMenuAwal(){
    // system("cls");
    warnateks(LIGHT_BLUE);
	 printf("\n\n\n\n\n\n\n"); 
     printf("\t\tCCCCCCC   CCCCCC   CCCCCC         CCCCC CCCCC   CCCCCC   CCCCC    CCCCCCC\n");
     printf("\t\t      C  C     C  C     C         C   CCC   C  C      C  C    C      C\n");
     printf("\t\tCCCCCCC  C        C        CCCCC  C         C  C      C  C     C     C\n");
     printf("\t\tC        C     C  C     C         C CCC CCC C  C CCCC C  CCCCCCC     C\n");
     printf("\t\tCCCCCCC   CCCCCC   CCCCCC         CCC CCC CCC  CCC  CCC  C     C     C\n\n");
     warnateks(WHITE);
     printf("\t\t\t\t   -----------------------------------\n");
     printf("\t\t\t\t\t   !! SELAMAT DATANG !!\n");
     printf("\t\t\t\t\t        1. MASUK\n");
     printf("\t\t\t\t\t        2. ATURAN\n");
     printf("\t\t\t\t\t        0. KELUAR\n");
     printf("\t\t\t\t   -----------------------------------\n");
     printf("\t\t\t\t   PILIH OPSI: ");
    //  DisplayLoading();
}

void DisplayMenuMasuk(){
    // system("cls");
    printf("\n\n\n"); 
    printf("\t\t\t\t --------------------------------\n");
    printf("\t\t\t\t|           2CC - MART           |\n");
    printf("\t\t\t\t|       - SELAMAT DATANG -       |\n");
    printf("\t\t\t\t|                                |\n");
    printf("\t\t\t\t|  1. Tambah pelanggan           |\n");
    printf("\t\t\t\t|  2. Tampilkan daftar pelanggan |\n");
    printf("\t\t\t\t|  3. Lainnya                    |\n");
    printf("\t\t\t\t|  0. Kembali                    |\n");
    printf("\t\t\t\t --------------------------------\n");
    printf("\t\t\t\tPilih opsi: ");
}

void DisplayMenuLanjutan(){     // belum dibuat alurnya
    // system("cls");
    printf("\n\n\n"); 
    printf("\t\t\t[digunakan ketika pelanggan ingin melakukan suatu perilaku saat sedang mengantri]\n\n");
    printf("\t\t\t\t\t -----------------------------------\n");
    printf("\t\t\t\t\t|  1. Selesai transaksi             |\n");
    printf("\t\t\t\t\t|  2. Keluar dari antrian tengah    |\n");
    printf("\t\t\t\t\t|  3. Keluar dari antrian belakang  |\n");
    printf("\t\t\t\t\t|  0. Kembali                       |\n");
    printf("\t\t\t\t\t -----------------------------------\n");
    printf("\t\t\t\t\tPilih opsi: ");
}

void DisplayBelanja(){
    printf("\n\n\n"); 
    printf("\t\t\t\tCCC\n");
	printf("\t\t\t\t  CC   CCCCCCCCCCCCCCC\n");
	printf("\t\t\t\t   CC              CC\n");
	printf("\t\t\t\t    CC            CC\n");
	printf("\t\t\t\t     CC          CC\n");
	printf("\t\t\t\t      CCCCCCCCCCCC\n");
	printf("\t\t\t\t      CC       CC\n");
	printf("\t\t\t\t     C  C     C  C\n");
	printf("\t\t\t\t      CC       CC\n\n");
	printf("\t\t\t\t------------------------\n");	
    printf("\t\t\t\t ! SELAMAT BERBELANJA ! \n");
	printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\tTekan apapun untuk melanjutkan...");
    getch();
}

void DisplayMenuBelanja(){
    // ambil kode customer
    // system("cls");
    printf("\n\n\n"); 
    printf("\t\t\t\t\t\tMENU BELANJA\n");
	printf("\t\t\t\t -------------------------------------\n");
    printf("\t\t\t\t|   1. Tambah barang belanja          |\n");
    printf("\t\t\t\t|   2. Ubah jumlah barang belanja     |\n");
    printf("\t\t\t\t|   3. Mengembalikan barang belanja   |\n");
    printf("\t\t\t\t|   4. Tampilkan keranjang belanja    |\n");
    printf("\t\t\t\t|   5. Selesai belanja                |\n");
	printf("\t\t\t\t -------------------------------------\n");
    printf("\t\t\t\tPilih opsi: ");
}

void DisplayAturan(){
    // system("cls");
    printf("\n\n\n"); 
    printf("\t\t\t\t    ! ! ! ! !  Aturan Berbelanja di 2CC-Mart  ! ! ! ! !\n");
    printf("\t\t\t\t ---------------------------------------------------------\n");
    printf("\t\t\t\t|    1. Pelanggan tidak boleh menyela antrian pelanggan   |\n");
    printf("\t\t\t\t|       lain di kassa                                     |\n");
    printf("\t\t\t\t|    2. Pelanggan yang sudah antri dan belum didepan      |\n");
    printf("\t\t\t\t|       kasir, boleh mengubah barang belanja dengan       |\n");
    printf("\t\t\t\t|       konsekuensi akan kembali antri dari belakang      |\n");
    printf("\t\t\t\t ---------------------------------------------------------\n\n");
    printf("\t\t\t\tTekan apapun untuk melanjutkan...");
}

void DisplayAntri(){
    // system("cls");
    printf("\t\t     CCCC\t     CCCC\t     CCCC\n");
    printf("\t\t   CCCCCCCC\t   CCCCCCCC\t   CCCCCCCC\n");
    printf("\t\t   CCCCCCCC\t   CCCCCCCC\t   CCCCCCCC\n");
    printf("\t\t    CCCCCC\t    CCCCCC\t    CCCCCC\n");
    printf("\t\t  CCCCCCCCCC\t  CCCCCCCCCC\t  CCCCCCCCCC\n");
    printf("\t\t CCCCCCCCCCCC\t CCCCCCCCCCCC\t CCCCCCCCCCCC\n");
    printf("\t\tCCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\n");
    printf("\t\tCCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\tCCCCCCCCCCCCCC\n\n");
    printf("\t\t\t-------------------------------\n");
    printf("\t\t\t    SILAKAN ANTRI DI KASSA\n");
    printf("\t\t\t-------------------------------\n");
    printf("\t\t\t\tTekan apapun untuk melanjutkan...");
    getch();
}

void DisplayThank(){
    // system("cls");
    printf("\t\t 	 CCC\n");
	printf("\t\t 	C  C\n");
	printf("\t\t CCCC  C  CCCCCC\n");
	printf("\t\t C  C  C        C\n");
	printf("\t\t C  C  C        C\n");
	printf("\t\t C  C  C        C\n");
	printf("\t\t CCCC   CCCCCCCC\n\n");
	printf("\t ---------------------------------\n");
	printf("\t   TERIMA KASIH SUDAH BERBELANJA\n");
	printf("\t    	    DI 2CC-MART\n");
	printf("\t ---------------------------------\n");

}