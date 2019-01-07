#include "header.h"
//source: https://www.geeksforgeeks.org/binary-search/

/*
** A recursive binary search function. It returns the location of name
**in given struct is present else it returns -1.
*/
int binarySearch(struct s_art **arts, int l, int h, char *name)
{
    int mid;

    if (l < h)
    {
        mid = l + (h - l) / 2;
        //check if element is present in the middle
        if (strcmp(arts[mid]->name, name) == 0)
            return (arts[mid]->price);
        //if element is smaller than mid, then it must be in the left of struct
        if (strcmp(arts[mid]->name, name) > 0)
            return (binarySearch(arts, l, mid - 1, name));
        //else if the element is bigger than mid, it must be on the right side
        return (binarySearch(arts, mid + 1, h, name));
    }
    return (-1);
}

int searchPrice(struct s_art **arts, int n, char *name)
{
    return (binarySearch(arts, 0, n - 1, name));
}
