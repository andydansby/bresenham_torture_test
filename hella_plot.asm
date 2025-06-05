PUBLIC _hellaPlot
_hellaPlot:	              ;  plot d = x-axis, e = y-axis
	                      ;  166 T states per pixel
	ld DE,(_gfx_xy)       ;  load xy pair
	xor A                 ;  reset a to 0 and flags to default

	ld A,E                ;  load X plot point

	rra                   ;  rotate Right ----------- divide in half
	                      ;  this could also be an RRCA
	scf                   ;  set carry flag --------- turn on Carry flag
	rra                   ;  rotate right
	or A
	rra                   ;  rotate right
	                      ;  this could also be an RRCA

	ld L,A                ;  temp store in L
	xor E
	and %11111000         ;  mask out unwanted bits
	xor E

	ld H,A                ;  store High address


	ld A,D                ;  load Y plot point
	xor L
	and %00000111         ;  mask out unwanted bits
	xor D
	rrca                  ;
	rrca                  ;
	rrca                  ;

	ld L,A
	                      ;  now we have the full address
	                      ;  now use LUT to find which bit to set
	ld A,D
	and %00000111 ; mask out unwanted bits

	                      ;  use a LUT to quickly find the bit position for the X position
	ld DE,X_PositionBits
	add A,E
	ld E,A
	ld A,(DE)

	                      ;  output to screen
	or (HL)
	ld (HL),A
ret


PUBLIC _createPixel_variable
_createPixel_variable:
	ld A, (_gfx_x)
	ld H, A
	ld A, (_gfx_y)
	ld L, A
	ld (_gfx_xy), HL
	ret



PUBLIC _hellaPlot2
_hellaPlot2:	                   ;  plot B = x-axis, C = y-axis
	                           ;  166 T states per pixel
	ld BC,(_gfx_xy)            ;  load xy pair
	xor A                      ;  reset a to 0 and flags to default

	ld A,C                     ;  load X plot point

	rra                        ;  rotate Right ----------- divide in half
	                           ;  this could also be an RRCA
	scf                        ;  set carry flag --------- turn on Carry flag
	rra                        ;  rotate right
	or A
	rra                        ;  rotate right
	                           ;  this could also be an RRCA

	ld L,A                     ;  temp store in L
	xor C
	and %11111000              ;  mask out unwanted bits
	xor C

	ld H,A                     ;  store High address


	ld A,B                     ;  load Y plot point
	xor L
	and %00000111              ;  mask out unwanted bits
	xor B
	rrca                       ;
	rrca                       ;
	rrca                       ;

	ld L,A
	                           ;  now we have the full address
	                           ;  now use LUT to find which bit to set
	ld A,B
	and %00000111              ;  mask out unwanted bits

	                           ;  use a LUT to quickly find the bit position for the X position
	ld BC,X_PositionBits
	add A,C
	ld C,A
	ld A,(BC)

	                           ;  output to screen
	or (HL)
	ld (HL),A
	ret













