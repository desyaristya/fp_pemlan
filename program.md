# fp_pemlan
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int addData(){
    FILE* fp = fopen("D://FP Pemlan/universities.csv", "a+");
  
    int Sno;
    int id_first_major;
    int id_first_university;
    int id_second_major;
    int id_second_university;
    int id_user;
    int score_bio;
    int score_fis;
    int score_kim;
    int score_kmb;
    int score_kpu;
    int score_kua;
    int score_mat;
    int score_ppu;
  
    if (!fp) {
        // untuk mengetahui bahwa file tidak bisa dideteksi
        printf("File tidak terdeteksi\n");
        return 0;
    }
  
    // diMeminta untuk memasukan pengguna 
    // pada rekor baru yang akan ditambahkan
    printf("\nEnter No Id\n");
    scanf("%d", &Sno);
    printf("\nEnter id first major\n");
    scanf("%d", &id_first_major);
    printf("\nEnter id_first_university\n");
    scanf("%d", &id_first_university);

    printf("\nEnter id_second_major\n");
    scanf("%d", &id_second_major);
    printf("\nEnter id_second_university\n");
    scanf("%d", &id_second_university);
    printf("\nEnter id_user\n");
    scanf("%d", &id_user);

    printf("\nEnter score_bio\n");
    scanf("%d", &score_bio);
    printf("\nEnter score_fis\n");
    scanf("%d", &score_fis);
    printf("\nEnter score_kim\n");
    scanf("%d", &score_kim);

    printf("\nEnter score_kmb\n");
    scanf("%d", &score_kmb);
    printf("\nEnter score_kpu\n");
    scanf("%d", &score_kpu);
    printf("\nEnter score_kua\n");
    scanf("%d", &score_kua);

    printf("\nEnter score_mat\n");
    scanf("%d", &score_mat);
    printf("\nEnter score_ppu\n");
    scanf("%d", &score_ppu);

  
    // untuk Menyimpan data dalam file
    fprintf(fp, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", Sno, id_first_major, id_first_university, id_second_major, id_second_university, id_user, score_bio, score_fis, score_kim, score_kmb, score_kpu, score_kua, score_mat, score_ppu);
  
    printf("\nAkun baru ditambahkan ke catatan");
  
    fclose(fp);
    return 0;
}

int readData(){
    FILE* fp = fopen("D://FP Pemlan/universities.csv","r");
  
    if (!fp)
        printf("file tidak terdeteksi\n");
  
    else {
        // Di sini kami telah mengambil ukuran
        // array 1024 Anda dapat memodifikasinya
        char buffer[1024];
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // Untuk menghindari pencetakan kolom
            // nama dalam file dapat diubah
            // yang sesuai dengan kebutuhan
            if (row == 1)
                continue;
  
            // untuk memisahkan data
            char* value = strtok(buffer, ", ");
  
            while (value) {
                
  
                printf("%-8s", value);
                value = strtok(NULL, ", ");
                column++;
            }
  
            printf("\n");
        }
  
        // untuk menutup file
        fclose(fp);
    }
    return 0;
}

int deleteData(){
     FILE *fRead, *fWrite;
    char *TextFile;
    char c;
    int Delete_Id, temp = 1;

    TextFile="D://FP Pemlan/universities.csv";

    fRead = fopen(TextFile, "r");
    c = getc(fRead);

    while (c != EOF){
    printf("%c", c);
    c = getc(fRead); 
    }

    rewind(fRead);

    printf("\nHapus data ke- : ");
    scanf("%d", &Delete_Id);

    Delete_Id=Delete_Id+1;

    fWrite = fopen("D://FP Pemlan/universities.csv", "w");
    c = getc(fRead);
    while (c != EOF) {
    c = getc(fRead);
    if (c == '\n')
    temp++;
    if (temp != Delete_Id){
    putc(c, fWrite); 
       } 
    }

    fclose(fRead);
    fclose(fWrite);

    remove(TextFile);

    rename("D://FP Pemlan/universities.csv", TextFile);
    printf("\nBerikut File yang telah dimodifikasi:\n");

    fRead = fopen(TextFile, "r");
    c = getc(fRead);
    while (c != EOF) {
    printf("%c", c);
    c = getc(fRead);
    }

    fclose(fRead);
}

int searching(){
      int num =0;
        char word[2000];
        char string[50];
        char student[100] = {0};

        while(student[0]!= '0')
        {
                FILE *in_file = fopen("D://FP Pemlan/universities.csv", "r");
                if (in_file == NULL)
                {
                        printf("Error file missing\n");
                        exit(-1);
                }

                printf("silahkan pilih 1 kata (jika anda memilih 0 maka program selesai)\n");
                scanf("%s", student);
                while ( fscanf(in_file,"%s", string) == 1)
                {
                        //Tambahkan loop for sampai strstr(string, student) tidak-mengembalikan null. 
                        if(strstr(string, student)!=0) {//if match found
                                num++;
                        }
                }
                printf("kami telah menemukan kata %s pada file %d times\n",student,num );
                num = 0;
                fclose(in_file);
        }
        return 0;
}
int inputMenu()
{
    int number;
    scanf("%d", &number);
    return (number);
}
int main(){
    int choice;
        while(1){
        	printf ("pilih menu dibawah ini:\n");
        printf("1. menampilkan data \n");
        printf("2. memasukkan data peserta baru\n");
        printf("3. hapus data peserta\n");
        printf("4. searching\n");
        printf("0. Exit\n");
        printf("Enter your choice:\n");
        choice = inputMenu();
        
        switch (choice) {
            case 1: {
                readData();
                break;
            }
            case 2: {
                addData();
                break;
            }
            case 3: {
                deleteData();
                break;
            }
            case 4: {
                searching();
            }
            case 0: {
                printf("\n\n\t\t\tTerimakasih:) !\n\n\n");
                exit(0);
       
            }
            default:
                printf("Anda salah memasukkan pilihan\n");
                printf("mohon pilih Kembali\n");
        }
        }
        
}
