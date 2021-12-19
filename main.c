#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void menu();
void muat_jumlah();

//MENU PEMBELI
void menu_pembeli();   //100%
void beli_barang();    //100%
void keranjang_saya(); //100%
void pesanan_saya();

//MENU PENJUAL
void menu_penjual();   //100%
void daftar_barang();  //100%
void tambah_barang();  //100%
void semua_barang();   //100%
void edit_barang();    //100%
void cari_barang();    //100% (Mode Linear)
void hapus_barang();   //100%
void sorting_barang(); //100% (Metode Selection)
void kategori();       //100%
void close();          //100%

struct Barang
{
    char nama[100];
    int harga, stok, kategori, jual; //kategori 1 = elektronik, 2 = fashion
} item[1000], keranjang[1000], checkout[1000];

struct Alamat
{
    char provinsi[100], kota[100], kecamatan[100], rincian[100], kelurahan[100], rekening[100];
    int kodepos;
} alamat;

char input[100], yn;
int total_harga = 0, pilih, tanda = 0, pilihsort, jumlah, jumlah_keranjang = 0, jumlah_pesanan = 0; //jumlah barang/item pada awalnya

int main()
{
    kelompok();
    daftar_barang();
    menu();
    update_item();
}

void kelompok()
{
    system("clear");
    printf("APLIKASI TOKO ONLINE : FISCHA (Fashion dan Elektronik)\n");
    printf("Oleh :\n1. Mohammad Nur Holis \t\t(20081010053)\n2. Hafizh Kennandya Maulana \t(20081010077)\n");
    printf("3. Aji Prayoga \t\t\t(20081010160)\n4. Muhammad Fadhil F \t\t(20081010216)\n5. Muhammad Iffan Maulana \t(20081010221)\n\n");
    system("pause");
}

void menu()
{
menu:
    system("cls");
    printf("MAIN MENU : \n");
    printf("[1]. Masuk Sebagai Pembeli\n[2]. Masuk Sebagai Penjual\n[3]. Keluar");
    printf("\n\n> Masukkan pilihan menu anda : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        menu_pembeli();
        goto menu;
        break;
    case 2:
        menu_penjual();
        goto menu;
        break;
    case 3:
        close();
        break;
    default:
        printf("\nMohon maaf pilihan anda salah!");
        getche();
        goto menu;
    }
}

///////////////////////////////////-MENU PEMBELI-////////////////////////////////////

void menu_pembeli()
{
menu_pembeli:
    system("cls");
    printf("MAIN MENU PEMBELI :\n[1] Beli Barang\n[2] Keranjang Saya\n[3] Pesanan Saya\n[4] Keluar");
    printf("\n\n> Masukkan pilihan menu anda : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        beli_barang();
        goto menu_pembeli;
        break;
    case 2:
        keranjang_saya();
        goto menu_pembeli;
        break;
    case 3:
        pesanan_saya();
        goto menu_pembeli;
        break;
    case 4:
        close();
        break;
    default:
        printf("\nMohon maaf pilihan anda salah!");
        getche();
        goto menu_pembeli;
    }
}

void beli_barang()
{
    system("cls");
    printf("BELI BARANG :\n");
    for (int a = 0; a < jumlah; a++)
    {
        printf("%i. \t%s (", a + 1, item[a].nama);
        kategori(item[a].kategori);
        printf(")\n\tRp %i | Stok : %i | Terjual : %i\n", item[a].harga, item[a].stok, item[a].jual);
        printf("\n");
    }
    printf("0.\tKembali\n\n");
    printf("Masukkan Pilihan : ");
    scanf("%i", &pilih);

    if (pilih == 0)
    {
    }
    else
    {
        if (item[pilih - 1].stok < 1)
        {
            printf("Mohon maaf %s stok habis", item[pilih - 1].nama);
            getche();
        }
        else
        {
            update_stok(pilih - 1);
            system("cls");
            printf("%s telah dimasukkan ke keranjang! \nSilahkan lakukan checkout pada menu keranjang", item[pilih - 1].nama);
            getche();
        }
    }
}

void update_stok(int a)
{
    item[a].stok = item[a].stok - 1;
    strcpy(keranjang[jumlah_keranjang].nama, item[a].nama);
    keranjang[jumlah_keranjang].harga = item[a].harga;
    jumlah_keranjang++;
}

void keranjang_saya()
{
menu_keranjang:
    system("cls");
    printf("KERANJANG SAYA :\n");
    for (int a = 0; a < jumlah_keranjang; a++)
    {
        printf("%i. %s | Rp. %i\n", a + 1, keranjang[a].nama, keranjang[a].harga);
        total_harga = total_harga + keranjang[a].harga;
    }
    printf("\nTotal Harga : Rp %i\n", total_harga);
    printf("\n1. Lakukan Pembayaran\n2. Hapus Barang\n3. Keluar\n\nMasukkan Pilihan : ");
    scanf("%i", &pilih);

    switch (pilih)
    {
    case 1:
        pembayaran();
        break;
    case 2:
        hapus_keranjang();
        break;
    case 3:
        close();
        break;
    default:
        printf("\nMohon maaf pilihan anda salah!");
        getche();
        goto menu_keranjang;
    }
}

void pembayaran()
{
    system("cls");
    printf("PEMBAYARAN :\n");
    printf("Masukkan Alamat!\n");
    printf("Provinsi : ");
    getchar();
    gets(alamat.provinsi);
    printf("Kota/Kabupaten : ");
    gets(alamat.kota);
    printf("Kecamatan : ");
    gets(alamat.kecamatan);
    printf("Kelurahan/Desa : ");
    gets(alamat.kelurahan);
    printf("Detail Lengkap (Jalan dan Nomor Rumah): ");
    gets(alamat.rincian);
    printf("Kodepos : ");
    scanf("%i", &alamat.kodepos);
    printf("\nMasukkan Nomer Rekening Anda : ");
    getchar();
    gets(alamat.rekening);
    printf("\nTotal Tagihan Sebesar %i\nLanjutkan pembayaran? (Y/N) : ", total_harga);
    scanf("%c", &yn);
    if (yn == 'Y' || yn == 'y')
    {
        buat_pesanan();
        system("cls");
        printf("Pesanan anda berhasil dibuat! Cek di menu Pesanan Saya");
        getche();
    }
    else
    {
        printf("Pesanan anda gagal dibuat!");
        getche();
    }
}

void buat_pesanan()
{
    jumlah_pesanan = 0;
    for (int a = 0; a < jumlah_keranjang; a++)
    {
        strcpy(checkout[a].nama, keranjang[a].nama);
        checkout[a].harga = keranjang[a].harga;
        jumlah_pesanan++;

        for (int b = 0; b < jumlah; b++)
        {
            if (strcmp(checkout[a].nama, item[b].nama) == 0)
            {
                item[b].jual++;
            }
        }
    }

    jumlah_keranjang = 0;
    total_harga = 0;
}

void hapus_keranjang()
{
    system("cls");
    printf("HAPUS BARANG :\n");
    for (int a = 0; a < jumlah_keranjang; a++)
    {
        printf("%i. %s | Rp. %i\n", a + 1, keranjang[a].nama, keranjang[a].harga);
    }
    printf("\nBarang yang Ingin Dihapus : ");
    scanf("%i", &pilih);
    update_keranjang_hapus(pilih - 1);
    getche();
}

void update_keranjang_hapus(int a)
{
    printf("\n%s telah dihapus", keranjang[a].nama);
    for (; a < jumlah_keranjang; a++)
    {
        strcpy(keranjang[a].nama, keranjang[a + 1].nama);
        keranjang[a].harga = keranjang[a + 1].harga;
        keranjang[a].stok = keranjang[a + 1].stok;
        keranjang[a].kategori = keranjang[a + 1].kategori;
        keranjang[a].jual = keranjang[a + 1].jual;
    }
    jumlah_keranjang--;
}

void pesanan_saya()
{
    system("cls");
    printf("PESANAN SAYA :\n");
    if (jumlah_pesanan == 0)
    {
        printf("Anda belum memiliki pesanan");
        getche();
    }
    else
    {
        for (int a = 0; a < jumlah_pesanan; a++)
        {
            printf("%i. %s | Rp. %i\n", a + 1, checkout[a].nama, checkout[a].harga);
        }
        printf("Rincian : Sedang dikirim ke %s, %s", alamat.kelurahan, alamat.kecamatan);
        getche();
    }
}

/////////////////////////////////-MENU PENJUAL-//////////////////////////////////////

void menu_penjual()
{
menu_penjual:
    system("cls");
    printf("MAIN MENU PENJUAL :");
    printf("\n[1]. Daftar Barang");
    printf("\n[2]. Tambah Barang");
    printf("\n[3]. Cari Barang");
    printf("\n[4]. Hapus Barang");
    printf("\n[5]. Edit Barang");
    printf("\n[6]. Sorting Barang");
    printf("\n[7]. Keluar");
    printf("\n\n> Masukkan pilihan menu anda : ");
    scanf("%d", &pilih);
    switch (pilih)
    {
    case 1:
        semua_barang();
        goto menu_penjual;
        break;
    case 2:
        tambah_barang();
        goto menu_penjual;
        break;
    case 3:
        cari_barang();
        goto menu_penjual;
        break;
    case 4:
        hapus_barang();
        goto menu_penjual;
        break;
    case 5:
        edit_barang();
        goto menu_penjual;
        break;
    case 6:
        sorting_barang();
        goto menu_penjual;
        break;
    case 7:
        close();
        break;
    default:
        printf("\nMohon maaf pilihan anda salah!");
        getche();
        goto menu_penjual;
    }
}

void sorting_barang()
{
    system("cls");
    printf("SORTING BERDASARKAN:\n1. Harga\n2. Stok\n3. Kategori\n4. Nama\n> ");
    scanf("%i", &pilihsort);
    printf("\n");
    switch (pilihsort)
    {
    case 1:
        sorting_harga();
        break;
    case 2:
        sorting_stok();
        break;
    case 3:
        sorting_kategori();
        break;
    case 4:
        sorting_nama();
        break;
    default:
        printf("\nMohon maaf pilihan anda salah!");
        getche();
    }
}

void tambah_barang()
{
    system("cls");
    int jumlah_tambah;
    printf("Jumlah Barang yang akan Ditambahkan : ");
    scanf("%i", &jumlah_tambah);

    system("cls");
    int a = jumlah, b = 1, c = jumlah + jumlah_tambah;
    for (; a < c; a++)
    {
        printf("Nama Barang ke-%i : ", b);
        getchar();
        gets(item[a].nama);
        printf("Harga Barang ke-%i: ", b);
        scanf("%i", &item[a].harga);
        printf("Jumlah Barang ke-%i: ", b);
        scanf("%i", &item[a].stok);
        printf("Kategori Barang ke-%i\n\t1. Elektronik\n\t2. Fashion\n> ", b);
        scanf("%i", &item[a].kategori);
        jumlah++;
        b++;
        printf("\n");
    }

    system("cls");
    printf("%i barang telah berhasil ditambahkan!", jumlah_tambah);
    update_jumlah();
    getche();
    semua_barang();
}

void cari_barang()
{
    system("cls");
    printf("CARI BARANG\n");
    printf("Masukkan Nama Barang : ");
    getchar();
    gets(input);

    for (int a = 0; a < jumlah; a++)
    {
        if (strcmp(item[a].nama, input) == 0)
        {
            printf("\nBarang Ditemukan!\n");
            tampil_barang(a);
            tanda = 1;
            break;
        }
    }
    if (tanda == 0)
    {
        printf("\nBarang Tidak Ditemukan!\n");
        getche();
    }
    tanda = 0;
}

void hapus_barang()
{
    system("cls");
    printf("HAPUS BARANG\n");
    printf("Masukkan Nama Barang yang Akan Dihapus : ");
    getchar();
    gets(input);

    for (int a = 0; a < jumlah; a++)
    {
        if (strcmp(item[a].nama, input) == 0)
        {
            printf("Apakah anda yakin untuk menghapus '%s'? (Y/N) : ", input);
            scanf("%c", &yn);

            if (yn == 'Y' || yn == 'y')
            {
                menghapus_barang(a);
                printf("\nBarang Telah Dihapus!");
            }
            else
            {
                printf("\nBarang Tidak Dihapus!");
            }
            tanda = 1;
            getche();
            break;
        }
    }
    if (tanda == 0)
    {
        printf("\nBarang Tidak Ditemukan!\n");
        getche();
    }
    tanda = 0;
    update_jumlah();
}

void menghapus_barang(int a)
{
    for (; a < jumlah; a++)
    {
        strcpy(item[a].nama, item[a + 1].nama);
        item[a].harga = item[a + 1].harga;
        item[a].stok = item[a + 1].stok;
        item[a].kategori = item[a + 1].kategori;
        item[a].jual = item[a + 1].jual;
    }
    jumlah--;
}

void edit_barang()
{
    system("cls");
    printf("EDIT BARANG\n");
    printf("Masukkan Nama Barang : ");
    getchar();
    gets(input);

    for (int a = 0; a < jumlah; a++)
    {
        if (strcmp(item[a].nama, input) == 0)
        {
            mengedit_barang(a);
            tanda = 1;
            break;
        }
    }
    if (tanda == 0)
    {
        printf("\nBarang Tidak Ditemukan!\n");
        getche();
    }
    tanda = 0;
}

void mengedit_barang(int a)
{
    system("cls");
    printf("Edit Nama Barang : ");
    gets(item[a].nama);
    printf("Edit Harga Barang : ");
    scanf("%i", &item[a].harga);
    printf("Edit Jumlah Barang : ");
    scanf("%i", &item[a].stok);
    printf("Edit Kategori Barang\n\t1. Elektronik\n\t2. Fashion\n> ");
    scanf("%i", &item[a].kategori);
    printf("\n");
    system("cls");
    printf("Barang telah berhasil diedit!");
    getche();
}

void sorting_harga()
{
    printf("SORTING HARGA :\n1. Murah ke Mahal (Ascending)\n2. Mahal ke Murah (Descending)\n> ");
    scanf("%i", &pilihsort);
    if (pilihsort == 1)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (item[j].harga > item[k].harga)
                {
                    j = k;
                }
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else if (pilihsort == 2)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (item[j].harga < item[k].harga)
                {
                    j = k;
                }
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else
    {
        printf("\nMohon maaf pilihan anda salah!");
        getche();
    }
}

void sorting_stok()
{
    printf("SORTING STOK :\n1. Sedikit ke Banyak (Ascending)\n2. Banyak ke Sedikit (Descending)\n> ");
    scanf("%i", &pilihsort);
    if (pilihsort == 1)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (item[j].stok > item[k].stok)
                {
                    j = k;
                }
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else if (pilihsort == 2)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (item[j].stok < item[k].stok)
                {
                    j = k;
                }
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else
    {
        printf("\nMohon maaf pilihan anda salah!");
        getche();
    }
}

void sorting_kategori()
{
    printf("SORTING Kategori :\n1. A ke Z (Ascending)\n2. Z ke A (Descending)\n> ");
    scanf("%i", &pilihsort);
    if (pilihsort == 1)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (item[j].kategori > item[k].kategori)
                {
                    j = k;
                }
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else if (pilihsort == 2)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (item[j].kategori < item[k].kategori)
                {
                    j = k;
                }
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else
    {
        printf("\nMohon maaf pilihan anda salah!");
        getche();
    }
}

void sorting_nama()
{
    printf("SORTING NAMA :\n1. A ke Z (Ascending)\n2. Z ke A (Descending)\n> ");
    scanf("%i", &pilihsort);
    if (pilihsort == 1)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j;
            j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (strcmp(item[j].nama, item[k].nama) == 1)
                    j = k;
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else if (pilihsort == 2)
    {
        for (int i = 0; i < jumlah; i++)
        {
            int j;
            j = i;
            for (int k = i + 1; k < jumlah; k++)
            {
                if (strcmp(item[j].nama, item[k].nama) == -1)
                    j = k;
            }
            if (j != i)
            {
                selection_sorting(i, j);
            }
        }
        semua_barang();
    }
    else
    {
        printf("\nMohon maaf pilihan anda salah!");
        getche();
    }
}

void tampil_barang(int a)
{
    printf("%s (", item[a].nama);
    kategori(item[a].kategori);
    printf(")\nRp %i | Stok : %i | Terjual : %i\n", item[a].harga, item[a].stok, item[a].jual);
    printf("\n");
    getche();
}

void semua_barang()
{
    system("cls");
    printf("DAFTAR BARANG :\n");
    for (int a = 0; a < jumlah; a++)
    {
        printf("%i. \t%s (", a + 1, item[a].nama);
        kategori(item[a].kategori);
        printf(")\n\tRp %i | Stok : %i | Terjual : %i\n", item[a].harga, item[a].stok, item[a].jual);
        printf("\n");
    }
    system("pause");
}

void daftar_barang()
{
    muat_jumlah();
    char data[100];
    int data2;
    int i = 0;
    FILE *pfile;

    pfile = fopen("item_nama.txt", "r");
    while (fgets(data, sizeof(data), pfile))
    {
        data[strcspn(data, "\n")] = 0; //menghapus new line
        strcpy(item[i].nama, data);
        i++;
    }
    i = 0;
    pfile = fopen("item_harga.txt", "r");
    while (fgets(data, sizeof(data), pfile))
    {
        data2 = atoi(data);
        item[i].harga = data2;
        i++;
    }
    i = 0;
    pfile = fopen("item_stok.txt", "r");
    while (fgets(data, sizeof(data), pfile))
    {
        data2 = atoi(data);
        item[i].stok = data2;
        i++;
    }
    i = 0;
    pfile = fopen("item_kategori.txt", "r");
    while (fgets(data, sizeof(data), pfile))
    {
        data2 = atoi(data);
        item[i].kategori = data2;
        i++;
    }
    i = 0;
    pfile = fopen("item_jual.txt", "r");
    while (fgets(data, sizeof(data), pfile))
    {
        data2 = atoi(data);
        item[i].jual = data2;
        i++;
    }
    fclose(pfile);
}

void kategori(int a)
{
    if (a == 1)
    {
        printf("Elektronik");
    }
    else if (a == 2)
    {
        printf("Fashion");
    }
}

void selection_sorting(int i, int j)
{
    char temp[1][40];
    strcpy(temp[0], item[j].nama);
    strcpy(item[j].nama, item[i].nama);
    strcpy(item[i].nama, temp[0]);
    int temp_harga = item[j].harga;
    item[j].harga = item[i].harga;
    item[i].harga = temp_harga;
    int temp_stok = item[j].stok;
    item[j].stok = item[i].stok;
    item[i].stok = temp_stok;
    int temp_kategori = item[j].kategori;
    item[j].kategori = item[i].kategori;
    item[i].kategori = temp_kategori;
    int temp_jual = item[j].jual;
    item[j].jual = item[i].jual;
    item[i].jual = temp_jual;
}

void muat_jumlah()
{
    char data[100];
    int data2;
    FILE *pfile;
    pfile = fopen("jumlah.txt", "r");
    fgets(data, 20, pfile);
    data2 = atoi(data);
    jumlah = data2;
    fclose(pfile);
}

void update_jumlah()
{
    char data[100];
    FILE *pfile;
    pfile = fopen("jumlah.txt", "w");
    fprintf(pfile, "%i", jumlah);
    fclose(pfile);
}

void update_item()
{
    char data[100];
    FILE *pfile;
    //update nama
    pfile = fopen("item_nama.txt", "w");
    for (int i = 0; i < jumlah; i++)
    {
        fprintf(pfile, "%s\n", item[i].nama);
    }
    //update harga
    pfile = fopen("item_harga.txt", "w");
    for (int i = 0; i < jumlah; i++)
    {
        fprintf(pfile, "%i\n", item[i].harga);
    }
    //update stok
    pfile = fopen("item_stok.txt", "w");
    for (int i = 0; i < jumlah; i++)
    {
        fprintf(pfile, "%i\n", item[i].stok);
    }
    //update kategori
    pfile = fopen("item_kategori.txt", "w");
    for (int i = 0; i < jumlah; i++)
    {
        fprintf(pfile, "%i\n", item[i].kategori);
    }
    //update jual
    pfile = fopen("item_jual.txt", "w");
    for (int i = 0; i < jumlah; i++)
    {
        fprintf(pfile, "%i\n", item[i].jual);
    }

    fclose(pfile);
}
