#include <boost/test/unit_test.hpp>

#include <rtt/os/main.h>

extern boost::unit_test::test_suite *init_unit_test_suite(int argc,
                                                          char *argv[]);

int ORO_main(int argc, char **argv) {
  return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}
