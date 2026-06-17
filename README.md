<div align="center">

# 🔃 push_swap

**Sort a stack of integers using a second stack and a tightly limited instruction set — in as few moves as possible.**

[![Language](https://img.shields.io/badge/C-92.7%25-8E2DE2?style=for-the-badge&logo=c&logoColor=white)](https://github.com/samhq23/Push_swap)
[![42](https://img.shields.io/badge/42-Project-4A00E0?style=for-the-badge)](https://42.fr)
[![Norm](https://img.shields.io/badge/Norminette-passing-B57BFF?style=for-the-badge)](https://github.com/42School/norminette)
[![Checker](https://img.shields.io/badge/Checker-✓%20OK-8E2DE2?style=for-the-badge)](#-verifying-correctness)

</div>

---

## 📌 What it is

`push_swap` is a sorting challenge from the 42 curriculum. You're given a stack `a` of random integers, an empty stack `b`, and **only 11 operations** to move data around. The goal isn't just to sort — it's to sort **efficiently**, producing the shortest possible list of operations.

The grading targets are strict:

| Stack size | Target |
|:----------:|:------:|
| 100 numbers | **< 700** operations |
| 500 numbers | **< 5500** operations |

This implementation comfortably stays under both.

---

## ✨ Highlights

- 🧮 **Cost-based greedy algorithm** on a doubly-linked list — not naïve bubble/selection sort
- 🎯 Computes a **target position** and a **move cost** for every element, then always plays the cheapest move
- 🪶 Hardened parsing: rejects duplicates, non-numbers, and `int` overflow before a single move is made
- 🧪 Ships with the official **checker** and a **visualizer** to prove correctness and watch the sort happen
- 🚫 **Zero leaks** — every allocation is tracked and freed

---

## 🧠 How it works

The stack is modeled as a doubly-linked list, where each node carries the bookkeeping the algorithm needs:

```c
typedef struct s_stack_node
{
    int                 value;
    int                 current_index;   // position in the stack
    int                 cost_a;          // rotations needed on a
    int                 cost_b;          // rotations needed on b
    int                 total_cost;      // combined move cost
    int                 above_median;    // rotate up or down?
    struct s_stack_node *target_node;    // where this node wants to land
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;
```

The sort runs in three phases:

1. **Drain `a` → `b`.** Push the first two elements blindly, then for each remaining element pick the *cheapest* one to move, computing how many rotations each side needs and whether it's faster to rotate up or down.
2. **Sort the base case.** Once only three elements remain in `a`, sort them with a hard-coded optimal sequence.
3. **Drain `b` → `a`.** For every node in `b`, find its **target node** in `a` (the smallest value larger than it, with wrap-around), cost the move on both stacks, and push back the cheapest. Finally, rotate the minimum to the top.

This "find target → cost the move → play the cheapest" loop is what keeps the operation count low.

### The instruction set

| Op | Effect |
|----|--------|
| `sa` `sb` `ss` | swap the top two elements of a / b / both |
| `pa` `pb` | push the top of one stack onto the other |
| `ra` `rb` `rr` | rotate a / b / both up |
| `rra` `rrb` `rrr` | reverse-rotate a / b / both down |

---

## 🚀 Build & run

```bash
# Clone and build
git clone https://github.com/samhq23/Push_swap.git
cd Push_swap
make

# Sort some numbers — prints the operations
./push_swap 4 67 3 87 23

# Count how many operations it took
./push_swap 4 67 3 87 23 | wc -l

# Stress test with 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

## ✅ Verifying correctness

The repo includes the official `checker_linux`. Pipe the operations into it with the same input — `OK` means the stack ends up sorted:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
# → OK
```

There's also a **`push_swap_visualizer`** to watch the algorithm move elements in real time.

---

## 🗂️ Structure

```
Push_swap/
├── inc/push_swap.h          # data structures + prototypes
├── src/
│   ├── Operations/          # the 11 stack operations + sort driver
│   └── Push_swap/           # parsing, cost logic, target finding, init
├── ft_printf/               # custom printf used for output
├── checker_linux            # official correctness checker
├── push_swap_visualizer     # visual demo tool
└── Makefile
```

## 💡 What I took away

Getting from a *correct* sort to an *efficient* one is the whole project. The naïve version is easy; squeezing under 700 moves for 100 numbers forced me to think in terms of move cost, amortized rotations, and choosing a data structure (doubly-linked list) that makes those calculations cheap.

---

<div align="center">

Built by **[Sam](https://github.com/samhq23)** · part of the [42 curriculum](https://github.com/samhq23/42_curriculum)

</div>
