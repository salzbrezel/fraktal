/* Datei: v3_dialo.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include "fraktal.h"
#include <stdio.h>
#include <stdlib.h>


/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/



/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

int InputInt (void)
{
	int k;
	scanf("%d",&k);
	return k;
};

double InputDouble()
{
	double d;
	scanf("%lf", &d);
	return d;
}


/*--- Parameter Dialog ------------------------------------------------------*/
int ParamDialog(struct tComplex *c, struct tComplex *z,struct tParam *p){

	 int wahl;
	 int done = 1;
	 printf("\nDarstellung fraktaler Grafiken\n\n");
	 do{

		 printf("\n\n\nAktuelle Einstellungen\n");
		 printf("1. Radius: %lf \n", p->R);
		 printf("2. Maximale Anzahl an Iterationsschritten: %d \n", p->imax);
		 printf("3. Fraktal-Typ (0=Apfel, 1=Julia): %d Fraktal \n", p->ftype);
		 printf("4. Analysegebiet: %lf<x<%lf , %lf<y<%lf \n", p->xmin, p->xmax, p->ymin, p->ymax);
		 printf("5. Auflösung: %d x %d \n", p->xres, p->yres);
		 printf("6. Komplexe Zahl c: %lf + j*%lf \n", c->re, c->im);
		 printf("7. Komplexe Zahl z: %lf + j*%lf \n\n", z->re, z->im);
		 printf("8. --Fraktal plotten--\n");
		 printf("9. --Program beenden--\n\n");
		 printf("Zum Ändern der Parameter die entsprechende Zahl 1-9 eingeben");

		 scanf("%i", &wahl);

		 switch(wahl)
		 {
			 case 1: printf("\nGeben Sie den neuen Radius ein:");
					 scanf("%lf", &p->R);
					 break;

			 case 2: printf("\nGeben Sie den neuen Wert fuer imax ein:");
			 	 	 scanf("%i", &p->imax);
			 	 	 break;

			 case 3: printf("\nGeben Sie den neuen Fraktal-Typen ein:");
					 //scanf("%i", &p->ftype);
					 break;

			 case 4: printf("\nGeben Sie den neuen Wert für xmin ein:");
			 	 	 scanf("%lf", &p->xmin);
			 	 	 printf("\nGeben Sie den neuen Wert für xmax ein:");
			 	 	 scanf("%lf", &p->xmax);
			 	 	 printf("\nGeben Sie den neuen Wert für ymin ein:");
			 	 	 scanf("%lf", &p->ymin);
			 	 	 printf("\nGeben Sie den neuen Wert für ymax ein:");
			 	 	 scanf("%lf", &p->ymax);
			 	 	 break;

			 case 5: printf("\nGeben Sie Ihre Auflösung in x-Richtung ein:");
			 	 	 scanf("%i", &p->xres);
			 	 	 printf("\nGeben Sie Ihre Auflösung in y-Richtung ein:");
			 	 	 scanf("%i", &p->yres);
			 	 	 break;

			 case 6: printf("\nGeben Sie den neuen Realteil ihrer komplexen Zahl ein:");
			 	 	 scanf("%lf", &c->re);
			 	 	 printf("\nGeben Sie den neuen Imaginärteil ihrer komplexen Zahl ein:");
			 	 	 scanf("%lf", &c->im);
			 	 	 break;

			 case 7: printf("\nGeben Sie den neuen Realteil ihrer komplexen Zahl ein:");
			 	 	 scanf("%lf", &z->re);
			 	 	 printf("\nGeben Sie den neuen Imaginärteil ihrer komplexen Zahl ein:");
			 	 	 scanf("%lf", &z->im);
			 	 	 break;

			 case 8:
				 	 plotFraktal(*c,*z,*p);
				 	 break;

			 case 9: done=0;
			 	 	 break;
			 default: printf("\n Ihre Eingabe ist ungueltig\n"); break;
		 }

	 }while(wahl != 9);

	 return done;
}


/* v3_frakt.c */
