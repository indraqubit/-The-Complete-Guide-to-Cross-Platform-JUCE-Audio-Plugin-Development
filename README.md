# The Complete Guide to Cross-Platform JUCE Audio Plugin Development

**Navigating the Challenges of Linux, Windows, and macOS Plugin Distribution**

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-sa/4.0/)
[![JUCE Version](https://img.shields.io/badge/JUCE-8.x-orange.svg)](https://juce.com)
[![Platform Linux](https://img.shields.io/badge/Platform-Linux-blue.svg)](https://www.linux.org/)
[![Platform Windows](https://img.shields.io/badge/Platform-Windows-blue.svg)](https://www.microsoft.com/windows)
[![Platform macOS](https://img.shields.io/badge/Platform-macOS-white.svg)](https://www.apple.com/macos)

Author: **indraqubit**  
Last Updated: **January 2026**

## 📖 About This Project

This repository contains the source content for "The Complete Guide to Cross-Platform JUCE Audio Plugin Development". This comprehensive guide addresses the gap between writing audio code and actually shipping a product to users across Linux, Windows, and macOS.

While the JUCE framework handles the audio and GUI abstraction beautifully, the "last mile" of distribution—dependencies, installers, code signing, and notarization—remains a significant hurdle for indie developers. This book documents the solutions, patterns, and pitfalls encountered in real-world production.

## 🚀 Repository Structure

```
├── The-Complete-Guide-to-Cross-Platform-JUCE-Audio-Plugin-Development.md  # Main Ebook File
├── modules/                                                               # Drop-in Source Code
│   └── anmo_platform/                                                     # Cross-Platform Diagnostics Module
├── CHANGELOG.md                                                           # Version History
├── LICENSE                                                                # CC BY-NC-SA 4.0
├── TAGS                                                                   # Search Keywords/Topics
└── README.md                                                              # This file
```

## 🧩 Drop-in Code Module

This repository includes **anmo_platform**, a ready-to-use JUCE module extracted from the book's case study. It handles the gritty details of system diagnostics across Windows, macOS, and Linux.

### Usage

**Option A: Projucer**
1.  Open your `.jucer` project.
2.  Go to **Modules** > **+** > **Add a module from a specified folder...**
3.  Select the `modules/anmo_platform` directory from this repo.

**Option B: CMake**
```cmake
add_subdirectory(path/to/repo/modules/anmo_platform)
target_link_libraries(MyPlugin PRIVATE anmo_platform)
```

## 🛠 Topics Covered

- **Architecture:** designing platform abstraction layers and managing dependencies.
- **Linux:** ALSA/JACK/PulseAudio, X11 vs Wayland, and .deb/.rpm distribution.
- **Windows:** VCRuntime hell, DirectX dependencies, Inno Setup, and signing.
- **macOS:** Hardened Runtime, Entitlements, Notarization, and .pkg creation.
- **CI/CD:** Automating multi-platform builds with GitHub Actions.
- **Licensing:** Implementing JWT-based offline/online validation with OpenSSL.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingChapter`)
3. Commit your Changes (`git commit -m 'Add some AmazingChapter'`)
4. Push to the Branch (`git push origin feature/AmazingChapter`)
5. Open a Pull Request

## 📄 License

This work is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/).

You are free to:
- **Share** — copy and redistribute the material in any medium or format
- **Adapt** — remix, transform, and build upon the material

Under the following terms:
- **Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made.
- **NonCommercial** — You may not use the material for commercial purposes.
- **ShareAlike** — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.
