# i8080_Emulator

CS 467 Capstone project

A i8080 Emulation written in C++ which includes the necessary functionality to run space invaders. 

A compiled executable will be released with the project. The project may be run from the included VS file on windows but SDL must be seperately installed.


1. Basic Setup (Windows 10)
  A. Make sure Microsoft Visual C++ Redistributable is installed on the machine. 
    a. https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0
  B. Open the i8080Emulator.exe file*
    b. NOTE: The program will ask the user for administrative privileges.
  C. Specify the directory where you would like to instal the program.
  D. The program will install, click close and the setup is complete.
  E. There will be a program shortcut found on the desktop.
  
2.Uninstalling the program (Windows 10)
  A. Select Start , then select Settings  > Apps > Apps & features. 
  B. Select the i8080Emulator, and then select Uninstall.
  C. The program will uninstall. 
    a. The uninstall.exe is also provided. It is found in the directory of the installation. 
3. Portable Setup
  A. Make sure Microsoft Visual C++ Redistributable is installed. 
    a. https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0
  B. Unarchive the exe with an unarchiving tool such as 7zip or winrar. 
    b. https://www.7-zip.org
  C. Run the i8080 Emulator
4. Compiling and Environment setup (for Visual Studio in Windows)
  A. Download the Visual C++ development libraries SDL2.
    a. https://www.libsdl.org/download-2.0.php
    b. Note** to download it for Visual Studio if using Windows 
  B. Download the Visual C++ development libraries SDL2 Mixer
    a. https://www.libsdl.org/projects/SDL_mixer/
  C. Note to download it for Visual Studio if using Windows 
  D. Download the code for the program from Github Repository
    a. https://github.com/woym97/i8080_Emulator
    b. The following is the original repository we used and is included in case the reader would like to see how the project progressed. 
    c. https://github.com/sanduler/CS467-Space-Invaders-Emulator
  E. Create a “SDL” Folder on the root of OS drive
    a. Tutorial belows assumes that an SDL folder is on C drive and all contents are inside the folder.
  F. Add all the files downloaded from SDL2 and SDL2 Mixer into it
  G. Merge folders so all files correspond to the file structure
  H. Tell Visual C++ to search for header files in the SDL extension include folder we just extracted. Under Configuration Properties in the VC++ Directories menu, select the Include Directories field, click the tiny down arrow button, and click edit.
  I. Click the folder icon, and then click the button that pops up.
  J. Now go find the SDL_image (or SDL_ttf/SDL_mixer) folders you extracted, and select the include folder and click OK.
Visual Studio knows where to find the header files. If you get an error that the compiler can't find SDL_image.h (or SDL_ttf.h/SDL_mixer.h), it means you messed up this step.
    a. Alternatively you can paste “C:\SDL\SDL2\include;$(IncludePath)”
  K. Repeat steps f - h for the “Library Directory” 
  L. Find the lib folder you extracted, and select the lib folder where you find two folders. There's one for 32bit x86 architecture and for 64bit x64 architecture.
For this project use x64 as it uses 64 bit architecture. 
    a. Alternatively you can paste “C:\SDL\SDL2\lib\x64;$(LibraryPath)”
  M. In “C/C++” in “Additional Include Directories” 
    A. Paste C:\SDL\SDL2\include;%(AdditionalIncludeDirectories)
  N. In order to compile SDL code, we will have to specify and tell Visual C++ to link against the libraries. In the Linker Input menu, edit the additional dependencies.
  O. In “Additional Library Dependencies”
    a. C:\SDL\SDL2\lib\x64;%(AdditionalLibraryDirectories)
  P. Press “OK” then Compile the program.
