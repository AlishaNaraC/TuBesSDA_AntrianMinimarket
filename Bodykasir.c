/*  File        : Bodykasir.c 
    Deskripsi   : Body modul untuk program antrian pelanggan di kassa
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

#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include <string.h>
#include "spkasir.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmptyP (ListP P){
    return((P).head == NULL);
}

bool ListEmptyB (ListB B){
    return((B).first == NULL);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateListK (){
	char nilaiInfoK[8];
	for(int i=0; i<jmlK; i++){
		sprintf(nilaiInfoK, "Kassa-%d",i+1);
		strcpy(ListK[i].infoK, nilaiInfoK);
		ListK[i].cust = NULL;
	}
}

void CreateListP (ListP *P){
	(*P).head = NULL;
	(*P).tail = NULL;
}

void CreateListB (ListB *B){
	(*B).first = NULL;
	(*B).last = NULL;
}

/**** Manajemen Memory ****/
infotype AlokasiInfo(){
    infotype nama = (infotype) malloc (sizeof(infotype)*NAMA);
    if(nama == NULL){
        printf("! MEMORI PENUH !\n");
    }
    return(nama);
}

addressP AlokasiP (infotype plgn){
	// Kamus Lokal
    addressP pel;
    // Algoritma
    pel = (addressP) malloc (sizeof (ElmtListP));
    if (pel != NULL){
        (pel)->infoP = plgn;
        (pel)->after = NULL;
        (pel)->before = NULL;
        (pel)->cart = NULL;
        return(pel);
    }else{
        return NULL;
    }
}

/* Fungsi alokasi untuk membuat sebuah elemen baru pada list */
addressB AlokasiB(infotype brg, int qty) {
	// Kamus Lokal
	addressB bar;

	// Algoritma
	bar = (addressB) malloc(sizeof(ElmtListB)); // alokasi memori untuk elemen b)aru
	if (bar == NULL){
        return NULL;   
    }else{
		(bar)->infoB = brg;
        (bar)->next = NULL; 
        (bar)->prev = NULL;
        (bar)->qtyB = qty;
        return(bar); 
    }
}

/**** Pencarian sebuah elemen List ****/
// mencari alamat dari node pelanggan
addressP SearchP (ListP P, infotype plgn){
	// Kamus Lokal
    addressP pel;
	bool ketemu = false;

	// Algoritma
	pel = (P).head;
	while((pel != NULL) && (!ketemu)){
		if(strcmpi((pel)->infoP,plgn)==0){
			ketemu = true;
		}else{
			pel = (pel)->after;
		}
	}
	return (pel);
}

// mencari alamat dari node barang
addressB SearchB (addressP pel, infotype brg){
	// Kamus Lokal
	addressB bar;
	bool ketemu = false;

	// Algoritma
	//bar = (B).first;
	if((*pel).cart != NULL){
		bar = (*pel).cart;
		while((bar != NULL) && (!ketemu)){
			if(strcmp((bar)->infoB,brg)==0){
				ketemu = true;
			} else{
				bar = (bar)->next;
			}
		}
	}
	return (bar);
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVLastP (ListP *P, infotype plgn){
    // Kamus Lokal
	addressP Pel;
	
	// Algoritma
    Pel = AlokasiP (plgn);
		if (P != NULL){
			InsertLastP (&(*P), Pel);
		}
}

void InsVLastB(addressP pel, infotype brg, int qty){
    // Kamus Lokal
    addressB bar;

    // Algoritma
    bar = AlokasiB(brg, qty);
    if(bar != NULL){
        InsertLastB(pel, bar);
    }
}

/**** Penghapusan Elemen ****/
void DelVFirstP (ListP *P, int id){
     /* Kamus Lokal */
 	addressP Pel;
	infotype *plgn;
	
 	/* Algoritma */
 	if(ListK[id].cust != NULL){
	 	Pel = (*P).head;
	 	*plgn = (Pel)->infoP;
	 	(*P).head = ((*P).head)->after;
	 	ListK[id].cust = (*P).head;
	 	
		if (Pel != NULL){
			free (Pel);
		}
		printf("Pelanggan yang bernama %s, telah melakukan pembayaran\n", *plgn);
	} else{
		printf("Tidak ada pelanggan yang mengantri\n");
	}
}
// void DelVFirstP (ListP *P, infotype *plgn){
//     /* Kamus Lokal */
// 	addressP Pel;
	
// 	/* Algoritma */
// 	Pel = (*P).head;
// 	*plgn = (Pel)->infoP;
// 	(*P).head = ((*P).head)->after;
// 	DeAlokasiP (Pel);
// }

// void DelVLastP (ListP *P, infotype *plgn){
//     /* Kamus Data */
// 	addressP PelDel;
	
// 	/* Algoritma */
// 	PelDel = (*P).tail;
// 	DelLastP (&(*P), &PelDel);
// 	(*plgn) = (PelDel)->infoP;
// 	DeAlokasiP (PelDel);
// }

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertLastP (ListP *P, addressP pel){
    // Algoritma
	if (!ListEmptyP){
		((*P).tail)->after = pel;
        (pel)->before = (*P).tail;
        (*P).tail = pel;
	} else {
		(*P).head = pel;
		(*P).tail = pel;
	}
}

void InsertLastB(addressP pel, addressB bar){
    // Kamus Lokal
    addressB bTemp;

    // Algoritma
    if((*pel).cart != NULL){
        bTemp =  (*pel).cart;
        while ((bTemp)->next != NULL){
            bTemp = bTemp->next;
        }
        bTemp->next = bar;
        (bar)->prev = bTemp;
        // (*B).last = bar;
    }else{
        (*pel).cart = bar;
        //(*B).first = bar;
        //(*B).last = bar;
    }
}

void InsertToK(ListP *P, addressP pel, int id){
    // Kamus Lokal
    addressP temp;

    // Algoritma
    if(ListEmptyP(*P)){
        (*P).head = pel;
        (*P).tail = pel;
        ListK[id].cust = pel;
    }else{
        (*P).tail->after = pel;
        (pel)->before = (*P).tail;
        (*P).tail = pel;
    }
}

/**** Penghapusan sebuah elemen ****/
// void DelFirstP (ListP *P, addressP *pel){
//     /* Algoritma */
// 	*pel = (*P).head;
// 	(*P).head = ((*P).head)->after;
// }

void DelAnyP (ListP *P, infotype plgn){         //BELUM BERES
 	/* Kamus Lokal */
 	addressP pel, prec=NULL, simpan;
 	bool ketemu=false;
 	
     /* Algoritma */
 	pel = (*P).head;
 	while((pel != NULL) &&(!ketemu)){
 		if(strcmp((pel)->infoP,plgn)==0){
 			ketemu = true;
 		}else{
 			prec = pel;
 			pel = (pel)->after;
 			simpan = pel;
 		}
 	}
 	if(ketemu){
 		//DelAllB(pel);
 		if(prec == NULL && (pel)->after == NULL){
 			(*P).head = NULL;
 			(pel)->after = NULL;
 		}else if(prec == NULL){
 			(*P).head =(pel)->after;
 			(pel)->after = NULL;
 		}else if((pel)->after == NULL){
 			(*P).tail = NULL;
 			(pel)->before = NULL;
 			(prec)->after = NULL;
 		}else{
 			(prec)->after = (pel)->after;
 			//pel =(pel)->after;
 			((pel)->after)->before = prec;
 		}
 		
 		if(pel != NULL){
        	free(pel);
        }
        printf("\nPelanggan telah batal untuk belanja\n");
 	} else {
 		printf("\nPelanggan gagal membatalkan belanja\n");
	 }
}

void DelAllB(addressP pel){             // BELUM BERES      
	// Kamus Lokal
	addressB barDel;
	
	//Algoritma
	barDel = pel->cart;
	while (barDel != NULL){
//		DelFirstP (&(*pel), &barDel);
//		*barDel = (*pel)->car;
//		(*pel).cart = ((*pel).cart)->next;
		if (barDel != NULL){
			free (barDel);
			barDel = pel->cart;
		}
	}
	(*pel).cart = NULL;
}

void DelAnyB(addressP pel, infotype brg){
    // Kamus Lokal
    addressB bar, prec=NULL;
    bool ketemu=false;

    // Algoritma
    bar = (*pel).cart;
    while ((bar != NULL) && (!ketemu)){
        if(strcmp((bar)->infoB, brg)==0){
            ketemu = true;
        }else{
            prec = bar;
            bar = bar->next;
        }
    } 
    if(ketemu){
        if((prec == NULL) && ((bar)->next == NULL)){    //hanya ada 1 node
            (*pel).cart = NULL;
        }else if((prec == NULL)){                       // merupakan node pertama
			(*pel).cart = (bar)->next;            
            // temp = (bar)->next;
            // (*pel).cart = temp;
            // (temp)->prev = NULL;
            // (bar)->next = NULL;
        }else if((bar)->next == NULL){                  // merupakan node terakhir
            (bar)->prev = NULL;
            (prec)->next = NULL;
        }else{
            (prec)->next = (bar)->next;
        	((bar)->next)->prev = prec;
            // (bar)->next = NULL;
            // (bar)->prev = NULL;
            // ((bar)->next)->prev = prec;
            // (prec)->next = (bar)->next;
        }
        if(bar != NULL){
        	free((bar)->infoB);
            free(bar);
        }
        printf("\nBarang sudah dikembalikan ke etalase\n");
    }else{
        printf("\nBarang tidak ditemukan dalam keranjang\n");
    }
}

void updateQty(addressP pel, infotype brg, int qty){
	// Kamus Lokal
	addressB update, prec=NULL, temp;
    bool ketemu=false;
    
	// Algoritma
	update = (pel)->cart;
    while ((update != NULL) && (!ketemu)){
        if(strcmp((update)->infoB, brg)==0){
            ketemu = true;
        }else{
            prec = update;
            update = (update)->next;
        }
    }
    
    if(ketemu){
    	(update)->qtyB = qty;
    	printf("Jumlah barang telah diubah\n");
	} else {
		printf("Jumlah barang gagal diubah\n");
	}

}

// int CountQtyCurB(ListB B){
// 	/* Kamus Lokal */
// 	int qty=0;
// 	addressB bar;

// 	/* Algoritma */
// 	bar = (B).first;
// 	if(bar != NULL){
// 		qty += (bar)->qtyB;
// 		bar = (bar)->next;
// 	}
// 	return (qty);
// }

// int CountQtyAllB(ListB B, int id){
// 	/* Kamus Lokal */
// 	int qty=0;
// 	addressP pel;
// 	addressB bar;

// 	/* Algoritma */
// 	pel = ListK[id].cust;
// 	bar = (pel)->cart;
// 	while((pel)->after != NULL){
// 		if(bar != NULL){
// 			qty += (bar)->qtyB;
// 			bar = (bar)->next;
// 		}else{
// 			(pel)->after;
// 		}
// 	}
// 	return (qty);
// }

// int CountP(ListP P, int indexK){
// 	/* Kamus Lokal */
// 	int qtyP=0;
// 	addressP pel;

// 	/* Algoritma */
// 	pel = ListK[indexK].cust;
// 	while((pel)->after != NULL){
// 		qtyP += 1;
// 		pel = (pel)->after;
// 	}
// 	return(qtyP);
// }

// void DelLastP (ListP *P, addressP *pel){
//     /* Kamus Data */
// 	addressP Prec;
	
// 	/* Algoritma */
// 	Prec = (addressP) (*pel)->before;
	
// 	if (Prec == NULL)
// 	{
// 		(*P).tail = NULL;
// 		(*P).head = NULL;
// 	} else
// 	{
// 		(Prec)->after = NULL;
// 		(*pel)->before = NULL;
// 		(*P).tail = Prec;
// 	}
// }


void PrintInfoK (){
	int i=0;
	for(i; i<jmlK; i++){
		if(ListK[i].infoK != NULL){
			printf("%d. %s\n",i+1, ListK[i].infoK);
		}
	}
}

void PrintCustK (ListP P, int id){
	addressP Pel; 
	addressB B;
	
	if(ListK[id].cust != NULL){
		Pel = ListK[id].cust;
		printf("%s: \n", (ListK[id]).infoK);
		while (Pel != NULL){
			B = (Pel)->cart;
			printf("   %s <-", (Pel)->infoP);
			
			while (B != NULL){
				printf("(%s [%d]) ", (B)->infoB, (B)->qtyB);
				B = (B)->next;
			}
			printf("\n");
			Pel = (Pel)->after;
		}
		printf("\n");
	} else {
		printf("%s: Antrian masih kosong \n",(ListK[id]).infoK);
	}
}

void PrintInfoKP (ListP P1, ListP P2, ListP P3, ListP temp){
	addressP aTemp, aP1, aP2, aP3;
    addressB B1, B2, B3;
    if (ListK[0].cust != NULL) {
        aP1 = ListK[0].cust;
        printf("1. %s: \n",(ListK[0]).infoK);
        while (aP1 != NULL) {
            B1 = (aP1)->cart;
            printf("   %s <- ", (aP1)->infoP);
            
            while (B1 != NULL) {
                printf("(%s [%d]) ", (B1)->infoB, (B1)->qtyB);
                B1 = (B1)->next;
            }
            printf("\n");
            aP1 = (aP1)->after;
        }
        printf("\n");
    } else {
        printf("1. %s: - \n",(ListK[0]).infoK);
    }

    if(ListK[1].cust != NULL){
        aP2 = ListK[1].cust;
		printf("2. %s: \n",(ListK[1]).infoK);
        while (aP2 != NULL) {
            B2 = (aP2)->cart;
            printf("   %s <- ", (aP2)->infoP);
            
            while (B2 != NULL) {
                printf("(%s [%d]) ", (B2)->infoB, (B2)->qtyB);
                B2 = (B2)->next;
            }
            
            printf("\n");
            aP2 = (aP2)->after;
        }
        printf("\n");
    }else{
		printf("2. %s: - \n",(ListK[1]).infoK);
    }

    if(ListK[2].cust != NULL){
        aP3 = ListK[2].cust;
		printf("3. %s: \n",(ListK[2]).infoK);
        while (aP3 != NULL) {
            B3 = (aP3)->cart;
            printf("   %s <- ", (aP3)->infoP);
            
            while (B3 != NULL) {
                printf("(%s [%d]) ", (B3)->infoB, (B3)->qtyB);
                B3 = (B3)->next;
            }
            
            printf("\n");
            aP3 = (aP3)->after;
        }
        printf("\n");
    }else{
		printf("3. %s: - \n",(ListK[2]).infoK);
    }
    if((temp).head == NULL){
        printf("Belum ada pelanggan di 2CC-Mart\n");
    }	
}

void PrintInfoPB (ListP P, int id){
    // Kamus Lokal
    addressP pel;
    addressB bar;
    int i = 1;

    // Algoritma
    pel = (P).head;
    bar = (*pel).cart;
    if(bar == NULL){
        printf("Keranjang kosong...\n");
    }else{
        printf("Isi keranjang belanja %s: \n",(pel)->infoP);
        printf("-------------------------------------------\n");
        printf("| No |      Nama Barang      |   Jumlah   |\n");
        printf("-------------------------------------------\n");
        
        if(id == -1){
            while(bar != NULL){
                printf("| %d | %-22s |  %-8d  |\n", i,(bar)->infoB, (bar)->qtyB);
                bar = (bar)->next;
                i++;
            }
        }
        printf("-------------------------------------------\n");
    }
}

void LoadBFromFile(){
	FILE* file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("File barang.txt tidak ditemukan!\n");
        return;
    }
    char jml[100];
    while (fgets(jml, 100, file)) {
        Barang barang;
        char* namaBarang = strtok(jml, ";");
        char* hargaBarang = strtok(NULL, ";");
        char* stokBarang = strtok(NULL, ";");
        
        if (namaBarang != NULL && hargaBarang != NULL && stokBarang != NULL) {
            strcpy(barang.nama, namaBarang);
            barang.harga = atoi(hargaBarang);
            barang.stok = atoi(stokBarang);
            listBarang[jumlahBarang] = barang;
            jumlahBarang++;
        }
    }
    
    fclose(file);
}

void PrintB(){
	printf("---------------------------------------------------\n");
    printf("| No |           Nama         |  Harga  |   Stok  |\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("| %-2d | %-22s |  %6d |  %5d  |\n",
            i+1, listBarang[i].nama, listBarang[i].harga, listBarang[i].stok);
    }
    printf("---------------------------------------------------\n");
}