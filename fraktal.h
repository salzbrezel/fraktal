/* Datei: v3_frakt.h            */
/* P. Rieger; TUD/PLT 20.8.1999 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/


#ifndef __fraktal
#define __fraktal
#include <math.h>
#include "dialog.h"
#include "typen.h"
/*--- Datentypvereinbarungen -----------------------------------------------*/




/*--- Fraktal analysieren und grafisch darstellen --------------------------*/
double getRadius(struct tComplex z);

int getItera( struct tComplex c, struct tComplex z, struct  tParam);

void Fraktal (struct tComplex c, struct tComplex z, struct tParam);

void plotFraktal(struct tComplex c, struct tComplex z, struct tParam);

#endif

/* v3_frakt.h */
