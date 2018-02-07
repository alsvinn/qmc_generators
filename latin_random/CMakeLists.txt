include(GenerateExportHeader)

add_library(latin_random SHARED src/latin_random.cpp src/latin_random_api.cpp)
GENERATE_EXPORT_HEADER( latin_random
             BASE_NAME latin_random
             EXPORT_MACRO_NAME LATIN_RANDOM_EXPORT
             EXPORT_FILE_NAME qmc/latin_random_export.h
)
target_include_directories(latin_random PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/qmc>
    )
