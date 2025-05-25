const float DOUBLEPI = 6.283184;
const float PI = 3.14159;
const float HALFPI = 1.570795;
const float QUARTERPI = 0.785398;

signed int x, y;
float t;
float YY, yy;

float sinCalc = 0;

unsigned char yHeight = 172;//height of the display
unsigned char xWidth = 255;//width of the display
unsigned char X_start = 255;
unsigned char Y_start = 45;

float sineCycle = 0;

unsigned char waveHeight = 40;
int halfHeight = 20;//waveHeight / 2
unsigned char offSet = 46;
float freq = 2;



int amplitude = 0;
int period = 0;
int phase_shift = 0;
int vertical_shift = 0;


int a_setting = 1;
int b_setting = 2;

float delta = 3.14/2;
int x_offset = 128;
int y_offset = 90;
int A = 120;
int B = 90;


int R_setting;
//int r_setting;
int d_setting;


//////////
unsigned char i;
unsigned char iterations;
unsigned char x1;
unsigned char y1;
unsigned char x2;
unsigned char y2;
unsigned char width = 255;
unsigned char height = 191;
unsigned char centerX = 127;
unsigned char centerY = 96;

float rad_angle1;
float rad_angle2;
float rad_angle_step;
float f_temp;
float t;

float f_x1;
float f_y1;


long microSec;
long seconds;
long minutes;
long timeStart;
long timeEnd;
long timeDiff;

