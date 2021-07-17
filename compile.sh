#https://github.com/gbdk-2020/gbdk-2020/releases/download/4.0.4/gbdk-linux64.tar.gz


#!/bin/bash

#delete old files

rm -rf obj
mkdir obj

date

echo "compile..."

#BANK7: Text routines and text data
lcc -Wa-l -Wl-m -Wl-j -Wf-bo7 -c -o obj/text.o text.c
lcc -Wa-l -Wl-m -Wl-j -Wf-bo7 -c -o obj/shieldtxt.o data/text/shields/shieldtxt.c

#BANK6
lcc -Wa-l -Wl-m -Wl-j -Wf-bo6 -c -o obj/environment.o environment.c 

#BANK5: level data
lcc -Wa-l -Wl-m -Wl-j -Wf-bo5 -c -o obj/lvldatmine-entrance.o data/level/lvldatmine-entrance.c

#Bank 4: other values
lcc -Wa-l -Wl-m -Wl-j -Wf-bo4 -c -o obj/values.o values.c

#Bank3: Level mine entrance
lcc -Wa-l -Wl-m -Wl-j -Wf-bo3 -c -o obj/mine-entrance.o mine-entrance.c

#Bank 2: tilesets and spritesets
lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -c -o obj/font-79-127.o data/tilesets/font-79-127.c
lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -c -o obj/maintiles.o data/tilesets/maintiles_77-0.c
lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -c -o obj/spriteset.o data/spritesets/spriteset.c

#Bank 0: main
lcc -Wa-l -Wl-m -Wl-j -c -o obj/globals.o globals.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/engine.o engine.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/hud.o hud.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/player.o player.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/lvlstatus.o lvlstatus.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/init.o init.c
lcc -Wa-l -Wl-m -Wl-j -Wa-l -Wl-m -Wl-j -c -o obj/graeber2.o graeber2.c

cd obj/

obj=$(ls | grep [.][o])

lcc -Wa-l -Wl-m -Wl-j -Wl-yt0x019 -Wl-yo8 -Wm-yn"graeber2" -o graeber2.gb $obj

cd ..

cp obj/graeber2.gb .

#https://github.com/bbbbbr/romusage
romusage obj/graeber2.noi

date

exit 0
