#!/bin/bash

#delete old files
rm -rf obj/*

date

echo "compile..."

#Bank 3: other values
lcc -Wa-l -Wl-m -Wl-j -Wf-bo3 -c -o obj/values.o values.c

#Bank 2: tilesets and spritesets
lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -c -o obj/font-81-127.o data/tilesets/font-81-127.c
lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -c -o obj/maintiles.o data/tilesets/maintiles_81-0.c
lcc -Wa-l -Wl-m -Wl-j -Wf-bo2 -c -o obj/spriteset.o data/spritesets/spriteset.c

#Bank 0: main
lcc -Wa-l -Wl-m -Wl-j -c -o obj/globals.o globals.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/engine.o engine.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/player.o player.c
lcc -Wa-l -Wl-m -Wl-j -c -o obj/init.o init.c
lcc -Wa-l -Wl-m -Wl-j -Wa-l -Wl-m -Wl-j -c -o obj/graeber2.o graeber2.c

cd obj/

obj=$(ls | grep [.][o])

lcc -Wa-l -Wl-m -Wl-j -Wl-yt0x019 -Wl-yo8 -Wm-yn"graeber2" -o graeber2.gb $obj

cd ..

cp obj/graeber2.gb .

date

exit 0
