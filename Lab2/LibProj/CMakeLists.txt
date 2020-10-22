cmake_minimum_required(VERSION 3.16.3)

project(libproj)

add_library(static_lib STATIC maths.cpp)

install (TARGETS static_lib DESTINATION ~/Desktop/Denis_Repo_Iep/Denis-IEP/Lab2/ExecProj)
install (FILES header.h DESTINATION ~/Desktop/Denis_Repo_Iep/Denis-IEP/Lab2/ExecProj)
