# TheBombermanGame

## Description

Bomberman lives in a rectangular grid. Each cell in the grid either contains a bomb or nothing at all.

Each bomb can be planted in any cell of the grid but once planted, it will detonate after exactly 3 seconds. Once a bomb detonates, it's destroyed — along with anything in its four neighbouring cells. This means that if a bomb detonates in cell _i, j_, any valid cells _(i ± 1, j)_ and _(i, j ± 1)_ are cleared. If there is a bomb in a neighbouring cell, the neighbouring bomb is destroyed without detonating, so there's no chain reaction.

Bomberman is immune to bombs, so he can move freely throughout the grid. Here's what he does:

1. Initially, Bomberman arbitrarily plants bombs in some of the cells, the initial state.
2. After one second, Bomberman does nothing.
3. After one more second, Bomberman plants bombs in all cells without bombs, thus filling the whole grid with bombs. No bombs detonate at this point.
4. After one more second, any bombs planted exactly three seconds ago will detonate. Here, Bomberman stands back and observes.
5. Bomberman then repeats steps 3 and 4 indefinitely.

Note that during every second Bomberman plants bombs, the bombs are planted simultaneously (i.e., at the exact same moment), and any bombs planted at the same time will detonate at the same time.

Given the initial configuration of the grid with the locations of Bomberman's first batch of planted bombs, determine the state of the grid after _N_ seconds.

For example, if the initial grid looks like:

```
...
.O.
...
```

It looks the same after the first second. After the second second, Bomberman has placed all his charges:

```
OOO
OOO
OOO
```

In the third second, the bomb in the middle blows up, emptying all surrounding cells:

```
O.O
...
O.O
```

## Returns

- string[r]: n array of strings that represent the grid in its final state

## Input

- The first line contains three space-separated integers _r_, _c_ and _n_. The number of rows, columns and seconds to simulate.
- Each of the next _r_ lines contains a row of the matrix as a single string of _c_ characters. The _._ character denotes an empty cell, and the O character (ASCII 79) denotes a bomb. 
