/**

    @file libpower.h
    @brief Huvudfil som innehåller deklarationen av funktionerna i libpower-biblioteket.
    @author Sven Rönnbäck
    */

#ifndef LIBPOWER_H
#define LIBPOWER_H

/**

    @brief Beräknar effekten i en resistor baserat på spänning och resistans.
    Denna funktion beräknar effekten (i watt) i en resistor baserat på angiven spänning
    och resistans. Resultatet returneras som en flyttalsvärde.
    @param fVolt Spänningen över resistorn (i volt).
    @param fResistance Resistansen hos resistorn (i ohm).
    @return Effekten (i watt) i resistorn.
    */
float fCalcPowerR(float fVolt, float fResistance);

/**

    @brief Beräknar effekten i en resistor baserat på spänning och ström.
    Denna funktion beräknar effekten (i watt) i en resistor baserat på angiven spänning
    och ström. Resultatet returneras som en flyttalsvärde.
    @param fVolt Spänningen över resistorn (i volt).
    @param fCurrent Strömmen genom resistorn (i ampere).
    @return Effekten (i watt) i resistorn.
    */
float fCalcPowerI(float fVolt, float fCurrent);

#endif // LIBPOWER_H
