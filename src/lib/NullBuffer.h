/*
 * Project: PSE Traffic Simulator
 * Author: Flor Ronsmans De Vry (flor.ronsmansdevry@student.uantwerpen.be), Achraf Yandouzi (achraf.yandouzi@student.uantwerpen.be)
 * Description: 
 * Version: 1.0
 * License: Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International (CC BY-NC-ND 4.0)
 * -----
 * File Created: Tuesday, 26th April 2022 7:55:34 pm
 */

#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_LIB_NULBUFFER_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_LIB_NULBUFFER_H_

#include <iostream>

class NullBuffer : public std::streambuf
{
public:
  int overflow(int c) { return c; }
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_LIB_NULBUFFER_H_