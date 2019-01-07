#include "header.h"

//source geeksforgeeks.org/quick-sort
void swap(struct s_art **arts, int i, int j)
{
    struct s_art *tmp;

    tmp = arts[i];
    arts[i] = arts[j];
    arts[j] = tmp;
}

/*
** Takes the last element as pivot, places the pivot element at its correct
** position in sorted array, and places all smaller (smaller than pivot) to left
**of pivot and all greater elements to right of pivot
*/
int partition (struct s_art **arts, int l, int h)
{
    char *pivot;
    int i = l - 1;
    pivot = arts[h]->name;

    for (int j = l; j < h; j++)
    {
        //check if current element is smaller than or equal to pivot, if so
        //swap them
        if (strcmp(arts[j]->name, pivot) <= 0)
        {
            i++;
            swap(arts, i, j);
        }
    }
    swap(arts, i + 1, h);
    return (i + 1);
}

/*
** implement quicksort algorithm
** l -> starting index
** h -> ending index
*/
void quickSort(struct s_art **arts, int l, int h)
{
    int p_index;

    if (l < h)
    {
        p_index = partition(arts, l, h);
        quickSort(arts, l, p_index - 1);
        quickSort(arts, p_index, h);
    }
}

void sortArts(struct s_art **arts)
{
    int i = 0;
    while (arts[i])
        i++;
    return (quickSort(arts, 0, i - 1));
}
