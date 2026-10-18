cmake_minimum_required(VERSION 4.2)

project(Chisel)

add_executable(chisel)

target_sources(chisel
	PRIVATE
		main.cpp
		tokenise.cpp
		format.cpp
)
