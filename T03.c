#include <stdio.h>
#include <string.h>

#define MAX 100

struct Laundry {
    int kode;
    char nama[50];
    char tanggal[20];
    int layanan;        // 1 = Reguler, 2 = Express
    float berat;
    float total;
    char status[20];    // Proses / Selesai
};

struct Laundry data[MAX];
int jumlah = 0;

void tambahLaundry() {
    float harga;

    printf("\n=== Tambah Data Laundry ===\n");

    data[jumlah].kode = jumlah + 1;

    printf("Nama Pelanggan: ");
    scanf(" %[^\n]", data[jumlah].nama);

    printf("Tanggal Masuk (dd/mm/yyyy): ");
    scanf("%s", data[jumlah].tanggal);

    printf("Jenis Layanan:\n");
    printf("1. Reguler (8000/kg)\n");
    printf("2. Express (12000/kg)\n");
    printf("Pilih: ");
    scanf("%d", &data[jumlah].layanan);

    printf("Berat (kg): ");
    scanf("%f", &data[jumlah].berat);

    if(data[jumlah].layanan == 1)
        harga = 8000;
    else if(data[jumlah].layanan == 2)
        harga = 12000;
    else {
        printf("Layanan tidak valid!\n");
        return;
    }

    data[jumlah].total = harga * data[jumlah].berat;

    if(data[jumlah].berat >= 8) {
        data[jumlah].total *= 0.85;
        printf("Diskon 15%% diberikan!\n");
    }

    strcpy(data[jumlah].status, "Proses");

    printf("Total Bayar: Rp %.0f\n", data[jumlah].total);

    jumlah++;
}

void lihatData() {
    int i;

    printf("\n=== Data Laundry ===\n");

    for(i = 0; i < jumlah; i++) {
        printf("\nKode: %d\n", data[i].kode);
        printf("Nama: %s\n", data[i].nama);
        printf("Tanggal: %s\n", data[i].tanggal);
        printf("Berat: %.2f kg\n", data[i].berat);
        printf("Total: Rp %.0f\n", data[i].total);
        printf("Status: %s\n", data[i].status);
    }
}

void ubahStatus() {
    int kode, i;

    printf("\nMasukkan kode laundry: ");
    scanf("%d", &kode);

    for(i = 0; i < jumlah; i++) {
        if(data[i].kode == kode) {
            strcpy(data[i].status, "Selesai");
            printf("Status berhasil diubah menjadi Selesai.\n");
            return;
        }
    }

    printf("Kode tidak ditemukan!\n");
}

void cetakStruk() {
    int kode, i;

    printf("\nMasukkan kode laundry untuk cetak struk: ");
    scanf("%d", &kode);

    for(i = 0; i < jumlah; i++) {
        if(data[i].kode == kode) {
            printf("\n======= STRUK LAUNDRY DEL =======\n");
            printf("Kode      : %d\n", data[i].kode);
            printf("Nama      : %s\n", data[i].nama);
            printf("Tanggal   : %s\n", data[i].tanggal);
            printf("Berat     : %.2f kg\n", data[i].berat);
            printf("Total     : Rp %.0f\n", data[i].total);
            printf("Status    : %s\n", data[i].status);
            printf("=================================\n");
            return;
        }
    }

    printf("Data tidak ditemukan!\n");
}

int main() {
    int pilihan;

    do {
        printf("\n===== SISTEM LAUNDRY DEL =====\n");
        printf("1. Tambah Laundry\n");
        printf("2. Lihat Data\n");
        printf("3. Ubah Status\n");
        printf("4. Cetak Struk\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: tambahLaundry(); break;
            case 2: lihatData(); break;
            case 3: ubahStatus(); break;
            case 4: cetakStruk(); break;
            case 5: printf("Terima kasih.\n"); break;
            default: printf("Menu tidak valid!\n");
        }

    } while(pilihan != 5);

    return 0;
}