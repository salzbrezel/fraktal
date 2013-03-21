#include "fraktal.h"

#include <xmmintrin.h> //sse intrinsics

#if defined _WIN64 || defined _WIN32

#include <windows.h>
double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

#else

#include <sys/time.h>
#include <sys/resource.h>

double get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

#endif

int getItera(struct tComplex c, struct tComplex z, struct tParam p)
{
	int i=0;

	struct tComplex tmp;
	while( i < p.imax) //Benennung ?
	{				   // "Formel": z^2 = x^2 - y^2 + j 2xy
		tmp = z;
		z.re = tmp.re*tmp.re - tmp.im*tmp.im + c.re;
		z.im = 2*tmp.re*tmp.im+c.im ;

		if(z.re*z.re+z.im*z.im < p.R ) // gleich?
			i+=1;
		else
			break;
	}
	return i;
}

void Fraktal (struct tComplex c, struct tComplex z, struct tParam p)
{
	double di = (p.ymax-p.ymin)/p.yres;
	double dr = (p.xmax-p.xmin)/p.xres;

	switch (p.ftype)
	{
		case Julia: //z über Analysebereich laufen lassen
			for (z.im=p.ymin; z.im<=p.ymax; z.im+=di)
			{

				for(z.re=p.xmin; z.re<=p.xmax; z.re+=dr)
				{
					getItera(c,z,p);

				}

			}			
			break;
		case Apfel: //c über Analysebereich laufen lassen
			for (c.im=p.ymin; c.im<=p.ymax; c.im+=di)
			{

				for(c.re=p.xmin; c.re<=p.xmax; c.re+=dr)
				{
					getItera(c,z,p);
				
				}

			}
			break;
		default:
			break;
	}
}

