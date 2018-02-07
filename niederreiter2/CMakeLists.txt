
include(GenerateExportHeader)

add_library(niederreiter2 SHARED src/niederreiter2.cpp src/niederreiter2_api.cpp)
GENERATE_EXPORT_HEADER( niederreiter2
             BASE_NAME niederreiter2
             EXPORT_MACRO_NAME NIEDERREITER2_EXPORT
             EXPORT_FILE_NAME qmc/niederreiter2_export.h
)
target_include_directories(niederreiter2 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/qmc>
    )
