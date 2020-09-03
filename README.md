# SID Factory II

SID Factory II is a cross-platform editor for composing music that will work on
a Commodore 64. It uses the reSID emulator and is currently in open BETA.

Main programming by Thomas Egeskov Petersen, with assistance by Jens-Christian
Huus and Michel de Bree.

## Compiling

### Visual Studio on Windows

In order to compile and run SID Factory II in Visual Studio on Windows you need to do this:

- First clone this repository into a folder on your computer. The `sidfactory2` folder is created which you can rename to something else if you want. (We will assume you kept the original name as is below.)
- Create a `libs` folder next to the `sidfactory2` folder
- Download the development library archive of SDL2 for Visual C++ from https://www.libsdl.org
- Extract it into the `libs` folder so you end up with `libs/SDL2-2.0.12` with various files and folders in it
- Download the runtime binary archive of SDL2 for x86 from the same web site
- Extract it and copy the `SDL2.dll` file in it to the `sidfactory2/SidFactoryII` folder

You should now be able to compile and run it when you open the solution file in Visual Studio.

## Changelog

### Build 2020????

#### Editor

- The overlay can now be shown inside the editor with F12 and also changes depending on what driver is loaded
- Added Ctrl + l for setting a song loop position (the orderlist words will turn green in that spot)
- It is now possible to delete a file in all file dialogues by hitting the appropriate key
- A config.ini file has been added where you can set up the audio, colors and key definitions
- Also added a user.ini which is your persistent changes to the default settings of config.ini
- Additional .ini files in a sub folder can be added to create new color schemes
- Seven new color schemes have been created in addition to the default one
- The importer now also carries over auxiliary data (e.g. table descriptions)
- Fixed ".." erroneously interpreted as a file to be opened instead of browsing back
- Fixed tracks not unmuted properly after muting them and then loading a different SF2 file
- Fixed the editor crashing when trying to optimize a song with no sequence data
- Fixed not being able to properly play from a bookmark when showing tracks of uneven lengths
- macOS: Now using Minus and Shift + Minus for fast/faster forward
- macOS: Remapped keys; instrument up/down is now Cmd + up/down while Cmd + up/down is now Shift + Cmd + up/down
- macOS: You can now open .sf2 files with SID Factory II directly from Finder (Open With)

#### Drivers

- Driver update 11.02 adds commands for pulse program index, tempo change, and main volume

#### Converter

- Added a third conversion option for handling .ct source tunes from CheeseCutter
- The SNG and CT converters now support the pulse program index and main volume commands added in driver 11.02
- The MOD, SNG and CT converters now support then tempo change command added in driver 11.02
- Command description labels are now created by the MOD and SNG converters too

#### Documentation

- Expanded the user manual with a table of contents, chapters about the data tables, and various pictures
- The notes.txt file has been overhauled to show a complete list of all default keys for both Windows and macOS
- The text files for all of the drivers have been polished to be easier to read at a glance

#### Other

- The PowerShell script for the bright overlay is now deprecated and will no longer be included
- The area previously known as the "gray orderlist" is now called the "song list" instead

### Build 20200718

- Added a dialog box message for when saving fails
- Added a dialog box message for when selecting a folder fails
- macOS: Fixed crash bug when trying to open a folder you had declined from a system dialog
- macOS: Editor ran without SDL2 being installed; added latest version of SDL2 to the package
- Fixed crashing when trying to display unknown characters (usually in the file menu)
- Fixed note preview using Caps Lock not working
- Fixed note preview sometimes behaving inconsistently
- Fixed left/right "blindness" in user manual

### Build 20200716

- Added description labels in the command and instrument tables
- All drivers have been updated with meta data for the new descriptions capability
- Also updated all the demo songs with command and instrument descriptions
- Updated the converter to copy instrument descriptions from GT2 and MOD files
- Changed hotkey for bit editing in tables to Shift + Enter because of descriptions now using the ENTER key
- Improved the table layout handling to allow for vertically tiled tables
- All tables can now be accessed with an Alt + [letter] hotkey (the letter is highlighted in the table name)
- A separate macOS build has been released for the first time (maintained by Michel de Bree)
- Added the Ctrl + u hotkey for toggling between lower and upper case letters for all hexadecimal values
- You can now drag-and-drop an SF2 source file directly into the editor
- Added exit application confirmation dialog
- All file lists now include a ".." line for browsing back to the parent folder
- Upgraded the ReSID emulation (resid-fp)
- Changed the application caption text (filename now comes first)
- Debug functionality added for examining ReSID output
- Fixed a threading issue that could cause instability in the ReSID emulation
- Fixed inserting/deleting rows in sequences not immediately being reflected in the orderlist overview

### Build 20200610

- Updated fast forward: ½ = 4 x update, Shift + ½ = super fast update
- Added Ctrl + i during sequence editing for inserting the current selected instrument value. If a value is already set, it'll be cleared
- Added Ctrl + o during sequence editing for inserting the current selected  command value. If a value is already set, it'll be cleared
- Added Ctrl + Space during table editing (if keyplay mode is on) - will play like space alone, but apply the current highlighted command, regardless which table is in focus
- In the marker view, ENTER (or mouse click) will move the current track position to that of the marker. Ctrl + Enter (or double click) will do the same and then start playback
- Reversed the direction of the CPU usage graph
- Added commandline parsing, so that it is possible to associate sf2 files with the editor and open view explorer
- Added numpad_plus and numpad_minus for incrementing and decrementing the currently selected index of the instrument table
- Added Ctrl + NumPad_plus and Ctrl + NumPad_minus for incrementing and decrementing the currently selected index of the command table

### Build 20200603

#### Drivers

- Driver 11 (all variants), fixed the meta data for command action keys (jump to relevant tables on Ctrl + Enter)

#### Editor

- Fixed import strings to say import music data, and dialog box to reflect the same too
- Fixed importer assertion when trying to import an empty project (aka. a driver)
- Fixed Ctrl + v (paste) not notifying the orderlist overview
- Editing octave down/up move to F3/F4 - transpose current sequence one semi tone down/up moved to Shift + F3/F4, transpose current sequence one octave down/up moved to Ctrl + F3/F4
- Added fast forward on ½
- Fixed bug: in directory enumeration that would cause a crash when trying to access some system files

### Build 20200528

#### Editor

- Added: Automatic update of build data, which is printed in right bottom of the splash screen
- Added: PNG support
- Added: Embedded logo (temporary)
- Table: Pressing END will set the row of the last occurrence of a zero only row found from the buttom and upwards
- OrderlistOverview: Added Ctrl + Enter to move to and start playing from position
- OrderlistOverview: Mouse click will select and move tracks view to position
- OrderlistOverview: Mouse double click will select and move tracks view to position and start playing from position
- OrderlistOverview: Page up / down implemented (skips 20 lines)
- OrderlistOverview: Home and End - Go to top visible then first index (HOME), go to last visible then last index (END)
- Tracks and orderlist focus: Fixed issue where cursor position would be misaligned when focusing on orderlist entry and pressing Ctrl + g
- Change Shift + F2 to play from the event position of the top current sequence of the track in focus (or last in focus)
- Added "press space" during table edit, to preview last note played through Shift + note value. This will do nothing if not already in "play through input" mode

---

Changes to earlier versions are not available.