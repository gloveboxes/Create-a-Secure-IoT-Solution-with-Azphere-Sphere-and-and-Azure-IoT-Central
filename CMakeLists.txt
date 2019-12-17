#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

cmake_minimum_required (VERSION 3.8)
project (AzureSphereBlink1 C)

add_subdirectory("../MT3620_Grove_Shield/MT3620_Grove_Shield_Library" out)

# Create executable
add_executable (${PROJECT_NAME} main.c epoll_timerfd_utilities.c)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${AZURE_SPHERE_API_SET_DIR}/usr/include/azureiot)
TARGET_COMPILE_DEFINITIONS(${PROJECT_NAME} PUBLIC AZURE_IOT_HUB_CONFIGURED)
target_link_libraries (${PROJECT_NAME} applibs pthread gcc_s c MT3620_Grove_Shield_Library azureiot)

# Add MakeImage post-build command
include (${AZURE_SPHERE_MAKE_IMAGE_FILE})
