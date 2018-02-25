
find_package(PythonInterp REQUIRED)
# The primes.h file is roughly 300 MB large, we don't want to add it to the repository
# Therefore, every time we compile, we generate the first (\approx) 8 million primes
add_custom_command(OUTPUT primes.h
	COMMAND "${PYTHON_EXECUTABLE}" "${CMAKE_CURRENT_SOURCE_DIR}/find_primes.py" "primes.h" "${CMAKE_CURRENT_BINARY_DIR}/primes.txt"
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generating known primes up to a certain limit (this could take a while).\nSee ${CMAKE_CURRENT_SOURCE_DIR}/find_primes.py")
add_custom_target(
  find_primes
  DEPENDS primes.h
)

add_library(primes INTERFACE)
add_dependencies(primes find_primes)
target_include_directories(primes INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/>
  $<INSTALL_INTERFACE:include>)
