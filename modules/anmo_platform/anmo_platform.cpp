/*
  ==============================================================================

   anmo_platform.cpp
   Author:  indraqubit

  ==============================================================================
*/

#include "anmo_platform.h"

// Unified compilation unit approach (JUCE style)

#if JUCE_WINDOWS
 #include "diagnostics/SystemDiagnostics_Windows.cpp"
#elif JUCE_MAC
 #include "diagnostics/SystemDiagnostics_Mac.mm"
#elif JUCE_LINUX
 #include "diagnostics/SystemDiagnostics_Linux.cpp"
#endif
