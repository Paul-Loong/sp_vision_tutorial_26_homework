cmake_minimum_required(VERSION 3.10)
project(lecture_2_homework)

# include_directories(part_1)
# add_executable(cpp_basics part_1/cpp_basics.cpp part_1/tools.cpp)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# add_executable(split_channels part_2/split_channels.cpp )
# target_link_libraries(split_channels ${OpenCV_LIBS})

# add_executable(lightbar_detection part_3/lightbar_detection..cpp)
# target_link_libraries(lightbar_detection ${OpenCV_LIBS})

find_package(FMT REQUIRED)
add_executable(fmt_test homework/fmt_test.cpp)
target_link_libraries(fmt_test fmt::fmt)

include_directories(homework)
add_executable(cv_main homework/main.cpp homework/tools.cpp)
target_link_libraries(cv_main ${OpenCV_LIBS})
target_link_libraries(cv_main fmt::fmt)
