#include "stdio.h"
#include "stdlib.h"
#include "time.h"


double bubblesorttime(int arr[] ,int n);
double sst(int arry[],int n);
double inss(int arry[],int n);
double shellsot(int arry[],int n);
double heapsort(int arry[],int n);
void swap(int* a, int* b);
void heapify(int arr[], int n, int i);
void merge(int arr[], int p, int q, int r,int n);
double mergeSort(int arr[], int l, int r,int n);
int partition(int array[], int low, int high);
double quickSort(int array[], int low, int high);
int main ()
{
    int n = 100;
    int n1 =10000;
     int arry[n];
     int arry1[n1];
 for ( int i = 0; i < n ; i ++)
   {
       arry[i] = rand() % n;
      //printf("%d, ",arry[i]);
   }
   for ( int i = 0; i < n1 ; i ++)
   {
       arry1[i] = rand() % n1;
      //printf("%d, ",arry[i]);
   }
double bbt = bubblesorttime(arry,n);
double bbt1 = bubblesorttime(arry1,n1);
double ss = sst(arry,n);
double ss1 = sst(arry1,n1);
double inst = inss(arry,n);
double inst1 = inss(arry1,n1);
double shellsott = shellsot(arry,n);
double  shellsott1 = shellsot(arry1,n1);
double heapsot = heapsort(arry,n);
double  heapsot1 = heapsort(arry1,n1);
double mt = mergeSort(arry, 0, n- 1,n);
double mt1 = mergeSort(arry1, 0, n1 - 1,n1);
double qt =  quickSort(arry, 0, n - 1);
double qt1 =  quickSort(arry1, 0, n1 - 1);






    printf("\n\n\n\n");
    printf("Algorithm           \tn = 100 \t\t n = 10000");
    printf("\n**********************************************************");
    printf("\nBubble sort      \t%f  \t\t %f",bbt,bbt1);
    printf("\nSelection sort   \t%f  \t\t %f",ss,ss1);
    printf("\nInsertion sort   \t%f  \t\t %f",inst,inst1);
    printf("\nMerge sort       \t%f  \t\t %f",mt,mt1);
    printf("\nQuick sort       \t%f  \t\t %f",qt,qt1);
    printf("\nShell sort       \t%f  \t\t %f",shellsott,shellsott1);
    printf("\nHeap sort        \t%f  \t\t %f",heapsot,heapsot1);
     printf("\n\n\n\n");
}
 double bubblesorttime(int arr[],int n)
    {
   int temp,i,unsot[n];
   for(int i = 0 ; i < n ; i++)
   {
   unsot[i] = arr[i];
   }
    double bbs_stime , bbs_etime, bbs_dur;
   bbs_stime = clock();
    for (i = 0; i < n - 1 ; i ++)
   {
       for (int j = 0; j < n - i -1 ; j ++)
        {
            if(unsot[j] > unsot[j + 1])
            {
                temp = unsot[j];
                unsot[j] = unsot[j + 1];
                unsot[j + 1] = temp;
            }
        }
   }
   bbs_etime = clock();
   bbs_dur = (double)(bbs_etime - bbs_stime)/CLOCKS_PER_SEC;
    printf("\n");
 /*for (int i = 0; i <  n; i ++)
   {
      printf("%d ,",unsot[i]);
   } */
   return bbs_dur;
}


double sst(int arry[],int n)
    {
    int unsot[n];
    int temp;
     for(int i = 0 ; i < n ; i++)
   {
   unsot[i] = arry[i];
   }
       double ss_stime , ss_etime, ss_dur;
  ss_stime = clock();
    for(int i = 0; i < n -1; i++)
    {
        int iMin = i;
        for(int j = i + 1 ; j < n ; j++)
        {
            if(unsot[j] < unsot[iMin])
            {iMin = j;};
            if(iMin != i)
            {
                temp = unsot[i];
               unsot[i] = unsot[iMin];
                unsot[iMin] = temp;
            }
        }

    }
    ss_etime = clock();
    ss_dur = (double)(ss_etime -ss_stime)/CLOCKS_PER_SEC;
   /* printf("\n");
     printf("%d",ss_dur);
      for(int i = 0; i <n ;i++)
    {

        printf("%d\t",unsot[i]);
    }*/
    return ss_dur;
    }
    double inss(int arry[],int n)
    {

    int unsot[n];
    int temp;
     for(int i = 0 ; i < n ; i++)
   {
   unsot[i] = arry[i];
   }
    double inss_stime , inss_etime, inss_dur;
    inss_stime = clock();
    for(int i = 1; i < n ;i++)
    {
        int j = i;
        while (j > 0 && unsot[j-1]>unsot[j])
        {
            temp = unsot[j-1];
            unsot[ j - 1]= unsot[ j];
            unsot[j]=temp;
            j--;
        }
    }
    inss_etime = clock();
    inss_dur = (double)(inss_etime - inss_stime)/CLOCKS_PER_SEC;

    /*  for(int i = 0; i <n ;i++)
    {

        printf("%d\t",unsot[i]);
    }*/
    return inss_dur;
    }
    double shellsot(int arry[],int n)
    {
    int unsot[n];
    int temp,i,j,k;
     for(int i = 0 ; i < n ; i++)
   {
   unsot[i] = arry[i];
   }
    double shells_stime , shells_etime,shells_dur;
    shells_stime = clock();
    for(i =n/2;i>0;i = i/=2)
    {
        for(j = i; j < n; j++)
        {
            for(k =j-i;k >= 0; k = k - i)
            {
               if(unsot[k+i] >= unsot[k])
                break;
               else{
                temp = unsot[k];
                unsot[k] = unsot[k + i];
                unsot[k+i] = temp;
               }
            }
        }
    }


    shells_etime = clock();
    shells_dur = (double)(shells_etime - shells_stime)/CLOCKS_PER_SEC;
    printf("\n");

    /*  for(int i = 0; i <n ;i++)
    {

        printf("%d\t",unsot[i]);
    }*/
    return shells_dur;
    }
    void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int left, right, largest;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;


    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}



double heapsort(int arry[],int n){
int unsot[n];

     for(int i = 0 ; i < n ; i++)
   {
   unsot[i] = arry[i];
   }
    double hep_stime , hep_etime,hep_dur;
    hep_stime = clock();
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
        heapify(unsot, n, i);

    for (i = n - 1; i >= 0; i--) {
        swap(&unsot[0], &unsot[i]);
        heapify(unsot, i, 0);
    }


    hep_etime = clock();
    hep_dur = (double)(hep_etime - hep_stime)/CLOCKS_PER_SEC;
    printf("\n");

     /* for(int i = 0; i <n ;i++)
    {

        printf("%d\t",unsot[i]);
    }*/
    return hep_dur;
    }
 void merge(int arr[], int p, int q, int r,int n) {
    int unsot[n];
    for(int i = 0 ; i < n ;i++)
  {
       unsot[i] = arr[i];

  }

  // Create L ¡û A[p..q] and M ¡û A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = unsot[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = unsot[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      unsot[k] = L[i];
      i++;
    } else {
      unsot[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    unsot[k] = M[j];
    j++;
    k++;
  }
}
double mergeSort(int arr[], int l, int r,int n) {
    double merg_stime , merg_etime,merg_dur;
   merg_stime = clock();
  if (l < r)
    {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m,n);
    mergeSort(arr, m + 1, r,n);

    // Merge the sorted subarrays
    merge(arr, l, m, r,n);
  }
  merg_etime = clock();
   merg_dur = (double)(merg_etime - merg_stime)/CLOCKS_PER_SEC;
  return merg_dur;
}
int partition(int array[], int low, int high) {


  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}
double quickSort(int array[], int low, int high) {
          double quick_stime , quick_etime,quick_dur;
   quick_stime = clock();
  if (low < high) {



    int pi = partition(array, low, high);


    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
   quick_etime = clock();
    quick_dur = (double)(quick_etime - quick_stime)/CLOCKS_PER_SEC;
    return quick_dur;
}




