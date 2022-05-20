//ALKINOOS-MICHAIL MICHALOPOULOS-TSESMETZHS ICSD18135
//SWTHRIOS SURMAS ICSD18213
#include <stdio.h>
#include <stdlib.h>


struct Node //Domh komvou.
{
    int data;
    struct Node* next;
};
void initList(struct Node **head)//Sunarthsh pou arxikopoiei thn lista mou.
{
    *head=NULL;
}


int isEmpty(struct Node *head) //Sunarthsh pou tsekarei an h lista mou einai adeia kai epistrefei endeiktikh timh.
{
    if(head==NULL)
        return 1;
    else
        return 0;
}


int listData(struct Node *p) //Sunarthsh pou mou gurnaei ton arithmo tou komvou pou dexetai ws parametro.
{
    return p->data;
}


void addNode(struct Node** head_ref, int new_data) //Sunarthsh pou prosthetei neo komvo sthn lista mou diatirontas ths fthinousa katataksh.
{
    struct Node* current;
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node)); //Desmefsh mnhmhs.
    new_node->data = new_data; //Anathesh timhs.
    if (*head_ref == NULL || (*head_ref)->data <= new_node->data)//An to head deixnei se null h to data ston komvo pou deixnei to head einai mikrotero h iso me thn timh tou kainouriou mou komvou.
    {
        new_node->next = *head_ref; //O kainourios komvos deixnei ston head.
        *head_ref = new_node; //Head einai isos me ton neo komvo.
    }
    else
    {
        current = *head_ref; //Kanw iso ton voithitiko komvo me to head.
        while (current->next != NULL && current->next->data > new_node->data)//Oso uparxei epomenos komvos kai h timh tou epomenou komvou einai megaluterh apo afth tou neou komvou.
        {
            current = current->next; //Sunexizw thn diasxish ths listas mou.
        }
        new_node->next = current->next; //o neos komvos deixnei ston epomeno tou head.
        current->next = new_node; //O epomenos tou head einai o neos komvos.
    }
}


void toString(struct Node *head) //Sunarthsh pou ektipwnei thn lista mou
{
    struct Node *curr;//Voithitikos komvos.
    curr=head; //Isos me ton head
    while(curr!=NULL)//Oso uparxei epomenos komvos.
    {
        printf("%d ",curr->data);//Printarw thn timh
        if(curr->next==NULL)//An den uparxei epomenos komvos
            break; //Stamataw(wste na mhn tupwthei sto telos mono tou komma(,))
        printf(",");
        curr=curr->next;
    }
    return 0;
}


void deleteList(struct Node **head)//Sunarthsh diagrafhs oloklhrhs ths listas pou dexetai ws parametro.
{
    if(isEmpty==1)
        return 0;
    struct Node *ptr;//Voithitikos komvos.
    while(*head!=NULL)//Oso uparxei epomenos komvos
    {
        ptr=*head;//ptr iso me head
        *head=(*head)->next;//head isos me ton epomeno tou
        free(ptr);//Apeleftherwsh ptr.
    }
}


void deleteElement(struct Node** head_ref, int x)
{
    struct Node *temp = *head_ref, *prev;//Voithitikos komvos kai prohgoumenos komvos.
    if (temp != NULL && temp->data == x)//An o komvos temp exei timh ish me to x.
    {
        *head_ref = temp->next; //Allagh tou head ston epomeno tou temp.
        printf("\nList after deleting number %d :\n",x);
        free(temp); //Apeleftherwsh paliou head.
        return;
    }
    while (temp != NULL && temp->data != x)//Oso uparxei epomenos komvos kai h timh tou komvou den einai to x.
    {
        prev = temp; //Prohgoumenos komvos isos me ton trexonta.
        temp = temp->next;//Trexontas komvos isos me ton epomeno tou.
    }
    if (temp == NULL)//An den uparxei epomenos komvos stamataei.
        return;
    prev->next = temp->next;//O epomenos tou prohgoumenou deixnei ston epomeno tou trexonta..
    printf("\nList after deleting number %d :\n",x);
    free(temp); // Apeleftherwsh xwrou.
}


int containsList(int x) //Sunarthsh pou tsekarei an uparxei o arithmos pou dexetai ws parametro sthn lista mou.
{
    if(listData==x)
        return 1;
    else
        return 0;
}


void countList(struct Node *head)//Sunarthsh pou metraei tous komvous.
{
    if(isEmpty==1)//Elegxos an einai adeia h lista mou.
        return 0;
    int i=0;//counter
    struct Node *curr;//Voithitikos komvos.
    curr=head;//pou deixnei ston head.
    while(curr!=NULL)//Oso uparxei epomenos komvos.
    {
        curr=curr->next;
        i++;//Afksanw ton counter
    }
    printf("\nLIST HAS %d NODES..\n",i);//kai ton printarw.
}


void countElement(struct Node *head, int x)//Sunarthsh pou metraei poses fores uparxei enas akeraios sthn lista mou.
{
    if(isEmpty==1)
        return 0;
    int i=0;//couner
    struct Node *curr;
    curr=head;
    while(curr!=NULL)
    {
        if(curr->data==x)//Otan vrethei komvos me timh ish me to x.
            i++;//Afksanetai o counter.
        curr=curr->next;
    }
    printf("\nNUM %d PRESENTED %d TIMES IN LIST..\n",x,i);
}


int getElement(struct Node **head, int j) //Sunarthsh pou dexetai enan akeraio ws thesh kai epistrefei ta dedomena se afthn thn thesh.
{
    if(isEmpty(*head)==1) //Elegxos an einai adeia h lista mou.
        return 0;
    int i=0;//counter.
    struct Node *curr;
    curr=*head;
    while(curr!=NULL) //Oso exei epomeno komvo h lista mou.
    {
        i++;
        if(i==j) //Otan ginei isos o counter me thn timh pou dothike sthn sunarthsh stamataei kai gurnaei thn timh sthn sugkekrimenh thesh.
            printf("\nPosition %d equals to value : %d \n",i,curr->data);
        curr=curr->next;
    }
    return 0;
}


void firstLocationList(struct Node *head, int x)//Sunarthsh pou epistrefei thn prwth emfanish enos akeraiou sthn lista mou.
{
    if(isEmpty==1)
        return 0;
    int i=0;
    struct Node *curr;
    curr=head;
    while(curr!=NULL)
    {
        i++;
        if(curr->data==x)//An ginei ish h timh kapoiou komvou me to x stamatane oi epanalhpseis.
            break;
        curr=curr->next;
    }
    printf("\nFIRST LOCATION OF NUM %d IS AT %d LOCATION..\n",x,i);
}


void lastLocationList(struct Node *head, int x)//Sunarthsh pou epistrefei thn teleftaia thesh tou akeraiou pou dexetai.
{
    if(isEmpty==1)//Elegxos an einai adeia h lista.
        return 0;
    int i=0,a=0;
    struct Node *curr;//Voithitikos komvos isos me head.
    curr=head;
    while(curr!=NULL)//Diasxish..
    {
        i++;
        if(curr->data==x)//An ginei ish h timh tou komvou me to x pou dothike.
        {
            a=i;//a=i opote tha kratithei sto a h teleftaia thesh pou emperiexetai o akeraios x
        }
        curr=curr->next;//Sunexeia diasxishs.
    }
    printf("\nLAST LOCATION OF NUM %d IS AT %d LOCATION..\n",x,a);
}


void removeDuplicates(struct Node *head)//Sunarthsh pou diwxnei ta diplotupa
{
    struct Node * current = head; //Voithitikos komvos.

    struct Node * next_next;//Komvos gia na krataei afton pou prepei na diagrafei.

    if (isEmpty(head)==1) //Elegxos an einai adeia h lista mou.
        return;

    while (current->next != NULL)//Diasxish listas.
    {
        if (current->data == current->next->data)//Sugrkish komvou me ton epomeno tou.
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else
        {
            current = current->next;//Sunexizei mono an den uparksei diagrafh.
        }
    }
    printf("\nAfter removing Duplicates my list is : \n");
    toString(head);
}


int main()
{
    struct Node* head;
    initList(&head);//Arxikopoihsh listas kai klhsh methodwn pou zhtithikan.
    addNode(&head,10);
    addNode(&head,3);
    addNode(&head,5);
    addNode(&head,5);
    addNode(&head,7);
    addNode(&head,8);
    addNode(&head,1);
    addNode(&head,2);
    addNode(&head,4);
    addNode(&head, 9);
    addNode(&head, 9);
    printf("\n Created Linked List\n");
    toString(head);
    printf("\n");
    deleteElement(&head,10);
    toString(head);
    printf("\n");
    getElement(&head,7);
    countElement(head,9);
    firstLocationList(head,9);
    lastLocationList(head,9);
    countList(head);
    removeDuplicates(head);
    deleteList(&head);
    return 0;
}
