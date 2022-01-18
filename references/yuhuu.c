#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mainBooks
{
    char namaPelanggan[100];
    char namaBuku[100];
    char jenisBuku[100];
    long int qtyBuku;
    long int hargaBuku;
    char tanggalBuku[100]; // ini tuh tadi int
                           // struct date
                           // {
    int day;
    int year;
    int month;
    // };
    long int totalHarga;
    int sizeArr;
} theBooks[5000];
int sizeArr = 0;

void listBook(int index)
{
    int condition = 0, askAdd;
    // char temp[20];

    // if (fptr == NULL)
    // {
    //     printf("Error!");
    //     exit(1);
    // }
    printf("-- PENGINPUTAN DATA BUKU --\n");
    while (condition == 0)
    {
        FILE *fptr;
        fptr = fopen("sales.txt", "r");
        int j;
        printf("Input %d\n", index);
        printf("Nama Pelanggan  : ");
        scanf(" %[^\n]s", &theBooks[index].namaPelanggan);
        // fprintf(fptr, "%[^\n]s", theBooks[index].namaPelanggan);
        printf("Nama Buku       : ");
        scanf(" %[^\n]s", &theBooks[index].namaBuku);
        // fprintf(fptr, "%[^\n]s", theBooks[index].namaBuku);
        printf("Jenis           : ");
        scanf(" %[^\n]s", &theBooks[index].jenisBuku);
        // fprintf(fptr, "%[^\n]s", theBooks[index].jenisBuku);
        printf("QTY             : ");
        scanf("%d", &theBooks[index].qtyBuku);
        // fprintf(fptr, "%d", theBooks[index].qtyBuku);
        printf("Harga           : ");
        scanf("%d", &theBooks[index].hargaBuku);
        // fprintf(fptr, "%d", theBooks[index].hargaBuku);
        printf("Tanggal         : ");
        scanf(" %d %d %d", &theBooks[index].day, &theBooks[index].month, &theBooks[index].year);
        // fprintf(fptr, "%d %d %d", temp);
        // scanf(" %[^\n]s", &theBooks[index].tanggalBuku);
        int totalHarga = theBooks[index].qtyBuku * theBooks[index].hargaBuku;
        // printf("var totHar %d", totalHarga);
        theBooks[index].totalHarga = totalHarga;
        printf("Total Harga     : Rp. %d\n", theBooks[index].totalHarga);
        // index = 0
        index++; // index = 1
        // printf("\n%d\n", index);             // index setelahnya
        // printf("\n%d\n", theBooks->sizeArr); // banyak buku saat ini
        theBooks->sizeArr = index;
        // printf("\n%d\n", theBooks->sizeArr); // banyak buku saat setelah ditambahkan

        printf("=================\n");
        printf("Ingin Menambahkan Buku lagi ?\n");
        getchar();
        scanf(" %d", &askAdd);
        if (askAdd == 1)
        {
            condition = 0;
        }
        else
        {
            condition = 1;
        }
        fclose(fptr);
    }
}

void writeFile()
{
    printf("\nFile Processing Succes\n");
    printf("# %d ", theBooks->sizeArr);
    FILE *fptr;

    fptr = fopen("sales.txt", "a");
    int i;
    for (i = 0; i < theBooks->sizeArr; i++)
    {
        fprintf(fptr, "\t===============\n %d %s %s %s %d %d %d/%d/%d %d\n", theBooks->sizeArr, 
        theBooks[i].namaPelanggan, 
        theBooks[i].namaBuku, 
        theBooks[i].jenisBuku, 
        theBooks[i].qtyBuku, 
        theBooks[i].hargaBuku, 
        theBooks[i].day, 
        theBooks[i].month, 
        theBooks[i].year, 
        theBooks[i].totalHarga);
    }

    fclose(fptr);
}

void readFile()
{
    FILE *fptr;
    if ((fptr = fopen("sales.txt", "r")) == NULL)
    {
        printf("eror openingfile");
        exit(1);
    }
    fread(&theBooks, sizeof(struct mainBooks), 50, fptr);
    fclose(fptr);
}

void printAll(int j)
{
    printf("\n%d ini size sizeArr\n", theBooks->sizeArr); // banyak buku saat ini
    for (j = 0; j < theBooks->sizeArr; j++)
    {
        printf("\n");
        printf("Nama Pelanggan        : %s \n", theBooks[j].namaPelanggan);
        printf("Judul Buku            : %s \n", theBooks[j].namaBuku);
        printf("Jenis Buku            : %s \n", theBooks[j].jenisBuku);
        printf("QTY Buku              : %d \n", theBooks[j].qtyBuku);
        printf("Harga                 : %d \n", theBooks[j].hargaBuku);
        printf("Tanggal Buku          : %s \n", theBooks[j].tanggalBuku);
        printf("Total harga buku      : %d \n", theBooks[j].totalHarga);
    }
}

// ! SORT
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortDate(int arr[], int size) // theBook , theBooks->sizeArr
{
}

void printSort()
{
}

int main()
{
    int menu, j;
    int i = 0;
    // int sizeArr = theBooks->sizeArr;

    while (i == 0)
    {
        printf("-- WELCOME TO PENDATAAN BUKU TOGAMBAK ---\n");
        printf("-- MENU --\n");
        printf(" 1. Pendataan Penjualan Buku\n");
        printf(" 2. Pencetakan Laporan Berdasarkan Tanggal\n");
        printf(" 3. Pencetakan Laporan Berdasarkan Produk Yang Terjual Paling Banyak\n");
        printf(" 4. Keluar\n");
        printf(" || Input Menu : ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            // printf("Hello ini menu 1\n");
            system("cls");
            listBook(theBooks->sizeArr);
            writeFile();
            system("pause");
            system("cls");

            i = 0;
            break;
        case 2:
            system("cls");
            // printAll(j);
            readFile();
            system("pause");
            system("cls");

            i = 0;
            break;
        case 3:
            printf("Hello menu 3\n");
            break;

        case 4:
            i = 1;
            break;
        default:
            printf("\n !Invalid input !!! \n");
            i = 0;
            break;
        }
    }
    printf("-- TERIMA KASIH --");

    return 0;
}