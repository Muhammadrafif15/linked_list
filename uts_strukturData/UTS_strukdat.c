#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NAMA 50
#define MAX_MAHASISWA 20


struct Mahasiswa {
    char nama[MAX_NAMA];
    char jenis_kelamin; 
};

typedef struct Mahasiswa Mahasiswa;

struct LingkaranApi {
    struct Mahasiswa mahasiswa_laki[MAX_MAHASISWA];
    int jumlah_laki;
    struct Mahasiswa mahasiswa_perempuan[MAX_MAHASISWA];
    int jumlah_perempuan;
};

typedef struct LingkaranApi LingkaranApi; 

void lingkaran(LingkaranApi *lingkaran) {
    lingkaran->jumlah_laki = 0;
    lingkaran->jumlah_perempuan = 0;
}

int cek_kapasitas(LingkaranApi *lingkaran) {
    return (lingkaran->jumlah_laki + lingkaran->jumlah_perempuan) < MAX_MAHASISWA;
}


bool tambah_mahasiswa(LingkaranApi *lingkaran, char nama[], char jenis_kelamin) {
    
    if (!cek_kapasitas(lingkaran)) {
        printf("Maaf, kapasitas sudah penuh (maksimal 20 orang)\n");
        return false;
    }

    Mahasiswa mhs;
    strncpy(mhs.nama, nama, MAX_NAMA - 1);
    mhs.nama[MAX_NAMA - 1] = '\0';
    mhs.jenis_kelamin = toupper(jenis_kelamin);

    
    if (strcmp(nama, "Cindy") == 0 && lingkaran->jumlah_perempuan == 0) {
        printf("Cindy hanya bisa bergabung jika ada mahasiswi lain\n");
        return false;
    }

    
    if (jenis_kelamin == 'L') {
        lingkaran->mahasiswa_laki[lingkaran->jumlah_laki] = mhs;
        lingkaran->jumlah_laki++;
    } else {
        lingkaran->mahasiswa_perempuan[lingkaran->jumlah_perempuan] = mhs;
        lingkaran->jumlah_perempuan++;
    }
    
    return true;
}


bool hapus_mahasiswa(LingkaranApi *lingkaran, char nama[]) {
    bool ditemukan = false;
    int i, j;
    
    
    for (i = 0; i < lingkaran->jumlah_laki; i++) {
        if (strcmp(lingkaran->mahasiswa_laki[i].nama, nama) == 0) {
            
            for (j = i; j < lingkaran->jumlah_laki - 1; j++) {
                lingkaran->mahasiswa_laki[j] = lingkaran->mahasiswa_laki[j + 1];
            }
            lingkaran->jumlah_laki--;
            ditemukan = true;

            break;
        }
    }
    
    if (!ditemukan) {
        for (i = 0; i < lingkaran->jumlah_perempuan; i++) {
            if (strcmp(lingkaran->mahasiswa_perempuan[i].nama, nama) == 0) {
                
                for (j = i; j < lingkaran->jumlah_perempuan - 1; j++) {
                    lingkaran->mahasiswa_perempuan[j] = lingkaran->mahasiswa_perempuan[j + 1];
                }
                lingkaran->jumlah_perempuan--;
                ditemukan = true;
                
                         
                break;
            }
        }
    }
    
    return ditemukan;
}

void tampilkan_status(struct LingkaranApi *lingkaran) {
    int i;
    printf("\nLingkaran Mahasiswa (Laki-laki):\n");
    for (i = 0; i < lingkaran->jumlah_laki; i++) {
        printf("%d. %s\n", i+1, lingkaran->mahasiswa_laki[i].nama);
    }
    
    printf("\nLingkaran Mahasiswi (Perempuan):\n");
    for (i = 0; i < lingkaran->jumlah_perempuan; i++) {
        printf("%d. %s\n", i+1, lingkaran->mahasiswa_perempuan[i].nama);
    }
    
    printf("\nTotal peserta: %d dari %d maksimal\n", 
           lingkaran->jumlah_laki + lingkaran->jumlah_perempuan, 
           MAX_MAHASISWA);
}

int main() {
    struct LingkaranApi lingkaran;
    lingkaran(&lingkaran);
    char pilihan;
    char nama[MAX_NAMA];
    char jenis_kelamin;

    do {
        printf("\nMenu:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Hapus Mahasiswa\n");
        printf("3. Tampilkan Status\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf(" %c", &pilihan);
        
        switch(pilihan) {
            case '1':
                printf("Masukkan nama: ");
                scanf(" %[^\n]s", nama);
                printf("Masukkan jenis kelamin (L/P): ");
                scanf(" %c", &jenis_kelamin);
                if (tambah_mahasiswa(&lingkaran, nama, jenis_kelamin, -1)) {
                    printf("Berhasil menambahkan %s\n", nama);
                }
                break;
                
            case '2':
                printf("Masukkan nama yang akan dihapus: ");
                scanf(" %[^\n]s", nama);
                if (hapus_mahasiswa(&lingkaran, nama)) {
                    printf("Berhasil menghapus %s\n", nama);
                } else {
                    printf("Mahasiswa tidak ditemukan\n");
                }
                break;
                
            case '3':
                tampilkan_status(&lingkaran);
                break;
                
            case '4':
                printf("Terima kasih!\n");
                break;
                
            default:
                printf("Pilihan tidak valid\n");
        }
    } while (pilihan != '4');

    return 0;
 