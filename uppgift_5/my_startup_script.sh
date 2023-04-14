#!/bin/bash

TEMPFILE=$(mktemp)

date >> "$TEMPFILE"
curl -s 'wttr.in/Luleå' >> "$TEMPFILE"

cat "$TEMPFILE" > /home/davjep/weather.txt

rm "$TEMPFILE"