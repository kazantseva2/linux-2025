#!/bin/sh

TMP=$(mktemp)

trap 'rm -f "$TMP"' EXIT INT TERM

ROW=0
while IFS= read LINE ; do
    COL=0
    echo "$LINE" | fold -w1 | while IFS= read S ; do
        printf "%d %d %s\n" "$ROW" "$COL" "$S" >> "$TMP"
        COL=$((COL+1))
    done
    ROW=$((ROW+1))
done

tput clean
shuf "$TMP" | while read ROW COL S ; do
    tput cup "$ROW" "$COL"
    printf "%s" "$S"
    sleep $1
done

tput cup $((ROW + 1)) 0
