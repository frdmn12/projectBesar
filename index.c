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
    int tanggalBuku;
    int totalHarga;
} theBooks[50];

// Menu 1
void listBook()
{
    int sizeAdd, j, condition;

    printf("-- PENGINPUTAN DATA BUKU --\n");
    printf("Menginput berapa buku ? ");
    scanf("%d", &sizeAdd);
    do
    {
        int j;
        for (j = 0; j <= sizeAdd; j++)
        {
            printf("Input %d",j);
            printf("Nama Pelanggan  : ");
            scanf(" %[^\n]s", &theBooks[j].namaPelanggan);
            printf("Nama Buku  : ");
            scanf(" %[^\n]s", &theBooks[j].namaBuku);
            printf("Jenis  : ");
            scanf(" %[^\n]s", &theBooks[j].jenisBuku);
            printf("QTY  : ");
            scanf("%d", &theBooks[j].qtyBuku);
            printf("Harga  : ");
            scanf("%d", &theBooks[j].hargaBuku);
            printf("Tanggal  : ");
            scanf("%d", &theBooks[j].tanggalBuku);
        }

    } while (condition == 0);

    // printf("NO\t |Pelanggan\t\t |Judul Buku\t\t |Genre\t |Banyak Buku\t |Harga Buku  \n");
    printf(
        // "1.\t %s\t\t  %s\t\t  %s\t  %d\t  %d\n",
        "1.%s |%s |%s |%d |%d\n",
        theBooks[0].namaPelanggan,
        theBooks[0].namaBuku,
        theBooks[0].jenisBuku,
        theBooks[0].qtyBuku,
        theBooks[0].hargaBuku);
    // print
}

//? void printAll (){
// struct mainBooks theBooks[3] = {
//     {"Bayu", "Harry Potter", "Fiksi", 2},
//     {"Tyo", "BUMI", "Fiksi", 2},
//     {"Roy", "Bumi Manusia", "Fiksi", 4}
//     };
// int i;
// for (i = 0; i < 3; i++)
// {
//     printf("\nNo. %d",i );
//     printf("\nNama Pelanggan  : %s \n", theBooks[i].namaPelanggan);
//     printf("\nJudul Buku      : %s \n", theBooks[i].namaBuku);
//     printf("\nJenis Buku      : %s \n", theBooks[i].jenisBuku);
// }
//? }

int main()
{
    int menu;
    int i = 0;

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
            listBook(i);
            system("pause");
            system("cls");

            /* code */
            i = 0;
            break;
        case 2:
            printf("Hello menu 2\n");
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