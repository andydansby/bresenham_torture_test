void bresenham_C4(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
    int deltaX = 0;
    int deltaY = 0;
    signed char stepx = 0;
    signed char stepy = 0;
    int error1 = 0;
    int error2 = 0;
    deltaX = abs(x2 - x1);
    deltaY = abs(y2 - y1);

    stepx = x1 < x2 ? 1 : -1;
    stepy = y1 < y2 ? 1 : -1;
    error1 = deltaX - deltaY;

    while (1)
    {
        if (x1 == x2)
        {
            if (y1 == y2)
            {
                break;
            }
        }
        error2 = error1 + error1;
        if (error2 > -deltaY)
        {
            error1 -= deltaY;
            x1 += stepx;

            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();
        }
        if (error2 < deltaX)
        {
            error1 += deltaX;
            y1 += stepy;

            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();
        }
    }
}//end routine


void bresenham_C2(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
    signed char stepx = 0;
    signed char stepy = 0;

    int deltaX = 0;
    int deltaY = 0;

    int error1 = 0;
    int error2 = 0;

    stepx = x1 < x2 ? 1 : -1;
    stepy = y1 < y2 ? 1 : -1;
    deltaX = abs(x2 - x1);
    deltaY = abs(y2 - y1);
    deltaY = -deltaY;//     ?
    error1 = deltaX + deltaY;

    while (1)
    {
        gfx_x = x1;
        gfx_y = y1;
        createPixel_variable();
        hellaPlot();
        if (x1 == x2)
        {
            if (y1 == y2)
            {
                break;
                //if both match then the line is done
                //exit the loop
            }
        }
        error2 = error1 + error1;

        // deltaY case
        if (error2 >= deltaY)
        {
            if (x1 == x2)
            {
                break;
            }

            error1 = error1 + deltaY;
            x1 = x1 + stepx;
        }//end IF

        //deltaX case
        if (error2 <= deltaX)
        {
            if (y1 == y2)
            {
                break;
            }

            error1 = error1 + deltaX;
            y1 = y1 + stepy;
        }//end IF
    }//end while
}//end routine

void bresenham_C3(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
    int delta_x1;//signed
    int delta_y1;//signed
    int stepx;//signed
    int stepy;//signed
    int fraction;//signed

    delta_x1 = x2 - x1;
    delta_y1 = y2 - y1;

    stepx = (delta_x1 < 0) ? -1 : 1;
    stepy = (delta_y1 < 0) ? -1 : 1;

    delta_x1 = abs(delta_x1);
    delta_y1 = abs(delta_y1);

    gfx_x = x1;
    gfx_y = y1;
    createPixel_variable();
    hellaPlot();

    if (delta_x1 > delta_y1)
    {
        fraction = delta_y1 - (delta_x1 >> 1);
        while (x1 != x2)
        {
                    //buffer_plotX = xx1;
                    //buffer_plotY = yy1;
                    //buffer_plot();
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= delta_x1;
            }
            x1 += stepx;
            fraction += delta_y1;
        }//end while
    }//end if
    else
    {
        fraction = delta_x1 - (delta_y1 >> 1);
        while (y1 != y2)
        {
            //buffer_plotX = xx1;
            //buffer_plotY = yy1;
            //buffer_plot();
            //buffer_point();
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                x1 += stepx;
                fraction -= delta_y1;
            }
            y1 += stepy;
            fraction += delta_x1;
        }//end while
    }//end else
}//end routine


void bresenham_C0(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{//Andy's Version
    int fraction = 0;
    //signed char fraction = 0;   //close but has errors
    //unsigned char = wrong


    unsigned char iterations = 0;

    signed char stepx = 0;
    signed char stepy = 0;
    unsigned char steps = 0;

    unsigned char deltaX = 0;
    unsigned char deltaY = 0;

    deltaX = abs(x2 - x1);
    deltaY = abs(y2 - y1);

    stepx = (x1 < x2) ? 1 : -1;
    stepy = (y1 < y2) ? 1 : -1;

    steps = max(deltaX, deltaY);

    //plot starting point
    gfx_x = x1;
    gfx_y = y1;
    createPixel_variable();
    hellaPlot();

    if (deltaX > deltaY)
    {
        fraction = deltaY - (deltaX >> 1);
        //fraction = deltaY - (deltaX / 2);

        for (iterations = 0; iterations <= steps;  iterations++)
        {
            //buffer_plotX = x1;
            //buffer_plotY = y1;
            //buffer_plot();        //buffer_point();
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                fraction -= deltaX;
                y1 += stepy;
            }
            x1 += stepx;
            fraction += deltaY;
        }//end for loop
    }//end if
    else       //(deltaX <= deltaY)     (deltaY >= deltaX)
    {
        fraction = deltaX - (deltaY >> 1);
        //fraction = deltaX - (deltaY / 2);

        for (iterations = 0; iterations <= steps; iterations++)
        {
            //buffer_plotX = x1;
            //buffer_plotY = y1;
            //buffer_plot();                        //buffer_point();
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                fraction -= deltaY;
                x1 += stepx;
            }
            y1 += stepy;
            fraction += deltaX;
        }//end for loop
    }//end else
}

void bresenham_C5(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
    int pixel_sum = 0;
    int iterations = 0;
    int delta_y1;
    int delta_x1;

    int deltaX;
    int deltaY;

    int stepx;
    int stepy;
    int fraction;

    delta_x1 = x2 - x1;
    delta_y1 = y2 - y1;

    stepx = (delta_x1 < 0) ? -1 : 1;
    stepy = (delta_y1 < 0) ? -1 : 1;

    deltaX = abs(delta_x1);
    deltaY = abs(delta_y1);

    pixel_sum = max(deltaX, deltaY);
    //plot starting point
    //buffer_plotX = xx1;
    //buffer_plotY = yy1;
    //buffer_plot();

    if (deltaX > deltaY)
    {
        fraction = deltaY - (deltaX >> 1);// multiply by 2

        for (iterations = 0; iterations < pixel_sum; iterations++)
        {
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= deltaX;
            }
            x1 += stepx;
            fraction += deltaY;
        }//end for loop
    }//end if
    else       //(deltaX <= deltaY)     (deltaY >= deltaX)
    {
        fraction = deltaX - (deltaY >> 1);
        for (iterations = 0; iterations < pixel_sum; iterations++)
        {
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                x1 += stepx;
                fraction -= deltaY;
            }
            y1 += stepy;
            fraction += deltaX;
        }//end for loop
    }//end else
}//end routine

void bresenham_C6(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
    int deltaX;
    int deltaY;
    int error1;
    int error2;
    unsigned char stepX;
    unsigned char stepY;
    unsigned char iterations;
    unsigned char steps;

    deltaX = abs(x2 - x1);
    deltaY = abs(y2 - y1);
    stepX = (x1 < x2) ? 1 : -1;
    stepY = (y1 < y2) ? 1 : -1;
    error1 = deltaX - deltaY;
    error2 = 0;

    //steps = (deltaX > deltaY) ? deltaX : deltaY;  // no +1 if loop includes final pixel
    steps = max (deltaX, deltaY);

    for (iterations = 0; iterations <= steps; iterations++)
    {
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

        //error2 = 2 * error1;//error2 = error1 + error1;
        error2 = error1 << 1;

        if (error2 > -deltaY)
        {
            error1 -= deltaY;
            x1 += stepX;
        }
        if (error2 < deltaX)
        {
            error1 += deltaX;
            y1 += stepY;
        }
    }
}//end routine


void bresenham_C1(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{//Andy's Version
    int fraction = 0;
    int iterations = 0;
    unsigned char stepx = 0;
    unsigned char stepy = 0;
    unsigned char steps = 0;
    unsigned char deltaX = 0;
    unsigned char deltaY = 0;
    deltaX = abs(x2 - x1);
    deltaY = abs(y2 - y1);
    stepx = (x1 < x2) ? 1 : -1;
    stepy = (y1 < y2) ? 1 : -1;
    steps = max(deltaX, deltaY);

    //plot starting point
    //gfx_x = x1;
    //gfx_y = y1;
    //createPixel_variable();
    //hellaPlot();

    if (deltaX > deltaY)
    {
        fraction = deltaY - (deltaX >> 1);        //fraction = deltaY - (deltaX / 2);

        for (iterations = 0; iterations <= steps;  iterations++)
        {
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                fraction -= deltaX;
                y1 += stepy;
            }
            x1 += stepx;
            fraction += deltaY;
        }//end for loop
    }//end if
    else
    {
        fraction = deltaX - (deltaY >> 1);        //fraction = deltaX - (deltaY / 2);

        for (iterations = 0; iterations <= steps; iterations++)
        {
            gfx_x = x1;
            gfx_y = y1;
            createPixel_variable();
            hellaPlot();

            if (fraction >= 0)
            {
                fraction -= deltaY;
                x1 += stepx;
            }
            y1 += stepy;
            fraction += deltaX;
        }//end for loop
    }//end else
}

