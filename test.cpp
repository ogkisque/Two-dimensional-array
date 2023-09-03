#include <stdio.h>
#include <assert.h>

void print_trian (const int* trian_mass, size_t row, const int indent);
void read_file_trian (int* trian_mass, size_t* row, const char* file_name);

int main ()
{
    const int INDENT = 5;
    const int MAX_LENGTH = 50;
    const char* FILE_NAME = "file.txt";

    size_t row = 0;
    int trian_mass[MAX_LENGTH] = {};

    read_file_trian (trian_mass, &row, FILE_NAME);

    print_trian (trian_mass, row, INDENT);
}

void print_trian (const int* trian_mass, size_t row, const int indent)
{
    assert (trian_mass);

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < i + 1; j++)
            printf ("%*d", indent, * (int*) ((int) trian_mass + ((int) ((1 + i) * i / 2) + j) * sizeof (int)));

        printf ("\n");
    }
}

void read_file_trian (int* trian_mass, size_t* row, const char* file_name)
{
    FILE* file = fopen (file_name, "r");

    assert (file);

    size_t i = 0;
    *row = 0;
    int tmp = 0;
    bool end_file = false;
    for (;;)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if (fscanf (file, "%d", &tmp) != 1)
            {
                end_file = true;
                break;
            }
            trian_mass[(i + 1) * i / 2 + j] = tmp;
        }
        if (end_file)
            break;
        i++;
    }
    *row = i;

    fclose (file);
}
