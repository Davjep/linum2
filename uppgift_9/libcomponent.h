/**

    @file libcomponent.h
    @brief  Huvudfil som innehåller deklarationen av funktionerna i libcomponent-biblioteket.
    @author Sven Rönnbäck
    */

#ifndef LIBCOMPONENT_H
#define LIBCOMPONENT_H

/**

    @brief Hittar E12-serieresistanser närmast det givna ursprungliga resistansvärdet.
    Denna funktion beräknar E12-serieresistanser som är närmast det givna ursprungliga resistansvärdet och
    lagrar dem i den tillhandahållna arrayen. Antalet resistanser att hitta begränsas av det specificerade
    maximala antalet resistanser.
    @param fOrigResistance Det ursprungliga resistansvärdet för vilket de närmaste E12-serieresistanserna ska hittas.
    @param nMaxResistances Det maximala antalet E12-serieresistanser som ska hittas.
    @param pfResArray En pekare till arrayen där de hittade E12-serieresistanserna kommer att lagras.
    @return Det faktiska antalet E12-serieresistanser som hittades och lagrades i den tillhandahållna arrayen.
    */
int nFindE12resistances(float fOrigResistance, int nMaxResistances, float *pfResArray);

#endif // LIBCOMPONENT_H
