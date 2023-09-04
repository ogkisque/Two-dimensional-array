#include <stdio.h>
#include <assert.h>
#include <math.h>

void print_arr (const int* arr);
int  getter (const int* arr, int i, int j);
int  setter (int* arr, int i, int j, int value);

int main ()
{
    int arr[] = {3, 4,
                 1,  2,  3,  4,
                 5,  6,  7,  8,
                 9, 10, 11, 12};

    print_arr (arr);
    printf ("\n");

    setter (arr, 1, 2, 99);
    print_arr (arr);
}

void print_arr (const int* arr)
{
    assert (arr);

    for (int i = 0; i < arr[0]; i++)
    {
        for (int j = 0; j < arr[1]; j++)
            printf ("%d ", getter (arr, i, j));
        printf ("\n");
    }
}

int getter (const int* arr, int i, int j)
{
    assert (arr);

    if (i >= arr[0] || j >= arr[1])
        return NAN;

    return arr[i * arr[1] + j + 2];
}

int setter (int* arr, int i, int j, int value)
{
    assert (arr);

    if (i >= arr[0] || j >= arr[1])
        return NAN;

    int tmp = arr[i * arr[1] + j + 2];
    arr[i * arr[1] + j + 2] = value;
    return tmp;
}
