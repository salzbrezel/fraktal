/*
 * typen.h
 *
 *  Created on: 13.01.2013
 *      Author: mrt
 */

#ifndef TYPEN_H_
#define TYPEN_H_

typedef enum
{  Apfel,
   Julia
} tFraktal;
struct tParam
{
	double R;
	int imax;
	tFraktal ftype;
	double xmin;
	double xmax;
	double ymin;
	double ymax;
	int xres;
	int yres;


};

struct tComplex
{
	double re;
	double im;
};

#endif /* TYPEN_H_ */
