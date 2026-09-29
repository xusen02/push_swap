*This project has been created as part of the 42 curriculum by [txu-sen] & [zyeo].*
## Description

`push_swap` is an algorithmic project that challenges you to sort a stack of integers using a restricted set of stack operations with the minimum number of moves.
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
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt) | wc -l

```


*(Target for maximum grade: < 700 operations)*
* **Test with 500 random numbers:**
```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l

```


*(Target for maximum grade: < 5500 operations)*

### sort_method
#### 1. Simple: Greedy algorithm + Insertion sort

##### Explanation
For smaller data sets, a Greedy approach combined with Insertion Sort is simpler.

- Insertion Sort looks at incoming elements and places them into their correct relative positions in the target stack.

- The Greedy component evaluates all possible moves across both stacks to find the cheapest operation (the one requiring the fewest total rotations and pushes) to move the next element into place.

##### Justification
- **Low Overhead:** For very small stacks (such as 3 to 5 elements), complex partitioning strategies add unnecessary overhead and instructions.

- **Precision:** The greedy strategy calculates the exact cost for every single element, ensuring that the minimum number of operations is performed for small inputs, satisfying t_node **strict efficiency criteria for edge cases.

#### 2. Medium: Chunk sort
##### Explanation
For medium-sized stacks (e.g., 100 numbers), Chunk Sort divides the total range of numbers into smaller, manageable segments (chunks) determined dynamically by the square root of the stack size (`chunk_size = ft_sqrt(size)`).

- Partitioning (`chunks_sort`): As the algorithm iterates through stack_a, elements belonging to the current chunk range are pushed to stack_b. Smaller indices within that chunk are pushed and immediately rotated to the bottom of stack_b using rb, keeping the stack partially ordered.

- Reconstruction (`push_back_to_a` & `final_rotate_a`): Once stack_a is empty, `push_back_to_a` finds the maximum index in stack_b, rotates it to the top using the shortest path (top half vs. bottom half optimization), and pushes it back to stack_a. Finally, `final_rotate_a` aligns the smallest element to the top.

##### Justification
- **Optimal Balance:** Chunk sort offers a sweet spot between implementation complexity and operation count. It avoids the heavy calculations of full cost-analysis algorithms while drastically reducing operations compared to naive sorts.

- **Adaptive Sizing:** Using $\sqrt{N}$ (ft_sqrt) ensures that the chunk size scales proportionally with the dataset, preventing stack B from becoming too congested or too sparse.

#### 3. Complex: Radix sort
##### Explanation
For large data sets (e.g., 500 numbers), Radix Sort (specifically binary LSD - Least Significant Digit radix sort) is utilized.

- Assuming all node values are normalized into indices ranging from $0$ to $N-1$, the algorithm inspects the binary representation of each index bit by bit, starting from the least significant bit (bit 0) up to the most significant bit.

- During each bit pass, elements are partitioned: if the bit at the current position is 0, the element is pushed to stack_b (pb); if it is 1, it is kept in stack_a via rotation (ra). Once all elements are checked for that bit, everything in stack_b is pushed back to stack_a (pa).
##### Justification
- **Guaranteed Performance:** Radix sort operates in $O(N \log N)$ time complexity in terms of bit-passes, providing a predictable and stable operation count regardless of how randomized the initial input is.

- **Simplicity and Scalability:** Unlike cost-benefit algorithms that require complex math for every element, Radix relies purely on bitwise operations and basic stack mechanics, making it extremely reliable and easy to scale up to massive inputs without risking timeout or exceeding operation limits.

### 4. Contribution
* **txu-sen:** operation functions and algorithm.

* **zyeo:** algorithm and input parser.
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

* **lastly:** the friends and family weve met along the way
