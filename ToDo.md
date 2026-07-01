# ToDo

## Missing Or Risky

- [ ] Fix error exit codes: `error_and_exit()` and `cleanup_and_exit()` currently exit with `0`.
- [ ] Remove `-fsanitize=leak` from `Makefile` before evaluation.
- [ ] Strengthen parser/config validation:
  - [ ] Detect duplicate identifiers.
  - [ ] Require all identifiers exactly once: `NO`, `SO`, `WE`, `EA`, `F`, `C`.
  - [ ] Require exactly 3 RGB values.
  - [ ] Reject non-numeric RGB values.
- [ ] Guard raycasting DDA against out-of-bounds access if validation misses a leak.
- [ ] Clean Norm issues:
  - [ ] Remove `//` comments.
  - [ ] Keep max 5 functions per `.c` file.
  - [ ] Add/fix 42 headers.
- [ ] Compile and test
