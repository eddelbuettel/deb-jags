#include <version.h>

extern "C" {
    
    const char * jags_version()
    {
	const char * version = "3.1.0";
	return version;
    }

}
