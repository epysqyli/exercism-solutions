#!/usr/bin/env bash

main() {
  res=""

  if [ $(($1 % 3)) -eq 0 ]; then
    res+="Pling"
  fi

  if [ $(($1 % 5)) -eq 0 ]; then
    res+="Plang"
  fi

  if [ $(($1 % 7)) -eq 0 ]; then
    res+="Plong"
  fi

  [ -z "$res" ] && echo "$1" && exit 0

  echo "$res"
}

main $@
