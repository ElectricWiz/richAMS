# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/electricwiz/geant4/physicsMattersTutorials

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/electricwiz/geant4/physicsMattersTutorials/build

# Include any dependencies generated for this target.
include CMakeFiles/sim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sim.dir/flags.make

CMakeFiles/sim.dir/Sim.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/Sim.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/Sim.cc
CMakeFiles/sim.dir/Sim.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sim.dir/Sim.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/Sim.cc.o -MF CMakeFiles/sim.dir/Sim.cc.o.d -o CMakeFiles/sim.dir/Sim.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/Sim.cc

CMakeFiles/sim.dir/Sim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/Sim.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/Sim.cc > CMakeFiles/sim.dir/Sim.cc.i

CMakeFiles/sim.dir/Sim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/Sim.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/Sim.cc -o CMakeFiles/sim.dir/Sim.cc.s

CMakeFiles/sim.dir/Action.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/Action.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/Action.cc
CMakeFiles/sim.dir/Action.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sim.dir/Action.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/Action.cc.o -MF CMakeFiles/sim.dir/Action.cc.o.d -o CMakeFiles/sim.dir/Action.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/Action.cc

CMakeFiles/sim.dir/Action.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/Action.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/Action.cc > CMakeFiles/sim.dir/Action.cc.i

CMakeFiles/sim.dir/Action.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/Action.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/Action.cc -o CMakeFiles/sim.dir/Action.cc.s

CMakeFiles/sim.dir/AeroRadiator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/AeroRadiator.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/AeroRadiator.cc
CMakeFiles/sim.dir/AeroRadiator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sim.dir/AeroRadiator.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/AeroRadiator.cc.o -MF CMakeFiles/sim.dir/AeroRadiator.cc.o.d -o CMakeFiles/sim.dir/AeroRadiator.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/AeroRadiator.cc

CMakeFiles/sim.dir/AeroRadiator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/AeroRadiator.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/AeroRadiator.cc > CMakeFiles/sim.dir/AeroRadiator.cc.i

CMakeFiles/sim.dir/AeroRadiator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/AeroRadiator.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/AeroRadiator.cc -o CMakeFiles/sim.dir/AeroRadiator.cc.s

CMakeFiles/sim.dir/Construction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/Construction.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/Construction.cc
CMakeFiles/sim.dir/Construction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sim.dir/Construction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/Construction.cc.o -MF CMakeFiles/sim.dir/Construction.cc.o.d -o CMakeFiles/sim.dir/Construction.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/Construction.cc

CMakeFiles/sim.dir/Construction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/Construction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/Construction.cc > CMakeFiles/sim.dir/Construction.cc.i

CMakeFiles/sim.dir/Construction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/Construction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/Construction.cc -o CMakeFiles/sim.dir/Construction.cc.s

CMakeFiles/sim.dir/Detector.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/Detector.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/Detector.cc
CMakeFiles/sim.dir/Detector.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sim.dir/Detector.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/Detector.cc.o -MF CMakeFiles/sim.dir/Detector.cc.o.d -o CMakeFiles/sim.dir/Detector.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/Detector.cc

CMakeFiles/sim.dir/Detector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/Detector.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/Detector.cc > CMakeFiles/sim.dir/Detector.cc.i

CMakeFiles/sim.dir/Detector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/Detector.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/Detector.cc -o CMakeFiles/sim.dir/Detector.cc.s

CMakeFiles/sim.dir/EventAction.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/EventAction.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/EventAction.cc
CMakeFiles/sim.dir/EventAction.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sim.dir/EventAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/EventAction.cc.o -MF CMakeFiles/sim.dir/EventAction.cc.o.d -o CMakeFiles/sim.dir/EventAction.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/EventAction.cc

CMakeFiles/sim.dir/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/EventAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/EventAction.cc > CMakeFiles/sim.dir/EventAction.cc.i

CMakeFiles/sim.dir/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/EventAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/EventAction.cc -o CMakeFiles/sim.dir/EventAction.cc.s

CMakeFiles/sim.dir/Generator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/Generator.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/Generator.cc
CMakeFiles/sim.dir/Generator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sim.dir/Generator.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/Generator.cc.o -MF CMakeFiles/sim.dir/Generator.cc.o.d -o CMakeFiles/sim.dir/Generator.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/Generator.cc

CMakeFiles/sim.dir/Generator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/Generator.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/Generator.cc > CMakeFiles/sim.dir/Generator.cc.i

CMakeFiles/sim.dir/Generator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/Generator.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/Generator.cc -o CMakeFiles/sim.dir/Generator.cc.s

CMakeFiles/sim.dir/NaFRadiator.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/NaFRadiator.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/NaFRadiator.cc
CMakeFiles/sim.dir/NaFRadiator.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sim.dir/NaFRadiator.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/NaFRadiator.cc.o -MF CMakeFiles/sim.dir/NaFRadiator.cc.o.d -o CMakeFiles/sim.dir/NaFRadiator.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/NaFRadiator.cc

CMakeFiles/sim.dir/NaFRadiator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/NaFRadiator.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/NaFRadiator.cc > CMakeFiles/sim.dir/NaFRadiator.cc.i

CMakeFiles/sim.dir/NaFRadiator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/NaFRadiator.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/NaFRadiator.cc -o CMakeFiles/sim.dir/NaFRadiator.cc.s

CMakeFiles/sim.dir/Run.cc.o: CMakeFiles/sim.dir/flags.make
CMakeFiles/sim.dir/Run.cc.o: /home/electricwiz/geant4/physicsMattersTutorials/Run.cc
CMakeFiles/sim.dir/Run.cc.o: CMakeFiles/sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sim.dir/Run.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sim.dir/Run.cc.o -MF CMakeFiles/sim.dir/Run.cc.o.d -o CMakeFiles/sim.dir/Run.cc.o -c /home/electricwiz/geant4/physicsMattersTutorials/Run.cc

CMakeFiles/sim.dir/Run.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sim.dir/Run.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/electricwiz/geant4/physicsMattersTutorials/Run.cc > CMakeFiles/sim.dir/Run.cc.i

CMakeFiles/sim.dir/Run.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sim.dir/Run.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/electricwiz/geant4/physicsMattersTutorials/Run.cc -o CMakeFiles/sim.dir/Run.cc.s

# Object files for target sim
sim_OBJECTS = \
"CMakeFiles/sim.dir/Sim.cc.o" \
"CMakeFiles/sim.dir/Action.cc.o" \
"CMakeFiles/sim.dir/AeroRadiator.cc.o" \
"CMakeFiles/sim.dir/Construction.cc.o" \
"CMakeFiles/sim.dir/Detector.cc.o" \
"CMakeFiles/sim.dir/EventAction.cc.o" \
"CMakeFiles/sim.dir/Generator.cc.o" \
"CMakeFiles/sim.dir/NaFRadiator.cc.o" \
"CMakeFiles/sim.dir/Run.cc.o"

# External object files for target sim
sim_EXTERNAL_OBJECTS =

sim: CMakeFiles/sim.dir/Sim.cc.o
sim: CMakeFiles/sim.dir/Action.cc.o
sim: CMakeFiles/sim.dir/AeroRadiator.cc.o
sim: CMakeFiles/sim.dir/Construction.cc.o
sim: CMakeFiles/sim.dir/Detector.cc.o
sim: CMakeFiles/sim.dir/EventAction.cc.o
sim: CMakeFiles/sim.dir/Generator.cc.o
sim: CMakeFiles/sim.dir/NaFRadiator.cc.o
sim: CMakeFiles/sim.dir/Run.cc.o
sim: CMakeFiles/sim.dir/build.make
sim: /home/electricwiz/geant4/geant4_install/lib/libG4Tree.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4FR.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4GMocren.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4visHepRep.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4RayTracer.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4VRML.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4ToolsSG.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4OpenGL.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4vis_management.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4modeling.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4interfaces.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4persistency.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4error_propagation.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4readout.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4physicslists.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4run.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4event.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4tracking.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4parmodels.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4processes.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4digits_hits.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4track.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4particles.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4geometry.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4materials.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4graphics_reps.so
sim: /usr/lib/libXmu.so
sim: /usr/lib/libXext.so
sim: /usr/lib/libXt.so
sim: /usr/lib/libICE.so
sim: /usr/lib/libSM.so
sim: /usr/lib/libX11.so
sim: /usr/lib/libGL.so
sim: /usr/lib/libQt5OpenGL.so.5.15.11
sim: /usr/lib/libQt5PrintSupport.so.5.15.11
sim: /usr/lib/libQt5Widgets.so.5.15.11
sim: /usr/lib/libQt5Gui.so.5.15.11
sim: /usr/lib/libQt5Core.so.5.15.11
sim: /usr/lib/libxerces-c.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4analysis.so
sim: /usr/lib/libexpat.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4zlib.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4intercoms.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4global.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4clhep.so
sim: /home/electricwiz/geant4/geant4_install/lib/libG4ptl.so.2.3.3
sim: CMakeFiles/sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sim.dir/build: sim
.PHONY : CMakeFiles/sim.dir/build

CMakeFiles/sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sim.dir/clean

CMakeFiles/sim.dir/depend:
	cd /home/electricwiz/geant4/physicsMattersTutorials/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/electricwiz/geant4/physicsMattersTutorials /home/electricwiz/geant4/physicsMattersTutorials /home/electricwiz/geant4/physicsMattersTutorials/build /home/electricwiz/geant4/physicsMattersTutorials/build /home/electricwiz/geant4/physicsMattersTutorials/build/CMakeFiles/sim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sim.dir/depend

