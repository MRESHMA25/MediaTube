Student Name: Reshma Sri Murakonda
Student Number: 101282055
==================================
Assignment 4
==================================
Project Overview:
This assignment implements a media network system called MediaTube. MediaTube hosts channels that contain media (audio with optional video ASCII art). Users can search for media by owner, category, or both, and then view and play the media using either an audio-only player or an audio+video player. Key components include:

1. Media: Represents a media item with metadata (channel title, owner, media title, category) and content (audio and video file).
2. Channel: A container class that holds media items and channel metadata.
3. MediaTube: The central control class that manages channels and provides search functionality.
4. MediaPlayer: An abstract class for media playback with derived classes AudioPlayer and VideoPlayer.
5. Search: An abstract base class and its derived classes (O_Search, C_Search, OorC_Search) used for filtering media.
6. Array: A custom templated dynamic array class used to store objects (e.g., Channel pointers, Media pointers).
7. View: Handles user interaction (menus, display, and toggling between player types).
8. MediaFactory: Creates Media, Channel, and Search objects as required.
9. Control, TestControl, and Tester: Classes used to manage application flow and run automated tests.

==================================
Files Included:
- Makefile
    → Compiles and links all source files into the executables "a4" and "test".
- README
    → This document.
- main.cc
    → Contains the main() function that launches the application.
- View.h, View.cc
    → Implements the View class for user input, display, and menu handling.
- Control.cc
    → Implements the Control class that coordinates interactions between MediaTube, MediaFactory, and View.
- MediaTube.h, MediaTube.cc
    → Implements the MediaTube class that manages channels and media.
- Channel.h, Channel.cc
    → Implements the Channel class which stores media items and channel metadata.
- Media.h, Media.cc
    → Implements the Media class representing individual media items.
- MediaPlayer.h, MediaPlayer.cc
    → Contains the MediaPlayer abstract class and its derived classes (AudioPlayer and VideoPlayer) for media playback.
- Search.h, Search.cc
    → Implements the Search abstract class and its derived classes (O_Search, C_Search, OorC_Search) for media filtering.
- Array.h
    → Implements the templated Array class used for storing dynamic collections.
- MediaFactory.h, MediaFactory.cc
    → Implements the MediaFactory class that creates Media, Channel, and Search objects.
- TestControl.cc, Tester.cc, test.cc
    → Files for running built-in tests and verifying the functionality of the application.

==================================
Compilation Instructions:
1. Open your terminal and navigate to the assignment directory.
2. Type the command:
       make all
   This compiles all source files and produces two executables: "a4" (the application) and "test" (the test suite).

==================================
Execution Instructions:
- To run the application:
       ./a4
  Follow the on-screen menu options to interact with MediaTube.

- To run the test suite:
       ./test

==================================
Additional Details:
- Memory Management:
  All dynamic memory is managed manually. Channels and Media objects created via MediaFactory are deleted in the destructors of MediaTube and Channel, respectively. Any Search objects created must be deleted by the caller after use.
- Directory Structure:
  Ensure that media files are located in the correct directories (e.g., "media" for media text files and "videos" for video ASCII art files) as expected by the code.
- Player Modes:
  The application supports toggling between an AudioPlayer (audio only) and a VideoPlayer (audio with video ASCII art). Use the "Toggle video" option to switch modes.
- Debugging:
  To check for memory leaks, run:
       valgrind --leak-check=full ./a4
  This helps ensure that all allocated memory is properly freed.

==================================