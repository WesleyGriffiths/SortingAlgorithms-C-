/*Wesley Griffiths
Takes coordinates and determines their distance from a
"home" coordinate and organizes them. Also checks if
coordinates are in the struct array
Utilizes merge sort, binary sort, and insertion sort*/

#include <stdio.h>
#include <stdlib.h>
//#include "leak_detector_c.h"
FILE *inFile, *outFile;
int  X, Y;
struct coord{
int x;
int y;
};

struct coord* ReadData(int n){
    int i;
    struct coord *temp = (struct coord*)malloc(sizeof(struct coord) * n);
    for (i = 0; i<n; i++){
        fscanf(inFile, "%d %d", &temp[i].x, &temp[i].y);
       // printf("%d %d\n", temp[i].x, temp[i].y);
    }
return temp;


}


int sqrt(int val){

int counter = 1, sqroot=1;

while (sqroot <= val)
{
counter++;
sqroot = counter*counter;
}

return counter -1;
}


int compareTo(struct coord one, struct coord two){
    if (one.x == two.x && one.y == two.y)
            return 0;
int sqrt1, sqrt2, val;
val = (one.x * one.x) + (one.y * one.y);
sqrt1 = sqrt(val);
val = (two.x * two.x) + (two.y * two.y);
sqrt2 = sqrt(val);

if(sqrt1 < sqrt2)
    return -1;
if(sqrt1 > sqrt2)
    return 1;

    if(one.x < two.x)
        return -1;
        if(one.x > two.x)
            return 1;
    if(one.y < two.y)
        return -1;
        if (one.y > two.y)
            return 1;

    }


void merge(struct coord *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    struct coord  *L = (struct coord*) malloc(n1*sizeof(struct coord));
    struct coord  *R = (struct coord*) malloc(n2*sizeof(struct coord));

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (compareTo(L[i], R[j]) == -1)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(struct coord *arr, int l, int r, int t)
{

    if (l<r)
    {
        if (r - l <= t)
            InsertionSort(arr, l, r);
        else{
        // get the mid point
        int m = (l+r)/2;

        // Sort first and second halves
        mergeSort(arr, l, m, t);
        mergeSort(arr, m+1, r, t);

       // printf("Testing l=%d r=%d m=%d\n", l, r, m);

        merge(arr, l, m, r);
        }
    }

    else{

    }
}
void InsertionSort(struct coord* arr, int l, int r)
{
    int i,  j, value;
    struct coord item;// = (struct coord*)malloc(sizeof(struct coord)*1);

   for(i=l; i<= r; i++){
    item = arr[i];
    j = i;
    while((j>=1) && (compareTo(arr[j-1], item) == 1)){
        arr[j] = arr[j-1];
        j--;
    }
    arr[j] = item;
   }

}
void find(struct coord *search, struct coord *array, int n,int l){
int i, f;
for(i=0; i<n;i++){
      f = BinarySearch(array, search[i], l);
if(f == -1){
    printf("%d %d not found\n", search[i].x, search[i].y);
     fprintf(outFile,"%d %d not found\n", search[i].x, search[i].y);
}
else{
    printf("%d %d found at rank %d\n", search[i].x, search[i].y, f + 1);
     fprintf(outFile,"%d %d found at rank %d\n", search[i].x, search[i].y, f + 1);
}

}
}
int BinarySearch(struct coord *array, struct coord item, int len)
{
    int l = 0, h = len - 1;
    int mid, comp;
    while (l <= h)
    {
        mid = (l + h) / 2;
        // Check if item is present at mid
        comp = compareTo( array[mid], item);
        if (comp == 0){
                if(array[mid].x == item.x && array[mid].y == item.y)
            return mid;
        }
         // If item greater, ignore left half
        if (comp == -1)
            l = mid + 1;

        // If item is smaller, ignore right half
        else
            h = mid - 1;
    }
    // if we reach here, then element was
    // not present
    return -1;
}




main(){
int shops, searches, thres;
//atexit(report_mem_leak);

  inFile = fopen("in.txt", "r");
    outFile = fopen("out.txt", "w");
    fscanf(inFile, "%d %d %d %d %d", &X, &Y, &shops, &searches, &thres);
    struct coord *location = ReadData(shops);
    mergeSort(location, 0, shops - 1, thres);

    int i;
    for(i = 0; i<shops; i++){
        printf("%d %d\n", location[i].x, location[i].y);
        fprintf(outFile,"%d %d\n", location[i].x, location[i].y);
    }




    struct coord *search = ReadData(searches);


    find(search, location, searches, shops);

    free(location);
    free(search);

}
