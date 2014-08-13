#pragma once
#define PULSE_DEBUG
#include "includes.hpp"


//class declarations
#include "defs.hpp"

//class headers
#ifdef PULSE_DEBUG
#include "client/test.hpp"
#endif

#include "config/config.hpp"
#include "control/control.hpp"
#include "dataBucket/dataBucket.hpp"
#include "MYSQL_Int/MYSQL_Int.hpp"
#Include "scheduler/scheduler.hpp"
#include "sock_int/sock_int.hpp"




//class definitions
#ifdef PULSE_DEBUG
#include "client/test.cpp"

#endif

#include "config/config.cpp"
#include "control/control.cpp"
#include "dataBucket/dataBucket.cpp"
#include "MYSQL_Int/MYSQL_Int.cpp"
#Include "scheduler/scheduler.cpp"
#include "sock_int/sock_int.cpp"
