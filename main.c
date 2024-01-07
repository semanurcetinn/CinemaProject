#include <stdio.h>

int user_info(int *check, char eposta[], char password[], char name_surname[]){
    
    printf("Hesabiniz varsa 1 yoksa 0 yaziniz:\n");
    //kullanici 1 veya 0 harici bir sey girerse burasi calisir.

    if (scanf("%d",check)!=1 || (*check!=0 && *check!=1 )){
        printf("Lutfen sadece 1 veya 0 giriniz\n");
        return 0; //Hata durumunda 0 dondurur.
    }

    if(*check==1){
        printf("E-posta'yi giriniz:\n");
        scanf("%s",eposta); // char array oldugu icin & kullanilmadi.
        printf("Sifrenizi giriniz:\n");
        scanf("%s",password);
    }
    else{
        printf("Hesap olusturun...\nAdinizi ve soyadinizi giriniz:\n");
        scanf(" %50[^\n]", name_surname); //%s format belirteci bosluklari dikkate almaz, %50[^\n] kulllanildi.
        printf("E-posta'yi giriniz:\n");
        scanf("%s",eposta);
        printf("Sifrenizi giriniz:\n");
        scanf("%s",password);
    }
    return 1;
}

int main(){
	int check = 0;
	char eposta[] = "";
	char password[10] = ""; //max sifre uzunlugu 10 karakter olmali.
	char name_surname[50] = "";
	int film = 0;
	float selected_session = 0;
	int ticket = 0;
	int student = 0;

    user_info(&check, eposta, password, name_surname);

	printf("============\n");

    char movies[3][10] = {"Dune","Totoro","Inception"};
    printf("Filmler:\n");

    for (int i = 0; i < 3; i++){
        printf("%s\n",movies[i]);
        float session[3][3] = {{09.00,15.00,20.00},{09.00,12.00,17.00},{10.00,16.00,20.00}};

        for (int j = 0; j < 3; j++){
            printf("%.2f\n", session[i][j]);
        }
        printf("----------------\n");
    }

	while(1){
		printf("\nSectiginiz filmi yaziniz (1:Dune, 2:Totoro, 3:Inception):");
		scanf("%d",&film);
		if(film>=1 && film<=3){
			break;
		}
		else{
			printf("Lutfen gecerli bir film secimi yapiniz.");
		}
	}

	while(1){
		printf("Seans saatini giriniz:\n");
		scanf("%f",&selected_session);
		if(film==1){
			if(selected_session == 09.00 || selected_session == 15.00 || selected_session == 20.00){
				break;
			}
			else{
				printf("Gecerli bir seans saati giriniz.\n");
			}
		}
		else if(film==2){
			if(selected_session == 09.00 || selected_session == 12.00 || selected_session == 17.00){
				break;
			}
			else{
				printf("Gecerli bir seans saati giriniz.\n");
			}
		}
		else{
			if(selected_session == 10.00 || selected_session == 16.00 || selected_session == 20.00){
				break;
			}
			else{
				printf("Gecerli bir seans saati giriniz.\n");
			}
		}
	}

	switch (film){
		case 1:
			ticket = 100; //Dune icin bilet fiyati
			break;
		case 2:
			ticket = 80; //Totoro filmi icin bilet fiyati
			break;
		case 3:
			ticket = 130; //Inception icin bilet fiyati
			break;
		default:
			printf("Gecerli bir film secimi yapmadiniz.\n");
			return 0;
	}

	printf("Ogrenci misiniz? (1:Evet, 0:Hayir):");
	scanf("%d",&student);

	if (student==1){ //ogrenci ise %40 indirim uygula
		ticket -= ticket*40/100;
		printf("Odemeniz gereken tutar:%d",ticket);
	}
	else{
		printf("Odemeniz gereken tutar:%d",ticket);
	}

	return 0;
}