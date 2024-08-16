#!/bin/bash

NUM_RENDERS=$(find renders -type f | wc -l)
NEW_IMG_NAME=$(($NUM_RENDERS + 1)).png

magick img renders/$NEW_IMG_NAME
