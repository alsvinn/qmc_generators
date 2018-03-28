find_package(Boost REQUIRED COMPONENTS system filesystem thread)

add_executable(dryrun src/main.cpp)
target_link_libraries(dryrun Boost::system
    Boost::filesystem ${CMAKE_DL_LIBS} )
