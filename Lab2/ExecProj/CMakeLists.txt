cmake_minimum_required(VERSION 3.16.3)

project(execproj)

add_executable(exec main.cpp)

target_link_libraries (exec ~/Desktop/Denis_Repo_Iep/Denis-IEP/Lab2/ExecProj/libstatic_lib.a)

install (TARGETS exec DESTINATION ~/Desktop/Denis_Repo_Iep/Denis-IEP/Lab2/ExecProj/build)
