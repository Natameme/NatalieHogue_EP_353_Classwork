# St Maximillian's Organ Indev
## how to Run

###Step 1

Set your console directory to Final/Source/

###Step 2a

Make sure your midi controller is plugged in before opening the program

###Step 2b

The line to compile each program is at the top of each C file, following the rough structure

    `clang Filename.c -o Filename -lportaudio -lportmidi && ./Filename`

The code will run through and midi setting, ideally it should return without an error, however in the event that you get an "invalid device ID" error,

    - Look through the list of audio and midi device and take the respective ID numbers for your desired devices

    - go into OrganSecondBuild.c and in the Constants Section (line 14) reinstantiate "kAudioDeviceOutputIndex" and "kMIDIInputDeviceID" with the correct numbers corresponding to the device you wish to user

###Step 3

    - Once you compile and run the code with no error you should be good to start making sound! hit a note on your keyboard and try it out.

    - Polyphony and the ability to pull in and out stops are coming in a later version. For now the (admittedly janky) method of pulling in and out stops is to comment out the stops you don't want at line 364.


### Notes

  this indev folder contains in development models. the current effort is to rebuild the architecture as a single-cycle sampler, allowing the computational process of adding sine waves to not run in real time, freeing up valuable processing space

  PolySineWorking is a base synthesis template that plays back a simple sine wave polyphonically.

  CycleSampler is an architecture intended to load each stop as a single cycle sample (stored in indev/waves/) to free up computational space, however as of yet the file loading architecture has hit a wall and needs to be rebuilt

  additionally, a reverb model needs to be added to the system, but that is still impractical as long as the synthesis engine is as computationally expensive as it is
