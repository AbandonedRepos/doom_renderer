INCLUDE(CMakeForceCompiler)

SET (CMAKE_CROSSCOMPILING   TRUE)
SET (CMAKE_SYSTEM_NAME      "Darwin")
SET (CMAKE_SYSTEM_PROCESSOR "armv7")
SET (IOS TRUE)

SET (IOS_SDK_DEVICE iPhoneOS)

SET (SDKVER     "${IOS_SDK_VERSION}")
SET (DEVROOT    "${XCODE_ROOT_DIR}/Platforms/${IOS_SDK_DEVICE}.platform/Developer")


SET (CMAKE_FIND_ROOT_PATH "${SDKROOT}" "${DEVROOT}")
SET (CMAKE_FIND_ROOT_PATH_MODE_PROGRAM  NEVER)
SET (CMAKE_FIND_ROOT_PATH_MODE_LIBRARY  ONLY)
SET (CMAKE_FIND_ROOT_PATH_MODE_INCLUDE  ONLY)