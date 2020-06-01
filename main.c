#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

FILE * ifp;

typedef struct mahasiswaODP{
	int nim;
	char nama[30];
	char universitas[50];
	char perjalanan[30];
}ODP;

ODP check, tambah, hapus;
//deklarasi prototype fungsi
int option();
void operasi();
void tampil_data();
void cari_data();
void tambah_data();
void hapus_data();
void edit_data();

int main(){
	//proses login
	system("cls");
    char user[10], pass[10], temp[30];
    ifp = fopen("login.bin","wb");

    printf("\t=========BERITA SEPUTAR COVID19 TERUPDATE==========\n\n");
    do{ 
      printf("LOGIN PORTAL \n"); 
      printf("Username : "); 
      scanf ("%s", user); 

      printf("Password : "); 
      scanf("%s", pass); 

      if ((strcmp(user,"admin")!=0) || (strcmp(pass,"root")!=0)) 
	   printf("Status Login Gagal\n\n"); 
  	
    }while((strcmp(user,"admin")!=0) || (strcmp(pass,"root")!=0)); 

    printf("Status Login Berhasil\n\n");
    printf("\t========= SELAMAT DATANG ADMIN =========\n");
    printf("\t\t\t   DI");
    printf("\n\t\tBERITA COVID19 TERUPDATE\n\n");

    strcpy(temp,user);//memindahkan isi dari variabel user ke variabel temp
    strcat(temp,pass);//menggabungkan isi dari variabel pass ke isi di variabel temp

    fprintf(ifp, "%s", temp);
    fclose(ifp);

    option();
    operasi();
    return 0;
}

int option(){
	int pilihan;
	printf("\n\nMenu :");
	printf("\n1. Tampilkan Data Mahasiswa yang ODP Covid19 di Banda Aceh");
	printf("\n2. Cari Data Mahasiswa yang ODP Covid19 di Banda Aceh");
	printf("\n3. tambah Data Mahasiswa yang ODP Covid19 di Banda Aceh");
	printf("\n4. Hapus Data Mahasiswa yang ODP Covid19 di Banda Aceh");
	printf("\n5. Ubah Data Mahasiswa yang ODP Covid19 di Banda Aceh");
	printf("\n6. Keluar");
	printf("\n==========================================================");
	printf("\n\n Pilihan : ");
	scanf("%d", &pilihan);

	return pilihan;
}

void operasi(){
	//untuk memanggil fungsi fungsinya sesuai dengan apa yang telah di input oleh user
	int menu = option();
	switch (menu){
    case 1: tampil_data();
        break;
    case 2: cari_data();
        break;
    case 3: tambah_data();
        break;
    case 4: hapus_data();
    	break;
    case 5: edit_data();
    	break;
    case 6:
    	return;
        break;
    default:
        printf("Pilihan tidak ada,silahkan ulang\n");
      option();
    }
}

void tampil_data(){
	ifp = fopen("data.txt","r");

	int test=0;
	system ("cls");//agar ketika program dimulai dari awal cmd
	printf ("Nim,Nama,Universitas.Riwayat Perjalanan\n");
	while (fscanf (ifp,"%d;%[^;];%[^;];%[^;]\n",&tambah.nim, &tambah.nama, &tambah.universitas,&tambah.perjalanan)!=EOF)//membaca isi file selama bukan end of file
	{
		printf("%d\t%s\t%s\t%s\n",tambah.nim,tambah.nama,tambah.universitas,tambah.perjalanan);// mencetak ke layar monitor 
		test++;
	}
	printf ("\nJumlah Data Mahasiswa : %d",test);
	fclose(ifp);
	
	if(test==0)//apabila tidak ada looping yang terjadi artinya test == 0 maka akan dicetak data kosong
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
	//menampilkan pilihan apakah user ingin keluar dari program atau ingin melanjutkan, jika ingin melanjutkan maka user akan diarahkan ke fungsi operasi()
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': operasi();
        	break;
        case '0': 
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;//apabila user memasukkan input selain 1 dan 0 maka user akan di arah kan ke bagian list_invalid
 	}
}

void cari_data()
{
	int test=0;
	system("cls");
	ifp=fopen("data.txt","r");
	system("cls");
	printf("Input nim Mahasiswa : ");

	fclose(ifp);
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData tidak ditemukan !");
		detail_invalid:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': cari_data();
            	break;
            case '1': operasi();
            	break;
            case '2': 
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': operasi();
       			break;
       		case '0':
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto detail_valid;
       	}	
    }	
	
}

void tambah_data(){
	FILE *ofp;
	int count=0;
	
	ifp =fopen("mahasiswa.txt","a");
		system("cls");
		ofp =fopen("mahasiswa.txt","r");
		while (fscanf (ofp,"%d;%[^;];%[^;];%[^;]\n",&tambah.nim,tambah.nama,tambah.universitas,&tambah.perjalanan)!=EOF)
		{
			tambah.nim++;	
		}
		check.nim = tambah.nim;//semua data yang ada pada variabel tambah.nim dipindahkan ke check.nim untuk nantinya digunakan pada proses mengubah data
		fclose(ofp);
		printf ("Nim : ");
		fflush(stdin);
		scanf ("%d",tambah.nim);
		printf ("Nama : ");
		fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("universitas : ");
		fflush(stdin);
		scanf ("%[^\n]",tambah.universitas);
		printf ("Riwayat Perjalanan: ");
		fflush(stdin);
		scanf ("%d",&tambah.perjalanan); 
	
		fprintf(ifp,"%d;%s;%s;%s\n",tambah.nim,tambah.nama,tambah.universitas,tambah.perjalanan);
		fclose(ifp);
	
		printf("\n\nData Mahasiswa Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': operasi();
        		break;
        	case '0':
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void hapus_data(){
	FILE *lama, *baru;
	int test=0;

	lama = fopen("data.txt","r");
	baru = fopen("baru.txt","w");//agar nantinya pada saat akan dihapus, datanya akan dipindahkan ke file yang baru terlebih dahulu
	system("cls");
	printf("Input Nim Mahasiswa yang akan di hapus : ");
	scanf("%d", &hapus.nim);
	while(fscanf (lama,"%d;%[^;];%[^;];%[^;]\n",&tambah.nim,&tambah.nama,&tambah.universitas,&tambah.perjalanan)!=EOF)
	{
		if(tambah.nim != hapus.nim)
		{
			fprintf(baru,"%d;%s;%s;%s\n",tambah.nim,tambah.nama,tambah.universitas,tambah.perjalanan);	
		}
		else{
			test++;
			printf("\nData Mahasiswa nim : %d dengan Nama : %s\n",tambah.nim,tambah.nama);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("data.txt");//file data.txt yang sebelumnya telah dipindahkan seluruh isinya ke file baru.txt akan dihapus
	rename("baru.txt","data.txt");//file baru.txt direname menjadi data.txt
		if(test==0){
            printf("\nData tidak ditemukan !");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_data();
            		break;
            	case '1': operasi();
            		break;
            	case '2':
            		break;
            	default:
            		printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': operasi();
       			break;
       		case '0':
       			break;
       		default:
       			printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
	
}

void edit_data(){
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("data.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");
	
	printf ("Masukan ID Mahasiswa : ");
	scanf ("%d",&check.nim);
	while(fscanf (lama,"%d;%[^;];%[^;];%[^;]\n",&tambah.nim,&tambah.nama,&tambah.universitas,&tambah.perjalanan)!=EOF)
	{
		if(tambah.nim == check.nim)
		{
			test=1;
			ganti:
				printf("\nNim : %d dimiliki Mahasiswa dengan Nama : %s",tambah.nim,tambah.nama);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Nama");//menyajikan menu yang ingin dihapus
				printf("\n[2]. Universitas");
				printf("\n[3]. Riwayat Perjalanan");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				
				if(pilih == 1)
				{
					printf ("\nMasukan Data Nama Baru : ");fflush(stdin);
					scanf ("%[^\n]",check.nama);
					strcpy(tambah.nama,check.nama);
						fprintf(baru,"%d;%s;%s;%s\n",tambah.nim,tambah.nama,tambah.universitas,tambah.perjalanan);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data Universitas : ");fflush(stdin);
					scanf ("%[^\n]",check.universitas);
					strcpy(tambah.universitas,check.universitas);
						fprintf(baru,"%d;%s;%s;%s\n",tambah.nim,tambah.nama,tambah.universitas,tambah.perjalanan);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Data Riwayat Perjalanan terbaru : ");
					scanf ("%d",&check.perjalanan);
					strcpy(tambah.perjalanan,check.perjalanan);
					fprintf(baru,"%d;%s;%s;%s\n",tambah.nim,tambah.nama,tambah.universitas,tambah.perjalanan);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru,"%d;%s;%s;%s\n",tambah.nim,tambah.nama,tambah.universitas,tambah.perjalanan);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("data.txt");
	rename("baru.txt","data.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_data();
            	break;
            case '1': operasi();
            	break;
            case '2':
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': operasi();
        		break;
        	case '0':
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}
