# MediaTube - C++ Media Sharing Platform

MediaTube is a lightweight C++ application for managing and playing media (audio and video). It allows users to create channels, upload media content, search by owner or category, and play media in either audio-only or audio-video (ASCII art) modes.

## 🚀 Features
- Create and manage multiple channels
- Upload and categorize audio/video media
- Search media by owner, category, or both
- Toggle between audio-only and audio-video playback
- Build and play dynamic playlists from search results

## 🛠️ Technical Highlights
- **Object-Oriented Design:** Inheritance, polymorphism, and encapsulation
- **Templates:** Generic dynamic array structure (without using STL)
- **Design Patterns:** Factory Pattern (object creation), Strategy Pattern (runtime behavior switching)
- **Operator Overloading:** `<<`, `[]`, `+=`, and `-=`
- **Manual Memory Management:** Raw pointers with explicit resource handling
- **Exception Handling:** Defensive error checking and program stability

## Project Structure

MediaTube/

  headers/      # Header files (.h)
  sources/      # Source files (.cc)
  media/        # ASCII art for video playback
  Makefile      # Build configuration
  README.md     # Project documentation
  main.cc       # Main application
  test.cc       # Test suite

## Build & Run
1. Navigate to the project directory and build the project:
   make
2. Run the main application:
   ./a4
3. Run tests:
   ./test

## Notes
- All dynamic memory is managed manually (no smart pointers).
- Project verified with Valgrind for memory safety.

This program was created by @MRESHMA25.
