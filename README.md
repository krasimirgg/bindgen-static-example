# static `bindgen` build example

This is an example of building `bindgen` statically using Bazel and `rules_rust`.

* uses `libclang_static` directly from the `@llvm-project` repository
* the `clang-sys` crate is customized to use the `static` feature, no build
  script and directly depend on `libclang_static`.
* the `third_party/bindgen-cli` directory is forked from [rust-lang/rust-bindgen](https://github.com/rust-lang/rust-bindgen/tree/main/bindgen-cli) because I had trouble getting it set via with crate universe.

To build the `bindgen` binary and verify that it statically links `libclang`:

```bash
bazel build :bindgen_cli && nm bazel-bin//bindgen_cli | grep "T clang_" | head -n 20
```
