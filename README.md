# push_swap
This project has been created as part of the 42 curriculum by [txu-sen] & [zyeo].
## Description

`push_swap` is an algorithmic project that challenges you to sort a stack of integers using a restricted set of stack operations with the absolute minimum number of moves.
---

## Instructions

### 1. Compilation

Clone the repository and compile using the provided `Makefile`:

```bash
git clone [https://github.com/xusen02/push_swap.git]
cd push_swap
make

```

*Available Makefile rules:* `make`, `make clean`, `make fclean`, `make re`.

### 2. Usage

Run the program by passing space-separated integers as arguments:

```bash
./push_swap 4 67 3 87 23

```

This outputs the sequence of instructions required to sort the stack.

### 3. Testing & Benchmarking

To verify correctness and count operations:

* **Test with 100 random numbers:**
```bash
ARG=\((shuf -i 1-100 -n 100 \vert{} tr '\\n' ' '); ./push_swap\)ARG | wc -l

```


*(Target for maximum grade: < 700 operations)*
* **Test with 500 random numbers:**
```bash
ARG=\((shuf -i 1-500 -n 500 \vert{} tr '\\n' ' '); ./push_swap\)ARG | wc -l

```


*(Target for maximum grade: < 5500 operations)*

---

## Resources

Helpful links, documentation, and conceptual guides for mastering `push_swap`:

* **Algorithmic Guides & Theory:**
* [Big-O Notation & Complexity Analysis](https://en.wikipedia.org/wiki/Big_O_notation)


* **Visualizers & Testing Tools:**
* [Push_swap Visualizer (GitHub)](https://github.com/o-reo/push_swap_visualizer) — Excellent GUI tool to visually debug and watch your algorithm sort stacks.
* [Push_swap Tester (GitHub)](https://github.com/gemartin99/Push-Swap-Tester) — Comprehensive automated stress-tester for 42 students.


* **Official Documentation:**
* 42 Subject PDF (Internal curriculum document detailing error management, edge cases, and mandatory norms).

* the friends and family weve met along the way
