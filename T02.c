#include <stdio.h>

int main() {
    int N;

    printf("=== PROGRAM PENJUMLAHAN NILAI SISWA ===\n");
    printf("Masukkan jumlah total siswa: ");
    scanf("%d", &N);

    int nilai[N];
    int kelompok[N];

    printf("\nMasukkan data siswa:\n");
    printf("(Format: nilai kode_kelompok)\n");

    for(int i = 0; i < N; i++) {
        printf("Siswa ke-%d : ", i + 1);
        scanf("%d %d", &nilai[i], &kelompok[i]);
    }

    int kode_dicari;
    printf("\nMasukkan kode kelompok yang ingin dijumlahkan: ");
    scanf("%d", &kode_dicari);

    int total = 0;

    for(int i = 0; i < N; i++) {
        if(kelompok[i] == kode_dicari) {
            total += nilai[i];
        }
    }

    printf("\nTotal nilai untuk kelompok %d adalah: %d\n", kode_dicari, total);

    return 0;
}