# The niederreiter2 sequence

Found at http://people.sc.fsu.edu/~jburkardt/cpp_src/niederreiter2/niederreiter2.html

To use with Alsvinn, include the following XML under uq/parameters/parameter

```xml
<type>dll</type>
<library>libniederreiter2.so</library>
<create_function>niederreiter2_create</create_function>
<delete_function>niederreiter2_delete</delete_function>
<generator_function>niederreiter2_generate</generator_function>
```

Make sure libniederreiter2.so is available at runtime.
