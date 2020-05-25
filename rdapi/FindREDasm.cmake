set(REDASM_FOUND TRUE)
set(REDASM_LIBRARY_NAME "LibREDasm${CMAKE_SHARED_LIBRARY_SUFFIX}")

foreach(MODULE ${CMAKE_MODULE_PATH})
    if(NOT DEFINED REDASM_INCLUDE_PATH AND EXISTS "${MODULE}/rdapi.h")
        set(REDASM_INCLUDE_PATH "${MODULE}/..")
    endif()

    if(NOT DEFINED REDASM_LIBRARY_PATH AND EXISTS "${MODULE}/../${REDASM_LIBRARY_NAME}")
        set(REDASM_LIBRARY_PATH "${MODULE}/../${REDASM_LIBRARY_NAME}")
    endif()
endforeach()

if(WIN32)
    if(NOT DEFINED REDASM_INCLUDE_PATH)
        set(REDASM_INCLUDE_PATH ${CMAKE_CURRENT_LIST_DIR})
    endif()

    if(NOT DEFINED REDASM_LIBRARY_PATH)
        set(REDASM_LIBRARY_PATH "${CMAKE_SOURCE_DIR}/../${REDASM_LIBRARY_NAME}")
    endif()
endif()

function(redasm_plugin P_NAME)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_SKIP_BUILD_RPATH TRUE)
    string(TOLOWER "${P_NAME}" P_ID)

    cmake_parse_arguments(ARG "${OPTIONS}" "" "" ${ARGN})
    add_library(${P_NAME} SHARED ${ARG_UNPARSED_ARGUMENTS})
    target_compile_definitions(${P_NAME} PRIVATE -Drd_plugin_id="${P_ID}")

    if(DEFINED REDASM_INCLUDE_PATH)
        target_include_directories(${P_NAME} PRIVATE ${REDASM_INCLUDE_PATH}
                                             PUBLIC  ${REDASM_INCLUDE_PATH}/libs)
    endif()

    if(DEFINED REDASM_LIBRARY_PATH)
        target_link_libraries(${P_NAME} PRIVATE ${REDASM_LIBRARY_PATH})
    else()
        target_link_libraries(${P_NAME} PRIVATE LibREDasm)
    endif()

    set_target_properties(${P_NAME} PROPERTIES PREFIX "")
    set_target_properties(${P_NAME} PROPERTIES OUTPUT_NAME "${P_ID}")
    set_target_properties(${P_NAME} PROPERTIES LINKER_LANGUAGE CXX)
endfunction()