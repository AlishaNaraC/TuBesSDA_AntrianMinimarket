/*  File        : Mainkasir.c
    Deskripsi   : Header untuk program antrian pelanggan di kassa
    Identitas   : Alisha Nara Chandrakirana     (221524033)
                  Keanu Rayhan Harits           (221524043)
                  Niqa Nabila Nur Ihsani        (221524054)
    Kelompok    : 2C
    Kelas       : 1B-D4IT
    Mata Kuliah : Struktur Data dan Algoritma
    Tugas       : Tugas Besar membuat program antrian pelanggan pada kassa di minimarket
    Tanggal     : 27 Maret 2023 s.d. 7 Mei 2023
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
    int opsiawal, opsimasuk, opsibelanja, opsisdhantri, opsikassa, qty;
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
    do{
    awal:
    DisplayMenuAwal();
    scanf("%d",&opsiawal);
    switch (opsiawal){
        case 1:{
            masuk:            
            DisplayMenuMasuk();
            scanf("%d",&opsimasuk);
            switch (opsimasuk){
                case 1:{
                    while(!done){
                        kodeP = AlokasiInfo();
                        printf("\t\t\t\t-~-~- TAMBAH PELANGGAN -~-~-\n\n");
                        printf("\t\t\t\tMasukkan kode pelanggan tanpa spasi (contoh: P1): ");
                        scanf("%s", kodeP);
                            if(SearchP(daftartemp, kodeP) != NULL){
                                printf("\t\t\t\tKode pelanggan sudah ada\n");
                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                getch();
                                goto masuk;
                            } else {
                                InsVLastP(&daftartemp, kodeP);
                                printf("\t\t\t\tPelanggan berhasil ditambahkan\n");
                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                getch();

                            }
                            break;
                        InsVLastP(&daftartemp, kodeP);
                        printf("\t\t\t\tPelanggan berhasil ditambahkan\n");
                        printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                        getch();
                        done = true;
                    }
                    DisplayBelanja();
                    belanjalagi:
                    DisplayMenuBelanja();
                    scanf("%d",&opsibelanja);
                    switch (opsibelanja){
                        case 1:
                            kodeP = AlokasiInfo();
                            ulangkode:
                            printf("\n\t\t\t\t---- TAMBAH BARANG ----\n\n");
                            printf("\t\t\t\tApakah anda sudah antri di kassa?\n");
                            printf("\t\t\t\t1. Ya, sudah\n");
                            printf("\t\t\t\t0. Belum\n");
                            printf("\t\t\t\tPilih opsi: ");
                            scanf("%d",&opsisdhantri);
                            // system("cls");
                            if (opsisdhantri == 1){
                                printf("\t\t\t\tAnda antri di kassa berapa (1/2/3)? ");
                                scanf("%d",&opsikassa);
                                printf("\t\t\t\tMasukkan kode pelangganmu: ");
                                scanf("%s", kodeP);
                                if (opsikassa == 1){
                                    cariP = SearchP(daftarP1, kodeP);
                                }else if(opsikassa == 2){
                                    cariP = SearchP(daftarP2, kodeP);
                                }else if(opsikassa == 3){
                                    cariP = SearchP(daftarP3, kodeP);
                                }
                            }else{
                                printf("\t\t\t\tMasukkan kode pelangganmu: ");
                                scanf("%s", kodeP);
                                cariP = SearchP(daftartemp, kodeP);
                            }
                            if(cariP == NULL){
                                printf("\t\t\t\tKode pelanggan tidak ditemukan\n");
                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                getch();
                                goto ulangkode;
                            }else{
                                ulangbrg:
                                brg = AlokasiInfo();
                                printf("\n\t\t\t\tDaftar Barang 2CC-MART\n");
                                LoadBFromFile();
                                PrintB();
                                printf("\t\t\t\tSilakan ketik nama barang: ");
                                scanf("%s",brg);
                                ulangqty:
                                printf("\t\t\t\tSilakan masukkan jumlah barang: ");
                                scanf("%d",&qty);
                                if(qty == 0){
                                    printf("\t\t\t\t! Jumlah barang tidak boleh 0 !\n");
                                    goto ulangqty;
                                }else{
                                    InsVLastB(cariP,brg,qty);
                                    adabrg = true;
                                    printf("\t\t\t\tBarang berhasil ditambahkan ke keranjang\n");
                                    printf("\t\t\t\tApakah anda ingin menambah barang lagi (y/n)? ");
                                    opsitambah = getche();
                                    if((opsitambah == 'Y') || (opsitambah == 'y')){
                                        goto ulangbrg;
                                    }else{
                                        goto belanjalagi;
                                    }
                                    printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                    getch();
                                    
                                }
                            }
                            break;
                        case 2:
                            if(((cariP)->cart == NULL) && (!adabrg)){
                                printf("\t\t\t\t! Keranjangmu kosong !\n");
                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                getch();
                                goto belanjalagi;
                            }else if(((cariP)->cart != NULL) && (adabrg)){
                                kodeP = AlokasiInfo();
                                printf("\t\t\t\t---- UBAH JUMLAH BARANG ----\n\n");
                                printf("\t\t\t\tApakah anda sudah antri di kassa?\n");
                                printf("\t\t\t\t1. Ya, sudah\n");
                                printf("\t\t\t\t0. Belum\n");
                                printf("\t\t\t\tPilih opsi: ");
                                scanf("%d",&opsisdhantri);
                                // system("cls");
                                if (opsisdhantri == 1){
                                    // printf("\t\t\t\tAnda antri di kassa berapa (1/2/3)? ");
                                    // scanf("%d",&opsikassa);
                                    // searchP in kassa, searchP_K maybe
                                }
                                ulangkode2:
                                printf("\t\t\t\tMasukkan kode pelangganmu: ");
                                scanf("%s", kodeP);
                                cariP = SearchP(daftartemp, kodeP);
                                if(cariP == NULL){
                                    printf("\t\t\t\tKode pelanggan tidak ditemukan\n");
                                    goto ulangkode2;
                                }else{
                                    brg = AlokasiInfo();
                                    PrintInfoPB(daftartemp, -1);
                                    printf("\n\t\t\t\tSilakan ketik nama barang yang ingin diubah: ");
                                    scanf("%s",brg);
                                    
                                    cariB = SearchB(cariP, brg);
                                    if(cariB == NULL){
                                        printf("\t\t\t\tBarang tidak ditemukan\n");
                                        goto belanjalagi;
                                    } else {
                                        updateqty:
                                            printf("\n\t\t\t\tSilakan masukkan perubahan jumlah barang: ");
                                            scanf("%d", &qty);
                                            if(qty == 0){
                                                printf("\t\t\t\tApakah anda ingin menyimpan kembali seluruh barang ke etalase (y/n)? ");
                                                opsitambah = getche();
                                                if((opsitambah == 'Y') || (opsitambah == 'y')){
                                                    DelAnyB(cariP, brg);
                                                    goto belanjalagi;
                                                }else{
                                                    goto updateqty;
                                                }
                                            } else {
                                                updateQty(cariP, brg, qty);
                                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                                getch();
                                                goto belanjalagi;
                                            }
                                    }
                                }
                            }
                            break;
                        case 3:
                            if(((cariP)->cart != NULL) && (!adabrg)){
                                adabrg = false;
                                printf("\t\t\t\t! Keranjangmu kosong !\n");
                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                getch();
                                goto belanjalagi;
                            }else if(((cariP)->cart != NULL) && (adabrg)){
                                printf("\t\t\t\t---- PENGEMBALIAN BARANG ----\n\n");
                                ulangkode3:
                                printf("\t\t\t\tMasukkan kode pelangganmu: ");
                                scanf("%s", kodeP);

                                cariP = SearchP(daftartemp, kodeP);
                                if(cariP == NULL){
                                    printf("\t\t\t\tKode pelanggan tidak ditemukan\n");
                                    goto ulangkode3;
                                } else{
                                    mengembalikanbarang:
                                    PrintInfoPB(daftartemp, -1);
                                    printf("\t\t\t\tMasukkan barang yang ingin dikembalikan: ");
                                    scanf("%s", brg);
                                    cariB = SearchB (cariP, brg);
                                    if(cariB == NULL){
                                        printf("\t\t\t\tBarang tidak ditemukan\n");
                                    } else {
                                        DelAnyB(cariP, brg);
                                        
                                        printf("\t\t\t\tApakah anda ingin mengembalikan barang lagi (y/n)? ");
                                        opsitambah = getche();
                                        if((opsitambah == 'Y') || (opsitambah == 'y')){
                                            if((cariP)->cart == NULL){
                                                adabrg = false;
                                                printf("\n\t\t\t\tKeranjang sudah kosong...\n");
                                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                                getch();
                                                goto belanjalagi;
                                            }else{
                                                goto mengembalikanbarang;
                                            }
                                        }else{
                                            goto belanjalagi;
                                        }
                                        printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                        getch();
                                    }
                                }
                            }
                            break;
                        case 4:
                            printf("\t\t\t\t---- DAFTAR BARANG DI KERANJANG ----\n\n");
                            PrintInfoPB(daftartemp, -1);
                            printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                            getch();
                            goto belanjalagi;
                        case 5:
                            if(adabrg){
                                // printinfo yg ada rincian harga
                                DisplayAntri();
                                printf("\n");
                                antri:
                                printf("\t\t\t\t---- DAFTAR KASSA ----\n");
                                PrintInfoK();
                                printf("\t\t\t\tPilih opsi kassa: ");
                                scanf("%d",&opsikassa);
                                if(opsikassa==1){
                                    printf("\t\t\t\tMasukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    cariP = SearchP(daftartemp, kodeP);
                                    if(cariP == NULL){
                                        printf("\t\t\t\tKode pelanggan tidak ditemukan\n");
                                        goto antri;
                                    }else{
                                        InsertToK(&daftarP1, cariP, opsikassa-1);
                                        printf("\t\t\t\tAnda masuk antrian kassa 1\n");
                                    }
                                }else if(opsikassa==2){
                                    printf("\t\t\t\tMasukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    cariP = SearchP(daftartemp, kodeP);
                                    if(cariP == NULL){
                                        printf("\t\t\t\tKode pelanggan tidak ditemukan\n");
                                        goto antri;
                                    }else{
                                        InsertToK(&daftarP2, cariP, opsikassa-1);                                       
                                        printf("\t\t\t\tAnda masuk antrian kassa 2\n");
                                    }
                                }else if(opsikassa==3){
                                    printf("\t\t\t\tMasukkan kode pelangganmu: ");
                                    scanf("%s", kodeP);
                                    cariP = SearchP(daftartemp, kodeP);
                                    if(cariP == NULL){
                                        printf("\t\t\t\tKode pelanggan tidak ditemukan\n");
                                        goto antri;
                                    }else{
                                        InsertToK(&daftarP3, cariP, opsikassa-1);                                        
                                        printf("\t\t\t\tAnda masuk antrian kassa 3\n");                                        
                                    }
                                }else{
                                    printf("\t\t\t\t! OPSI SALAH !\n");
                                    printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                    getch();
                                    goto antri;
                                }
                                // DelVFirstP(&daftartemp,&kodeP);
                                printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                                getch();
                                goto masuk;
                            }else{
                                printf("\t\t\t\tAnda belum memilih barang\n");
                                printf("\t\t\t\tApakah anda ingin keluar dari 2CC-Mart (y/n)? ");
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
                            printf("\t\t\t\t! OPSI SALAH !\n");
                            printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                            getch();
                            goto belanjalagi;
                            break;
                    }        
                    break;
                }
                case 2:
                    printf("\t\t\t\t-~-~- DAFTAR PELANGGAN -~-~-\n\n");
                    // if(ListEmptyP){
                    //     printf("\t\t\t\tBelum ada pelanggan di 2CC-Mart\n");
                    // }else{
                    //     PrintInfoKP(daftarP1, daftarP2, daftarP3, daftartemp);
                    // }
                    PrintInfoKP(daftarP1, daftarP2, daftarP3, daftartemp);
                    printf("\t\t\t\tTekan apapun untuk melanjutkan...");
                    getch();
                    break;
                case 3:
                    printf("\t\t\t\t-~-~- OPSI LANJUTAN PELANGGAN -~-~-\n\n");
                    DisplayMenuLanjutan();
                    break;
                case 0:
                    goto awal;
                    break;
                default:
                    printf("\t\t\t\t! OPSI SALAH !\n");
                    printf("\t\t\t\tTekan apapun untuk melanjutkan...");
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
            printf("\t\t\t\t---------------------------------------------------\n"\
                "\t\t\t\tApakah anda ingin keluar dari 2CC-Mart (y/n)? ");
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
            printf("\t\t\t\t! OPSI SALAH !\n");
            printf("\t\t\t\tTekan apapun untuk melanjutkan...");
            getch();
            goto awal;
            break;
    }
    }while(opsiawal != 99);
    return 0;
}