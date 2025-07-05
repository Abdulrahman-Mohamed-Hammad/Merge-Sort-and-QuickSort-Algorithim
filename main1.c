#include <stdio.h>
#include <stdlib.h>
char c[100];
int QUICKSWAP=0;
int QUICKCOMP=0;
int MERGSWAP=0;
int MERGCOP=0;

void print(int*arr, int size,int x)
{
    if(x==0)
    {
        printf("SORTED LIST :\n");
        printf("%s\n",c);
        for (int i = 0; i < size; i++)

        {
            printf("x=%d\n", arr[i]);
        }
    }
    else
    {
        printf("INVERSELY SORTED LIST :\n");
        printf("%s\n",c);
        for (int i = size; i > -1; i--)
        {
            printf("x=%d\n", arr[i]);
        }
    }
}

int merge(int*arr,int START,int m,int END)
{
    int i,j,k;
    int LEFT =m-START+1;
    int RIGHT = END-m;
    int L[LEFT],R[RIGHT];

    for (i = 0; i < LEFT; i++)
        L[i] = arr[START + i];
    for (j = 0; j < RIGHT; j++)
        R[j] = arr[m + 1 + j];


    i = 0;
    j = 0;
    k = START;
    while (i < LEFT && j < RIGHT)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            MERGSWAP++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            MERGSWAP++;
        }

        MERGCOP++;
        k++;
    }


    while (i < LEFT)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < RIGHT)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
int MERGSORT(int*arr,int START,int END)
{

    if(START<END)
    {
        int m=(END+START)/2;
        MERGSORT(arr,START,m);
        MERGSORT(arr,m+1,END);
        merge(arr,START,m,END);
    }
    else
        return 0;
}
int partition (int*arr, int start, int end)
{

    int pivot = arr[end]; // pivot element
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
    {
        QUICKCOMP++;
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element

            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            QUICKSWAP++;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;
    QUICKSWAP++;
    return (i + 1);

}

void QuickSORT(int*arr,int START, int END)
{



    if(START >= END)
    {
        return;
    }
    int PA=partition(arr,START,END);
    QuickSORT(arr,START,(PA-1));
    QuickSORT(arr,(PA+1),END);

}
void UI(int* arr, int size)
{
    int X,y=0;

    printf("\n1-QUICKSORT :\n2-MERGESORT :\n3-ALL OF THEM :\n\nENTER YOUR CHOOSE : ");
TRYAGAIN:
    scanf("%d", &X);

    if (X == 1)
    {
        strcpy(c,"QUICKSORT");
        QuickSORT(arr, 0, size - 1);
    }

    else if (X == 2)
    {
        strcpy(c,"MERGSORT");
        MERGSORT(arr, 0, size - 1);
    }

    else if (X == 3)
    {
        strcpy(c,"QUICKSORT");
        QuickSORT(arr, 0, size - 1);
        y=1;
        goto print;
merge:
        strcpy(c,"MERGSORT");
        MERGSORT(arr, 0, size - 1);
        y=0;
        goto OUT;
    }
    else
    {
        printf("TRY AGAIN \n NUMBER = %");

    }

print:
OUT:
    printf("\n1-SORT :\n2-INVERSE SORT :\n\nENTER YOUR CHOOSE : ");
    scanf("%d",&X);

    if (X == 1)
    {
        print(arr,size,0);
    }

    else if (X == 2)
    {
        print(arr,size-1,1);
    }

    else
    {
        printf("TRY AGAIN \n NUMBER = %d", X);
    }

    if(y==1)
    {
        goto merge;
    }


}

int main() {
    int size;
    int *arr;

    printf("SIZE OF LIST : ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid input. Please enter a positive integer for size.\n");
        return 1;
    }

    arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("\nELEMENTS OF LIST:\n");
    for (int i = 0; i < size; i++) {
        printf("ELEMENT %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            free(arr);
            return 1;
        }
    }

    UI(arr, size);

    printf("\nQUICKSORT SWAPS : %d", QUICKSWAP);
    printf("\nQUICKSORT COMPARISONS : %d", QUICKCOMP);

    printf("\nMERGESORT SWAPS : %d", MERGSWAP);
    printf("\nMERGESORT COMPARISONS : %d\n", MERGCOP);

    free(arr);

    return 0;
}
