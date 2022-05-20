//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct Prod //���� ������.
{
    int id;
    char man[30];
    char desc[80];
    float price;
    int stock;
    struct Prod *next;
    struct Prod *prev;
} Prod;

Prod *head=NULL; //Global ���������� � head ��� � tail.
Prod *tail=NULL;

void addLast(int id,char man[],char desc[],float price,int stock)//��������� ��� ��������� ����� ��� ����� ��� ������ ���.
{
    Prod *current, *new_node; //���������� ��� ���������� ������
    new_node=malloc(sizeof(Prod));//�������� ������ ��� ��� ��� �����
    new_node->next=NULL; //������������ ��� ������ ���.
    new_node->prev=NULL;
    new_node->id=id;
    strcpy(new_node->man,man);//strcpy ��� �� ������ ��� ������ ���������� �� string.
    strcpy(new_node->desc,desc);
    new_node->price=price;
    new_node->stock=stock;
    if(head==NULL) //�� ����� ����� � ����� ���.
    {
        head=tail=new_node;
        new_node->next=NULL;
        new_node->prev=NULL;
        return;
    }
    else
    {
        current=head; //���������� ������
        while(current!=NULL) //��� ������� �������� ������
        {
            if(new_node->id==current->id)//�� ������ ������ �� ���� id �� ������� ������ ��� ������ ���.
            {
                printf("\nCANNOT ADD PRODUCT WITH ID %d. ALREADY EXIST TO A PRODUCT..\n",id);
                return;
            }
            current=current->next;
        }
    }
    tail->next=new_node; //���������� ������ � ����������.
    new_node->prev=tail;//�� ����������� ��� ��� ����� �����������.
    tail=new_node;
    tail->next=NULL;//��� � next ��� ���������� ������� �� Null.
}

void displayy()//��������� ��� ��������� ��� ����� ���.
{
    Prod *current;//���������� ������.
    current=head;
    if(head==NULL)//�� �����.
        {
            printf("\nLIST IS EMPTY..\n");
            return;
        }
    printf("\n[ ");
    while(current!= NULL)//��� ������� ��������.
    {
        printf("(%d,%s,%s,%.2f,%d) ",current->id,current->man,current->desc,current->price,current->stock);//�������� ��� ��������� ��� �����
        current = current->next;
    }

    printf(" ]\n");
}

void searchP(int x)//��������� ��� ������� ����� �� id=x ��� �� ��� ���� ��� ����� ���� ����� ��� ������.
{
    Prod *current;//���������� ������.
    current=head;
    if(head==NULL)
        {
            printf("\nLIST IS EMPTY..\n");
            return;
        }
    while(current!=NULL)
    {
        if(current->id==x)//�� ������ ������ �� id=x
        {
            printf("\nTHE PRODUCT WITH ID: %d IS:\n",x);
            printf("\n(%d,%s,%s,%.2f,%d) \n",current->id,current->man,current->desc,current->price,current->stock);//�������� ��� ��������� ��� ������ ��� �����������.
            if(current->next!=NULL && current->prev!=NULL)//�� ����� ���������� ������(������ ���� ��� ����������� ��� �������.)
            {

                current->prev->next=current->next;//� ������������ ��� ������� ���� ������.
                current->next->prev=current->prev;//� �������� ������� ���� �����������.
                head->prev=current;//� ������������ head ������� ���� current.
                current->prev=NULL;//� current ������� ������ ������.
                current->next=head;
                return;
            }
            else if(current->next==NULL && current->prev!=NULL)//�� ����� � ����������.
            {

                current->prev->next=NULL;//� �������� ��� ������������ ������� �� null.
                head->prev=current;//��� ���� �������� ��� ���� �����.
                tail=current->prev;
                current->prev=NULL;
                current->next=head;
                head=current;

            }
        }
        current=current->next;
    }
}

void deleteE(int x)//��������� ��� ��������� ��� ����� �� id ��� �� �� ������.
{
    Prod *current;
    current=head;
    if(head==NULL)
        {
            printf("\nLIST IS EMPTY..\n");
            return;
        }

    while(current!=NULL)//��� ������� �������� ������.
    {
        if(current->id==x)//�� ������� ������ �� id ��� �� �� ������.
        {
            if(current->next==NULL)//�� ����� � ���������� ������.
                current->prev->next=NULL;//� next ��� ������������ ��� ������� �� null.
            else if(current->prev==NULL)//�� ����� � ������ ������.
                {
                    head=current->next;//� head ������� ���� ������� ���.
                    current->next->prev=NULL;//� ������������ ������� �� null.
                }
            else//�� ����� ��������� ���� �����.
            {
                current->prev->next=current->next;//� ������������ ������� ���� �������.
                current->next->prev=current->prev;//� �������� ������� ���� �����������.
            }
            free(current);//������������ ������.
        }
        current=current->next;
    }

}

void countNodes()//��������� ��� ������� ����� ������ �������� ���� ����� ���.
{
    Prod *current;//���������� ������.
    current=head;
    int i=0;//Counter.
    if(head==NULL)//�� �����.
        return;
    while(current!= NULL)//��� ������� ��������.
    {
        i++;//������ ��� ������� ��� ���� ���.
        current = current->next;
    }
    printf("\nLIST HAS %d NODES\n",i);//�������� ��� counter.

}

int main()//����� ����������..
{
    addLast(456,"RAZER","MOUSEPAD",25.99,20);
    addLast(486,"LOGITECH","PRINTER",129.99,13);
    displayy();
    addLast(456,"RAZER","MOUSEPAD",25.99,20);
    addLast(487,"MOTOSPEED","KEYBOARD",87.99,12);
    deleteE(486);
    searchP(456);
    addLast(459,"LG","MONITOR",359.69,8);
    displayy();
    searchP(457);
    addLast(500,"SONY","WEB-CAMERA",60.49,9);
    displayy();
    countNodes();
    free(head);//����������� ������.
    free(tail);
    return 0;

}
