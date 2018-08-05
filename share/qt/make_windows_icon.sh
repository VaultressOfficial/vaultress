#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/vaultress.png
ICON_DST=../../src/qt/res/icons/vaultress.ico
convert ${ICON_SRC} -resize 16x16 vaultress-16.png
convert ${ICON_SRC} -resize 32x32 vaultress-32.png
convert ${ICON_SRC} -resize 48x48 vaultress-48.png
convert vaultress-48.png vaultress-32.png vaultress-16.png ${ICON_DST}

