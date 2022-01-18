#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct mainBooks
{
	char namaPelanggan[100];
	char namaBuku[20];
	char jenisBuku[10];
	int qtyBuku;
	int hargaBuku;
	int tanggalBuku;
	int bulanBuku;
	int tahunBuku;
	int totalHarga;
} buku1, buku2, buku3, buku4, buku5;

void listBuku()
{
	int exit1 = 0;
	int pilihan1;
	printf("Silahkan pilih jenis buku yang anda inginkan :\n");
	printf("1. Fiksi\n");
	printf("2. Non-Fiksi\n");
	printf("Masukkan Pilihan Anda : ");
	scanf("%d", &pilihan1);
	switch (pilihan1)
	{
	case 1:
	{
		system("cls");
		int exit2 = 0;
		int pilihan2;
		printf("Silahkan pilih judul buku fiksi yang anda inginkan :\n");
		printf("1. Harry Potter\n");
		printf("2. Negeri 5 Menara\n");
		printf("Masukkan Pilihan Anda : ");	
		scanf("%d", &pilihan2);
		switch (pilihan2)
		{
		case 1:
		{
			system("cls");
			strncpy(buku1.namaBuku, "Harry Potter", 20);
			strncpy(buku1.jenisBuku, "Fiksi", 10);
			buku1.hargaBuku = 250000;
			printf("Nama Pelanggan	: ");
			getchar();
			scanf("%[^\n]s", buku1.namaPelanggan);
			printf("Nama Buku	: %s\n", buku1.namaBuku);
			printf("Jenis Buku 	: %s\n", buku1.jenisBuku);
			printf("Harga		: %d\n", buku1.hargaBuku);
			printf("Tanggal pembelian	: ");
			scanf("%d/%d/%d", &buku1.tanggalBuku, &buku1.bulanBuku, &buku1.tahunBuku);
			printf("Jumlah Pembelian	: ");
			scanf("%d", buku1.qtyBuku);
			buku1.totalHarga = buku1.hargaBuku * buku1.qtyBuku;
			printf("Total harga		: %d\n", buku1.totalHarga);
			system("pause");
			system("cls");
			break;
		}
		}
		break;
	}
	}
}

int main()
{
	int exit = 0;
	int pilihan;
	while (exit == 0)
	{
		printf("=====================================================\n");
		printf("			APLIKASI BOOKSTORE\n");
		printf("=====================================================\n");
		printf("Selamat datang di aplikasi BookStore\n");
		printf("Silahkan pilih menu dibawah ini :\n");
		printf("1. Pendataan Penjualan Buku\n");
		printf("2. Pencetakan Laporan Berdasarkan Tanggal\n");
		printf("3. Pencetakan Laporan Berdasarkan Produk Yang Terjual Paling Banyak\n");
		printf("4. Keluar\n");
		printf("Masukkan Pilihan Anda : ");
		scanf("%d", &pilihan);
		switch (pilihan)
		{
		case 1:
		{
			system("cls");
			listBuku();
			system("pause");
			system("cls");
			break;
		}
		}
	}
	return 0;
}
