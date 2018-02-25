include(GenerateExportHeader)
find_package(PythonInterp REQUIRED)

add_library(sobol_large SHARED src/sobol_large_api.cpp)

GENERATE_EXPORT_HEADER( sobol
             BASE_NAME sobol
             EXPORT_MACRO_NAME SOBOL_EXPORT
             EXPORT_FILE_NAME qmc/sobol_export.h
)
target_include_directories(sobol_large PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
    )

