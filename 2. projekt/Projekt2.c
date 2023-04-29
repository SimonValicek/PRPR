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

//na �vod by som r�d povedal, �e nasleduj�ca verzia m�jho projektu je presne to ist� ako t�, ktor� som odovzal v prvom term�ne
//mo�no sa nejak� riadok n�jde in�, ale funk�nos� tejto verzie a minulej je presne t� ist�
//rozdiel by mal by� len v tom, �e t�to verzia je okomentovan�

//tak�e vytvor�me si �trukt�ru
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

//vytvor�me si novy zaznam, ktor� je typu �trukt�ry, ktor� sme si vy��ie vytvorili...........neviem ako to lep�ie pop�sa�

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

//funkcia N na��ta zo s�boru, do �trukt�ry, nepracoval som s dealok�ciou, v pr�pade, �e vyvol�me pr�kaz p sk�r, ako pr�kaz n
//pravdupovediac, s takou variantou m�j program nepo��ta, prv� pr�kaz, ktor� mus�me stla�i�, aby sme mohli pracova� s �dajmi je N
//jednotliv� vstupy nem�m o�etren�, to znamen�, �e prejde takmer �oko�vek, akur�t pri ��slach by mali prejs� iba ��sla

void N(ZAZNAM **zaciatok, ZAZNAM **koniec){				//ch�ba dealok�cia
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
printf("pocet: %d\n",pocet);							//vr�ti� hodnotu po�et a pracova� s �ou
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

//funckia v zabezpe�uje v�pis, funguje vo v�etk�ch pr�padoch, aj ke� sa z�znamy zmenia, av�ak, v�dy vyp�e nanajv�� 7 z�znamov
//m�j program m� po�et z�znamov dan� ako kon�tantu, ktor� m��me meni� v jej defin�ci� na za�iatku programu, t�m chcem poveda� �e po�et z�znamov nie je premenn�, s ktorou m��me nar�ba�
//sna�il som sa tento pr�pad opravi�, no nakoniec som sa rozhodol, cel� to uz�tvorkova�, �i�e to nem� �iadnu v�hu

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

//funkcia p dok�e pracova� s pridan�m nov�ch hodn�t na za�iatok, do stredu aj na koniec, av�ak nefunguje bez stla�enia N

void P(int overenie, ZAZNAM **zaciatok, ZAZNAM **koniec){					//o�etri� prv�ho
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

//neo�etren� pre pr�pad, �e z�znamov je viacej ako �es�, takisto neviem vymaza� prv� z�znam, zvy�ok funguje

void Z(ZAZNAM *zaciatok){								//o�etri� pre pr�pad, �e tam bude viac z�znamov ako 6, plus o�etri� aby sa vyp�salo aj ke� sa vyma�e prv�
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

//jedin� chybi�ka je, �e neberie do �vahy zmenu po�tu z�znamov, v�dy pracuje so �iestimi

void H(ZAZNAM *zaciatok){											//dokonale, o�etri� u� len po�et z�znamov
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

//takisto v�etko ok, ale pracuje len so 6. z�znamami

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

//funkcia R nefunguje pre pr�pad, �e sa rozhodneme vzia� prv� z�znam a vymeni� ho s in�m, ostatn� v�meny funguj�

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

//na toto ste mi povedali, �e nedealokuje spr�vne, ale bohu�ia�, neviem si overi� dealok�ciu nijak
//ako som sa z projektu �.1 dozvedel, ke� si pom��em funkciou printf, tak mi niekedy u� na dealokovanom mieste vyp�e p�vodn� hodnoty, tak�e tak�to overenie nie je relevantn�

void K(ZAZNAM **zaciatok){
ZAZNAM *v=*zaciatok;
while(*zaciatok!=NULL){
	v=*zaciatok;
	*zaciatok=(*zaciatok)->dalsi;
	free(v);}
}

//funckia main by mala by� v poriadku
//zrhnutie: slabiny m�jho programu s� predov�etk�m pr�ca s prv�m z�znamom v zozname, to sa prizn�m, �e mi absolutne nejde + alok�ciu, ktor� si neodk�em nijak�m sp�sobom overi�
//�alej s� to neoverenie korektnosti vstupov a pr�ca s kon�tantn�m po�tom z�znamov, tieto pova�ujem za vyrie�ite�n�, ale nechcel som kv�li tomu prepisova� cel� program, ke� u� mi z ve�kej �asti fungoval

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
