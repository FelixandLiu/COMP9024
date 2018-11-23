#!/bin/sh

if test $# -eq 1
then
  program_loc="$1/main"
else
  program_loc="./main"
fi

for file in *.in
do
  file_out=`echo $file | sed -e 's/in$/out/'`
  $program_loc < $file | diff -b $file_out -
  if test $? -eq 1
  then
    echo "Test $file failed"
  else
    echo "Test $file success"
  fi
  
done
