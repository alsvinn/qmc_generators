include(GoogleTest)
enable_testing()
find_package(Boost REQUIRED COMPONENTS system filesystem thread)
find_package(GTest REQUIRED)
SET(MPI_CXX_SKIP_MPICXX ON)
# It seems MPI doesn't set this correctly anymore, so we have to
# specify This
# manually.
add_definitions(-DOMPI_SKIP_MPICXX)
add_definitions(-DMPICH_SKIP_MPICXX)
find_package(MPI REQUIRED)

add_executable(qmc_test src/main.cpp src/convergence_test.cpp)

gtest_add_tests(TARGET qmc_test)

target_link_libraries(qmc_test GTest::Main GTest::GTest Boost::system
    Boost::filesystem ${CMAKE_DL_LIBS} MPI::MPI_C)

