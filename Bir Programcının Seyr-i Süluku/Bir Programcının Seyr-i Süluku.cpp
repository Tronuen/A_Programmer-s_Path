/*****************************************************B�SM�LLAH*********************************************************************
Cevvad-� Mutlak (Celle Celaluhu), her ferd-i z�hayat�n eline lezzet midad�yla ve ihtiya� m�rekkebiyle yaz�lm�� bir tezkereyi vermi�. 
				Onunla evamir-i tekviniyenin pro�ram�n� ve hizmetlerinin fihristesini tevdi' etmi�tir*/
				
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
					
					
					islem1:		//							<<----------------------------------- �SLEM 1
					
					
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
								PlaySoundA("M�zikler/S�rur.wav",NULL,SND_ASYNC);
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
							PlaySoundA("M�zikler/Yakma Yarabbi.wav",NULL,SND_ASYNC);
							
							
							win:		//							<<----------------------------------- W�N
							
							
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
						PlaySoundA("M�zikler/S�rur.wav",NULL,SND_ASYNC);
						goto win;
					}
					
				}
				break;
				
			case '2':
				while(true)
				{
					system("cls");
					menu_2(arazi);
					
					
					islem2:		//							<<--------------------------------------- �SLEM 2
					
					
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


short kontrol(short a, short b, short s)		//Bu kareye daha �nce u�ray�p u�ramad���m�z� kontrol ediyor
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
				boslar[s]=x-1;		boslar[s+1]=y-1;		s+=2;					//Gitti�imiz kareleri diziye al�yoruz.
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
	
	if(*k!=9 && *e<s)		//e'ye ko�ul koymazsak boslar[-]'ye gider ve oralarda bir say� olmad��� i�in hata verir.
	{						// 's' kadar ad�m att���m�z i�in s'den k���k diyoruz.
		*e+=2;
		return boslara_bak_sag(arazi,yeralti,boslar[s-*e],boslar[s+1-*e],s);		//8 tarafa da gidemedi�inde bir �nceki kareye g�nderiyor.
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
/*Sol �st*/	if(x-1>=0 && y-1>=0 && yeralti[x-1][y-1]!=136)
				yeralti[x-1][y-1]++;
/*Yukar�*/	if(x-1>=0 && yeralti[x-1][y]!=136)
				yeralti[x-1][y]++;
/*Sa� �st*/	if(x-1>=0 && y+1<*byt && yeralti[x-1][y+1]!=136)
				yeralti[x-1][y+1]++;
/*Sol */	if(y-1>=0 && yeralti[x][y-1]!=136)
				yeralti[x][y-1]++;
/*Sa� */	if(y+1<*byt && yeralti[x][y+1]!=136)
				yeralti[x][y+1]++;
/*Sol alt*/	if(x+1<10 && y-1>=0 && yeralti[x+1][y-1]!=136)
				yeralti[x+1][y-1]++;
/*A�a��*/	if(x+1<10 && yeralti[x+1][y]!=136)
				yeralti[x+1][y]++;
/*Sa� alt*/	if(x+1<10 && y+1<*byt && yeralti[x+1][y+1]!=136)
				yeralti[x+1][y+1]++;
}


char *harf_duzelt(char metin[1000])
{
	for(i=0;metin[i]!='\0';i++)
		switch(metin[i])
		{
			case '�':	metin[i]=131;	break;
			case '�':	metin[i]=135;	break;
			case '�':	metin[i]=167;	break;
			case '�':	metin[i]=140;	break;
			case '�':	metin[i]=141;	break;
			case '�':	metin[i]=148;	break;
			case '�':	metin[i]=150;	break;
			case '�':	metin[i]=129;	break;
			case '�':	metin[i]=159;	break;
			case '�':	metin[i]=182;	break;
			case '�':	metin[i]=128;	break;
			case '�':	metin[i]=166;	break;
			case '�':	metin[i]=152;	break;
			case '�':	metin[i]=153;	break;
			case '�':	metin[i]=154;	break;
			case '�':	metin[i]=158;	break;
			case '�':	metin[i]=130;	break;
			default: ;
		}	
	
	return metin;
}


void ipuclar()
{
	char ipuclar[6][500]={"Bir s�rada say�lar 1-2-1 �eklinde s�ralanm�� ise 1'lerin bakt��� yer u�urum, 2'nin bakt��� yer bo�tur.",
						"Bir s�rada say�lar 1-2-2-1 �eklinde s�ralanm�� ise 1'lerin bakt��� yer bo�, 2'lerin bakt��� yer u�urumdur.",
						"E�er 1 say�s� kapal� kap�lar�n k��esinde kalm��sa, o k��edeki kap� vartal�d�r.",
						"E�er bir s�rada 2-2 ikilisi varsa bunlar�n hizalar�nda �� kap� kapal� di�erleri a��ksa o kap�lardan ortadaki kesin vartal�d�r.",
						"E�er bir s�rada 1-1 ikilisi varsa o 1'lerin hizas�ndaki kap�lar hari� di�er etraf�ndaki kap�lar bo�tur. ��nk� dip dibe olan bu 1'lerin hizas�ndaki bir kapal� kap� di�erinin k��esine, di�erinin hizas�ndaki de bunun k��esine denk geldi�i i�in vartal� kap� bu ikisinden biridir. Di�erleri bo�tur.",
						"Bir s�rada say�lar 1-2-3-2-1 �eklinde s�ralanm�� ise 1'lerin bakt��� yer bo�, 2'lerin ve 3'lerin bakt��� yer u�urumdur. Bu 3'ten istedi�i kadar olsun(1-2-3-3-...-3-3-2-1)"};
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
					"\n\n\t1-)Say�lar� veya harfleri kullanarak men�lerde ilerleyebilirsiniz. Ana men�de sadece say�lar� kullanabilirsiniz."
					" '0' veya ESC tu�u ile geri gidebilir veya ��k�� yapabilirsiniz."
					"\n\n\t2-)Arkas� u�urumlu(vartal�) kap�lar� a�madan b�t�n kap�lar� a�arsan�z bu terakki s�recini tamamlars�n�z."
					"\n\n\t3-)Bu kap�lar�n bir k�sm�n�n arkas�nda u�urum var. Mesela k���k ve kolay mertebede 15 tane vartal� kap� var. O kap�lardan birini a�t���n�zda vartaya yuvarlan�rs�n�z."
					"\n\n\t4-)Baz� kap�lar�n arkas�nda say�lar vard�r. Bu say�lar o kap�n�n etraf�nda ka� tane u�urumlu kap� oldu�unu g�sterir."
					"\n\n\t5-)Bir kap�n�n arkas�nda en fazla '8' rakam� olabilir."
					"\n\n\t6-)Ancak b�t�n vartal� kap�lar� kilitleyip geri kalan t�m kap�lar� a�t���n�zda terakkinizi bitirebilirsiniz. Veya bir vartadan yuvarlan�n bitsin...:)"
					"\n\n***********************************************                        ************************************************"
					"\n\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tD�sturlar----> ",
					
					"\n\n***********************************************       D�STURLAR       *************************************************"
					"\n\n\t1-)En temel i�lemimiz kap� a�mad�r. Ana men�de '1' se�ene�ine t�klad���m�zda bizden koordinatlar� girmemizi isteyecek. Biz de a�mak istedi�imiz kap�n�n koordinatlar�n� bo�luk b�rakarak giriyoruz."
					"\n\n\t2-)Burada yard�m alma(himmet) se�ene�i dikkatinizi �ekmi�tir. 'H' tu�una basarak himmet al�rsan�z program size g�venli herhangi bir kap�y� a�acakt�r. Standart mertebede 3 yard�m hakk�n�z vard�r. B�lgenin b�y�kl���ne ve imtihan�n zorlu�una g�re himmet say�n�z de�i�ebilir."
					"\n\n\t3-)Vartal� oldu�unu d���nd���n�z alanlar� kilitlemek veya i�aretlemek i�in ana men�den '2' se�ene�ine t�kl�yoruz."
					"\n\n\t4-)Burada 'K' veya '1' tu�una basarak girdi�iniz koordinatl� kap�y� kilitleyebilirsiniz."
					"\n\n\t5-)'�' veya '2' tu�una basarak ��phelendi�iniz kap�y� ��pheli olarak i�aretliyoruz."
					"\n\n\t6-)Bu i�aretlemelerin avantaj� kap� a�arken yanl��l�kla istemedi�iniz kap�y� a�may� engellemek i�indir. ��aretli kap�y� a�mak i�in tekrar i�aretleme men�s�ne gelip i�areti kald�rman�z gerekiyor. Bunun i�in ayn� i�lemleri yap�yorsunuz."
					"\n\t7-)G�rebilece�iniz �zere burda da himmet hakk�n�z var. Bunu kulland���n�zda program size kesin vartal� olan ve daha �nce kilitlemedi�iniz bir kap�y� kilitler. Standart mertebede 1 tane himmet alma hakk�n�z vard�r. Tahmin edebildi�iniz �zere 'H' tu�una basarak kullan�yoruz."
					"\n\n***********************************************                       *************************************************"
					"\n\n       <----Esaslar\t\t\t\t\t\t\t\t\t\t  0-Geri",
					
					"\n\n\n\n\n***********************************************        H�LELER        *************************************************"
					"\n\n\t1-)�ncelikle buray� bulmay� ba�ard���n i�in seni tebrik ederim. Zeki birisin. Ya da sadece �ansl�yd�n.",
					"\n\n\n\n\n***********************************************        H�LELER        *************************************************"
					"\n\n\t1-)Hileleri mi unuttun? San�r�m haf�zan pek kuvvetli de�il...",
					"\n\t2-)Hile konsolunu a�mak i�in �ift t�rnak(\") yani ESC tu�unun alt�ndaki � tu�una bas�n."
					"\n\n\t3-)Hileleri yazarken ba��na kesme i�areti(-) koyun. Misal; -sesi kes"
					"\n\n\tHile Kodlar�:"
					"\n\n\t-sesi kes ==>�alan m�zi�i durdurmak i�in yaz�l�r. (arada bo�luk var)"
					"\n\t-hakikat50 ==>50 tane g�venli kap� a�ar."
					"\n\t-hakikat100 ==>100 tane g�venli kap� a�ar."
					"\n\t-kilitle10 ==>Arkas� u�urumlu 10 kap�y� kilitler."
					"\n\t-kilitle20 ==>Arkas� u�urumlu 20 kap�y� kilitler."
					"\n\n***********************************************                        ************************************************"
					"\n\n\n\n\n\n\n\n\t\t\t\t\t\tHileci ba��na bir ka� kere u�rayarak onu tatmin edebilirsiniz. :)"};				
	
	
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
	char hakaretler[8][100]={"Elin s�r�t� de mi?",
							"Kesin elin s�r�m��t�r",
							"Her zamanki gibi sallayanlardans�n i�te...",
							"Dedem bile senden daha iyi yazard�!",
							"Bir hileyi bile d�zg�n yazam�yorsun mal!",
							"San�r�m hileyi unuttun. Aaa tesad�fe bak ki ben de unuttum. :)",
							"Bilmiyorsan �ek git �urdan! Onca i�imiz g�c�m�z aras�nda...",
							"Ulan biz o kadar program� k�ral�m sistemi hackleyelim, sen bir hileyi bile yazama!"};
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
					case 0:		PlaySoundA("M�zikler/Bitiri�.wav",NULL,SND_ASYNC);	break;
					
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
	char mucizeler[5][10000]={"\n\n\n\n**********************************************   MUC�ZAT-I NEBEV�YE   *************************************************"
				"\n\n\t1) Resul-i Ekrem Aleyhissal�t� Vessel�m'�n Hazret-i Zeyneb ile tezevv�c� vel�mesinde, Hazret-i Enes'in v�lidesi �mm-� S�leym, bir-iki avu� hurmay� ya� ile kavurarak bir kaba koyup Hazret-i Enes'le Peygamber Aleyhissal�t� Vessel�m'a g�nderdi." 
				"Enes'e ferman etti ki: \"Filan, filan� �a��r. Hem kime tesad�f etsen davet et.\" Enes de kime rast geldiyse �a��rd�. ��y�z kadar sahabe gelip, Suffe ve H�cre-i Saadeti doldurdular. "
				"Ferman etti: \"Onar onar halka olunuz!\" Sonra m�barek elini o az taam �zerine koydu, dua etti, \"Buyurun\" dedi. B�t�n o ��y�z adam yediler, tok olup kalkt�lar. Enes'e ferman etmi�: \"Kald�r!\" Enes demi� ki: \"Bilmedim, taam kab�n� koydu�um vakit mi taam �oktu, yoksa kald�rd���m vakit mi �oktu farkedemedim.\""
				"\n\n\t2) Bir gazvede ordu a� kald�. Resul-i Ekrem Aleyhissal�t� Vessel�m'a m�racaat ettiler. Ferman etti ki: \"Heybelerinizde kalan bakiyye-i erzak� toplay�n�z!\" Herkes azar birer par�a hurma getirdi. En �ok getiren d�rt avu� getirebildi. Bir kilime koydular. Seleme der ki: \"Mecmuunu ben tahmin ettim, oturmu� bir ke�i kadar ancak vard�.\"" 
				"Sonra Resul-i Ekrem Aleyhissal�t� Vessel�m bereketle dua edip, ferman etti: \"Herkes kab�n� getirsin!\" Ko�u�tular, geldiler. O ordu i�inde hi�bir kap kalmad�, hepsini doldurdular. Hem fazla kald�. "
				"\n\n\tSahabeden bir r�vi demi�:\"O bereketin gidi�at�ndan anlad�m; e�er ehl-i Arz gelseydi, onlara dahi k�fi gelecekti\""
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevam�----> ",
				
				"\n\n\n\n**********************************************   MUC�ZAT-I NEBEV�YE   *************************************************"
				"\n\n\t3) Hazret-i C�bir �bn-i Abdullah-il Ensar� beyan ediyor: \"Biz bin be�y�z ki�i, Gazve-i Hudeybiye'de susad�k. Resul-i Ekrem Aleyhissal�t� Vessel�m k�rba denilen deriden bir kap sudan abdest ald�, sonra elini i�ine soktu. G�rd�m ki, parmaklar�ndan �e�me gibi su ak�yor. Bin be�y�z ki�i i�ip, kaplar�n� o k�rbadan doldurdular. S�lim �bn-i Ebi-l Ca'de, C�bir'den sormu�: \"Ka� ki�i idiniz?\" C�bir demi� ki: \"Y�zbin ki�i de olsayd�, yine k�fi gelirdi. Fakat biz, onbe� y�z (yani bin be�y�z) idik.\"" 
				"\n\n\t��te �u mu'cize-i bahirenin r�vileri, manen bin be�y�z kadard�rlar. ��nki f�trat-� be�eriyede, yalana yalan demek bir meyl-i arzusu vard�r. Sahabeler ise s�dk ve do�ruluk i�in, can ve mal ve peder ve v�lidelerini ve kavim ve kab�lelerini feda edip, s�dk ve hak i�in fedai olduklar� halde; hem \"Benden bilerek yalan bir�ey haber veren, Cehennem ate�inden yerini haz�rlas�n!\" mealindeki had�s-i �erifin tehdidine kar��, yalana mukabil s�k�t etmeleri m�mk�n de�ildir. Madem s�k�t ettiler; o haberi kabul ettiler, manen i�tirak edip tasdik ediyorlar demektir."
				"\n\n\t4) Gazve-i Taif'te, Resul-i Ekrem Aleyhissal�t� Vessel�m gece at �st�nde giderken uykusu geliyordu. O halde iken, bir sidre a�ac�na rastgeldi. A�a� ona yol verip, at�n� incitmemek i�in, iki �akk oldu. Resul-i Ekrem Aleyhissal�t� Vessel�m, hayvan ile i�inden ge�ti. T� zaman�m�za kadar o a�a�, iki ayak �st�nde, muhterem bir vaziyette kald�."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\tDevam�----> ",
				
				"\n\n\n\n**********************************************   MUC�ZAT-I NEBEV�YE   *************************************************"
				"\n\n\t5) Hazret-i Enes (h�dim-i Nebev�) demi� ki: Resul-i Ekrem Aleyhissal�t� Vessel�m'�n yan�nda idik. Avucuna k���k ta�lar� ald�, m�barek elinde tesbih etmeye ba�lad�lar. Sonra Ebu Bekir-is S�dd�k'�n eline koydu, yine tesbih ettiler. Sonra Hazret-i �mer'in eline koydu, yine tesbih ettiler. Sonra ald� yere koydu, sustular. Sonra yine ald�, Hazret-i Osman'�n eline koydu, yine tesbihe ba�lad�lar. Sonra Hazret-i Enes ve Ebu Zerr diyorlar ki: \"Ellerimize koydu, sustular.\""
				"\n\n\t6) Resul-i Ekrem Aleyhissal�t� Vessel�m, Ebu Bekir-is S�dd�k, �mer-�l Faruk ve Osman-� Zinnureyn ile Uhud Da��'n�n ba��na ��kt�lar. Cebel-i Uhud ya onlar�n mehabetlerinden veya kendi s�rur ve sevincinden lerzeye geldi, k�m�ldand�. Resul-i Ekrem Aleyhissal�t� Vessel�m ferman etti ki: '�sb�d y� uhud feinnema aleyke nebiyy�n ve s�dd�kun ve �eh�d�ni' �u had�s, Hazret-i �mer ve Osman �ehid olacaklar�na bir ihbar-� gayb�dir. "
				"\n\n\t�u misalin tetimmesi olarak nakledilmi� ki: Resul-i Ekrem Aleyhissal�t� Vessel�m Mekke'den hicret etti�i ve k�ffarlar takibe ��kt�klar� vakit, Sebir nam�ndaki da�a ��kt�lar. Sebir dedi: \"Ya Resulallah, benden ininiz! Korkar�m, benim �st�mde sizi vururlarsa, Allah beni tazib eder. Onun i�in korkar�m.\"bCebel-i Hira �a��rd�: \" Y� Resulullah, Bana gel.\" Bu s�r i�indir ki, ehl-i kalb, Sebir'de havf(korku) ve Hira'da da emniyeti hissederler. Bu misalden anla��l�r ki: O koca da�lar, birer m�stakil abddir, m�sebbihtir ve vazifedard�rlar. Peygamber Aleyhissal�t� Vessel�m'� tan�r ve severler; ba��bo� de�illerdir."
				"\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\tDevam�----> ",

				"\n\n\n\n**********************************************   MUC�ZAT-I NEBEV�YE   *************************************************"
				"\n\n\t7) Bir menba'-� garaib olan Gazve-i K�bra-y� Bedir'de, Ukka�e �bn-il Mihsan-il Esed�'nin m��riklerle d�����rken k�l�nc� k�r�ld�. Resul-i Ekrem Aleyhissal�t� Vessel�m ona k�l�nca mukabil kal�nca bir de�nek verdi. Dedi: \"Bununla harbet.\" Birden de�nek, biiznillah uzun, beyaz bir k�l�n� oldu. Onunla harbetti. Hayat� mikdar�nca, t� Yemame Harbi'nde �ehid oluncaya kadar boynunda ta��d�." 
				"�u h�dise kat'�dir. ��nki Ukka�e b�t�n hayat�nda onunla iftihar etmi� ve o k�l�n� \"El-Avn\" nam�yla me�hur olmu�. ��te Hazret-i Ukka�e'nin iftihar� ve k�l�nc�n Avn nam�yla, k�l�n�lar�n fevkinde i�tihar�, �u h�disenin iki h�ccetidir."
				"\n\n\t8) B�y�k bir imam olan �bn-i Vehb haber veriyor ki: Gazve-i Bedr'in ond�rt �ehidinden birisi olan Muavviz �bn-i Afra', Ebu Cehil ile d�����rken; Ebu Cehil-i La�n, o kahraman�n bir elini kesmi�. O da �teki eliyle elini tutup, Resul-i Ekrem Aleyhissal�t� Vessel�m'�n yan�na gelmi�. Resul-i Ekrem Aleyhissal�t� Vessel�m onun elini yine yerine yap��t�rd�, t�k�r���n� ona s�rd�; birden �ifa buldu. Yine harbe gitti, �ehid oluncaya kadar harbetti." 
				"Hem yine �mam-� Celil �bn-i Vehb haber veriyor ki: O gazvede Hubeyb �bn-i Yesaf'�n omuz ba��na bir k�l�n� vurulmu� ki, bir �akk� ayr�lm�� gibi deh�etli bir yara a��lm��. Resul-i Ekrem Aleyhissal�t� Vessel�m onun kolunu omuzuna eliyle yap��t�rm��, nefes etmi�; �ifa bulmu�."
				"��te �u iki vak�a, �endan �h�d�dir ve haber-i v�hiddir; fakat �bn-i Vehb gibi bir imam tashih etse, Gazve-i Bedir gibi bir menba'-� mu'cizat olan bir gazvede olsa, hem bu iki vak�ay� and�racak �ok misaller bulunsa; elbette �u iki vak�a, kat'� ve vaki'dir denilebilir."		
				"\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\tDevam�----> ",

				"\n\n\n\n*****************************     BU PAR�A ALTUN VE ELMAS �LE YAZILSA L�YAKATI VAR     *********************************"
				"\n\n\tEvet s�b�kan bahsi ge�mi�: Avucunda k���k ta�lar�n zikir ve tesbih etmesi; 'Ve ma rameyte iz rameyte' s�rr�yla ayn� avucunda, k���c�k ta� ve toprak, d��mana top ve g�lle h�km�nde onlar� inhizama sevketmesi;" 
				"'Ven �eggal kamer' nass� ile ayn� avucunun parma��yla Kamer'i iki par�a etmesi; ve ayn� el, �e�me gibi on parma��ndan suyun akmas� ve bir orduya i�irmesi;" 
				"ve ayn� el, hastalara ve yaral�lara �ifa olmas�, elbette o m�barek el, ne kadar h�rika bir mu'cize-i kudret-i �lahiye oldu�unu g�sterir."
				"\n\n\tG�ya ahbab i�inde o elin avucu k���k bir zikirhane-i S�bhan�dir ki, k���c�k ta�lar dahi i�ine girse, zikir ve tesbih ederler."
				"\n\tVe a'daya kar�� k���c�k bir cephane-i Rabban�dir ki; i�ine ta� ve toprak girse, g�lle ve bomba olur."
				"\n\tVe yaral�lar ve hastalara kar�� k���c�k bir eczahane-i Rahman�dir ki, hangi derde temas etse derman olur."
				"\n\tVe celal ile kalkt��� vakit, Kamer'i par�alay�p Kab-� Kavseyn �eklini verir; "
				"\n\tve cemal ile d�nd��� vakit, �b-� kevser ak�tan on musluklu bir �e�me-i rahmet h�km�ne girer."
				"\n\n\tAcaba b�yle bir z�t�n bir tek eli, b�yle acib mu'cizata mazhar ve medar olsa; o z�t�n H�l�k-� K�inat yan�nda ne kadar makbul oldu�u ve davas�nda ne kadar sad�k bulundu�u ve o el ile biat edenler, ne kadar bahtiyar olacaklar�, bedahet derecesinde anla��lmaz m�?.."
				"\n\n******************************************                                 ********************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\t0-Geri"};
	
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
				"\n\n\tBir zaman bir b�y�k h�kim, iki hizmetk�r�n� -her birisine 24 alt�n verip- iki ay uzakl�kta has ve g�zel bir �iftli�ine ikamet etmek i�in g�nderiyor. Ve onlara emreder ki \"�u para ile yol ve bilet masraf� yap�n�z. Hem oradaki meskeninize l�z�m b�z� �eyleri m�b�yaa ediniz. Bir g�nl�k mesafede bir istasyon vard�r. Hem araba, hem gemi, hem �imendifer, hem tayyare bulunur. Sermayeye g�re binilir.\""
				"\n\n\t�ki hizmetk�r, ders ald�ktan sonra giderler. Birisi bahtiy�r idi ki, istasyona kadar bir par�a masraf eder. Fakat o masraf i�inde, efendisinin ho�una gidecek �yle g�zel bir ticaret elde eder ki, sermayesi birden bine ��kar."
				"\n\n\t�teki hizmetk�r, bedbaht, serseri oldu�undan istasyona kadar 23 alt�n�n� sarfeder. Kumara-mumara verip z�yi eder. Birtek alt�n� kal�r. Arkada�� ona der: \"Y�hu, �u liran� bir bilete ver. T� bu uzun yolda yayan ve a� kalmayas�n. Hem bizim efendimiz ker�mdir; belki merhamet eder. etti�in kusuru affeder. Seni de tayyareye bindirirler. Bir g�nde mahall-i ikametimize gideriz. Yoksa, iki ayl�k bir ��lde a�, yayan, yaln�z gitmeye mecbur olursun."
				"\n\n\tAcaba �u adam inad edip, o tek liras�n� bir def�ne anahtar� h�km�nde olan bir bilete vermeyip, muvakkat bir lezzet i�in sef�hete sarfetse; gayet ak�ls�z, zararl�, bedbaht oldu�unu, en ak�ls�z adam dahi anlamaz m�?"
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevam�----> ",
				"\n\n***********************************************                       *************************************************"
				"\n\n\t��te ey namazs�z adam! Ve ey namazdan ho�lanmayan nefsim!"
				"\n\n\tO h�kim ise; Rabbimiz, Hal�k'�m�zd�r. O iki hizmetk�r yolcu ise; biri: M�tedeyyin, namaz�n� �evk ile k�lar. Di�eri: Gafil, namazs�z insanlard�r. O 24 alt�n ise; yirmid�rt saat her g�ndeki �m�rd�r. O has �iftlik ise; Cennet'tir. O istasyon ise; kabirdir. O seyehat ise; kabre, ha�re, ebede gidecek be�er yolculu�udur. Amele g�re, takv� kuvvetine g�re, o uzun yolu m�tef�vit derecede kat'ederler. Bir k�s�m ehl-i takv� berk gibi, bin senelik yolu bir g�nde keser. Bir k�sm� da hay�l gibi, ellibin senelik mesafeyi bir g�nde kat'eder. Kur'�n-� Az�m���an �u hakikate iki �yetiyle i��ret eder. O bilet ise; NAMAZd�r. Bir tek saat, be� vakit namaza abdestle k�fi gelir."
				"\n\n\tAcaba, 23 saatini, �u k�sac�k hayat-� d�nyeviyeye sarf eden ve o uzun hayat-� ebed�yeye bir tek saatini sarfetmeyen; ne kadar zarar eder, ne kadar nefsine zulmeder, ne kadar hil�f-� ak�l hareket eder! Z�r�, bin adam�n i�tirak etti�i bir piyango kumar�na yar� mal�n� vermek, ak�l kabul ederse; halbuki kazan� ihtimali binde birdir. Sonra yirmid�rtten 1 mal�n�, y�zde doksandokuz ihtim�l ile kazanc� musaddak bir hazine-i ebed�yeye vermemek; ne kadar hil�f-� ak�l ve hikmet hareket etti�ini, ne kadar ak�ldan uzak d��t���n�, kendini �k�l zanneden adam anlamaz m�?"
				"\n\n\tH�lbuki: Namazda; ruhun, kalbin, akl�n b�y�k bir rahat� vard�r, hem cisme de o kadar a��r bir i� de�ildir."
				"\n\n\tHem, namaz k�lan�n di�er m�bah d�nyev� amelleri, g�zel bir niyet ile ib�det h�km�n� al�r. Bu s�rette b�t�n serm�ye-i �mr�n�, �hirete mal edebilir. F�ni �mr�n� bir cihette ibk� eder."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri"};
	
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
					"\n\n\tBir vakit iki asker, uzak bir �ehire gitmek i�in emir al�yorlar. Beraber giderler; t�, yol ikile�ir. Bir adam orada bulunur, onlara der: \"�u sa�daki yol, hi� zarar� olmamakla beraber, onda giden yolculardan ondan dokuzu b�y�k k�r ve rahat g�r�r. Soldaki yol ise, menfaat� olmamakla beraber, on yolcusundan dokuzu zarar g�r�r. Hem ikisi, k�sa ve uzunlukta birdirler. Yaln�z bir fark var ki, intizams�z, h�k�metsiz olan sol yolun yolcusu �antas�z, sil�hs�z gider. Zahir� bir h�ffet, yalanc� bir rahatl�k g�r�r. �ntizam-� asker� alt�ndaki sa� yolun yolcusu ise, mugaddi h�l�salardan dolu d�rt okkal�k bir �anta ve her ad�vv� alt ve ma�lub edecek iki k�yyelik bir m�kemmel m�r� sil�h� ta��maya mecburdur.\""
					"\n\n\tO iki asker, o muarrif adam�n s�z�n� dinledikten sonra �u bahtiyar nefer, sa�a gider. Bir batman a��rl��� omuzuna ve beline y�kler. Fakat kalbi ve ruhu, binler batman minnetlerden ve korkulardan kurtulur. �teki bedbaht nefer ise, askerli�i b�rak�r. Nizama t�bi olmak istemez, sola gider. Cismi bir batman a��rl�ktan kurtulur, fakat kalbi binler batman minnetler alt�nda ve ruhu hadsiz korkular alt�nda ezilir. Hem herkese dilenci, hem her �eyden, her h�diseden titrer bir surette gider. T�, mahall-i maksuda yeti�ir. Orada, �si ve ka�ak cezas�n� g�r�r."
					"\n\n\tAskerlik nizam�n� seven, �anta ve sil�h�n� muhafaza eden ve sa�a giden nefer ise, kimseden minnet almayarak, kimseden havf etmeyerek rahat-� kalb ve vicdan ile gider. T� o matlub �ehire yeti�ir. Orada, vazifesini g�zelce yapan bir namuslu askere m�nasib bir m�k�fat g�r�r."
					"\n\n\n***********************************************                       *************************************************"
					"\n\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevam�----> ",
					"\n\n\n\n\n***********************************************                       *************************************************"
					"\n\n\t��te ey nefs-i serke�! Bil ki: O iki yolcu; biri muti-i kanun-u �lah�, birisi de �si ve hevaya t�bi insanlard�r. O yol ise, hayat yoludur ki; �lem-i ervahtan gelip kabirden ge�er, �hirete gider. O �anta ve sil�h ise, ibadet ve takvad�r. �badetin �endan zahir� bir a��rl��� var. Fakat manas�nda �yle bir rahatl�k ve hafiflik var ki, tarif edilmez. ��nki �bid, namaz�nda der: 'E�hed� el la ilahe illAllah' Yani: \"H�l�k ve Rezzak, ondan ba�ka yoktur. Zarar ve menfaat, onun elindedir. O hem Hak�m'dir, abes i� yapmaz. Hem Rah�m'dir; ihsan�, merhameti �oktur\" diye itikad etti�inden her �eyde bir hazine-i rahmet kap�s�n� bulur. Dua ile �alar. Hem her �eyi kendi Rabbisinin emrine m�sahhar g�r�r, Rabbisine iltica eder. Tevekk�l ile istinad edip her musibete kar�� tahassun eder. �man�, ona bir emniyet-i t�mme verir."
					"\n\n\tEvet her hakik� hasenat gibi cesaretin dahi menba�, imand�r, ubudiyettir. Her seyyiat gibi cebanetin dahi menba�, dalalettir. Evet tam m�nevver-�l kalb bir �bidi, k�re-i arz bomba olup patlasa, ihtimaldir ki, onu korkutmaz. Belki h�rika bir kudret-i Samedaniyeyi, lezzetli bir hayret ile seyredecek. Fakat me�hur bir m�nevver-�l ak�l denilen kalbsiz bir f�s�k feylesof ise; g�kte bir kuyruklu y�ld�z� g�rse, yerde titrer. \"Acaba bu serseri y�ld�z Arz�m�za �arpmas�n m�?\" der; evhama d��er. (Bir vakit b�yle bir y�ld�zdan Amerika titredi. �oklar� gece vakti hanelerini terkettiler.)"
					"\n\n\n***********************************************                       *************************************************"
					"\n\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\tDevam�----> ",
					"\n\n\n\n***********************************************                       *************************************************"
					"\n\n\tEvet insan, nihayetsiz �eylere muhta� oldu�u halde; sermayesi hi� h�km�nde... Hem nihayetsiz musibetlere maruz oldu�u halde; iktidar�, hi� h�km�nde bir �ey... �deta sermaye ve iktidar�n�n dairesi, eli nereye yeti�irse o kadard�r. Fakat emelleri, arzular� ve elemleri ve belalar� ise; dairesi, g�z�, hayali nereye yeti�irse ve gidinceye kadar geni�tir. Bu derece �ciz ve za�f, fakir ve muhta� olan ruh-u be�ere ibadet, tevekk�l, tevhid, teslim; ne kadar az�m bir k�r, bir saadet, bir nimet oldu�unu, b�t�n b�t�n k�r olmayan g�r�r, derk eder."
					"\n\n\tMal�mdur ki: Zarars�z yol, zararl� yola -velev on ihtimalden bir ihtimal ile olsa- tercih edilir. Halbuki mes'elemiz olan ubudiyet yolu, zarars�z olmakla beraber ondan dokuz ihtimal ile bir saadet-i ebediye hazinesi vard�r. F�sk ve sefahet yolu ise; -hatt� f�s�k�n itiraf�yla dahi- menfaats�z oldu�u halde, ondan dokuz ihtimal ile �ekavet-i ebediye hel�keti bulundu�u; icma ve tevat�r derecesinde hadsiz ehl-i ihtisas�n ve m��ahedenin �ehadetiyle sabittir. Ve ehl-i zevkin ve ke�fin ihbarat�yla muhakkakt�r."
					"\n\n\tElhas�l: �hiret gibi, d�nya saadeti dahi, ibadette ve Allah'a asker olmaktad�r. \n�yle ise, biz daima 'Elhamdu lillahi ala-tt�ati ve-ttevf�g' demeliyiz. Ve m�sl�man oldu�umuza ��kretmeliyiz."
					"\n\n\n***********************************************                       *************************************************"
					"\n\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri"};
	
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
				"\n\n\t\tCenab-� Hak nefse demi� ki: \"Ben neyim, sen nesin?\" Nefis demi�: \"Ben benim, sen sensin!\""
				"\n\n\t\t\tAzab vermi�, Cehennem'e atm��, yine sormu�. Yine demi�: \"Ene ene, ente ente.\" "
				"\n\n\t\tHangi nevi azab� vermi�, enaniyetten vazge�memi�. Sonra a�l�k ile azab vermi�, yani a� b�rakm��. "
				"\n\n\tYine sormu�: \"Men ene vema ente?\" Nefis demi�: \"Sen benim Rabb-i Rah�m'imsin, ben senin �ciz bir abdinim.\" "
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
				"\n\n\tAdem babam�z yasak meyveyi yedikten sonra Cennet'ten indirilmi�, D�nya'ya g�nderilmi�ti. Hz. Adem d�nyaya cuma g�n� g�nderilmi� ve Hindistan'da Bevz(Nevz) da��na indirilmi�."
				" Hz. Adem nas�l tevbe edilece�ini bilmiyordu. Nas�l bilsin ki? �nsanl�k tarihinde yap�lacak ilk tevbe isti�fard� bu. Hz. Adem Rabb'inden baz� kelimeler telakki etti. Bunun �zerine Allah ona nas�l tevbe edece�ini ilham etti ve Hz. Adem tevbe etmeye ba�lad�."
				"\n\n\tAdem (a.s) u�rad��� a��r ibtil�dan dolay� a�lamaya ba�lad�. A�lamas� �yle �iddetlendi ki melekler de onun a�lamas�ndan a�la�maya ve tasas�ndan tasalanmaya ba�lad�."
				"Bunun �zerine Y�ce Allah, Adem'e: \"Ar��m�n alt hizas�nda benim bir Harem'im(Yasak b�lgem) vard�r. Sen hemen git de, orada benim i�in bir beyt yap. Meleklerimin, Ar�'�m� tavaf ettiklerini g�rd���n gibi sen de oray� tavaf et ve beni zikr et. Orada senin duan� ve t�at�mda bulunan �ocuklar�n�n dualar�n� kabul edece�im.\" diye vahy ederek Mekke'ye gitmesini emreder."
				"\n\n\tAdem (a.s):\"Ey Rabb'im! Bu, benim i�in nas�l m�mk�n olur? Ben buna ne g�� yetirebilirim, ne de oraya varmaya yol bulabilirim?\" dedi.Cenab-� Hakk ona k�lavuz olmas� i�in bir melek g�nderdi ve Mekke'ye do�ru g�t�rd�."
				"Giderken, yerler, u�suz bucaks�z ��ller ve ovalar onun i�in d�r�ld�. Ge�ece�i her yer; ��lller, �ukurlar, denizler onun i�in d�r�l�p bir ad�mda atlan�r, ge�ilir oldu."
				"Mekke'ye var�ncaya kadar, arzdan her nereye ayak bast�, her nerede konaklad� ise, oras� bir m�m�re, bereketli bir yer oldu. Ayak bast��� yer ye�illik oldu. Bir ad�mda ge�ti�i yerler ise bo� bir yer oldu."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevam�----> ",
				"\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tNihayet Mekke'ye gelip eri�tiler. Cebrail, kanad�n� yerin dibindeki berk ve sabit kesimine kadar dald�r�p K�be'nin temelini a�t�. Melekler de 30 ki�inin kald�ramayaca�� a��r kayalar�, temellere b�rakt�lar."
				"Adem (a.s) K�be'yi, be� da�dan getirilen ta�larla yapt�. Bu ta�lar:\n"
				"\n\t1)T�r-i Seyn�, \n\t2)T�r-i Zeytun(Zeyta), \n\t3)L�bnan, \n\t4)C�d�, \n\t5)Hir�\tda�lar�ndan getirilmi�ti."
				"\n\n\tK�be'nin in�as� bitince Cebrail, Hz. Adem'i Araf�t'a g�t�rd�. Hacc amellerinin hepsini, ona g�sterdi."
				"\n\n\tAdem (a.s), Hz. Havva'y�; Hz. Havva da Adem Aleyhisselam� ar�yodu. Nihayet, Arafatta bulu�tular. Orada birbirlerini g�r�p tan�d�lar ve M�zdelife'de bir araya geldiler."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\t\tDevam�----> ",
				"\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tCebrail Aleyhisselam, Hz. Adem'i Mekke'ye getirdi. Adem (a.s) Mekke'yi 7 kere tavaf etti. Tavaf ederken Meleklerle kar��la�t�. Melekler Adem (a.s)'�n Hacc�n� tebrik ettiler ve: \"Biz bu Beyt'i, senden iki bin y�l �nce tavaf ve Hacc etmi�izdir.\" dediler."
				"\n\n\tAdem (a.s) onlara: \"Siz tavaf ederken ne derdiniz?\" diye sorunca melekler: \"'S�bh�nall�hi ve-lhamd� lill�hi ve l� il�he illAll�hu vAll�hu ekber' derdik.\" dediler. Adem (a.s) buna 've l� havle ve l� kuvvete ill� bill�h' c�mlesini ekledi. Bunun �zerine melekler, tavafta, bu c�mleyi ekleyerek okumaya ba�lad�lar."
				"\n\n\tHz. Adem Hacc amellerini yerine getirdi�i zaman: \"Ey Rabb'im! Her amel sahibi i�in bir ecir olur?\" Y�ce Allah: \"Ey Adem! Senin de vard�r. Ben seni afv etmi�imdir. Senin z�rriyetine gelince, onlardan bu Beyt'e g�nah� ile gelen kimsenin de, g�nah�n� afv edece�im!\" buyurdu. Hz. Adem'in tevbesi de bir Cuma g�n� kabul buyurulmu�tur."
				"\n\n\tAdem (a.s), Hacc'dan sonra, Hz. Havva ile birlikte Hindistan'a d�nd�. Gecelerinde ve g�nd�zlerinde i�inde bar�nmak �zere, bir ma�aray� bar�nak edindiler."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri"};
	
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
				"\n\n\t\t�ktisad, sebeb-i izzet ve kemal oldu�una delalet eden bir vak�a: "
				"\n\n\tBir zaman, d�nyaca sehavetle me�hur H�tem-i T��, m�him bir ziyafet veriyor. Misafirlerine gayet fazla hediyeler verdi�i vakit, ��lde gezmeye ��k�yor. Bakar ki: Bir ihtiyar fakir adam, bir y�k dikenli �al� ve gevenleri beline y�klemi�; cesedine bat�yor, kanat�yor. H�tem ona dedi: \"H�tem-i T��, hediyelerle beraber m�him bir ziyafet veriyor. Sen de oraya git; be� kuru�luk bu �al� y�k�ne bedel, be� y�z kuru� al�rs�n.\" O muktesid ihtiyar demi� ki: \" Ben, bu dikenli y�k�m� izzetimle �ekerim, kald�r�r�m. H�tem-i T��'nin minnetini almam.\" "
				"\n\n \tSonra, H�tem-i T��'den sormu�lar: \"Sen kendinden daha civanmerd, aziz, kimi bulmu�sun?\" Demi�: \"��te o sahrada rast geldi�im o muktesid ihtiyar� benden daha aziz, daha y�ksek, daha civanmerd g�rd�m.\""
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
				"\n\n\tBir g�n Cebrail Aleyhissel�m, �dem Aleyhissel�m'�n yan�na gelip:"
				"\n\n\t\"Ben sana 3 �ey getirdim. Birisini se� al!\" dedi."
				"\n\n\t�dem Aleyhissel�m: \"Ey Cebrail! Nedir onlar?\" diye sordu."
				"\n\n\tCebrail Aleyhissel�m: \"Ak�l, Hay�, Din!\" dedi. �dem Aleyhissel�m: \"Akl'� se�tim!\" dedi."
				"\n\n\tCebrail Aleyhissel�m; Hay� ile Din'e: \"Akl'� size tercih edip se�ti. Siz, d�n�p gidiniz.!\" dedi."
				"\n\n\tOnlar: \"Biz, her nerede olursa olsun, ak�l ile birlikte bulunmakla emr oldunduk!\" dediler, akl'�n yan�ndan ayr�lmad�lar."
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
				"\n\n\tBir Ramazan'da Medineli bir m�sl�man, Halife Hz. �mer'i iftar yeme�ine davet eder. Yemek s�ras�nda yaln�z Hz. �mer'e bir kab i�inde bir i�ecek sunulur. Hz. �mer sorar:"
				"\n\n\t\"Bu nedir?\""
				"\n\n\tEv sahibi cevab verir:"
				"\n\n\t\"Bal �erbetidir efendim, sizin i�in ay�rm��t�k da...\""
				"\n\n\tHz. �mer onu i�meyi reddederek ��yle der:"
				"\n\n\t\"Benim y�netimini �stlendi�im halk�n �o�u i�mek i�in hen�z kuyu suyunu bile bulamazken ben burada bal �erbeti i�emem.\""
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
				"\n\n\tFatih Sultan Mehmet'in dervi�lere kar�� �ok zaaf� vard�. Bir g�n onun bu zay�f taraf�ndan istifade etmek isteyen, pejm�rde k�l�kl� bir adam huzura girip:"
				"\n\n\t\"Devletl� Sultan�m, ben senin karde�inim. Mal�n�n yar�s�n� bana vermen gerek, dedi.\""
				"\n\n\tFatih, kesedar�na: \"Bu fakire bir mang�r ver!\" dedi. Fakat miskin, paray� az bulup:"
				"\n\n\t\"Senin gibi �anl� bir h�k�mdara, karde�ine bu kadar az para vermek yak���r m�?\" dedi."
				"\n\n\tFatih: \"Seninle nerden karde� oluyoruz? diye sorunca. Adam: \"Senin de, benim de ilk anam�z Havva, ilk babam�z �dem Aleyhissel�m de�il mi?\" dedi."
				"\n\n\tBu sefer Hz. Fatih'in cevab� ��yle oldu: \"Sen verdi�im paray� az g�r�yorsun, halbuki �teki karde�lerin duyarsa hissene bu kadar da d��mez. �imdilik bu sana yeter!\""
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
				"\n\n\t Ormanlar aras�nda bir g�r�lt�, bir ba��r�p �a��rmad�r ba�lad�. B�y�k a�a�lar:"
				"\n\n\t- Ne oluyor yahu? Ne ba��r�yorsunuz!?, diye sorduklar�nda, k���kler:"
				"\n\n\t- Kenarlardan ba�lam��lar kesmeye... Adam�n biri elinde bir demirle kesip geliyor, derler."
				"\n\n\tB�y�k a�a�lar:\n\t- Korkmay�n �ocuklar, korkmay�n... �yi bakt�n�z m�? Bizden bir �ey var m� adam�n elinde? diye sorduklar�nda,"
				"\n\n\tOnlar:\n\t- Var efendim var! Adam�n elindeki kesici �eyin (balta) sap� bizden, diye cevap verirler."
				"\n\n\tO zaman b�y�k a�a�lar� bir korku kaplar: \"�imdi korkun i�te... E�er bizden birisi ise, hepimizi de kesebilir.\" derler."
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
				"\n\n\tHazreti Peygamberimiz �sl�m� tebli�le emrolundu�u zaman, bir�ok padi�ahlara, sultanlara, �ahlara mektup yaz�p �mana davet ediyor, el�iler g�nderip fikirlerini soruyordu. Bunlardan kendisine mektup g�nderilen Arap kabile Reislerinden Habbab isminde birisi daha vard� ki, kendisine mektup getiren el�iyi hayli h�rpalad�ktan sonra serbest b�rakt�. �n�nde duran mektubu da eline bile almak tenezz�l�nde bulunmadan adamlar�na:"
				"\n\n\t-Kald�r�n, �unu �n�mden, at�n bir yere!, diye emir verdi. Mektubu derhal sultan�n �n�nden ald�lar, fakat y�rt�p atmad�lar. Di�er evraklarla beraber onu da saray�n hazinesinde bir sand��a koydular."
				"\n\n\tBu k�stah, kendini bilmez sultan�n, Habbab isminde bir de o�lu vard�. Daha ya�� gen�, babas�n�n yerine sultan olmaya haz�rlanan, ne isterse kendisinden esirgenmeyen, saray�n tek o�lu idi. Birg�n saray�n hazinesine girdi. Orada evraklar� kar��t�r�rken, sand�k i�ine saklanm�� olan mektubu g�rd�. B�y�k bir dikkatle al�p, tekrar tekrar okudu. Fakat hayret! Okuduk�a i�inde bir ate� hissediyor, tekrar okuyor:"
				"\n\n\t-Bu mektubu buraya niye koymu�lar acaba?... Ne g�zel bir mektup bu. Hem Allah'�n el�isi oldu�unu bildiriyor, kendi dinine davet ediyor, hem de, dinine girmek isteyenlerden hi� bir �ey talep etmedi�ini bildiriyor... Ne g�zel s�zler bunlar. Demek bizim tek yarat�c�m�z var, O'nun da yer y�z�nde bir el�isi var!... diye s�yleniyordu kendi kendine."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t0-Geri\t\t\t\t\t\t\t\t\t\t\tDevam�----> ",
				"\n\n\n\n***********************************************                       *************************************************"
				"\n\n\t��nk� Mektub-u �erifte:\"Ey h�k�mdar! Kendini insanlara Allah olarak tapt�rma! Senin ve b�t�n k�inat�n yarat�c�s� olan Allah'a �man et ki, d�nya ve ahirette kurtulu�a eri�esin. O tap�nd���n�z putlar ve siz cehennemin ate�i olmaktan kurtulun\" diye yaz�l�yd�. Hen�z gen� ya�ta olan Habbab, mektupta ta'rif edildi�i �zere orada �man ederek �ehadet getirdi."
				"\n\n\tMektubu okuyup �man ettikten sonra, bu halinden babas�na bahsetmek istedi ise de, babas� onu konu�turmuyor, hemen s�z�n� keserek: \"O�lum sak�n ona aldanma! Sen zevk-� sefana bak, sen benim yerime ge�ecek, bu milletin reisi olacaks�n. �yle ne idi�i belli olmayan birisine inan�rsan kendine yaz�k edersin\" diyerek kendince nasihat ediyordu."
				"\n\n\tFakat Habbab'�n kafas�na girmiyordu b�yle s�zler, o bir kere inanm��t� Allah'a ve O'nun Resul�ne... O�lunun d�vas�ndan d�nmedi�ini g�ren babas�, ona bizzat kendisi ceza vermek istedi. Ayaklar� alt�na alarak, �ld�rmeye kasdedercesine d�vmeye ba�lad�. �yle �ok d�v�yordu ki, elinden vezirleri zor ald�lar. Bu kadar yapt��� eziyet yetmiyormu� gibi, bir de cellatlar�na emrederek: \"Buna ne i�kence yap�lmak m�mk�nse yap�n, �man�ndan d�nmez, bizim yolumuzu kabul etmezse de en sonunda kellesini kesin\" diye emretti."
				"\n\n\tCellatlar al�p g�t�rd�ler... �yle i�kenceye t�bi tuttular ki, dille ta'rifi m�mk�n de�il. ��-d�rt g�n k�zg�n ��llerde su �ektirdiler, bir lokma ekmek bile vermiyorlar, ancak bir miktar tuzlu yiyecek veriyorlar, bir damla su i�irmiyorlard�: \"Ya dininden d�nersin, yahut bu i�kencelerden sonra senin kelleni kesece�iz\" diyorlard�, ama ona hi�bir�ey te'sir etmiyor: 'La ilahe illAllah' diyor ba�ka bir �ey demiyordu."
				"\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\tDevam�----> ",
				"\n\n\n\n\n***********************************************                       *************************************************"
				"\n\n\t�� d�rt g�n s�ren i�kenceden sonra, h�l� d�vas�ndan d�nmedi�ini g�r�nce, art�k idam�na karar verdiler. Fakat idam� ile g�revlendirilen cellada �yle bir uyku gelmi�ti ki, ne yapt� ise de uykudan kurtulamad�. Habbab ise kal�n zincirlerle ba�lanm��t�. O anda olmasa bile; yar�n mutlaka idam edilecekti. G�nlerce a�-susuz bu kadar i�kenceye t�bi tutulan, her taraf� kan revan i�inde kalan Habbab hazretleri Allah'tan ba�ka yard�m isteyecek kimse bulam�yordu. Ellerini Allah'a a�arak ��yle yalvard�:"
				"\n\n\t-Ya Rabbi! Halim sana ma'lum, ben sana inand���m, senin Resul�n Hazreti Muhammed'e inand���m i�in bu ezaya t�bi tutuluyorum. Beni bu bel�dan ancak sen kurtar�rs�n. �lece�ime de�il, K�inat�n Nuru, Habibin Muhammed Mustafa'y� g�rmeden bu �lemden gidece�im i�in h�z�nl�y�m. Beni, ismine ���k oldu�um Resul�ne, bir an �nce kavu�tur da, ondan sonra ne olursa olsun, Ya Rabbi!, diye yalvarmaya ba�lad�."
				"\n\n\tOnun, bu hul�s-u kalb ile yalvar���; ar�-� �l�y� titretmi�ti. Cenab-� Allah, hemen Cebrail Aleyhissel�m� g�ndererek, dile�inin yerine getirilmesini temin etmesini emretti. Cebrail Aleyhissel�m, geldi.. Habbab'in ba�l� oldu�u zincir sanki ��r�m�� bez par�alar� gibi da��lmaya ba�lad�. Zincirden kurtulan Hazreti Habbab, hi�bir �ey d���nmeden oldu�u haliyle Medine taraf�na ko�maya ba�lad�. �yle gidiyordu ki, sanki r�zg�r esiyordu. Yetmi� konakl�k mesafeyi bir gecede ald�."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\t\t0-Geri",
				"\n\n\n\n***********************************************                       *************************************************"
				"\n\n\tY�rt�lm�� elbiseleri, kan �amur i�inde kalm�� v�cudu ile Medine'ye eri�ti. Fakat nas�l bulacakt� mahbubunu? Medine'nin sokaklar�ndan birinde a�layarak gezerken Amr bin As (r.a.) Hazretlerini g�rd�. Amr Hazretleri:" 
				"\n\n\t-Evl�d�m nedir senin bu h�lin? Sen ���k olmu� birisine benziyorsun. Derdini bana anlat ki, a�san sana yemek getireyim, �ok peri�an bir haldesin. G�nlerdir yemek yememi� bir halin var, deyince, gen� delikanl�:"
				"\n\n\t-Hay�r, benim arzulad���m ne yemektir, ne de ba�ka bir d�nya mal�, diye cevap verince, anlad� m�barek; onun Peygamberimize ve O'nun yoluna ���k oldu�unu..."
				"\n\n\t\"Ben Hazreti Muhammed'e(a.s.m) �man etmi� bir m�sl�man�m, s�rr�n� bana s�yle karde�im. Kimseye s�ylemeyece�ime dair s�z veriyorum.\" deyince Habbab Hazretleri eline sar�larak: \"Beni Hazret-i Muhammed'e g�t�r\" dedi."
				"\n\n\tTam bu esnada Cenab-� Allah (C.C.) Cebraili g�ndererek Peygamberimize haber vermi�, uzaklardan bir misafirinin geldi�ini ve kar��lamas�n� ta'lim buyurmu�tu. Hazreti Peygamberimiz, orada bulunan ash�b�yla beraber, Medine sokaklar�ndan huzuruna gelmekte olan Hazreti Habbab'� kar��lad�. Ona sadakat�ndan dolay� iltifatlar etti:\n\n\t\t\t-Ho� geldiniz fedak�r o�lum Habbab!, diyerek kucaklad�, ba�r�na bast�."
				"\n\n\n***********************************************                       *************************************************"
				"\n\n\t<----�nceki sayfa\t\t\t\t\t\t\t\t\t0-Geri"};				
	
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

