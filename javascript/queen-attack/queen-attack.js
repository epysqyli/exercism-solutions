export class QueenAttack {
  constructor({
    white: [whiteRow, whiteCol] = [7, 3],
    black: [blackRow, blackCol] = [0, 3],
  } = {}) {
    if (whiteRow >= 0 && whiteRow < 8 && whiteCol >= 0 && whiteCol < 8) {
      this.white = [whiteRow, whiteCol];
    } else {
      throw new Error("Queen must be placed on the board");
    }

    if (blackRow >= 0 && blackRow < 8 && blackCol >= 0 && blackCol < 8) {
      this.black = [blackRow, blackCol];
    } else {
      throw new Error("Queen must be placed on the board");
    }

    if (whiteRow == blackRow && whiteCol == blackCol) {
      throw new Error("Queens cannot share the same space");
    }
  }

  get canAttack() {
    if (this.white[0] == this.black[0]) {
      return true;
    } else if (this.white[1] == this.black[1]) {
      return true;
    } else if (this.isDiagonal() == true) {
      return true;
    } else {
      return false;
    }
  }

  isDiagonal() {
    const resX = Math.abs(this.white[0] - this.black[0]);
    const resY = Math.abs(this.white[1] - this.black[1]);
    if (resX == resY) return true;
  }

  toString() {
    const board = [
      "_ _ _ _ _ _ _ _",
      "_ _ _ _ _ _ _ _",
      "_ _ _ _ _ _ _ _",
      "_ _ _ _ _ _ _ _",
      "_ _ _ _ _ _ _ _",
      "_ _ _ _ _ _ _ _",
      "_ _ _ _ _ _ _ _",
      "_ _ _ _ _ _ _ _",
    ];

    const rowModelArray = ["_", "_", "_", "_", "_", "_", "_", "_"];
    const whiteSign = "W";
    const blackSign = "B";

    if (this.white[0] != this.black[0]) {
      let whiteRowArray = [...rowModelArray];
      whiteRowArray[this.white[1]] = whiteSign;
      const whiteRowStr = whiteRowArray.join(" ");

      let blackRowArray = [...rowModelArray];
      blackRowArray[this.black[1]] = blackSign;
      const blackRowStr = blackRowArray.join(" ");

      board.splice(this.white[0], 1, whiteRowStr);
      board.splice(this.black[0], 1, blackRowStr);
    } else {
      let rowArray = [...rowModelArray];
      rowArray[this.white[1]] = whiteSign;
      rowArray[this.black[1]] = blackSign;
      const rowStr = rowArray.join(" ");
      board.splice(this.white[1], 1, rowStr);
    }

    // manage inverted board representation?
    return board.join("\n");
  }
}
