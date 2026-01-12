#include <sys/sysctl.h>
#import <Foundation/Foundation.h>

namespace anmo
{

SystemDiagnostics::SystemInfo SystemDiagnostics::getSystemInfo()
{
    SystemInfo info;
    info.osName = "macOS";
    
    // Get OS Version
    NSOperatingSystemVersion version = [[NSProcessInfo processInfo] operatingSystemVersion];
    info.osVersion = juce::String::formatted("%d.%d.%d", 
        (int)version.majorVersion, (int)version.minorVersion, (int)version.patchVersion);
        
    // Check Rosetta vs Native
    int ret = 0;
    size_t size = sizeof(ret);
    if (sysctlbyname("sysctl.proc_translated", &ret, &size, NULL, 0) != -1) {
        if (ret == 1) info.architecture = "x86_64 (Rosetta)";
        else          info.architecture = "Native (ARM64/Intel)";
    }
    else
    {
        info.architecture = "Native";
    }
    
    return info;
}

} // namespace anmo
