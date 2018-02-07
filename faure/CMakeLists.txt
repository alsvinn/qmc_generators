
include(GenerateExportHeader)

add_library(faure SHARED src/faure.cpp src/faure_api.cpp)
GENERATE_EXPORT_HEADER( faure
             BASE_NAME faure
             EXPORT_MACRO_NAME FAURE_EXPORT
             EXPORT_FILE_NAME qmc/faure_export.h
)
target_include_directories(faure PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/qmc>
    )
