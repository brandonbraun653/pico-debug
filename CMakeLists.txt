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
  ${CMSIS_SDK_PATH}/CMSIS/DAP/Firmware/Source/DAP_vendor.c
  ${CMSIS_SDK_PATH}/CMSIS/DAP/Firmware/Source/JTAG_DP.c
  ${CMSIS_SDK_PATH}/CMSIS/DAP/Firmware/Source/SW_DP.c
  ${CMSIS_SDK_PATH}/CMSIS/DAP/Firmware/Source/SWO.c
)
target_compile_definitions(pico_debug PRIVATE -DCFG_TUSB_MCU=OPT_MCU_RP2040)
target_include_directories(pico_debug PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMSIS_SDK_PATH}/CMSIS/Core/Include
  ${CMSIS_SDK_PATH}/CMSIS/DAP/Firmware/Include
  ${PICO_SDK_PATH}/lib/tinyusb/hw/
  ${PICO_SDK_PATH}/lib/tinyusb/src/
  ${PICO_SDK_PATH}/src/boards/include/
  ${PICO_SDK_PATH}/src/common/pico_base/include/
  ${PICO_SDK_PATH}/src/common/pico_binary_info/include/
  ${PICO_SDK_PATH}/src/common/pico_bit_ops/include/
  ${PICO_SDK_PATH}/src/common/pico_divider/include/
  ${PICO_SDK_PATH}/src/common/pico_stdlib/include/
  ${PICO_SDK_PATH}/src/common/pico_sync/include/
  ${PICO_SDK_PATH}/src/common/pico_time/include/
  ${PICO_SDK_PATH}/src/common/pico_util/include/
  ${PICO_SDK_PATH}/src/rp2040/hardware_regs/include/
  ${PICO_SDK_PATH}/src/rp2040/hardware_structs/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_base/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_claim/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_clocks/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_divider/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_gpio/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_irq/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_pll/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_resets/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_sync/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_timer/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_uart/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_vreg/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_watchdog/include/
  ${PICO_SDK_PATH}/src/rp2_common/hardware_xosc/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_base/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_bootrom/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_double/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_float/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_int64_ops/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_platform/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_printf/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_runtime/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_stdio/include/
  ${PICO_SDK_PATH}/src/rp2_common/pico_stdio_uart/include/
  )
