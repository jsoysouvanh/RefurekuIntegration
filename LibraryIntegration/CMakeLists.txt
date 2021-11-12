cmake_minimum_required(VERSION 3.13.5)

project(RefurekuIntegrationWithCMake)

set(Target RefurekuIntegrationWithCMake)
add_executable(${Target} Source/main.cpp)

# Compile in c++17
target_compile_features(${Target} PUBLIC cxx_std_17)

# Add Include directories
target_include_directories(${Target}
							PRIVATE
								../ThirdParty/Include	# Refureku Include dir
								Include)				# Our project Include dir

# Link against Refureku library
target_link_directories(${Target} PRIVATE ../ThirdParty/Lib)
target_link_libraries(${Target} PRIVATE Refureku)

# Create the command to run RefurekuGenerator
add_custom_target(RunRefurekuGenerator
					WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}			# This is CMakeLists.txt location, which is /LibraryIntegration
					COMMAND ../ThirdParty/Bin/RefurekuGenerator ./RefurekuSettings.toml)

# Run the RefurekuGenerator BEFORE building the project to refresh generated files
add_dependencies(${Target} RunRefurekuGenerator)

# Copy Refureku dynamic library to the output folder to make sure it is used by the executable
add_custom_command(TARGET ${Target} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy
					${PROJECT_SOURCE_DIR}/../ThirdParty/Bin/Refureku.dll
					${CMAKE_BINARY_DIR}/Refureku.dll)