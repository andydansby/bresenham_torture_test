PUBLIC _bresenham_line_3
_bresenham_line_3:
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	                           ;  deltaX = abs(x2 - x1);
	                           ;  first we perform x2-x1

DX_ABS3:
	xor A                      ;  clear flags
	ld A,(_line_x2)            ;  load in X end point
	ld L,A                     ;  copy to L
	ld A,(_line_x1)            ;  load in X start point
	sbc A, L                   ;  find the difference

	jp p,DXABS3_finished       ;  if a positive number, ABS found
	                           ;  otherwise
	neg                        ;  invert all bits if negative number
DXABS3_finished:
	ld D,A                     ;  write our answer to D

step_X3:	                   ;  line_x1 and line_x2 have already been
	                           ;  evaluated once, use those results
	                           ;  stepx = (x2 < x1) ? -1 : 1;
	jp c,positiveDX3
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;
negativeDX3:	               ;  point 1 is larger, going backwards
	ld A,-1                    ;  set A to -1 or $FF
	ld (stepX),A               ;  load into variable
	jp DY_ABS
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;

positiveDX3:	               ;  point 2 is larger, going forwards
	ld A,1                     ;  set a to +1
	ld (stepX),A               ;  load into variable
	                           ;  120 T-States
	                           ;  31 Bytes

	                           ;  ;;;;;;;;;;;;;;;;;
                               ;  deltaX in D deltaY in E
DY_ABS3:
	xor A                      ;  clear flags
	ld A,(_line_y2)            ;  load in Y end point
	ld L,A                     ;  copy to L
	ld A,(_line_y1)            ;  load in Y start point

	sbc A, L

	jp p,DYABS3_finished       ;  if a positive number, ABS found
	                           ;  otherwise
	neg                        ;  invert all bits if negative number
DYABS3_finished:
	ld E,A                     ;  write our answer to E register

step_Y3:	                   ;  stepy = (y2 < y1) ? -1 : 1;
	                           ;  line_x1 and line_x2 have already been
	                           ;  evaluated once, use those results
	jp c,positiveDY3
	                           ;  fall through if negative, Y2 is larger
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;
negativeDY3:
	ld A,-1                    ;  set A to -1 or $FF
	ld (stepY),A               ;  load into variable
	jp steps_calculation3
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;
positiveDY3:
	ld A,1                     ;  set A to +1
	ld (stepY),A               ;  load into variable
	                           ;  ld A,H

steps_calculation3:	           ;  steps = max(deltaX, deltaY);
	                           ;  deltaX in D deltaY in E
	ld H,E
	ld A,D                     ;  load in length of Y axis
	cp H                       ;  compare against deltaX
	jr c,delta_Y_max3          ;  if carry flag is set, then delta_Y is larger

delta_X_max3:
	ld A,D                     ;  now that deltaX is the maximum, load it into A
	jr max_steps3

delta_Y_max3:
	ld A,E                     ;  now that deltaY is the maximum, load it into A

max_steps3:
	ld (steps),A               ;  now we know the maximum pixels that will be used


	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;
	                           ;  lets start our loop
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;

DXDY_loop3:	                   ;  deltaX in D deltaY in E
	                           ;  if (deltaX > deltaY)
	                           ;  ld A,(deltaX)
	ld H,D                     ;  load deltaX
	ld A,E                     ;  load deltaY
	cp H                       ;  compare deltaX and deltaY
	jp nc,delta_Y_larger3      ;  if no carry the deltaY is larger
	                           ;  otherwise fall through

delta_X_larger3:	           ;  if (deltaX > deltaY)
	jp deltaX_case3

	                           ;  else if (deltaY >= deltaX)
delta_Y_larger3:
	jp deltaY_case3

	                           ;  NOW we need to start treating
	                           ;  deltaX and deltaY as 16 bit variables
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;

deltaX_case3:	               ;  if (deltaX > deltaY)

	                           ;  fraction = deltaY - (deltaX >> 1);
	                           ;  fraction = deltaY - (deltaX / 2);
	                           ;  deltaX in D deltaY in E

	ld A,D                     ;  load deltaX into Accumulator
	srl A                      ;  scroll right 1 bit to divide by 2
	ld C,A                     ;  load into low bit of BC
	ld A,E                     ;  load deltaY into A
	sub C                      ;  subtract deltaX
	ld (fraction),A            ;  store answer

deltaX_loop3:	               ;  for (iterations = 0; iterations <= steps; iterations++)

	ld A,(iterations)
	ld H,A
	ld A,(steps)
	cp H                       ;  compare steps with iterations
	ret Z                      ;  replacement to save space and speed
	                           ;  otherwise continue the loop

	                           ;  now plot our point
	ld A,(_line_x1)
	ld H,A
	ld A,(_line_y1)
	ld L,A
	ld (_gfx_xy), HL
	call _hellaPlot2
		                       ; 71 T + routine time
	                           ; 15 bytes

check_DeltaX_Fraction3:
	                           ;  check to see if fraction is less than 0
	xor A                      ;  clear flags and A
	ld L,A                     ;  set L to 0
	ld A,(fraction)            ;  load in fraction
	sub L                      ;  is it less than 0
	jp m,add_x_fraction3       ;  L is > 0 Sign flag is ON


	                           ;  jp p sign flag OFF
	                           ;  jp m sign flag ON

subtract_x_fraction3:	       ;  fraction >= 0

	                           ;  deltaX in D deltaY in E
	                           ;  fraction is already in A
	                           ;  fraction -= deltaX;
	sbc A, D		           ;  subtract fraction and deltaX
	ld (fraction), A	       ;  answer
	;17T
	;4 bytes


	                           ;  y1 += stepy;
	ld A,(_line_y1)            ;  load in _line_y1
	ld H,A                     ;  move to H
	ld A,(stepY)               ;  load in stepy
	add A,H                    ;  add the two
	ld (_line_y1),A            ;  answer
	                           ;  47 T
	                           ;  11 bytes

	                           ;  fraction < 0
add_x_fraction3:
		                       ;  fraction += deltaY;
	                           ;  deltaX in D deltaY in E

	ld A, (fraction)	       ;  load in fraction
	add A, E		           ;  add fraction and deltaY
	ld (fraction), A

	                           ;  x1 += stepx;
	ld A,(_line_x1)            ;  load lineX1
	ld H,A                     ;  move to H
	ld A,(stepX)               ;  load stepX
	add A,H                    ;  add the two
	ld (_line_x1),A            ;  write the answer

deltaX_loop_increment3:
	                           ;  finally, we increment our loop by 1
	ld A,(steps)               ;  load in steps
	dec A                      ;  decrease staps by 1
	ld (steps),A               ;  rewrite steps

	jp deltaX_loop3            ;  jump back to start of loop

	                           ;  ;;;;;;;;;;;;;;;;;;;;;;

deltaY_case3:	               ;  if (deltaX > deltaY)

	                           ;  fraction = deltaX - (deltaY >> 1);
	                           ;  fraction = deltaX - (deltaY / 2);
	                           ;  deltaX in D deltaY in E
	ld A,E                     ;  load deltaY into Accumulator
	srl A                      ;  scroll right 1 bit to divide by 2
	ld C,A                     ;  load into low bit of BC
	ld A, D                    ;  load deltaX
	sub C                      ;
	ld (fraction),A            ;  store answer
	                           ;  37T
	                           ;  9 bytes


deltaY_loop3:	               ;  for (iterations = 0; iterations <= steps; iterations++)
	                           ;  incrementor
	ld A,(iterations)
	ld H,A
	ld A,(steps)
	cp H                       ;  compare steps with iterations
	ret Z                      ;  Line finished
	                           ;  otherwise continue the loop
							   ;  39 / 45T
							   ;  9 Bytes

	                           ;  now plot our point
	ld A,(_line_x1)
	ld H,A
	ld A,(_line_y1)
	ld L,A
	ld (_gfx_xy), HL
	call _hellaPlot2
		                       ;  71 T + routine time
	                           ;  15 bytes

check_DeltaY_Fraction3:
                               ;  check to see if fraction is less than 0
	xor A                      ;  clear flags and A
	ld L,A                     ;  set L to 0
	ld A,(fraction)            ;  load in fraction
	sub L                      ;  is it less than 0
	jp m,add_y_fraction3       ;  L is > 0 Sign flag is ON
                               ;  35 T
                               ;  9 bytes

subtract_y_fraction3:	       ;  fraction >= 0

	                           ;  deltaX in D deltaY in E
	                           ;  fraction is already in A
	                           ;  fraction -= deltaY;
	sbc A, E		           ;  subtract fraction and deltaY
	ld (fraction), A	       ;  answer
	                           ;  17T
	                           ;  4 bytes

	                           ;  x1 += stepx;
	ld A,(_line_x1)            ;  load linex1
	ld H,A                     ;  move to H
	ld A,(stepX)               ;  load stepX
	add A,H                    ;  add the two
	ld (_line_x1),A            ;  write the answer
	                           ;  47 T
	                           ;  11 bytes

	                           ;  fraction < 0
add_y_fraction3:
	                           ;  fraction += deltaX;
                               ;  deltaX in D deltaY in E
	ld A, (fraction)	       ;  load in fraction
	add A, D		           ;  add fraction and deltaX
	ld (fraction), A

		                       ;  y1 += stepx;
	ld A,(_line_y1)            ;  load lineY1
	ld H,A                     ;  move to H
	ld A,(stepY)               ;  load stepX
	add A,H                    ;  add the two
	ld (_line_y1),A            ;  write the answer

deltaY_loop_increment3:
	                           ;  finally, we increment our loop by 1
	ld A,(steps)               ;  load in steps
	dec A                      ;  decrease steps by 1
	ld (steps),A               ;  rewrite steps

	jp deltaY_loop3            ;  jump back to start of loop

