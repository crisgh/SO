#!/bin/sh
dirs=$*
if test $# -eq 0;then
  echo usage: $0 Error, no directorios
  exit 1

else

  #export dirs

fi



# /usr/include .. dentro de un comentario puede haber include pero no se tiene que mostrar
# egrep -n '#include[^<]\.[c|h|cpp]$'
ls /usr/include *.chcpp| egrep '.[chcpp]$'| sort -k1,3
