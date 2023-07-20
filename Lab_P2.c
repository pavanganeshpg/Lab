# include<stdio.h>
# include<stdbool.h>

typedef struct Interval{
    int start, end;
}Interval;
int compareInterval(const void* a, const void* b)
{
    return ((Interval*)a)->start - ((Interval*)b)->start;
}
void Merge(Interval arr[], int n)
{
   if(n <= 0)
     return;

   qsort(arr, n, sizeof(Interval), compareInterval);
   int idx = 0;
   for(int i =1; i<n; i++){
    if (arr[idx].end >= arr[idx].start){
        if (arr[idx].end < arr[i].end)
           arr[idx].end = arr[i].end;
    }
    else{
        idx++;
        arr[idx] = arr[i];
    }
}
printf("The Merged Intervals are:");
for (int i = 0; i<= idx; i++){
    printf("[%d,%d]", arr[i].start, arr[i].end);
}
}
int main()
{
     Interval interval[] = {{2,3}, {1,4}};
    int n = sizeof(interval)/ sizeof(interval[0]);
    Merge(interval, n);
    return 0;
}
