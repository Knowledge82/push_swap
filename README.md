*This project has been created as part of the 42 curriculum by vdarsuye*

> 🇬🇧 [English](README.md) | 🇺🇦 [Українська](README_UK.md) | 🇷🇺 [Русский](README_RU.md) | 🇪🇸 [Español](README_ES.md)

# 🔄 Push_swap

## 📋 Description

**Push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the minimum number of moves possible.

The project consists of two programs:
- **push_swap**:  Generates a sequence of instructions to sort the given stack
- **checker** (bonus): Validates if a sequence of instructions correctly sorts the stack

### The Challenge

You have two stacks: 
- **Stack A**: Contains the initial unsorted integers
- **Stack B**: Initially empty, used as auxiliary storage

You can only use these operations: 

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack A |
| `sb` | Swap the first 2 elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the top element from B to A |
| `pb` | Push the top element from A to B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (last element becomes first) |
| `rrb` | Reverse rotate B (last element becomes first) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

---

## 🧠 Algorithm:  Turk Sort

This implementation uses the **Turk Sort** algorithm, an efficient approach that minimizes the total number of operations. 

### How It Works

#### Phase 1: Push to Stack B (Descending Order)

1. Push the first two elements from A to B
2. For each remaining element in A: 
   - Calculate the **cost** to move it to the correct position in B
   - Cost = rotations needed in A + rotations needed in B
   - Find the element with the **minimum cost**
   - Execute the move (using combined rotations `rr`/`rrr` when possible)
3. B is now sorted in **descending order**

#### Phase 2: Push Back to Stack A

1. Find the **maximum** element in B
2. Rotate B to bring max to the top
3. Push all elements from B to A
4. A is now sorted in **ascending order**

#### Phase 3: Final Rotation

1. Find the position of the minimum element in A
2. Rotate A to bring the minimum to the top

### Cost Calculation

For each element in A, we calculate:
```
cost = cost_a + cost_b
```

Where:
- `cost_a` = rotations to bring element to top of A
- `cost_b` = rotations to bring target position to top of B

**Optimization**: If both rotations are in the same direction, we use `rr` or `rrr` to reduce total moves.

### Complexity

| Stack Size | Operations (approx.) | Requirement |
|------------|---------------------|-------------|
| 3 | ≤ 3 | ≤ 3 |
| 5 | ≤ 8 | ≤ 12 |
| 100 | ≤ 550 | ≤ 700 |
| 500 | ≤ 5000 | ≤ 5500 |

---

## 🛠️ Instructions

### Compilation

```bash
# Compile push_swap
make

# Compile checker (bonus)
make bonus

# Clean object files
make clean

# Full clean (including executables)
make fclean

# Recompile
make re
```

### Usage

#### push_swap

```bash
# Basic usage
./push_swap 3 2 1

# With more numbers
./push_swap 5 2 8 1 9 3 7 4 6

# Using shell to generate random numbers
./push_swap $(seq 1 100 | shuf | xargs)

# Count operations
./push_swap $(seq 1 100 | shuf | xargs) | wc -l
```

#### checker (bonus)

```bash
# Validate push_swap output
./push_swap 3 2 1 | ./checker 3 2 1
# Output: OK

# Manual input (end with Ctrl+D)
./checker 3 2 1 0
rra
pb
sa
rra
pa
# Ctrl+D
# Output: OK or KO

# Test with random numbers
ARG=$(seq 1 100 | shuf | xargs); ./push_swap $ARG | ./checker $ARG
```

### Testing

```bash
# Test 100 random numbers
ARG=$(seq 1 100 | shuf | xargs)
echo "Operations: $(./push_swap $ARG | wc -l)"
./push_swap $ARG | ./checker $ARG

# Test 500 random numbers
ARG=$(seq 1 500 | shuf | xargs)
echo "Operations: $(./push_swap $ARG | wc -l)"
./push_swap $ARG | ./checker $ARG

# Run multiple tests
for i in {1..10}; do
    ARG=$(seq 1 100 | shuf | xargs)
    OPS=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker $ARG)
    echo "Test $i: $OPS operations - $RESULT"
done
```

---

## 📁 Project Structure

```
push_swap/
├── push_swap.c           # Main program entry point
├── checker_bonus.c       # Bonus: checker program
├── checker_utils_bonus.c # Bonus: instruction parsing
├── parsing. c             # Argument parsing and validation
├── stack.c               # Stack creation and management
├── utils.c               # Utility functions
├── check_utils.c         # Input validation
├── sorting.c             # Sorting for small stacks (≤5)
├── turk. c                # Turk sort algorithm
├── cost.c                # Cost calculation
├── cost_utils.c          # Cost utilities
├── move. c                # Move execution
├── op_swap.c             # sa, sb, ss operations
├── op_push.c             # pa, pb operations
├── op_rotate.c           # ra, rb, rr operations
├── op_reverse_rotate.c   # rra, rrb, rrr operations
├── push_swap. h           # Header file
├── Makefile              # Build configuration
├── libft/                # Custom C library
└── README.md             # This file
```

---

## 📚 Resources

### Documentation & Articles

- [Push_swap Tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - Comprehensive guide to the project
- [Turk Algorithm Explanation](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Detailed breakdown of the Turk sort
- [Visualizer](https://github.com/o-reo/push_swap_visualizer) - Helpful tool for debugging

### AI Usage Disclosure

AI (GitHub Copilot) was used in this project for: 

- **Learning & Understanding**: Explaining the Turk sort algorithm concept and optimization strategies
- **Debugging**: Identifying issues in Makefile configuration and linking errors
- **Code Review**: Discussing alternative approaches and best practices
- **Documentation**: Assistance in structuring this README

All code was written, understood, and tested by the author.  AI served as an educational tool and coding assistant, similar to consulting documentation or peer discussions.

---

## 👤 Author

- **Login**:  vdarsuye
- **Campus**: 42 Barcelona

---

## 📄 License

This project is part of the 42 school curriculum and is intended for educational purposes. 
