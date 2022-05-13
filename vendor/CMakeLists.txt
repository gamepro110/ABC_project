# vendor config

## glfw
add_subdirectory(GLFW)
#set_target_properties(
#	glfw
#	uninstall
#	update_mappings
#	PROPERTIES
#	FOLDER "deps/GLFW3"
#)
#set_target_properties(
#	boing gears heightmap offscreen particles
#	sharing simple splitview wave
#	PROPERTIES
#	FOLDER "deps/GLFW3/Examples"
#)
#set_target_properties(
#	clipboard cursor empty events gamma glfwinfo icon iconify
#	inputlag joysticks monitors msaa opacity reopen tearing
#	threads timeout title triangle-vulkan windows
#	PROPERTIES
#	FOLDER "deps/GLFW3/Tests"
#)

## dear-imgui
file(
	GLOB
	IMGUI_SRC
	"${vendorPath}/dear-imgui/*.cpp"
	"${vendorPath}/dear-imgui/*.h"
	"${vendorPath}/dear-imgui/backends/imgui_impl_glfw.cpp"
	"${vendorPath}/dear-imgui/backends/imgui_impl_glfw.h"
)

if(WIN32)
	set(IMGUI_SRC "${IMGUI_SRC};${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.h;${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.cpp")
elseif(UNIX)
	if(APPLE)
		message("!! check included imgui files !!")
		message(">>> PRE ${IMGUI_SRC}")
		set(IMGUI_SRC "${IMGUI_SRC};${vendorPath}/dear-imgui/backends/imgui_impl_metal.h;${vendorPath}/dear-imgui/backends/imgui_impl_metal.mm")
		message(">>> POST ${IMGUI_SRC}")
	else()
		set(IMGUI_SRC "${IMGUI_SRC};${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.h;${vendorPath}/dear-imgui/backends/imgui_impl_vulkan.cpp")
	endif()
endif()

add_library(
	IMGUI_LIB
	STATIC
	${IMGUI_SRC}
)

target_include_directories(
	IMGUI_LIB
	PUBLIC
	"${vendorPath}/dear-imgui/"
	"${vendorPath}/GLFW/include"
    "${Vulkan_INCLUDE_DIRS}"
)

target_link_libraries(
	IMGUI_LIB
	PUBLIC
	"${Vulkan_LIBRARIES}"
)

set_target_properties(
	IMGUI_LIB
	PROPERTIES
	POSITION_INDEPENDENT_CODE ON
	CXX_STANDARD 20
	FOLDER "deps/ImGui"
)

## spdlog
add_subdirectory(spdlog)

set_target_properties(
	spdlog
	PROPERTIES
	POSITION_INDEPENDENT_CODE ON
	CXX_STANDARD 20
	FOLDER "deps/spdlog"
)

## catch2
add_subdirectory(catch2)
