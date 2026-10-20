cmake_minimum_required(VERSION 4.2)

project(Chisel
	VERSION 0.0.1
	DESCRIPTION "Chisel is a flexible code formatter written in pure C++"
	LANGUAGES CXX
)

add_executable(chisel)

target_sources(chisel
	PRIVATE
		src/main.cpp
		src/tokenise.cpp
		src/format.cpp
)

find_package(Catch2 REQUIRED)

add_executable(tests)

target_sources(tests
	PRIVATE
		tests/test.cpp
		src/tokenise.cpp
)

target_link_libraries(tests
	PRIVATE
		Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(tests)
