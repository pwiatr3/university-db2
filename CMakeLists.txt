cmake_minimum_required(VERSION 3.10)

project(univeristy-db)
enable_testing()

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

#add_executable(tests test.cpp)
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(${PROJECT_NAME} main.cpp db.cpp student.cpp person.cpp menu.cpp)

add_executable(${PROJECT_NAME}-ut db.cpp student.cpp person.cpp menu.cpp test.cpp)
target_link_libraries(${PROJECT_NAME}-ut PRIVATE Catch2::Catch2WithMain)
