

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

//C0  = 7020
//C10 = 7500
void bresenham_C10(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{//Andy's Version

    signed char stepx = 0;//must be signed
    signed char stepy = 0;//must be signed

    unsigned char steps = 0;
    unsigned char iterations = 0;

    signed char deltaX = 0;
    signed char deltaY = 0;

    signed char fraction = 0;//must be signed

    deltaX = abs(x2 - x1);
    deltaY = abs(y2 - y1);
    stepx = (x1 < x2) ? 1 : -1;
    stepy = (y1 < y2) ? 1 : -1;
    steps = max(deltaX, deltaY);

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

