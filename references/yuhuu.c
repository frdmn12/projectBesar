#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mainBooks
{
    char namaPelanggan[100];
    char namaBuku[100];
    char jenisBuku[100];
    int qtyBuku;
    long int hargaBuku;
    char tanggalBuku[100]; // ini tuh tadi int
    int totalHarga;
    int sizeArr;
} theBooks[50];
int sizeArr = 0;

void listBook(int index)
{
    // int sizeArr = 0
    int condition = 0, askAdd;

    printf("-- PENGINPUTAN DATA BUKU --\n");
    while (condition == 0)
    {
        int j;
        printf("Input %d\n", index);
        printf("Nama Pelanggan  : ");
        scanf(" %[^\n]s", &theBooks[index].namaPelanggan);
        printf("Nama Buku  : ");
        scanf(" %[^\n]s", &theBooks[index].namaBuku);
        printf("Jenis  : ");
        scanf(" %[^\n]s", &theBooks[index].jenisBuku);
        printf("QTY  : ");
        scanf("%d", &theBooks[index].qtyBuku);
        printf("Harga  : ");
        scanf("%d", &theBooks[index].hargaBuku);
        printf("Tanggal  : ");
        scanf(" %[^\n]s", &theBooks[index].tanggalBuku);
        index++;
        theBooks->sizeArr += index;

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
    }
}

void printAll()
{
    struct mainBooks theBooks[3] = {
        {"Bayu", "Harry Potter", "Fiksi", 2},
        {"Tyo", "BUMI", "Fiksi", 2},
        {"Roy", "Bumi Manusia", "Fiksi", 4}};
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("\nNo. %d", i);
        printf("\nNama Pelanggan  : %s \n", theBooks[i].namaPelanggan);
        printf("\nJudul Buku      : %s \n", theBooks[i].namaBuku);
        printf("\nJenis Buku      : %s \n", theBooks[i].jenisBuku);
    }
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
            system("pause");
            system("cls");

            i = 0;
            break;
        case 2:
            printf("\n%d ini size sizeArr\n", theBooks->sizeArr);
            for (j = 0; j <= theBooks->sizeArr; j++)
            {
                printf("\nNama Pelanggan  : %s \n", theBooks[j].namaPelanggan);
                printf("\nJudul Buku      : %s \n", theBooks[j].namaBuku);
                printf("\nnJenis Buku      : %s \n", theBooks[j].jenisBuku);
                printf("\nQTY Buku      : %d \n", theBooks[j].qtyBuku);
                printf("\n Harga       : %d \n", theBooks[j].hargaBuku);
                printf("\nTanggal Buku      : %s \n", theBooks[j].tanggalBuku);
            }

            i = 0;
            break;
        case 3:
            printf("Hello menu 3\n");
            break;

        case 4:
            i = 1;
            break;
        default:
            printf("Mohon input sesuai");
            i = 0;
            break;
        }
    }
    printf("-- TERIMA KASIH --");

    return 0;
}