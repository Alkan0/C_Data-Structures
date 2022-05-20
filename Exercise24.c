//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define MAXSIZE 25

int num=0; //Global ���������� ��� ��� ����.
int rear=-1;
int front=-1;
int uniqueid=0;

typedef struct Customer{ //���� �������.
    int id;
    float times,timef;
    char fname[15],lname[15];
}Customer;

Customer arr[MAXSIZE]; //������� �������.


void enqueue() //��������� ��� ��������� ���� ���� ������.
{
    Customer insert_cust;
    char temp[30];
    int tmp;
    if (num == MAXSIZE){ //������� �� ������ ����� �������.
       printf("H oura einai gemath.-\n");
       }
    else // ������ ��� ����� ��� ���� ���� ������.
    {
        front = 0;
        printf("Eisagetai to onoma tou pelath\n : ");
        scanf("%s",&temp);
        strcpy(insert_cust.fname,temp);
        printf("Eisagetai to epwnymo tou pelath\n : ");
        scanf("%s",&temp);
        strcpy(insert_cust.lname,temp);
        insert_cust.id=++uniqueid; //�������� id ��� ��� ������
        insert_cust.times=(float)clock(); //������������.
        rear = rear + 1;
        arr[rear] = insert_cust;
        num++;
    }
}

void dequeue() //��������� ��� ������� ��� ����� �� ��� ���� ���� �������������� �� ����� �� �������.
{
    if (front == - 1 || front > rear) //������� �� ����� ����� � ���� .
    {
        printf("H oura einai adeia.\n");
        return ;
    }
    else
    {
        printf("O pelatis me ID: %d efyge\n", arr[front].id); //� ������ ������� ��� �����.
        float start = arr[front].times;
        float end = clock();//����� ������
        double time_used = (double)(end-start)/CLOCKS_PER_SEC; //����� ��� �� �����������  � ��� ��������.
        printf("o pelaths perimene : %.1f defterolepta",time_used);
        num--;
        for(int i=0;i<num;i++) //���������.
        {
            arr[i]=arr[i+1];
        }
        rear= rear-1;
    }
}

void show() //��������� ��������� �������.
{

    if (front == - 1)
        printf("H oura einai adeia.\n");
    else
    {
        printf("Queue: \n");
        for (int i = 0; i <= rear; i++) //�������� ��� ����.
        {
            Customer tmp; //���������� �������.
            tmp = arr[i];
            float start = tmp.times;
            float end = clock();
            double time_used1 = (double)(end-start)/CLOCKS_PER_SEC;
            printf("onoma: %s ", tmp.fname);
            printf("epitheto: %s ", tmp.lname);
            printf("id: %d ",tmp.id);
            printf("Xronos Anamonis: %.1f defterolepta",time_used1);
            printf("\n");
        }
        printf("\n");
    }
}
void plithos() //��������� ��� ��������� �� ������ ��� ������� .
{
    printf("%d pelates einai sthn anamonh\n",num);
}

int main()
{
    int choice;
    while(5) //���������� �����.
    {
        printf("\nMENU\n");
        printf("\n=====\n");
        printf("\n1.Eisodos pelath.\n");
        printf("\n2.Eksodos pelath.\n");
        printf("\n3.Emfanish stoixeiwn pelatwn.\n");
        printf("\n4.Plithos pelatwn.\n");
        printf("\n0.Eksodos.\n");
        printf("Epelekse: ");
        fflush(stdin); //Buggare � while ��'���� ������������� fflush.
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            plithos();
            break;
            case 0:
            exit(0);
            default:
            printf("Epelekse arithmo apo to 0 mexri to 4");
        }
    }
    return 0;
}
