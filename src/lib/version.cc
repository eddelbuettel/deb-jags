#include <version.h>

extern "C" {
    
    const char * jags_version()
    {
	const char * version = "5.0.0";
	return version;
    }

}
