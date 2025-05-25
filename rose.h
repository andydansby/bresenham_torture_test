#ifndef ROSE_H
#define ROSE_H


void ROSE_S_Sine (void)
{
    float a = 0;
    float d = d_setting;
    float r = R_setting;//60
    float calcX = 0;
    float calcY = 0;
    int x_offset = 128;//128
    int y_offset = 86;//86

    float radius = 60;

    //r = 50 * cos(7 * a);
    while (1)
    {

        radius = 60 * S_cos(d * a);
        calcX = radius * S_cos (a + r);
        calcY = radius * S_sine (a + r);

        x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        a = a + .01;
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}


void ROSE_Q_Sine (void)
{
    float a = 0;
    float d = d_setting;
    float r = R_setting;//60
    float calcX = 0;
    float calcY = 0;
    int x_offset = 128;//128
    int y_offset = 86;//86

    float radius = 60;

    //r = 50 * cos(7 * a);
    while (1)
    {

        radius = 60 * Q_cos(d * a);
        calcX = radius * Q_cos (a + r);
        calcY = radius * Q_sin (a + r);

        x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        a = a + .01;
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}


void ROSE_Hella_Sine (void)
{
    float a = 0;
    float d = d_setting;
    float r = R_setting;//60
    float calcX = 0;
    float calcY = 0;
    int x_offset = 128;//128
    int y_offset = 86;//86

    float radius = 60;

    //r = 50 * cos(7 * a);
    while (1)
    {

        radius = 60 * hella_cos(d * a);
        calcX = radius * hella_cos (a + r);
        calcY = radius * hellaSin (a + r);

        x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        a = a + .01;
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}

void ROSE_Onecoder_Sine (void)
{
    float a = 0;
    float d = d_setting;
    float r = R_setting;//60
    float calcX = 0;
    float calcY = 0;
    int x_offset = 128;//128
    int y_offset = 86;//86

    float radius = 60;

    //r = 50 * cos(7 * a);
    while (1)
    {

        radius = 60 * _onecoder_cos(d * a);
        calcX = radius * _onecoder_cos (a + r);
        calcY = radius * _oneCoder_sin (a + r);

        x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        a = a + .01;
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}


/*
void Hypotrochoid_Rose (void)
{
    float t=0;
    float calcX, calcY;
    float a = (float) a_setting;
    float b = (float) b_setting;

    float R = (float)R_setting + .5;// changes shape
//    float r = (float)r_setting + .5;
    float d = (float)d_setting + .5;
    //originally
    //R = 125;
    //r = 75;
    //d = 125;

    float angle = 0;
    float theta = 0.04;//0.2
    //float steps = 6 * PI /theta;//float steps = (int)(6 * PI /theta);
    float steps = 2 * PI /theta;

    int x_offset = 128;//128
    int y_offset = 86;//86

    while (1)
    {
		angle+=theta;
        calcX = ((R - r) * S_cos(angle) + d * S_cos (((R-r)/r)*angle) );
        calcY = ((R - r) * S_sine(angle) - d * S_sine(((R-r)/r)*angle) );

		x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}
*/

//////////////////////////////////////
//THESE ARE NOT WORKING


void ROSE_curious (void)
{
    float a = 0;
    float d = d_setting;
    float r = R_setting;//60
    float calcX = 0;
    float calcY = 0;
    int x_offset = 128;//128
    int y_offset = 86;//86

    float radius = 60;

    //r = 50 * cos(7 * a);
    while (1)
    {

        radius = 60 * S_cos(d * r);
        calcX = radius * S_cos (a * d);
        calcY = radius * S_sine (a * r);

        x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        a = a + .005;
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}


void ROSE_curious2 (void)
{
    float a = 0;
    float d = d_setting;
    float r = R_setting;//60
    float calcX = 0;
    float calcY = 0;
    int x_offset = 128;//128
    int y_offset = 86;//86

    float radius = 60;

    //r = 50 * cos(7 * a);
    while (1)
    {

        radius = 60 * Q_cos(d * a);
        calcX = radius * Q_cos (a * d);
        calcY = radius * Q_sin (a * r);

        //x = (int) calcX;
        //y = (int) calcY;

        x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        a = a + .005;
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}


void ROSE_curious3 (void)
{
    float a = 0;
    float d = d_setting;
    float r = R_setting;//60
    float calcX = 0;
    float calcY = 0;
    int x_offset = 128;//128
    int y_offset = 86;//86

    float radius = 60;

    //r = 50 * cos(7 * a);
    while (1)
    {

        radius = 60 * hella_cos(d * a);
        calcX = radius * hella_cos (a);
        calcY = radius * hellaSin (a);

        //x = (int) calcX;
        //y = (int) calcY;

        x = (int) calcX + x_offset;
        y = (int) calcY + y_offset;
		plot(x, y);

        a = a + .01;
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }
}


#endif
//leave blank line after

