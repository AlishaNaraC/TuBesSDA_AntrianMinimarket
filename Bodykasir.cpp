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
void CreateListK (ListK *K){
	(*K)->cust =NULL;
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
addressP AlokasiP (infotype plgn){
	 /* Kamus Lokal */
	 addressP pel;
	 /* Algoritma */
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
	/* Kamus Lokal */
	addressB bar;
	/* Algoritma */
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

void DeAlokasiP (addressP pel){
	if(pel != NULL){
		free(pel);
	}
}

void DeAlokasiB (addressB bar){
	if(bar != NULL){
		free(bar);
	}
}

/**** Pencarian sebuah elemen List ****/
// mencari index dari kasir
int SearchK (ListK K, infotype ksr){
	for(int i=0; i<jmlK; i++){
		if((strcmp(K[i].infoK,ksr))==0){
			return i;
		}
	}
	return -1;
}

// mencari alamat dari node pelanggan
addressP SearchP (ListP P, infotype plgn){
	/* Kamus Lokal */
	addressP pel;
	bool ketemu = false;

	/* Algoritma */
	pel = (P).head;
	while((pel != NULL) && (!ketemu)){
		if(strcmp((pel)->infoP,plgn)){
			ketemu = true;
		}else{
			pel = (pel)->after;
		}
	}
	return (pel);
}

// mencari alamat dari node barang
addressB SearchB (ListB B, infotype brg){
	/* Kamus Lokal */
	addressB bar;
	bool ketemu = false;

	/* Algoritma */
	bar = (B).first;
	while((bar != NULL) && (!ketemu)){
		if(strcmp((bar)->infoB,brg)){
			ketemu = true;
		}else{
			bar = (bar)->next;
		}
	}
	return (bar);
}

bool FSearchK (ListK K, addressK kas){

}

bool FSearchP (ListP P, addressP pel){

}

bool FSearchB (ListB B, addressB bar){

}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVLastP (ListP *P, infotype plgn){
    // keanu
}

void InsVLastB (ListB *B, infotype brg, int qty){
	/* Kamus Lokal */
	addressB bar;
	/* Algoritma */
	bar = AlokasiB (brg, qty);
	if (bar != NULL){	
		InsertLastB (&(*B), bar);		
	}	
}

/**** Penghapusan Elemen ****/
void DelVFirstP (ListP *P, infotype *plgn){
    // keanu
}

void DelVFirstB (ListB *B, infotype *brg){
	 /* Kamus Lokal */
	addressB bar;
	 /* Algoritma */
	bar =  (*B).first;
	*brg = (bar)->infoB;
	(*B).first = ((*B).first)->next;
	DeAlokasiB (bar);
}

void DelVLastP (ListP *P, infotype *plgn){
    // keanu
}

void DelVLastB (ListB *B, infotype *brg) {
	 /* Kamus Lokal */
	addressB barDel;
	 /* Algoritma */
	barDel = (*B).first;
	DelLastB (&(*B), &barDel);
	(*brg) = (barDel)->infoB;
	DeAlokasiB (barDel);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertLastP (ListP *P, addressP pel){
    // keanu
}

void InsertLastB (ListB *B, addressB bar){
	 /* Kamus Lokal */
	addressB Last;
	 /* Algoritma */
     if(ListEmptyB){
        (*B).first = bar;
        (*B).last = bar;
     }else{
        ((*B).last)->next = bar;
        (bar)->prev = (*B).last;
        (*B).last = bar;
     }
}

/**** Penghapusan sebuah elemen ****/
/*
void DelFirstP (ListP *P, addressP *pel){
    // keanu
}*/

void DelFirstB (ListB *B, addressB *bar) {
	 *bar = (*B).first;
	 (*B).first = ((*B).first)->next;
}

void DelAnyP (ListP *P, infotype plgn){
	/* Kamus Lokal */
	addressP pel, prec=NULL;
	bool ketemu=false;
    /* Algoritma */
	pel = (*P).head;
	while((pel != NULL) &&(!ketemu)){
		if(strcmp((pel)->infoP,plgn)==0){
			ketemu = true;
		}else{
			prec = pel;
			pel = (pel)->after;
		}
	}
	if(ketemu){
		if(prec == NULL && (pel)->after == NULL){
			(*P).head = NULL;
		}else if(prec == NULL){
			(*P).head = (pel)->after;
		}else{
			(prec)->after = (pel)->after;
		}
		(pel)->after = NULL;
		DeAlokasiP (pel);
	}
}

void DelAnyB (ListB *B, infotype brg){
    /* Kamus Lokal */
    addressB bar, prec=NULL;
    bool ketemu=false;
    /* Algoritma */
    bar = (*B).first;
    while((bar != NULL) && (!ketemu)){
        if(strcmp((bar)->infoB,brg)==0){
            ketemu = true;
        }else{
            prec = bar;
            bar = (bar)->next;
        }
    }
    if(ketemu){
        if(prec == NULL && (bar)->next == NULL){
            (*B).first = NULL;
        }else if(prec == NULL){
            (*B).first = (bar)->next;
        }else{
            (prec)->next = (bar)->next;
        }
        (bar)->next=NULL;
        DeAlokasiB (bar);
    }
}

/*
void DelLastP (ListP *P, addressP *pel){
    // keanu
}*/

void DelLastB (ListB *B, addressB *bar) {
	 /* Kamus Lokal */
	addressB Prec;
	 /* Algoritma */
	*bar = (*B).first;
	Prec = NULL;
	while ((*bar)->next != NULL)
	{
		Prec = *bar;
		*bar = (*bar)->next;
	}

	if (Prec == NULL)	{	
		(*B).first = NULL;	
	}else{		
		(Prec)->next = NULL;	
	}
}

/**** PROSES SEMUA ELEMEN LIST  ****/
// tampilkan pada layar
/**** Display ****/
void DisplayMenuAwal(){
	// sama niqa
}

void DisplayMenuMasuk(){
	
}

void DisplayMenuKeluar(){

}

void DisplayMenuLanjutan(){

}

void DisplayMenuBelanja(){

}

void DisplayMenuKassa(){

}


