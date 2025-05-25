#ifndef SINE_ESTIMATOR_H
#define SINE_ESTIMATOR_H

#define ABS(N) ((N<0)?(-N):(N))


float wrap (float xx)
{
    return xx - 6.28 * floor(xx / 6.28 + 0.5);
}

//_sine_Smile
float S_sine(float xx)
{
	//http://devmaster.net/posts/9648/fast-and-accurate-sine-cosine
    //this routine was found by user Smile, don't know where
    //the algorithm comes from

    const float A = 7.5894;//A = 16 * sqrt(P);
    const float B = 1.6338;//B = (1 - P) / sqrt(P);
    const float C = 0.15915; //.157 = HALFPI, move decimal point left 1

    float xxx = xx * C;//xxx = xx / DOUBLEPI;

    xxx = xxx - floor(xxx + 0.5);//5620
    //xxx = xxx - (int)(xxx + .5);//5640


	xxx = A * xxx * (0.5 - ABS(xxx));
	//yy = A * yy * (0.5 - (yy));


	//return yy * (B + ABS(yy));
	return xxx * (B + ABS(xxx));
}

float _oneCoder_sin (float xx)
{
	xx = xx * 0.15915;
	xx = xx - floor (xx);
	return 20.785 * xx * (xx - 0.5) * (xx - 1.0);
	//return 20.785 * (j - 0) * (j - 0.5) * (j - 1.0);
}

//_sine_Smile
float Q_sin(float xx)
{
	xx = wrap(xx);

	if (xx < 0)
		return xx * (1.273 + 0.405 * xx);
	else
		return xx * (1.273 - 0.405 * xx);
}

float hellaSin (float xx)
{
    //
    //f(x)=0.38981969947653056*(pi-abs(x))
    //
    /*
    https://stackoverflow.com/questions/9285983/fast-equivalent-to-sin-for-dsp-referenced-in-stk

    How accurate do you need this?
    f(x)=0.398*x*(3.1076- abs(x))
    for x between -pi and pi
    This function, f(x)=0.398x*(3.1076-|x|), does a reasonably good job for x between -pi and pi.
    An even better approximation is f(x)=0.38981969947653056*(pi-|x|), which keeps the absolute error to 0.038158444604 or less for x between -pi and pi.
    */
    xx = wrap(xx);
    //return 0.3981 * xx * (PI - abs(xx));
    //return 0.3898 * xx * (PI - abs(xx));
    //ABS slows the routine down
    //return 0.3898 * xx * (PI - fabs(xx));


 /*   if (xx < 0)
		return 0.3898 * xx * (PI + (xx));
	else
		return 0.3898 * xx * (PI - (xx));*/


    if (xx < 0)
		return xx * 0.3898 * (PI + (xx));
	else
		return xx * 0.3898 * (PI - (xx));
}


//_SMILE_cosine
float S_cos (float xx)
{
	return S_sine(xx + PI / 2);
}

float _onecoder_cos (float xx)
{
	return _oneCoder_sin(xx + PI / 2);
}

float Q_cos (float xx)
{
	return Q_sin(xx + PI / 2);
}

float hella_cos (float xx)
{
	return Q_sin(xx + PI / 2);
}

#endif
//leave blank line after

