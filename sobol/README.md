# The sobol sequence

Found at http://people.sc.fsu.edu/~jburkardt/cpp_src/sobol/sobol.html

To use with Alsvinn, include the following XML under uq/parameters/parameter

```xml
<type>dll</type>
<library>libsobol.so</library>
<create_function>sobol_create</create_function>
<delete_function>sobol_delete</delete_function>
<generator_function>sobol_generate</generator_function>
```

Make sure libsobol.so is available at runtime.
