SET PATH=c:\z88dk;c:\z88dk\bin;c:\z88dk\lib\;c:\z88dk\lib\clibs;c:\z88dk\lib\config

rem SET PATH=c:\z88dk203;c:\z88dk203\bin;c:\z88dk203\lib\;c:\z88dk203\lib\clibs;c:\z88dk203\lib\config;C:\Program Files\SDCC\bin;C:\Program Files\GnuWin32\bin

rem del "1Lissajous.tap"
cls

@rem zcc +zx -lp3 -lm -create-app -bn sin main.c

@rem zcc +zx -vn -SO3 -m -lm -clib=new main.c -o 1Lissajous -startup=9 -create-app

@rem zcc +zx -vn -m -lm -clib=sdcc_iy -c -o uncontended.o  @ramMain.lst

@rem zcc +zx -vn -m -startup=1 -clib=sdcc_iy -lm ramALL.o -o compiled -pragma-include:zpragma.inc

@rem zcc +zx -vn -m -startup=1 -clib=sdcc_iy -lm uncontended.o -o compiled -pragma-include:zpragma.inc

@rem z88dk-z80nm uncontended.o
@rem z88dk-z80nm uncontended.o > uncontended.txt


@rem z88dk-z80asm -v uncontended.o -o=ramALL.o
@rem z88dk-z80asm -v -o=ramALL.o uncontended.o

del "1output.tap"

zcc +zx -vn -SO3 -m --math32 -clib=new @ramMain.lst -o 1output -startup=9 -create-app


cd utils
    copy "bas2tap.exe" ".."
    copy "loader.bas" ".."
cd ..

@rem z88dk-appmake +zx -b compiled_CODE.bin -o uncontended.tap --org 32768 --noloader --blockname uncontended

@rem bas2tap -a1 -sprogram loader.bas basloader.tap




@rem copy /b basloader.tap+uncontended.tap   1output.tap


call beep.bat


