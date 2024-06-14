# This CMakeLists.txt file requires the definition of the following variables:
# - CMSIS_SDK_PATH: the path to the CMSIS root directory
# - PICO_SDK_PATH: the path to the Pico SDK directory

if(NOT DEFINED CMSIS_SDK_PATH)
    message(FATAL_ERROR "CMSIS_SDK_PATH is not defined")
endif()

if(NOT DEFINED PICO_SDK_PATH)
    message(FATAL_ERROR "PICO_SDK_PATH is not defined")
endif()

# Include the CMSIS SDK
add_library(pico_debug STATIC
  ${CMSIS_SDK_PATH}/CMSIS/DAP/Firmware/Source/DAP.c
)