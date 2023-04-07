#!/bin/sh
# Exempelfil, hämtad från webbplats https://www.shellscript.sh/trap.html

tag=catchsignalinscript
trap 'increment' 2

increment()
{
  logger -t $tag -p NOTICE "Caught SIGINT..."
  X=`expr ${X} + 500`
  if [ "${X}" -gt "2000" ]
  then
    logger -t $tag -p alert "Okay, I'll quit..."
    exit 1
  else
    logger -t $tag -p warning "Don't you provoke me..."
  fi
}

### main script
X=0
while :
do
  logger -t $tag -p info "X=$X"
  X=`expr ${X} + 1`
  sleep 1
done
