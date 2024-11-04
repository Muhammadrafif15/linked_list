#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================
//Nama : Muhammad Rafif Rizqullah
//NPM : 23081010301

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
        system("cls");
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
      // jika hanya satu data, maka akan menunjuk ke dirinya sendiri
      if(*head == NULL){
        pNew -> next = pNew;
      }else{
        pNew -> next = *head;
        node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = pNew;
      }
    *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil, found = 0;
  node *pNew, *pCur;

if (*head == NULL)
{
    system("cls");
    printf("List kosong");
    getch();
    return;
}

system("cls");
tranverse(*head);
printf("\nposisi penyisipan setelah data bernilai : ");
fflush(stdin);
scanf("%d", &pos);


printf("bilangan : ");
fflush(stdin);
scanf("%d", &bil);

  pCur = *head;
do
  {
    if (pCur->data == pos)
    {
        pNew = (node *)malloc(sizeof(node));
        if (pNew == NULL)
        {
            printf("Alokasi data Gagal");
            getch();
            return;
        }
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew; 
    }
    
    pCur=pCur->next;
    
} while (pCur != *head);
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

        if (*head == NULL)
        {
            pNew -> next = pNew;
            *head = pNew;
        }else
        {
            pCurr = *head;
            while (pCurr->next != *head)
            {
                pCurr = pCurr->next;
            }
            pCurr->next = pNew;
            pNew->next = *head;
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

    //kondidi ketika hanya ada satu data itupun menunjuk kedirinya berarti menghapus diri sendiri
    }else if (pCurr->next == *head)
    {
        free(*head);
        *head = NULL;
        printf("Data berhasol dihapus");
        getch();
    }
    
    else{
        node *last = *head;
        node *temp = *head;

        while (last->next != *head)
        {
            last = last->next;
        }
        //
        *head = (*head)->next;          //menunjuk ke node selanjutnya
        last->next = *head;         
        
        free(temp);
        printf("Data telah dihapus");
        getch();
    }
    
    
}
void hapusTengah(node **head){
   node *prev = NULL, *pCurr = *head;
   int bil;

   system("cls");
   tranverse(*head);
   printf("\nMasukkan nilai yang ingin dihapus : ");
   fflush(stdin);
   scanf("%d", &bil);\

   if (!*head)
   {
    printf("List kosong");
    getch();
    return;
   }
   do
   {
    if(pCurr->data == bil){
        if(pCurr == *head){
            if(pCurr->next == pCurr){
                free(pCurr);
                *head = NULL;
            }else
            {
                node *last = *head;
                while(last->next != *head) last = last->next;
                *head = pCurr->next;
                last->next = *head;
                
                free(pCurr);
            }
            
        }else{
            prev->next = pCurr->next;
            free(pCurr);
        }
        printf("data dihapus");
        getch();
        return;
    }
    prev = pCurr;
    pCurr = pCurr->next;
   } while (pCurr->next != *head);

   printf("data tidak ditemukan");
}
void hapusAkhir(node **head){

node *pCurr = *head, *prev = NULL;

   if(*head == NULL){
      printf("Tidak ada data ");
      getch();
   }
   if(pCurr->next == *head){
      free(pCurr);
      *head = NULL;
      printf("data berhasil dihapus ");
      getch();
   }else{
      while (pCurr->next != *head){
        prev = pCurr;
        pCurr = pCurr->next;
      }
      //mengarahkan head ke node selanjutanya, agar node sekarang bisa dihapus
      prev->next = *head;
      free(pCurr);
 
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
   int count = 0;
   node *pCurr = head;

   do
   {
    count ++;
    pCurr = pCurr->next;
   } while (pCurr != head);
   
   system("cls");
   printf("Banyak data didalam list adalah : %d ",count);
   getch();
}
void jumlahData(node *head){
   int total = 0;
   node *pCurr = head;

   do
   {
    total += pCurr->data;
      pCurr = pCurr->next; 
   } while (pCurr != head);
   
   system("cls");
   printf("total nilai dari list adalah %d ",total);
   getch();
   
}

void tranverse(node *head){

    system("cls");
    if (head == NULL) {
        printf("List kosong");
    } else {
        node *pWalker = head;
        do {
            printf(" %d ", pWalker->data);
            pWalker = pWalker->next;
            printf(" -> ");
        } while (pWalker != head);
        printf(" %d() ", head->data);
    }
}