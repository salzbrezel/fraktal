#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>
#include <windows.h>
#define NO_STDIO_REDIRECT
int main(int argc, char* argv[])
{
	tFraktal f = Apfel;
	struct tParam p  = {4,300,f,-0.7,-0.2,-0.25,0.25,800,640};

	struct tComplex c = {0.4,0.4};
	struct tComplex z = {0,0};


	//while(ParamDialog(&c, &z, &p))
	//{}
	Fraktal(c,z,p);

	/*
	tFraktal f = Apfel;
	struct tParam k  = {800000,5,f,-2,2,-2,2,0,0};
	struct tComplex c = {0,2};
	struct tComplex z = {0,0};
	getItera(c,z,k);
	*/
	return 0;
}
