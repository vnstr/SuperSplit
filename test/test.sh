#!/bin/sh

gcc main.c ../super_split.a -o bintest

./bintest > user_output.txt

diff correct_output.txt user_output.txt
