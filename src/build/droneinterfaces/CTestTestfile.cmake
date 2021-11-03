# CMake generated Testfile for 
# Source directory: /home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces
# Build directory: /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(copyright "/usr/bin/python3.8" "-u" "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/test_results/droneinterfaces/copyright.xunit.xml" "--package-name" "droneinterfaces" "--output-file" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/ament_copyright/copyright.txt" "--command" "/home/jakeluo/Software/ros2_rolling/install/ament_copyright/bin/ament_copyright" "--xunit-file" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/test_results/droneinterfaces/copyright.xunit.xml")
set_tests_properties(copyright PROPERTIES  LABELS "copyright;linter" TIMEOUT "120" WORKING_DIRECTORY "/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces" _BACKTRACE_TRIPLES "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_copyright/share/ament_cmake_copyright/cmake/ament_copyright.cmake;46;ament_add_test;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_copyright/share/ament_cmake_copyright/cmake/ament_cmake_copyright_lint_hook.cmake;18;ament_copyright;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_copyright/share/ament_cmake_copyright/cmake/ament_cmake_copyright_lint_hook.cmake;0;;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/jakeluo/Software/ros2_rolling/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/jakeluo/Software/ros2_rolling/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces/CMakeLists.txt;33;ament_package;/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3.8" "-u" "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/test_results/droneinterfaces/lint_cmake.xunit.xml" "--package-name" "droneinterfaces" "--output-file" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/ament_lint_cmake/lint_cmake.txt" "--command" "/home/jakeluo/Software/ros2_rolling/install/ament_lint_cmake/bin/ament_lint_cmake" "--xunit-file" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/test_results/droneinterfaces/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces" _BACKTRACE_TRIPLES "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_lint_cmake/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/jakeluo/Software/ros2_rolling/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/jakeluo/Software/ros2_rolling/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces/CMakeLists.txt;33;ament_package;/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3.8" "-u" "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_test/share/ament_cmake_test/cmake/run_test.py" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/test_results/droneinterfaces/xmllint.xunit.xml" "--package-name" "droneinterfaces" "--output-file" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/ament_xmllint/xmllint.txt" "--command" "/home/jakeluo/Software/ros2_rolling/install/ament_xmllint/bin/ament_xmllint" "--xunit-file" "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneinterfaces/test_results/droneinterfaces/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces" _BACKTRACE_TRIPLES "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_test/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_xmllint/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/jakeluo/Software/ros2_rolling/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/home/jakeluo/Software/ros2_rolling/install/ament_lint_auto/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces/CMakeLists.txt;33;ament_package;/home/jakeluo/Documents/MonitoringSystemRos2/src/droneinterfaces/CMakeLists.txt;0;")
subdirs("droneinterfaces__py")