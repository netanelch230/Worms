cmake_minimum_required (VERSION 3.14)

project (Worms)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/permissive-)
endif ()
	add_executable (Worms WIN32 "")
	add_subdirectory (Box2D/include)
	add_subdirectory (Box2D/src)
	add_subdirectory (include)
	add_subdirectory (src)
	add_subdirectory (resources)

	set (SFML_STATIC_LIBRARIES TRUE)
	set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

	find_package (SFML 2.5 COMPONENTS audio graphics REQUIRED)


	target_link_libraries (Worms sfml-graphics sfml-audio sfml-main)
	target_link_libraries (Worms box2d)

	set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)


