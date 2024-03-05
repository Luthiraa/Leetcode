import java.util.HashSet;
import java.util.Set;
package Hard;
public class Solution {
    private int[] rows = new int[9];
    private int[] cols = new int[9];
    private int[] boxes = new int[9];

    public void solveSudoku(char[][] board) {
        // Initialize the rows, cols, and boxes arrays
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + j / 3;
                    rows[i] |= 1 << num;
                    cols[j] |= 1 << num;
                    boxes[boxIndex] |= 1 << num;
                }
            }
        }

        solve(board);
    }

    private boolean solve(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int boxIndex = (i / 3) * 3 + j / 3;
                    int used = rows[i] | cols[j] | boxes[boxIndex];
                    for (char c = '1'; c <= '9'; c++) {
                        int num = c - '1';
                        if ((used & (1 << num)) == 0) {
                            board[i][j] = c;
                            rows[i] |= 1 << num;
                            cols[j] |= 1 << num;
                            boxes[boxIndex] |= 1 << num;

                            if (solve(board)) {
                                return true;
                            }

                            board[i][j] = '.';
                            rows[i] &= ~(1 << num);
                            cols[j] &= ~(1 << num);
                            boxes[boxIndex] &= ~(1 << num);
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
}
