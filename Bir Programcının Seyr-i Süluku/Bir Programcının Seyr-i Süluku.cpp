/*****************************************************BÝSMÝLLAH*********************************************************************
Cevvad-ý Mutlak (Celle Celaluhu), her ferd-i zîhayatýn eline lezzet midadýyla ve ihtiyaç mürekkebiyle yazýlmýþ bir tezkereyi vermiþ. 
				Onunla evamir-i tekviniyenin proðramýný ve hizmetlerinin fihristesini tevdi' etmiþtir*/
				
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>


short i,j,x,y;
short hakikatler[11], boslar[500];
char boyut, zorluk, renk ,onay, *rnk;
short *byt, *vrt, *jkr_a,  *jkr_k, *hl, *e, *k, *ziyaret;

void kareac(char **arazi, short **yeralti, short x, short y);
short kontrol(short a, short b, short s);
short boslara_bak_sag(char **arazi, short **yeralti, short x, short y, short s);
short boslara_bak_sol(char **arazi, short **yeralti, short x, short y, short s);
void yeni_oyun(char **arazi, short **yeralti);
short mayinsay(short **yeralti, short x, short y);
void ana_menu(char **arazi);
void menu_1(char **arazi);
void menu_2(char **arazi);
void yolun_sonu(char **arazi);
void tablo_ayar(char boyut);
void zorluk_ayar(char zorluk);
void renk_ayar(char *rnk);
short ayarlar();
char *harf_duzelt(char metin[1000]);
char *harf_duzelt_D(char metin[1000]);
void ipuclar();
void kurallar();
void hileler(short **yeralti, char **arazi);
void hikaye_5();
void mucizeler();
void hakikat_1();
void hakikat_2();
void hakikat_3();
void hakikat_4();
void hakikat_5();
void hakikat_6();
void hakikat_7();
void hakikat_8();
void hakikat_9();
void hakikat_10();


int main()
{	
	short *yeralti[10];
	char *arazi[10];
	char gecici,secim,secim1,islem_1,islem_2;
	short s;
	
	ziyaret=(short*)calloc(1,sizeof(short));
	e=(short*)calloc(1,sizeof(short));
	k=(short*)calloc(1,sizeof(short));
	byt=(short*)malloc(1*sizeof(short));
	vrt=(short*)malloc(1*sizeof(short));
	jkr_a=(short*)malloc(1*sizeof(short));
	jkr_k=(short*)malloc(1*sizeof(short));
	hl=(short*)calloc(1,sizeof(short));
	
	system("color 37");
	
	*byt=10;		*vrt=15;		*ziyaret=0;
	
	
	bastan_basla:		//							<<------------------------------------------- BASTAN_BASLA
	
	
	srand(time(NULL));
	rnk=&renk;
	short okunan_hakikat=0;
	
	
	short mayin_tablo[10][*byt]={0};
	char tablo[10][*byt]={0};
	
	for(i=0;i<10;i++)
		yeralti[i]=mayin_tablo[i];
		
	for(i=0;i<10;i++)
		arazi[i]=tablo[i];
		
	yeni_oyun(arazi,yeralti);
	
	
	while(secim!='0' & secim!=27)
	{
		system("cls");
		ana_menu(arazi);
		
		secim=getch();
		switch(secim)
		{
			case '1':
				
				while(true)
				{
					system("cls");
					menu_1(arazi);
					
					
					islem1:		//							<<----------------------------------- ÝSLEM 1
					
					
					islem_1=getche();
						
					if(islem_1=='0' || islem_1==27)		break;
					else if(islem_1=='p' || islem_1=='P')
					{
						short s=0;
						for(i=0;i<10;i++)
							for(j=0;j<*byt&s<150;j++)
								if(yeralti[i][j]!=136 && arazi[i][j]==-79 && arazi[i][j]!=-78)
								{
									if(yeralti[i][j]==0)	arazi[i][j]=' ';
									else					arazi[i][j]=yeralti[i][j]+48;
									s++;
								}
						continue;
					}
					else if(islem_1=='y' || islem_1=='Y')
					{
						yeni_oyun(arazi,yeralti);
						break;
					}
					else if(islem_1=='i' || islem_1==-104)
					{
						printf("\b");
						ipuclar();
						goto islem1;
					}
					else if(islem_1=='h' || islem_1=='H')
					{
						if(*jkr_a==0)
						{
							printf("\b  \aHimmet alma hakk%cn%cz bitti!",141,141);
							goto islem1;
						}
						else
						{
							s=0;
							while(true)
							{
								x=rand()%10;		y=rand()%*byt;
								if(yeralti[x][y]!=136 && arazi[x][y]==-79 && arazi[x][y]!=-78)
								{
									if(yeralti[x][y]==0)	arazi[x][y]=' ';
									else					arazi[x][y]=yeralti[x][y]+48;
									*jkr_a-=1;
									break;
								}
								if(s==300)	{	printf("\b \aSan%cr%cm a%c%clacak kap%c kalmad%c",141,141,135,141,141,141);	goto islem1;	}
								s++;
							}
							
							for(i=0,s=0;i<10;i++)
								for(j=0;j<*byt;j++)
									if(arazi[i][j]!=-79 && arazi[i][j]!=-78)
										s++;
							
							if(s==*byt*10-*vrt)
							{
								system("cls");
								system("color 57");
								printf("\n");
									for(i=0;i<*byt/2;i++)
										printf("   ");
								printf("   (: TEBR%cKLER! BA%cARDINIZ! :)",152,158);
								PlaySoundA("Müzikler/Sürur.wav",NULL,SND_ASYNC);
								goto win;
							}
							
							system("cls");
							menu_1(arazi);
							for(i=-2;i<*byt/2;i++)
								printf("   ");
							printf("%d-%d Kap%cs%c a%c%cld%c\n",x+1,y+1,141,141,135,141,141);
							goto islem1;
						}
					}
					else if(islem_1>'0' && islem_1<='9')
					{
						gecici=getche();
						
						if(gecici>='0' && gecici<='9')
							x=(islem_1-48)*10+gecici-48;
						else if(gecici==27)		break;
						else	x=islem_1-48;	
					}
					else	continue;
					
					printf("\n");
					
					islem_2=getche();
					
					if(islem_2==13 || islem_2==' ')
						islem_2=getche();
					if(islem_2>='0' && islem_2<='9')
					{
						gecici=getche();
						
						if(gecici>='0' && gecici<='9')
							y=(islem_2-48)*10+gecici-48;
						else if(gecici==27)		break;
						else	y=islem_2-48;
					}
					else	continue;
					
					
					if(x<=10 && x>0 && y<=*byt && y>0)
					{
						if(arazi[x-1][y-1]==-78 || arazi[x-1][y-1]=='?')
						{
							printf("\a\t\t%cnce kilitli kap%c%y%c a%c%cn%cz!\n",153,141,141,135,141,141);
							goto islem1;
						}
						if(yeralti[x-1][y-1]==136)
						{
							arazi[x-1][y-1]=yeralti[x-1][y-1]+48;
							
							
							lose:		//							<<---------------------------------- LOSE
							
							
							system("cls");
							system("color 7");
							printf("\n");
							for(i=0;i<*byt/2;i++)
								printf("   ");
							printf("  :(   _VARTAYA D%c%cT%cN%cZ_   ):",154,158,154,154);
							PlaySoundA("Müzikler/Yakma Yarabbi.wav",NULL,SND_ASYNC);
							
							
							win:		//							<<----------------------------------- WÝN
							
							
							yolun_sonu(arazi);
							secim1=getch();
							if(secim1=='1' || secim1=='H' || secim1=='h')
							{
								for(i=0;i<10;i++)
									for(j=0;j<*byt;j++)
									{
										if(yeralti[i][j]==0)
											arazi[i][j]=' ';
										else
											arazi[i][j]=yeralti[i][j]+48;
									}
								system("cls");
								printf("\n");
								goto win;
							}
							else if(secim1=='0' || secim1==27)
								goto out;
							else
							{
								renk_ayar(rnk);
								yeni_oyun(arazi,yeralti);
								break;
							}
							goto lose;
							
						}
						else if(yeralti[x-1][y-1]==0)
						{
							for(i=0;i<80;i++)
								boslar[i]=-1;
							arazi[x-1][y-1]=' ';
							*e=0;			*k=0;			s=0;
							boslar[s]=x-1;		boslar[s+1]=y-1;		s+=2;
							boslara_bak_sag(arazi,yeralti,x-1,y-1,s);
							
							*e=0;			*k=0;			s=0;
							boslar[s]=x-1;		boslar[s+1]=y-1;		s+=2;
							boslara_bak_sol(arazi,yeralti,x-1,y-1,s);				
						}
						else
							arazi[x-1][y-1]=yeralti[x-1][y-1]+48;	
						
					}
					else
					{
						printf("\a\nS%cn%crlar%c a%cmayan de%cerler giriniz!\n",141,141,141,159,167);
						goto islem1;
					}
					
					
					for(i=0,x=0;i<10;i++)
						for(j=0;j<*byt;j++)
							if(arazi[i][j]!=-79 && arazi[i][j]!=-78)
								x++;
					
					if(x==*byt*10-*vrt)
					{
						system("cls");
						system("color 57");
						printf("\n");
							for(i=0;i<*byt/2;i++)
								printf("   ");
						printf("   (: TEBR%cKLER! BA%cARDINIZ! :)",152,158);
						PlaySoundA("Müzikler/Sürur.wav",NULL,SND_ASYNC);
						goto win;
					}
					
				}
				break;
				
			case '2':
				while(true)
				{
					system("cls");
					menu_2(arazi);
					
					
					islem2:		//							<<--------------------------------------- ÝSLEM 2
					
					
					secim1=getch();
					
					if(secim1=='1' || secim1=='k' || secim1=='K' || secim1=='2' || secim1==-98 || secim1==-97)
					{
						while(true)
						{
							if(secim1=='1' || secim1=='k' || secim1=='K')
								printf("%c--->\n Vartal%c kap%cy%c kilitleyiniz:  x=",secim1,141,141,141);
							else if(secim1=='2' || secim1==-98 || secim1==-97)
								printf("%c--->\n Hangisinden %c%cpheleniyorsun:  x=",secim1,159,129);
							
							islem_1=getche();
						
							if(islem_1=='0' || islem_1==27)		break;
							else if(islem_1>'0' && islem_1<='9')
							{
								gecici=getche();
						
								if(gecici>='0' && gecici<='9')
									x=(islem_1-48)*10+gecici-48;
								else if(gecici==27)		break;
								else if(gecici==13)		{	x=islem_1-48;		printf("\t\t\t\t\t\b\b\b\b\b\b");		}
								else	x=islem_1-48;
							}
							else	{	printf("\n");	continue;	}
							
							printf(" ");
							if(gecici==' ')	{	printf("\b");	}
							printf("y=");
							
							islem_2=getche();
					
							if(islem_2==13 || islem_2==' ')
								islem_2=getche();
							if(islem_2>='0' && islem_2<='9')
							{
								gecici=getche();
						
								if(gecici>='0' && gecici<='9')
									y=(islem_2-48)*10+gecici-48;
								else if(gecici==27)		break;
								else	y=islem_2-48;
							}
							else if(islem_2==27)	break;
							else	continue;
							
							if(x<=10 && x>0 && y<=*byt && y>0)
							{
								if(secim1=='1' || secim1=='k' || secim1=='K')
									{
										if(arazi[x-1][y-1]==-78)
											arazi[x-1][y-1]=177;
										else
											arazi[x-1][y-1]=178;
									}
								else if(secim1=='2' || secim1==-98 || secim1==-97)
									{
										if(arazi[x-1][y-1]=='?')
											arazi[x-1][y-1]=177;
										else if(arazi[x-1][y-1]!=-78)
											arazi[x-1][y-1]='?';
										else
										{
											if(gecici==13)
												printf("\a\t\t\t\t\t%cnce kilitli kap%c%y%c a%c%cn%cz!\n",153,141,141,135,141,141);
											else
												printf("\a\t%cnce kilitli kap%c%y%c a%c%cn%cz!\n",153,141,141,135,141,141);
											continue;
										}
									}
									system("cls");
									menu_2(arazi);
									continue;
							}
							else	printf("\a\nS%cn%crlar%c a%cmayan de%cerler giriniz!\n",141,141,141,159,167);
						}
					}
					else if(secim1=='h' || secim1=='H' || secim1=='3')
					{
						if(*jkr_k==0)
						{
							printf("  \aHimmetsiz kald%cn%cz!",141,141);
							goto islem2;
						}
						else
						{
							s=0;
							while(true)
							{
								x=rand()%10;		y=rand()%*byt;
								if(yeralti[x][y]==136 && arazi[x][y]!=-78)
								{		arazi[x][y]=178;		break;		}
								if(s==300)	{	printf(" \aSan%cr%cm kilitlenecek kap%c kalmad%c",141,141,141,141);	goto islem2;	}
								s++;
							}
							(*jkr_k)--;
							system("cls");
							menu_2(arazi);
							for(i=-2;i<*byt/2;i++)
								printf("   ");
							printf("%d-%d Vartal%c Kap%c Kapat%cld%c\n",x+1,y+1,141,141,141,141);
							goto islem2;
						}
					}
					else if(secim1=='0' || secim1==27)
						break;
				}
				break;
			
			case '3':
				x=ayarlar();
				if(x==1)
					goto bastan_basla;
				else
					break;
			
			case '4':
				system("cls");
				kurallar();
				break;
			
			case '5':
				
				for(i=okunan_hakikat;i<11;i++)
				{
					switch(hakikatler[i])
					{
						case 0:system("cls");	mucizeler();		break;
						case 1:system("cls");	hakikat_1();		break;
						case 2:system("cls");	hakikat_2();		break;
						case 3:system("cls");	hakikat_3();		break;
						case 4:system("cls");	hakikat_4();		break;
						case 5:system("cls");	hakikat_5();		break;
						case 6:system("cls");	hakikat_6();		break;
						case 7:system("cls");	hakikat_7();		break;
						case 8:system("cls");	hakikat_8();		break;
						case 9:system("cls");	hakikat_9();		break;
						case 10:system("cls");	hakikat_10();		break;
						default:	getch();
					}
					okunan_hakikat++;
					if(okunan_hakikat==11)	okunan_hakikat=0;
					break;
				}
				break;
			
			case '"':
				hileler(yeralti,arazi);				
				break;
				
			default: 
				if(secim=='0' || secim==27)
				{
					printf("\t\t\t\t\t%cIKMAK %cSTED%c%c%cN%cZE EM%cN M%cS%cN%cZ?\n",128,152,152,166,152,152,152,152,152,152);
					
					printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
					printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
					printf("\t\t\t%c EVET = ENTER %c\t\t\t\t%c HAYIR = ESC %c\n",186,186,186,186);
					printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
					printf("\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
					
					secim=getch();
					if(secim=='0' || secim==27)
						secim='1';
					else if(secim=13)
						secim=27;
				}break;
		}
		
	}
	
	
	out:		//							<<---------------------------------------------------------- OUT
		
	
	system("cls");
	printf("\n\n\n\n\n************************************\t\t\t\t\t\t     ***********************************");
	printf("\n\n\n\n\t\t\tM%cCADELE-%c NEF%cSTE ve %cBADETTE ve HAKA%cK-%c %cMAN%cYEN%cN %cNK%c%cAFINDA BOL NAS%cPLER\n\n\n\n",154,152,152,152,152,152,152,152,152,152,152,158,152);
	printf("\n************************************\t\t\t\t\t\t     ***********************************\n\n\n");
	printf("\n\t\t\t\t\t\t   By Aziz-%cl Azazat\n",129);	

	free(byt);
	free(vrt);
	free(jkr_a);
	free(jkr_k);
	free(hl);
	free(e);
	free(k);
	free(ziyaret);	
	getch();
	return 0;
}


short kontrol(short a, short b, short s)		//Bu kareye daha önce uðrayýp uðramadýðýmýzý kontrol ediyor
{
	for(i=0;i<s;i+=2)
		if(boslar[i]==a && boslar[i+1]==b)
			return 0;
	return 1;
}

short boslara_bak_sag(char **arazi, short **yeralti, short x, short y, short s)
{
	kareac(arazi,yeralti,x,y);
	if(x-1>=0 && y-1>=0)
		if(yeralti[x-1][y-1]==0)
		{
			kareac(arazi,yeralti,x-1,y-1);
			if(kontrol(x-1,y-1,s)==1)
			{
				boslar[s]=x-1;		boslar[s+1]=y-1;		s+=2;					//Gittiðimiz kareleri diziye alýyoruz.
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x-1>=0)
		if(yeralti[x-1][y]==0)
		{
			kareac(arazi,yeralti,x-1,y);
			if(kontrol(x-1,y,s)==1)
			{
				boslar[s]=x-1;		boslar[s+1]=y;			s+=2;
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x-1>=0 && y+1<*byt)
		if(yeralti[x-1][y+1]==0)
		{
			kareac(arazi,yeralti,x-1,y+1);
			if(kontrol(x-1,y+1,s)==1)
			{
				boslar[s]=x-1;		boslar[s+1]=y+1;		s+=2;
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(y+1<*byt)
		if(yeralti[x][y+1]==0)
		{
			kareac(arazi,yeralti,x,y+1);
			if(kontrol(x,y+1,s)==1)
			{
				boslar[s]=x;		boslar[s+1]=y+1;		s+=2;
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x+1<10 && y+1<*byt)
		if(yeralti[x+1][y+1]==0)
		{
			kareac(arazi,yeralti,x+1,y+1);
			if(kontrol(x+1,y+1,s)==1)
			{
				boslar[s]=x+1;		boslar[s+1]=y+1;		s+=2;
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x+1<10)
		if(yeralti[x+1][y]==0)
		{
			kareac(arazi,yeralti,x+1,y);
			if(kontrol(x+1,y,s)==1)
			{
				boslar[s]=x+1;		boslar[s+1]=y;			s+=2;
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x+1<10 && y-1>=0)
		if(yeralti[x+1][y-1]==0)
		{
			kareac(arazi,yeralti,x+1,y-1);
			if(kontrol(x+1,y-1,s)==1)
			{
				boslar[s]=x+1;		boslar[s+1]=y-1;		s+=2;
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(y-1>=0)
		if(yeralti[x][y-1]==0)
		{
			kareac(arazi,yeralti,x,y-1);
			if(kontrol(x,y-1,s)==1)
			{
				boslar[s]=x;		boslar[s+1]=y-1;		s+=2;
				return boslara_bak_sag(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	
	if(*k!=9 && *e<s)		//e'ye koþul koymazsak boslar[-]'ye gider ve oralarda bir sayý olmadýðý için hata verir.
	{						// 's' kadar adým attýðýmýz için s'den küçük diyoruz.
		*e+=2;
		return boslara_bak_sag(arazi,yeralti,boslar[s-*e],boslar[s+1-*e],s);		//8 tarafa da gidemediðinde bir önceki kareye gönderiyor.
	}
}


short boslara_bak_sol(char **arazi, short **yeralti, short x, short y, short s)
{
	if(x-1>=0 && y-1>=0)
		if(yeralti[x-1][y-1]==0)
		{
			kareac(arazi,yeralti,x-1,y-1);
			if(kontrol(x-1,y-1,s)==1)
			{
				boslar[s]=x-1;		boslar[s+1]=y-1;		s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(y-1>=0)
		if(yeralti[x][y-1]==0)
		{
			kareac(arazi,yeralti,x,y-1);
			if(kontrol(x,y-1,s)==1)
			{
				boslar[s]=x;		boslar[s+1]=y-1;		s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x+1<10 && y-1>=0)
		if(yeralti[x+1][y-1]==0)
		{
			kareac(arazi,yeralti,x+1,y-1);
			if(kontrol(x+1,y-1,s)==1)
			{
				boslar[s]=x+1;		boslar[s+1]=y-1;		s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x+1<10)
		if(yeralti[x+1][y]==0)
		{
			kareac(arazi,yeralti,x+1,y);
			if(kontrol(x+1,y,s)==1)
			{
				boslar[s]=x+1;		boslar[s+1]=y;			s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x+1<10 && y+1<*byt)
		if(yeralti[x+1][y+1]==0)
		{
			kareac(arazi,yeralti,x+1,y+1);
			if(kontrol(x+1,y+1,s)==1)
			{
				boslar[s]=x+1;		boslar[s+1]=y+1;		s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(y+1<*byt)
		if(yeralti[x][y+1]==0)
		{
			kareac(arazi,yeralti,x,y+1);
			if(kontrol(x,y+1,s)==1)
			{
				boslar[s]=x;		boslar[s+1]=y+1;		s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x-1>=0 && y+1<*byt)
		if(yeralti[x-1][y+1]==0)
		{
			kareac(arazi,yeralti,x-1,y+1);
			if(kontrol(x-1,y+1,s)==1)
			{
				boslar[s]=x-1;		boslar[s+1]=y+1;		s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	if(x-1>=0)
		if(yeralti[x-1][y]==0)
		{
			kareac(arazi,yeralti,x-1,y);
			if(kontrol(x-1,y,s)==1)
			{
				boslar[s]=x-1;		boslar[s+1]=y;			s+=2;
				return boslara_bak_sol(arazi,yeralti,boslar[s-2],boslar[s-1],s);
			}
		}
	
	if(*k!=9 && *e<s)
	{
		*e+=2;
		if(boslar[s-2]==boslar[0] && boslar[s-1]==boslar[1])
		{
			*e=0;
			*k+=1;
			return boslara_bak_sol(arazi,yeralti,boslar[0],boslar[1],s);
		}
		else
			return boslara_bak_sol(arazi,yeralti,boslar[s-*e],boslar[s+1-*e],s);
	}
}



void kareac(char **arazi, short **yeralti, short x, short y)
{
	arazi[x][y]=' ';
	if(x-1>=0 && y-1>=0)
	{
		if(yeralti[x-1][y-1]==0)	arazi[x-1][y-1]=' ';
		else						arazi[x-1][y-1]=yeralti[x-1][y-1]+48;
	}
	if(x-1>=0)
	{
		if(yeralti[x-1][y]==0)		arazi[x-1][y]=' ';
		else						arazi[x-1][y]=yeralti[x-1][y]+48;
	}
	if(x-1>=0 && y+1<*byt)
	{
		if(yeralti[x-1][y+1]==0)	arazi[x-1][y+1]=' ';
		else						arazi[x-1][y+1]=yeralti[x-1][y+1]+48;
	}
	if(y-1>=0)
	{
		if(yeralti[x][y-1]==0)		arazi[x][y-1]=' ';
		else						arazi[x][y-1]=yeralti[x][y-1]+48;
	}
	if(y+1<*byt)
	{
		if(yeralti[x][y+1]==0)		arazi[x][y+1]=' ';
		else						arazi[x][y+1]=yeralti[x][y+1]+48;
	}
	if(x+1<10 && y-1>=0)
	{
		if(yeralti[x+1][y-1]==0)	arazi[x+1][y-1]=' ';
		else						arazi[x+1][y-1]=yeralti[x+1][y-1]+48;
	}
	if(x+1<10)
	{
		if(yeralti[x+1][y]==0)		arazi[x+1][y]=' ';
		else						arazi[x+1][y]=yeralti[x+1][y]+48;
	}
	if(x+1<10 && y+1<*byt)
	{
		if(yeralti[x+1][y+1]==0)	arazi[x+1][y+1]=' ';
		else						arazi[x+1][y+1]=yeralti[x+1][y+1]+48;
	}
}



short ayarlar()
{
	while(true)
	{
		system("cls");
		printf("\n\n\tHizmet Edilecek B%clge Ne Kadar?\n\n",148);

		printf("\t\t%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,187);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,187);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,187);
		printf("\t\t%c 1-K%c%c%cK %c\t\t%c 2-ORTA %c\t\t%c 3-B%cY%cK %c\t\t%c 4-%cZEL %c\n",186,154,128,154,186,186,186,186,154,154,186,186,153,186);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,188);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,188);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,188);
		
		
		gel_boyut:		//							<<--------------------------------------- GEL_BOYUT
		
			
		printf("\t");
		boyut=getch();
		printf("%c",boyut);
		if(boyut!='1' && boyut!='2' && boyut!='3' && boyut!='4' && boyut!='k' && boyut!='o' && boyut!='b' && boyut!=-108 && boyut!='K' && boyut!='O' && boyut!='B' && boyut!=-103 && boyut!=27)
			goto gel_boyut;
		else if(boyut==27)
			return 0;
		else if(boyut=='4' || boyut==-108 || boyut==-103)
			{
				printf("\tBu s%cr%cmde sadece s%ctun say%cs%cn%c de%ci%ctirebilirsiniz: ",129,129,129,141,141,141,167,159);
				scanf("%d",&boyut);
				if(boyut>20)		boyut=20;
				else if(boyut<10)	boyut=10;
				printf("\tS%ctun boyutu %hd olarak ayarland%c",129,boyut,141);
			}

		printf("\n\n\tNe Kadar %cetin Bir %cmtihandan Ge%ceceksin?\n\n",128,152,135);
	
		printf("\t\t%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,187);
		printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
		printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,187);	
		printf("\t\t%c 1-KOLAY %c\t\t\t%c 2-NORMAL %c\t\t\t%c  3-ZOR  %c\n",186,186,186,186,186,186);
		printf("\t\t%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,188);
		printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,188);
		printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,188);
	
	
		gel_zorluk:		//							<<--------------------------------------- GEL_ZORLUK
		
		
		printf("\t");
		zorluk=getche();
		if(zorluk!='1' && zorluk!='2' && zorluk!='3' && zorluk!='k' && zorluk!='o' && zorluk!='z' && zorluk!='K' && zorluk!='O' && zorluk!='Z' && zorluk!=27)
			goto gel_zorluk;
		else if(zorluk==27)
			return 0;
			
		printf("\n\n\t%cu An Alemin Hangi Renk?\n\n",158);

		printf("\t%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,187);
		printf("\t %c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\t    %c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\t%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,187);
		printf("\t%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,187);
		printf("\t%c 1-MAV%c %c\t%c 2-YE%c%cL %c\t %c 3-TURKUAZ %c\t    %c 4-KIRMIZI %c\t%c 5-MOR %c\t%c 6-SARI %c\n",186,152,186,186,158,152,186,186,186,186,186,186,186,186,186);
		printf("\t%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188);
		printf("\t%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,188);
		printf("\t %c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\t    %c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\t%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,188);
		printf("\t%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,188);
		
		
		gel_renk:		//							<<--------------------------------------- GEL_RENK
		
		
		printf("\t");
		renk=getche();
		if(*rnk!='1' && *rnk!='2' && *rnk!='3' && *rnk!='4' && *rnk!='5' && *rnk!='6' && *rnk!='m' && *rnk!='y' && *rnk!='t' && *rnk!='k' && *rnk!='s' && *rnk!='M' && *rnk!='Y' && *rnk!='T' && *rnk!='K' && *rnk!='S' && *rnk!=27)
			goto gel_renk;
		else if(*rnk==27)
			return 0;
		
		printf("\n\t\t\t\tDe%ci%ciklikleri Kaydetti%cinizde Yeni Bir Seyr-i S%cluk Ba%clayacak",167,159,167,129,159);
		printf("\n\t\t\t\t\t\t Mertebeler Kaydedilsin mi?\n");
	
		printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\t\t\t%c EVET = ENTER %c\t\t\t\t\t%c HAYIR = ESC %c\n",186,186,186,186);
		printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,188);	
	
	
		gel_enter:		//							<<--------------------------------------- GEL_ENTER
		
		
		printf("\t");
		onay=getch();
		if(onay!=13 && onay!=27)
			goto gel_enter;
		else if(onay==27)
			continue;
		else
		{
			tablo_ayar(boyut);
			zorluk_ayar(zorluk);
			renk_ayar(rnk);
			printf("\n\t\t\t\t\t\t De%ci%cikler Kaydedildi.",167,159);
			getch();
			system("cls");
			return 1;
		}
	}
	
}


void tablo_ayar(char boyut)
{
	switch(boyut)
	{
		case '1': *byt=10;		break;
		case '2': *byt=15;		break;
		case '3': *byt=20;		break;
		case 'k': *byt=10;		break;
		case 'o': *byt=15;		break;
		case 'b': *byt=20;		break;
		case 'K': *byt=10;		break;
		case 'O': *byt=15;		break;
		case 'B': *byt=20;		break;
		default: *byt=boyut;
	}
}


void zorluk_ayar(char zorluk)
{
	switch(zorluk)
	{
		case '1': if(*byt<14)	*vrt=15;	else if(*byt<18)	*vrt=22;	else	*vrt=30;		break;
		case '2': if(*byt<14)	*vrt=22;	else if(*byt<18)	*vrt=33;	else	*vrt=44;		break;
		case '3': if(*byt<14)	*vrt=30;	else if(*byt<18)	*vrt=45;	else	*vrt=60;		break;
		case 'k': if(*byt<14)	*vrt=15;	else if(*byt<18)	*vrt=22;	else	*vrt=30;		break;
		case 'o': if(*byt<14)	*vrt=22;	else if(*byt<18)	*vrt=33;	else	*vrt=44;		break;
		case 'z': if(*byt<14)	*vrt=30;	else if(*byt<18)	*vrt=45;	else	*vrt=60;		break;
		case 'K': if(*byt<14)	*vrt=15;	else if(*byt<18)	*vrt=22;	else	*vrt=30;		break;
		case 'O': if(*byt<14)	*vrt=22;	else if(*byt<18)	*vrt=33;	else	*vrt=44;		break;
		case 'Z': if(*byt<14)	*vrt=30;	else if(*byt<18)	*vrt=45;	else	*vrt=60;		break;
		default:  if(*byt<14)	*vrt=15;	else if(*byt<18)	*vrt=22;	else	*vrt=30;
	}
}


void renk_ayar(char *rnk)
{
	switch(*rnk)
	{
		case '1': system("color 97");		break;
		case '2': system("color 27");		break;
		case '3': system("color 37");		break;
		case '4': system("color 47");		break;
		case '5': system("color 57");		break;
		case '6': system("color 67");		break;
		case 'm': system("color 97");	*rnk='1';		break;
		case 'y': system("color 27");	*rnk='2';		break;
		case 't': system("color 37");	*rnk='3';		break;
		case 'k': system("color 47");	*rnk='4';		break;
		case 's': system("color 67");	*rnk='6';		break;
		case 'M': system("color 57");	*rnk='5';		break;
		case 'Y': system("color 27");	*rnk='2';		break;
		case 'T': system("color 37");	*rnk='3';		break;
		case 'K': system("color 47");	*rnk='4';		break;
		case 'S': system("color 67");	*rnk='6';		break;
		default: system("color 37");	*rnk='3';
	}
}


void yolun_sonu(char **arazi)
{
	printf("\n\n");
	
	for(i=-1;i<10;i++)
	{
		printf("\t");
		if(i==-1)
		{
			for(j=0;j<*byt;j++)
				printf(" %02d ",j+1);
			printf("%c",179);
			printf("\n");
		}
		else
		{
			for(j=0;j<=*byt;j++)
			{
				if(i==0 && j==0)
					printf("%c%c%c%c",218,196,196,196);
				else if(i==0 && j==*byt)
					printf("%c%c%c",197,196,196);
				else if(i==0)
					printf("%c%c%c%c",194,196,196,196);
			}
			if(i==3)
				printf("      %c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
			if(i==5)
				printf("      s%cluk",129);
			printf("\n");
			printf("\t");
			for(j=0;j<*byt;j++)
			{
				if(arazi[i][j]=='1' || arazi[i][j]=='2' || arazi[i][j]=='3' || arazi[i][j]=='4' || arazi[i][j]=='5' || arazi[i][j]=='6' || arazi[i][j]=='7' || arazi[i][j]=='8' || arazi[i][j]==-72)
					printf("%c %c ",179,arazi[i][j]);
				else
					printf("%c%c%c%c",179,arazi[i][j],arazi[i][j],arazi[i][j]);
			}
			printf("%c%02d",179,i+1);
			if(i==3)
				printf("\t      H-Hakikat%c %c%cren",141,148,167);
			if(i==4)
				printf("\t      Y-Yeni bir seyr-i");
			if(i==9)
				printf("\t      ESC-KAB%cR",152);
			printf("\n");
			printf("\t");
			for(j=0;j<=*byt;j++)
			{
				if(i==9 && j==0)
					printf("%c%c%c%c",192,196,196,196);
				else if(i==9 && j==*byt)
					printf("%c",217);
				else if(i==9)
					printf("%c%c%c%c",193,196,196,196);
				else if(j==0)
					printf("%c%c%c%c",195,196,196,196);
				else if(j==*byt)
					printf("%c",180);
				else
					printf("%c%c%c%c",197,196,196,196);
			}
		}
	}
	printf("\n");
}



void menu_2(char **arazi)
{
	printf("\n\n\n");
	
	for(i=-1;i<10;i++)
	{
		printf("\t");
		if(i==-1)
		{
			for(j=0;j<*byt;j++)
				printf(" %02d ",j+1);
			printf("%c",179);
			printf("\n");
		}
		else
		{
			for(j=0;j<=*byt;j++)
			{
				if(i==0 && j==0)
					printf("%c%c%c%c",218,196,196,196);
				else if(i==0 && j==*byt)
					printf("%c%c%c",197,196,196);
				else if(i==0)
					printf("%c%c%c%c",194,196,196,196);
			}
			if(i==2)
				printf("      %c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
			printf("\n");
			printf("\t");
			for(j=0;j<*byt;j++)
			{
					if(arazi[i][j]=='1' || arazi[i][j]=='2' || arazi[i][j]=='3' || arazi[i][j]=='4' || arazi[i][j]=='5' || arazi[i][j]=='6' || arazi[i][j]=='7' || arazi[i][j]=='8')
						printf("%c %c ",179,arazi[i][j]);
					else
						printf("%c%c%c%c",179,arazi[i][j],arazi[i][j],arazi[i][j]);
			}
			printf("%c%02d",179,i+1);
			if(i==1)
				printf("\t       %c%cLEM",152,158);
			if(i==2)
				printf("\t      K-Kilitle");
			if(i==3)
				printf("\t      %c-%c%cpheli",158,158,129);
			if(i==4)
				printf("\t      H-Himmet(%d)",*jkr_k);
			if(i==9)
				printf("\t      ESC-%c%ck%c%c",128,141,141,159);
			printf("\n");
			printf("\t");
			for(j=0;j<=*byt;j++)
			{
				if(i==9 && j==0)
					printf("%c%c%c%c",192,196,196,196);
				else if(i==9 && j==*byt)
					printf("%c",217);
				else if(i==9)
					printf("%c%c%c%c",193,196,196,196);
				else if(j==0)
					printf("%c%c%c%c",195,196,196,196);
				else if(j==*byt)
					printf("%c",180);
				else
					printf("%c%c%c%c",197,196,196,196);
			}
		}
	}
	printf("\n");
}


void menu_1(char **arazi)
{
	printf("\n\n");
	for(i=-1;i<10;i++)
	{
		printf("\t");
		if(i==-1)
		{
			for(j=0;j<*byt;j++)
				printf(" %02d ",j+1);
			printf("%c",179);
			printf("\n");
		}
		else
		{
			for(j=0;j<=*byt;j++)
			{
				if(i==0 && j==0)
					printf("%c%c%c%c",218,196,196,196);
				else if(i==0 && j==*byt)
					printf("%c%c%c",197,196,196);
				else if(i==0)
					printf("%c%c%c%c",194,196,196,196);
			}
			if(i==2)
				printf("      %c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
			if(i==5)
				printf("      s%cluk",129);
			printf("\n");
			printf("\t");
			for(j=0;j<*byt;j++)
			{
				if(arazi[i][j]=='1' || arazi[i][j]=='2' || arazi[i][j]=='3' || arazi[i][j]=='4' || arazi[i][j]=='5' || arazi[i][j]=='6' || arazi[i][j]=='7' || arazi[i][j]=='8')
					printf("%c %c ",179,arazi[i][j]);
				else
					printf("%c%c%c%c",179,arazi[i][j],arazi[i][j],arazi[i][j]);
			}
			printf("%c%02d",179,i+1);
			if(i==1)
				printf("\t       %c%cLEM",152,158);
			if(i==2)
				printf("\t      H-Himmet(%d)",*jkr_a);
			if(i==3)
				printf("\t      %c-%cpucu",152,152);
			if(i==4)
				printf("\t      Y-Yeni bir seyr-i");
			if(i==9)
				printf("\t      ESC-%c%ck%c%c",128,141,141,159);
			printf("\n");
			printf("\t");
			for(j=0;j<=*byt;j++)
			{
				if(i==9 && j==0)
					printf("%c%c%c%c",192,196,196,196);
				else if(i==9 && j==*byt)
					printf("%c",217);
				else if(i==9)
					printf("%c%c%c%c",193,196,196,196);
				else if(j==0)
					printf("%c%c%c%c",195,196,196,196);
				else if(j==*byt)
					printf("%c",180);
				else
					printf("%c%c%c%c",197,196,196,196);
			}
		}
	}
	printf("\n");
}


void ana_menu(char **arazi)
{
	printf("\n\n");
	for(i=-1;i<10;i++)
	{
		printf("\t");
		if(i==-1)
		{
			for(j=0;j<*byt;j++)
				printf(" %02d ",j+1);
			printf("%c",179);
			printf("\n");
		}
		else
		{
			for(j=0;j<=*byt;j++)
			{
				if(i==0 && j==0)
					printf("%c%c%c%c",218,196,196,196);
				else if(i==0 && j==*byt)
					printf("%c%c%c",197,196,196);
				else if(i==0)
					printf("%c%c%c%c",194,196,196,196);
			}
			if(i==1)
				printf("      %c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
			if(i==6)
				printf("      bir hakikat anlat",159);
			printf("\n");
			printf("\t");
			for(j=0;j<*byt;j++)
			{
				if(arazi[i][j]=='1' || arazi[i][j]=='2' || arazi[i][j]=='3' || arazi[i][j]=='4' || arazi[i][j]=='5' || arazi[i][j]=='6' || arazi[i][j]=='7' || arazi[i][j]=='8')
					printf("%c %c ",179,arazi[i][j]);
				else
					printf("%c%c%c%c",179,arazi[i][j],arazi[i][j],arazi[i][j]);
			}
			printf("%c%02d",179,i+1);
			if(i==0)
				printf("\t         MEN%c",154);
			if(i==1)
				printf("\t      1-Kap%c a%c",141,135);
			if(i==2)
				printf("\t      2-%c%caretle",152,159);
			if(i==3)
				printf("\t      3-Mertebeler");
			if(i==4)
				printf("\t      4-Nas%cl ilerlenir",141);
			if(i==5)
				printf("\t      5-B%crak bunlar%c da",141,141);
			if(i==9)
				printf("\t      ESC-Kabir");
			printf("\n");
			printf("\t");
			for(j=0;j<=*byt;j++)
			{
				if(i==9 && j==0)
					printf("%c%c%c%c",192,196,196,196);
				else if(i==9 && j==*byt)
					printf("%c",217);
				else if(i==9)
					printf("%c%c%c%c",193,196,196,196);
				else if(j==0)
					printf("%c%c%c%c",195,196,196,196);
				else if(j==*byt)
					printf("%c",180);
				else
					printf("%c%c%c%c",197,196,196,196);
			}
		}
	}
	printf("\n");
}


void yeni_oyun(char **arazi, short **yeralti)
{
	switch(*vrt)
	{
		case 15:	*jkr_a=3;	*jkr_k=1;	break;
		case 22:	*jkr_a=4;	*jkr_k=2;	break;
		case 30:	*jkr_a=5;	*jkr_k=3;	break;
		case 33:	*jkr_a=6;	*jkr_k=4;	break;
		case 44:	*jkr_a=7;	*jkr_k=5;	break;
		case 45:	*jkr_a=7;	*jkr_k=5;	break;
		case 60:	*jkr_a=8;	*jkr_k=6;	break;
	}
	
	for(i=0;i<10;i++)
		for(j=0;j<*byt;j++)
				yeralti[i][j]=0;
	
	i=0;
	while(i<*vrt)
	{
		x=rand()%10;	y=rand()%*byt;
		if(yeralti[x][y]!=136)
		{
			yeralti[x][y]=136;
			i++;
		}
	}
			
	for(i=0;i<10;i++)
		for(j=0;j<*byt;j++)
			if(yeralti[i][j]==136)
				mayinsay(yeralti,i,j);
				
	for(i=0;i<10;i++)
		for(j=0;j<*byt;j++)			
				arazi[i][j]=177;
	
	for(i=0;i<11;i++)
	{
		hakikatler[i]=rand()%11;
		for(j=0;j<i;)
		{
			if(hakikatler[j]==hakikatler[i])
			{
				hakikatler[i]=rand()%11;
				j=0;
			}
			else	j++;
		}		
	}
}


short mayinsay(short **yeralti, short x, short y)
{
/*Sol üst*/	if(x-1>=0 && y-1>=0 && yeralti[x-1][y-1]!=136)
				yeralti[x-1][y-1]++;
/*Yukarý*/	if(x-1>=0 && yeralti[x-1][y]!=136)
				yeralti[x-1][y]++;
/*Sað üst*/	if(x-1>=0 && y+1<*byt && yeralti[x-1][y+1]!=136)
				yeralti[x-1][y+1]++;
/*Sol */	if(y-1>=0 && yeralti[x][y-1]!=136)
				yeralti[x][y-1]++;
/*Sað */	if(y+1<*byt && yeralti[x][y+1]!=136)
				yeralti[x][y+1]++;
/*Sol alt*/	if(x+1<10 && y-1>=0 && yeralti[x+1][y-1]!=136)
				yeralti[x+1][y-1]++;
/*Aþaðý*/	if(x+1<10 && yeralti[x+1][y]!=136)
				yeralti[x+1][y]++;
/*Sað alt*/	if(x+1<10 && y+1<*byt && yeralti[x+1][y+1]!=136)
				yeralti[x+1][y+1]++;
}


char *harf_duzelt(char metin[1000])
{
	for(i=0;metin[i]!='\0';i++)
		switch(metin[i])
		{
			case 'â':	metin[i]=131;	break;
			case 'ç':	metin[i]=135;	break;
			case 'ð':	metin[i]=167;	break;
			case 'î':	metin[i]=140;	break;
			case 'ý':	metin[i]=141;	break;
			case 'ö':	metin[i]=148;	break;
			case 'û':	metin[i]=150;	break;
			case 'ü':	metin[i]=129;	break;
			case 'þ':	metin[i]=159;	break;
			case 'Â':	metin[i]=182;	break;
			case 'Ç':	metin[i]=128;	break;
			case 'Ð':	metin[i]=166;	break;
			case 'Ý':	metin[i]=152;	break;
			case 'Ö':	metin[i]=153;	break;
			case 'Ü':	metin[i]=154;	break;
			case 'Þ':	metin[i]=158;	break;
			case 'é':	metin[i]=130;	break;
			default: ;
		}	
	
	return metin;
}


void ipuclar()
{
	char ipuclar[6][500]={"Bir sýrada sayýlar 1-2-1 þeklinde sýralanmýþ ise 1'lerin baktýðý yer uçurum, 2'nin baktýðý yer boþtur.",
						"Bir sýrada sayýlar 1-2-2-1 þeklinde sýralanmýþ ise 1'lerin baktýðý yer boþ, 2'lerin baktýðý yer uçurumdur.",
						"Eðer 1 sayýsý kapalý kapýlarýn köþesinde kalmýþsa, o köþedeki kapý vartalýdýr.",
						"Eðer bir sýrada 2-2 ikilisi varsa bunlarýn hizalarýnda üç kapý kapalý diðerleri açýksa o kapýlardan ortadaki kesin vartalýdýr.",
						"Eðer bir sýrada 1-1 ikilisi varsa o 1'lerin hizasýndaki kapýlar hariç diðer etrafýndaki kapýlar boþtur. Çünkü dip dibe olan bu 1'lerin hizasýndaki bir kapalý kapý diðerinin köþesine, diðerinin hizasýndaki de bunun köþesine denk geldiði için vartalý kapý bu ikisinden biridir. Diðerleri boþtur.",
						"Bir sýrada sayýlar 1-2-3-2-1 þeklinde sýralanmýþ ise 1'lerin baktýðý yer boþ, 2'lerin ve 3'lerin baktýðý yer uçurumdur. Bu 3'ten istediði kadar olsun(1-2-3-3-...-3-3-2-1)"};
	char *metin;
	
	metin=harf_duzelt(ipuclar[rand()%6]);
	puts(metin);
}


void kurallar()
{
	short s=0,i=0;
	char secim;
	char *metin,*metin1;
	char kurallar[5][10000]={"\n\n\n\n\n***********************************************        ESASLAR        *************************************************"
					"\n\n\t1-)Sayýlarý veya harfleri kullanarak menülerde ilerleyebilirsiniz. Ana menüde sadece sayýlarý kullanabilirsiniz."
					" '0' veya ESC tuþu ile geri gidebilir veya çýkýþ yapabilirsiniz."
					"\n\n\t2-)Arkasý uçurumlu(vartalý) kapýlarý açmadan bütün kapýlarý açarsanýz bu terakki sürecini tamamlarsýnýz."
					"\n\n\t3-)Bu kapýlarýn bir kýsmýnýn arkasýnda uçurum var. Mesela küçük ve kolay mertebede 15 tane vartalý kapý var. O kapýlardan birini açtýðýnýzda vartaya yuvarlanýrsýnýz."
					"\n\n\t4-)Bazý kapýlarýn arkasýnda sayýlar vardýr. Bu sayýlar o kapýnýn etrafýnda kaç tane uçurumlu kapý olduðunu gösterir."
					"\n\n\t5-)Bir kapýnýn arkasýnda en fazla '8' rakamý olabilir."
					"\n\n\t6-)Ancak bütün vartalý kapýlarý kilitleyip geri kalan tüm kapýlarý açtýðýnýzda terakkinizi bitirebilirsiniz. Veya bir vartadan yuvarlanýn bitsin...:)"
					"\n\n***********************************************                        ************************************************"
					"\n\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDüsturlar----> ",
					
					"\n\n***********************************************       DÜSTURLAR       *************************************************"
					"\n\n\t1-)En temel iþlemimiz kapý açmadýr. Ana menüde '1' seçeneðine týkladýðýmýzda bizden koordinatlarý girmemizi isteyecek. Biz de açmak istediðimiz kapýnýn koordinatlarýný boþluk býrakarak giriyoruz."
					"\n\n\t2-)Burada yardým alma(himmet) seçeneði dikkatinizi çekmiþtir. 'H' tuþuna basarak himmet alýrsanýz program size güvenli herhangi bir kapýyý açacaktýr. Standart mertebede 3 yardým hakkýnýz vardýr. Bölgenin büyüklüðüne ve imtihanýn zorluðuna göre himmet sayýnýz deðiþebilir."
					"\n\n\t3-)Vartalý olduðunu düþündüðünüz alanlarý kilitlemek veya iþaretlemek için ana menüden '2' seçeneðine týklýyoruz."
					"\n\n\t4-)Burada 'K' veya '1' tuþuna basarak girdiðiniz koordinatlý kapýyý kilitleyebilirsiniz."
					"\n\n\t5-)'Þ' veya '2' tuþuna basarak þüphelendiðiniz kapýyý þüpheli olarak iþaretliyoruz."
					"\n\n\t6-)Bu iþaretlemelerin avantajý kapý açarken yanlýþlýkla istemediðiniz kapýyý açmayý engellemek içindir. Ýþaretli kapýyý açmak için tekrar iþaretleme menüsüne gelip iþareti kaldýrmanýz gerekiyor. Bunun için ayný iþlemleri yapýyorsunuz."
					"\n\t7-)Görebileceðiniz üzere burda da himmet hakkýnýz var. Bunu kullandýðýnýzda program size kesin vartalý olan ve daha önce kilitlemediðiniz bir kapýyý kilitler. Standart mertebede 1 tane himmet alma hakkýnýz vardýr. Tahmin edebildiðiniz üzere 'H' tuþuna basarak kullanýyoruz."
					"\n\n***********************************************                       *************************************************"
					"\n\n       <----Esaslar\t\t\t\t\t\t\t\t\t\t  0-Geri",
					
					"\n\n\n\n\n***********************************************        HÝLELER        *************************************************"
					"\n\n\t1-)Öncelikle burayý bulmayý baþardýðýn için seni tebrik ederim. Zeki birisin. Ya da sadece þanslýydýn.",
					"\n\n\n\n\n***********************************************        HÝLELER        *************************************************"
					"\n\n\t1-)Hileleri mi unuttun? Sanýrým hafýzan pek kuvvetli deðil...",
					"\n\t2-)Hile konsolunu açmak için çift týrnak(\") yani ESC tuþunun altýndaki é tuþuna basýn."
					"\n\n\t3-)Hileleri yazarken baþýna kesme iþareti(-) koyun. Misal; -sesi kes"
					"\n\n\tHile Kodlarý:"
					"\n\n\t-sesi kes ==>Çalan müziði durdurmak için yazýlýr. (arada boþluk var)"
					"\n\t-hakikat50 ==>50 tane güvenli kapý açar."
					"\n\t-hakikat100 ==>100 tane güvenli kapý açar."
					"\n\t-kilitle10 ==>Arkasý uçurumlu 10 kapýyý kilitler."
					"\n\t-kilitle20 ==>Arkasý uçurumlu 20 kapýyý kilitler."
					"\n\n***********************************************                        ************************************************"
					"\n\n\n\n\n\n\n\n\t\t\t\t\t\tHileci baþýna bir kaç kere uðrayarak onu tatmin edebilirsiniz. :)"};				
	
	
	while(secim!='0'&secim!=27)
	{
		metin=harf_duzelt(kurallar[i]);
		puts(metin);
		secim=getch();
		system("cls");
		if(secim==77)			{	if(i!=1)	i++;	s++;	}
		else if(secim==75)		{	if(i!=0)	i--;			}
		if(s==4 && *ziyaret==1)
		{
			metin=harf_duzelt(kurallar[3]);
			puts(metin);
			metin1=harf_duzelt(kurallar[4]);
			puts(metin1);
			getch();
			system("cls");
			s=1;
		}
		else if(s==4 && *ziyaret==0)
		{
			metin=harf_duzelt(kurallar[2]);
			puts(metin);
			metin1=harf_duzelt(kurallar[4]);
			puts(metin1);
			getch();
			system("cls");
			s=1;	*ziyaret=1;
		}
	}
	
}


void hileler(short **yeralti, char **arazi)
{
	short x,y,s;
	char hileler[5][20]={"sesi kes","hakikat50","hakikat100","kilitle10","kilitle20"};
	char hile[20];
	char hakaretler[8][100]={"Elin sürçtü de mi?",
							"Kesin elin sürçmüþtür",
							"Her zamanki gibi sallayanlardansýn iþte...",
							"Dedem bile senden daha iyi yazardý!",
							"Bir hileyi bile düzgün yazamýyorsun mal!",
							"Sanýrým hileyi unuttun. Aaa tesadüfe bak ki ben de unuttum. :)",
							"Bilmiyorsan çek git þurdan! Onca iþimiz gücümüz arasýnda...",
							"Ulan biz o kadar programý kýralým sistemi hackleyelim, sen bir hileyi bile yazama!"};
	char *kontrol,*metin;
	printf("\n\n----------------------------------------------------------------------------------------------------------------------\n");
	
	
	while(true)
	{
		if(*hl==0)
			printf("\tHileci Ba%c%c:   Oooooo hile yaz%cyorsun. Hadi bak%cy%cm.\n",159,141,141,141,141);
		else if(*hl==1)
		{
			printf("\tHileci Ba%c%c:   Ule gene mi sen?\n\tNeyse hadi yaz yaz ba%c%cm%cn belas%c...\n\n",159,141,159,141,141,141);
			*hl=2;
		}
		else
			printf("\tHileci Ba%c%c: Hilekar seni...\n\n",159,141);
			
		onay=0;
		do
		{
			if(onay==13)
			{
				printf("\n\tHileci Ba%c%c: Yanl%c%c kod!\n\tHileci Ba%c%c: ",159,141,141,159,159,141);
				metin=harf_duzelt(hakaretler[rand()%8]);
				puts(metin);
			}
			onay=getche();
		}while(onay==13 || (onay!='-' && onay!=27));
		
		if(onay==27)			break;
		
		gets(hile);
		if(*hl==0)
		{
			printf("\n\tHileci Ba%c%c:   Hak yolunda hile olmaz ko%cummm. Hadi ikile ikile...\n\n",159,141,135);
			*hl=1;
			onay=getch();
			break;
		}
		for(x=0,y=0;x<5;x++)
		{
			kontrol=strstr(hile,hileler[x]);
			if(kontrol!=NULL && strlen(hile)==strlen(hileler[x]))
			{
				y++;
				printf("\n\tHileci Ba%c%c: Do%cru yazd%cn\n",159,141,167,141);
				switch(x)
				{
					case 0:		PlaySoundA("Müzikler/Bitiriþ.wav",NULL,SND_ASYNC);	break;
					
					case 1:
						s=0;
						for(i=0;i<10;i++)
							for(j=0;j<*byt&s<50;j++)
								if(yeralti[i][j]!=136 && arazi[i][j]==-79 && arazi[i][j]!=-78)
								{
									if(yeralti[i][j]==0)	arazi[i][j]=' ';
									else					arazi[i][j]=yeralti[i][j]+48;
									s++;
								}
						break;
					
					case 2:
						s=0;
						for(i=0;i<10;i++)
							for(j=0;j<*byt&s<100;j++)
								if(yeralti[i][j]!=136 && arazi[i][j]==-79 && arazi[i][j]!=-78)
								{
									if(yeralti[i][j]==0)	arazi[i][j]=' ';
									else					arazi[i][j]=yeralti[i][j]+48;
									s++;
								}
						break;
					
					case 3:
						s=0;
						for(i=0;i<10;i++)
							for(j=0;j<*byt&s<10;j++)
								if(yeralti[i][j]==136 && arazi[i][j]==-79 && arazi[i][j]!=-78)
								{
									arazi[i][j]=-78;
									s++;
								}
						break;
						
					case 4:
						s=0;
						for(i=0;i<10;i++)
							for(j=0;j<*byt&s<20;j++)
								if(yeralti[i][j]==136 && arazi[i][j]==-79 && arazi[i][j]!=-78)
								{
									arazi[i][j]=-78;
									s++;
								}
						break;
						
					default: ;
				}
				break;
			}
		}
		if(y==0)
		{
			printf("\n\tHileci Ba%c%c: Yanl%c%c kod!\n\tHileci Ba%c%c: ",159,141,141,159,159,141);
			metin=harf_duzelt(hakaretler[rand()%8]);
			puts(metin);
		}
	}
}





void mucizeler()
{
	char secim;
	char *metin;
	char mucizeler[5][10000]={"\n\n\n\n**********************************************   MUCÝZAT-I NEBEVÝYE   *************************************************"
				"\n\n\t1) Resul-i Ekrem Aleyhissalâtü Vesselâm'ýn Hazret-i Zeyneb ile tezevvücü velîmesinde, Hazret-i Enes'in vâlidesi Ümm-ü Süleym, bir-iki avuç hurmayý yað ile kavurarak bir kaba koyup Hazret-i Enes'le Peygamber Aleyhissalâtü Vesselâm'a gönderdi." 
				"Enes'e ferman etti ki: \"Filan, filaný çaðýr. Hem kime tesadüf etsen davet et.\" Enes de kime rast geldiyse çaðýrdý. Üçyüz kadar sahabe gelip, Suffe ve Hücre-i Saadeti doldurdular. "
				"Ferman etti: \"Onar onar halka olunuz!\" Sonra mübarek elini o az taam üzerine koydu, dua etti, \"Buyurun\" dedi. Bütün o üçyüz adam yediler, tok olup kalktýlar. Enes'e ferman etmiþ: \"Kaldýr!\" Enes demiþ ki: \"Bilmedim, taam kabýný koyduðum vakit mi taam çoktu, yoksa kaldýrdýðým vakit mi çoktu farkedemedim.\""
				"\n\n\t2) Bir gazvede ordu aç kaldý. Resul-i Ekrem Aleyhissalâtü Vesselâm'a müracaat ettiler. Ferman etti ki: \"Heybelerinizde kalan bakiyye-i erzaký toplayýnýz!\" Herkes azar birer parça hurma getirdi. En çok getiren dört avuç getirebildi. Bir kilime koydular. Seleme der ki: \"Mecmuunu ben tahmin ettim, oturmuþ bir keçi kadar ancak vardý.\"" 
				"Sonra Resul-i Ekrem Aleyhissalâtü Vesselâm bereketle dua edip, ferman etti: \"Herkes kabýný getirsin!\" Koþuþtular, geldiler. O ordu içinde hiçbir kap kalmadý, hepsini doldurdular. Hem fazla kaldý. "
				"\n\n\tSahabeden bir râvi demiþ:\"O bereketin gidiþatýndan anladým; eðer ehl-i Arz gelseydi, onlara dahi kâfi gelecekti\""
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevamý----> ",
				
				"\n\n\n\n**********************************************   MUCÝZAT-I NEBEVÝYE   *************************************************"
				"\n\n\t3) Hazret-i Câbir Ýbn-i Abdullah-il Ensarî beyan ediyor: \"Biz bin beþyüz kiþi, Gazve-i Hudeybiye'de susadýk. Resul-i Ekrem Aleyhissalâtü Vesselâm kýrba denilen deriden bir kap sudan abdest aldý, sonra elini içine soktu. Gördüm ki, parmaklarýndan çeþme gibi su akýyor. Bin beþyüz kiþi içip, kaplarýný o kýrbadan doldurdular. Sâlim Ýbn-i Ebi-l Ca'de, Câbir'den sormuþ: \"Kaç kiþi idiniz?\" Câbir demiþ ki: \"Yüzbin kiþi de olsaydý, yine kâfi gelirdi. Fakat biz, onbeþ yüz (yani bin beþyüz) idik.\"" 
				"\n\n\tÝþte þu mu'cize-i bahirenin râvileri, manen bin beþyüz kadardýrlar. Çünki fýtrat-ý beþeriyede, yalana yalan demek bir meyl-i arzusu vardýr. Sahabeler ise sýdk ve doðruluk için, can ve mal ve peder ve vâlidelerini ve kavim ve kabîlelerini feda edip, sýdk ve hak için fedai olduklarý halde; hem \"Benden bilerek yalan birþey haber veren, Cehennem ateþinden yerini hazýrlasýn!\" mealindeki hadîs-i þerifin tehdidine karþý, yalana mukabil sükût etmeleri mümkün deðildir. Madem sükût ettiler; o haberi kabul ettiler, manen iþtirak edip tasdik ediyorlar demektir."
				"\n\n\t4) Gazve-i Taif'te, Resul-i Ekrem Aleyhissalâtü Vesselâm gece at üstünde giderken uykusu geliyordu. O halde iken, bir sidre aðacýna rastgeldi. Aðaç ona yol verip, atýný incitmemek için, iki þakk oldu. Resul-i Ekrem Aleyhissalâtü Vesselâm, hayvan ile içinden geçti. Tâ zamanýmýza kadar o aðaç, iki ayak üstünde, muhterem bir vaziyette kaldý."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\tDevamý----> ",
				
				"\n\n\n\n**********************************************   MUCÝZAT-I NEBEVÝYE   *************************************************"
				"\n\n\t5) Hazret-i Enes (hâdim-i Nebevî) demiþ ki: Resul-i Ekrem Aleyhissalâtü Vesselâm'ýn yanýnda idik. Avucuna küçük taþlarý aldý, mübarek elinde tesbih etmeye baþladýlar. Sonra Ebu Bekir-is Sýddýk'ýn eline koydu, yine tesbih ettiler. Sonra Hazret-i Ömer'in eline koydu, yine tesbih ettiler. Sonra aldý yere koydu, sustular. Sonra yine aldý, Hazret-i Osman'ýn eline koydu, yine tesbihe baþladýlar. Sonra Hazret-i Enes ve Ebu Zerr diyorlar ki: \"Ellerimize koydu, sustular.\""
				"\n\n\t6) Resul-i Ekrem Aleyhissalâtü Vesselâm, Ebu Bekir-is Sýddýk, Ömer-ül Faruk ve Osman-ý Zinnureyn ile Uhud Daðý'nýn baþýna çýktýlar. Cebel-i Uhud ya onlarýn mehabetlerinden veya kendi sürur ve sevincinden lerzeye geldi, kýmýldandý. Resul-i Ekrem Aleyhissalâtü Vesselâm ferman etti ki: 'Üsbüd yâ uhud feinnema aleyke nebiyyün ve sýddîkun ve þehîdâni' Þu hadîs, Hazret-i Ömer ve Osman þehid olacaklarýna bir ihbar-ý gaybîdir. "
				"\n\n\tÞu misalin tetimmesi olarak nakledilmiþ ki: Resul-i Ekrem Aleyhissalâtü Vesselâm Mekke'den hicret ettiði ve küffarlar takibe çýktýklarý vakit, Sebir namýndaki daða çýktýlar. Sebir dedi: \"Ya Resulallah, benden ininiz! Korkarým, benim üstümde sizi vururlarsa, Allah beni tazib eder. Onun için korkarým.\"bCebel-i Hira çaðýrdý: \" Yâ Resulullah, Bana gel.\" Bu sýr içindir ki, ehl-i kalb, Sebir'de havf(korku) ve Hira'da da emniyeti hissederler. Bu misalden anlaþýlýr ki: O koca daðlar, birer müstakil abddir, müsebbihtir ve vazifedardýrlar. Peygamber Aleyhissalâtü Vesselâm'ý tanýr ve severler; baþýboþ deðillerdir."
				"\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\tDevamý----> ",

				"\n\n\n\n**********************************************   MUCÝZAT-I NEBEVÝYE   *************************************************"
				"\n\n\t7) Bir menba'-ý garaib olan Gazve-i Kübra-yý Bedir'de, Ukkaþe Ýbn-il Mihsan-il Esedî'nin müþriklerle döðüþürken kýlýncý kýrýldý. Resul-i Ekrem Aleyhissalâtü Vesselâm ona kýlýnca mukabil kalýnca bir deðnek verdi. Dedi: \"Bununla harbet.\" Birden deðnek, biiznillah uzun, beyaz bir kýlýnç oldu. Onunla harbetti. Hayatý mikdarýnca, tâ Yemame Harbi'nde þehid oluncaya kadar boynunda taþýdý." 
				"Þu hâdise kat'îdir. Çünki Ukkaþe bütün hayatýnda onunla iftihar etmiþ ve o kýlýnç \"El-Avn\" namýyla meþhur olmuþ. Ýþte Hazret-i Ukkaþe'nin iftiharý ve kýlýncýn Avn namýyla, kýlýnçlarýn fevkinde iþtiharý, þu hâdisenin iki hüccetidir."
				"\n\n\t8) Büyük bir imam olan Ýbn-i Vehb haber veriyor ki: Gazve-i Bedr'in ondört þehidinden birisi olan Muavviz Ýbn-i Afra', Ebu Cehil ile döðüþürken; Ebu Cehil-i Laîn, o kahramanýn bir elini kesmiþ. O da öteki eliyle elini tutup, Resul-i Ekrem Aleyhissalâtü Vesselâm'ýn yanýna gelmiþ. Resul-i Ekrem Aleyhissalâtü Vesselâm onun elini yine yerine yapýþtýrdý, tükürüðünü ona sürdü; birden þifa buldu. Yine harbe gitti, þehid oluncaya kadar harbetti." 
				"Hem yine Ýmam-ý Celil Ýbn-i Vehb haber veriyor ki: O gazvede Hubeyb Ýbn-i Yesaf'ýn omuz baþýna bir kýlýnç vurulmuþ ki, bir þakký ayrýlmýþ gibi dehþetli bir yara açýlmýþ. Resul-i Ekrem Aleyhissalâtü Vesselâm onun kolunu omuzuna eliyle yapýþtýrmýþ, nefes etmiþ; þifa bulmuþ."
				"Ýþte þu iki vakýa, çendan âhâdîdir ve haber-i vâhiddir; fakat Ýbn-i Vehb gibi bir imam tashih etse, Gazve-i Bedir gibi bir menba'-ý mu'cizat olan bir gazvede olsa, hem bu iki vakýayý andýracak çok misaller bulunsa; elbette þu iki vakýa, kat'î ve vaki'dir denilebilir."		
				"\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\tDevamý----> ",

				"\n\n\n\n*****************************     BU PARÇA ALTUN VE ELMAS ÝLE YAZILSA LÝYAKATI VAR     *********************************"
				"\n\n\tEvet sâbýkan bahsi geçmiþ: Avucunda küçük taþlarýn zikir ve tesbih etmesi; 'Ve ma rameyte iz rameyte' sýrrýyla ayný avucunda, küçücük taþ ve toprak, düþmana top ve gülle hükmünde onlarý inhizama sevketmesi;" 
				"'Ven þeggal kamer' nassý ile ayný avucunun parmaðýyla Kamer'i iki parça etmesi; ve ayný el, çeþme gibi on parmaðýndan suyun akmasý ve bir orduya içirmesi;" 
				"ve ayný el, hastalara ve yaralýlara þifa olmasý, elbette o mübarek el, ne kadar hârika bir mu'cize-i kudret-i Ýlahiye olduðunu gösterir."
				"\n\n\tGüya ahbab içinde o elin avucu küçük bir zikirhane-i Sübhanîdir ki, küçücük taþlar dahi içine girse, zikir ve tesbih ederler."
				"\n\tVe a'daya karþý küçücük bir cephane-i Rabbanîdir ki; içine taþ ve toprak girse, gülle ve bomba olur."
				"\n\tVe yaralýlar ve hastalara karþý küçücük bir eczahane-i Rahmanîdir ki, hangi derde temas etse derman olur."
				"\n\tVe celal ile kalktýðý vakit, Kamer'i parçalayýp Kab-ý Kavseyn þeklini verir; "
				"\n\tve cemal ile döndüðü vakit, âb-ý kevser akýtan on musluklu bir çeþme-i rahmet hükmüne girer."
				"\n\n\tAcaba böyle bir zâtýn bir tek eli, böyle acib mu'cizata mazhar ve medar olsa; o zâtýn Hâlýk-ý Kâinat yanýnda ne kadar makbul olduðu ve davasýnda ne kadar sadýk bulunduðu ve o el ile biat edenler, ne kadar bahtiyar olacaklarý, bedahet derecesinde anlaþýlmaz mý?.."
				"\n\n******************************************                                 ********************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\t0-Geri"};
	
	j=0;
	while(secim!='0'&secim!=27)
	{
		metin=harf_duzelt(mucizeler[j]);	
		
		if(j==4)	system("color 67");
		
		system("cls");
		puts(metin);
		secim=getch();
		
		if((j==4 && secim==75) || secim=='0' || secim==27)
			renk_ayar(rnk);
			
		if(secim==77)			{	if(j!=4)	j++;	}
		else if(secim==75)		{	if(j!=0)	j--;	}
	}
	
}


void hakikat_1()
{
	char secim;
	char *metin;
	char hakikat[2][2000]={"\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tBir zaman bir büyük hâkim, iki hizmetkârýný -her birisine 24 altýn verip- iki ay uzaklýkta has ve güzel bir çiftliðine ikamet etmek için gönderiyor. Ve onlara emreder ki \"Þu para ile yol ve bilet masrafý yapýnýz. Hem oradaki meskeninize lâzým bâzý þeyleri mübâyaa ediniz. Bir günlük mesafede bir istasyon vardýr. Hem araba, hem gemi, hem þimendifer, hem tayyare bulunur. Sermayeye göre binilir.\""
				"\n\n\tÝki hizmetkâr, ders aldýktan sonra giderler. Birisi bahtiyâr idi ki, istasyona kadar bir parça masraf eder. Fakat o masraf içinde, efendisinin hoþuna gidecek öyle güzel bir ticaret elde eder ki, sermayesi birden bine çýkar."
				"\n\n\tÖteki hizmetkâr, bedbaht, serseri olduðundan istasyona kadar 23 altýnýný sarfeder. Kumara-mumara verip zâyi eder. Birtek altýný kalýr. Arkadaþý ona der: \"Yâhu, þu liraný bir bilete ver. Tâ bu uzun yolda yayan ve aç kalmayasýn. Hem bizim efendimiz kerîmdir; belki merhamet eder. ettiðin kusuru affeder. Seni de tayyareye bindirirler. Bir günde mahall-i ikametimize gideriz. Yoksa, iki aylýk bir çölde aç, yayan, yalnýz gitmeye mecbur olursun."
				"\n\n\tAcaba þu adam inad edip, o tek lirasýný bir defîne anahtarý hükmünde olan bir bilete vermeyip, muvakkat bir lezzet için sefâhete sarfetse; gayet akýlsýz, zararlý, bedbaht olduðunu, en akýlsýz adam dahi anlamaz mý?"
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevamý----> ",
				"\n\n***********************************************                       *************************************************"
				"\n\n\tÝþte ey namazsýz adam! Ve ey namazdan hoþlanmayan nefsim!"
				"\n\n\tO hâkim ise; Rabbimiz, Halýk'ýmýzdýr. O iki hizmetkâr yolcu ise; biri: Mütedeyyin, namazýný þevk ile kýlar. Diðeri: Gafil, namazsýz insanlardýr. O 24 altýn ise; yirmidört saat her gündeki ömürdür. O has çiftlik ise; Cennet'tir. O istasyon ise; kabirdir. O seyehat ise; kabre, haþre, ebede gidecek beþer yolculuðudur. Amele göre, takvâ kuvvetine göre, o uzun yolu mütefâvit derecede kat'ederler. Bir kýsým ehl-i takvâ berk gibi, bin senelik yolu bir günde keser. Bir kýsmý da hayâl gibi, ellibin senelik mesafeyi bir günde kat'eder. Kur'ân-ý Azîmüþþan þu hakikate iki âyetiyle iþâret eder. O bilet ise; NAMAZdýr. Bir tek saat, beþ vakit namaza abdestle kâfi gelir."
				"\n\n\tAcaba, 23 saatini, þu kýsacýk hayat-ý dünyeviyeye sarf eden ve o uzun hayat-ý ebedîyeye bir tek saatini sarfetmeyen; ne kadar zarar eder, ne kadar nefsine zulmeder, ne kadar hilâf-ý akýl hareket eder! Zîrâ, bin adamýn iþtirak ettiði bir piyango kumarýna yarý malýný vermek, akýl kabul ederse; halbuki kazanç ihtimali binde birdir. Sonra yirmidörtten 1 malýný, yüzde doksandokuz ihtimâl ile kazancý musaddak bir hazine-i ebedîyeye vermemek; ne kadar hilâf-ý akýl ve hikmet hareket ettiðini, ne kadar akýldan uzak düþtüðünü, kendini âkýl zanneden adam anlamaz mý?"
				"\n\n\tHâlbuki: Namazda; ruhun, kalbin, aklýn büyük bir rahatý vardýr, hem cisme de o kadar aðýr bir iþ deðildir."
				"\n\n\tHem, namaz kýlanýn diðer mübah dünyevî amelleri, güzel bir niyet ile ibâdet hükmünü alýr. Bu sûrette bütün sermâye-i ömrünü, âhirete mal edebilir. Fâni ömrünü bir cihette ibkâ eder."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri"};
	
	j=0;
	while(secim!='0'&secim!=27)
	{
		metin=harf_duzelt(hakikat[j]);
		system("cls");	
		puts(metin);
		secim=getch();
		if(secim==77)			{	if(j!=1)	j++;	}
		else if(secim==75)		{	if(j!=0)	j--;	}
	}
}

void hakikat_2()
{
	char secim;
	char *metin;
	char hakikat[3][2000]={"\n\n\n***********************************************                       *************************************************"
					"\n\n\tBir vakit iki asker, uzak bir þehire gitmek için emir alýyorlar. Beraber giderler; tâ, yol ikileþir. Bir adam orada bulunur, onlara der: \"Þu saðdaki yol, hiç zararý olmamakla beraber, onda giden yolculardan ondan dokuzu büyük kâr ve rahat görür. Soldaki yol ise, menfaatý olmamakla beraber, on yolcusundan dokuzu zarar görür. Hem ikisi, kýsa ve uzunlukta birdirler. Yalnýz bir fark var ki, intizamsýz, hükûmetsiz olan sol yolun yolcusu çantasýz, silâhsýz gider. Zahirî bir hýffet, yalancý bir rahatlýk görür. Ýntizam-ý askerî altýndaki sað yolun yolcusu ise, mugaddi hülâsalardan dolu dört okkalýk bir çanta ve her adüvvü alt ve maðlub edecek iki kýyyelik bir mükemmel mîrî silâhý taþýmaya mecburdur.\""
					"\n\n\tO iki asker, o muarrif adamýn sözünü dinledikten sonra þu bahtiyar nefer, saða gider. Bir batman aðýrlýðý omuzuna ve beline yükler. Fakat kalbi ve ruhu, binler batman minnetlerden ve korkulardan kurtulur. Öteki bedbaht nefer ise, askerliði býrakýr. Nizama tâbi olmak istemez, sola gider. Cismi bir batman aðýrlýktan kurtulur, fakat kalbi binler batman minnetler altýnda ve ruhu hadsiz korkular altýnda ezilir. Hem herkese dilenci, hem her þeyden, her hâdiseden titrer bir surette gider. Tâ, mahall-i maksuda yetiþir. Orada, âsi ve kaçak cezasýný görür."
					"\n\n\tAskerlik nizamýný seven, çanta ve silâhýný muhafaza eden ve saða giden nefer ise, kimseden minnet almayarak, kimseden havf etmeyerek rahat-ý kalb ve vicdan ile gider. Tâ o matlub þehire yetiþir. Orada, vazifesini güzelce yapan bir namuslu askere münasib bir mükâfat görür."
					"\n\n\n***********************************************                       *************************************************"
					"\n\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevamý----> ",
					"\n\n\n\n\n***********************************************                       *************************************************"
					"\n\n\tÝþte ey nefs-i serkeþ! Bil ki: O iki yolcu; biri muti-i kanun-u Ýlahî, birisi de âsi ve hevaya tâbi insanlardýr. O yol ise, hayat yoludur ki; âlem-i ervahtan gelip kabirden geçer, âhirete gider. O çanta ve silâh ise, ibadet ve takvadýr. Ýbadetin çendan zahirî bir aðýrlýðý var. Fakat manasýnda öyle bir rahatlýk ve hafiflik var ki, tarif edilmez. Çünki âbid, namazýnda der: 'Eþhedü el la ilahe illAllah' Yani: \"Hâlýk ve Rezzak, ondan baþka yoktur. Zarar ve menfaat, onun elindedir. O hem Hakîm'dir, abes iþ yapmaz. Hem Rahîm'dir; ihsaný, merhameti çoktur\" diye itikad ettiðinden her þeyde bir hazine-i rahmet kapýsýný bulur. Dua ile çalar. Hem her þeyi kendi Rabbisinin emrine müsahhar görür, Rabbisine iltica eder. Tevekkül ile istinad edip her musibete karþý tahassun eder. Ýmaný, ona bir emniyet-i tâmme verir."
					"\n\n\tEvet her hakikî hasenat gibi cesaretin dahi menbaý, imandýr, ubudiyettir. Her seyyiat gibi cebanetin dahi menbaý, dalalettir. Evet tam münevver-ül kalb bir âbidi, küre-i arz bomba olup patlasa, ihtimaldir ki, onu korkutmaz. Belki hârika bir kudret-i Samedaniyeyi, lezzetli bir hayret ile seyredecek. Fakat meþhur bir münevver-ül akýl denilen kalbsiz bir fâsýk feylesof ise; gökte bir kuyruklu yýldýzý görse, yerde titrer. \"Acaba bu serseri yýldýz Arzýmýza çarpmasýn mý?\" der; evhama düþer. (Bir vakit böyle bir yýldýzdan Amerika titredi. Çoklarý gece vakti hanelerini terkettiler.)"
					"\n\n\n***********************************************                       *************************************************"
					"\n\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\tDevamý----> ",
					"\n\n\n\n***********************************************                       *************************************************"
					"\n\n\tEvet insan, nihayetsiz þeylere muhtaç olduðu halde; sermayesi hiç hükmünde... Hem nihayetsiz musibetlere maruz olduðu halde; iktidarý, hiç hükmünde bir þey... Âdeta sermaye ve iktidarýnýn dairesi, eli nereye yetiþirse o kadardýr. Fakat emelleri, arzularý ve elemleri ve belalarý ise; dairesi, gözü, hayali nereye yetiþirse ve gidinceye kadar geniþtir. Bu derece âciz ve zaîf, fakir ve muhtaç olan ruh-u beþere ibadet, tevekkül, tevhid, teslim; ne kadar azîm bir kâr, bir saadet, bir nimet olduðunu, bütün bütün kör olmayan görür, derk eder."
					"\n\n\tMalûmdur ki: Zararsýz yol, zararlý yola -velev on ihtimalden bir ihtimal ile olsa- tercih edilir. Halbuki mes'elemiz olan ubudiyet yolu, zararsýz olmakla beraber ondan dokuz ihtimal ile bir saadet-i ebediye hazinesi vardýr. Fýsk ve sefahet yolu ise; -hattâ fâsýkýn itirafýyla dahi- menfaatsýz olduðu halde, ondan dokuz ihtimal ile þekavet-i ebediye helâketi bulunduðu; icma ve tevatür derecesinde hadsiz ehl-i ihtisasýn ve müþahedenin þehadetiyle sabittir. Ve ehl-i zevkin ve keþfin ihbaratýyla muhakkaktýr."
					"\n\n\tElhasýl: Âhiret gibi, dünya saadeti dahi, ibadette ve Allah'a asker olmaktadýr. \nÖyle ise, biz daima 'Elhamdu lillahi ala-ttâati ve-ttevfîg' demeliyiz. Ve müslüman olduðumuza þükretmeliyiz."
					"\n\n\n***********************************************                       *************************************************"
					"\n\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri"};
	
	j=0;
	while(secim!='0'&secim!=27)
	{
		metin=harf_duzelt(hakikat[j]);
		system("cls");	
		puts(metin);
		secim=getch();
		if(secim==77)			{	if(j!=2)	j++;	}
		else if(secim==75)		{	if(j!=0)	j--;	}
	}
}


void hakikat_3()
{
	char *metin;
	char hakikat[]="\n\n\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\t\tCenab-ý Hak nefse demiþ ki: \"Ben neyim, sen nesin?\" Nefis demiþ: \"Ben benim, sen sensin!\""
				"\n\n\t\t\tAzab vermiþ, Cehennem'e atmýþ, yine sormuþ. Yine demiþ: \"Ene ene, ente ente.\" "
				"\n\n\t\tHangi nevi azabý vermiþ, enaniyetten vazgeçmemiþ. Sonra açlýk ile azab vermiþ, yani aç býrakmýþ. "
				"\n\n\tYine sormuþ: \"Men ene vema ente?\" Nefis demiþ: \"Sen benim Rabb-i Rahîm'imsin, ben senin âciz bir abdinim.\" "
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\n\n\n\n\n\t0-Geri";
				
	metin=harf_duzelt(hakikat);
	system("cls");
	puts(metin);
	getch();
}

void hakikat_4()
{
	char secim;
	char *metin;
	char hakikat[3][2000]={"\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tAdem babamýz yasak meyveyi yedikten sonra Cennet'ten indirilmiþ, Dünya'ya gönderilmiþti. Hz. Adem dünyaya cuma günü gönderilmiþ ve Hindistan'da Bevz(Nevz) daðýna indirilmiþ."
				" Hz. Adem nasýl tevbe edileceðini bilmiyordu. Nasýl bilsin ki? Ýnsanlýk tarihinde yapýlacak ilk tevbe istiðfardý bu. Hz. Adem Rabb'inden bazý kelimeler telakki etti. Bunun üzerine Allah ona nasýl tevbe edeceðini ilham etti ve Hz. Adem tevbe etmeye baþladý."
				"\n\n\tAdem (a.s) uðradýðý aðýr ibtilâdan dolayý aðlamaya baþladý. Aðlamasý öyle þiddetlendi ki melekler de onun aðlamasýndan aðlaþmaya ve tasasýndan tasalanmaya baþladý."
				"Bunun üzerine Yüce Allah, Adem'e: \"Arþýmýn alt hizasýnda benim bir Harem'im(Yasak bölgem) vardýr. Sen hemen git de, orada benim için bir beyt yap. Meleklerimin, Arþ'ýmý tavaf ettiklerini gördüðün gibi sen de orayý tavaf et ve beni zikr et. Orada senin duaný ve tâatýmda bulunan çocuklarýnýn dualarýný kabul edeceðim.\" diye vahy ederek Mekke'ye gitmesini emreder."
				"\n\n\tAdem (a.s):\"Ey Rabb'im! Bu, benim için nasýl mümkün olur? Ben buna ne güç yetirebilirim, ne de oraya varmaya yol bulabilirim?\" dedi.Cenab-ý Hakk ona kýlavuz olmasý için bir melek gönderdi ve Mekke'ye doðru götürdü."
				"Giderken, yerler, uçsuz bucaksýz çöller ve ovalar onun için dürüldü. Geçeceði her yer; çölller, çukurlar, denizler onun için dürülüp bir adýmda atlanýr, geçilir oldu."
				"Mekke'ye varýncaya kadar, arzdan her nereye ayak bastý, her nerede konakladý ise, orasý bir mâmûre, bereketli bir yer oldu. Ayak bastýðý yer yeþillik oldu. Bir adýmda geçtiði yerler ise boþ bir yer oldu."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevamý----> ",
				"\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tNihayet Mekke'ye gelip eriþtiler. Cebrail, kanadýný yerin dibindeki berk ve sabit kesimine kadar daldýrýp Kâbe'nin temelini açtý. Melekler de 30 kiþinin kaldýramayacaðý aðýr kayalarý, temellere býraktýlar."
				"Adem (a.s) Kâbe'yi, beþ daðdan getirilen taþlarla yaptý. Bu taþlar:\n"
				"\n\t1)Tûr-i Seynâ, \n\t2)Tûr-i Zeytun(Zeyta), \n\t3)Lübnan, \n\t4)Cûdî, \n\t5)Hirâ\tdaðlarýndan getirilmiþti."
				"\n\n\tKâbe'nin inþasý bitince Cebrail, Hz. Adem'i Arafât'a götürdü. Hacc amellerinin hepsini, ona gösterdi."
				"\n\n\tAdem (a.s), Hz. Havva'yý; Hz. Havva da Adem Aleyhisselamý arýyodu. Nihayet, Arafatta buluþtular. Orada birbirlerini görüp tanýdýlar ve Müzdelife'de bir araya geldiler."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\t\tDevamý----> ",
				"\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tCebrail Aleyhisselam, Hz. Adem'i Mekke'ye getirdi. Adem (a.s) Mekke'yi 7 kere tavaf etti. Tavaf ederken Meleklerle karþýlaþtý. Melekler Adem (a.s)'ýn Haccýný tebrik ettiler ve: \"Biz bu Beyt'i, senden iki bin yýl önce tavaf ve Hacc etmiþizdir.\" dediler."
				"\n\n\tAdem (a.s) onlara: \"Siz tavaf ederken ne derdiniz?\" diye sorunca melekler: \"'Sübhânallâhi ve-lhamdü lillâhi ve lâ ilâhe illAllâhu vAllâhu ekber' derdik.\" dediler. Adem (a.s) buna 've lâ havle ve lâ kuvvete illâ billâh' cümlesini ekledi. Bunun üzerine melekler, tavafta, bu cümleyi ekleyerek okumaya baþladýlar."
				"\n\n\tHz. Adem Hacc amellerini yerine getirdiði zaman: \"Ey Rabb'im! Her amel sahibi için bir ecir olur?\" Yüce Allah: \"Ey Adem! Senin de vardýr. Ben seni afv etmiþimdir. Senin zürriyetine gelince, onlardan bu Beyt'e günahý ile gelen kimsenin de, günahýný afv edeceðim!\" buyurdu. Hz. Adem'in tevbesi de bir Cuma günü kabul buyurulmuþtur."
				"\n\n\tAdem (a.s), Hacc'dan sonra, Hz. Havva ile birlikte Hindistan'a döndü. Gecelerinde ve gündüzlerinde içinde barýnmak üzere, bir maðarayý barýnak edindiler."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri"};
	
	j=0;
	while(secim!='0'&secim!=27)
	{
		metin=harf_duzelt(hakikat[j]);
		system("cls");	
		puts(metin);
		secim=getch();
		if(secim==77)			{	if(j!=2)	j++;	}
		else if(secim==75)		{	if(j!=0)	j--;	}
	}
	
}


void hakikat_5()
{
	char *metin;
	char hakikat[]="\n\n\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\t\tÝktisad, sebeb-i izzet ve kemal olduðuna delalet eden bir vakýa: "
				"\n\n\tBir zaman, dünyaca sehavetle meþhur Hâtem-i Tâî, mühim bir ziyafet veriyor. Misafirlerine gayet fazla hediyeler verdiði vakit, çölde gezmeye çýkýyor. Bakar ki: Bir ihtiyar fakir adam, bir yük dikenli çalý ve gevenleri beline yüklemiþ; cesedine batýyor, kanatýyor. Hâtem ona dedi: \"Hâtem-i Tâî, hediyelerle beraber mühim bir ziyafet veriyor. Sen de oraya git; beþ kuruþluk bu çalý yüküne bedel, beþ yüz kuruþ alýrsýn.\" O muktesid ihtiyar demiþ ki: \" Ben, bu dikenli yükümü izzetimle çekerim, kaldýrýrým. Hâtem-i Tâî'nin minnetini almam.\" "
				"\n\n \tSonra, Hâtem-i Tâî'den sormuþlar: \"Sen kendinden daha civanmerd, aziz, kimi bulmuþsun?\" Demiþ: \"Ýþte o sahrada rast geldiðim o muktesid ihtiyarý benden daha aziz, daha yüksek, daha civanmerd gördüm.\""
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\n\n\t0-Geri";
				
	metin=harf_duzelt(hakikat);
	system("cls");
	puts(metin);
	getch();
}


void hakikat_6()
{
	char *metin;
	char hakikat[]="\n\n\n\n\n\n**********************************************                       *************************************************"
				"\n\n\tBir gün Cebrail Aleyhisselâm, Âdem Aleyhisselâm'ýn yanýna gelip:"
				"\n\n\t\"Ben sana 3 þey getirdim. Birisini seç al!\" dedi."
				"\n\n\tÂdem Aleyhisselâm: \"Ey Cebrail! Nedir onlar?\" diye sordu."
				"\n\n\tCebrail Aleyhisselâm: \"Akýl, Hayâ, Din!\" dedi. Âdem Aleyhisselâm: \"Akl'ý seçtim!\" dedi."
				"\n\n\tCebrail Aleyhisselâm; Hayâ ile Din'e: \"Akl'ý size tercih edip seçti. Siz, dönüp gidiniz.!\" dedi."
				"\n\n\tOnlar: \"Biz, her nerede olursa olsun, akýl ile birlikte bulunmakla emr oldunduk!\" dediler, akl'ýn yanýndan ayrýlmadýlar."
				"\n\n***********************************************                       *************************************************"
				"\n\n\n\n\t0-Geri";
	
	metin=harf_duzelt(hakikat);
	system("cls");
	puts(metin);
	getch();
}


void hakikat_7()
{
	char *metin;
	char hakikat[]="\n\n\n\n\n\n**********************************************                       *************************************************"
				"\n\n\tBir Ramazan'da Medineli bir müslüman, Halife Hz. Ömer'i iftar yemeðine davet eder. Yemek sýrasýnda yalnýz Hz. Ömer'e bir kab içinde bir içecek sunulur. Hz. Ömer sorar:"
				"\n\n\t\"Bu nedir?\""
				"\n\n\tEv sahibi cevab verir:"
				"\n\n\t\"Bal þerbetidir efendim, sizin için ayýrmýþtýk da...\""
				"\n\n\tHz. Ömer onu içmeyi reddederek þöyle der:"
				"\n\n\t\"Benim yönetimini üstlendiðim halkýn çoðu içmek için henüz kuyu suyunu bile bulamazken ben burada bal þerbeti içemem.\""
				"\n\n***********************************************                       *************************************************"
				"\n\n\n\n\t0-Geri";
	
	metin=harf_duzelt(hakikat);
	system("cls");
	puts(metin);
	getch();
}


void hakikat_8()
{
	char *metin;
	char hakikat[]="\n\n\n\n\n\n**********************************************                       *************************************************"
				"\n\n\tFatih Sultan Mehmet'in derviþlere karþý çok zaafý vardý. Bir gün onun bu zayýf tarafýndan istifade etmek isteyen, pejmürde kýlýklý bir adam huzura girip:"
				"\n\n\t\"Devletlû Sultaným, ben senin kardeþinim. Malýnýn yarýsýný bana vermen gerek, dedi.\""
				"\n\n\tFatih, kesedarýna: \"Bu fakire bir mangýr ver!\" dedi. Fakat miskin, parayý az bulup:"
				"\n\n\t\"Senin gibi þanlý bir hükümdara, kardeþine bu kadar az para vermek yakýþýr mý?\" dedi."
				"\n\n\tFatih: \"Seninle nerden kardeþ oluyoruz? diye sorunca. Adam: \"Senin de, benim de ilk anamýz Havva, ilk babamýz Âdem Aleyhisselâm deðil mi?\" dedi."
				"\n\n\tBu sefer Hz. Fatih'in cevabý þöyle oldu: \"Sen verdiðim parayý az görüyorsun, halbuki öteki kardeþlerin duyarsa hissene bu kadar da düþmez. Þimdilik bu sana yeter!\""
				"\n\n***********************************************                       *************************************************"
				"\n\n\n\t0-Geri";
	
	metin=harf_duzelt(hakikat);
	system("cls");
	puts(metin);
	getch();
}


void hakikat_9()
{
	char *metin;
	char hakikat[]="\n\n\n\n\n**********************************************                       *************************************************"
				"\n\n\t Ormanlar arasýnda bir gürültü, bir baðýrýp çaðýrmadýr baþladý. Büyük aðaçlar:"
				"\n\n\t- Ne oluyor yahu? Ne baðýrýyorsunuz!?, diye sorduklarýnda, küçükler:"
				"\n\n\t- Kenarlardan baþlamýþlar kesmeye... Adamýn biri elinde bir demirle kesip geliyor, derler."
				"\n\n\tBüyük aðaçlar:\n\t- Korkmayýn çocuklar, korkmayýn... Ýyi baktýnýz mý? Bizden bir þey var mý adamýn elinde? diye sorduklarýnda,"
				"\n\n\tOnlar:\n\t- Var efendim var! Adamýn elindeki kesici þeyin (balta) sapý bizden, diye cevap verirler."
				"\n\n\tO zaman büyük aðaçlarý bir korku kaplar: \"Þimdi korkun iþte... Eðer bizden birisi ise, hepimizi de kesebilir.\" derler."
				"\n\n***********************************************                       *************************************************"
				"\n\n\n\t0-Geri";
	
	metin=harf_duzelt(hakikat);
	system("cls");
	puts(metin);
	getch();
}


void hakikat_10()
{
	char secim;
	char *metin;
	char hakikat[4][2000]={"\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tHazreti Peygamberimiz Ýslâmý tebliðle emrolunduðu zaman, birçok padiþahlara, sultanlara, þahlara mektup yazýp îmana davet ediyor, elçiler gönderip fikirlerini soruyordu. Bunlardan kendisine mektup gönderilen Arap kabile Reislerinden Habbab isminde birisi daha vardý ki, kendisine mektup getiren elçiyi hayli hýrpaladýktan sonra serbest býraktý. Önünde duran mektubu da eline bile almak tenezzülünde bulunmadan adamlarýna:"
				"\n\n\t-Kaldýrýn, þunu önümden, atýn bir yere!, diye emir verdi. Mektubu derhal sultanýn önünden aldýlar, fakat yýrtýp atmadýlar. Diðer evraklarla beraber onu da sarayýn hazinesinde bir sandýða koydular."
				"\n\n\tBu küstah, kendini bilmez sultanýn, Habbab isminde bir de oðlu vardý. Daha yaþý genç, babasýnýn yerine sultan olmaya hazýrlanan, ne isterse kendisinden esirgenmeyen, sarayýn tek oðlu idi. Birgün sarayýn hazinesine girdi. Orada evraklarý karýþtýrýrken, sandýk içine saklanmýþ olan mektubu gördü. Büyük bir dikkatle alýp, tekrar tekrar okudu. Fakat hayret! Okudukça içinde bir ateþ hissediyor, tekrar okuyor:"
				"\n\n\t-Bu mektubu buraya niye koymuþlar acaba?... Ne güzel bir mektup bu. Hem Allah'ýn elçisi olduðunu bildiriyor, kendi dinine davet ediyor, hem de, dinine girmek isteyenlerden hiç bir þey talep etmediðini bildiriyor... Ne güzel sözler bunlar. Demek bizim tek yaratýcýmýz var, O'nun da yer yüzünde bir elçisi var!... diye söyleniyordu kendi kendine."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevamý----> ",
				"\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tÇünkü Mektub-u Þerifte:\"Ey hükümdar! Kendini insanlara Allah olarak taptýrma! Senin ve bütün kâinatýn yaratýcýsý olan Allah'a îman et ki, dünya ve ahirette kurtuluþa eriþesin. O tapýndýðýnýz putlar ve siz cehennemin ateþi olmaktan kurtulun\" diye yazýlýydý. Henüz genç yaþta olan Habbab, mektupta ta'rif edildiði üzere orada îman ederek þehadet getirdi."
				"\n\n\tMektubu okuyup îman ettikten sonra, bu halinden babasýna bahsetmek istedi ise de, babasý onu konuþturmuyor, hemen sözünü keserek: \"Oðlum sakýn ona aldanma! Sen zevk-ü sefana bak, sen benim yerime geçecek, bu milletin reisi olacaksýn. Öyle ne idiði belli olmayan birisine inanýrsan kendine yazýk edersin\" diyerek kendince nasihat ediyordu."
				"\n\n\tFakat Habbab'ýn kafasýna girmiyordu böyle sözler, o bir kere inanmýþtý Allah'a ve O'nun Resulüne... Oðlunun dâvasýndan dönmediðini gören babasý, ona bizzat kendisi ceza vermek istedi. Ayaklarý altýna alarak, öldürmeye kasdedercesine dövmeye baþladý. Öyle çok dövüyordu ki, elinden vezirleri zor aldýlar. Bu kadar yaptýðý eziyet yetmiyormuþ gibi, bir de cellatlarýna emrederek: \"Buna ne iþkence yapýlmak mümkünse yapýn, îmanýndan dönmez, bizim yolumuzu kabul etmezse de en sonunda kellesini kesin\" diye emretti."
				"\n\n\tCellatlar alýp götürdüler... Öyle iþkenceye tâbi tuttular ki, dille ta'rifi mümkün deðil. Üç-dört gün kýzgýn çöllerde su çektirdiler, bir lokma ekmek bile vermiyorlar, ancak bir miktar tuzlu yiyecek veriyorlar, bir damla su içirmiyorlardý: \"Ya dininden dönersin, yahut bu iþkencelerden sonra senin kelleni keseceðiz\" diyorlardý, ama ona hiçbirþey te'sir etmiyor: 'La ilahe illAllah' diyor baþka bir þey demiyordu."
				"\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\tDevamý----> ",
				"\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tÜç dört gün süren iþkenceden sonra, hâlâ dâvasýndan dönmediðini görünce, artýk idamýna karar verdiler. Fakat idamý ile görevlendirilen cellada öyle bir uyku gelmiþti ki, ne yaptý ise de uykudan kurtulamadý. Habbab ise kalýn zincirlerle baðlanmýþtý. O anda olmasa bile; yarýn mutlaka idam edilecekti. Günlerce aç-susuz bu kadar iþkenceye tâbi tutulan, her tarafý kan revan içinde kalan Habbab hazretleri Allah'tan baþka yardým isteyecek kimse bulamýyordu. Ellerini Allah'a açarak þöyle yalvardý:"
				"\n\n\t-Ya Rabbi! Halim sana ma'lum, ben sana inandýðým, senin Resulün Hazreti Muhammed'e inandýðým için bu ezaya tâbi tutuluyorum. Beni bu belâdan ancak sen kurtarýrsýn. Öleceðime deðil, Kâinatýn Nuru, Habibin Muhammed Mustafa'yý görmeden bu âlemden gideceðim için hüzünlüyüm. Beni, ismine âþýk olduðum Resulüne, bir an önce kavuþtur da, ondan sonra ne olursa olsun, Ya Rabbi!, diye yalvarmaya baþladý."
				"\n\n\tOnun, bu hulûs-u kalb ile yalvarýþý; arþ-ý âlâyý titretmiþti. Cenab-ý Allah, hemen Cebrail Aleyhisselâmý göndererek, dileðinin yerine getirilmesini temin etmesini emretti. Cebrail Aleyhisselâm, geldi.. Habbab'in baðlý olduðu zincir sanki çürümüþ bez parçalarý gibi daðýlmaya baþladý. Zincirden kurtulan Hazreti Habbab, hiçbir þey düþünmeden olduðu haliyle Medine tarafýna koþmaya baþladý. Öyle gidiyordu ki, sanki rüzgâr esiyordu. Yetmiþ konaklýk mesafeyi bir gecede aldý."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri",
				"\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tYýrtýlmýþ elbiseleri, kan çamur içinde kalmýþ vücudu ile Medine'ye eriþti. Fakat nasýl bulacaktý mahbubunu? Medine'nin sokaklarýndan birinde aðlayarak gezerken Amr bin As (r.a.) Hazretlerini gördü. Amr Hazretleri:" 
				"\n\n\t-Evlâdým nedir senin bu hâlin? Sen âþýk olmuþ birisine benziyorsun. Derdini bana anlat ki, açsan sana yemek getireyim, çok periþan bir haldesin. Günlerdir yemek yememiþ bir halin var, deyince, genç delikanlý:"
				"\n\n\t-Hayýr, benim arzuladýðým ne yemektir, ne de baþka bir dünya malý, diye cevap verince, anladý mübarek; onun Peygamberimize ve O'nun yoluna âþýk olduðunu..."
				"\n\n\t\"Ben Hazreti Muhammed'e(a.s.m) îman etmiþ bir müslümaným, sýrrýný bana söyle kardeþim. Kimseye söylemeyeceðime dair söz veriyorum.\" deyince Habbab Hazretleri eline sarýlarak: \"Beni Hazret-i Muhammed'e götür\" dedi."
				"\n\n\tTam bu esnada Cenab-ý Allah (C.C.) Cebraili göndererek Peygamberimize haber vermiþ, uzaklardan bir misafirinin geldiðini ve karþýlamasýný ta'lim buyurmuþtu. Hazreti Peygamberimiz, orada bulunan ashâbýyla beraber, Medine sokaklarýndan huzuruna gelmekte olan Hazreti Habbab'ý karþýladý. Ona sadakatýndan dolayý iltifatlar etti:\n\n\t\t\t-Hoþ geldiniz fedakâr oðlum Habbab!, diyerek kucakladý, baðrýna bastý."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----Önceki sayfa\t\t\t\t\t\t\t\t\t0-Geri"};				
	
	j=0;
	while(secim!='0'&secim!=27)
	{
		metin=harf_duzelt(hakikat[j]);
		system("cls");	
		puts(metin);
		secim=getch();
		if(secim==77)			{	if(j!=3)	j++;	}
		else if(secim==75)		{	if(j!=0)	j--;	}
	}

}

