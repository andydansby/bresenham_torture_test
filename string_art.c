
void draw_circle_string_art(unsigned char radius, unsigned char points, unsigned char step)
{//c version
    timerStart();
    iterations = 0;

    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;

    rad_angle1 = 0;
    rad_angle2 = 0;

    rad_angle_step = 2 * PI / points;

    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = iterations * rad_angle_step;
        rad_angle2 = ((iterations + step) % points) * rad_angle_step;

        x1 = (unsigned char)(centerX + radius * cos(rad_angle1));
        y1 = (unsigned char)(centerY + radius * sin(rad_angle1));
        x2 = (unsigned char)(centerX + radius * cos(rad_angle2));
        y2 = (unsigned char)(centerY + radius * sin(rad_angle2));

        bresenham_C0(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void draw_circle_string_art4(unsigned char radius, unsigned char points, unsigned char step)
{//c version
    timerStart();
    iterations = 0;

    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;

    rad_angle1 = 0;
    rad_angle2 = 0;

    rad_angle_step = 2 * PI / points;

    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = iterations * rad_angle_step;
        rad_angle2 = ((iterations + step) % points) * rad_angle_step;

        x1 = (unsigned char)(centerX + radius * cos(rad_angle1));
        y1 = (unsigned char)(centerY + radius * sin(rad_angle1));
        x2 = (unsigned char)(centerX + radius * cos(rad_angle2));
        y2 = (unsigned char)(centerY + radius * sin(rad_angle2));

        //bresenham_C10(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void draw_circle_string_art5(unsigned char radius, unsigned char points, unsigned char step)
{//asm version
    timerStart();
    iterations = 0;

    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;

    rad_angle1 = 0;
    rad_angle2 = 0;

    rad_angle_step = 2 * PI / points;

    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = iterations * rad_angle_step;
        rad_angle2 = ((iterations + step) % points) * rad_angle_step;

        line_x1 = (unsigned char)(centerX + radius * cos(rad_angle1));
        line_y1 = (unsigned char)(centerY + radius * sin(rad_angle1));
        line_x2 = (unsigned char)(centerX + radius * cos(rad_angle2));
        line_y2 = (unsigned char)(centerY + radius * sin(rad_angle2));
        bresenham_line_3();
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}



void draw_circle_string_art2(unsigned char radius, unsigned char points, unsigned char step)
{//asm version
    timerStart();
    iterations = 0;

    line_x1 = 0;
    line_y1 = 0;
    line_x2 = 0;
    line_y2 = 0;

    rad_angle1 = 0;
    rad_angle2 = 0;

    rad_angle_step = 2 * PI / points;

    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = iterations * rad_angle_step;
        rad_angle2 = ((iterations + step) % points) * rad_angle_step;

        line_x1 = (unsigned char)(centerX + radius * cos(rad_angle1));
        line_y1 = (unsigned char)(centerY + radius * sin(rad_angle1));
        line_x2 = (unsigned char)(centerX + radius * cos(rad_angle2));
        line_y2 = (unsigned char)(centerY + radius * sin(rad_angle2));

        //no line at all loop timing    //3800 ms
        //bresenham_C0(x1, y1, x2, y2);//7020 ms
        bresenham_line_1();//5460 ms

    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}


void draw_circle_string_art3(unsigned char radius, unsigned char points, unsigned char step)
{//asm version
    timerStart();
    iterations = 0;

    line_x1 = 0;
    line_y1 = 0;
    line_x2 = 0;
    line_y2 = 0;

    rad_angle1 = 0;
    rad_angle2 = 0;

    rad_angle_step = 2 * PI / points;

    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = iterations * rad_angle_step;
        rad_angle2 = ((iterations + step) % points) * rad_angle_step;

        line_x1 = (unsigned char)(centerX + radius * cos(rad_angle1));
        line_y1 = (unsigned char)(centerY + radius * sin(rad_angle1));
        line_x2 = (unsigned char)(centerX + radius * cos(rad_angle2));
        line_y2 = (unsigned char)(centerY + radius * sin(rad_angle2));

        //no line at all loop timing    //3800 ms
        //bresenham_C0(x1, y1, x2, y2);//7020 ms
        //bresenham_line_1();//5460 ms

        bresenham_line_2();//5440 ms

    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}



// Draws a curve-like pattern from two edges using straight lines
void string_edge_curve(unsigned char steps)
{//c version
    timerStart();
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    width = 254;
    height = 191;
    for (iterations = 0; iterations <= steps; iterations++)
    {
        x1 = (width * iterations) / steps;
        y1 = (height * iterations) / steps;

        bresenham_C0(0, y1, x1, height);  // From left edge to bottom edge
        bresenham_C0(width, y1, x1, 0);  //
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void string_edge_curve2(unsigned char steps)
{//asm version
    timerStart();
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    width = 254;
    height = 191;
    for (iterations = 0; iterations <= steps; iterations++)
    {
        x1 = (width * iterations) / steps;
        y1 = (height * iterations) / steps;

        //bresenham_C0(width, y1, x1, 0);  //
        line_x1 = width;
        line_y1 = y1;
        line_x2 = x1;
        line_y2 = 0;
        bresenham_line_1();

    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void string_edge_curve3(unsigned char steps)
{//asm version
    timerStart();
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    width = 254;
    height = 191;
    for (iterations = 0; iterations <= steps; iterations++)
    {
        x1 = (width * iterations) / steps;
        y1 = (height * iterations) / steps;

        //bresenham_C0(width, y1, x1, 0);  //
        line_x1 = width;
        line_y1 = y1;
        line_x2 = x1;
        line_y2 = 0;
        bresenham_line_2();

    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}


void string_edge_curve4(unsigned char steps)
{//asm version
    timerStart();
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    width = 254;
    height = 191;
    for (iterations = 0; iterations <= steps; iterations++)
    {
        x1 = (width * iterations) / steps;
        y1 = (height * iterations) / steps;

        //bresenham_C0(width, y1, x1, 0);  //
        line_x1 = width;
        line_y1 = y1;
        line_x2 = x1;
        line_y2 = 0;
        bresenham_line_3();

    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}



void draw_radial_spokes(unsigned char r, unsigned char num_spokes)
{//c version
    timerStart();
    //int centerX = 127;
    //int centerY = 96;
    for (iterations = 0; iterations < num_spokes; iterations++)
    {
        rad_angle1 = 2 * PI * iterations / num_spokes;
        x2 = (unsigned char)(centerX + r * cos(rad_angle1));
        y2 = (unsigned char)(centerY + r * sin(rad_angle1));
        bresenham_C0(centerX, centerY, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void draw_radial_spokes2(unsigned char r, unsigned char num_spokes)
{//asm version
    timerStart();
    //int centerX = 127;
    //int centerY = 96;
    for (iterations = 0; iterations < num_spokes; iterations++)
    {
        rad_angle1 = 2 * PI * iterations / num_spokes;
        x2 = (unsigned char)(centerX + r * cos(rad_angle1));
        y2 = (unsigned char)(centerY + r * sin(rad_angle1));

        line_x1 = centerX;
        line_y1 = centerY;
        line_x2 = x2;
        line_y2 = y2;
        bresenham_line_1();
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}


void draw_radial_spokes3(unsigned char r, unsigned char num_spokes)
{//asm version
    timerStart();
    //int centerX = 127;
    //int centerY = 96;
    for (iterations = 0; iterations < num_spokes; iterations++)
    {
        rad_angle1 = 2 * PI * iterations / num_spokes;
        x2 = (unsigned char)(centerX + r * cos(rad_angle1));
        y2 = (unsigned char)(centerY + r * sin(rad_angle1));

        line_x1 = centerX;
        line_y1 = centerY;
        line_x2 = x2;
        line_y2 = y2;
        bresenham_line_2();
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void draw_radial_spokes4(unsigned char r, unsigned char num_spokes)
{//asm version
    timerStart();
    //int centerX = 127;
    //int centerY = 96;
    for (iterations = 0; iterations < num_spokes; iterations++)
    {
        rad_angle1 = 2 * PI * iterations / num_spokes;
        x2 = (unsigned char)(centerX + r * cos(rad_angle1));
        y2 = (unsigned char)(centerY + r * sin(rad_angle1));

        line_x1 = centerX;
        line_y1 = centerY;
        line_x2 = x2;
        line_y2 = y2;
        bresenham_line_3();
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}



void draw_modulas(unsigned char points, unsigned char k)
{//C version
    timerStart();
    //int centerX = 127;
    //int centerY = 96;
    int radius = 90;

    for (iterations = 0; iterations < points; iterations++)
    {
        f_temp = (iterations * k) % points;
        rad_angle1 = 2 * PI * iterations / points;
        rad_angle2 = 2 * PI * f_temp / points;

        x1 = centerX + radius * cos(rad_angle1);
        y1 = centerY + radius * sin(rad_angle1);
        x2 = centerX + radius * cos(rad_angle2);
        y2 = centerY + radius * sin(rad_angle2);
        bresenham_C0(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void draw_modulas2(unsigned char points, unsigned char k)
{//asm version
    timerStart();
    //int centerX = 127;
    //int centerY = 96;
    int radius = 90;

    for (iterations = 0; iterations < points; iterations++)
    {
        f_temp = (iterations * k) % points;
        rad_angle1 = 2 * PI * iterations / points;
        rad_angle2 = 2 * PI * f_temp / points;

        line_x1 = centerX + radius * cos(rad_angle1);
        line_y1 = centerY + radius * sin(rad_angle1);
        line_x2 = centerX + radius * cos(rad_angle2);
        line_y2 = centerY + radius * sin(rad_angle2);
        bresenham_line_1();
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void draw_pin(unsigned char points)
{
    timerStart();
    int radius = 90;
    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = 2 * PI * iterations / points;

        x1 = centerX + radius * cos(rad_angle1);
        y1 = centerY + radius * sin(rad_angle1);

        for (f_temp = iterations + 1; f_temp < points; f_temp++)
        {
            rad_angle2 = 2 * PI * f_temp / points;
            x2 = centerX + radius * cos(rad_angle2);
            y2 = centerY + radius * sin(rad_angle2);

            bresenham_C0(x1, y1, x2, y2);
        }
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

void draw_pin2(unsigned char points)
{
    timerStart();
    int radius = 90;
    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = 2 * PI * iterations / points;

        x1 = centerX + radius * cos(rad_angle1);
        x2 = centerY + radius * sin(rad_angle1);

        for (f_temp = iterations + 1; f_temp < points; f_temp++)
        {
            rad_angle2 = 2 * PI * f_temp / points;
            line_x2 = centerX + radius * cos(rad_angle2);
            line_y2 = centerY + radius * sin(rad_angle2);

            line_x1 = x1;
            line_y1 = x2;

            bresenham_line_1();
        }
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}






























/*void drawLinearWhirlpool(int radius, int points, int step)
{
    timerStart();
    float angle_increment = 2 * M_PI / points;
    for (iterations = 0; iterations < points; iterations++)
    {
        rad_angle1 = iterations * angle_increment;
        rad_angle2 = ((iterations + step) % points) * angle_increment;

        x1 = centerX + radius * cos(rad_angle1);
        y1 = centerY + radius * sin(rad_angle1);
        x2 = centerX + radius * cos(rad_angle2);
        y2 = centerY + radius * sin(rad_angle2);

        bresenham_C0(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}*/


///////////////////////////////////////


//////////////////////

