# Secure C: A Practical Guide to Safer Embedded Programming

Welcome to *Secure C*, a straight-to-the-point guide for C programmers who work close to the metal. Whether you're writing firmware for a microcontroller or managing memory in a constrained embedded environment, this guide is for you.

The C language is powerful but dangerous. It gives you full control over memory, but one wrong move and you've got buffer overflows, segfaults, or exploitable code. This guide walks through real-world C security issues, how to spot them, and how to fix them without turning your code into an unreadable mess.

---

## Why Security Matters in Embedded C

- Embedded systems often lack runtime protections (like ASLR or memory paging)
- Devices might be deployed for years without updates
- Exploits can affect critical infrastructure, vehicles, or personal data
- Firmware attacks are becoming more common and harder to detect

---

## 🔥 Common C Security Flaws (and How to Not Shoot Yourself in the Foot)

### 1. Buffer Overflows
**Bad:**
```c
char name[8];
gets(name); // BOOM. Never use gets()
```

**Better:**
```c
char name[8];
fgets(name, sizeof(name), stdin);
```

### 2. Format String Vulnerabilities
**Bad:**
```c
printf(user_input); // Attacker controls format string
```

**Better:**
```c
printf("%s", user_input); // Always use format specifiers
```

### 3. Integer Overflows
**Bad:**
```c
uint8_t total = a + b; // if a + b > 255, wraparound
```

**Better:**
```c
if (UINT8_MAX - a < b) handle_overflow();
else uint8_t total = a + b;
```

### 4. Use-After-Free
**Bad:**
```c
free(ptr);
*ptr = 42; // Still using ptr
```

**Better:**
```c
free(ptr);
ptr = NULL;
```

### 5. Unsafe Functions
Avoid:
- `gets()`
- `strcpy()` / `strcat()`
- `sprintf()`
- `scanf("%s")`

Use safer variants:
- `fgets()`
- `strncpy()`
- `snprintf()`
- `sscanf()` with width limits

---

## ⚙️ Embedded-Specific Tips

- Stack size is limited – avoid deep recursion or large stack allocations
- Interrupt Handlers – must be re-entrant and avoid blocking
- No OS means no fallback – there’s no segfault handler
- Watchdog timers – a crash can lock your device. Use watchdog resets
- Avoid dynamic allocation – malloc() and free() are risky on MCUs

---

## 🧪 Tooling: Catch Bugs Before They Bite

### Static Analyzers
- Cppcheck
- Flawfinder
- Clang --analyze

### Compiler Flags (GCC/Clang)
```sh
-fstack-protector-all -D_FORTIFY_SOURCE=2 -Wall -Wextra -Werror
```

### Runtime Tools (for Linux-based dev)
- valgrind
- AddressSanitizer

---

## ✅ Quick Checklist for Secure C

- [ ] Never trust input – always validate
- [ ] Avoid unsafe functions
- [ ] Use length-bounded string ops
- [ ] Check buffer sizes before writing
- [ ] Initialize all memory
- [ ] Zero out secrets before freeing
- [ ] Clear pointers after freeing
- [ ] Use compiler warnings and static analysis

---

## 📚 References
- [MITRE CWE](https://cwe.mitre.org)
- [CERT C Secure Coding](https://wiki.sei.cmu.edu)
- Seacord, R. C. *Secure Coding in C and C++*
- [Clang Static Analyzer](https://clang-analyzer.llvm.org)
- [Cppcheck](http://cppcheck.sourceforge.net/)

---

## 🛠 Coming with the Guide:
This doc is paired with a GitHub repo containing code samples that show each issue in action:

- `/vulnerable/` — insecure versions
- `/secure/` — fixed versions
- Simple Makefile to build and test locally

---

## 📦 GitHub Repository Layout

```
secure-c-guide/
├── Secure_C_Guide.docx      # The written reference guide
├── Makefile                 # Compiles all code samples
├── vulnerable/              # Insecure C code examples
│   ├── buffer_overflow.c
│   ├── format_string.c
│   ├── integer_overflow.c
│   └── use_after_free.c
├── secure/                  # Secure equivalents
    ├── buffer_overflow.c
    ├── format_string.c
    ├── integer_overflow.c
    └── use_after_free.c
```

## 🧪 How to Use

### 🔧 Build Everything
```sh
make
```
This compiles both the secure and vulnerable samples into:
- `vulnerable_demo`
- `secure_demo`

### 🧹 Clean Up
```sh
make clean
```

## 🛡️ Author
Created by **Nathaniel Moore** as a final project for CSC-234: Software Security.

---

Happy hacking — just do it securely.
