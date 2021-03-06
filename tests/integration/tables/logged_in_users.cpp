
/**
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed as defined on the LICENSE file found in the
 *  root directory of this source tree.
 */

// Sanity check integration test for logged_in_users
// Spec file: specs/logged_in_users.table

#include <osquery/tests/integration/tables/helper.h>

namespace osquery {
namespace table_tests {

class LoggedInUsersTest : public testing::Test {
  protected:
    void SetUp() override {
      setUpEnvironment();
    }
};

TEST_F(LoggedInUsersTest, sanity) {
  auto const rows = execute_query("select * from logged_in_users");
  auto const row_map = ValidatatioMap{
      {"type", NonEmptyString},
      {"user", NormalType},
      {"tty", NormalType},
      {"host", NormalType},
      {"time", NonNegativeInt},
      {"pid", NonNegativeOrErrorInt},
  };
  validate_rows(rows, row_map);
}

} // namespace table_tests
} // namespace osquery
