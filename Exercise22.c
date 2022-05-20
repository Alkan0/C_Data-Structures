//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct Prod //Δομή κόμβου.
{
    int id;
    char man[30];
    char desc[80];
    float price;
    int stock;
    struct Prod *next;
    struct Prod *prev;
} Prod;

Prod *head=NULL; //Global μεταβλητές ο head και ο tail.
Prod *tail=NULL;

void addLast(int id,char man[],char desc[],float price,int stock)//Συνάρτηση που προσθέτει κόμβο στο τέλος της λίστας μου.
{
    Prod *current, *new_node; //Βοηθητικός και καινούριος κόμβος
    new_node=malloc(sizeof(Prod));//Δέσμευση μνήμης για τον νέο κόμβο
    new_node->next=NULL; //Αρχικοποίηση του κόμβου μου.
    new_node->prev=NULL;
    new_node->id=id;
    strcpy(new_node->man,man);//strcpy για να περάσω τον πίνακα χαρακτήρων σε string.
    strcpy(new_node->desc,desc);
    new_node->price=price;
    new_node->stock=stock;
    if(head==NULL) //Αν είναι άδεια η λίστα μου.
    {
        head=tail=new_node;
        new_node->next=NULL;
        new_node->prev=NULL;
        return;
    }
    else
    {
        current=head; //Βοηθητικός κόμβος
        while(current!=NULL) //Όσο υπάρχει επόμενος κόμβος
        {
            if(new_node->id==current->id)//Αν βρεθεί κόμβος με ίδιο id με κάποιου κόμβου της λίστας μου.
            {
                printf("\nCANNOT ADD PRODUCT WITH ID %d. ALREADY EXIST TO A PRODUCT..\n",id);
                return;
            }
            current=current->next;
        }
    }
    tail->next=new_node; //Τελευταίος κόμβος ο καινούριος.
    new_node->prev=tail;//Με προηγούμυνό του τον πρώην προηγούμενο.
    tail=new_node;
    tail->next=NULL;//Και ο next του τελευταίου δείχνει σε Null.
}

void displayy()//Συνάρτηση που εμφανίζει την λίστα μου.
{
    Prod *current;//Βοηθητικός κόμβος.
    current=head;
    if(head==NULL)//Αν άδεια.
        {
            printf("\nLIST IS EMPTY..\n");
            return;
        }
    printf("\n[ ");
    while(current!= NULL)//Όσο υπάρχει επόμενος.
    {
        printf("(%d,%s,%s,%.2f,%d) ",current->id,current->man,current->desc,current->price,current->stock);//Εμφάνιση των στοιχείων του κόμου
        current = current->next;
    }

    printf(" ]\n");
}

void searchP(int x)//Συνάρτηση που αναζητά κόμβο με id=x και αν τον βρει τον βάζει στην αρχλη της λίστας.
{
    Prod *current;//Βοηθητικός κόμβος.
    current=head;
    if(head==NULL)
        {
            printf("\nLIST IS EMPTY..\n");
            return;
        }
    while(current!=NULL)
    {
        if(current->id==x)//Αν βρεθεί κόμβος με id=x
        {
            printf("\nTHE PRODUCT WITH ID: %d IS:\n",x);
            printf("\n(%d,%s,%s,%.2f,%d) \n",current->id,current->man,current->desc,current->price,current->stock);//Εμφάνιση των στοιχείων του κόμβου που αναζητήθηκε.
            if(current->next!=NULL && current->prev!=NULL)//Αν είναι ενδιάμεσος κόμβος(δηλαδή έχει και προηγούμενο και επόμενο.)
            {

                current->prev->next=current->next;//Ο προηγούμενός του δείχνει στον επόμεν.
                current->next->prev=current->prev;//Ο επόμενος δείχνει στον προηγούμενο.
                head->prev=current;//Ο προηγούμενος head δείχνει στον current.
                current->prev=NULL;//Ο current γίνεται πρώτος κόμβος.
                current->next=head;
                return;
            }
            else if(current->next==NULL && current->prev!=NULL)//Αν είναι ο τελευταίος.
            {

                current->prev->next=NULL;//Ο επόμενος του προηγούμενου δείχνει σε null.
                head->prev=current;//Και όπως παραπάνω τον κάνω πρώτο.
                tail=current->prev;
                current->prev=NULL;
                current->next=head;
                head=current;

            }
        }
        current=current->next;
    }
}

void deleteE(int x)//Συνάρτηση που διαγράφει τον κόμβο με id ίσο με το όρισμα.
{
    Prod *current;
    current=head;
    if(head==NULL)
        {
            printf("\nLIST IS EMPTY..\n");
            return;
        }

    while(current!=NULL)//Όσο υπάρχει επόμενος κόμβος.
    {
        if(current->id==x)//Αν υπάρχει κόμβος με id ίσο με το όρισμα.
        {
            if(current->next==NULL)//Αν είναι ο τελευταίος κόμβος.
                current->prev->next=NULL;//Ο next του προηγούμενού του δείχνει σε null.
            else if(current->prev==NULL)//Αν είναι ο πρώτος κόμβος.
                {
                    head=current->next;//Ο head δείχνει στον επόμενό του.
                    current->next->prev=NULL;//Ο προηγούμενος δείχνει σε null.
                }
            else//Αν είναι ενδιάμεσα στην λίστα.
            {
                current->prev->next=current->next;//Ο προηγούμενος δείχνει στον επόμενο.
                current->next->prev=current->prev;//Ο επόμενος δείχνει στον προηγούμενο.
            }
            free(current);//Απελευθέρωση μνήμης.
        }
        current=current->next;
    }

}

void countNodes()//Συνάρτηση που μετράει πόσοι κόμβοι υπάρχουν στην λίστα μου.
{
    Prod *current;//Βοηθητικός κόμβος.
    current=head;
    int i=0;//Counter.
    if(head==NULL)//Αν άδεια.
        return;
    while(current!= NULL)//Όσο υπάρχει επόμενος.
    {
        i++;//Αύξηση του μετρητή μου κατά ένα.
        current = current->next;
    }
    printf("\nLIST HAS %d NODES\n",i);//Εμφάνιση του counter.

}

int main()//Κλήση συαρτήσεων..
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
    free(head);//Αποδέσμευση μνήμης.
    free(tail);
    return 0;

}
