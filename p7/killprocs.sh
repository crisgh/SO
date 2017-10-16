#!/bin/sh
if test $# -eq 0;then
  echo usage: $0 -n arg1 arg2...argN or pid1 pid2.. pidN
  exit 1
fi
if test $1 = "-n" ;then
  shift
  for var in "$@"
  do
    kill -9 $(ps -e|egrep ^$var$| awk '{print $1}')
  done
  exit
fi


for var in "$@"
do
    kill -9 $var
done
