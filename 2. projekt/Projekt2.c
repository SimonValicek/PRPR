#include <stdlib.h>
#include <string.h>												
#include <stdio.h>
#define CYKLUS 9
#define ZAZNAMY 6
#define PREZENTER 50
#define KOD 4
#define TEMA 150
#define AUTOR 200
#define ZNAK 3
#define RODCISLO 11
#define CAS 5
#define DATUM 9
#define RIADOK 200

//na úvod by som rád povedal, e nasledujúca verzia môjho projektu je presne to isté ako tá, ktorú som odovzal v prvom termíne
//mono sa nejakı riadok nájde inı, ale funkènos tejto verzie a minulej je presne tá istá
//rozdiel by mal by len v tom, e táto verzia je okomentovaná

//take vytvoríme si štruktúru
typedef struct zaznam{
   char prezenter[PREZENTER];
   double rod_c;
   char kod[KOD];
   char tema[TEMA];
   char autor[AUTOR];
   char znak[ZNAK];
   int cas;
   int datum;
   struct zaznam *dalsi;    
}ZAZNAM;

//vytvoríme si novy zaznam, ktorı je typu štruktúry, ktorú sme si vyššie vytvorili...........neviem ako to lepšie popísa

ZAZNAM *novy_zaznam(char prezenter[], double rod_c,char kod[], char tema[], char autor[], char znak[],  int cas, int datum){
    ZAZNAM *pole = malloc(sizeof(ZAZNAM));
    strcpy(pole->prezenter, prezenter);
    pole->rod_c=rod_c;
    strcpy(pole->kod, kod);
    strcpy(pole->tema, tema);
    strcpy(pole->autor, autor);
  	strcpy(pole->znak, znak);
   	pole->cas=cas;
   	pole->datum=datum;
	return pole;}

//funkcia N naèíta zo súboru, do štruktúry, nepracoval som s dealokáciou, v prípade, e vyvoláme príkaz p skôr, ako príkaz n
//pravdupovediac, s takou variantou môj program nepoèíta, prvı príkaz, ktorı musíme stlaèi, aby sme mohli pracova s údajmi je N
//jednotlivé vstupy nemám ošetrené, to znamená, e prejde takmer èoko¾vek, akurát pri èíslach by mali prejs iba èísla

void N(ZAZNAM **zaciatok, ZAZNAM **koniec){				//chıba dealokácia
FILE *fr;
if ((fr=fopen("projekt.txt","r"))==NULL) printf("Subor sa nepodarilo otvorit.\n");
ZAZNAM *v;
char v_prezenter[PREZENTER], v_kod[KOD], v_tema[TEMA], v_autor[AUTOR], v_znak[ZNAK], riadok[RIADOK];
double v_rod_c;
int pocet,v_cas, v_datum,a,pocitadlo=1;
for(a=0;;a++){
	if(feof(fr))break;
	fgets(riadok,RIADOK,fr);}
rewind(fr);
pocet=a/CYKLUS;
printf("pocet: %d\n",pocet);							//vráti hodnotu poèet a pracova s òou
while(1){
/*	v = novy_zaznam(v_prezenter, v_rod_c, v_kod, v_tema, v_autor, v_znak, v_cas, v_datum);
	if(pocitadlo==1) pomocna(zaciatok, koniec, v);
	else pomocna_3(koniec, v);*/
	fgets(riadok,RIADOK,fr);
	printf("%s",riadok);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_prezenter,riadok);
	printf("%s\n",v_prezenter);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	v_rod_c=atof(riadok);
	printf("%.lf\n",v_rod_c);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_kod,riadok);
	printf("%s\n",v_kod);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_tema,riadok);
	printf("%s\n",v_tema);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_autor,riadok);
	printf("%s\n",v_autor);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_znak,riadok);
	printf("%s\n",v_znak);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	v_cas=atoi(riadok);
	printf("%d\n",v_cas);
	
	fgets(riadok,RIADOK,fr);
	riadok[strlen(riadok)-1]=0;
	v_datum=atoi(riadok);
	printf("%d\n",v_datum);
	
	v = novy_zaznam(v_prezenter, v_rod_c, v_kod, v_tema, v_autor, v_znak, v_cas, v_datum);
    if(pocitadlo==1) *zaciatok = v;
    else (*koniec)->dalsi = v;
    *koniec = v;
    pocitadlo++;
	if(feof(fr)) break;
	}
}

//funckia v zabezpeèuje vıpis, funguje vo všetkıch prípadoch, aj keï sa záznamy zmenia, avšak, vdy vypíše nanajvıš 7 záznamov
//môj program má poèet záznamov danı ako konštantu, ktorú môme meni v jej definícií na zaèiatku programu, tım chcem poveda e poèet záznamov nie je premenná, s ktorou môme narába
//snail som sa tento prípad opravi, no nakoniec som sa rozhodol, celé to uzátvorkova, èie to nemá iadnu váhu

void V(struct zaznam*v){
int i=1;
for (v;v!=NULL;v=v->dalsi) {
	printf("%d.\n",i); i++;
	printf("Prezenter: %s\n", v->prezenter);
	printf("Rodne cislo: %.lf\n", v->rod_c);
	printf("Kod miestnosti: %s\n", v->kod);
	printf("Tema: %s\n", v->tema);
	printf("Autor: %s\n", v->autor);
	printf("Znak: %s\n", v->znak);
	printf("Cas: %d\n", v->cas);
	printf("Datum: %d\n", v->datum);}}

//funkcia p dokáe pracova s pridaním novıch hodnôt na zaèiatok, do stredu aj na koniec, avšak nefunguje bez stlaèenia N

void P(int overenie, ZAZNAM **zaciatok, ZAZNAM **koniec){					//ošetri prvého
ZAZNAM *v;
ZAZNAM *predchadzajuci = *zaciatok;
ZAZNAM *pomocna = *zaciatok;
char prez[RIADOK], v_kod[RIADOK], v_tema[RIADOK], v_autor[RIADOK], v_znak[RIADOK], riadok[RIADOK];
double v_rod_c;
int v_cas, v_datum,poradie,i=1,j;
/*	getchar();
if (overenie!=1){
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	poradie=atoi(riadok);
	
	fgets(riadok,RIADOK,stdin);
	printf("%s",riadok);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(prez,riadok);
	printf("%s\n",prez);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	v_rod_c=atof(riadok);
	printf("%.lf\n",v_rod_c);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_kod,riadok);
	printf("%s\n",v_kod);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_tema,riadok);
	printf("%s\n",v_tema);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_autor,riadok);
	printf("%s\n",v_autor);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_znak,riadok);
	printf("%s\n",v_znak);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	v_cas=atoi(riadok);
	printf("%d\n",v_cas);
	
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	v_datum=atoi(riadok);
	printf("%d\n",v_datum);
	v = novy_zaznam(prez, v_rod_c, v_kod, v_tema, v_autor, v_znak, v_cas, v_datum);
	*zaciatok = v;}*/
	getchar();
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	poradie=atoi(riadok);
//printf("%d\n",poradie);
	fgets(prez,RIADOK,stdin);														//
	prez[strlen(prez)-1]=0;
//printf("%s\n",prez);
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	v_rod_c=atof(riadok);
//printf("%.lf\n",v_rod_c);
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_kod,riadok);
//printf("%s\n",v_kod);
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_tema,riadok);
//printf("%s\n",v_tema);
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	strcpy(v_autor,riadok);
//printf("%s\n",v_autor);
	fgets(riadok,RIADOK,stdin);                              
	riadok[strlen(riadok)-1]=0;
	strcpy(v_znak,riadok);
//printf("%s\n",v_znak);
	fgets(riadok,RIADOK,stdin);
	riadok[strlen(riadok)-1]=0;
	v_cas=atoi(riadok);
//printf("%d\n",v_cas);
	fgets(riadok,RIADOK,stdin);																					
	riadok[strlen(riadok)-1]=0;
	v_datum=atoi(riadok);
//printf("%d\n",v_datum);
	v = novy_zaznam(prez, v_rod_c, v_kod, v_tema, v_autor, v_znak, v_cas, v_datum);
if (poradie==1){		
	v->dalsi=*zaciatok;															
	predchadzajuci=v;
	*zaciatok=predchadzajuci;
//printf(" predchadzajuci: %s\n predchadzajuci->dalsi: %s\n v->dalsi: %s\n zaciatok: %s\n v: %s\n",predchadzajuci, predchadzajuci->dalsi,v->dalsi,zaciatok,v);
//putchar('\n');
//for(predchadzajuci;predchadzajuci!=NULL;predchadzajuci=predchadzajuci->dalsi){
//printf("%s\n",predchadzajuci);}
}
else{		
	if (poradie<ZAZNAMY+1){
		for (i=1;i<poradie-1;i++){
			predchadzajuci=predchadzajuci->dalsi;}
		v->dalsi=predchadzajuci->dalsi;
		predchadzajuci->dalsi=v;}	
	else{
		if(poradie>ZAZNAMY+1) printf("Zadane poradie je nespravne.");
		else{
			v->dalsi=(*koniec)->dalsi;
			(*koniec)->dalsi=v;
			*koniec=v;}}}}

//neošetrené pre prípad, e záznamov je viacej ako šes, takisto neviem vymaza prvı záznam, zvyšok funguje

void Z(ZAZNAM *zaciatok){								//ošetri pre prípad, e tam bude viac záznamov ako 6, plus ošetri aby sa vypísalo aj keï sa vymae prvı
ZAZNAM *predchadzajuci =zaciatok;  
ZAZNAM *v = zaciatok;
double rc;
int i=0;
scanf("%lf",&rc);
for(v;v!=NULL;v=v->dalsi){
	if(v->rod_c==rc){									
		predchadzajuci->dalsi=v->dalsi;
		printf("Prezenter s menom %s bol vymazany\n",v->prezenter);
		free(v);}
	else{
		predchadzajuci=v;
		i++;}}
if(i==6) printf("Rodne cislo nebolo najdene.");
}

//jediná chybièka je, e neberie do úvahy zmenu poètu záznamov, vdy pracuje so šiestimi

void H(ZAZNAM *zaciatok){											//dokonale, ošetri u len poèet záznamov
ZAZNAM *v = zaciatok;
char kod[KOD];
int i=1,j=0;
scanf("%s",kod);
for(v;v!=NULL;v=v->dalsi){
	if (strcmp(kod,v->kod)==0){
		printf("%d.\n",i); i++;
		printf("Prezenter: %s\n", v->prezenter);
		printf("Rodne cislo: %.lf\n", v->rod_c);
		printf("Kod miestnosti: %s\n", v->kod);
		printf("Tema: %s\n", v->tema);
		printf("Autor: %s\n", v->autor);
		printf("Znak: %s\n", v->znak);
		printf("Cas: %d\n", v->cas);
		printf("Datum: %d\n", v->datum);}
	else j++;}
if(j==6) printf("Pre kod miestnosti <%s> sa nenasiel ziadny zaznam.\n",kod);	
}

//takisto všetko ok, ale pracuje len so 6. záznamami

void A(ZAZNAM *zaciatok){
ZAZNAM *v = zaciatok;
char znak[ZNAK];
double rc;
int j=0;
scanf("%lf %s",&rc,znak);
for(v;v!=NULL;v=v->dalsi){
	if (v->rod_c==rc){
		strcpy(v->znak,znak);
		printf("Prezenter s menom %s bude prezentovat prispevok %s: %s\n",v->prezenter,v->tema,v->znak);}
	else j++;}
if(j==6) printf("Pre dane zadane rodne cislo neexistuje ziaden zaznam.\n");}

//funkcia R nefunguje pre prípad, e sa rozhodneme vzia prvı záznam a vymeni ho s inım, ostatné vımeny fungujú

void R(ZAZNAM **zaciatok){
ZAZNAM *v= *zaciatok;
ZAZNAM *novy= *zaciatok;
ZAZNAM *pomocna_dalsi_1= *zaciatok;
ZAZNAM *pomocna_dalsi_2= *zaciatok;
ZAZNAM *pomocna_1= *zaciatok;
ZAZNAM *pomocna_2= *zaciatok;
ZAZNAM *pomocna_xy;
int a,b,i=0,j=0,h=1,pom;
scanf("%d %d",&a,&b);
if (a>b) {pom=a;a=b;b=pom;}
if (a>ZAZNAMY||b>ZAZNAMY) printf("Chybny vstup.");
else{
	for(h=1;novy!=NULL;h++){
		printf("novy: %s\n",novy);
		printf("zaciatok: %s\n",*zaciatok);
		if(h==a) 
			if(h==1){pomocna_1=*zaciatok; pomocna_dalsi_1=pomocna_1->dalsi, printf("pomocna 1: %s\n",pomocna_1);} 
			else {pomocna_1=novy; pomocna_dalsi_1=pomocna_1->dalsi; printf("pomocna 1: %s\n",pomocna_1);}
		if(h==b) {pomocna_2=novy; pomocna_dalsi_2=pomocna_2->dalsi; printf("pomocna 2: %s\n",pomocna_2);}
		novy=novy->dalsi; }
	putchar('\n');
	printf("pomocna_dalsi_1: %s			pomocna_dalsi_2: %s\n",pomocna_dalsi_1, pomocna_dalsi_2);
	putchar('\n');
	putchar('\n');
	novy=v; printf(" dalsi novy: %s\n",novy);
	putchar('\n');
	putchar('\n');
	pomocna_xy=pomocna_2;
	if(a==1) {
		for(h=1;h<7;h++){
			if(h==1||h==b){
				if(h==1){				
					pomocna_2->dalsi=*zaciatok;
					novy=pomocna_2;
					*zaciatok=novy;}
				if(h==b){
					novy->dalsi=pomocna_1;
					pomocna_1->dalsi=pomocna_2->dalsi;}}
			else novy=novy->dalsi;	
			putchar('\n');
			printf(" a: %d\n b: %d\n h: %d\n pomocna_2: %s\n pomocna_2->dalsi: %s\n pomocna_1: %s\n zaciatok: %s\n novy: %s\n novy->dalsi: %s\n pomocna_1->dalsi: %s\n pomocna_dalsi_2 %s\n pomocna_dalsi_1 %s\n",a,b,h,pomocna_2,pomocna_2->dalsi,pomocna_1,*zaciatok,novy,novy->dalsi,pomocna_1->dalsi,pomocna_dalsi_2,pomocna_dalsi_1);	
				}}
				
	else{
		for(h=1;novy!=NULL;h++){
		/*	if(a==1){
				(*zaciatok)->dalsi=pomocna_2;
				pomocna_2->dalsi=pomocna_dalsi_1;}*/
			if(h==(a-1)){
				novy->dalsi=pomocna_2;
				pomocna_2->dalsi=pomocna_dalsi_1;}
			if(h==(b-1)){
				novy->dalsi=pomocna_1;
				pomocna_1->dalsi=pomocna_dalsi_2;}	
			novy=novy->dalsi;}}
	novy=v;
	putchar('\n');
	putchar('\n');
	for(h=1;h<ZAZNAMY+1;h++){
		printf("novy %s\n",novy);
		novy=novy->dalsi;}}}

//na toto ste mi povedali, e nedealokuje správne, ale bohuia¾, neviem si overi dealokáciu nijak
//ako som sa z projektu è.1 dozvedel, keï si pomôem funkciou printf, tak mi niekedy u na dealokovanom mieste vypíše pôvodné hodnoty, take takéto overenie nie je relevantné

void K(ZAZNAM **zaciatok){
ZAZNAM *v=*zaciatok;
while(*zaciatok!=NULL){
	v=*zaciatok;
	*zaciatok=(*zaciatok)->dalsi;
	free(v);}
}

//funckia main by mala by v poriadku
//zrhnutie: slabiny môjho programu sú predovšetkım práca s prvım záznamom v zozname, to sa priznám, e mi absolutne nejde + alokáciu, ktorú si neodkáem nijakım spôsobom overi
//ïalej sú to neoverenie korektnosti vstupov a práca s konštantnım poètom záznamov, tieto povaujem za vyriešite¾né, ale nechcel som kvôli tomu prepisova celı program, keï u mi z ve¾kej èasti fungoval

int main(){
ZAZNAM *zaciatok=NULL;
ZAZNAM *koniec=NULL;
int zaznamy=-1;
int overenie=-1;
char a;
while (a!='x'){
	scanf("%c",&a);
	if (a=='v')	V(zaciatok);
	if (a=='n')	{N(&zaciatok,&koniec);overenie=1;}
	if (a=='p')	P(overenie,&zaciatok,&koniec);
	if (a=='r')	R(&zaciatok);
	if (a=='a') A(zaciatok);
	if (a=='k')	{K(&zaciatok);break;}
	if (a=='z') Z(zaciatok);
	if (a=='h') H(zaciatok);
}
return 0;
}
