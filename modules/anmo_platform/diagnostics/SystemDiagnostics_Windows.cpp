#include <windows.h>

namespace anmo
{

SystemDiagnostics::SystemInfo SystemDiagnostics::getSystemInfo()
{
    SystemInfo info;
    info.osName = "Windows";
    info.architecture = "x64"; // Assuming 64-bit build for modern plugins

    // Getting exact Windows version via Registry (as per Chapter 5.5)
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, 
        "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 
        0, KEY_READ, &hKey) == ERROR_SUCCESS) 
    {
        char value[255];
        DWORD bufferSize = 255;
        if (RegQueryValueExA(hKey, "DisplayVersion", nullptr, nullptr, 
            reinterpret_cast<LPBYTE>(&value), &bufferSize) == ERROR_SUCCESS) 
        {
            info.osVersion = value; // e.g., "22H2"
        }
        else
        {
             // Fallback for older versions
            if (RegQueryValueExA(hKey, "ReleaseId", nullptr, nullptr, 
                reinterpret_cast<LPBYTE>(&value), &bufferSize) == ERROR_SUCCESS)
            {
                info.osVersion = value;
            }
        }
        RegCloseKey(hKey);
    }
    else 
    {
        info.osVersion = "Unknown";
    }
    
    // Check for running via RDP
    if (GetSystemMetrics(SM_REMOTESESSION))
        info.graphicsAPI = "RDP (Software Rendering)";
    else
        info.graphicsAPI = "Local Display";

    return info;
}

} // namespace anmo
