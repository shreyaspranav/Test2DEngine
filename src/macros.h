#pragma once

#ifdef _MSC_VER
	#define TRIGGER_BREAKPOINT __debugbreak()
#elif 
	#include <signal.h>
	#define TRIGGER_BREAKPOINT raise(SIGINT)
#endif
#include <stdlib.h>