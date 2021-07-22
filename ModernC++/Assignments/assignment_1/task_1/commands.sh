#!/bin/sh

clear

n_lines=`wc -l $1`
echo "Number of lines in $1 is $n_lines"

d_lines=`grep -o '\(dalor\|dolor\)' $1 | wc -l`
echo "Number of lines containing 'dolor' or 'dalor' in $1 is $d_lines"

n_words=`wc -w $1`
echo "Number of words in $1 is $n_words"

mol_count=`grep '^[mol]' $1 | grep e -o | wc -w`
echo "Number of words starting with 'mol' in $1 is $mol_count"