# Static Bindgen Build Example

This is an example of building `bindgen` statically using Bazel and `rules_rust`.

- **LLVM Integration**: Uses `libclang_static` directly from the `@llvm-project` repository.
- **Clang-Sys Patching**: The `clang-sys` crate is configured via `crate_universe` to:
    - Disable its default `runtime` feature and enable the `static` one.
    - Skip the `build.rs` script entirely (`gen_build_script = "off"`) to avoid system-level probes.
- **Static Linking**: Utilizes an `alwayslink` `cc_library` wrapper to ensure all `clang_` symbols are preserved in the final binary.
- **Custom CLI Wrapper**: The `third_party/bindgen-cli` directory is forked from [rust-lang/rust-bindgen](https://github.com/rust-lang/rust-bindgen/tree/main/bindgen-cli) because `rules_rust` `crate_universe` integration encountered issues resolving the binary-only `bindgen-cli` crate in Bzlmod's `from_specs` mode.

To build the `bindgen` binary and verify that it statically links `libclang`:

```bash
bazel build //third_party/bindgen-cli:bindgen && \
nm bazel-bin/third_party/bindgen-cli/bindgen | grep "T clang_" | head -n 20
```
