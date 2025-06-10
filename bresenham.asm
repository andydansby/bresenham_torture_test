include "bresenham_line1.asm"
include "bresenham_line2.asm"
include "bresenham_line3.asm"

;PUBLIC _bresenham_line_2
;_bresenham_line_2:
;ret

;local variables
stepX:	defb 0              ;  direction of travel horizontally
stepY:	defb 0              ;  direction of travel vertically

steps:	defb 0              ;  the total number of pixels to be plotted
iterations:	defb 0          ;  loop counter

deltaX:	defw 0              ;  distance between points in X axis
deltaY:	defw 0              ;  distance between points in Y axis

fraction:	defw 0          ;  pivot point on the next pixel direction

;  Bresenham variables
PUBLIC _line_x1
_line_x1:	defb 000        ;  line start point X

PUBLIC _line_y1
_line_y1:	defb 000        ;  line start point Y

PUBLIC _line_x2
_line_x2:	defb 000        ;  line end point X

PUBLIC _line_y2
_line_y2:	defb 000        ;  line end point Y



