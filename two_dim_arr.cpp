#include <stdio.h>

struct Array
{
    int* data;
    size_t row;
    size_t col;
};

void print_arr (const Array* arr);

int main ()
{
    int data_t[] = {1,  2,  3,  4,
                   5,  6,  7,  8,
                   9, 10, 11, 12};
    Array arr;
    arr.row = 3;
    arr.col = 4;
    arr.data = data_t;
    print_arr (&arr);
}

void print_arr (const Array* arr)
{
    for (size_t i = 0; i < arr->row; i++)
    {
        for (size_t j = 0; j < arr->col; j++)
            printf ("%d ", (arr->data)[i * arr->col + j]);
        printf ("\n");
    }
}
