cmake_minimum_required (VERSION 2.8)

project (ip_link_linux)

aux_source_directory (./ SRC_LIST)

add_executable (main ${SRC_LIST})

target_link_libraries (main m)