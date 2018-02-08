# The hammersley sequence

Found at http://people.sc.fsu.edu/~jburkardt/cpp_src/hammersley/hammersley.html

To use with Alsvinn, include the following XML under uq/parameters/parameter

```xml
<type>dll</type>
<library>libhammersley.so</library>
<create_function>hammersley_create</create_function>
<delete_function>hammersley_delete</delete_function>
<generator_function>hammersley_generate</generator_function>
```

Make sure libhammersley.so is available at runtime.
