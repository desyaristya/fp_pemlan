#include<stdio.h>
#include<string.h>

#define MAXCHAR 1000

typedef enum { false, true } boolean;

int main(){

    FILE *fp;
    char row[MAXCHAR];

    fp = fopen("score_science.csv","r");
    
    while(feof(fp) != true){
        fgets(row, MAXCHAR, fp);
		printf("%s", row);
    }
    
    int menu;
	boolean a = true;
    
    while (a){
    	system("cls");
	    printf("1. Display Data Peserta\n");
		printf("2. Display Data Peserta dengan Filter\n");
	    printf("3. Edit Informasi Peserta\n");
	    printf("4. Hapus Data Peserta\n");
	    printf("5. Masukkan Data Peserta Baru\n");
	    printf("6. Cek Peluang Lolos Peserta\n");
	    printf("7. Searching\n");
	    printf("8. Sorting\n");
	    printf("Pilih Menu di Atas: ");
	    scanf("%d", &menu);
		
//		switch(menu){
//			case 1 :
//				display();
//        		break;
//        	case 2 :
//				filter();
//				break;
//			case 3 :
//				edit();
//				break;
//			case 4 :
//				hapus();
//				break;
//			case 5 :
//				baru();
//				break;
//			case 6 :
//				peluang();
//				break;
//			case 7 :
//				search();
//				break;
//			case 8 :
//				sort();
//				break;
//    	}
	}

    return 0;
}
