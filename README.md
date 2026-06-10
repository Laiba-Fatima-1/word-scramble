# 🔀 Word Scramble

> Unscramble the word. Beat the clock. Climb the leaderboard.

A console-based word scramble game built in C++ for 1st semester. Race against a countdown timer, use hints wisely, and see how high you can score across three difficulty levels.

---

## 🎮 Features

- **3 Difficulty Levels** — Easy (40s), Medium (30s), Hard (20s) with increasing point rewards
- **Live Timer** — Each round is timed; run out and the answer is revealed
- **3 Attempts Per Word** — Wrong guesses cost you chances, not just points
- **Hint System** — Type `hint` to reveal a clue, but it costs 5 points
- **In-Session Leaderboard** — Tracks cumulative scores across multiple rounds
- **Play Again Loop** — Keep playing without restarting the program
- **File-Based Word Bank** — Words and hints loaded from an external `.txt` file

---

## 🛠️ Tech Stack

| Component | Details |
|-----------|---------|
| Language | C++17 |
| Platform | Cross-platform (standard library only) |
| Word Storage | External `.txt` file |
| Randomness | `<random>` (Mersenne Twister) |
| Timing | `<chrono>` high-resolution clock |

---

## 🚀 Getting Started

### Prerequisites
- Any C++ compiler (g++, MSVC, Clang)

### Build & Run

```bash
# Using g++
g++ WordScramble.cpp -o WordScramble.exe
./WordScramble.exe
```

> ⚠️ Make sure `words.txt` is in the **same directory** as the executable.

---

## 📁 Project Structure

```
word-scramble/
├── WordScramble.cpp    # Main game source code
├── words.txt           # Word bank with hints
└── README.md
```

---

## 📄 Word Bank Format

Each line in `words.txt` follows this format:
```
word A short hint describing the word
```

Example:
```
algorithm A step-by-step procedure for solving a problem
compiler A program that translates code into machine language
recursion A function that calls itself to solve a problem
```

You can add your own words and hints by editing the file directly.

---

## 🎯 How to Play

1. Enter your name
2. Choose a difficulty level (1 = Easy, 2 = Medium, 3 = Hard)
3. A scrambled word appears on screen — type your guess
4. Type `hint` to get a clue (costs 5 points, one hint per word)
5. You have 3 attempts and a time limit per word
6. Scores accumulate across rounds; leaderboard shown at the end

### Scoring

| Difficulty | Points per Word | Time Limit |
|------------|----------------|------------|
| Easy       | 10             | 40 seconds |
| Medium     | 20             | 30 seconds |
| Hard       | 30             | 20 seconds |

> Using a hint deducts 5 points from that word's reward.

---

## 📌 Known Limitations

- Leaderboard resets when the program closes (not saved to file)
- Single player only
- No color output

---

## 🔮 Planned Improvements

- [ ] Save leaderboard to file for persistence across sessions
- [ ] Colored console output for better visual feedback
- [ ] Multiplayer / head-to-head mode
- [ ] Difficulty-based word filtering (short words for easy, long for hard)

---

## 👩‍💻 Author

Built as a 1st semester C++ project.