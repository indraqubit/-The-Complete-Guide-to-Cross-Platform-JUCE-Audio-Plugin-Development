#pragma once

namespace anmo
{

class SystemDiagnostics
{
public:
    struct SystemInfo
    {
        juce::String osName;
        juce::String osVersion;
        juce::String architecture;
        juce::String graphicsAPI;
    };

    /** Returns platform-specific system information details used for debugging logs. */
    static SystemInfo getSystemInfo();
};

} // namespace anmo
