#ifndef __PROJECTS_PSE_TRAFFIC_SIM_SRC_LIB_NULBUFFER_H_
#define __PROJECTS_PSE_TRAFFIC_SIM_SRC_LIB_NULBUFFER_H_

#include <iostream>

class NullBuffer : public std::streambuf
{
public:
  int overflow(int c) { return c; }
};

#endif // __PROJECTS_PSE_TRAFFIC_SIM_SRC_LIB_NULBUFFER_H_