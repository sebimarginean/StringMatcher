# Pattern Matching Algorithms in C++

## Overview

This C++ project encompasses two distinct pattern matching algorithms: a Finite Automaton (FA) based matcher and the Knuth-Morris-Pratt (KMP) matcher. These algorithms are designed to efficiently find occurrences of a pattern within a text. 

- **Finite Automaton Matcher**: Builds a transition table based on the given pattern and utilizes this table to scan through the text, matching the pattern.
- **Knuth-Morris-Pratt (KMP) Matcher**: Utilizes a prefix function to efficiently find occurrences of the pattern in the text by avoiding redundant checks.

## Features

- **FA Matcher**:
  - Calculates the transition function for a given pattern.
  - Matches the pattern against a text using the computed transition function.
  
- **KMP Matcher**:
  - Computes the prefix function for the pattern.
  - Utilizes the prefix function to match the pattern against the text.

## Usage

### Compilation

Compile the program using a C++ compiler that supports C++11 or newer standards. For example, using `g++`:

```bash
g++ -std=c++11 main.cpp -o patternMatcher
