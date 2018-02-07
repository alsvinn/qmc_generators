# The faure sequence

Found at http://people.sc.fsu.edu/~jburkardt/cpp_src/faure/faure.html

To use with Alsvinn, include the following XML under uq/parameters/parameter

    ```.xml
    <type>dll</type>
    <library>libfaure.so</library>
    <create_function>faure_create</create_function>
    <delete_function>faure_delete</delete_function>
    <generator_function>faure_generate</generator_function>
   ```

Make sure libfaure.so is available at runtime.
