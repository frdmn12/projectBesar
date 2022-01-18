#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct data
{
    char nama[20], produk[20], harga[20], total[20];
    int jumlah;
    struct tanggal
    {
        int hari;
        int bulan;
        int tahun;
    } tanggal;
} data[1000];

int panjangdata;

void databaru()
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
        while (fscanf(fptr, "%d/%d/%d  %s  %s  %d  %s  %s\n", &data[no].tanggal.hari, &data[no].tanggal.bulan, &data[no].tanggal.tahun, &data[no].nama, &data[no].produk, &data[no].jumlah, &data[no].harga, &data[no].total) != EOF)
        {
            no++;
        }
        panjangdata = no;
    }
    fclose(fptr);
}

void tambahdata()
{

    //	char tanggal[20],nama[20],jenis[20],produk[20],jumlah[20],harga[20],total[20];
    char temp[20];
    int i, j, x, p;
    char y;
    int menu;
    FILE *fptr;
    fptr = fopen("sales.txt", "a");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    srand(time(0));
    printf("=============================\n");
    printf("      Tambah data produk\n");
    printf("=============================\n\n");

    printf("List barang yang tersedia : \n\n");
    printf("RakDinding \t\t Rp.500.000 \n");
    printf("RakPiring \t\t Rp.800.000 \n");
    printf("KitchenSet \t\t Rp.25.000.000 \n");
    printf("MejaDanKursi \t\t Rp.2.000.000 \n");
    printf("Kulkas \t\t\t Rp.15.000.000 \n");
    printf("Westafel \t\t Rp.500.000 \n");
    printf("PiringSet \t\t Rp.150.000 \n");
    printf("GelasSet \t\t Rp.100.000 \n");
    printf("Dekorasi \t\t Rp.100.000 \n");
    printf("ToplesOrganizer \t Rp.50.000");

    printf("\n\n");
    printf("Masukkan tanggal transaksi produk(DD/MM/YY): ");
    scanf("\n%[^\n]", &temp);
    fprintf(fptr, "%s", temp);

    printf("Masukkan nama pelanggan: ");
    scanf("\n%[^\n]", &temp);
    fprintf(fptr, "  %s", temp);

    printf("Masukkan nama produk: ");
    scanf("\n%[^\n]", &temp);
    fprintf(fptr, "  %s", temp);

    printf("Masukkan jumlah produk: ");
    scanf("\n%[^\n]", &temp);
    fprintf(fptr, "  %s", temp);

    printf("Masukkan harga produk: Rp. ");
    scanf("\n%[^\n]", &temp);
    fprintf(fptr, "  %s", temp);

    printf("Masukkan total harga: Rp. ");
    scanf("\n%[^\n]", &temp);
    fprintf(fptr, "  %s\n", temp);

    fclose(fptr);
    printf("\nData berhasil ditambahkan\n");
}

void lihatdata()
{

    FILE *fp = fopen("sales.txt", "r");
    if (fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {

        printf("%-5s| %-15s| %-15s| %-15s| %-15s| %-15s| %-15s|\n", "No.", "Tanggal", "Nama", "Produk", "Jumlah", "Harga", "Total");
        int i;
        for (i = 0; i < 110; i++)
        {
            printf("=");
        }
        printf("\n");
        char temp[2][200];

        for (i = 0; i < panjangdata; i++)
        {
            // sscanf(temp, "%d/%d/%d", data[i].tanggal.hari, data[i].tanggal.bulan, data[i].tanggal.tahun);
            sprintf(temp[0], "%02d/%02d/%d", data[i].tanggal.hari, data[i].tanggal.bulan, data[i].tanggal.tahun);
            sprintf(temp[1], "%d", data[i].jumlah);
            printf("%-5d| %-15s| %-15s| %-15s| %-15s| %-15s| %-15s|\n", i + 1, temp[0], data[i].nama, data[i].produk, temp[1], data[i].harga, data[i].total);
        }
        for (i = 0; i < 110; i++)
        {
            printf("=");
        }

        fclose(fp);
    }
}

void lihatdata_tertentu()
{

    int no;
    printf("==========================================\n");
    printf("\t   List dan Data Barang \n");
    printf("==========================================\n");
    printf("1.Rak dinding \n");
    printf("2.Rak piring \n");
    printf("3.Kitchen Set \n");
    printf("4.Meja dan kursi \n");
    printf("5.Kulkas \n");
    printf("6.Westafel \n");
    printf("7.Piring set \n");
    printf("8.Gelas set \n");
    printf("9.Dekorasi \n");
    printf("10.Toples Organizer");

    printf("\n\n");

    printf("Silahkan Memilih barang di atas untuk menampilkan data Produk : ");
    scanf("%d", &no);
    printf("Nomor barang yang anda pilih adalah no %d", no);
    switch (no)
    {
    case 1:
        printf("\n\n\tRak Dinding \n\nMaterial Bahan : Kayu Jati \n\nDeskripsi Produk :\nRak dinding 2 susun berbahan kayu jati yang bagus serta anti rayap \nyang sangat bagus untuk di jadikan tempat penyimpanan alat dapur.\n\nHarga Rp.500.000\n\n");
        break;
    case 2:
        printf("\n\n\tRak Piring \n\nMaterial Bahan : Besi \n\nDeskripsi Produk :\nRak Piring dengan material besi yang kokoh untuk di gunakan di dapur\nuntuk menahan beban sampai dengan 100 kilo. Desain yang minimalis juga sangat cocok untuk dapur anda.\n\nHarga Rp.800.000\n\n");
        break;
    case 3:
        printf("\n\n\tKitchen Set \n\nMaterial Bahan : Kombinasi kayu dan besi \n\nDeskripsi Produk :\nKitchen set dengan material bahan berkualitas yang pastinya awet dan juga memiliki desain yang minimalis namun elegan\nsangat cocok di gunakan sebagai pelengkap dapur anda dengan setiap detail yang terkesan mewah dan juga elegan.\n\nHarga Rp.25.000.000\n\n");
        break;
    case 4:
        printf("\n\n\tMeja dan Kursi \n\nMaterial Bahan : kayu Jati \n\nDeskripsi Produk :\nMeja dining set dengan material bahan kayu jati berkualitas tinggi yang sangat cocok \nuntuk di jadikan set meja dining untuk restoran ataupun rumah anda\nDengan dudukan busa yang empuk dan juga nyaman, desain yang minimalis dan tampilannya \nyang juga sangat nyaman membuat daya tarik untuk set dining table ini.\n\nHarga Rp.2.000.000\n\n");
        break;
    case 5:
        printf("\n\n\tKulkas \n\nMaterial Bahan : Tempered Glass \nDeskripsi Produk :\nKulkas dua pintu dengan kapasitas penyimpanan besar yang sangat menunjang anda untuk menyimpan \nbahan makanan di lemari pendingin ini dengan teknologi yang sangat canggih kulkas ini dapat menjaga bahan makanan anda agar tetap fresh dalam jangka waktu yang panjang. \nDengan memiliki kulkas ini anda tidak perlu khawatir lagi dengan masalah kulkan yang tidak dingin karena teknologi yang ada membuat kulkas ini tetap dingin sampai dengan\njangka waktu yang panjang.\n\nHarga Rp.15.000.000\n\n ");
        break;
    case 6:
        printf("\n\n\tWestafel \n\nMaterial Bahan : Steel \nDeskripsi Produk :\nWestafel dengan bahan steel yang anti karat dengan desain sederhan namun tidak menghilangkan kesan \nelegan walaupun hanya sebuah westafel.\nSangat cocok sebagai pelengkap pada bagian dapur dengan kapasitas tampung yang besar.\n\nHarga Rp.500.000\n\n");
        break;
    case 7:
        printf("\n\n\tPiring set \n\nMaterial Bahan : Keramik \nDeskripsi Produk :\nKualitas bahan keramik yang sangat baik di tambah dengan bentuk dan juga ukiran di setiap pcs pring \nmenambah kesan elagan pada piring yang sangat cocok sebagai pelengkap koleksi piring yang untuk di sajikan kepada customer dengan elegan.\nHarga Rp.150.000\n\n");
        break;
    case 8:
        printf("\n\n\tGelas set \n\nMaterial Bahan : Keramik \nDeskripsi Produk : \nKualitas keramik yang sangat baik dan juga desain yang sangat cantik \nmembuat set gelas ini sangat cocok untuk di pasangkan dengan piring yang serupa dengan gaya yang elegan \n\nHarga Rp.100.000\n\n");
        break;
    case 9:
        printf("\n\n\tDekorasi \n\nMaterial Bahan : Kanvas \nDeskripsi Produk : \nDengan bahan kanvas dekorasi ini dapat melengkapi hiasan dinding anda \ndengan berbagai macam gambar dapat membuat dinding anda semakin indah \n\nHarga Rp.100.000\n\n");
        break;
    case 10:
        printf("\n\n\tToples Organizer \n\nMaterial Bahan : Akrilik \nDeskripsi Produk :\nDengan menggunakan material bahan akrilik toples ini tidak mudah pecah dan tahan akan benturan \nwalaupun menggunakan bahan akrilik tidak mengurangi nilai tampilan dari toples ini \ndi mana toples ini tetap terlihat elegan dengan desainya. \n\nHarga Rp.50.000\n\n");
        break;
    }
}

void transaksisesuai_tanggal()
{
    struct data temp;
    databaru();
    int i, j;
    for (i = 0; i < panjangdata; i++)
    {
        for (j = 0; j < panjangdata; j++)
        {
            if (j <= i)
                continue;
            if (data[i].tanggal.tahun == data[j].tanggal.tahun)
            {
                if (data[i].tanggal.bulan == data[j].tanggal.bulan)
                {
                    if (data[i].tanggal.hari == data[j].tanggal.hari)
                    {
                        temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                    else
                    {
                        if (data[i].tanggal.hari > data[j].tanggal.hari)
                        {
                            temp = data[i];
                            data[i] = data[j];
                            data[j] = temp;
                        }
                    }
                }
                else
                {
                    if (data[i].tanggal.bulan > data[j].tanggal.bulan)
                    {
                        temp = data[i];
                        data[i] = data[j];
                        data[j] = temp;
                    }
                }
            }
            else
            {
                if (data[i].tanggal.tahun > data[j].tanggal.tahun)
                {
                    temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
        if (i > 0)
        {
            if (data[i].tanggal.hari == data[i - 1].tanggal.hari &&
                data[i].tanggal.bulan == data[i - 1].tanggal.bulan &&
                data[i].tanggal.tahun == data[i - 1].tanggal.tahun)
            {
                if (data[i].jumlah > data[i - 1].jumlah)
                {
                    temp = data[i];
                    data[i] = data[i - 1];
                    data[i - 1] = temp;
                }
            }
        }
    }
}

void transaksisesuai_barang()
{
    struct data temp;
    databaru();
    int i, j;
    for (i = 0; i < panjangdata; i++)
    {
        for (j = 0; j < panjangdata; j++)
        {
            if (j <= i)
                continue;
            if (data[i].jumlah < data[j].jumlah)
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        if (i > 0)
        {
            struct data temp;
            if (data[i].jumlah == data[i - 1].jumlah)
            {
                if (data[i].tanggal.tahun == data[i - 1].tanggal.tahun)
                {
                    if (data[i].tanggal.bulan == data[i - 1].tanggal.bulan)
                    {
                        if (data[i].tanggal.hari < data[i - 1].tanggal.hari)
                        {
                            temp = data[i];
                            data[i] = data[i - 1];
                            data[i - 1] = temp;
                        }
                    }
                    else
                    {
                        if (data[i].tanggal.bulan < data[i - 1].tanggal.bulan)
                        {
                            temp = data[i];
                            data[i] = data[i - 1];
                            data[i - 1] = temp;
                        }
                    }
                }
                else
                {
                    if (data[i].tanggal.tahun < data[i - 1].tanggal.tahun)
                    {
                        temp = data[i];
                        data[i] = data[i - 1];
                        data[i - 1] = temp;
                    }
                }
            }
        }
    }
}

int main()
{
    int menu;
menu:
    printf("=================================================\n");
    printf("\t\tMenu Dining & Kitchen\n");
    printf("=================================================\n");
    printf("Silahkan pilih nomor dibawah ini sesuai kebutuhan:\n");
    printf("1. Tambah data produk\n");
    printf("2. Tampilkan data-data yang di inginkan\n");
    printf("3. Tampilkan transaksi sesuai data produk\n");
    printf("4. Tampilkan transaksi sesuai tanggal\n");
    printf("5. Save and Exit\n");
    printf("Input : ");
    scanf("%d", &menu);
    system("cls");
    switch (menu)
    {
    case 1:
        tambahdata();
        printf("\n");
        system("pause");
        system("cls");
        goto menu;

    case 2:
        lihatdata_tertentu();
        printf("\n");
        system("pause");
        system("cls");
        goto menu;

    case 3:
        transaksisesuai_barang();
        lihatdata();
        printf("\n");
        system("pause");
        system("cls");
        goto menu;

    case 4:
        transaksisesuai_tanggal();
        lihatdata();
        printf("\n");
        system("pause");
        system("cls");
        goto menu;

    case 5:
        printf("========= Terima Kasih!! ==========");
        break;
    default:
        printf("Input Error!\n");
        system("pause");
        system("cls");
        goto menu;
    }
    printf("\n");
    return 0;
}
