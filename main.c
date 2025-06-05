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

void set_a(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  1-50 Current = %d\n", a_setting);
	printf("\n");
	printf("Try 2,  larger is wider");
	printf("\n");
	scanf("%d", &a_setting);
}

void set_b(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  1-50 Current = %d\n", b_setting);
	printf("\n");
	printf("Try 3,  larger is wider");
	printf("\n");
	scanf("%d", &b_setting);
}

void set_A(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  1-255 Current = %d\n", A);
	printf("\n");
	printf("Try 2,  larger is wider");
	printf("\n");
	scanf("%d", &A);
}

void set_B(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  1-192 Current = %d\n", B);
	printf("\n");
	printf("Try 3,  larger is wider");
	printf("\n");
	scanf("%d", &B);
}

void set_R(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  0-10 Current = %d", R_setting);
	printf("\n");
	printf("Try 2");
	printf("\n");
	scanf("%d", &R_setting);
}

/*void set_r()
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  0-100 Current = %d\n", r_setting);
	printf("\n");
	printf("Try 37");
	printf("\n");
	scanf("%d", &r_setting);
}*/

void set_d(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  1-10 Current = %d\n", d_setting);
	printf("\n");
	printf("Try 1");
	printf("\n");
	scanf("%d", &d_setting);
}





void set_x_offset(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  1-255 Current = %d\n", x_offset);
	printf("\n");
	printf("Try 128,  larger is wider");
	printf("\n");
	scanf("%d", &x_offset);
}

void set_y_offset(void)
{
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input a setting  1-192 Current = %d\n", y_offset);
	printf("\n");
	printf("Try 90,  larger is wider");
	printf("\n");
	scanf("%d", &y_offset);
}

void options1 (void)
{
    //key presses
    while (1)
    {
        if (in_key_pressed( IN_KEY_SCANCODE_p ))
		{//straight line
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			//bresenham_C1(0, 5, 255, 190);
			//bresenham_C1(220, 160, 215, 170);//closer to 180

			line_x1 = 220;
            line_y1 = 160;
            line_x2 = 215;
            line_y2 = 170;
            //bresenham_line_1();
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_q ))
		{// C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_circle_string_art(80, 100, 25);
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_w ))
		{// C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			string_edge_curve(32);
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_e ))
		{// C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_radial_spokes(80, 96);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_r ))
		{//C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_modulas(120, 2);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_t ))
		{//C version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			draw_pin(15);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_y ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			//draw_vortex(30);
			drawLineWhirlpool(50, 100, 3.0);

            in_wait_key();
            break;
		}

        if (in_key_pressed( IN_KEY_SCANCODE_u ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			//spiral(4);
			drawLinearWhirlpool(80, 30, 5);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_i ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			//drawHypotrochoid(50, 35, 60);
			drawSpiralPattern(95, 20);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_o ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			chord_grid(80,100,3.2);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_a ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_circle_string_art2(80, 100, 25);
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_z ))
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
			string_edge_curve2(32);
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_d ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_radial_spokes2(80, 96);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_f ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_modulas2(120, 2);

            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_g ))
		{//asm version
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();

			draw_pin2(15);

            in_wait_key();
            break;
		}



        if (in_key_pressed( IN_KEY_SCANCODE_l ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_lissajous(128, 96, 100, 80, 3, 2, 0, 500);

            in_wait_key();
            break;
		}


		/////////////////////////////////
		if (in_key_pressed( IN_KEY_SCANCODE_m ))
		{
		    zx_cls(PAPER_WHITE | INK_RED);
			in_wait_nokey();
			draw_lissajous(128, 96, 100, 80, 3, 2, 0, 500);

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

/*
        if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{
			in_wait_nokey();
			set_a();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{
			in_wait_nokey();
			set_b();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_3 ))
		{
			in_wait_nokey();
			set_R();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_4 ))
		{
			in_wait_nokey();
			set_d();//routine
            in_wait_key();
            break;
		}

*/






    }//end while
}//end options1


void printOptions (void)
{
    {
        zx_cls(PAPER_WHITE | INK_BLUE);
        zx_border (2);
        printf("\x16\x01\x02");

        printf ("Welcome to the Bresenham Tester V1.0");
        printf ("\n");
        printf ("press a key for test");
        printf ("\n");

		printf ("1 -           a setting (1) = %d", a_setting);
        printf ("\n");
		printf ("2 -           b setting (2) = %d", b_setting);
		printf ("\n\n");


        printf ("Q - String Circle C-Bresenham Line");
        printf ("\n");
        printf ("W- Lissajous onecoder estimate");
        printf ("\n");
        printf ("E- Lissajous SMILE estimate");
        printf ("\n");
        printf ("R- Lissajous QSIN estimate");
        printf ("\n");
        printf ("P - C Bresenham Line");

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

//leave blank line after
