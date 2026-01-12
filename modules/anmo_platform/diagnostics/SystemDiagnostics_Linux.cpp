#include <sys/utsname.h>
#include <fstream>

namespace anmo
{

SystemDiagnostics::SystemInfo SystemDiagnostics::getSystemInfo()
{
    SystemInfo info;
    info.osName = "Linux";
    
    // Get Kernel Info
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        info.osVersion = buffer.release; // e.g., "5.15.0-generic"
        info.architecture = buffer.machine; // "x86_64"
    }

    // Get Distro Info (Standard way)
    std::ifstream osRelease("/etc/os-release");
    std::string line;
    while (std::getline(osRelease, line)) {
        if (line.find("PRETTY_NAME=") == 0) {
             // Remove quotes and prefix
             auto rawName = line.substr(12); 
             if (rawName.front() == '"') rawName.erase(0, 1);
             if (rawName.back() == '"') rawName.pop_back();
             
             info.osName = juce::String(rawName); 
        }
    }
    
    // Check Graphics (X11 vs Wayland)
    const char* sessionType = std::getenv("XDG_SESSION_TYPE");
    info.graphicsAPI = (sessionType != nullptr) ? sessionType : "unknown";

    return info;
}

} // namespace anmo
