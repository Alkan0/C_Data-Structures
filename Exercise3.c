//ICSD18135 ΜΙΧΑΛΟΠΟΥΛΟΣ-ΤΣΕΣΜΕΤΖΗΣ ΑΛΚΙΝΟΟΣ-ΜΙΧΑΗΛ
//ICSD18213 ΣΥΡΜΑΣ ΣΩΤΗΡΗΣ
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct country
{
    struct country *left;
    struct country *right;
    char name[20];
    int population;
} country; //Δήλωση δομής.

country* insert(country *node,char *name,int ppl) //Συνάρτηση εισαγωγής.
{
    if (node == NULL) //'Ελεγχος αν είναι άδειο το δέντρο.
    {
        country* node = (country*)malloc(sizeof(country)); //Δέσμευση μνήμης και ανάθεση τιμών.
        node->population=ppl;
        strcpy(node->name,name);
        node->left= NULL;
        node->right= NULL;
        return node;
    }

    if (strcmp(node->name,name)>0) //Έλεγχος για το που πρέπει να μπει ο κάθε κόμβος με βάση το Name.
    {
        node->left  = insert(node->left,name,ppl);
    }

    else if (strcmp(node->name,name)<0)
    {
        node->right = insert(node->right,name,ppl);
    }
    else //Απαγορεύονται τα ίδια ονόματα(Άλλωστε δεν υπάρχουν χώρες με ίδιο όνομα)
        return node;
}

void printValues(country *root)//Συνάρτηση εμφάνισης στοιχείων κάθε χώρας.
{
    if (root == NULL)
        return;
    printValues(root->left); //Αναδρομή για το αριστερό παιδί.
    printf("%s ,",root->name);
    printf("%d \n",root->population);
    printValues(root->right);//Αναδρομή για το δεξί παιδί.
}

int calculateNumberOfCountries(country *root)//Συνάρτηση που μετράει πόσες αποθηκευμένες χώρες υπάρχουν στην δομή.
{
    if (root == NULL)
        return;
    return 1 +calculateNumberOfCountries(root->left) +calculateNumberOfCountries(root->right);

}

int findMin(country *root)//Συνάρτηση για την εύρεση του μικρότερου αποθηκευμένου πληθυσμού στην δομή μου.
{
    while(root!=NULL)//Όσο υπάρχει αποθηκευμένη χώρα
    {
    int result = root->population;//Κρατάω τον πληθυσμό του γονέα και των δύο παιδιών.
    int left=findMin(root->left);
    int right=findMin(root->right);
    if(left<result) //Συγκρίνω το πληθυσμό του γονέα με τα παιδιά και γυρνάω τον μικρότερο αριθμό.
        result=left;
    if(right<result)
        result = right;
    return result;
    }
}

int findMax(country *root)
{
    while (root!=NULL)//Το ίδιο με την findMin απλά με βάση τον μεγαλύτερο.
    {
    int result = root->population;
    int left=findMax(root->left);
    int right=findMax(root->right);
    if(left>result)
        result=left;
    if(right>result)
        result = right;
    return result;
    }
}

void search(country *root,char *nme)//Συνάρτηση αναζήτησης πληθυσμού συγκεκριμένης χώρας με βάση το όνομά της.
{
    if(strcmp(root->name,nme)==0) //Όταν βρεθεί η χώρα με το όνομα που ζητήθηκε.
    {
        printf("H xwra me onoma %s exei ",nme);
        printf("%d ",root->population);
        printf("plithismo.\n");
    }
    else if(strcmp(root->name,nme)>0)//¶ν είναι μικρότερο το όνομα, αναδρομή προς την αριστερή πλευρά του δέντρου.
        search(root->left,nme);
    else
        search(root->right,nme);//¶ν είναι μεγαλύτερο το όνομα, αναδρομή προς την δεξιά πλευρά του δέντρου.
}

void deleteCountry(country *root, int orio)//Συνάρτηση διαγραφής όλων των χωρών με πληθυσμό μικρότερου του ορίου που θέτω.
{
    country *current,*parent,*next;//Βοηθητικές μεταβλητές
    int x;
    *current=*root;
    parent=NULL;
    while(current!=NULL)
    {
        if(orio==current->population)
            break;
        else if(orio < current->population)
        {
            parent = current;
            x=1;
            current=current->left;
        }
        else
        {
            parent = current;
            x=2;
            current=current->right;
        }
    }
    if(current==NULL)
        return;
    if(current->left==NULL && current->right==NULL)
    {
        free(current);
        if(parent==NULL)
            root=NULL;
        else
            if(x==1)
                parent->left=NULL;
            else
                parent->right=NULL;
            return;
    }
    else if(current->left!=NULL && current->right==NULL)
    {
        if(parent==NULL)
            root=current->left;
        else
            if(x==1)
                parent->left=current->left;
            else
                parent->right=current->left;
            free(current);
            return;
    }
    else if(current->left==NULL && current->right!=NULL)
    {
        if(parent==NULL)
            root=current->right;
        else
            if(x==1)
            parent->left=current->right;
            else
                parent->right=current->right;
        free(current);
        return;
    }
    else
    {
        x=1;
        next=current->right;
        while(next->left!=NULL)
        {
            parent=next;
            next=next->left;
            x=2;
        }
        current->population=next->population;
        if(x==1)
        {
            current->right=next->right;
            free(next);
        }
        else
        {
            parent->left=next->right;
            free(next);
        }
    }
}

int main()
{
    country *root = NULL;
    FILE *fp; //Για να περάσω από το αρχείο.
    char name[30];
    int popul;
    fp = fopen("countries.dat", "r");
    if (fp == NULL)
    {
        printf("Can't open input file\n");
        return -1;
    }
    while (!feof(fp))
    {
        fscanf(fp,"%s %d",name, &popul);
        root = insert(root,name,popul);
    }

    fclose(fp);

    int choice;
    do//ΜΕΝΟΥ.
    {
        printf("\n-------------------------MENU-------------------------\n\n");
        printf("1.Emfanish twn stoixeiwn twn apothikevmenwn xwrwn.\n\n");
        printf("2.Emfanish plithous xwrwn.\n\n");
        printf("3.Emfanish ths xwras me ton megalutero plithismo.\n\n");
        printf("4.Emfanish ths xwras me ton mikrotero plithismo.\n\n");
        printf("5.Anazhtish plithismou gia kapoia xwra.\n\n");
        printf("6.Diagrafh olwn twn xwrwn me mikrotero plithismo\n  apo to orio pou thes.\n\n");
        printf("0.Eksodos.\n\n");
        printf("-------------------------------------------------------\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            printf("Apothikevmenes xwres kai stoixeia tous:\n");
            printValues(root);

        }
        break;
        case 2:
        {
            printf("Uparxoun %d apothikevmenes xwres.\n",calculateNumberOfCountries(root));
        }
        break;
        case 3:
        {

            printf("H xwra me ton megalutero plithismo exei %d katoikous",findMax(root));

        } break;
        case 4:
        {
            printf("H xwra me ton mikrotero plithismo exei %d katoikous.",findMin(root));

        } break;
        case 5:
        {
            char name[30];
            printf("Country name: \n");
            fflush(stdin);
            gets(name);
            search(root,name);
        }
        break;
        case 6:
        {
            int orio;
            printf("Dwse orio plithismou: ");
            scanf("%d",&orio);
            deleteCountry(root,orio);
        } break;
        default:
            printf("Epilogi : ");
        }
    }
    while(choice!=0);
    free(root);//Αποδέσμευση μνήμης.
    return 0;

}
