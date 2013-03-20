
#include <stdio.h>
#include <stdlib.h>
#include "typen.h"
#include <windows.h>   //timer
#include <emmintrin.h> //sse2 intrinsics
//#include <mmintrin.h>
//#include <xmmintrin.h>
double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

int getItera(struct tComplex c, struct tComplex z, struct tParam p)
{
	int i=0;
	double a_r, b_r;//, a_i, b_i,
	_mm_add_ps(a_r, b_r);
	//struct tComplex tmp;
	//a_r = (__m128)z.re;
	//a_i = (__m128)z.im;
	//b_i = (__m128)c.im;
	//b_r = (__m128)(c.re);
	while( i < p.imax) //Benennung ?
	{				   // "Formel": z^2 + c = x^2 - y^2 + cre + j 2xy + c im
		//z.re = _mm_add_ps(_mm_sub_ps(_mm_mul_ps(a_r,a_r),_mm_mul_ps(a_i,a_i)), b_r);
		//z.im = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(a_r,a_i),2),b_i);
		/*
		tmp = z;
		z.re = tmp.re*tmp.re - tmp.im*tmp.im + c.re;
		z.im = tmp.re*tmp.im+tmp.re*tmp.im+c.im ;
		*/
		//printf("\n %f, %f", z.re, z.im);
		if(z.re*z.re+z.im*z.im < p.R ) // gleich?
			i+=1;
		else
			break;
	}
	return i;
}
int Fraktal (struct tComplex c, struct tComplex z, struct tParam p)
{
	int n=0;
		double di = (p.ymax-p.ymin)/p.yres;
		double dr = (p.xmax-p.xmin)/p.xres;

		switch (p.ftype)
		{
			case Julia: //z über Analysebereich laufen lassen

				for (z.im=p.ymin; z.im<=p.ymax; z.im+=di)
				{

					for(z.re=p.xmin; z.re<=p.xmax; z.re+=dr)
					{
						n = getItera(c,z,p);


					}

				}

				break;
			case Apfel: //c über Analysebereich laufen lassen
				for (c.im=p.ymin; c.im<=p.ymax; c.im+=di)
				{

					for(c.re=p.xmin; c.re<=p.xmax; c.re+=dr)
					{
						n = getItera(c,z,p);
					}

				}
				break;
			default:
				break;
		}
		return n;
}

int main(void)
{
		double runtime;
		double diff;
		int i;
		tFraktal f = Apfel;
		//struct tParam p1  = {4,300,f,-1,-0.5,-0.25,0.25,800,640};
		struct tParam p[5]=
		    {{4,300,f,-0.7, -0.2, -0.25, 0.25, 800,640},
			 {4,300,f,-1, 1, -1, 1, 800,640},
			 {4,300,f,-0.2,0.3,-0.2,0.3,800,640},
			 {4,300,f,-0.205,0.206,-0.250,0.251,800,640},
			 {4,300,f,-1,-0.5,-0.25,0.25,800,640}};
		struct tComplex c = {0.4,0.4};
		struct tComplex z = {0,0};
		runtime = get_time();
		for(i=0; i<5; i++)
		{
			diff = get_time();
			Fraktal(c,z,p[0]);
			printf("\n%d %.2f s", i, get_time()-diff);
		}
		printf("\n-------------------------------\n"
				"all: %.2fs | average %.2f ", get_time()-runtime, (get_time()-runtime)/i);
		return 0;
}

