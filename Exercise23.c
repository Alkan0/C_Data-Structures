//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
//Η άσκηση ζητούσε να υλοποιηθεί με δύο στοίβες άλλα βρήκαμε υλοποίηση
//με αναδρομή στις συναρτήσεις που ζητείται η βοηθητική στοίβα.

struct myStack { //Δομή στοίβας.
    int top;
    int array[MAXSIZE];
}Stack;

void initialize() { //Συνάρτηση αρχικοποίησης.
 Stack.top = -1;
}

void insertAtBottom(int item) {//Συνάρτηση που προσθέτει στην τελευταία θέση της στοίβας αναδρομικά.
    if (isEmpty()) {//Στην περίπτωση άδειας στοίβας γίνεται εισαγωγή κατευθείαν.
        push(item);
    } else {
        int top = pop();
        insertAtBottom(item);
        push(top);
    }
}

void reverse() {
    if (!isEmpty()) {//Στην περίπτωση που η στοίβα μας έχει στοιχεία μέσα, περνάμε
        //όλες τις τιμές της στοίβας αναδρομικά στην μεταβλητή top,
        //όταν εκτελείται η reverse αναδρομικά,
        //οι τιμές του top μένουν στην μνήμη.Όταν δεν υπάρχουν άλλα στοιχεία να γίνουν pop
        //η συνάρτηση τρέχει για όλες τις τιμές που είναι αποθηκευμένες
        //στην μνήμη με πρώτο στοιχείο το τελευταίο που αποθηκεύτηκε.
        //Άρα θα εκτελεστεί η insertAtBottom με όλα τα στοιχεία απλά με ανάποδη σειρά.
        int top = pop();
        reverse();
        insertAtBottom(top);
    }
}
void reverseH(int x) {//βοηθητική συνάρτηση reverse
    if (!isEmpty()) {
        int top = pop();
        reverseH(x);
        if(top!=x)
            insertAtBottom(top);
    }
}
void clear(int x)//Συνάρτηση αφαίρεσης όλων των εμφανίσεων μίας τιμής.
{
    reverseH(x);
    reverse();
}

int isFull()//έλεγχος άμα η στοίβα έχει φτάσει στο μέγιστο επιτρεπτό όριο.
{
    return Stack.top == MAXSIZE - 1;
}

int isEmpty()//έλεγχος άδειας στοίβας.
{
    return Stack.top == -1;
}

void printStack(){//συνάρτηση εμφάνισης στοίβας.
 if(!isEmpty()){
     int temp = pop();
     printStack();
     printf("%d\n", temp);
     push(temp);
    }
}

void push(int item)//συνάρτηση που βάζει ένα καινούριο στοιχείο στην top θέση της στοίβας.
{
    if (isFull(Stack))
        return;
    Stack.array[++Stack.top] = item;

}

int pop()//συνάρτηση αφαίρεσης του τελευταίου στοιχείου της στοίβας
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
