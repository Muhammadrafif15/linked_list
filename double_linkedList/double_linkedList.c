#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================
//nama = Muhammad Rafif Rizqullah
// NPM = 23081010301

struct node {
	int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void banyakData(node *head);
void tranverse(node *head);


//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
   system("cls");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir\n");
     printf("4. hapus data di awal\n");
     printf("5. hapus data\n");
     printf("6. hapus data di akhir\n");
     printf("7. cari data\n");
     printf("8. jumlah data\n");
     printf("9. banyak data\n");
     printf("0. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1') tambahAwal(&head);
     else if (pilih == '2') tambahData(&head);
     else if (pilih == '3') tambahAkhir(&head);
     else if (pilih == '4') hapusAwal(&head);
     else if (pilih == '5') hapusData(&head);
     else if (pilih == '6') hapusAkhir(&head);
     else if (pilih == '7') cariData(head);
     else if (pilih == '8') jumlahData(head);
     else if (pilih == '9') banyakData(head);
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
   pNew->prev = NULL;

   if (*head != NULL) (*head) -> prev = pNew;
   *head = pNew;
   printf("Data Berhasil di Input");
   getch();
   
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
  printf("\n\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

   pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
   pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));
  pNew->data = bil;

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
   if (pCur->next == NULL)
   {
      // jika diapit oleh dua node satu bernilai, satu bernilai null 
      pNew -> data = bil;
      pNew -> next = pCur->next;
      pNew -> prev = pCur;
      pCur -> next = pNew;
   }else
   {
      // posisi di tengah node bernilai
      pNew -> data = bil;
      pNew -> next = pCur->next;
      pNew -> prev = pCur;
      pCur -> next -> prev = pNew;
      pCur -> next = pNew;
   }
   printf("\nData berhasil diInput");
   getch();
  }
}


void tambahAkhir(node **head){
   int bil;
   node *pNew, *pCur;

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
      pNew->prev = NULL;

      if (*head == NULL) *head = pNew;
      else{

         pCur = *head;
         while (pCur -> next != NULL){
            pCur = pCur->next; 
         }
         pCur -> next = pNew;
         pNew -> prev = pCur;         
         pNew -> next = NULL;    //pNew -> next = pCur -> next;   // menghubungkan ke node selanjutnya dari pnew
      }
   printf("Data berhasil di Input");

   }else{
      printf("input memori gagal");

   }
   getch();
   
}
void hapusAwal(node **head){

   node *pCur;
   if (*head == NULL) printf("Tidak ada Node");
   else
   {
      pCur = *head;
      *head = pCur -> next;
      pCur -> prev = NULL;
      free(pCur); 
     printf("\nData Berhasil Dihapus"); 
   }
   getch();
   
}
void hapusData(node **head){
   node *pCur;
   int bil;

   if (*head == NULL) {
   printf("Data Kosong");
   }else{

      system("cls");
      tranverse(*head);
      printf("\n\nData Yang ingin dihapus : ");
      scanf("%d", &bil);

      pCur = *head;
      while (pCur != NULL && pCur -> data != bil)
   {
      pCur = pCur -> next;
   }
   
   if(pCur == NULL){ printf("Data Invalid");
   }else{
      if (pCur -> prev != NULL)  pCur -> prev -> next = pCur -> next;
      else *head = pCur -> next;
      if (pCur -> next != NULL) {
         pCur -> next -> prev = pCur -> prev;
      }
      // else pCur -> prev -> next = pCur -> next;
      free(pCur);
      printf("Data berhasil dihapus");
   }
   }
   getch();
}
void hapusAkhir(node **head){
   if (*head == NULL) {
      printf("Data Kosong");
   }
   else if ((*head) -> next == NULL){
      *head = (*head) -> next;
      free(*head);
      printf("Data Berhasil Dihapus");
   }else{
      node *pCur = *head;
      while (pCur -> next!= NULL)
      {
         pCur = pCur-> next;
      }
      pCur -> prev -> next = NULL;
      free(pCur);
      printf("Data Berhasil Dihapus");
   }
   getch();
}
void cariData(node *head){
   int target;
   node *pCur;

   system("cls");
   printf("Data Yang dicari : ");
   scanf("%d", &target);

   pCur = head;
   while (pCur != NULL && pCur->data != target){
   pCur = pCur->next;
   }
   printf(pCur ? "data ditemukan" : "data tidak ditemukan");
   getch();
}
void jumlahData(node *head){

   int count;
   while (head != NULL)
   {
      count += head-> data;
      head = head -> next;
   }
   system("cls");
   printf("total data pada list adalah : %d", count);
   getch();
   
}
void banyakData(node *head){

   int count;
   while (head != NULL)
   {
      count++;
      head = head->next;
   }
   system("cls");
   printf("Banyak data pada list : %d", count);
   getch();
}



void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
   printf("NULL <-> ");
	while (pWalker != NULL){
         printf("%d", pWalker -> data);
         printf(" <-> ");
   	   pWalker = pWalker -> next;
	}
   printf("NULL");
}

