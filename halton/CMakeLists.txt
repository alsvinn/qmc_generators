include(GenerateExportHeader)

add_library(halton SHARED src/halton.cpp src/halton_api.cpp)
GENERATE_EXPORT_HEADER( halton
             BASE_NAME halton
             EXPORT_MACRO_NAME HALTON_EXPORT
             EXPORT_FILE_NAME qmc/halton_export.h
)
target_include_directories(halton PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>)
