/**
 * @file libresistance.h
 * @brief Huvudfil som innehåller deklarationen av funktionerna i libresistance-biblioteket.
 * @author Sven Rönnbäck
 */

#ifndef __LIBRESISTANCE_H__
#define __LIBRESISTANCE_H__

/**
 * @brief Beräknar den totala resistansen för en kombination av resistorer.
 *
 * Denna funktion beräknar den totala resistansen för en kombination av resistorer beroende på
 * resistorernas typ, antal och värden. Resultatet returneras som en flyttalsvärde.
 *
 * @param cType     Typen av resistorer (seriekopplade eller parallellkopplade).
 * @param uCount    Antalet resistorer i kombinationen.
 * @param pfArray   En pekare till arrayen som innehåller resistansvärdena.
 *
 * @return Den totala resistansen för kombinationen av resistorer.
 */
float fCalcResistance(char cType, unsigned int uCount, float *pfArray);

#endif // __LIBRESISTANCE_H__
