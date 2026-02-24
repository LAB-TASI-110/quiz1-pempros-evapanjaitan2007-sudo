#include <stdio.h>
#include <string.h>

int main() {
    // Berdasarkan perbandingan tubuh (Asumsi Ucok:Butet adalah 3:2 atau 1.5x)
    double b_ucok = 3.0;
    double b_butet = 2.0;
    double rasio = b_ucok / b_butet;

    // Harga Menu berdasarkan image/menu.jpeg
    double h_np = 25000.0; // Nasi Padang
    double h_rd = 30000.0; // Rendang
    double h_ag = 22000.0; // Ayam Goreng

    char kode[20];
    double p_butet;
    double total = 0;

    // Buffer untuk menyimpan data tampilan struk
    char names[10][30];
    double porsis[10];
    double hargas[10];
    double subtotals[10];
    int count = 0;

    while (scanf("%s", kode) != EOF && strcmp(kode, "END") != 0) {
        if (scanf("%lf", &p_butet) != 1) break;

        double p_total = p_butet + (p_butet * rasio);
        double current_harga = 0;

        if (strcmp(kode, "NP") == 0) {
            strcpy(names[count], "Nasi Padang");
            current_harga = h_np;
        } else if (strcmp(kode, "RD") == 0) {
            strcpy(names[count], "Rendang");
            current_harga = h_rd;
        } else if (strcmp(kode, "AG") == 0) {
            strcpy(names[count], "Ayam Goreng");
            current_harga = h_ag;
        }

        porsis[count] = p_total;
        hargas[count] = current_harga;
        subtotals[count] = p_total * current_harga;
        total += subtotals[count];
        count++;
    }

    // Output sesuai image_449f18.png
    printf("%-20s %-10s %-10s %-10s\n", "Menu", "Porsi", "Harga", "Total");
    printf("============================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10.0f %-10.0f %-10.0f\n", names[i], porsis[i], hargas[i], subtotals[i]);
    }

    printf("============================================================\n");
    printf("%-42s %.0f\n", "Total Pembayaran", total);

    return 0;
}