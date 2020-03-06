CMAKE_MINIMUM_REQUIRED(VERSION 3.0 FATAL_ERROR)
CMAKE_POLICY(SET CMP0054 NEW)

PROJECT(CyberAttack)

SET(OUTBIN ${CMAKE_BINARY_DIR}/bin)

IF(
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang"
)
	SET(cxx_flags "-std=c++14 -Wall -Wextra")
	SET(cxx_flags_debug "-g -O0")
	SET(cxx_flags_release "-O3")
ELSEIF("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	SET(cxx_flags "/std:c++14 /WX /EHsc")
ENDIF()

ADD_SUBDIRECTORY(vendor)

IF(NOT CONFIGURED_ONCE)
	SET(
		CMAKE_CXX_FLAGS "${cxx_flags}"
		CACHE STRING "cxx flags" FORCE
	)
	SET(
		CMAKE_CXX_FLAGS_DEBUG "${cxx_flags_debug}"
		CACHE STRING "cxx flags debug" FORCE
	)
	SET(
		CMAKE_CXX_FLAGS_RELEASE "${cxx_flags_release}"
		CACHE STRING "cxx flags release" FORCE
	)
ENDIF()

ADD_SUBDIRECTORY(src)

SET(CONFIGURED_ONCE TRUE CACHE INTERNAL "configured once")
