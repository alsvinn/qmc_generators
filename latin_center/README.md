# The latin_center sequence

Found at http://people.sc.fsu.edu/~jburkardt/cpp_src/latin_center/latin_center.html

To use with Alsvinn, include the following XML under uq/parameters/parameter

    ```
    <type>dll</type>
    <library>liblatin_center.so</library>
    <create_function>latin_center_create</create_function>
    <delete_function>latin_center_delete</delete_function>
    <generator_function>latin_center_generate</generator_function>
   ```

Make sure liblatin_center.so is available at runtime.
