/*  File        : Mainkasir.c
    Deskripsi   : Main program untuk program antrian pelanggan di kassa
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

#include "spkasir.h"
#include "Bodykasir.c"
#include "display.c"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

int main(){
    /* Kamus Lokal*/
    ListP daftartemp, daftarP1, daftarP2, daftarP3;
    ListB daftarB;
    infotype kodeP, brg;
    addressP cariP;
    addressB cariB;
    int opsiawal, opsimasuk, opsibelanja, opsisdhantri, opsikassa, qty, opsilainnya;
    bool done=false, adabrg=false;
    char opsitambah, opsiantri, opsi;
    // addressP cariP;

    /* Algoritma */
    // system("cls");
    CreateListK();
    CreateListP(&daftartemp);
    CreateListP(&daftarP1);
    CreateListP(&daftarP2);
    CreateListP(&daftarP3);
    CreateListB(&daftarB);
    LoadBFromFile();

    do{
    awal:
    system("cls");
    DisplayMenuAwal();
    scanf("%d",&opsiawal);
    system("cls");
    switch (opsiawal){
        case 1:{
            masuk: 
            system("cls");
            DisplayMenuMasuk();
            scanf("%d",&opsimasuk);
            system("cls");
            switch (opsimasuk){
                case 1:{
                    while(!done){
                        kodeP = AlokasiInfo();
                        printf("-~-~- TAMBAH PELANGGAN -~-~-\n\n");
                        printf("Masukkan kode pelanggan tanpa spasi (contoh: P1): ");
                        scanf("%s", kodeP);
                            if(SearchP(daftartemp, kodeP) != NULL){
                                printf("Kode pelanggan sudah ada\n");
                                printf("Tekan apapun untuk melanjutkan...");
                                getch();
                                goto masuk;
                            } else {
                                InsVLastP(&daftartemp, kodeP);
                                printf("Pelanggan berhasil ditambahkan\n");
                                printf("Tekan apapun untuk melanjutkan...");
                                getch();

                            }
                            break;
                        InsVLastP(&daftartemp, kodeP);
                        printf("Pelanggan berhasil ditambahkan\n");
                        printf("Tekan apapun untuk melanjutkan...");
                        getch();
                        done = true;
                    }
                    system("cls");
                    DisplayBelanja();
                    belanjalagi:
                    system("cls");
                    DisplayMenuBelanja();
                    scanf("%d",&opsibelanja);
                    system("cls");
                    switch (opsibelanja){
                        case 1:                            
                            kodeP = AlokasiInfo();
                            ulangkode:
                            printf("\n---- TAMBAH BARANG ----\n\n");
                            printf("Apakah anda sudah antri di kassa?\n");
                            printf("1. Ya, sudah\n");
                            printf("0. Belum\n");
                            printf("Pilih opsi: ");
                            scanf("%d",&opsisdhantri);
                            system("cls");
                            if (opsisdhantri == 1){
                                printf("Anda antri di kassa berapa (1/2/3)? ");
                                scanf("%d",&opsikassa);
                                printf("Masukkan kode pelangganmu: ");
                                scanf("%s", kodeP);
                                if (opsikassa == 1){
                                    cariP = SearchP(daftarP1, kodeP);
                                }else if(opsikassa == 2){
                                    cariP = SearchP(daftarP2, kodeP);
                                }else if(opsikassa == 3){
                                    cariP = SearchP(daftarP3, kodeP);
                                }
                            }else{
                                printf("Masukkan kode pelangganmu: ");
                                scanf("%s", kodeP);
                                cariP = SearchP(daftartemp, kodeP);
                            }
                            if(cariP == NULL){
                                printf("Kode pelanggan tidak ditemukan\n");
                                printf("Tekan apapun untuk melanjutkan...");
                                getch();
                                goto ulangkode;
                            }else{
                                ulangbrg:
                                system("cls");
                                brg = AlokasiInfo();
                                printf("\nDaftar Barang 2CC-MART\n");                                
                                PrintB();
                                printf("Silakan ketik nama barang: ");
                                scanf("%s",brg);
                                ulangqty:
                                printf("Silakan masukkan jumlah barang: ");
                                scanf("%d",&qty);
                                if(qty == 0){
                                    printf("! Jumlah barang tidak boleh 0 !\n");
                                    goto ulangqty;
                                }else{
                                    InsVLastB(cariP,brg,qty);
                                    adabrg = true;
                                    printf("Barang berhasil ditambahkan ke keranjang\n");
                                    printf("Apakah anda ingin menambah barang lagi (y/n)? ");
                                    opsitambah = getche();
                                    if((opsitambah == 'Y') || (opsitambah == 'y')){
                                        goto ulangbrg;
                                    }else{
                                        goto belanjalagi;
                                    }
                                    printf("Tekan apapun untuk melanjutkan...");
                                    getch();                                    
                                }
                            }
                            break;
                        case 2:
                            if(((cariP)->cart == NULL) && (!adabrg)){
                                printf("! Keranjangmu kosong !\n");
                                printf("Tekan apapun untuk melanjutkan...");
                                getch();
                                goto belanjalagi;
                            }else if(((cariP)->cart != NULL) && (adabrg)){
                                ulangkode2:
                                system("cls");
                                kodeP = AlokasiInfo();                                
                                printf("---- UBAH JUMLAH BARANG ----\n\n");
                                printf("Apakah anda sudah antri di kassa?\n");
                                printf("1. Ya, sudah\n");
                                printf("0. Belum\n");
                                printf("Pilih opsi: ");
                                scanf("%d",&opsisdhantri);
                                system("cls");
                                if (opsisdhantri == 1){
                                    printf("Anda antri di kassa berapa (1/2/3)? ");
                                    scanf("%d",&opsikassa);
                                    printf("Masukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    if (opsikassa == 1){
                                        cariP = SearchP(daftarP1, kodeP);
                                    }else if(opsikassa == 2){
                                        cariP = SearchP(daftarP2, kodeP);
                                    }else if(opsikassa == 3){
                                        cariP = SearchP(daftarP3, kodeP);
                                    }
                                }else{
                                    printf("Masukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    cariP = SearchP(daftartemp, kodeP);
                                }                                
                                if(cariP == NULL){
                                    printf("Kode pelanggan tidak ditemukan\n");
                                    goto ulangkode2;
                                }else{
                                    system("cls");
                                    brg = AlokasiInfo();
                                    PrintInfoPB(daftartemp, -1);
                                    printf("\nSilakan ketik nama barang yang ingin diubah: ");
                                    scanf("%s",brg);
                                    
                                    cariB = SearchB(cariP, brg);
                                    if(cariB == NULL){
                                        printf("Barang tidak ditemukan\n");
                                        goto belanjalagi;
                                    } else {
                                        updateqty:
                                            printf("\nSilakan masukkan perubahan jumlah barang: ");
                                            scanf("%d", &qty);
                                            if(qty == 0){
                                                printf("Apakah anda ingin menyimpan kembali seluruh barang ke etalase (y/n)? ");
                                                opsitambah = getche();
                                                if((opsitambah == 'Y') || (opsitambah == 'y')){
                                                    DelAnyB(cariP, brg);
                                                    goto belanjalagi;
                                                }else{
                                                    goto updateqty;
                                                }
                                            } else {
                                                updateQty(cariP, brg, qty);
                                                printf("Tekan apapun untuk melanjutkan...");
                                                getch();
                                                goto belanjalagi;
                                            }
                                    }
                                }
                            }
                            break;
                        case 3:
                            if(((cariP)->cart == NULL) && (!adabrg)){
                                adabrg = false;
                                printf("! Keranjangmu kosong !\n");
                                printf("Tekan apapun untuk melanjutkan...");
                                getch();
                                goto belanjalagi;
                            }else if(((cariP)->cart != NULL) && (adabrg)){
                                ulangkode3:
                                system("cls");
                                printf("---- PENGEMBALIAN BARANG ----\n\n");
                                printf("Masukkan kode pelangganmu: ");
                                kodeP = AlokasiInfo();      //ini baru ditambah
                                scanf("%s", kodeP);

                                cariP = SearchP(daftartemp, kodeP);
                                if(cariP == NULL){
                                    printf("Kode pelanggan tidak ditemukan\n");
                                    goto ulangkode3;
                                } else{
                                    mengembalikanbarang:
                                    system("cls");
                                    PrintInfoPB(daftartemp, -1);
                                    printf("Masukkan barang yang ingin dikembalikan: ");
                                    scanf("%s", brg);
                                    cariB = SearchB (cariP, brg);
                                    if(cariB == NULL){
                                        printf("Barang tidak ditemukan\n");
                                        goto mengembalikanbarang;
                                    } else {
                                        DelAnyB(cariP, brg);
                                        
                                        printf("Apakah anda ingin mengembalikan barang lagi (y/n)? ");
                                        opsitambah = getche();
                                        if((opsitambah == 'Y') || (opsitambah == 'y')){
                                            if((cariP)->cart == NULL){
                                                adabrg = false;
                                                printf("\nKeranjang sudah kosong...\n");
                                                printf("Tekan apapun untuk melanjutkan...");
                                                getch();
                                                goto belanjalagi;
                                            }else{
                                                goto mengembalikanbarang;
                                            }
                                        }else{
                                            goto belanjalagi;
                                        }
                                        printf("Tekan apapun untuk melanjutkan...");
                                        getch();
                                    }
                                }
                            }
                            break;
                        case 4:
                            system("cls");
                            printf("---- DAFTAR BARANG DI KERANJANG ----\n\n");
                            PrintInfoPB(daftartemp, -1);
                            printf("Tekan apapun untuk melanjutkan...");
                            getch();
                            goto belanjalagi;
                        case 5:
                            if(adabrg){
                                // printinfo yg ada total jumlah barang 
                                DisplayAntri();
                                antri:
                                system("cls");
                                printf("---- DAFTAR KASSA ----\n");
                                PrintInfoK();
                                printf("Pilih opsi kassa: ");
                                scanf("%d",&opsikassa);
                                if(opsikassa==1){
                                    printf("Masukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    cariP = SearchP(daftartemp, kodeP);
                                    if(cariP == NULL){
                                        printf("Kode pelanggan tidak ditemukan\n");
                                        goto antri;
                                    }else{
                                        InsertToK(&daftarP1, cariP, opsikassa-1);
                                        printf("Anda masuk antrian kassa 1\n");
                                    }
                                }else if(opsikassa==2){
                                    printf("Masukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    cariP = SearchP(daftartemp, kodeP);
                                    if(cariP == NULL){
                                        printf("Kode pelanggan tidak ditemukan\n");
                                        goto antri;
                                    }else{
                                        InsertToK(&daftarP2, cariP, opsikassa-1);                                       
                                        printf("Anda masuk antrian kassa 2\n");
                                    }
                                }else if(opsikassa==3){
                                    printf("Masukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    cariP = SearchP(daftartemp, kodeP);
                                    if(cariP == NULL){
                                        printf("Kode pelanggan tidak ditemukan\n");
                                        goto antri;
                                    }else{
                                        InsertToK(&daftarP3, cariP, opsikassa-1);                                        
                                        printf("Anda masuk antrian kassa 3\n");                                        
                                    }
                                }else{
                                    printf("! OPSI SALAH !\n");
                                    printf("Tekan apapun untuk melanjutkan...");
                                    getch();
                                    goto antri;
                                }
                                // DelVFirstP(&daftartemp,&kodeP);
                                printf("Tekan apapun untuk melanjutkan...");
                                getch();
                                goto masuk;
                            }else{
                                printf("Anda belum memilih barang\n");
                                printf("Apakah anda ingin keluar dari 2CC-Mart (y/n)? ");
                                opsiantri = getche();
                                if((opsiantri == 'Y') || (opsiantri == 'y')){
                                    // system("cls");
                                    exit(99);
                                }else{
                                    goto belanjalagi;
                                }
                            }
                            break;
                        default:
                            printf("! OPSI SALAH !\n");
                            printf("Tekan apapun untuk melanjutkan...");
                            getch();
                            goto belanjalagi;
                            break;
                    }        
                    break;
                }
                case 2:
                    system("cls");
                    printf("-~-~- DAFTAR PELANGGAN -~-~-\n\n");
                    PrintInfoKP(daftarP1, daftarP2, daftarP3, daftartemp);
                    printf("Tekan apapun untuk melanjutkan...");
                    getch();
                    goto masuk;
                    break;
                case 3:
                    lainnya:
                    system("cls");
                    printf("-~-~- AKTIVITAS PELANGGAN -~-~-\n\n");
                    DisplayMenuLanjutan();
                    scanf("%d", &opsilainnya);
                    
                    switch(opsilainnya){
                    	case 1:
                            system("cls");
                            printf("---- SELESAI TRANSAKSI ----\n\n");
                    		PrintInfoKP(daftarP1, daftarP2, daftarP3, daftartemp);
                    		printf("Pilih Kassa Untuk Melakukan Proses Transaksi: ");
                    		scanf("%d", &opsikassa);
	                    	if(opsikassa == 1){
//	                    			printf("Apakah anda ingin melanjutkan proses transaksi (y/n)? ");
//	                    			opsitambah = getche();
//	                    			if((opsitambah == 'y') || (opsitambah == 'Y')){
	                   				DelVFirstP (&daftarP1, opsikassa-1);
	                   				printf("\nTekan apapun untuk melanjutkan...");
	                           		getch();
//								}
							} else if(opsikassa == 2){
								DelVFirstP (&daftarP2, opsikassa-1);
	                   			printf("\nTekan apapun untuk melanjutkan...");
	                           	getch();
							} else if(opsikassa == 3){
								DelVFirstP (&daftarP3, opsikassa-1);
	                   			printf("\nTekan apapun untuk melanjutkan...");
	                           	getch();									
							} else {
								printf("\nMasukkan Kassa yang valid !\n");
								goto lainnya;
							}
							break;
							
						case 2:
                            system("cls");
							printf("---- OPSI PELANGGAN ----\n");
							DisplayPelangganKeluar();
							scanf("%d", &opsilainnya);
							
							switch(opsilainnya){
								case 1:
                                    system("cls");
									printf("Apakah yakin anda akan membatalkan belanja (y/n)? ");
									opsi = getche();
									if((opsi == 'Y') || (opsi == 'y')){
										PrintInfoKP(daftarP1, daftarP2, daftarP3, daftartemp);
										printf("Pilih antrian kassa : ");
										scanf("%d", &opsikassa);
										if(opsikassa == 1){
											PrintCustK (daftarP1, opsikassa - 1);
											printf("Pilih pelanggan yang ingin dibatalkan: ");
											kodeP = AlokasiInfo();
											scanf("%s", kodeP);
											
											if(daftarP1.head != NULL){
												DelAnyP (&daftarP1, kodeP);
											} else {
												printf("Pelanggan tidak ditemukan\n");
											}
											printf("\nTekan apapun untuk melanjutkan...");
	                          				getch();
										} else if(opsikassa == 2){
											PrintCustK (daftarP2, opsikassa - 1);
										} else if(opsikassa == 3){
											PrintCustK (daftarP3, opsikassa - 1);						
										} else {
											
										}
									}
									break;
									
								case 2:
									system("cls");
									break;
									
								case 0:
									goto lainnya;
									break;
							}							
							break;							
						}
                    break;
                case 0:
                    goto awal;
                    break;
                default:
                    printf("! OPSI SALAH !\n");
                    printf("Tekan apapun untuk melanjutkan...");
                    getch();
                    goto masuk;
                    break;
            }
            break;
        }
        case 2:
            DisplayAturan();
            getch();
            break;
        case 0:
            printf("\n\n\n"); 
            printf("---------------------------------------------------\n"\
                   "Apakah anda ingin keluar dari 2CC-Mart (y/n)? ");
            opsi = getche();
            system("cls");
            printf("\n");
            if((opsi == 'Y') || (opsi == 'y')){
                // system("cls");
                exit(1);
            }else{
                main();
            }
            break;
        default:
            printf("! OPSI SALAH !\n");
            printf("Tekan apapun untuk melanjutkan...");
            getch();
            goto awal;
            break;
    }
    }while(opsiawal != 99);
    return 0;
}
