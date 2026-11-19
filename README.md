# FitAssistant

A C++ console application for meal nutrition calculation and workout tracking. The written
report refers to the project as **FitSync**.

## Features

- **Meal builder** — pick one meat, one carb, and one vegetable with portion sizes, then get
  total protein and calories. Portions can be increased interactively in 100 g steps.
- **Ingredient sorting** — insertion sort by protein or calories, ascending or descending.
- **Calorie-range search** — binary search tree lookup of ingredients within a calorie range.
- **Workout tracker** — stack-based log of calories burned, with undo and history display.

## Build

Requires a C++ compiler with C++11 or later (tested with `g++`).

```bash
make compile
```

This produces the `FitAssistant` binary. To remove it:

```bash
make clean
```

You can also compile directly:

```bash
g++ main.cpp -o FitAssistant
```

## Usage

The program takes a command as its first argument. **Running it with no arguments crashes**,
so always pass one of the commands below.

### 1. Build a meal

```bash
./FitAssistant meal <meat> <meat_qty> <carbs> <carbs_qty> <vegetable> <veg_qty>
```

Each quantity is multiplied by 100, so `3` means 300 g:

```bash
./FitAssistant meal Beef 3 Pasta 5 Broccoli 2
```

After the totals are printed, the program asks whether to increase a portion by 100 g.
Answer `yes` or `no` (then choose `meat`, `carbs`, or `vegetables`).

Ingredient names are **case-sensitive** and use underscores where shown:

| Category | Ingredients |
| --- | --- |
| Meat | `Beef`, `Chicken`, `Crab`, `Duck`, `Lamb`, `Pork`, `Salmon`, `Shrimp`, `Turkey` |
| Carbs | `Bread`, `Brown_Rice`, `Egg_Noodles`, `Jasmine_Rice`, `Oats`, `Pasta`, `Udon`, `White_Rice`, `Black_Rice` |
| Vegetables | `Basil`, `Bell_Peppers`, `Broccoli`, `Carrots`, `Cauliflower`, `Garlic`, `Lettuce`, `Potatoes`, `Tomatoes` |

A misspelled ingredient prints `wrong ... input` and contributes zero to the totals.

### 2. Sort ingredients

```bash
./FitAssistant order <ascending|descending> <protein|calories>
```

Examples:

```bash
./FitAssistant order ascending protein
./FitAssistant order descending calories
```

### 3. Search by calorie range

```bash
./FitAssistant search <min_calories> <max_calories>
```

Example (calories per 100 g):

```bash
./FitAssistant search 100 200
```

### 4. Workout tracker

```bash
./FitAssistant workout
```

This opens an interactive menu:

```text
1. Add workout
2. Undo last
3. View history
0. Exit
```

Entering `1` then a number records calories burned with a timestamp. `2` removes the most
recent entry, `3` prints the stack, and `0` exits.

### Makefile shortcuts

After compiling, these targets run sample commands:

```bash
make AscProt   # order ascending protein
make DesProt   # order descending protein
make AscCal    # order ascending calories
make DesCal    # order descending calories
make meal1     # sample valid meal
make meal2     # sample intentionally misspelled meal
```

## Project structure

| File | Purpose |
| --- | --- |
| `main.cpp` | Entry point, ingredient data, and command dispatch |
| `meat.h`, `carbs.h`, `vegetables.h` | Ingredient classes (name, calories, protein) |
| `meal.h` | Meal calculation and portion-increase prompt |
| `insertion.h` | Insertion-sort functions used by the `order` command |
| `Sort.h` | Unused placeholder header left over from the project template |
| `functions.h` | Generic `display` and `swap` helpers |
| `BST.h` | Binary search tree for calorie-range search |
| `stack.h`, `node.h` | Linked-list stack for workout history |
| `makefile` | Build and sample-command targets |
| `FitAssistant v2.pdf` | Written project report |
| `LICENSE` | MIT license for the source code |

## Known limitations

- Ingredient names must match capitalization and spelling exactly.
- Quantities must be integers and negative values are accepted.
- There is no validation of the number of command-line arguments.
- The `workout` command exits before freeing the dynamically allocated ingredient arrays.

## Report

The complete written report is included in this repository:
[FitAssistant v2.pdf](FitAssistant%20v2.pdf).

## License

The source code is released under the [MIT License](LICENSE). The written report is
included for reference; copyright in the report remains with its authors.

## Project context and team

Group project for **EGCI211: Advanced Computer Programming** at
**Mahidol University International College**, Term 2/2024.

Completed by:

- Guyver Phongsanguanthai (6680580)
- Shazia Huasin (6680689)
- Jonathan Reppert (6680701)
- Wunna Aung Hein (6680715)
