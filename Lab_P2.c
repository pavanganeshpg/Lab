#include <stdio.h>
#include <stdbool.h>

struct Interval
{
    int start, end;
};
int compareInterval(const void *a, const void *b)
{
    return ((struct Interval *)a)->start - ((struct Interval *)b)->start;
}
void Merge(struct Interval arr[], int n)
{
    if (n <= 0)
        return;

    qsort(arr, n, sizeof(struct Interval), compareInterval);
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        // If current interval overlaps with the previous, merge them
        if (arr[idx].end >= arr[i].start)
        {
            if (arr[idx].end < arr[i].end)
                arr[idx].end = arr[i].end;
        }
        else
        {
            idx++;
            arr[idx] = arr[i];
        }
    }
    printf("The Merged Intervals are: ");
    for (int i = 0; i <= idx; i++)
    {
        printf("[%d,%d]", arr[i].start, arr[i].end);
        if (i < idx)
            printf(" ");
    }
    printf("\n");
}
int main()
{
    struct Interval intervals[] = {{2, 3}, {1, 4}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    Merge(intervals, n);
    return 0;
}