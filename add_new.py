"""
Adds a new library. This is just to minimize duplication of code
"""
import sys
import os

if __name__ == "__main__":
    name = sys.argv[1]
    os.system("mkdir %s" % name)

    cmakeString = """
include(GenerateExportHeader)

add_library(%(name)s SHARED src/%(name)s.cpp src/%(name)s_api.cpp)
GENERATE_EXPORT_HEADER( %(name)s
             BASE_NAME %(name)s
             EXPORT_MACRO_NAME %(name_upper)s_EXPORT
             EXPORT_FILE_NAME qmc/%(name)s_export.h
)
target_include_directories(%(name)s PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
    $<INSTALL_INTERFACE:include>
    PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/qmc>
    )
"""%({'name' : name, 'name_upper' : name.upper()})

    with open("%s/CMakeLists.txt" % name,"w") as f:
        f.write(cmakeString)

    os.system("mkdir %s/src" % name)
    os.system("mkdir %s/include" % name)
    os.system("mkdir %s/include/qmc" % name)

    with open("%s/src/%s_api.cpp" % (name, name), "w") as f:
        f.write("""
#include "qmc/%(name)s_api.h"
#include "qmc/%(name)s.hpp"
#include <memory>
#include <iostream>
extern "C" {

%(name_upper)s_EXPORT double %(name)s_generate(void* data, int size, int dimension, int component, int sample) {

}

%(name_upper)s_EXPORT void *%(name)s_create(int size, int dimensions) {

}

%(name_upper)s_EXPORT void %(name)s_delete(void *data) {

}
}
"""% ({'name':name, 'name_upper':name.upper()}))

    with open("%s/include/qmc/%s_api.h" % (name, name), "w") as f:
        f.write("""#pragma once
#include "qmc/%(name)s_export.h"

#ifdef __cplusplus
extern "C" {
#endif
%(name_upper)s_EXPORT void* %(name)s_create(int size, int dimensions);

%(name_upper)s_EXPORT double %(name)s_generate(void* data, int size, int dimension, int component, int sample);

%(name_upper)s_EXPORT void %(name)s_delete(void* data);

#ifdef __cplusplus
}
#endif
""" % ({'name' : name, 'name_upper' : name.upper()}))


    os.system("cp {name}.cpp {name}/src/{name}.cpp".format(name = name))
    os.system("cp {name}.hpp {name}/include/qmc/{name}.hpp".format(name = name))

    with open("{name}/README.md".format(name = name), "w") as f:
        f.write("""# The %(name)s sequence

Found at %(url)s

To use with Alsvinn, include the following XML under uq/parameters/parameter

```xml
<type>dll</type>
<library>lib%(name)s.so</library>
<create_function>%(name)s_create</create_function>
<delete_function>%(name)s_delete</delete_function>
<generator_function>%(name)s_generate</generator_function>
```

Make sure lib%(name)s.so is available at runtime.
""" % ({'name': name, 'url' : sys.argv[2]}))
    
    
                

    
