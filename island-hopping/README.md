# Island Hopping - Kattis

## [The Problem](https://open.kattis.com/problems/islandhopping)

You are a contractor for the small independent nation of Microisles, which is far out in the Pacific ocean, and made up of a large number of islands. The islanders travel between islands on boats, but the government has hired you to design a set of bridges that would connect all the islands together. However, they want to do this at a minimum cost. Cost is proportional to bridge length, so they want to minimize the total length of all bridges put together. You need to decide which bridges should connect which islands.

### Input

The first line contains an integer 1 ≤ 𝑛 ≤ 10. After that, 𝑛 cases follow. Each case starts with a line containing the integer number of islands 1 ≤ 𝑚 ≤ 750, followed by 𝑚 lines each containing the real-valued horizontal and vertical position of a bridge endpoint for the corresponding island. All bridge endpoints are, of course, unique. Each coordinate is in the range [−1000 to 1000] meters and has at most 3 digits past the decimal point.

### Output

For each test case, output the total length of bridges needed to connect all the islands accurate to relative and absolute error of 10^−3 meters.

### Example

**Sample input**

```
2
3
0.0 0.0
0.0 1.0
1.0 0.0
10
30.0 38.0
43.0 72.0
47.0 46.0
49.0 69.0
52.0 42.0
58.0 17.0
73.0 7.0
84.0 81.0
86.0 75.0
93.0 50.0
```

**Sample output**

```
2.000
168.01015709273446
```

## Collaborators

[Mikey Lau](https://github.com/MikeyJL)

[Darius](https://github.com/DariusJA)
