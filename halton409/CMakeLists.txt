include(GenerateExportHeader)

add_library(halton409 SHARED src/halton.cpp src/halton_api.cpp)
GENERATE_EXPORT_HEADER( halton409
             BASE_NAME halton
             EXPORT_MACRO_NAME HALTON409_EXPORT
             EXPORT_FILE_NAME qmc/halton_export.h
)
target_include_directories(halton409 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>)
