# CTest GitHub Actions Bug Demo
This is a demonstration for the following GitHub Actions issue:
[GitHub Actions Issue 1206 - CTest Dropped Output](https://github.com/actions/runner/issues/1206)

## Build Instructions
```
git clone https://github.com/jgehrig/ctest-actions-bug.git
cd ctest-actions-bug
cmake -B build
cmake --build build
ctest -VV
```

When the commands above are run, you should see the following output:
```
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: test_demo

1: Test command: ...
1: Test timeout computed to be: 10000000
1: ********* Start testing of TestDemo *********
1: Config: Using QtTest library 5.15.2, Qt 5.15.2 (x86_64-little_endian-lp64 shared (dynamic) release build; by GCC 11.2.1 20220115), gentoo unknown
1: PASS   : TestDemo::initTestCase()
1: PASS   : TestDemo::PassingTestCase()
1: FAIL!  : TestDemo::FailingTestCase() 'false' returned FALSE. ()
1:    Loc: [ctest-actions-bug/test_demo.cpp(19)]
1: PASS   : TestDemo::cleanupTestCase()
1: Totals: 3 passed, 1 failed, 0 skipped, 0 blacklisted, 0ms
1: ********* Finished testing of TestDemo *********
1/1 Test #1: test_demo ........................***Failed    0.00 sec

0% tests passed, 1 tests failed out of 1

Total Test time (real) =   0.00 sec

The following tests FAILED:
          1 - test_demo (Failed)
Errors while running CTest
```

When the same set of steps is run through GitHub Actions, the failure output of `test_demo` is dropped.

Here is an [Actions Log](https://github.com/jgehrig/ctest-actions-bug/runs/5574254973?check_suite_focus=true#step:6:16) with missing output:
```
...
Checking test dependency graph end
test 1
    Start 1: test_demo

    1: Test command: D:\a\ctest-actions-bug\ctest-actions-bug\build\Debug\test_demo.exe
    1: Test timeout computed to be: 10000000                    <==== MISSING OUTPUT BELOW THIS LINE
    1/1 Test #1: test_demo ........................***Failed    0.52 sec

    0% tests passed, 1 tests failed out of 1
...
```
