#include <stdio.h>

void arrMenu(int *a, int *b)
{
    int simpan = *a;
    *a = *b;
    *b = simpan;
}

void sort(int array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                arrMenu(&array[j], &array[j + 1]);
}

void printSort(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
}

// Declare variable
struct angka
{
    int angka[100],input;
} a;

int main(int argc, char const *argv[])
{
    FILE *file1,*file2;

    int  max, min;
    double allArr, rata;
    printf("Masukan jumlah nilai yang akan anda masukkan : ");
    // printf("Input angka : ");
    scanf("%d", &a.input);
    for (int i = 0; i < a.input; i++)
    {
        scanf("%d", &a.angka[i]);
        allArr += a.angka[i];
    }
    max = a.angka[0];
    min = a.angka[0];
    for (int i = 0; i < a.input; i++)
    {
        if (a.angka[i] >= max)
        {
            max = a.angka[i];
        }
        else if (a.angka[i] <= min)
        {
            min = a.angka[i];
        }
    }
    rata = allArr / a.input;
    // Find MIN MAX AVG
    printf("---- MIN MAX AVG ----");
    printf("\nNilai Terbesar : %d\n", max);
    printf("Nilai Terkecil : %d\n", min);
    printf("Nilai Rata - Rata : %.1lf\n\n", rata);

    // FIND SORT
    printf("---- SORT ----");
    sort(a.angka, a.input);
    printf("\nNilai Setelah Di Urutkan : \n");
    printSort(a.angka, a.input);

    // FILE PROCESSING
    printf("\n---- FILE PROCESSING ----");
    file1 = fopen("quis.txt", "w");
    file2 = fopen("quisbin.txt", "w");
    printf("\nNilai dibawah ini berhasil dimasukkan pada file quis.txt\n");
    for (int i = 0; i < a.input; i++)
    {
        fprintf(file1, "%d ", a.angka[i]);
        printf("%d ", a.angka[i] );
    }
    fwrite(&a, sizeof(struct angka),1,file2);
    fclose(file2);
    fclose(file1);

    
    return 0;
}
