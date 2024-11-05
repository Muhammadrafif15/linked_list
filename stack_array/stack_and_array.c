#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

// dibuat oleh 
// Nama = Muhammad rafif Rizqullah
// NPM = 23081010301

struct Stack
{
    int data[100];
    int top;
};

typedef struct Stack stack;
int top(stack *s);
int pop(stack *s);
bool isEmpty(stack *s);
bool isFull(stack *s);
void push(stack *s, int value);
void makeEmpty(stack *s);
void dislay(stack *s);

int main(){
    stack Stack;
    int pilih, value;

    makeEmpty(&Stack);

    do
    {
        printf("\n1. push");
        printf("\n2. pop");
        printf("\n3. top");
        printf("\n4. Cek Stack Kosong\n");
        printf("5. Cek Stack Penuh\n");
        printf("6. Tampilkan Stack\n");
        printf("7. Kosongkan Stack\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            system("cls");
            printf("Nilai : ");
            scanf("%d", & value);

            push(&Stack, value);
            getch();
            break;
        case 2:
            system("cls");
            if (!isEmpty(&Stack)) {
                value = pop(&Stack);
                printf("Nilai yang di-pop: %d\n", value);
            }
            else printf("data kosong");
            getch();
            break;
        case 3:
            system("cls");
            if (!isEmpty(&Stack)) {
            value = top(&Stack);
            printf("Nilai yang di-top: %d\n", value);
            }
            else printf("data kosong");
            getch();
            break;
        case 4:
            system("cls");
            if (isEmpty(&Stack)) printf("Stack kosong");
            else printf("Stack penuh");
            getch();
            break;
        case 5:
            system("cls");
            if (isFull(&Stack)) printf("Stack Penuh");
            else printf("Stack Kosong");
            getch();
            break;
        case 6:
            system("cls");
            dislay(&Stack);
            getch();
            break;
        case 7:
            system("cls");
            makeEmpty(&Stack);
            getch();
            break;
        default:
            break;
        }
    } while (pilih != 0);
    
}
int top(stack *s){
    if (isEmpty(s))
    {
        printf("data kosong");
        return -1;
    }
    return s->data[s->top];
}
int pop(stack *s){

    if (isEmpty(s))
    {
        printf("data kosong");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
    
}
bool isEmpty(stack *s){
    return s->top == - 1;
}
bool isFull(stack *s){
    return s->top == 100 - 1;
}
void push(stack *s, int value){
    if (isFull(s))
    {
        printf("stuck penuh \n");
        return;
    }
    s->top++;
    s->data[s->top] = value;
    printf("Berhasil\n");
    
}
void makeEmpty(stack *s){
    s->top = -1;
}
void dislay(stack *s){
    if (isEmpty(s))
    {
        printf("data kosong\n");
        return ;
    }
    for (int i = s->top; i >= 0 ; i--)
    {
        printf("%d ->", s->data[i]);
        if (i == s->top)
        {
            printf("<- top");
        }
        printf("\n");
    }
    
}