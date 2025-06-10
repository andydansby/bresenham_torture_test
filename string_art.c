
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

        bresenham_C10(x1, y1, x2, y2);
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

        //bresenham_C0(0, y1, x1, height);  // From left edge to bottom edge
        line_x1 = 0;
        line_y1 = y1;
        line_x2 = x1;
        line_y2 = height;
        //bresenham_line_1();


        //bresenham_C0(width, y1, x1, 0);  //
        line_x1 = width;
        line_y1 = y1;
        line_x2 = x1;
        line_y2 = 0;
        //bresenham_line_1();

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
        //bresenham_C0(centerX, centerY, x2, y2);

        line_x1 = centerX;
        line_y1 = centerY;
        line_x2 = x2;
        line_y2 = y2;
        //bresenham_line_1();
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
        //bresenham_line_1();
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
            //line_x2 = x2;

            //bresenham_line_1();
        }
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}









void drawLineWhirlpool(int radius, int lines, double twist)
{
    timerStart();
    for (int iterations = 0; iterations < lines; iterations++)
    {
        float t = (float)iterations / lines;

        // Two rotating angles
        rad_angle1 = 2 * PI * t;
        rad_angle2 = 2 * PI * t * twist;

        int x1 = centerX + radius * cos(rad_angle1);
        int y1 = centerY + radius * sin(rad_angle1);
        int x2 = centerX + radius * cos(rad_angle2);
        int y2 = centerY + radius * sin(rad_angle2);

        bresenham_C0(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}

/*void drawLinearWhirlpool(int radius, int steps, int lines, float rotation)
{
    for (int iterations = 0; iterations < lines; iterations++)
    {
        float t1 = (float)iterations / lines;
        float t2 = (float)(iterations + 1) / lines;

        // Interpolated radius
        float r1 = radius * (1.0 - t1);
        float r2 = radius * (1.0 - t2);

        // Angles increase linearly, but one side rotated more for spiral
        rad_angle1 = iterations * rotation;
        rad_angle2 = (iterations + 1) * rotation * 1.05; // slight offset

        // Convert to Cartesian (optional: replace with lookup or linear angle sweep)
        x1 = centerX + r1 * cos(rad_angle1);
        y1 = centerY + r1 * sin(rad_angle1);
        x2 = centerX + r2 * cos(rad_angle2);
        y2 = centerY + r2 * sin(rad_angle2);

        bresenham_C1(x1, y1, x2, y2);
    }
}*/

void drawLinearWhirlpool(int radius, int points, int step)
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
}





void drawSpiralPattern(int size, int steps)
{
    timerStart();
    for (iterations = 0; iterations < steps; iterations++)
    {
        x1 = centerX - size + (2 * size * iterations) / steps;
        y1 = centerY - size;
        x2 = centerX + size;
        y2 = centerY - size + (2 * size * iterations) / steps;

        bresenham_C0(x1, y1, x2, y2);
    }
    for (iterations = 0; iterations < steps; iterations++)
    {
        x1 = centerX + size;
        y1 = centerY - size + (2 * size * iterations) / steps;
        x2 = centerX + size - (2 * size * iterations) / steps;
        y2 = centerY + size;

        bresenham_C0(x1, y1, x2, y2);
    }

    for (iterations = 0; iterations < steps; iterations++)
    {
        x1 = centerX + size - (2 * size * iterations) / steps;
        y1 = centerY + size;
        x2 = centerX - size;
        y2 = centerY + size - (2 * size * iterations) / steps;

        bresenham_C0(x1, y1, x2, y2);
    }

    for (iterations = 0; iterations < steps; iterations++)
    {
        x1 = centerX - size;
        y1 = centerY + size - (2 * size * iterations) / steps;
        x2 = centerX - size + (2 * size * iterations) / steps;
        y2 = centerY - size;

        bresenham_C0(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);

}




///////////////////////////////////////

void spiral(unsigned char b)
{
    timerStart();
    int centerX = 127;
    int centerY = 96;
    float a = 0;
    float b = 2;  // Controls spiral spacing
    float angle_step = 0.1;
    float angle, r1, r2;

    for (angle = 0; angle < 10 * PI; angle += angle_step)
    {
        r1 = a + b * angle;
        r2 = a + b * (angle + angle_step);

        x1 = centerX + r1 * cos(angle);
        y1 = centerY + r1 * sin(angle);
        x2 = centerX + r2 * cos(angle + angle_step);
        y2 = centerY + r2 * sin(angle + angle_step);
        bresenham_C0(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);

}


void drawHypotrochoid(float R, float r, float d)
{
    timerStart();
    int cx = 127;
    int cy = 96;
    float t;
    int a = r;
    int b = R;
    //int t;


    x1 = cx + (int)((R - r) * cos(0) + d * cos((R - r) / r * 0));
    y1 = cy + (int)((R - r) * sin(0) - d * sin((R - r) / r * 0));



    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }

    //for (t = 0; t <= 2 * PI * r / a; t += 0.01)
    for (t = 0; t <= 2 * PI * r / a; t += 0.01)
    {
        x2 = cx + (int)((R - r) * cos(t) + d * cos((R - r) / r * t));
        y2 = cy + (int)((R - r) * sin(t) - d * sin((R - r) / r * t));
        bresenham_C0(x1, y1, x2, y2);
        x1 = x2;
        y1 = y2;
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}


void chord_grid(int radius, int points, float factor)
{
    timerStart();
    for (int iterations = 0; iterations < points; iterations++)
    {
        float angle1 = 2 * M_PI * iterations / points;
        float angle2 = 2 * M_PI * fmod(iterations * factor, points) / points;

        x1 = centerX + radius * cos(angle1);
        y1 = centerY + radius * sin(angle1);
        x2 = centerX + radius * cos(angle2);
        y2 = centerY + radius * sin(angle2);
        bresenham_C0(x1, y1, x2, y2);
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}



//////////////////////

// Draw a Lissajous figure
void draw_lissajous(unsigned char cx, unsigned char cy, unsigned char amp_x,
                     unsigned char amp_y, float freq_x, float freq_y,
                     float phase, unsigned char steps)
{
    float x2f, y2f;
    rad_angle_step = (2 * PI) / steps;

    f_x1 = cx + amp_x * sin(phase);
    f_y1 = cy + amp_y * sin(0);

    for (i = 1; i <= steps; i++)
    {
        t = i * rad_angle_step;

        x2f = cx + amp_x * sin(freq_x * t + phase);
        y2f = cy + amp_y * sin(freq_y * t);

        x1 = (unsigned char)f_x1;
        y1 = (unsigned char)f_y1;
        x2 = (unsigned char)x2f;
        y2 = (unsigned char)y2f;

        //if (x2 < 256 && y2 < 192 && x1 < 256 && y1 < 192)
            bresenham_C0(x1, y1, x2, y2);

        f_x1 = x2f;
        f_y1 = y2f;
    }
    timerEnd();
    printf("\x16\x01\x01");
    printf("\n\ntime = %ld MS", timeDiff);
}


