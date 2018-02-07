
include(GenerateExportHeader)

add_library(latin_center SHARED src/latin_center.cpp src/latin_center_api.cpp)
GENERATE_EXPORT_HEADER( latin_center
             BASE_NAME latin_center
             EXPORT_MACRO_NAME LATIN_CENTER_EXPORT
             EXPORT_FILE_NAME qmc/latin_center_export.h
)
target_include_directories(latin_center PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/qmc>
    )
