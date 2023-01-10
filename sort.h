#ifndef SORT_H
#define SORT_H

#include "stdio.h"
#include "Windows.h"

#define HS_RIGHT(X)  (X*2+1)
#define HS_LEFT(X)   (X*2)

#define ST_SWAP(X,Y) { T c=X; X=Y;Y=c; }

typedef unsigned int ssize;

static ssize heapsize = 0;

template<typename T>
void InsertionSort(T* data,long st,long en){

    if( (st>=en) || (en-st)<=1) { return; }

    T key;
    for(long i(0), j(st+1); j<en; j++){
        key = data[j];
        i=(j-1);
        while( (i>=0) && data[i]>key ){
            data[i+1] = data[i];
            i--;
        }
        data[i+1]=key;
    }
}

template<typename T>
void MaxHeapify(T*data,ssize i){

    ssize largest(i);

    ssize left = HS_LEFT(i);
    ssize right = HS_RIGHT(i);

    if( (left<heapsize) && (data[left]>data[i]) ) {
        largest = left;
    }

    if( (right<heapsize) && (data[right]>data[largest]) ) {
        largest = right;
    }
    if(largest!=i){
        ST_SWAP(data[i],data[largest]);
        MaxHeapify(data,largest);
    }

}


template<typename T>
void HeapSort(T* data,ssize st,ssize en){

    if( (st>=en) || (en-st)<=1) { return; }
    heapsize = en-st;

    ssize i(heapsize/2);

    T* data_= &(data[st]);

    bool exit(i==0);

    while( !exit ){
        MaxHeapify(data_,i);
        if(i==0){ exit=true; }
        else { i--; }
    }

    for(ssize i=(heapsize-1);i>=1;i--){
        ST_SWAP(data_[0],data_[i]);
        heapsize--;
        MaxHeapify(data_,0);
    }
    heapsize = 0;
}

template<typename T>
ssize Partition(T*data, ssize p, ssize r){

    T x = data[r];
    ssize i = p;

    for(ssize j=p; j<r; j++){
        if(data[j]<=x ){
            ST_SWAP(data[i],data[j]);
            i++;
        }
    }
    ST_SWAP(data[i],data[r]);
    return i;
}

template<typename T>
void QuickSortLoop(T* data, ssize p, ssize r){
    if(p<r){
        ssize q = Partition(data,p,r);
        if((q>0) && (p<q-1)){ QuickSortLoop(data,p,q-1); }
        if((r>0) && (q+1<r)){ QuickSortLoop(data,q+1,r); }
    }
}
template<typename T>
void QuickSort(T* data, ssize st, ssize en){
    if( (st>=en) || (en-st)<=1) { return; }
    QuickSortLoop(data,st,en-1);
}

#endif // SORT_H
