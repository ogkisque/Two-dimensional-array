#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>

const int   MAX_LEN   = 300;
const int   MAX_ROW   = 300;
const char* FILE_NAME = "file.txt";

int read_arr (char** arr, const char* file_name);
void print_arr (const char** arr, int row);
void free_arr (char** arr, int row);

int main ()
{
    char** arr = (char**) calloc (MAX_ROW, sizeof (char*));

    int row = read_arr (arr, FILE_NAME);
    print_arr ((const char**) arr, row);

    free_arr (arr, row);
}

void print_arr (const char** arr, int row)
{
    assert (arr);

    for (int i = 0; i < row; i++)
    {
        printf ("%s", arr[i]);
    }
}

int read_arr (char** arr, const char* file_name)
{
    FILE* file = fopen (file_name, "r");

    assert (file);

    int i = 0;
    char str[MAX_LEN] = {};
    while (fgets (str, 100, file) != NULL)
    {
        arr[i] = strdup (str);
        i++;
    }

    fclose (file);

    return i;
}

void free_arr (char** arr, int row)
{
    for (int i = 0; i < row; i++)
        free (arr[i]);
    free (arr);
}

