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
    char tanggalBuku[100];
    struct dateBuku{
    	int tanggal,bulan,tahun;
	}date;
    long int totalHarga;
} theBooks[50];
   
    int sizeArr;

void listBook(int index)
{
    int condition = 0;
	char askAdd;
    printf("-- PENGINPUTAN DATA BUKU --\n");
    FILE *fptr;
  	fptr=fopen("sales.txt","a");
    while (condition == 0)
    {
        int j;
        printf("Input %d\n", index+1);
        printf("Nama Pelanggan  	: ");
        scanf(" %[^\n]s", &theBooks[index].namaPelanggan);
        fprintf(fptr,"%s",theBooks[index].namaPelanggan);
        printf("Nama Buku      	 	: ");
        scanf(" %[^\n]s", &theBooks[index].namaBuku);
        fprintf(fptr," %s",theBooks[index].namaBuku);
        printf("Jenis         		: ");
        scanf(" %[^\n]s", &theBooks[index].jenisBuku);
        fprintf(fptr, " %s",theBooks[index].jenisBuku);
        printf("QTY            		: ");
        scanf("%d", &theBooks[index].qtyBuku);
        fprintf(fptr," %d",theBooks[index].qtyBuku);
        printf("Harga           	: ");
        scanf("%d", &theBooks[index].hargaBuku);
        fprintf(fptr," %d",theBooks[index].hargaBuku);
        printf("Tanggal(DD/MM/YYYY)     : ");
        scanf("%d/%d/%d", &theBooks[index].date.tanggal,&theBooks[index].date.bulan,&theBooks[index].date.tahun);
        fprintf(fptr, " %d/%d/%d",theBooks[index].date.tanggal,theBooks[index].date.bulan,theBooks[index].date.tahun);
        int totalHarga = theBooks[index].qtyBuku * theBooks[index].hargaBuku;
        // printf("var totHar %d", totalHarga);
        theBooks[index].totalHarga = totalHarga;
        printf("Total Harga    		: %d\n", theBooks[index].totalHarga);
        fprintf(fptr," %d\n",theBooks[index].totalHarga);
        // index = 0
        index++;                             // index = 1
        /*printf("\n%d\n", index);             // index setelahnya
        printf("\n%d\n", sizeArr); // banyak buku saat ini
        sizeArr = index;
        printf("\n%d\n", sizeArr); // banyak buku saat setelah ditambahkan*/
        printf("=================\n");
        printf("Ingin Menambahkan Buku lagi ?(y/n)\n");
        getchar();
        scanf(" %c", &askAdd);
        if (askAdd == 'y')
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

void jumlahData(){
	int c;
	int count=0;
	FILE *fptr;
	fptr=fopen("sales.txt","r");
	for(c = getc(fptr); c != EOF; c = getc(fptr))
	        if (c == '\n')
	            count = count + 1;
	fclose(fptr);
	sizeArr=count;
}

void readData(){
	jumlahData();
	FILE *fptr;
    fptr= fopen("sales.txt","r");
        if(fptr == NULL){
        printf("Error!");
        exit(1);
	        
	}
	else {
		int no;
		for(no=0;no<sizeArr;no++){
			fscanf(fptr,"%s %s %s %d %d %d/%d/%d %d\n",&theBooks[no].namaPelanggan,&theBooks[no].namaBuku,&theBooks[no].jenisBuku,&theBooks[no].qtyBuku,&theBooks[no].hargaBuku,&theBooks[no].date.tanggal,&theBooks[no].date.bulan,&theBooks[no].date.tahun,&theBooks[no].totalHarga);
		}
		
	}
	  fclose(fptr);
}

void printAll(int j){
	FILE *fp;
	fp=fopen("sales.txt","r");
	
    printf("\n%d ini size sizeArr\n", sizeArr); // banyak buku saat ini
    for(j=0;j<sizeArr;j++)
	//while(fscanf(fp,"%s %s %s %d %d %d/%d/%d %d\n",&theBooks[j].namaPelanggan,&theBooks[j].namaBuku,&theBooks[j].jenisBuku,&theBooks[j].qtyBuku,&theBooks[j].hargaBuku,&theBooks[j].date.tanggal,&theBooks[j].date.bulan,&theBooks[j].date.tahun,&theBooks[j].totalHarga)!=EOF)
    {
        printf("\n");
        printf("Nama Pelanggan        : %s \n", theBooks[j].namaPelanggan);
        printf("Judul Buku            : %s \n", theBooks[j].namaBuku);
        printf("Jenis Buku            : %s \n", theBooks[j].jenisBuku);
        printf("QTY Buku              : %d \n", theBooks[j].qtyBuku);
        printf("Harga                 : %d \n", theBooks[j].hargaBuku);
        printf("Tanggal Buku          : %d/%d/%d \n", theBooks[j].date.tanggal,theBooks[j].date.bulan,theBooks[j].date.tahun);
        printf("Total harga buku      : %d \n", theBooks[j].totalHarga);
    }
    fclose(fp);
}
void sortDate(){
  struct mainBooks temp;
  jumlahData();
  int i,j;
  for (i = 0; i < sizeArr; i++){
            for (j = 0; j < sizeArr; j++){
                if (j <= i) continue;
                if (theBooks[i].date.tahun == theBooks[j].date.tahun){
                    if (theBooks[i].date.bulan == theBooks[j].date.bulan){
                        if (theBooks[i].date.tanggal == theBooks[j].date.tanggal){
                            temp = theBooks[i];
                            theBooks[i] = theBooks[j];
                            theBooks[j] = temp;
                        }
                        else{
                            if (theBooks[i].date.tanggal > theBooks[j].date.tanggal){
                                temp = theBooks[i];
                                theBooks[i] = theBooks[j];
                                theBooks[j] = temp;
                            }
                        }
                    }
                    else{
                        if (theBooks[i].date.bulan > theBooks[j].date.bulan){
                            temp = theBooks[i];
                            theBooks[i] = theBooks[j];
                            theBooks[j] = temp;
                        }
                    }
                }
                else{
                    if (theBooks[i].date.tahun > theBooks[j].date.tahun){
                        temp = theBooks[i];
                        theBooks[i] = theBooks[j];
                        theBooks[j] = temp;
                    }
                }
            }
            if (i > 0){
                if (theBooks[i].date.tanggal == theBooks[i-1].date.tanggal &&
                    theBooks[i].date.bulan == theBooks[i-1].date.bulan &&
                    theBooks[i].date.tahun == theBooks[i-1].date.tahun)
                {
                    if (theBooks[i].qtyBuku > theBooks[i-1].qtyBuku){
                        temp = theBooks[i];
                        theBooks[i] = theBooks[i-1];
                        theBooks[i-1] = temp;
                    }
                }
            }
        }
}
void sortQty(){
 struct mainBooks temp;
  jumlahData();
  int i,j;
  for (i = 0; i < sizeArr; i++){
            for (j = 0; j < sizeArr; j++){
                if (j <= i) continue;
                if (theBooks[i].qtyBuku < theBooks[j].qtyBuku){
                    temp = theBooks[i];
                    theBooks[i] = theBooks[j];
                    theBooks[j] = temp;
                }
            }
            if (i > 0){
                struct mainBooks temp;
                if (theBooks[i].qtyBuku == theBooks[i-1].qtyBuku){
                    if (theBooks[i].date.tahun == theBooks[i-1].date.tahun){
                        if (theBooks[i].date.bulan == theBooks[i-1].date.bulan){
                            if (theBooks[i].date.tanggal < theBooks[i-1].date.tanggal){
                                temp = theBooks[i];
                                theBooks[i] = theBooks[i-1];
                                theBooks[i-1] = temp;
                            }
                        }
                        else{
                            if (theBooks[i].date.bulan < theBooks[i-1].date.bulan){
                                temp = theBooks[i];
                                theBooks[i] = theBooks[i-1];
                                theBooks[i-1] = temp;
                            }
                        }
                    }
                    else{
                        if (theBooks[i].date.tahun < theBooks[i-1].date.tahun){
                            temp = theBooks[i];
                            theBooks[i] = theBooks[i-1];
                            theBooks[i-1] = temp;
                        }
                    }
                }
            }
        }
}


int main(){
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
            readData();
            sortDate();
            printAll(j);
            system("pause");
            system("cls");

            i = 0;
            break;
        case 3:
            system("cls");
            readData();
            sortQty();
            printAll(j);
            system("pause");
            system("cls");
            i = 0;
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
