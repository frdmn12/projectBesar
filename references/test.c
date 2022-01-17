#include <stdio.h>
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

int main()
{
    struct mainBooks theBooks[5] = {
    {"Bayu", "Harry Potter", "Fiksi", 2},
    {"Tyo", "BUMI", "Fiksi", 2},
    {"Roy", "Bumi Manusia", "Fiksi", 4}
    };

    int result = sizeof theBooks/ sizeof theBooks[0];
    printf("size of this struct %d", result);
    
     return 0;
}