#!/bin/sh

gcc main.c ../mutant_split.a -o bintest

./bintest > user_output.txt

diff correct_output.txt user_output.txt
