
---

# ✍️ Example doc for your assignment

```markdown
# Game Design Notes

## A) Top-Level Responsibilities

### Board

- Display the game board
- Track game state
- Validate moves
- Update
- Randomize starting state
- Check win condition

### User Input
- Get commands from user
- Parse input
- Handle invalid input
- Allow quit/restart 

### Game Logic
- Main loop
- Check win/lose conditions

---

## B) Structure

### class Board
Implements:
- Display board
- Store state

Members:
- grid
- display()
- update()

---

### class InputHandler
Implements:
- User input

Members:
- getCommand()
- parse()

---

### function main
Implements:
- Game loop

Steps:
1. Initialize board
2. Loop:
   - display
   - get input
   - update state
   - check end condition

---

## C) Helpers

- Position struct (x, y)
- Command enum
- Utility parsing functions
