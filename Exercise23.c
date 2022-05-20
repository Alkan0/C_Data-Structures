//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
//� ������ ������� �� ���������� �� ��� ������� ���� ������� ���������
//�� �������� ���� ����������� ��� �������� � ��������� ������.

struct myStack { //���� �������.
    int top;
    int array[MAXSIZE];
}Stack;

void initialize() { //��������� �������������.
 Stack.top = -1;
}

void insertAtBottom(int item) {//��������� ��� ��������� ���� ��������� ���� ��� ������� ����������.
    if (isEmpty()) {//���� ��������� ������ ������� ������� �������� ����������.
        push(item);
    } else {
        int top = pop();
        insertAtBottom(item);
        push(top);
    }
}

void reverse() {
    if (!isEmpty()) {//���� ��������� ��� � ������ ��� ���� �������� ����, �������
        //���� ��� ����� ��� ������� ���������� ���� ��������� top,
        //���� ���������� � reverse ����������,
        //�� ����� ��� top ������ ���� �����.���� ��� �������� ���� �������� �� ������ pop
        //� ��������� ������ ��� ���� ��� ����� ��� ����� �������������
        //���� ����� �� ����� �������� �� ��������� ��� ������������.
        //��� �� ���������� � insertAtBottom �� ��� �� �������� ���� �� ������� �����.
        int top = pop();
        reverse();
        insertAtBottom(top);
    }
}
void reverseH(int x) {//��������� ��������� reverse
    if (!isEmpty()) {
        int top = pop();
        reverseH(x);
        if(top!=x)
            insertAtBottom(top);
    }
}
void clear(int x)//��������� ��������� ���� ��� ���������� ���� �����.
{
    reverseH(x);
    reverse();
}

int isFull()//������� ��� � ������ ���� ������ ��� ������� ��������� ����.
{
    return Stack.top == MAXSIZE - 1;
}

int isEmpty()//������� ������ �������.
{
    return Stack.top == -1;
}

void printStack(){//��������� ��������� �������.
 if(!isEmpty()){
     int temp = pop();
     printStack();
     printf("%d\n", temp);
     push(temp);
    }
}

void push(int item)//��������� ��� ����� ��� ��������� �������� ���� top ���� ��� �������.
{
    if (isFull(Stack))
        return;
    Stack.array[++Stack.top] = item;

}

int pop()//��������� ��������� ��� ���������� ��������� ��� �������
{
    if (isEmpty())
        return ;
    return Stack.array[Stack.top--];
}

int main()
{
    initialize();
    push(1);
    push(2);
    push(2);
    push(3);
    push(4);
    insertAtBottom(5);
    printf("Original Stack\n");
    printStack();
    reverse();
    printf("\nReversed Stack\n");
    printStack();
    clear(2);
    clear(3);
    printf("\nCleared Stack\n");
    printStack();
    return 0;
}
