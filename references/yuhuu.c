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
    long int totalHarga;
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
        printf("Nama Buku       : ");
        scanf(" %[^\n]s", &theBooks[index].namaBuku);
        printf("Jenis           : ");
        scanf(" %[^\n]s", &theBooks[index].jenisBuku);
        printf("QTY             : ");
        scanf("%d", &theBooks[index].qtyBuku);
        printf("Harga           : ");
        scanf("%d", &theBooks[index].hargaBuku);
        printf("Tanggal         : ");
        scanf(" %[^\n]s", &theBooks[index].tanggalBuku);
        int totalHarga = theBooks[index].qtyBuku * theBooks[index].hargaBuku;
        printf("var totHar %d", totalHarga);
        theBooks[index].totalHarga = totalHarga;
        printf("Total Harga     : %d", theBooks[index].totalHarga);
        // index = 0
        index++;                                // index = 1
        // printf("\n%d\n", index);             // index setelahnya
        // printf("\n%d\n", theBooks->sizeArr); // banyak buku saat ini
        theBooks->sizeArr = index;
        // printf("\n%d\n", theBooks->sizeArr);    // banyak buku saat setelah ditambahkan

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

void printAll(int j)
{
    printf("\n%d ini size sizeArr\n", theBooks->sizeArr); // banyak buku saat ini
    for (j = 0; j <= theBooks->sizeArr - 1; j++)
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
            system("cls");
            printAll(j);
            system("pause");
            system("cls");

            // printf("\n%d ini size sizeArr\n", theBooks->sizeArr);
            // for (j = 0; j <= theBooks->sizeArr - 1; j++)
            // {
            //     printf("\nNama Pelanggan  : %s \n", theBooks[j].namaPelanggan);
            //     printf("\nJudul Buku      : %s \n", theBooks[j].namaBuku);
            //     printf("\nnJenis Buku      : %s \n", theBooks[j].jenisBuku);
            //     printf("\nQTY Buku      : %d \n", theBooks[j].qtyBuku);
            //     printf("\n Harga       : %d \n", theBooks[j].hargaBuku);
            //     printf("\nTanggal Buku      : %s \n", theBooks[j].tanggalBuku);
            // }

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