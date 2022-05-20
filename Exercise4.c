//��������-������ ������������-���������� icsd18135
//������� ������ icsd18213
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int N; //Global �� � ��� �� ��������������� ���� �����������.
double counter;//Counter ��� ��� ����������.

void swap(int *a, int *b) //��������� ������� ����� �� ����� 3�� ���������� ����������.
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_pn(int *pinakas, int N)//��������� ��� ���������� �������� ��� �������.
{
    int i;
    printf("[");
    for(i=0; i<N; i++)
        printf("%d, ",pinakas[i]);
    printf("%d]",pinakas[N-1]);
}

void init(int *pinakas, int lenght)//��������� ��� ��� ������������ ������ �� ������ �� ������� ���
{
    int i;
    srand(time(NULL));
    for(i=0; i<lenght; i++)
    {
        pinakas[i]=rand()%30001;//�������� ������� ����� ��� �� 0 ����� �� 30000.
    }
}

void insertionSort(int *pinax, int N)  //��������� ����������� ����������.
{
    int i,j;
    for(i=1; i<N; i++) //��� ������ � ��� ���� �� ����� ��� � ������� �������.
    {
        for(j=i; j>=1; j--)
        {

            if(pinax[j]>pinax[j-1])
            {
                counter++;
                // �� � ������� ��� ��������� ���� ���� j ����� ����������� ��'��� ������ ��� ������������ �����.
                swap(&pinax[j],&pinax[j-1]); //������ ��� ��� �����.
            }
            else
            {
                counter++;
                break;
            }
        }
    }
}


void Merge(int *pinakas, int low, int high, int mid)//��������� ����������� �����������.
{
    int i=low,j=mid+1,k=0;
    int temp[high-low+1]; //���������� �������.

    while(i<=mid && j<= high)
    {
        if(pinakas[i]>pinakas[j])
        {
            counter++;
            temp[k++]=pinakas[i++];
        }
        else
        {
            temp[k++]=pinakas[j++];
            counter++;
        }
    }
    while(i<=mid)
    {
        temp[k++]=pinakas[i++];
    }

    while(j<=high)
    {
        temp[k++]=pinakas[j++];
    }

    for(i=low; i<=high; i++)
    {

        pinakas[i]=temp[i-low];

    }
    return;
}


void MergeSort(int *pinakas,int low, int high)
{
    int mid;

    if(low<high)
    {
        mid=(low+high)/2;

        MergeSort(pinakas,low,mid);
        MergeSort(pinakas,mid+1,high);

        Merge(pinakas,low,high,mid);
    }

    return;
}


void QuickSort(int *pinakas, int left, int right)
{
    int i = left;
    int j = right; //"������" ��� ��� ����� ��� ������.
    int temp = pinakas[i]; //���������� �������

    if( left < right)
    {
        while(i < j)
        {
            counter++; //����������++
            while(pinakas[j] <= temp && i < j)
            {
                j--;
            }
            pinakas[i] = pinakas[j];

            while(pinakas[i] >= temp && i < j)
            {
                i++;
            }
            pinakas[j] = pinakas[i];
        }
        pinakas[i] = temp;

        QuickSort(pinakas, left, i - 1); //�������� ��� �� ��� ������ ��� ������.
        QuickSort(pinakas, j + 1, right);
    }
}

void heapify(int *pinakas, int n, int i)
{

    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && pinakas[left] < pinakas[smallest])
        smallest = left;

    if (right < n && pinakas[right] < pinakas[smallest])
        smallest = right;


    if (smallest != i)
    {
        counter++;
        swap(&pinakas[i], &pinakas[smallest]);
        heapify(pinakas, n, smallest);
    }
}


void heapSort(int *pinakas, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(pinakas, n, i);


    for (int i = n - 1; i >= 0; i--)
    {
        swap(&pinakas[0], &pinakas[i]);


        heapify(pinakas, i, 0);
    }
}

int main()
{
    int i,z;
    printf("Array's size: ");
    scanf("%d",&N);
    int *pinakas =malloc(N*sizeof(int));
    printf("\n----------MENU----------\n"); //Menu �������� �������.
    printf(" 1.Insertion Sort Algorithm.\n");
    printf(" 2.Merge Sort Algorithm.\n");
    printf(" 3.Quick Sort Algorithm.\n");
    printf(" 4.Heap Sort Algorithm.\n");
    printf("\n Enter your choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
        clock_t begin = clock(); //������ � �������.
        for(z=0; z<30; z++) //30 �����.
        {
            init(pinakas,N); //������������
            print_pn(pinakas,N);
            printf("\n");
            insertionSort(pinakas,N);//����������.
            print_pn(pinakas,N);
            printf("\n");
        }
        clock_t end = clock(); //����� ����������.
        double time_spent = (double)(end-begin)/CLOCKS_PER_SEC; //����� ��� ����� ���������� ������.
        printf("%lf comparisons and %.5f seconds needed.",(counter/30),time_spent); //��������� ������.
        break;
    }
    case 2:
    {
        clock_t begin = clock(); //������ �� ��� 1� �������.
        for(z=0; z<30; z++)
        {
            init(pinakas,N);
            print_pn(pinakas,N);
            printf("\n");
            MergeSort(pinakas,0,N);
            print_pn(pinakas,N);
            printf("\n");
        }
        clock_t end = clock();
        double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("%lf comparisons and %.5f seconds needed.",(counter/30),time_spent);
        break;
    }
    case 3:
    {
        clock_t begin = clock();//������ �� ��� 1� �������.
        for(z=0; z<30; z++)
        {
            init(pinakas,N);
            print_pn(pinakas,N);
            printf("\n");
            QuickSort(pinakas,0,N);
            print_pn(pinakas,N);
            printf("\n");
        }
        clock_t end = clock();
        double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("%lf comparisons and %.5f seconds needed.",(counter/30),time_spent);
        break;
    }
    case 4:
    {
        clock_t begin = clock();//������ �� ��� 1� �������.
        for(z=0; z<30; z++)
        {
            init(pinakas,N);
            print_pn(pinakas,N);
            printf("\n");
            heapSort(pinakas,N);
            print_pn(pinakas,N);
            printf("\n");
        }
        clock_t end = clock();
        double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("%lf comparisons and %.5f seconds needed.",(counter/30),time_spent);
        break;
    }
    }
    free(pinakas);
    return 0;
}
