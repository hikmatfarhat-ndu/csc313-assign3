cmake_minimum_required(VERSION 3.10.0)
project (assign3 LANGUAGES CXX)
add_executable (main main.cpp map.h)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "main")
set(CMAKE_SUPPRESS_REGENERATION true)
set_target_properties(main PROPERTIES CXX_STANDARD 17)

if(NOT WIN32)
	add_executable (t0 t0.cpp )
	add_executable (t1 t1.cpp )
	add_executable (t2 t2.cpp )
	add_executable (t3 t3.cpp)
	add_custom_target(tests)
	add_dependencies(tests t0 t1 t2 t3)
#	add_executable (test2 t2.cpp helpers.h)
#	add_executable (test3 t3.cpp helpers.h)
#	set_target_properties(test0 PROPERTIES CXX_STANDARD 17)
#	set_target_properties(test1 PROPERTIES CXX_STANDARD 17)
#	set_target_properties(test2 PROPERTIES CXX_STANDARD 17)
#	set_target_properties(test3 PROPERTIES CXX_STANDARD 17)
endif()

#if(WIN32)
	#target_compile_options(main PRIVATE "/std:c++17")

	#set_target_properties(main PROPERTIES CXX_STANDARD 17)
#else()
#target_compile_options(main PRIVATE "-std=c++17")
#target_compile_options(test0 PRIVATE "-std=c++17")
#target_compile_options(test1 PRIVATE "-std=c++17")
#target_compile_options(test2 PRIVATE "-std=c++17")
#endif()


