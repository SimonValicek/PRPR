#include<stdio.h>																					//zadefinovanie, respekt�ve v�pis kni�n�c, z ktor�ch budem �erpa�
#include<stdlib.h>
#include<string.h>
#define VELKOST 200																					//defin�cie kon�t�nt (polku som s�ce ani nepou�il)
#define CYKLUS 9
#define MENO 50
#define RODCISLO 11
#define ROOMNUM 4
#define TEMA 150
#define AUTOR 200
#define TYP 3
#define CAS 5
#define DATUM 9
#define POM 400
#define ZAZNAMY 6

void V(FILE **fr)													
{
char a=' ',b='\n';
int i=0,pom=0,j=0,pom1=0,pom2=0,tj=0,tri=0,dva=0,t=0,feb=0,x=0,parne,neparne,sucet;					//klasick� defin�cie
if ((*fr=fopen("zoznam.txt","r"))==NULL) printf("Neotvoreny subor\n");								//otvor� s�bor
while (a!=EOF){																						//funkcia while - na��tavanie znaku, pokia� nepr�deme na koniec s�bor
	printf("Prezenter: ");																			//Vyp�e na obrazovku prezent�r:
		for(a=getc(*fr);a!=b;i++){																	//skenujeme znaky po koniec riadku, akceptuje len p�smen� a medzery
			if(((a<'A')||(a>'z'))&&((a!=' ')&&(a!='\n'))) j++;										//Kontroluje podmienku "povolen� znaky"
			putchar(a);a=getc(*fr);}																//naskenovan� znak vyp�e a na��ta nov�
		if(j||i>50)printf(" Nekorektne zadany vstup PREZENTER");									//skontroluje podmienku dl�ka riadku
		putchar('\n'); i=0; j=0;																	//vyp�e znak nov�ho riadku a vynuluje premenn�
	printf("Rodne cislo: "); 																		//skenujeme znaky po koniec riadku, n�sledne prebehne overenie spr�vnosti rodn�ho ��sla - deliteln� 11
    	for(a=getc(*fr);a!=b;i++){																	//vyp�e Rodne cislo: na obrazovku (riadok vy��ie), skenuje znak a� po znak konca riadku
    		if(i%2!=0) neparne+=a;																	//kontroluje podmienku delite�nosti 11timi
    		else parne+=a;		
			putchar(a);a=getc(*fr);}																//vyp�e na��tan� znak a na��ta nov�
			sucet=parne-neparne;																		
		if((((neparne%11)!=0)&&(sucet!=0))||(i!=10)||(j))printf(" Nekorektne zadany vstup RODNE CISLO");					//kontroluje podmienky, vr�tane d�ky rodn�ho ��sla	
    	putchar('\n');i=0;j=0;parne=0;neparne=0;sucet=0;											//vyp�e znak nov�ho riadku, vynuluje premenn�
    printf("Kod miestnosti: "); 																	//vyp�e K�d miestnosti
    	for(a=getc(*fr);a!=b;i++){																	//to ist� ako v predo�l�ch, overujeme korektnos� (1. znak velke pismeno, nasledne 2 cisla)
			if((i==0)&&((a<'A')||(a>'Z'))) j++;														
			if(((i==1)||(i==2))&&((a<'0')||(a>'9'))) j++;
			putchar(a);a=getc(*fr);}																//to ist� ako vy��ie, vyp�e na��tan� znak "a" a do premennej a na��ta nov� (�alej to u� nebudem komentova�)
		if((j)||(i!=3)) printf(" Nekorektne zadany vstup KOD MIESTNOSTI");							//kontroluje podmienky, zabezpe�uje v�pis
		putchar('\n');i=0;j=0;																		//znak nov�ho riadka, nuluje premenn�
    printf("Nazov prispevku: ");																	
		for(a=getc(*fr);a!=b;i++){																	//v podstate je to v�etko to ist�, dalej budem komentova� u� len d�le�it� veci
			putchar(a);a=getc(*fr);}
		if(i>=TEMA)printf(" Nekorektne zadany vstup NAZOV PRISPEVKU");
		putchar('\n');i=0;
    printf("Autor prezentacie: ");
	 	for(a=getc(*fr);a!=b;i++){
		 	if(((a<'A')||(a>'z'))&&((a!=' ')&&(a!='\n')&&(a!='#'))) j++;		
		 	putchar(a);a=getc(*fr);}
		if((j)||(i>=AUTOR))printf(" Nekorektne zadany vstup AUTOR PREZENTACIE"); 					//�alej to u� nebudem rozpisova�, je to to ist�, len podmienky sa menia
	 	putchar('\n');i=0;j=0;
    printf("Typ prezentovania ");
		for(a=getc(*fr);a!=b;i++){
			if((i==0)&&((a!='P')&&(a!='U'))) j++;
			if((i==1)&&((a!='D')&&(a!='P'))) j++;
			putchar(a);a=getc(*fr);} 
		if((j)||(i!=2)) printf(" Nekorektne zadany vstup Typ prezentovania");
    	putchar('\n');i=0;j=0;
    printf("Cas prezentacie: "); 
    	for(a=getc(*fr);a!=b;i++){
    		if((i==0)&&((a<'0')||(a>'2'))) j++;
    		if((i==0)&&(a=='2')) pom1++;
    		if(((i==1)&&(pom1!=0))&&((a<'0')||(a>'3'))) j++; 
    		if(((i==1)&&(pom1==0))&&((a<'0')||(a>'9'))) j++;
    		if((i==2)&&((a<'0')||(a>'5'))) j++;
    		if((i==3)&&((a<'0')||(a>'9'))) j++;
    		putchar(a);a=getc(*fr);}
    	if((j)||(i!=4))printf(" Nekorektne zadany vstup CAS");
    	putchar('\n');i=0;j=0;														//Tu za��na najlep�ia �as� projektu
    printf("Datum prezentacie: "); 													// �a�ko sa v tom zorientova�, ale na toto dielo som py�n�
    	for(a=getc(*fr);a!=b;i++){													//nasleduj�ci cyklus kontroluje v�etko, okrem priestupn�ho roka (febru�r m� len 28 dn�)
    		if((i==4)&&((a!='0')&&(a!='1'))) j++;
			if((i==4)&&(a=='0')) x++;	
    		if((i==4)&&(a=='1'))
    		if((i==5)&&(x!=0)&&(a=='0')) j++;
    		if(((i==5)&&(x!=0))&&((a=='1')||(a=='3')||(a=='5')||(a=='7')||(a=='8'))) tj++;
    		if(((i==5)&&(x!=0))&&((a=='4')||(a=='6')||(a=='9'))) t++;
    		if((i==5)&&(x!=0)&&(a=='2')) feb++;
    		if((i==5)&&(x==0)&&((a<'0')||(a>'2'))) j++;
    		if(((i==5)&&(x==0))&&((a=='0')||(a=='2'))) tj++;
    		if((i==5)&&(x==0)&&(a=='1')) t++;
    		if((i==6)&&((t!=0)||(tj!=0))&&(a=='3')) tri++;
    		if((i==6)&&((t!=0)||(tj!=0))&&((a<'0')||(a>'3'))) j++;
    		if((i==6)&&(feb!=0)&&(a=='2')) dva++;
    		if((i==6)&&(feb!=0)&&((a<'0')||(a>'2'))) j++;
    		if((i==7)&&(tri!=0)&&(tj!=0)&&((a<'0')||(a>'1'))) j++;
    		if((i==7)&&(tri!=0)&&(t!=0)&&(a!='0')) j++;
    		if((i==7)&&(dva!=0)&&((a<'0')||(a>'8'))) j++;
			putchar(a);a=getc(*fr);}
		if((j)||(i>8))printf(" Nekorektne zadany vstup DATUM");	
	putchar('\n');i=0;x=0;t=0,tj=0,feb=0,dva=0,tri=0;									
		putchar('\n');i=0;j=0;pom1=0;
	putchar('\n');
	a=getc(*fr);}}																					//kon��me pr�zdnym riadkom v s�bore
																	
void O(FILE *fr){
if (fr==NULL) {printf("Subor este nebol otvoreny.\n"); }											//kontroluje, �i bol s�bor otvoren�
else{   
	rewind(fr);																						//vr�ti kurzor na za�iatok s�boru
	char **nazov,**meno,**znak,riadok[VELKOST],**kod,retazec[4];									//defin�cie premenn�ch a pol�
    int*datum,*cas,date,j,i,k=0,f,g,h,pom,*sort,*pomocna;
    nazov=(char**) calloc(VELKOST,sizeof(char*));													//nasleduj�ce riadky s� alok�cie dynamick�ch pol�
    meno=(char**) calloc(VELKOST,sizeof(char*));
    znak=(char**) calloc(VELKOST, sizeof(char*));
    cas=(int*) calloc(VELKOST,sizeof(int));					
    datum=(int*) calloc(VELKOST, sizeof(int));
	kod=(char**)calloc(VELKOST, sizeof(char*));	
	sort=(int*)calloc(VELKOST, sizeof(int));
	pomocna=(int*)calloc(VELKOST, sizeof(int));
   	j=0;														
while(1){																							//while(1) bude be�a� donekone�na, pokia� cyklus neukon��me nejak inak
        fgets(riadok,VELKOST, fr);																	//na��ta riadok zo s�boru
		riadok[strlen(riadok)-1] = 0;																//odstr�ni '\n' z riadku
		meno[j]=strdup(riadok);																		//zap�e do po�a na to ur�en�ho
//printf("%s\n",meno[j]);																			//.....�alej sa to opakuje s ka�d�m z�znamom (z�znamy sa triedia do jendotliv�ch pol�)
        fgets(riadok,VELKOST, fr);
        fgets(riadok,VELKOST, fr);
        riadok[strlen(riadok)-1]=0;
        kod[j]=strdup(riadok);
//printf("%s\n",kod[j]);
        fgets(riadok,VELKOST, fr);
        riadok[strlen(riadok)-1]=0;
        nazov[j]=strdup(riadok);
//printf("%s\n",nazov[j]);
        fgets(riadok,VELKOST, fr);
        fgets(riadok,VELKOST, fr);
        riadok[strlen(riadok)-1]=0;
        znak[j]=strdup(riadok);
//printf("%s\n",znak[j]);
        fgets(riadok,VELKOST, fr);
        riadok[strlen(riadok)-1]=0;
        cas[j]=atoi(strdup(riadok));
//printf("%d\n",cas[j]);
        fgets(riadok,VELKOST, fr);
        riadok[strlen(riadok)-1]=0;
        datum[j]=atoi(strdup(riadok));
//printf("%d\n",datum[j]);
        fgets(riadok,VELKOST,fr);
//putchar('\n');																					
        j++;																						//zvy�uje index....v�etky polia maj� zap�san� hodnoty [0], v �al�om kole sa id� zapisova� hodnoty pol� [1]
        if(feof(fr)) break;}																		//ak sme pri�li na koniec s�boru, nekone�n� cyklus while(1) sa ukon��
    for(f=0;f!=j;f++)																				//tzv. bubblesort
	pomocna[f]=cas[f]; 																				//v nasleduj�cich riadkoch si zorad�me �asy pod�a hodnoty (od najmen�ieho po najv��ie - tak ako hodiny plyn�)
  	for(f=0;f!=j;f++){
  		for(g=j-1;g>f;g--){
  			if(pomocna[g]<pomocna[g-1]){
  				pom=pomocna[g-1];
  				pomocna[g-1]=pomocna[g];
  				pomocna[g]=pom;}}
		if(sort[g-1]==pomocna[g])continue;															//ak sa dve hodnoty rovnaj�, po��ta sa iba jedna
  		sort[g]=pomocna[g];}	  																	//zoraden� by sme mali
	scanf("%d %s",&date,retazec);																	//na��tame d�tum a k�d miestnosti
	for(g=0;g!=j;g++){																				//vyp�e zodpovedaj�ce re�azce (hodnoty) pre UD a UP, tak, ako sme ich zoradili pod�a �asu
		for(i=0;i<j;i++){
			if(date==datum[i] && sort[g]==cas[i] && (strcmp(retazec,kod[i])==0) && ((strcmp("UP",znak[i])==0) || (strcmp("UD",znak[i])==0) )){
				printf("%d %s %s	%s\n",cas[i],znak[i],meno[i],nazov[i]);}}}													
		putchar('\n');																				//pr�zdny riadok
	for(g=0;g!=j;g++){																				//vyp�e zodpovedaj�ce re�azce (hodnoty) pre PD a PP, tak, ako sme ich zoradili pod�a �asu
		for(i=0;i<j;i++){		
			if(date==datum[i] && sort[g]==cas[i] && (strcmp(retazec,kod[i])==0) && ((strcmp("PP",znak[i])==0) || (strcmp("PD",znak[i])==0) )){
				printf("%d %s %s	%s\n",cas[i],znak[i],meno[i],nazov[i]);}}}}} 					//vybaven�

void N(FILE *fr,char ***prezenter, char***kod,char***nazov,char***autor,char***spec_znak,double**rod_cislo,int**cas,int**datum){   					//PERFEKTNE
	char riadok[VELKOST];
	int pocetr=1,i,j=0,time,date;
	double rod_c=0;
	if (fr==NULL) {printf("Subor este nebol otvoreny.\n"); }
	else{
	rewind(fr);
	while ((fgets(riadok, VELKOST, fr)) != NULL) pocetr++;
	rewind(fr);
//printf("%d\n",pocetr);																		//Funkcia funguje tak ako m�, dynamick� polia s� vytvoren� a �daje v nich s� zap�san� spr�vne
	i=pocetr/CYKLUS;																			//pre overenie spr�vnosti som si ich pomocou funkcie printf vytla�il do konzoly
	*prezenter = (char**) calloc(ZAZNAMY, sizeof(char*));											//t�to tla� som tam nechal pre bud�cu pr�cu s projektom/kontrolu
    *rod_cislo = (double*) calloc(ZAZNAMY, sizeof(double));											//pou��val som funkciu fgets na z�skanie riadku a cyklus while na jej opakovanie
    *kod = (char**) calloc(ZAZNAMY, sizeof(char*));													
    *nazov = (char**) calloc(ZAZNAMY, sizeof(char*));
    *autor = (char**) calloc(ZAZNAMY, sizeof(char*));
    *spec_znak = (char**) calloc(ZAZNAMY, sizeof(char*));
    *cas = (int*) calloc(ZAZNAMY, sizeof(int));
    *datum = (int*) calloc(ZAZNAMY, sizeof(int));
	while(1){
			fgets(riadok, VELKOST, fr);
			riadok[strlen(riadok)-1]=0;
			(*prezenter)[j]=strdup(riadok);
//printf("%s\n",(*prezenter)[j]);
			fgets(riadok, VELKOST, fr);
			(*rod_cislo)[j]=atof(strdup(riadok));
//printf("%.f\n",(*rod_cislo)[j]);
			fgets(riadok, VELKOST, fr);
			riadok[strlen(riadok)-1]=0;
			(*kod)[j]=strdup(riadok);
//printf("%s\n",(*kod)[j]);
			fgets(riadok, VELKOST, fr);
			riadok[strlen(riadok)-1]=0;
			(*nazov)[j]=strdup(riadok);
//printf("%s\n",(*nazov)[j]);
			fgets(riadok, VELKOST, fr);
			riadok[strlen(riadok)-1]=0;
			(*autor)[j]=strdup(riadok);
//printf("%s\n",(*autor)[j]);
        	fgets(riadok, VELKOST, fr);
        	riadok[strlen(riadok)-1]=0;
        	(*spec_znak)[j]=strdup(riadok);
//printf("%s\n",(*spec_znak)[j]);
        	fgets(riadok, VELKOST, fr);
        	(*cas)[j]=atoi(strdup(riadok));
//printf("%d\n",(*cas)[j]);
			fgets(riadok,VELKOST, fr);
			(*datum)[j]=atoi(strdup(riadok));
//printf("%d\n",(*datum)[j]);
			fgets(riadok,VELKOST,fr);
//putchar('\n');
			j++;
			if(feof(fr))break;}}}  
			    
void S(int overenie,int*datum,char***spec_znak,int*cas,char***prezenter,char***nazov){				//PERFEKTN�............ZADAVA SA {UP,UD,PP,PD}
	if(overenie==-1) printf("Polia nie su vytvorene.\n");											//kontrola vytvorenia dynamick�ch pol�
	else{
	int date,j,pocet=6,i=0;																			//asi nie je �o doda�, v jednoduchosti je kr�sa, ten riadok vy��ie je tam pre m�a, lebo som v�dy zad�val
	char znak[3];																					//zl� vstup a potom som sa tr�pil, pre�o mi to nefunguje
	scanf("%d %s",&date,znak);
		for(j=0;j<pocet;j++){
		if(date==datum[j] && strcmp(znak,(*spec_znak)[j])==0){										//kontrola podmienok zo zadania
			printf("%d	%s		%s\n",cas[j],(*prezenter)[j],(*nazov)[j]);i++;}}					//v�pis pod�a zadania
	if(i==0) printf("Pre dany vstup neexistuju zaznamy.\n");}	}

void H(int overenie,double*rod_cislo,char***spec_znak){												//histogram vytvoren� pomocou statick�ho trojrozmern�ho po�a na princ�p tabu�ky
if(overenie==-1) printf("Polia nie su vytvorene.\n");
else{
	int i=0,l=0,j,y,z,datum,den,mesiac,rok,vek,x=0,a=0,b=9;											//nasleduj�ce riadky s� triedenie do kateg�ri� pohlavie a vek
	int tabulka [2][10][4]={0};
	for(j=0;j<ZAZNAMY;j++){
//printf("%s\n",(*spec_znak)[j]);
//printf("%.f\n",(rod_cislo)[j]);
		datum=(rod_cislo)[j]/10000;
		den=datum%100; // printf("%d\n",den);
		datum/=100;
		mesiac=datum%100; 
		if(mesiac>12){
			x++; mesiac-=50;
//printf("Je to zena.\n");	
//printf("%d\n",mesiac);
		}
//		else{
//printf("Je to muz.\n");
//printf("%d\n",mesiac);}
		datum/=100;
		rok=datum%100;
		if(rok<=21) rok+=2000;
		else rok+=1900;
//printf("Datum narodenia je %d. %d. %d\n",den,mesiac,rok);
		if(mesiac<11) vek=2021-rok;
		else{
			if((mesiac==11)&&(den<=6)) vek=2021-rok;
			else vek=2021-rok-1;}
//printf("Dotycny ma %d rokov\n",vek);
//putchar('\n');
		y=vek/10;
		if (strcmp("UP",(*spec_znak)[j])==0) z=0;												//nasleduj�ce riadky s� triedenie do kateg�ri� pod�a �peci�lneho znaku (typ prezentovania)
		if (strcmp("UD",(*spec_znak)[j])==0) z=1;
		if (strcmp("PP",(*spec_znak)[j])==0) z=2;
		if (strcmp("PD",(*spec_znak)[j])==0) z=3;
		tabulka[x][y][z] +=1;
		x=0;y=0;z=0;}
//putchar('\n');																				//riadky ni��ie sl��ia len na v�pis tabu�ky
		printf("MUZI	UP	UD	PP	PD\n");														//najprv tabu�ka mu�i
		for(i=0;i<10;i++){
			printf("%d-%d",a,b);
			for(l=0;l<4;l++)
				printf("	%d",tabulka[0][i][l]);
			putchar('\n');
			l=0;a+=10;b+=10;}
		putchar('\n');
			a=0;b=9;
		printf("ZENY	UP	UD	PP	PD\n");														//potom tabu�ka �eny
		for(i=0;i<10;i++){
			printf("%d-%d",a,b);
			for(l=0;l<4;l++)
				printf("	%d",tabulka[1][i][l]);
			putchar('\n');
			l=0;a+=10;b+=10;}
		putchar('\n');}}

void P(int overenie,char***prezenter,char***nazov,char***kod,char***spec_znak,int*cas,int*datum,double*rod_cislo){
	if (overenie==-1) printf("Polia nie su vytvorene.\n");
	else{
	int j,i=1,pocet=6,pole[ZAZNAMY],por,a,err=0;
	char code[4],s_znak[3],time[5],date[9];
	double rc;																						
	scanf("%lf",&rc);													
	for(j=0;j<ZAZNAMY;j++){																					//ak sa rovn� rodn� ��slo (nami naskenovan�), vyp�e s�visiace �daje na obrazovku
		if(rc==rod_cislo[j]){	
			printf("%d %s	%s\n",i,(*prezenter)[j],(*nazov)[j]);pole[i]=j;i++;}}
	if (i==1) printf("Zadane udaje su nespravne.\n");
	else {
	printf("Zadaj nove hodnoty: ");
while(1){																									//nekone�n� cyklus while, ktor� kon�� na��tan�m spr�vnych �dajov z kl�vesnice
	err=0;																									//pomocn� err = error
	scanf("%d %s %s %s %s",&por,code,s_znak,time,date);														//na��tanie ��siel, re�azcov
	a=pole[por];																							//nasleduj�ce riadky s� overovania podmienok, d�tum ako vo funkcii v(nepo��ta priestupn� rok, inak o�etren� dokonale)
	if((por<=0)||(por>=i)){
//printf("chyba v poradi\n");
		err++;}
//	else printf("%d\n",por);
	if((strlen(code)!=3)||((code[0] < 65)||(code[0] > 90))||((code[1] < 48)||(code[1] > 57))||((code[2] < 48)||(code[2] > 57))){
//		printf("chyba v kode\n");
		err++;}
	else{
		(*kod)[a]=strdup(code);
//		printf("%s\n",(*kod)[a]);
		}		
	if(((s_znak[0]!='P')&&(s_znak[0]!='U'))||((s_znak[1]!='P')&&(s_znak[1]!='D'))||(s_znak[2]!='\0')){
//		printf("chyba v znaku\n");
		err++;}
	else{
		(*spec_znak)[a]=strdup(s_znak);
//		printf("%s\n",(*spec_znak)[a]);
		}
	if((((atoi(time)/100)>23)||((atoi(time)/100)<0))||((atoi(time)%100)>59)||(strlen(time)!=4)){
//		printf("chyba v case\n");
		err++;}
	else{
	 	(cas)[a]=atoi(strdup(time));
//		printf("%d\n",(cas)[a]);
		}
	if ((atoi(datum)%10000000>0)||strlen(date)!=8||((date[4]!='0')&&(date[4]!='1'))||((date[6]<'0')||(date[6]>'3'))||((date[4]=='0')&&(date[5]=='2')&&((date[6]<'0')||(date[6]>'2')))||((date[4]=='1')&&((date[5]!='0')&&(date[5]!='1')&&(date[5]!='2')))||((date[4]=='0')&&((date[5]=='1')||(date[5]=='3')||(date[5]=='5')||(date[5]=='7')||(date[5]=='8'))&&(date[6]=='3')&&((date[7]!='0')&&(date[7]!='1')))||((date[4]=='1')&&((date[5]=='0')||(date[5]=='2'))&&(date[6]=='3')&&((date[7]!='0')&&(date[7]!='1')))||((date[4]=='0')&&(date[5]=='2')&&(date[6]=='2')&&((date[7]<'0')||(date[7]>'8')))||((date[4]=='0')&&((date[5]=='4')||(date[5]=='6')||(date[5]=='9'))&&(date[6]=='3')&&(date[7]!='0'))||((date[4]=='1')&&(date[5]=='1')&&(date[6]=='3')&&(date[7]!='0'))){
//		printf("chyba v datume\n");
		err++;}	
	else{
		(datum)[a]=atoi(strdup(date));
//		printf("%d\n",(datum)[a]);
		}	
	if(err!=0){printf("Zadaj nove hodnoty.");}
	else {printf("Aktualizacia prebehla uspesne.\n");	break;}}}}}																//spr�vne na��tan� (zadan�) hodnoty ukon�ia cyklus

void Z(int overenie, char***prezenter, char***kod, char***nazov, char***autor,char***spec_znak, double**rod_cislo, int**cas,int**datum){
if (overenie==-1) printf("Polia nie su vytvorene.\n");
else{
int i,j, del=0,zaznamy=ZAZNAMY;
double rc;
scanf("%lf",&rc);
for(i=0;i<zaznamy;i++){															//porovn�va rodn� ��slo, ak sa rovn�, na indexe pod ktor�m bolo ulo�en� s� po novom zap�san� �daje z po�a o jedno vy��ie
	if(rc==(*rod_cislo)[i]){													//ak sa rovnalo rodn� ��slo v poli rod_cislo[3] so zadan�m rodn�m ��slom z kl�vesnice, v�etky �daje v poliach pod indexom[3]
		del++;																	//s� nahraden� hodnotami z pol� pod indexom [4], tie s� nahraden� hodnotami z pol� pod indexom [5].....at� a posledn� pole
		for(j=i;j!=zaznamy-1;j++){												//sa vyma�e funkciou realloc, respekt�ve pole sa zmen�� o 1 (v�etky polia...tj aj prezenter, aj kod, aj nazov.....)
			(*prezenter)[j]=(*prezenter)[j+1];									//premenna del = delete zaznamen�va, ko�kokr�t sa cyklus opakoval, t.j, ko�ko z�znamov sa vymazalo
			(*kod)[j]=(*kod)[j+1];
			(*nazov)[j]=(*nazov)[j+1];
			(*autor)[j]=(*autor)[j+1];
			(*spec_znak)[j]=(*spec_znak)[j+1];
			(*rod_cislo)[j]=(*rod_cislo)[j+1];
			(*cas)[j]=(*cas)[j+1];
			(*datum)[j]=(*datum)[j+1];}
			zaznamy--; i--;	
	*prezenter = (char**) realloc(*prezenter, (ZAZNAMY-del)*sizeof(char*));											
	*rod_cislo = (double*) realloc(*rod_cislo, (ZAZNAMY-del)*sizeof(double));											
	*kod = (char**) realloc(*kod, (ZAZNAMY-del)*sizeof(char*));													
	*nazov = (char**) realloc(*nazov, (ZAZNAMY-del)*sizeof(char*));
	*autor = (char**) realloc(*autor, (ZAZNAMY-del)*sizeof(char*));
	*spec_znak = (char**) realloc(*spec_znak, (ZAZNAMY-del)*sizeof(char*));
	*cas = (int*) realloc(*cas, (ZAZNAMY-del)*sizeof(int));
	*datum = (int*) realloc(*datum, (ZAZNAMY-del)*sizeof(int));}}
printf("Bolo vymazanych %d zaznamov\n",del);}}									//vyp�e, ko�ko z�znamov sa vymazalo

void K(FILE*fr,char***prezenter, char***kod, char***nazov, char***autor,char***spec_znak, double**rod_cislo, int**cas,int**datum){ 
int i; 
for(i=ZAZNAMY;i!=0;i--){														//tu neviem �o by som komentoval, proste dealokuje v�etky polia stringov
	free((*prezenter)[i]);
    free((*kod)[i]);									
    free((*nazov)[i]);
    free((*autor)[i]);
    free((*spec_znak)[i]);}
free(*prezenter);																//n�sledne dealokuje pointre
free(*kod);																		//vo funkcii main je pr�kaz, ktor�m stla�en�m K-�ka zatvor�me s�bor
free(*nazov);
free(*autor);
free(*spec_znak);
free(*datum);
free(*cas);
free(*rod_cislo);}
			   	
int main(){																		//funkcia main sama o sebe, na��tava znaky, ak znak nie�o znamen� pod�a zadania, vykon� sa k nemu patriaca funkcia
	char **prezenter,**kod,**nazov,**autor,**spec_znak;							//premennou overenie som overoval spr�vnos� vytvorenia dynamick�ch pol�
	int *cas,*datum;
	double *rod_cislo;
	int overenie=-1;
	FILE *fr = NULL;
	char a=' ';
	while(1){    
	scanf("%c", &a);
	    if(a=='v')	V(&fr);
		if(a=='n')	{N(fr,&prezenter,&kod,&nazov,&autor,&spec_znak,&rod_cislo,&cas,&datum);overenie=1;continue;}
		if(a=='s')	S(overenie,datum,&spec_znak,cas,&prezenter,&nazov);
		if(a=='h')	H(overenie,rod_cislo,&spec_znak);
		if(a=='p')	P(overenie,&prezenter,&nazov,&kod,&spec_znak,cas,datum,rod_cislo);
		if(a=='o')	O(fr);
		if(a=='k')	{K(fr,&prezenter,&kod,&nazov,&autor,&spec_znak,&rod_cislo,&cas,&datum); break;}		//funkcia K uzatv�ra s�bor
		if(a=='z')	Z(overenie,&prezenter,&kod,&nazov,&autor,&spec_znak,&rod_cislo,&cas,&datum);}        
fclose(fr); return 0;}																					//To je asi z mojej strany v�etko. 
