//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define MAXSIZE 25

int num=0; //Global μεταβλητές για την ουρά.
int rear=-1;
int front=-1;
int uniqueid=0;

typedef struct Customer{ //Δομή πελατών.
    int id;
    float times,timef;
    char fname[15],lname[15];
}Customer;

Customer arr[MAXSIZE]; //Πίνακας πελατών.


void enqueue() //Συνάρτηση που προσθέτει στην ουρά πελάτη.
{
    Customer insert_cust;
    char temp[30];
    int tmp;
    if (num == MAXSIZE){ //Έλεγχος αν χωράει άλλος πελάτης.
       printf("H oura einai gemath.-\n");
       }
    else // Περνάω τις τιμές που θέλω στον πελάτη.
    {
        front = 0;
        printf("Eisagetai to onoma tou pelath\n : ");
        scanf("%s",&temp);
        strcpy(insert_cust.fname,temp);
        printf("Eisagetai to epwnymo tou pelath\n : ");
        scanf("%s",&temp);
        strcpy(insert_cust.lname,temp);
        insert_cust.id=++uniqueid; //Μοναδικό id για τον καθένα
        insert_cust.times=(float)clock(); //Χρονομέτρηση.
        rear = rear + 1;
        arr[rear] = insert_cust;
        num++;
    }
}

void dequeue() //Συνάρτηση που αφαιρεί τον πρώτο απ την ουρά αφου εξυπηρετούνται με σειρά οι πελάτες.
{
    if (front == - 1 || front > rear) //Έλεγχος αν είναι άδεια η ουρά .
    {
        printf("H oura einai adeia.\n");
        return ;
    }
    else
    {
        printf("O pelatis me ID: %d efyge\n", arr[front].id); //Ο πρώτος πελάτης της ουράς.
        float start = arr[front].times;
        float end = clock();//Τέλος χρόνου
        double time_used = (double)(end-start)/CLOCKS_PER_SEC; //Πράξη για να υπολογιστεί  η ώρα αναμονής.
        printf("o pelaths perimene : %.1f defterolepta",time_used);
        num--;
        for(int i=0;i<num;i++) //Ολίσθηθση.
        {
            arr[i]=arr[i+1];
        }
        rear= rear-1;
    }
}

void show() //Συνάρτηση εμφάνισης πελατών.
{

    if (front == - 1)
        printf("H oura einai adeia.\n");
    else
    {
        printf("Queue: \n");
        for (int i = 0; i <= rear; i++) //Διατρέχω την ουρά.
        {
            Customer tmp; //Βοηθητικός πελάτης.
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
void plithos() //Συνάρτηση που εμφανίζει το πλήθος των πελατών .
{
    printf("%d pelates einai sthn anamonh\n",num);
}

int main()
{
    int choice;
    while(5) //Δημιουργία μενού.
    {
        printf("\nMENU\n");
        printf("\n=====\n");
        printf("\n1.Eisodos pelath.\n");
        printf("\n2.Eksodos pelath.\n");
        printf("\n3.Emfanish stoixeiwn pelatwn.\n");
        printf("\n4.Plithos pelatwn.\n");
        printf("\n0.Eksodos.\n");
        printf("Epelekse: ");
        fflush(stdin); //Buggare η while γι'αυτό χρησιμοποίησα fflush.
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
