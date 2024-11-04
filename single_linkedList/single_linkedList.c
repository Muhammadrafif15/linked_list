#include <stdio.h>
#include <conio.h>

#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungBanyakData(node *head);
void jumlahData(node *head);
void tranverse(node *head);


//========================================================

int main()
{
   node *head;
  char pilih;
  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list\n");
     printf("=======================================\n");
     printf("4. hapus data di awal\n");
     printf("5. hapus data di tengah list\n");
     printf("6. hapus data di akhir list\n");
     printf("=======================================\n");
     printf("7. cari data\n");
     printf("8. hitung banyak data list\n");
     printf("9. jumlah semua data list\n");
     printf("0. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
      if (pilih == '1')
         tambahAwal(&head);
      else if (pilih == '2')
         tambahData(&head);
      else if (pilih == '3')
         tambahAkhir(&head);
      else if (pilih == '4')
         hapusAwal(&head);
      else if (pilih == '5')
         hapusTengah(&head);
      else if (pilih == '6')
         hapusAkhir(&head);
      else if (pilih == '7')
         cariData(head);
      else if (pilih == '8')
         hitungBanyakData(head);
      else if (pilih == '9')
         jumlahData(head);
      else if (pilih == '0'){
         tranverse(head);
         getch();
     }
  } while (pilih != 'q'); 
 
  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = *head;
      //add before first logical node or to an empty list
      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================

void tambahAkhir(node **head){

    int bil;
    node *pNew, *pCurr;

    system("cls");
    fflush(stdin);
    printf("\nMasukkan Bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));


    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->next = NULL;
        if (*head == NULL)
        {
            *head = pNew;
        }else
        {
            pCurr = *head;
            while (pCurr->next != NULL)
            {
                pCurr = pCurr->next;
            }
            pCurr->next = pNew;
        }
    }else{
        printf("Input ke Memeori Error");
        getch();
    }
}

//========================================================

void hapusAwal(node **head){
    node *pCurr;
    if (*head == NULL){
        printf("\nTidak ada data yang dapat dihapus");
        getch();
    }else{
        pCurr = *head;
        *head = pCurr->next;
        free(pCurr);
        printf("Data telah dihapus");
        getch();
    }
    
    
}
void hapusTengah(node **head){
   node *temp, *pCurr;
   int bil;

   system("cls");
   tranverse(*head);
   printf("\nMasukkan nilai yang ingin dihapus : ");
   fflush(stdin);
   scanf("%d", &bil);

   for (node **pCurr = head; *pCurr; pCurr = &(*pCurr)->next)
   {
      if((*pCurr)->data == bil){
            temp = *pCurr;
            *pCurr = (*pCurr)->next;
            free(temp);
            printf("Data berhasil dihapus");
            getch();
            return;
      }
   }
   printf("data tidak ditemukan");
   
}
void hapusAkhir(node **head){
   if(!(*head)){
      printf("Tidak ada data ");
      getch();
   }
   else if(!(*head)->next){
      free(*head);
      *head = NULL;
      printf("data berhasil dihapus ");
      getch();
   }else{
      node **pCurr = head;
      while ((*head)->next->next)
      {
         pCurr = &(*pCurr)->next;
      }
      free((*pCurr)->next);
      (*pCurr)->next = NULL;
      printf("data berhasil dihapus ");
      getch();
   }
}
void cariData(node *head){
   int cari;
   system("cls");
   printf("Masukkan Nilai yang ingin dicari: ");
   scanf("%d", &cari);

   node *pCurr = head;
   while (pCurr && pCurr->data != cari){
      pCurr = pCurr->next;
   }
   printf(pCurr ? "Data %d ditemukan " : "Data %d tidak ditemukan ", cari);
   getch();
}
void hitungBanyakData(node *head){
   int count;
   node *pCurr = head;
   while (pCurr != NULL ){
      count ++;
      pCurr = pCurr->next;
   }
   system("cls");
   printf("Banyak data didalam list adalah : %d ",count);
   getch();
}
void jumlahData(node *head){
   int total;
   node *pCurr = head;
   while (pCurr != NULL)
   {
      total += pCurr->data;
      pCurr = pCurr->next; 
   }
   system("cls");
   printf("total nilai dari list adalah %d ",total);
   getch();
   
}

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf(" %d\t ", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
}