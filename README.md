# ⚙️ Custom I/O & Variadic `printf` Implementation

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/Level-Low--Level-orange.svg" alt="Level">
</p>

A lightweight, low-level I/O library written in pure C that bypasses the standard high-level streams (`printf`, `putchar`, `getchar`) to implement a custom formatting engine (`my_printf`). By utilizing hardware-level **System Calls** (`read`/`write`) and **Variadic Arguments** (`<stdarg.h>`), this engine provides platform-agnostic terminal buffer manipulation.

---

## 📌 Table of Contents
- [Core Features](#-core-features)
- [Architectural Deep Dive](#-architectural-deep-dive)
- [Low-Level Component Breakdown](#-low-level-component-breakdown)
- [Variadic Parsing Engine](#-variadic-parsing-engine)
- [Getting Started](#-getting-started)
- [Performance & Footprint Comparison](#-performance--footprint-comparison)
- [License](#-license)

---

## ✨ Core Features

* **Direct System Call Trapping:** Interacts directly with Standard Input (`fd: 0`) and Standard Output (`fd: 1`) without stdio layer buffers.
* **Cross-Platform OS Wrapper:** Dynamically wraps Windows-specific POSIX abstractions (`_write`/`io.h`) and Unix standards (`unistd.h`) via preprocessor macro switches.
* **Stack-Based Argument Parsing:** Manages runtime variable-length arguments natively on the execution stack frame.
* **Zero Allocations ($O(1)$ Space):** Formats integers, characters, and string buffers iteratively without allocating dynamic heap memory (`malloc`).

---

## 🧠 Architectural Deep Dive

Standard formatting utilities inject heavy abstraction layers into executables. This implementation hooks into the kernel's File Descriptor table directly:

```text
[my_printf] ──> [Formatting Engines] ──> [_putchar] ──> System Call (write) ──> Kernel (TTY Driver)