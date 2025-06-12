#ifndef SINE_ESTIMATOR_H
#define SINE_ESTIMATOR_H

#define ABS(N) ((N<0)?(-N):(N))


float wrap (float xx)
{
    return xx - 6.28 * floor(xx / 6.28 + 0.5);
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


float hella_cos (float xx)
{
	return hellaSin(xx + PI / 2);
}

#endif
//leave blank line after

