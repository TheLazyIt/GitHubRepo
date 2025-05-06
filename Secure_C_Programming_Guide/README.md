# Secure C : A Practical Guide to Better Security in Embedded Programming
Welcome to Secure C, a direct-to-the-point manual for C programmers who code at the hardware level. So whether you are developing firmware for a microcontroller, or managing memory in a low power embedded environment, this guide has something for you!
C is a powerful but dangerous language. It's all this wonderful memory control, but a false move and boom, you've got buffer overflows, segfaults, or straight up exploit code. The guide covers real-world security problems from C, how to find them, and how to solve them without turning your code into spaghetti.
Importance of Security in Embedded C
- Embedded systems often lack runtime protections (like ASLR or memory paging)
- Devices might be deployed for years without updates
- Exploits can affect critical infrastructure, vehicles, or personal data
- Firmware attacks are becoming more common and harder to detect
🔥 Common C Security Bugs (and How to Not Shoot Yourself in the Foot)
1. Buffer Overflows
Bad:
char name[8];
gets(name); // BOOM. Never use gets()
Better:
char name[8];
fgets(name,sizeof(name),stdin);
2. Format String Vulnerabilities
Bad:
printf(user_input); // Attacker can control the format string
Better:
printf("%s", user_input); // Print formatting is very important. Always use format specifiers
3. Integer Overflows
Bad:
uint8_t total = a + b; // if a + b > 255 then wraps round.
Better:
if ( UINT8_MAX - a < b ) handle_overflow();
else uint8_t total = a + b;
4. Use-After-Free
Bad:
free(ptr);
*ptr = 42; // Still using ptr
Better:
free(ptr);
ptr = NULL;
5. Unsafe Functions
Avoid:
gets()
strcpy() / strcat()
sprintf()
scanf("%s")
Use safer variants:
fgets()
strncpy()
snprintf()
sscanf() with width limits
⚙️ Embedded-Specific Tips
    – Stack size is limited – don’t do a lot of recursion or stack allocation
    - Stack size is limited – avoid deep recursion or large stack allocations
    - Interrupt Handlers – must be re-entrant and avoid blocking
    - No OS means no fallback – there’s no segfault handler
    - Watchdog timers – a crash can lock your device. Use watchdog resets
    - Avoid dynamic allocation – malloc() and free() are risky on MCUs
🧪 Tooling: Catch Bugs Before They Bite 👉 newrepository A statically-typed superset of JavaScript that adds an optional type system!
Static Analyzers
    - Cppcheck
    - Flawfinder
    - Clang --analyze
Compiler Flags (GCC/Clang)
-fstack-protector-all -D_FORTIFY_SOURCE=2 -Wall -Wextra -Werror
Runtime Tools (for Linux-based dev)
    - valgrind
    - AddressSanitizer

✅ Quick Checklist for Secure C
[ ] Never trust input – always validate/csrf protect cookie/header etc.
[ ] Avoid unsafe functions
[ ] Benefits from Len-bounded string ops
[ ] Ensure buffer size before writing out the same measurements from the same sensor.
[ ] Initialize all memory
[ ] Before freeing, zero out secrets.
[ ] Clean pointers after free and after close.
[ ] Leverage compiler warnings and static analysis
📚 References
MITRE CWE (https://cwe.mitre.org)
CERT C Secure Coding (https://wiki.sei.cmu.edu)
Seacord, R. C. Secure Coding in C and C++
Clang Static Analyzer (https://clang-analyzer.llvm.org)
Cppcheck (cppcheck.sourceforge.net/)
🛠 Coming with the Guide:
This doc is associated with a GitHub repo that lists code samples to show every issue in action:
/vulnerable/ — insecureVersions
/secure/ — fixed versions
Easy Makefile to build and test it locally
Happy hacking — find a way to hack, and do it securely.

