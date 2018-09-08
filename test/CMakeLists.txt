add_executable(gtestbadge_unittest
  ${GTESTBADGE_EXPORT_HEADER}
  ${GTESTBADGE_VERSION_HEADER}
  ${GTESTBADGE_CONFIG_HEADER}
  main.cpp
  ImageListBuilder.cpp
  ImageListBuilder.h
  TestBadge.cpp
  TestBadge.h
  TestBadgeEventListener.cpp
  TestBadgeEventListener.h
  TestSystem.cpp
  TestSystem.h
)

add_executable(gtestbadge_subtests
  ${GTESTBADGE_EXPORT_HEADER}
  ${GTESTBADGE_VERSION_HEADER}
  ${GTESTBADGE_CONFIG_HEADER}
  subtests.cpp
  TestFoo.cpp
  TestFoo.h
)

# Unit test projects requires to link with pthread if also linking with gtest
if(NOT WIN32)
  set(PTHREAD_LIBRARIES -pthread)
endif()

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(gtestbadge_unittest PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(gtestbadge_subtests PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# gtestbadge_unittest
target_include_directories(gtestbadge_unittest PRIVATE rapidassist)
target_include_directories(gtestbadge_unittest PRIVATE ${GTEST_INCLUDE_DIR})
add_dependencies(gtestbadge_unittest gtestbadge_subtests gtestbadge)
target_link_libraries(gtestbadge_unittest PUBLIC rapidassist gtestbadge ${PTHREAD_LIBRARIES} ${GTEST_LIBRARIES} )

install(TARGETS gtestbadge_unittest
        EXPORT gtestbadge-targets
        ARCHIVE DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${GTESTBADGE_INSTALL_BIN_DIR}
)

# gtestbadge_subtests
target_include_directories(gtestbadge_subtests PRIVATE rapidassist)
target_include_directories(gtestbadge_subtests PRIVATE ${GTEST_INCLUDE_DIR})
add_dependencies(gtestbadge_subtests gtestbadge)
target_link_libraries(gtestbadge_subtests PUBLIC rapidassist gtestbadge ${PTHREAD_LIBRARIES} ${GTEST_LIBRARIES} )

install(TARGETS gtestbadge_subtests
        EXPORT gtestbadge-targets
        ARCHIVE DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${GTESTBADGE_INSTALL_BIN_DIR}
)
