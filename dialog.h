/* Datei: v3_dialo.h              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#ifndef __dialog
#define __dialog

#include "fraktal.h"
#include "typen.h"

/*--- Parameter Dialog Prototyp --------------------------------------------*/
int ParamDialog(struct tComplex *c, struct tComplex *z,struct  tParam *p);

/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
char InputChar();
int InputInt();
double InputDouble();


#endif
/* v3_dialo.h */
