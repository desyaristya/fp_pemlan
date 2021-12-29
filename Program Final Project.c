#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_first_major;
    int id_user;
	int score_bio;
    int score_fis;
    int score_kim;
    int mean_score;
} Owner;

Owner owners[100];

int load(char* filename)
{
    char buffer[200];
    char token[50];
    Owner* owner;
    int owners_size = 0;
    FILE* file = fopen(filename, "r");

    while(fgets(buffer, 200, file) != NULL)
    {
	    owner = (Owner *)malloc(sizeof(Owner));
	    owner->id_first_major = atoi(strtok(buffer, ","));
	    owner->id_user = atoi(strtok(NULL, ","));
	    owner->score_bio = atoi(strtok(NULL, ","));
	    owner->score_fis = atoi(strtok(NULL, ","));
	    owner->score_kim = atoi(strtok(NULL, ","));
	    owners[owners_size++] = *owner;
    }

    fclose(file);
    return owners_size;
}

void display (char* owners_filename){
	
	int choise, owners_size, index;

	owners_size = load(owners_filename);

    if(owners_size)
    {
        printf("owners size: %d\n\n", owners_size);

        for(index = 0; index < owners_size; index++)
            printf("%d	%d	%d	%d	%d\n",  owners[index].id_first_major, owners[index].id_user,owners[index].score_bio, owners[index].score_fis,owners[index].score_kim);
    }
}

void displayByFilter(char* owners_filename, int rawal, int rakhir){
	int choise, owners_size, index;

	owners_size = load(owners_filename);

    if(owners_size)
    {
        printf("owners size: %d\n\n", owners_size);

        for(index = rawal-1; index < rakhir; index++)
            printf("%d	%d	%d	%d	%d\n",  owners[index].id_first_major, owners[index].id_user,owners[index].score_bio, owners[index].score_fis,owners[index].score_kim);
    }
}

void mean (char* owners_filename, int input_tampil_mean){
	int choise, owners_size, index;

	owners_size = load(owners_filename);
	
	for(index = 0; index < owners_size; index++){
		owners[index].mean_score = (owners[index].score_bio + owners[index].score_fis + owners[index].score_kim) / 3;
		if (owners[index].mean_score == input_tampil_mean){
      		printf("%d	%d	%d	%d	%d	%d\n",  owners[index].id_first_major, owners[index].id_user,owners[index].score_bio, owners[index].score_fis,owners[index].score_kim, owners[index].mean_score);
		}
	}	
}

void sorting (char* owners_filename){
	//selection sort
	int count, temp;
	int choise, owners_size, index;

	owners_size = load(owners_filename);
	
	for(index = 0; index < owners_size; index++){
		for(count = index + 1; count < owners_size; count++){
			if(owners[index].id_first_major > owners[count].id_first_major){
				temp = owners[index].id_first_major;
      			owners[index].id_first_major = owners[count].id_first_major;
        		owners[count].id_first_major = temp;
         	}
      	}
   	}
   	for(index = 0; index < owners_size; index++){
		printf("%d	%d	%d	%d	%d\n",  owners[index].id_first_major, owners[index].id_user,owners[index].score_bio, owners[index].score_fis,owners[index].score_kim);
   	}
}

void search (char* owners_filename, int cari){
	//linear search
	int choise, owners_size, index;

	owners_size = load(owners_filename);
 
	for (index = 0; index < owners_size; index++) {
    	if (owners[index].id_user == cari) {
      		printf("%d	%d	%d	%d	%d\n\n",  owners[index].id_first_major, owners[index].id_user,owners[index].score_bio, owners[index].score_fis,owners[index].score_kim);
      		break;
    	}
  	}
	if (index == owners_size){
    	printf("Peserta dengan id user = %d tidak terdapat dalam data\n\n", cari);
  	}
}

void insert_data(char* owners_filename, char* filename){
    char buffer[200];
    char token[50];
    Owner* owner;
    int owners_size = 0;
    FILE* file = fopen(filename, "a+");

    while(fgets(buffer, 200, file) != NULL)
    {
	    owner = (Owner *)malloc(sizeof(Owner));
	    owner->id_first_major = atoi(strtok(buffer, ","));
	    owner->id_user = atoi(strtok(NULL, ","));
	    owner->score_bio = atoi(strtok(NULL, ","));
	    owner->score_fis = atoi(strtok(NULL, ","));
	    owner->score_kim = atoi(strtok(NULL, ","));
	    owners[owners_size++] = *owner;
    }

	printf("\nMasukkan id major : \n");
    scanf("%d", &owners[owners_size+1].id_first_major);
	printf("\nMasukkan id user : \n");
    scanf("%d", &owners[owners_size+1].id_user);
	printf("\nMasukkan score bio : \n");
    scanf("%d", &owners[owners_size+1].score_bio);
	printf("\nMasukkan score fis : \n");
    scanf("%d", &owners[owners_size+1].score_fis);
	printf("\nMasukkan score kim : \n");
    scanf("%d", &owners[owners_size+1].score_kim);

    fprintf(file, "\n%d, %d, %d, %d, %d", owners[owners_size+1].id_first_major, owners[owners_size+1].id_user, owners[owners_size+1].score_bio, owners[owners_size+1].score_fis, owners[owners_size+1].score_kim);
  
    printf("\nData baru telah ditambahkan");
  
	fclose(file);
}


int main()
{
    char* owners_filename = "SCIENCE.txt";
    int menu;
    int rawal, rakhir, input_tampil_mean, cari;
    do{
	    printf("DATA PESERTA UTBK\n");
	    printf("==================================================\n");
	    printf("1. Display Data Peserta\n");
	    printf("2. Display Data Peserta dengan Filter\n");
	    printf("3. Hitung Rata-Rata Score Peserta\n");
	    printf("4. Sorting\n");
	    printf("5. Searching\n");
	    printf("6. Masukkan Data Peserta Baru\n");
//	    printf("7. Edit Informasi Peserta\n");
//	    printf("8. Hapus Data Peserta\n");
        
		printf("\nPilih Opsi di Atas : ");
        scanf("%d",&menu);
        switch(menu){
        case 1:
            display(owners_filename);
            break;
        case 2:
			printf("Masukkan Range Awal : ");
    		scanf("%d",&rawal);
    		printf("Masukkan Range Akhir : ");
    		scanf("%d",&rakhir);
    
    		displayByFilter(owners_filename, rawal, rakhir);
            break;
        case 3:
            printf("Masukkan Rata-Rata Score Peserta : ");
			scanf("%d", &input_tampil_mean);
			
			mean(owners_filename, input_tampil_mean);
            break;
        case 4:
            sorting(owners_filename);
        	break;
        case 5:
            printf("Input Id User Peserta yang Ingin Dicari: ");
			scanf("%d", &cari);
			
			search(owners_filename, cari);
        	break;
        case 6:
            insert_data(owners_filename, owners_filename);
        	break;
//        case 7:
//            update();
//        	break;
//        case 8:
//            delete();
//            break;
        }
    }while(menu!=0);

    return 0;
}
