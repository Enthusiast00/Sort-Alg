#include "sort.h"

typedef int ArrayType;
void sorttest(ArrayType * A, unsigned long count){
    for(unsigned long i=0;i< (count-1) ;i++){
        if(A[i]>A[i+1]){ fprintf(stderr,"un sorted: A[%i]:%u ,A[%i]:%u \n",i,A[i],i,A[i+1]); }
    }
}
unsigned long long ticks_;
inline unsigned int TimerStart(){
    QueryPerformanceCounter((LARGE_INTEGER*)&ticks_);
    return (unsigned int)ticks_;
}
inline unsigned int TimerEnd(unsigned int st){
    QueryPerformanceCounter((LARGE_INTEGER*)&ticks_);
    return (unsigned int)(ticks_ - st);
}

int main(){

    //IsertionSort
    printf("IsertionSort \n");

    unsigned int len = 10;
    unsigned int ticks(0);

    ArrayType * A = new int[len];
    for(unsigned int i =0; i<len; i++) { A[i] = rand()%200; }

    printf(" pre sort\n");
    for(unsigned int i = 0; i<len; i++) { printf("A[%i] %i \n",i,A[i]); }

    InsertionSort(A,0,len);

    printf(" post sort\n");
    for(unsigned int i = 0; i<len; i++) { printf("A[%i] %i \n",i,A[i]); }

    delete A;
    len = 1000;
    A = new int[len];
    for(unsigned int i =0; i<len; i++){ A[i] = rand(); }

    ticks=TimerStart();
    InsertionSort(A,0,len);
    ticks=TimerEnd(ticks);

    printf("IsertionSort %u: Randomvalues: %u \n",len,ticks);

    for(unsigned int i =0; i<len; i++){ A[i] = i; }
    ticks = TimerStart();
    InsertionSort(A,0,len);
    ticks = TimerEnd(ticks);
    printf("IsertionSort %u: Sortedvalues: %u \n",len,ticks);

    for(unsigned int ii(0),i =len; ii<len; ii++,i--){ A[ii] = i; }
    ticks = TimerStart();
    InsertionSort(A,0,len);
    ticks = TimerEnd(ticks);
    printf("IsertionSort %u: ReverseSortedvalues: %u \n",len,ticks);



    //HeapSort
    printf("\n\nHeapSort \n");

    delete A;
    len = 10;
    A = new int[len];

    for(unsigned int i =0; i<len; i++) { A[i] = rand()%350; }
    printf("pre sort \n");
    for(unsigned long i = 0; i<len; i++) { printf("A[%i] %i \n",i,A[i]); }
    HeapSort(A,0,len);
    printf("post sort \n");
    for(unsigned long i = 0; i<len; i++) { printf("A[%i] %i \n",i,A[i]); }

    delete A;
    len = 1000000;
    A = new int[len];
    for(unsigned int i =0; i<len; i++){ A[i] = rand(); }

    ticks=TimerStart();
    HeapSort(A,0,len);
    ticks=TimerEnd(ticks);

    printf("HeapSort %u: Randomvalues: %u \n",len,ticks);

    for(unsigned int i =0; i<len; i++){ A[i] = i; }
    ticks = TimerStart();
    HeapSort(A,0,len);
    ticks = TimerEnd(ticks);
    printf("HeapSort %u: Sortedvalues: %u \n",len,ticks);

    for(unsigned int ii(0),i =len; ii<len; ii++,i--){ A[ii] = i; }
    ticks = TimerStart();
    HeapSort(A,0,len);
    ticks = TimerEnd(ticks);
    printf("HeapSort %u: ReverseSortedvalues: %u \n",len,ticks);



    //QuickSort
    printf("\n\nQuickSort \n");

    delete A;
    len = 10;
    A = new int[len];

    for(unsigned int i =0; i<len; i++) { A[i] = rand()%89; }
    printf("pre sort \n");
    for(unsigned long i = 0; i<len; i++) { printf("A[%i] %i \n",i,A[i]); }
    QuickSort(A,0,len);
    printf("post sort \n");
    for(unsigned long i = 0; i<len; i++) { printf("A[%i] %i \n",i,A[i]); }

    delete A;
    len = 1000000;
    A = new int[len];
    for(unsigned int i =0; i<len; i++){ A[i] = rand(); }

    ticks=TimerStart();
    QuickSort(A,0,len);
    ticks=TimerEnd(ticks);

    printf("QuickSort %u: Randomvalues: %u \n",len,ticks);


    delete A;
    len = 10000;
    A = new int[len];// quick sort O(n^2) on sorted arrays

    for(unsigned int i =0; i<len; i++){ A[i] = i; }
    ticks = TimerStart();
    QuickSort(A,0,len);
    ticks = TimerEnd(ticks);
    printf("QuickSort %u: Sortedvalues: %u \n",len,ticks);

    for(unsigned int ii(0),i =len; ii<len; ii++,i--){ A[ii] = i; }
    ticks = TimerStart();
    QuickSort(A,0,len);
    ticks = TimerEnd(ticks);
    printf("QuickSort %u: ReverseSortedvalues: %u \n",len,ticks);

    delete A;

    return 0;
}
