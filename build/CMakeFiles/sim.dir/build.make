# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/electricwiz/richAMS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/electricwiz/richAMS/build

# Include any dependencies generated for this target.
include CMakeFiles/sim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim.dir/flags.make

CMakeFiles/sim.dir/source/Sim.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/Sim.cc.o: /home/electricwiz/richAMS/source/Sim.cc
CMakeFiles/sim.dir/source/Sim.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim.dir/source/Sim.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/Sim.cc.o -MF CMakeFiles/sim.dir/source/Sim.cc.o.d -o CMakeFiles/sim.dir/source/Sim.cc.o -c /home/electricwiz/richAMS/source/Sim.cc

CMakeFiles/sim.dir/source/Sim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/Sim.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/Sim.cc > CMakeFiles/sim.dir/source/Sim.cc.i

CMakeFiles/sim.dir/source/Sim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/Sim.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/Sim.cc -o CMakeFiles/sim.dir/source/Sim.cc.s

CMakeFiles/sim.dir/source/Action.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/Action.cc.o: /home/electricwiz/richAMS/source/Action.cc
CMakeFiles/sim.dir/source/Action.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sim.dir/source/Action.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/Action.cc.o -MF CMakeFiles/sim.dir/source/Action.cc.o.d -o CMakeFiles/sim.dir/source/Action.cc.o -c /home/electricwiz/richAMS/source/Action.cc

CMakeFiles/sim.dir/source/Action.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/Action.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/Action.cc > CMakeFiles/sim.dir/source/Action.cc.i

CMakeFiles/sim.dir/source/Action.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/Action.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/Action.cc -o CMakeFiles/sim.dir/source/Action.cc.s

CMakeFiles/sim.dir/source/AeroRadiator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/AeroRadiator.cc.o: /home/electricwiz/richAMS/source/AeroRadiator.cc
CMakeFiles/sim.dir/source/AeroRadiator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sim.dir/source/AeroRadiator.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/AeroRadiator.cc.o -MF CMakeFiles/sim.dir/source/AeroRadiator.cc.o.d -o CMakeFiles/sim.dir/source/AeroRadiator.cc.o -c /home/electricwiz/richAMS/source/AeroRadiator.cc

CMakeFiles/sim.dir/source/AeroRadiator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/AeroRadiator.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/AeroRadiator.cc > CMakeFiles/sim.dir/source/AeroRadiator.cc.i

CMakeFiles/sim.dir/source/AeroRadiator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/AeroRadiator.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/AeroRadiator.cc -o CMakeFiles/sim.dir/source/AeroRadiator.cc.s

CMakeFiles/sim.dir/source/Construction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/Construction.cc.o: /home/electricwiz/richAMS/source/Construction.cc
CMakeFiles/sim.dir/source/Construction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sim.dir/source/Construction.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/Construction.cc.o -MF CMakeFiles/sim.dir/source/Construction.cc.o.d -o CMakeFiles/sim.dir/source/Construction.cc.o -c /home/electricwiz/richAMS/source/Construction.cc

CMakeFiles/sim.dir/source/Construction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/Construction.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/Construction.cc > CMakeFiles/sim.dir/source/Construction.cc.i

CMakeFiles/sim.dir/source/Construction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/Construction.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/Construction.cc -o CMakeFiles/sim.dir/source/Construction.cc.s

CMakeFiles/sim.dir/source/Detector.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/Detector.cc.o: /home/electricwiz/richAMS/source/Detector.cc
CMakeFiles/sim.dir/source/Detector.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sim.dir/source/Detector.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/Detector.cc.o -MF CMakeFiles/sim.dir/source/Detector.cc.o.d -o CMakeFiles/sim.dir/source/Detector.cc.o -c /home/electricwiz/richAMS/source/Detector.cc

CMakeFiles/sim.dir/source/Detector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/Detector.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/Detector.cc > CMakeFiles/sim.dir/source/Detector.cc.i

CMakeFiles/sim.dir/source/Detector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/Detector.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/Detector.cc -o CMakeFiles/sim.dir/source/Detector.cc.s

CMakeFiles/sim.dir/source/EventAction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/EventAction.cc.o: /home/electricwiz/richAMS/source/EventAction.cc
CMakeFiles/sim.dir/source/EventAction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sim.dir/source/EventAction.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/EventAction.cc.o -MF CMakeFiles/sim.dir/source/EventAction.cc.o.d -o CMakeFiles/sim.dir/source/EventAction.cc.o -c /home/electricwiz/richAMS/source/EventAction.cc

CMakeFiles/sim.dir/source/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/EventAction.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/EventAction.cc > CMakeFiles/sim.dir/source/EventAction.cc.i

CMakeFiles/sim.dir/source/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/EventAction.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/EventAction.cc -o CMakeFiles/sim.dir/source/EventAction.cc.s

CMakeFiles/sim.dir/source/Generator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/Generator.cc.o: /home/electricwiz/richAMS/source/Generator.cc
CMakeFiles/sim.dir/source/Generator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sim.dir/source/Generator.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/Generator.cc.o -MF CMakeFiles/sim.dir/source/Generator.cc.o.d -o CMakeFiles/sim.dir/source/Generator.cc.o -c /home/electricwiz/richAMS/source/Generator.cc

CMakeFiles/sim.dir/source/Generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/Generator.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/Generator.cc > CMakeFiles/sim.dir/source/Generator.cc.i

CMakeFiles/sim.dir/source/Generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/Generator.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/Generator.cc -o CMakeFiles/sim.dir/source/Generator.cc.s

CMakeFiles/sim.dir/source/NaFRadiator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/NaFRadiator.cc.o: /home/electricwiz/richAMS/source/NaFRadiator.cc
CMakeFiles/sim.dir/source/NaFRadiator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sim.dir/source/NaFRadiator.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/NaFRadiator.cc.o -MF CMakeFiles/sim.dir/source/NaFRadiator.cc.o.d -o CMakeFiles/sim.dir/source/NaFRadiator.cc.o -c /home/electricwiz/richAMS/source/NaFRadiator.cc

CMakeFiles/sim.dir/source/NaFRadiator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/NaFRadiator.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/NaFRadiator.cc > CMakeFiles/sim.dir/source/NaFRadiator.cc.i

CMakeFiles/sim.dir/source/NaFRadiator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/NaFRadiator.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/NaFRadiator.cc -o CMakeFiles/sim.dir/source/NaFRadiator.cc.s

CMakeFiles/sim.dir/source/Run.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/Run.cc.o: /home/electricwiz/richAMS/source/Run.cc
CMakeFiles/sim.dir/source/Run.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sim.dir/source/Run.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/Run.cc.o -MF CMakeFiles/sim.dir/source/Run.cc.o.d -o CMakeFiles/sim.dir/source/Run.cc.o -c /home/electricwiz/richAMS/source/Run.cc

CMakeFiles/sim.dir/source/Run.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/Run.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/Run.cc > CMakeFiles/sim.dir/source/Run.cc.i

CMakeFiles/sim.dir/source/Run.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/Run.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/Run.cc -o CMakeFiles/sim.dir/source/Run.cc.s

CMakeFiles/sim.dir/source/SteppingAction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/source/SteppingAction.cc.o: /home/electricwiz/richAMS/source/SteppingAction.cc
CMakeFiles/sim.dir/source/SteppingAction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sim.dir/source/SteppingAction.cc.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/source/SteppingAction.cc.o -MF CMakeFiles/sim.dir/source/SteppingAction.cc.o.d -o CMakeFiles/sim.dir/source/SteppingAction.cc.o -c /home/electricwiz/richAMS/source/SteppingAction.cc

CMakeFiles/sim.dir/source/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/source/SteppingAction.cc.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/richAMS/source/SteppingAction.cc > CMakeFiles/sim.dir/source/SteppingAction.cc.i

CMakeFiles/sim.dir/source/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/source/SteppingAction.cc.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/richAMS/source/SteppingAction.cc -o CMakeFiles/sim.dir/source/SteppingAction.cc.s

# Object files for target sim
sim_OBJECTS = \
"CMakeFiles/sim.dir/source/Sim.cc.o" \
"CMakeFiles/sim.dir/source/Action.cc.o" \
"CMakeFiles/sim.dir/source/AeroRadiator.cc.o" \
"CMakeFiles/sim.dir/source/Construction.cc.o" \
"CMakeFiles/sim.dir/source/Detector.cc.o" \
"CMakeFiles/sim.dir/source/EventAction.cc.o" \
"CMakeFiles/sim.dir/source/Generator.cc.o" \
"CMakeFiles/sim.dir/source/NaFRadiator.cc.o" \
"CMakeFiles/sim.dir/source/Run.cc.o" \
"CMakeFiles/sim.dir/source/SteppingAction.cc.o"

# External object files for target sim
sim_EXTERNAL_OBJECTS =

sim: CMakeFiles/sim.dir/source/Sim.cc.o
sim: CMakeFiles/sim.dir/source/Action.cc.o
sim: CMakeFiles/sim.dir/source/AeroRadiator.cc.o
sim: CMakeFiles/sim.dir/source/Construction.cc.o
sim: CMakeFiles/sim.dir/source/Detector.cc.o
sim: CMakeFiles/sim.dir/source/EventAction.cc.o
sim: CMakeFiles/sim.dir/source/Generator.cc.o
sim: CMakeFiles/sim.dir/source/NaFRadiator.cc.o
sim: CMakeFiles/sim.dir/source/Run.cc.o
sim: CMakeFiles/sim.dir/source/SteppingAction.cc.o
sim: CMakeFiles/sim.dir/build.make
sim: /home/electricwiz/geant4/install/lib64/libG4Tree.so
sim: /home/electricwiz/geant4/install/lib64/libG4FR.so
sim: /home/electricwiz/geant4/install/lib64/libG4GMocren.so
sim: /home/electricwiz/geant4/install/lib64/libG4visHepRep.so
sim: /home/electricwiz/geant4/install/lib64/libG4RayTracer.so
sim: /home/electricwiz/geant4/install/lib64/libG4VRML.so
sim: /home/electricwiz/geant4/install/lib64/libG4ToolsSG.so
sim: /home/electricwiz/geant4/install/lib64/libG4OpenGL.so
sim: /home/electricwiz/geant4/install/lib64/libG4vis_management.so
sim: /home/electricwiz/geant4/install/lib64/libG4modeling.so
sim: /home/electricwiz/geant4/install/lib64/libG4interfaces.so
sim: /home/electricwiz/geant4/install/lib64/libG4mctruth.so
sim: /home/electricwiz/geant4/install/lib64/libG4geomtext.so
sim: /home/electricwiz/geant4/install/lib64/libG4gdml.so
sim: /home/electricwiz/geant4/install/lib64/libG4error_propagation.so
sim: /home/electricwiz/geant4/install/lib64/libG4readout.so
sim: /home/electricwiz/geant4/install/lib64/libG4physicslists.so
sim: /home/electricwiz/geant4/install/lib64/libG4run.so
sim: /home/electricwiz/geant4/install/lib64/libG4event.so
sim: /home/electricwiz/geant4/install/lib64/libG4tracking.so
sim: /home/electricwiz/geant4/install/lib64/libG4parmodels.so
sim: /home/electricwiz/geant4/install/lib64/libG4processes.so
sim: /home/electricwiz/geant4/install/lib64/libG4digits_hits.so
sim: /home/electricwiz/geant4/install/lib64/libG4track.so
sim: /home/electricwiz/geant4/install/lib64/libG4particles.so
sim: /home/electricwiz/geant4/install/lib64/libG4geometry.so
sim: /home/electricwiz/geant4/install/lib64/libG4materials.so
sim: /home/electricwiz/geant4/install/lib64/libG4graphics_reps.so
sim: /usr/lib64/libGL.so
sim: /usr/lib64/libXmu.so
sim: /usr/lib64/libXext.so
sim: /usr/lib64/libXt.so
sim: /usr/lib64/libICE.so
sim: /usr/lib64/libSM.so
sim: /usr/lib64/libX11.so
sim: /usr/lib64/libxerces-c.so
sim: /home/electricwiz/geant4/install/lib64/libG4analysis.so
sim: /usr/lib64/libexpat.so
sim: /home/electricwiz/geant4/install/lib64/libG4zlib.so
sim: /home/electricwiz/geant4/install/lib64/libG4intercoms.so
sim: /home/electricwiz/geant4/install/lib64/libG4global.so
sim: /home/electricwiz/geant4/install/lib64/libG4clhep.so
sim: /home/electricwiz/geant4/install/lib64/libG4ptl.so.2.3.3
sim: CMakeFiles/sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/electricwiz/richAMS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim.dir/build: sim
.PHONY : CMakeFiles/sim.dir/build

CMakeFiles/sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim.dir/clean

CMakeFiles/sim.dir/depend:
	cd /home/electricwiz/richAMS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/electricwiz/richAMS /home/electricwiz/richAMS /home/electricwiz/richAMS/build /home/electricwiz/richAMS/build /home/electricwiz/richAMS/build/CMakeFiles/sim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sim.dir/depend

