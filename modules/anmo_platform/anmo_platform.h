/*
  ==============================================================================

   anmo_platform.h
   Author:  indraqubit

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this module, and is read by
 the Projucer to automatically generate project code that uses it.
 For details, see the Juce Library Code header.

 BEGIN_JUCE_MODULE_DECLARATION

  ID:               anmo_platform
  vendor:           indraqubit
  version:          1.0.0
  name:             ANMO Platform Helpers
  description:      Cross-platform system diagnostics and utilities for JUCE.
  website:          https://github.com/indraqubit
  license:          MIT

  dependencies:     juce_core

 END_JUCE_MODULE_DECLARATION
*******************************************************************************/

#pragma once

#if ! defined (JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED)
 /*
   This is the usual include that defines the JUCE_WINDOWS/JUCE_MAC/etc macros
   so that this module knows what platform it is on.
 */
 #include <juce_core/juce_core.h>
#endif

namespace anmo
{
    // Namespace for the library
}

#include "diagnostics/SystemDiagnostics.h"
