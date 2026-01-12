if(COMMAND juce_add_module)
    juce_add_module(anmo_platform
        SOURCES
            anmo_platform.h
            anmo_platform.cpp
            diagnostics/SystemDiagnostics.h
            diagnostics/SystemDiagnostics_Windows.cpp
            diagnostics/SystemDiagnostics_Mac.mm
            diagnostics/SystemDiagnostics_Linux.cpp
    )
else()
    message(STATUS "Note: anmo_platform module found, but not added via juce_add_module (likely running via Projucer)")
endif()
