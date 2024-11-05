#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

// dibuat oleh 
// Nama = Muhammad rafif Rizqullah
// NPM = 23081010301

 struct Node{
    int data;
   struct Node *next;
};

 struct Stack
{
   struct Node *top;
    int count;
};
typedef struct Node Node;
typedef struct Stack stack;

int top(stack *s);
int pop(stack *s);
bool isEmpty(stack *s);
bool isFull(stack *s);
void push(stack *s, int value);
void makeEmpty(stack *s);
void dislay(stack *s);
void destroyStack(Stack* stack);

int main(){
    stack Stack;
    Stack.top = NULL;
    Stack.count = 0;
    int pilih, value;

    makeEmpty(&Stack);

    do
    {
        printf("\n1. push");
        printf("\n2. pop");
        printf("\n3. top");
        printf("\n4. Cek Keadaan Stack\n");
        printf("5. Stack Full\n");
        printf("6. Display Stack\n");
        printf("7. Kosongkan Stack\n");
        printf("8. Destoy Stack\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            system("cls");
            printf("Nilai : ");
            scanf("%d", & value);

            push(&Stack, value);
            Stack.count++;
            getch();
            break;
        case 2:
            system("cls");
            if (!isEmpty(&Stack)) {
                pop(&Stack);
                printf("Nilai terhapus");
                Stack.count--;
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
            if (isEmpty(&Stack)) printf("Stack kosong, tidak bersisi data");
            else printf("Stack terisi %d", Stack.count);
            getch();
            break;
        case 5: 
            // system("cls");
            // if (isFull(&Stack)) printf("Stack Penuh");
            // else printf("Stack Kosong");
            // getch();
            break;
        case 6:
            system("cls");
            dislay(&Stack);
            getch();
            break;
        case 7:
            system("cls");
            makeEmpty(&Stack);
            Stack.count = 0;
            getch();
            break;
        case 8:
            system("cls");
            destroyStack(&Stack);
            Stack.count=0;
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
    return s->top->data;
}
int pop(stack *stack){

    if (isEmpty(stack))
    {
        printf("data kosong");
        return -1;
    }
    Node *tmp = stack->top;
    int data = tmp->data;
    stack->top = tmp->next;
    free(tmp);
    return data;
}
int count(stack *s){
    return s->count;
}
bool isEmpty(stack *s){
    return s->top == NULL;
}
bool isFull(stack *s){
    return s->count == 10 ;
}
void push(stack *stack, int data){
    if (isFull(stack))
    {
        printf("stuck penuh \n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++ ;
    
    printf("Berhasil\n");
    
}
void makeEmpty(stack *s){
    s->count = -1;
}
void dislay(stack *s){
    if (isEmpty(s))
    {
        printf("data kosong\n");
        return ;
    }
    Node *curr = s->top;
    printf(" top -->>");
    while (curr != NULL)
    {
        printf(" %d ", curr->data);
        curr = curr->next;
        s->count--;
    }
}
void destroyStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}