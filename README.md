*This project has been created as part of the 42 curriculum by acombier, adghouai.*

# push_swap

## Description

**push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the minimum number of moves possible. The project involves two stacks (A and B) and a set of predefined operations to manipulate them.

The goal is to sort stack A in ascending order using the following operations:
- **sa/sb**: Swap the first two elements of stack A/B
- **pa/pb**: Push the top element from one stack to the other
- **ra/rb**: Rotate stack A/B (first element becomes last)
- **rra/rrb**: Reverse rotate stack A/B (last element becomes first)

This implementation features an **adaptive algorithm selection** system that automatically chooses the most efficient sorting strategy based on the input's disorder level.

## Instructions

### Compilation

```bash
# Build the project
make

# Clean object files
make clean

# Full clean (remove executable and libraries)
make fclean

# Rebuild from scratch
make re
```

### Usage

```bash
./push_swap [OPTIONS] <numbers>
```

**Options:**
| Option | Description |
|--------|-------------|
| `--simple` | Force selection-based algorithm |
| `--medium` | Force chunk-based algorithm |
| `--complex` | Force radix sort algorithm |
| `--adaptive` | Use adaptive selection (default) |
| `--bench` | Display performance benchmark |

**Examples:**
```bash
# Basic usage
./push_swap 3 2 1 5 4

# Using quoted string
./push_swap "3 2 1 5 4"

# Force specific algorithm
./push_swap --complex 5 3 1 2 4

# With benchmark output
./push_swap --bench 100 50 25 75 10
```

**Output:**
- Operations are printed to stdout (one per line)
- Errors are printed to stderr as `Error\n`
- Benchmark data (if enabled) is printed to stderr

### Verification

You can verify the output using the provided checker:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms

### Overview

This project implements three distinct sorting algorithms with automatic selection based on input disorder:

| Algorithm | Complexity | Best For |
|-----------|------------|----------|
| Simple (Selection) | O(n²) | Nearly sorted input (disorder < 20%) |
| Medium (Chunk-based) | O(n√n) | Moderate disorder (20% - 50%) |
| Complex (Radix) | O(n log n) | High disorder (> 50%) |

### Algorithm Details and Justification

#### 1. Simple Algorithm (Selection Sort)

**Implementation:** `algorithms/simple_algo.c`

**How it works:**
1. Find the minimum element in stack A
2. Rotate it to the top using the shortest path (ra or rra)
3. Push it to stack B
4. Repeat until stack A is empty
5. Push all elements back to stack A

**Justification:**
- Chosen for nearly-sorted inputs where the overhead of more complex algorithms isn't worth it
- Simple and predictable behavior
- Minimal memory overhead
- When data is already mostly sorted, finding and moving minimums requires fewer operations than restructuring for radix sort

#### 2. Medium Algorithm (Chunk-based Sort)

**Implementation:** `algorithms/medium_algo.c`

**How it works:**
1. Calculate number of chunks: √n (minimum 2)
2. Divide the value range into equal-sized chunks
3. For each chunk, find elements belonging to it and push to stack B
4. Use optimal rotation (ra vs rra) to minimize operations
5. Push elements back from B to A, always selecting the maximum

**Justification:**
- Provides a balance between operation count and algorithmic simplicity
- The √n chunk division minimizes the average distance elements need to travel
- Optimal rotation selection (comparing clockwise vs counter-clockwise distance) reduces wasted moves
- More efficient than selection sort for moderately disordered data
- Simpler to implement correctly than full radix sort while achieving good performance

#### 3. Complex Algorithm (Radix Sort)

**Implementation:** `algorithms/complex_algo.c`

**How it works:**
1. Convert each number to its rank (0 to n-1 based on sorted position)
2. Determine the maximum number of bits needed
3. For each bit position (LSB to MSB):
   - If bit is 0: push element to B
   - If bit is 1: rotate to bottom of A
4. Push all elements from B back to A
5. Repeat for the next bit position

**Justification:**
- Guaranteed O(n log n) time complexity regardless of input distribution
- Performs consistently well on highly randomized data
- Using ranks (0 to n-1) instead of actual values ensures optimal bit usage
- Binary radix sort is ideal for the push_swap constraints because:
  - Each bit pass requires exactly n push/rotate operations
  - Total operations = n × (number of bits) = n × log₂(n)
  - No comparisons needed, only bit checking

### Adaptive Selection

The default behavior analyzes the input's **disorder level** (ratio of inversions to total pairs) and selects the optimal algorithm:

| Disorder Level | Algorithm Selected | Reasoning |
|----------------|-------------------|-----------|
| < 20% | Simple | Few elements out of place; selection sort handles efficiently |
| 20% - 50% | Medium | Moderate reshuffling needed; chunks provide good balance |
| > 50% | Complex | Heavy restructuring needed; radix sort guarantees efficiency |

This adaptive approach ensures optimal performance across different input patterns without requiring manual algorithm selection.

## Resources

### Documentation and References

- [Push_swap Tutorial - A journey to find most efficient sorting algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Chunk Sort Strategy for Push_swap](https://github.com/o-reo/push_swap_visualizer)
- [42 Push_swap Subject PDF](https://cdn.intra.42.fr/pdf/pdf/960/push_swap.en.pdf)
- [Visualizer for Push_swap](https://github.com/o-reo/push_swap_visualizer)

### AI Usage Declaration

AI assistance (Claude) was used in this project for:
- **README Documentation**: Generation of this README file following 42 format requirements
- **Code Review**: Analysis of existing code structure and algorithm implementations
- **Algorithm Explanation**: Help articulating the justification for algorithm choices

No AI was used for:
- Writing the core sorting algorithms
- Implementing stack operations
- Creating the project structure or Makefile
- Writing validation and error handling code

## Authors

- **acombier** - 42 Student
- **adghouai** - 42 Student
