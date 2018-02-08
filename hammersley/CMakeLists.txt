
include(GenerateExportHeader)

add_library(hammersley SHARED src/hammersley.cpp src/hammersley_api.cpp)
GENERATE_EXPORT_HEADER( hammersley
             BASE_NAME hammersley
             EXPORT_MACRO_NAME HAMMERSLEY_EXPORT
             EXPORT_FILE_NAME qmc/hammersley_export.h
)
target_include_directories(hammersley PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/qmc>
    )
