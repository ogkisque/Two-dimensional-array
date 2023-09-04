#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

void read_file (char* arr, const char* file_name, int row, int col);
void print_arr (const char* arr, int row, int col);

const int MAX_ROW = 50;
const int MAX_COL = 50;
const char* FILE_NAME = "file.txt";

int main ()
{
    char arr[MAX_ROW][MAX_COL] = {};

    read_file ((char*) arr, FILE_NAME, MAX_ROW, MAX_COL);
    print_arr ((char*) arr, MAX_ROW, MAX_COL);
}

void print_arr (const char* arr, int row, int col)
{
    assert (arr);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf ("%c", arr[i * col + j]);
    }
}

void read_file (char* arr, const char* file_name, int row, int col)
{
    FILE* file = fopen (file_name, "r");

    int i = 0;
    char str[MAX_COL] = "";
    while (fgets (str, col, file) != NULL && i < row)
    {
        strncpy (arr + i * col + 1, str, col);
        i++;
    }

    fclose (file);
}

