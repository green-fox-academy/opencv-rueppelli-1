# :warning:  :traffic_light:  :red_car:  === OpenCV - 1 - Rueppellii ===  :red_car:  :traffic_light:  :warning:
> made by Gergo Barta, Gabor Fodor and Fruzsina Vegh

## OUR MISSION  :oncoming_automobile: :camera: :computer:  :recycle:
The purpose of the team is to help computers to understand the world as we see it. More precisely we are going to
process pictures and videos from car Dash Cams and transport situations and try to make decisions based on that.
These camera systems slowly but surely are getting a huge part in nowadays automobile industry (because only one
camera can replace numerous sensors), this is why we are focusing only on transporting.
For that we are going to use OpenCV to process the camera input with C++.

On this week:
Now we are building the framework of our project and getting acquainted with the opencv's mystery.

## Table of contents
- [OUR MISSION](#our-mission)
- [BUILD STATUS](#build-status)
- [TECHNOLOGIES](#technologies)
- [THE PROJECT ITSELF](#the-project-itself)
- [TESTS](#tests)
- [REQUIREMENTS](#requirements)
- [INSTALLATION AND SETUP](#installation-and-setup)
- [HOW TO USE?](#how-to-use)
- [YOU HAVE TROUBLES?](#you-have-troubles)
- [LICENSE](#license)

## BUILD STATUS
 - [ ] Reading different inputs for processing [in progress]
 - [ ] Applying filters and operations to pictures and videos [in progress]
 - [ ] Object detection
 - [ ] Text detection and character recognition
 - [ ] Traffic control police pose detection
 - [ ] Creating a driver helping HUD
 - [ ] Storing the usage in a database and use it to create metrics and statistics

## TECHNOLOGIES
Project is created with:
* __C++14__
* __SQLite3__
* __OpenCV library__
* __OpenPose__
* __Google Test__

## THE PROJECT ITSELF
 - pictures...
> coming soon...

 - [function database] ( link ahol van a functions.md )
> coming soon...

## TESTS


## REQUIREMENTS



## INSTALLATION AND SETUP
 Things you will need:
 
 - [Jetbrains CLion](https://www.jetbrains.com/clion/)
 - [MinGW-w64](https://drive.google.com/open?id=1tNNNxxlnYyeeiGAozp307DbwI1kel2AQ)
 - [CMake](https://github.com/Kitware/CMake/releases/download/v3.14.0-rc1/cmake-3.14.0-rc1-win64-x64.msi)
 - [OpenCV 4.0.1](https://github.com/opencv/opencv/archive/4.0.1.zip)
 - [SQLite3](https://drive.google.com/open?id=1fUCQl_v66Zl4Wb51pFHGSVmeZyfMp83z)
 - [Google Test](https://github.com/green-fox-academy/teaching-materials/blob/master/workshop/testing/env-setup/cpp/resource/googletest.zip)
 
Building OpenCV with CMake:
 - Download the Mingw-w64 linked above. It may or may not work with other version.
 - Extract the file and set the ./x86_64-8.1.0-posix-sjlj-rt_v6-rev0/mingw64/bin directory in the 
 PATH environment variable. (You might need to restart your machine)
 - Extract the OpenCV archive
 - Open CMake
 - Tick grouped and advanced for clarity afterwards
 - Press the browse source button and locate the extracted OpenCV folder
 - Press the browse build button and set the location you want to build to
 - Press configure and if asked, use native compiler,
 - After half an eternity, you're greeted by a bunch of red text
 - Now is the important part: In Build, look for built type and set it to 'Release'. In Enable, untick precompiled headers.
 In With, untick MSMF and IPP.
 - Click configure again
 - Now, everything should be white. You can click on generte now.
 - Open CMD and navigate to the build directory you generated
 - type 'mingw32-make' and press enter
 - Go and take a shower, cook dinner, go for a run, it will take a while
 - No, it's not done yet
 - Not yet
 - ...
 - Okay, let's pretend it's done(probably it's not)
 - In CMD, type 'mingw32-make install'
 - Now, in the OpenCV build folder, locate ./install/x64/mingw/lib and set it as an environment variable called OPENCV_DIR
 - Now, for SQLite3, extract the downloaded file
 - We're going to build this with CMake too, in CMake, click browse source and locate the SQLite3 folder
 - Browse build can be whatever
 - Configure, configure, generate
 - Navigate to the SQLite3 build folder with CMD (you might need to run it as administrator)
 - type mingw32-make and when it finished, mingw32-make install(if it fails, you need to run CMD as administrator)
 - SQLite3 install in Program Files (x86) by default
 - Locate the ./sqlite3/lib/cmake folder and set it as an environment variable called SQLITE3_DIR
 - Locate the ./sqlite3/include folder and set it as an environment variable called SQlite3_inc
 - Extract the contents of the linked googletest archive
 - Locate the googletest folder and set it as an environment variable called PATH_TO_GOOGLETEST
 - In CLion, go to Settings -> Build, Execution, Deployment -> Toolchains
 - At the environment field, locate the mingw-w64 you built OpenCV and SQLite3 with
 - Fork and clone the repository
 - Open the project folder in CLion with File -> Import Project and then click on Open existing CMake project
 - CLion should generate a folder in the projet root, called cmake-build-debug
 - In your OpenCV install directory, locate ./install/x64/mingw/bin
 - Copy all the DLL files to the cmake-build-debug folder and the gtest folder found in cmake-build-debug
 - Enjoy...

## HOW TO USE?



## YOU HAVE TROUBLES?



## LICENSE
Copyright 2019 © .OCV-R3.
