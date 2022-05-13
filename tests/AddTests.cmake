cmake_minimum_required(VERSION 3.10)
include_guard(GLOBAL)

function(AddTests TestName sourceFile)
	
	set(fullName "${PROJECT_NAME}_${TestName}")
	set(_runtime "${fullName}_Tests")

	add_executable(${_runtime} ${sourceFile})
	set_property(TARGET ${_runtime} PROPERTY FOLDER "Tests/")
	target_include_directories(${_runtime} PUBLIC "${vendorPaht}/catch2/src/")
	
	if(WIN32)
	target_link_libraries(${_runtime} PUBLIC ${PROJECT_NAME} Catch2 Catch2WithMain)
	else()
	target_link_libraries(${_runtime} PUBLIC Catch2 Catch2WithMain)
	endif()

	add_test(NAME ${_runtime} COMMAND ${_runtime})

endfunction(AddTests)