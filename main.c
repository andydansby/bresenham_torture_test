//  zcc +zx -vn -SO3 -m -lm -clib=new main.c -o main -create-app

#define ABS(N) ((N<0)?(-N):(N))
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))


#pragma printf "%f %ld %d %u"
#pragma scanf  "%f %ld %d"

#include <intrinsic.h>//temp to place labels

#include <arch/zx.h>
#include <stdio.h>
#include <stdlib.h>//standard library
#include <input.h>
#include <float.h>
#include <math.h>

#include "variables.h"
#include "timer.h"
#include "externs.h"

#include "plot.h"
#include "sine_estimator.h"

#include "bresenham.h"

#include "string_art.c"


//powerful troubleshooting tool
        //intrinsic_label(border_start);
        //intrinsic_label(border_end);


void printOptions (void);

void options1 (void)
{
    //key presses
    while (1)
    {
        //first row
        if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{// C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_circle_string_art(80, 100, 25);
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{// C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			string_edge_curve(32);
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_3 ))
		{// C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_radial_spokes(80, 96);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_4 ))
		{//C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_modulas(120, 2);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_5 ))
		{//C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			draw_pin(15);

            in_wait_key();
            break;
		}

        /*if (in_key_pressed( IN_KEY_SCANCODE_6 ))
		{//C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			//spiral(4);
			drawLinearWhirlpool(80, 30, 5);

            in_wait_key();
            break;
		}*/

        //second row
		if (in_key_pressed( IN_KEY_SCANCODE_q ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_circle_string_art2(80, 100, 25);
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_w ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			string_edge_curve2(32);
            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_e ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_radial_spokes2(80, 96);

            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_r ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_modulas2(120, 2);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_t ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			draw_pin2(15);

            in_wait_key();
            break;
		}//g

        /*if (in_key_pressed( IN_KEY_SCANCODE_y ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			drawLinearWhirlpool2(80, 30, 5);

            in_wait_key();
            break;
		}//h
		*/





        //third row
		if (in_key_pressed( IN_KEY_SCANCODE_a ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_circle_string_art3(80, 100, 25);
            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_s ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			string_edge_curve3(32);
            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_d ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_radial_spokes3(80, 96);

            in_wait_key();
            break;
		}


		//fourth row
		if (in_key_pressed( IN_KEY_SCANCODE_z ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_circle_string_art5(80, 100, 25);
            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_x ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			string_edge_curve4(32);
            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_c ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_radial_spokes4(80, 96);

            in_wait_key();
            break;
		}








		/////////////////////////////////
		if (in_key_pressed( IN_KEY_SCANCODE_b ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			//draw_lissajous(128, 96, 100, 80, 3, 2, 0, 500);
			draw_circle_string_art4(80, 100, 25);

            in_wait_key();
            break;
		}



		if (in_key_pressed( IN_KEY_SCANCODE_l ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			gfx_x = 250;
            gfx_y = 3;
            createPixel_variable();
			hellaPlot();

			bresenham_C1(5, 5, 10, 30);
            in_wait_key();
            break;
		}


    }//end while
}//end options1


void printOptions (void)
{
    {
        zx_cls(PAPER_WHITE | INK_BLUE);
        zx_border (2);
        printf("\x16\x01\x02");

        printf ("Welcome to the Bresenham Tester V1.0\n");
        printf ("press a key for test\n");

        printf ("1 - 6 Various C-Bresenham Line Tests");
        printf ("\n");
        printf ("Q - T Various ASM 1-Bresenham Line Tests");
        printf ("\n");

        printf ("\n\n");

        printf ("3 -           R setting (3)= %d", R_setting);
        printf ("\n");
		printf ("4 -           d setting (3)= %d", d_setting);
		printf ("\n\n");
        printf ("A-D ROSE Curve");
        printf ("\n");

        printf ("Z -- ROSE Curious");
        printf ("\n\n\n");
        printf ("Press SPACE to STOP drawing");
    }

    options1();
}

void main(void)
{
	__asm
	ei
	__endasm

	zx_cls(PAPER_WHITE | INK_BLUE);

	yHeight = 190;
	xWidth = 255;
	X_start = 255;
	Y_start = 45;
	sineCycle = 0;
	waveHeight = 40;
	halfHeight = waveHeight / 2;
	freq = 2.0;
    offSet = 46;

    a_setting = 1;
    b_setting = 2;


    amplitude = 10;
//    period = 150;
    phase_shift = 0;
    vertical_shift = 87;

    R_setting = 3;//62.5       changes shape
//    r_setting = 50;//37.5
    d_setting = 3;//62.5

    while (1)
    {
        printOptions();
    }

}

void end_junk ()
{
    unsigned char a = 0;
    return a;
}

//leave blank line after
