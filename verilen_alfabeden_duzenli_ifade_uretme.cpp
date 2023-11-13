#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

char alfabedekiElemanlar[10][10], alfabe[100], duzenliIfade[100], duzenliIfadedekiTumElemanlar[10][10], duzenliIfadedekiElemanlar[10][10];
int elemanSayisi=1, kelimeSayisi, yazilanKelime=0;
char cevap[10];
char kelime[10][10]; 
int w=0;

void alfabedekiElemanSayisiniBulma(void){ 
    for(int i=0 ; i<strlen(alfabe) ; i++){
        if(alfabe[i]==','){ 
            elemanSayisi++;  
        }
    }
}

int a=0,b=0;
void duzenliIfadedekiTumElemanlariBelirleme(void){
	for(int i=0 ; i<strlen(duzenliIfade) ; i++){
        if(duzenliIfade[i]=='*'||duzenliIfade[i]=='+'){
        	if(b!=0){
        		b=0;
        		duzenliIfadedekiTumElemanlar[++a][0]=duzenliIfade[i];
        		a++;
			}
			else{
				duzenliIfadedekiTumElemanlar[a++][0]=duzenliIfade[i];
			}
		}
		else{
			duzenliIfadedekiTumElemanlar[a][b++]=duzenliIfade[i];
		}
    }
}

int duzenliIfadedekiElemanSayisi=0, e=0,f=0,max=0;
void duzenliIfadedekiElemanlariBelirleme(void){
	for(int i=0 ; i<strlen(duzenliIfade) ; i++){
        if(duzenliIfade[i]!='*'&&duzenliIfade[i]!='+'&&duzenliIfade[i]!='('&&duzenliIfade[i]!=')'&&duzenliIfade[i]!='['&&duzenliIfade[i]!=']'){
        	duzenliIfadedekiElemanlar[e][f++]=duzenliIfade[i];
        	duzenliIfadedekiElemanSayisi++;
        	if(f>max){
        			max=f;
			}
		}
		else{
			if(f!=0){
	        	f=0;
	        	e++;	
			}
		}
    }
}

int c=0,d=0;
void alfabedekiElemanlariBelirleme(void){
	for(int i=0 ; i<strlen(alfabe) ; i++){
        if(alfabe[i]!=','){
            alfabedekiElemanlar[c][d++]=alfabe[i];
        }
        else{
        	d=0;
        	c++;
        	if(c==elemanSayisi){
        		break;
			}
		}
    }
}
int kelimeUretme(void){
	for(int k=0 ; k<1 ; k++){
		for(int i=0 ; i<1 ; i++){
			if(duzenliIfadedekiTumElemanlar[i+1][0]=='+'){
				if(duzenliIfadedekiTumElemanlar[i+3][0]!='+'&&duzenliIfadedekiTumElemanlar[i+3][0]!='*'){
					printf("Sadece iki kelime uretilebilir.\n");
					printf("%s ve %s\n",duzenliIfadedekiElemanlar[0],duzenliIfadedekiElemanlar[1]);
					printf("\nKontrol edilecek kelimeyi giriniz: ");
					scanf("%s", cevap);
					getchar();
					if(strcmp(cevap,duzenliIfadedekiElemanlar[0])==0||strcmp(cevap,duzenliIfadedekiElemanlar[1])==0){
						printf("Bu kelime L diline aittir.");
					}
					else{
						printf("Bu kelime L diline ait degildir.");
					}
				}
				else if(duzenliIfadedekiTumElemanlar[i+3][0]=='*'){
					char dizi4[10],dizi5[10];
					char dizi1[10];
					int t=0;
					for(int p=0 ; p<10 ; p++){ 
						dizi1[p]=NULL;
						dizi5[p]=NULL;
						if(duzenliIfadedekiTumElemanlar[0][p]!='('&&duzenliIfadedekiTumElemanlar[0][p]!=')'&&duzenliIfadedekiTumElemanlar[0][p]!=NULL){
							dizi1[t++]=duzenliIfadedekiTumElemanlar[0][p];
						}
					}
					t=0;
					char dizi2[10];
					for(int p=0 ; p<10 ; p++){
						dizi2[p]=NULL;
						dizi4[p]=NULL;
						if(duzenliIfadedekiTumElemanlar[2][p]!='('&&duzenliIfadedekiTumElemanlar[2][p]!=')'&&duzenliIfadedekiTumElemanlar[2][p]!=NULL){
							dizi2[t++]=duzenliIfadedekiTumElemanlar[2][p];
						}
					}
					t=0;
					char dizi3[10];
					for(int p=0 ; p<10 ; p++){
						dizi3[p]=NULL;
						if(duzenliIfadedekiTumElemanlar[4][p]!='('&&duzenliIfadedekiTumElemanlar[4][p]!=')'&&duzenliIfadedekiTumElemanlar[4][p]!=NULL){
							dizi3[t++]=duzenliIfadedekiTumElemanlar[4][p];
						}
					}
					
					for(int p=0 ; p<kelimeSayisi ; p++){
						if(p%2==0){
							if(p==0){
								strcpy(kelime[w],dizi3);
								printf("%s",dizi3);
								yazilanKelime++;
								if(yazilanKelime==kelimeSayisi){
									printf("\nKontrol edilecek kelimeyi giriniz: ");
									scanf("%s", cevap);
									getchar();
									for(int i=0 ; i<yazilanKelime ; i++){
										if(strcmp(cevap,kelime[i])==0){
											printf("Bu kelime L diline aittir.");
											return 0;
										}
										else if(strcmp(cevap,kelime[i])!=0&&i==yazilanKelime-1){
											printf("Bu kelime L diline ait degildir.");
											return 0;
										}
									}
									return 0;
								}
							}
							else{
								for(int r=0 ; r<1 ; r++){
									strcat(dizi4,dizi2);
									strcpy(kelime[++w],dizi4);
									strcat(kelime[w],dizi3);
									printf(", %s%s",dizi4,dizi3);
									yazilanKelime++;
									if(yazilanKelime==kelimeSayisi){
									printf("\nKontrol edilecek kelimeyi giriniz: ");
									scanf("%s", cevap);
									getchar();
									for(int i=0 ; i<yazilanKelime ; i++){
										if(strcmp(cevap,kelime[i])==0){
											printf("Bu kelime L diline aittir.");
											return 0;
										}
										else if(strcmp(cevap,kelime[i])!=0&&i==yazilanKelime-1){
											printf("Bu kelime L diline ait degildir.");
											return 0;
										}
									}
									return 0;
									}
								}
							}
						}
						else{
							for(int r=0 ; r<1 ; r++){	
								strcat(dizi5,dizi1);
								strcpy(kelime[++w],dizi5);
								strcat(kelime[w],dizi3);
								printf(", %s%s",dizi5,dizi3);
								yazilanKelime++;
								if(yazilanKelime==kelimeSayisi){
									printf("\nKontrol edilecek kelimeyi giriniz: ");
									scanf("%s", cevap);
									getchar();
									for(int i=0 ; i<yazilanKelime ; i++){
										if(strcmp(cevap,kelime[i])==0){
											printf("Bu kelime L diline aittir.");
											return 0;
										}
										else if(strcmp(cevap,kelime[i])!=0&&i==yazilanKelime-1){
											printf("Bu kelime L diline ait degildir.");
											return 0;
										}
									}
								}
							}
						}
					}
				}
				else if(duzenliIfadedekiTumElemanlar[i+3][0]=='+'){
					char dizi[10][10];
					char dizii[10];
					char geciciDizi[10];
					for(int p=0 ; p<10 ; p++){
						dizii[p]=NULL;
						geciciDizi[p]=NULL;
						for(int t=0 ; t<10 ; t++){
							dizi[p][t]=NULL;
						}
					}
					int o=0,u;
					for(int n=3 ; ; n=n+2){
						if(duzenliIfadedekiTumElemanlar[i+n+2][0]!='+'&&duzenliIfadedekiTumElemanlar[i+n+2][0]!='*'){
							for(int p=0 ; p<10 ; p=p+2){
								u=0;
								for(int t=0 ; t<10 ; t++){
									if(duzenliIfadedekiTumElemanlar[p][t]!='('&&duzenliIfadedekiTumElemanlar[p][t]!=')'&&duzenliIfadedekiTumElemanlar[p][t]!=NULL){
										dizi[o][u]=duzenliIfadedekiTumElemanlar[p][t];
										u++;
									}
								}
								if(u!=0){
									o++;	
								}
							}
							if(kelimeSayisi>o){
								printf("Bu kadar kelime girilen ifadeden uretilemez. Yazilabilecek tum kelimeler geliyor.");
								printf("%s",dizi[0]);
								for(int p=1 ; p<o ; p++){
									printf(", %s",dizi[p]);
								}
							}
							else{
								printf("%s",dizi[0]);
								for(int p=1 ; p<kelimeSayisi ; p++){
									printf(", %s",dizi[p]);
								}
							}
							printf("\nKontrol edilecek kelimeyi giriniz: ");
							scanf("%s", cevap);
							getchar();
							for(int i=0 ; i<kelimeSayisi ; i++){
								if(strcmp(cevap,dizi[i])==0){
									printf("Bu kelime L diline aittir.");
									return 0;
								}
								else if(strcmp(cevap,dizi[i])!=0&&i==kelimeSayisi-1){
									printf("Bu kelime L diline ait degildir.");
									return 0;
								}
							}	
						}
					}	
				}
			}
			else if(duzenliIfadedekiTumElemanlar[i+1][0]=='*'){
				if(duzenliIfadedekiTumElemanlar[i+3][0]!='+'&&duzenliIfadedekiTumElemanlar[i+3][0]!='*'){
					char dizi[10];
					char dizii[10];
					char geciciDizi[10];
					for(int i=0 ; i<10 ; i++){
						dizii[i];
						dizi[i]=NULL;
						geciciDizi[i]=NULL;
					}
					int h=0;
					for(int p=0 ; p<10 ; p++){
						if(duzenliIfadedekiTumElemanlar[0][p]!='('&&duzenliIfadedekiTumElemanlar[0][p]!=')'&&duzenliIfadedekiTumElemanlar[0][p]!=NULL){
							dizi[h++]=duzenliIfadedekiTumElemanlar[0][p];
						}
					}
					h=0;
					for(int p=0 ; p<10 ; p++){
						if(duzenliIfadedekiTumElemanlar[2][p]!='('&&duzenliIfadedekiTumElemanlar[2][p]!=')'&&duzenliIfadedekiTumElemanlar[2][p]!=NULL){
							dizii[h++]=duzenliIfadedekiTumElemanlar[2][p];
						}
					}
					printf("%s, ",dizii);
					strcpy(kelime[0],dizii);
					for(int t=1 ; t<kelimeSayisi ; t++){
						strcat(geciciDizi,dizi);
						strcpy(kelime[t],geciciDizi);
						printf("%s%s, ",geciciDizi,dizii);
					}
					printf("\nKontrol edilecek kelimeyi giriniz: ");
					scanf("%s", cevap);
					getchar();
					for(int i=0 ; i<kelimeSayisi ; i++){
						if(strcmp(cevap,kelime[i])==0){
							printf("Bu kelime L diline aittir.");
							return 0;
						}
						else if(strcmp(cevap,kelime[i])!=0&&i==kelimeSayisi-1){
							printf("Bu kelime L diline ait degildir.");
							return 0;
						}
					}
				}
			}
		}
	}
} 

int kontrolDizisi[10][10];
int kontrolDizisindekiBirSayisi=0;
void kontrolEtme(void){
	for(int i=0 ; i<10 ; i++){
		for(int j=0 ; j<10 ; j++){
			kontrolDizisi[i][j]=0;
		}
	}
	for(int i=0 ; i<duzenliIfadedekiElemanSayisi ; i++){
		for(int j=0 ; j<max+1 ; j++){
			for(int k=0 ; k<c+1 ; k++){
				if(duzenliIfadedekiElemanlar[i][j]==alfabedekiElemanlar[k][0]){
					kontrolDizisi[i][j]=1;
					kontrolDizisindekiBirSayisi++;
				}
			}
		}
	}
	if(kontrolDizisindekiBirSayisi==duzenliIfadedekiElemanSayisi){
		printf("Girilen duzenli ifade girilen alfabeden uretilebilir. Kelimeleriniz listeleniyor...\n");
		kelimeUretme();
	}
	else{
		printf("Girilen duzenli ifade girilen alfabeden uretilemez.");
	}
}

int main(void){
	printf("Alfabeyi giriniz: ");
    scanf("%s", alfabe);
	getchar();
	alfabedekiElemanSayisiniBulma();
    alfabedekiElemanlariBelirleme();
    printf("Duzenli ifadeyi giriniz: ");
	scanf("%s", duzenliIfade);
	getchar();
    duzenliIfadedekiTumElemanlariBelirleme();
    printf("L dilinin kac kelimesini gormek istiyorsunuz: ");
    scanf("%d",&kelimeSayisi);
	getchar();
	duzenliIfadedekiElemanlariBelirleme();
	kontrolEtme();
}
