# tests config
include(CTest)
include(AddTests.cmake)

enable_testing()

AddTests("Example" "src/example/example.cpp")
