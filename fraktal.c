/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"

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
	int n=0;
	double di = (p.ymax-p.ymin)/p.yres;
	double dr = (p.xmax-p.xmin)/p.xres;

	switch (p.ftype)
	{
		case Julia: //z über Analysebereich laufen lassen
			LockScreen();
			for (z.im=p.ymin; z.im<=p.ymax; z.im+=di)
			{

				for(z.re=p.xmin; z.re<=p.xmax; z.re+=dr)
				{
					n = getItera(c,z,p);

					SetPoint(z.re, z.im, getColorValue(n, p.imax));

				}

			}
			UnlockScreen();
			break;
		case Apfel: //c über Analysebereich laufen lassen
			LockScreen();
			for (c.im=p.ymin; c.im<=p.ymax; c.im+=di)
			{

				for(c.re=p.xmin; c.re<=p.xmax; c.re+=dr)
				{
					n = getItera(c,z,p);

					SetPoint(c.re, c.im, getColorValue(n, p.imax));

				}

			}
			UnlockScreen();
			break;
		default:
			break;
	}
}
void plotFraktal(struct tComplex c, struct tComplex z, struct tParam p)
{
	int done=0; //quit flag
	int redraw=1; //redraw flag
	double runtime;
	char time[30];
	double di = (p.ymax-p.ymin)/p.yres;
	double dr = (p.xmax-p.xmin)/p.xres;
	SDL_Event event;
	while(!done)
		{
			if(redraw)
			{
				InitGraph(p.xmin,p.xmax,p.ymin,p.ymax,p.xres,p.yres);
				runtime = get_time();
				Fraktal(c,z,p);
				runtime = get_time() - runtime;
				sprintf(time, "%.3fs @ (%f, %f) - (%f, %f)", runtime, p.xmin, p.ymin, p.xmax, p.ymax);
				SDL_WM_SetCaption(time, NULL);
				redraw = 0;
			}

			while(SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					done = 1;
					break;
				case SDL_KEYDOWN:

					if (event.key.keysym.sym == SDLK_KP_MINUS || event.key.keysym.sym == SDLK_MINUS || event.key.keysym.sym == SDLK_o	)
					{ //rauszoomen
						p.ymax += di *70;
						p.ymin -= di*70;
						p.xmax += dr *100;
						p.xmin -= dr*100;
					    di = (p.ymax-p.ymin)/p.yres;
						dr = (p.xmax-p.xmin)/p.xres;
						redraw = 1;

					}
					if (event.key.keysym.sym == SDLK_KP_PLUS || event.key.keysym.sym == SDLK_PLUS || event.key.keysym.sym == SDLK_i)
					{ //reinzoomen
						p.ymax -= di *70;
						p.ymin += di*70;
						p.xmax -= dr *100;
						p.xmin += dr*100;
					    di = (p.ymax-p.ymin)/p.yres;
						dr = (p.xmax-p.xmin)/p.xres;
						redraw = 1;
					}
					if (event.key.keysym.sym == SDLK_UP)
					{
						p.ymax -= di * 0.1 * p.yres; //10%
						p.ymin -= di*0.1 * p.yres;
						redraw = 1;
					}
					if (event.key.keysym.sym == SDLK_DOWN)
					{
						p.ymax += di *0.1 * p.yres;
						p.ymin += di*0.1 * p.yres;
						redraw = 1;
					}
					if (event.key.keysym.sym == SDLK_LEFT)
					{
						p.xmax -= dr * 0.1 * p.xres;
						p.xmin -= dr * 0.1 * p.xres;
						redraw = 1;
					}
					if (event.key.keysym.sym == SDLK_RIGHT)
					{
						p.xmax += dr * 0.1 * p.xres;
						p.xmin += dr * 0.1 * p.xres;
						redraw = 1;
					}
					if (event.key.keysym.sym == SDLK_q)
					{
						done = 1;
					}
					break;
				default:
					break;

				}


			}
		}
		CloseGraph();
}
/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/


/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/


/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/


/* v3_frakt.c */
