#!/usr/bin/python3

#Author: David Jepsson 920125-5271

import sys
import os

#Loopar igenom alla argument som har getts
for arg in sys.argv[1:]:
    #Testar att loopa igenom alla filer i sökvägen som getts. Går till except ifall arg inte är en sökväg.
    try:
        for filename in os.listdir(arg):
            #Kollar ifall filen slutar på .txt. Skriver ut de 2 första raderna ifall det är de
            if os.path.splitext(filename)[1] == ".txt":
                print(filename + ":")
                with open(filename, 'r') as read:
                    print(read.readline())
                    print(read.readline())
            else:
                print(filename + " är ingen .txt fil")
    except Exception as e:
        #Skriver ut error meddelande och går vidare till nästa argument
        print(f"Error: {e}: " + arg + " är inte en sökväg. Går vidare till nästa...")
        