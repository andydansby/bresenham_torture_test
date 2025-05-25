SECTION code_user


include "hella_plot.asm"
include "bresenham_line1.asm"


PUBLIC X_PositionBits
X_PositionBits: defb 128,64,32,16,8,4,2,1

PUBLIC _gfx_xy
_gfx_xy:    defw 0

PUBLIC _gfx_x
_gfx_x:    defb 0

PUBLIC _gfx_y
_gfx_y:    defb 0





