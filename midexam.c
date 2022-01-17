#include <stdio.h>
#include <time.h>
int main()
{
    printf("\n---------------Selamat Datang-----------------\n");
    printf("\nProgram Vaksinasi Flu Rumah Sakit Kota Malang\n");
    printf(" Silakang lakukan pengisian data vaksinasi \n");

    // VARIABEL DATA VAKSIN
    char 
    nameVaksin[100],    // var dari Nama Vaksin 
    numVaksin[100],     // var dari Kode Batch Vaksin
    statusVaksin[100],  // var dari Status Vaksin (sudah digunakan atau tidak)
    expiredVaksin[100]; // var dari Masa Kadaluarsa vaksin

    // VARIABEL DATA PESERTA
    long long int NIK;      // var dari NIK (Nomor Induk Kependudukan) Peserta Vaksin
    char namePeserta[100],  // var dari Nama Peserta Vaksin
    TTL[35],                // var dari Tempat Tanngal Lahir
    address[50],            // var dari Alamat Peserta Vaksin
    addressVaksin[50],      // var dari Alamt Vaksinasi Dilakukan
    namePetugas[100],       // var dari Peserta Vaksinasi yang bertugas
    numIjinPrak[100],       // var dari Nomor Ijin Praktek Tenaga Medis / Tenaga Kesehatan
    numHP[15];              // var dari Nomor HP Peserta Vaksin

    //INPUT DATA VAKSIN
    printf("1. Data Vaksin :\n");
    printf(" Nama Vaksin : ");
    scanf(" %[^\n]s", &nameVaksin);
    printf(" Kode Batch Vaksin : ");
    scanf(" %[^\n]s", &numVaksin);
    printf(" Status Vaksin (sudah digunakan atau tidak): ");
    scanf(" %[^\n]s", &statusVaksin);
    printf(" Masa Kadaluarsa vaksin: ");
    scanf(" %[^\n]s", &expiredVaksin);

    // printf("\n%s", nameVaksin);
    // printf("\n%s", numVaksin);
    // printf("\n%s", statusVaksin);
    // printf("%s", nameVaksin);

    printf("---------------------------------------");
    // INPUT DATA PESERTA VAKSIN
    printf("\n2. Data Peserta Vaksin :");
    printf("\n Nomor Induk Kependudukan : ");
    scanf(" %lld", &NIK);
    // getchar();
    printf(" Nama : ");
    scanf(" %[^\n]s", &namePeserta);
    getchar();
    printf(" Tempat/Tanggal Lahir :");
    scanf(" %[^\n]s", &TTL);
    getchar();
    printf(" Alamat (sesuai NIK) : ");
    scanf(" %[^\n]s", &address);
    getchar();
    printf(" Nomor HandPhone : ");
    scanf(" %s", &numHP);
    getchar();
    printf("-- Tenaga Kesehatan yang melakukan vaksinasi --\n");
    printf("\tNama : ");
    scanf(" %[^\n]s", &namePetugas);
    getchar();
    printf("\tNomor Ijin Praktek : ");
    scanf("%[^\n]s", &numIjinPrak);
    getchar();

    // lakuin vaksin keberapa ?
    int menu;
    printf("\nPeserta melakukan vaksinasi keberapa ?");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        // vaksinasi pertama
        printf("\nVaksinasi Pertama");
        printf("\nNama Vaksin : %s", nameVaksin);
        printf("\nNomor Batch Vaksinasi : %s", numVaksin);
        printf("\nLokasi Vaksinasi : Rumah Sakit Daerah Kota Malang \n");
        // scanf(" %[^\n]s", &addressVaksin);getchar();

        // Date Now
        int y, m, d;
        time_t now;
        time(&now);

        struct tm *local = localtime(&now);
        d = local->tm_mday;    // get day of month (1 to 31)
        m = local->tm_mon + 1; // get month of year (0 to 11)
        y = local->tm_year + 1900;
        printf("Tanggal Vaksin Pertama : %d/%d/%d\n", d, m, y);
        printf("Kode Sertifikat: VKS1-%d%d%d-%lld", y,m,d, NIK);

        // Future Date
        // get the value first
         struct tm t = {
        .tm_year = y - 1900,
        .tm_mon = m - 1,
        .tm_mday = d,
        };
        // SUM for 31 Days/ 1 months
        t.tm_mday += 31;
        mktime(&t);
        // result
        printf("\nTanggal Vaksinasi Kedua : %d/%d/%d", t.tm_mday,t.tm_mon,t.tm_year+1900);
        break;
    case 2:
        // vaksinasi kedua
        printf("\nVaksinasi Kedua");
        printf("\nNama Vaksin : %s", nameVaksin);
        printf("\nNomor Batch Vaksinasi : %s", numVaksin);
        printf("\nLokasi Vaksinasi : Rumah Sakit Daerah Kota Malang \n");
        // scanf(" %[^\n]s", &addressVaksin);getchar();

        // Date Now
        int ye, mo, da;
        time_t current;
        time(&current);

        // printf("Tanngal Vaksin Pertama : %s", ctime(&now));
        struct tm *local2 = localtime(&current);
        da = local2->tm_mday;    // get day of month (1 to 31)
        mo = local2->tm_mon + 1; // get month of year (0 to 11)
        ye = local2->tm_year + 1900;
        printf("Tanggal Vaksin Kedua : %d/%d/%d\n", da, mo, ye);
        printf("Kode Sertifikat: VKS2-%d%d%d-%lld", ye,mo,da, NIK);

        // Future Date
        // get the value first
         struct tm t2 = {
        .tm_year = ye - 1900,
        .tm_mon = mo - 1,
        .tm_mday = da
        };
        // SUM for 1 Year
        t2.tm_mday += 365;
        mktime(&t2);
        // result
        printf("\nTanggal Vaksinasi Selanjutnya : %d/%d/%d", t2.tm_mday,t2.tm_mon+1,t2.tm_year+1900);
        break;
    default:
        break;
    }

    // printf("----------------------------------------------------------------");
    // printf("%s", namePetugas);
    // printf("%s", numIjinPrak);
    // printf("\n%lld", NIK);
    // printf("\n%s", namePeserta);
    // printf("\n%s", TTL);
    // printf("\n%s", address);
    // printf("\n%s", numHP);
}