
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(CalculusParser STATIC 
    
    ${SOURCE_FILES}
    

)



#target_include_directories(CalculusParser PRIVATE ${SOME_INCLUDE_DIRS})

# Ensures that lib files are contained in build directory
set_target_properties(CalculusParser PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)