# ⚙️ ft_printf - Custom Variadic Formatting Engine

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/Level-Low--Level-orange.svg" alt="Level">
</p>

A minimal, high-performance subsystem implementation of the standard `printf` library function, strictly aligned with 42 Network standards. By bypassing the standard I/O library (`stdio.h`), this project intercepts the kernel boundary directly using raw input/output **System Calls** (`read`/`write`) and handles dynamic execution stacks via **Variadic Arguments** (`<stdarg.h>`).

---

## 📌 Table of Contents
- [Project Architecture](#-project-architecture)
- [Core Features](#-core-features)
- [File Structure Breakdown](#-file-structure-breakdown)
- [Variadic Parsing Control Flow](#-variadic-parsing-control-flow)
- [Compilation & Execution](#-compilation--execution)

---

## 🧠 Project Architecture

Unlike standard library formatting engines that rely on user-space buffered streams (`stdout`), `ft_printf` communicates directly with the operating system's internal File Descriptor table. Every character sequence flows downstream to a single unbuffered choke point before trapping into Kernel Space.

```text
[ft_printf] ──> [Format Dispatcher] ──> [Type Utilities] ──> [ft_putchar] ──> Syscall (write) ──> Kernel