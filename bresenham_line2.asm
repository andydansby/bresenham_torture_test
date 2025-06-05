PUBLIC _bresenham_line_2
_bresenham_line_2:

;  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  deltaX = abs(x2 - x1);
;  first we perform x2-x1
DX_ABS:
	xor A                      ;  clear flags
	ld A,(_line_x2)            ;  load in X end point
	ld L,A                     ;  copy to L
	ld A,(_line_x1)            ;  load in X start point

	sub L                      ;  find the difference

	jp p,DXABS_finished2        ;  if a positive number, ABS found
	                           ;  otherwise
	neg                        ;  invert all bits if negative number
DXABS_finished2:
	ld D,A                     ;  write our answer to D


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  deltaY = abs(y2 - y1);
;  now we perform y2-y1
DY_ABS:
	xor A                      ;  clear flags
	ld A,(_line_y2)            ;  load in Y end point
	ld L,A                     ;  copy to L
	ld A,(_line_y1)            ;  load in Y start point

	sub L                      ;  find the difference

	jp p,DYABS_finished2        ;  if a positive number, ABS found
	                           ;  otherwise
	neg                        ;  invert all bits if negative number
DYABS_finished2:
	ld E,A                     ;  write our answer to E register

	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;ATTENTION
;temp:	                           ;  deltaX in D deltaY in E
;	ld A,D
;	ld (deltaX),A
;	ld A,E
;	ld (deltaY),A
;ATTENTION



step_X2:	                           ;  stepx = (x1 < x2) ? 1 : -1;
	xor A                      ;  clear flags
	ld A,(_line_x1)            ;  load point X1
	ld H,A                     ;  copy to H register
	ld A,(_line_x2)            ;  load point X2
	sub H                      ;  subtract point 1 from point 2
	                           ;  ld H,A ; store answer in H

	jp c,negativeDX2            ;  if carry flag is set, then X2 is smaller
	jp z,negativeDX2            ;  if carry flag is set, then X2 is smaller

	                           ;  fall through if positive, X2 is larger
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;;


positiveDX2:	                   ;  point 2 is larger, going forwards
	ld A,1                     ;  set a to +1
	ld (stepX),A               ;  load into variable
	                           ;  ld A,H
	jp step_Y2

	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;
negativeDX2:	                   ;  point 1 is larger, going backwards
	ld A,-1                    ;  set A to -1 or $FF
	ld (stepX),A               ;  load into variable
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;

step_Y2:	                           ;  stepy = (y1 < y2) ? 1 : -1;
	xor A                      ;  clear flags
	ld A,(_line_y1)            ;  load point X1
	ld H,A                     ;  copy to H register
	ld A,(_line_y2)            ;  load point X2
	sub H                      ;  subtract point 1 from point 2
	                           ;  ld H,A ; store answer in H

	jp c,negativeDY2            ;  if carry flag is set, then Y2 is smaller
	jp z,negativeDY2            ;  if equal, then set Y2 as negative

	                           ;  fall through if positive, Y2 is larger
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;
positiveDY2:
	ld A,1                     ;  set A to +1
	ld (stepY),A               ;  load into variable
	                           ;  ld A,H
	jp steps_calculation2

negativeDY2:
	ld A,-1                    ;  set A to -1 or $FF
	ld (stepY),A               ;  load into variable
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;

steps_calculation2:	           ;  steps = max(deltaX, deltaY);
	                           ;  deltaX in D deltaY in E
	xor A                      ;  clear flags
	ld A,E                     ;  load in length of X axis
	ld H,A
	ld A,D                     ;  load in length of Y axis
	                           ;  sub h ; subtract point 1 from point 2
	cp H                       ;  compare against deltaX
	jr c,delta_Y_max2           ;  if carry flag is set, then delta_Y is larger

delta_X_max2:
	ld A,D                     ;  now that deltaX is the maximum, load it into A

	jr max_steps2

delta_Y_max2:
	ld A,E                     ;  now that deltaY is the maximum, load it into A

max_steps2:
	ld (steps),A               ;  now we know the maximum pixels that will be used

    ;plot our first point
	;ld A,(_line_x1)
	;ld D,A
	;ld A,(_line_y1)
	;ld E,A
	;ld (_gfx_xy), DE
	;call _hellaPlot

	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;
	                           ;  lets start our loop
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;;;
	jp DXDY_loop2

;ATTENTION
end_bresenham2:	               ;  <----------------- end routine
	ret
;soon to be obsolete

DXDY_loop2:	                    ;
                                ;  if (deltaX > deltaY)
                                ;  deltaX in D      deltaY in E
                                ;  if (deltaX > deltaY)
                                ;  ld A,(deltaX)
	ld H,D                      ;  load deltaX
	ld A,E                      ;  load deltaY
	cp H
	jp nc,delta_Y_larger2
                                ;  otherwise fall through
delta_X_larger2:                ;  if (deltaX > deltaY)
	jp deltaX_case2

	                           ;  else if (deltaY >= deltaX)
delta_Y_larger2:
	jp deltaY_case2

	                           ;  NOW we need to start treating
	                           ;  deltaX and deltaY as 16 bit variables
	                           ;  ;;;;;;;;;;;;;;;;;;;;;;

deltaX_case2:	               ;  if (deltaX > deltaY)

	                           ;  fraction = deltaY - (deltaX >> 1);
	                           ;  deltaX in D       deltaY in E
	ld A,D                     ;  load deltaX into Accumulator
	srl A                      ;  scroll right 1 bit to divide by 2
	ld C,A                     ;  load into low bit of BC
	xor A                      ;  set A to 0 and clear flags
	ld B,A                     ;  clear high bit of BC
	ld H,A                     ;  clear high bit of HL
	ld L,E                     ;  load deltaY into low bit of HL
	scf                        ;  set carry flag
	sbc HL,BC                  ;  deltaY - (deltaX >> 1)
	ld (fraction),HL           ;  store answer
	                           ;  67T   14 bytes

deltaX_loop2:	               ;  for (iterations = 0; iterations <= steps; iterations++)
    ;incrementor
	xor A                      ;  clear flags
	ld A,(iterations)          ; load in iterations
	ld H,A                     ; move to H
	ld A,(steps)               ; load in steps
	cp H                       ;  compare steps with iterations
	;jr z,end_DX2              ;  if no difference, Zero flag is set and we can break out
	ret z
	                           ;  otherwise continue the loop

	                           ;  now plot our point
	ld A,(_line_x1)
	ld B,A
	ld A,(_line_y1)
	ld C,A
	ld (_gfx_xy), BC
	call _hellaPlot2

    ; check to see if fraction is less than 0
    xor A                       ;  clear carry flag
    ld BC,(fraction)            ;  load 16 bit fraction
	ld H, A                     ;  load our compare value 0 high bit HL
	ld L, A                     ;  load our compare value 0 low bit HL
	sbc HL,BC                   ;  compare against 0
	jp p,add_x_fraction2        ;  HL is < 0 Sign flag is Off
    ;57 t   12 bytes

subtract_x_fraction2:	        ;  fraction >= 0

                                ; fraction -= deltaX;
    ld HL,(fraction)    ;  load fraction in HL
    ld C, D             ;  move deltaX into low bit of BC
    xor A               ;  clear flags and A
    ld B, A             ;  set high bit to 0
    sbc HL, BC          ;  fraction – deltaX
    ld (fraction),HL    ;  load answer in fraction
    ;59T
    ;11 bytes

                                ;  y1 += stepY;
	ld A,(_line_y1)	            ; load lineY1
	ld H,A			            ; move to H
	ld A,(stepY)		        ; load stepY
	add A,H                    	; add the two
	ld (_line_y1),A	            ; write the answer
	;47 T
	;11 bytes

	                           ; fraction < 0
add_x_fraction2:
	                           ; x1 += stepx;
	ld A,(_line_x1)            ; load lineX1
	ld H,A                     ; move to H
	ld A,(stepX)               ; load stepX
	add A,H                    ; add the two
	ld (_line_x1),A            ; write the answer

	;  deltaX in D      deltaY in E
    or A                       ; clear our flags
    ld A, E                    ; load in our deltaY
    ld HL,(fraction)           ; load in our fraction 16 bit variable
    add A,L                    ; add the two
	ld L,A                     ; push answer to L
	jr nc,DX_fraction2         ;  if no carry, skip incrementing H
	inc H
DX_fraction2:
	ld (fraction),HL           ; write the Answer
	;106T
	;24 bytes

deltaX_loop_increment:
	                           ;  finally, we increment our loop by 1
	ld A,(steps)               ;  load in steps
	dec A                      ;  decrease staps by 1
	ld (steps),A               ;  rewrite steps

	jp deltaX_loop2             ;  jump back to start of loop

	                           ;  ;;;;;;;;;;;;;;;;;;;;;;

deltaY_case2:	               ;  if (deltaY > deltaX)

	                           ;  fraction = deltaX - (deltaY >> 1);
	                           ;  deltaX in D       deltaY in E
	ld A,E                     ;  load deltaY into Accumulator 4t
	srl A                      ;  scroll right 1 bit to divide by 2 8t
	ld C,A                     ;  load into low bit of BC 4t
	xor A                      ;  set A to 0 and clear flags 4t
	ld B,A                     ;  clear high bit of BC 4t
	ld H,A                     ;  clear high bit of HL 4t
	ld L,D                     ;  load deltaX into low bit of HL 4t
	scf                        ;  set carry flag 4t
	sbc HL,BC                  ;  deltaY - (deltaX >> 1) 15t
	ld (fraction),HL           ;  store answer 16t
	                           ;  67T
	                           ;  14 byte

deltaY_loop2:	               ;  for (iterations = 0; iterations <= steps; iterations++)

    ;incrementor
	xor A                      ;  clear flags
	ld A,(iterations)
	ld H,A
	ld A,(steps)
	cp H                       ;  compare steps with iterations
	ret z                      ;  Line finished
	                           ;  otherwise continue the loop

	                           ;  now plot our point
	ld A,(_line_x1)
	ld B,A
	ld A,(_line_y1)
	ld C,A
	ld (_gfx_xy), BC
	call _hellaPlot2

    xor A                       ;  clear carry flag
    ld BC,(fraction)            ;  load 16 bit fraction
	ld H, A                     ;  load our compare value 0 into H
	ld L, A                     ;  load our compare value 0 into L
	sbc HL,BC                   ;  compare against 0
	jp p,add_y_fraction2        ;  HL is > 0 Sign flag is Off
    ;57 t   12 bytes

subtract_y_fraction2:	       ;  fraction >= 0

	                           ;  fraction -= deltaY;
	                           ;  deltaX in D 		deltaY in E
	ld HL,(fraction)           ; load in our fraction
	xor A
	ld C, E                    ; load deltaY
	ld B, A
	sbc HL, BC                 ; subtract deltaY to get answer
	ld (fraction),HL           ; write answer
	;59T

	                           ;  x1 += stepx;
	ld A,(_line_x1)
	ld H,A
	ld A,(stepX)
	add A,H
	ld (_line_x1),A

	                           ;  fraction < 0
add_y_fraction2:	           ;  add_y_fraction:
	                           ;  y1 += stepY;
	ld A,(_line_y1)
	ld H,A
	ld A,(stepY)
	add A,H
	ld (_line_y1),A

	                           ;  fraction += deltaX;
	                           ;  deltaX in D 		deltaY in E
	or A                       ; clear our flags
	;ld A,(deltaX)
	ld A,D  ;WTF                  ; load in our deltaX
	ld HL,(fraction)
	add A,L
	ld L,A
	jr nc, DY_fraction2        ;  if no carry, skip incrementing H
	inc H
DY_fraction2:
	ld (fraction),HL

	                           ;  finally, we increment our loop by 1
	ld A,(steps)
	dec A
	ld (steps),A

	jp deltaY_loop2


