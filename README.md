# ARM A9 Stopwatch 

# Note 
This repository contains 'ELEC5620M-Resouces' folder that provides the sample code and the DebugConfig files that are needed to configure and run the code. This folder was provided by the University of Leeds. '.project and.cproject files and .c and .h files are located in the ARM-A9 Stopwatch Folder'. 


# INTRODUCTION
In this project, the task to implement a stopwatch using the ARM A9 Private timer. To achieve this 7 different source files were made. This 

# Watchdog Timer
A file was created to initialise the watchdog timer and use it to reset the system to it's initial state.

# Seven-Segment driver
Two files were created that were used tot initialise the seven-segment display of the DE1-SoC kit. These driver codes were called in the main function to execute them.

# ARM A9 Private Timer Initialisation
Two files ptimer.c and ptimer.h were created to configure the private timer.

# Initialising key and variables
Two files, source and header, ini.c and ini.h were created to initialise the keypresses and the variables used for governin the code flow and to display it in the MM:SS:FF format.

# Main.c
This is the last file that needed to be created in order to execute the program, all the header and source files and it executes all the defined functions by calling them sequentially.



# OUTPUT

MM:SS:FF
![20220321_003253](https://user-images.githubusercontent.com/99490543/159275445-c1d12c1e-c2ca-45b4-910d-e206b895c010.jpg)

HH:MM:SS
![20220321_124741](https://user-images.githubusercontent.com/99490543/159275573-5a02cc34-0c0c-410f-8fec-10b6f4ec202e.jpg)

Reset and Initial Conditions
![20220321_002954](https://user-images.githubusercontent.com/99490543/159275718-68ddf871-9386-4239-9a92-fe6a6110916e.jpg)




