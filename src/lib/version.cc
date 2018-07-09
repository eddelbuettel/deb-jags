#include <version.h>

extern "C" {
    
    const char * jags_version()
    {
	const char * version = "3.4.0";
	return version;
    }

}
