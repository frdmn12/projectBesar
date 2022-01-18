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
    struct dateBuku
    {
        int hari, bulan, tahun;
    } date;
    long int totalHarga;
} theBooks[50];
int sizeArr;

void listBook(int index)
{
    int condition = 0, askAdd;
    printf("-- PENGINPUTAN DATA BUKU --\n");
    FILE *fptr;
    fptr = fopen("sales.txt", "a");
    while (condition == 0)
    {
        int j;
        printf("Input %d\n", index + 1);
        printf("Nama Pelanggan  : ");
        scanf(" %[^\n]s", &theBooks[index].namaPelanggan);
        fprintf(fptr, "%s", theBooks[index].namaPelanggan);
        printf("Nama Buku       : ");
        scanf(" %[^\n]s", &theBooks[index].namaBuku);
        fprintf(fptr, " %s", theBooks[index].namaBuku);
        printf("Jenis           : ");
        scanf(" %[^\n]s", &theBooks[index].jenisBuku);
        fprintf(fptr, " %s", theBooks[index].jenisBuku);
        printf("QTY             : ");
        scanf("%d", &theBooks[index].qtyBuku);
        fprintf(fptr, " %d", theBooks[index].qtyBuku);
        printf("Harga           : ");
        scanf("%d", &theBooks[index].hargaBuku);
        fprintf(fptr, " %d", theBooks[index].hargaBuku);
        printf("Tanggal(DD/MM/YYYY)         : ");
        scanf(" %[^\n]s", &theBooks[index].tanggalBuku);
        fprintf(fptr, " %s", theBooks[index].tanggalBuku);
        int totalHarga = theBooks[index].qtyBuku * theBooks[index].hargaBuku;
        // printf("var totHar %d", totalHarga);
        theBooks[index].totalHarga = totalHarga;
        printf("\nTotal Harga     : %d\n", theBooks[index].totalHarga);
        fprintf(fptr, " %d\n", theBooks[index].totalHarga);
        // index = 0
        index++;                   // index = 1
        printf("\n%d\n", index);   // index setelahnya
        printf("\n%d\n", sizeArr); // banyak buku saat ini
        sizeArr = index;
        printf("\n%d\n", sizeArr); // banyak buku saat setelah ditambahkan

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
    fclose(fptr);
}

void jumlahData()
{
    int c;
    int count = 0;
    FILE *fptr;
    fptr = fopen("sales.txt", "r");
    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n')
            count = count + 1;
    fclose(fptr);
    sizeArr = count;
}

void readFile()
{
    FILE *fptr;
    fptr = fopen("sales.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        int no = 0;
        while (fscanf(fptr, "%s %s %s %d %d %d/%d/%d %d\n",
                      &theBooks[no].namaPelanggan,
                      &theBooks[no].namaBuku,
                      &theBooks[no].jenisBuku,
                      &theBooks[no].qtyBuku,
                      &theBooks[no].hargaBuku,
                      &theBooks[no].date.hari,
                      &theBooks[no].date.bulan,
                      &theBooks[no].date.tahun,
                      &theBooks[no].totalHarga) != EOF)
            ;
        {
            no++;
        }
        sizeArr = no;
    }
    fclose(fptr);
}

void printAll(int j)
{
    struct mainBooks temp;
    jumlahData();
    FILE *fp;
    fp = fopen("sales.txt", "r");

    printf("\n%d ini size sizeArr\n", sizeArr); // banyak buku saat ini
    while (fscanf(fp, "%s %s %s %d %d %d/%d/%d %d\n", &theBooks[j].namaPelanggan,
                  &theBooks[j].namaBuku,
                  &theBooks[j].jenisBuku,
                  &theBooks[j].qtyBuku,
                  &theBooks[j].hargaBuku,
                  &theBooks[j].date.hari,
                  &theBooks[j].date.bulan,
                  &theBooks[j].date.tahun,
                  &theBooks[j].totalHarga) != EOF)
    {
        printf("\n");
        printf("Nama Pelanggan        : %s \n", theBooks[j].namaPelanggan);
        printf("Judul Buku            : %s \n", theBooks[j].namaBuku);
        printf("Jenis Buku            : %s \n", theBooks[j].jenisBuku);
        printf("QTY Buku              : %d \n", theBooks[j].qtyBuku);
        printf("Harga                 : %d \n", theBooks[j].hargaBuku);
        printf("Tanggal Buku          : %d/%d/%d \n", theBooks[j].date.hari, theBooks[j].date.bulan, theBooks[j].date.tahun);
        printf("Total harga buku      : %d \n", theBooks[j].totalHarga);
        printf("\t =======================");
    }
    fclose(fp);
}

void sortDate()
{
    struct mainBooks temp;
    readFile();
    int i, j;
    for (i = 0; i < sizeArr; i++)
    {
        for (j = 0; j < sizeArr; j++)
        {
            if (j <= i)
                continue;
            if (theBooks[i].date.tahun == theBooks[j].date.tahun)
            {
                if (theBooks[i].date.bulan == theBooks[j].date.bulan)
                {
                    if (theBooks[i].date.hari == theBooks[j].date.hari)
                    {
                        temp = theBooks[i];
                        theBooks[i] = theBooks[j];
                        theBooks[j] = temp;
                    }
                    else
                    {
                        if (theBooks[i].date.hari > theBooks[j].date.hari)
                        {
                            temp = theBooks[i];
                            theBooks[i] = theBooks[j];
                            theBooks[j] = temp;
                        }
                    }
                }
                else
                {
                    if (theBooks[i].date.bulan > theBooks[j].date.bulan)
                    {
                        temp = theBooks[i];
                        theBooks[i] = theBooks[j];
                        theBooks[j] = temp;
                    }
                }
            }
            else
            {
                if (theBooks[i].date.tahun > theBooks[j].date.tahun)
                {
                    temp = theBooks[i];
                    theBooks[i] = theBooks[j];
                    theBooks[j] = temp;
                }
            }
        }
        if (i > 0)
        {
            if (theBooks[i].date.hari == theBooks[i - 1].date.hari &&
                theBooks[i].date.bulan == theBooks[i - 1].date.bulan &&
                theBooks[i].date.tahun == theBooks[i - 1].date.tahun)
            {
                if (theBooks[i].qtyBuku > theBooks[i - 1].qtyBuku)
                {
                    temp = theBooks[i];
                    theBooks[i] = theBooks[i - 1];
                    theBooks[i - 1] = temp;
                }
            }
        }
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
            jumlahData();
            listBook(sizeArr);
            system("pause");
            system("cls");

            i = 0;
            break;
        case 2:
            system("cls");
            sortDate();  // transasksisesuai_barang;
            printAll(j); // lihat_data
            printf("\n");
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
            printf("Mohon input sesuai");
            i = 0;
            break;
        }
    }
    printf("-- TERIMA KASIH --");

    return 0;
}
