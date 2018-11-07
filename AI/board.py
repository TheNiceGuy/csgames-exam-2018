class Board:

    HEIGHT = 6
    WIDTH = 7

    EMPTY = '.'
    PLAYER_X_PIECE = 'X'
    PLAYER_O_PIECE = 'O'

    def __init__(self):
        self.grid = [[Board.EMPTY for _ in range(Board.HEIGHT)] for _ in range(Board.WIDTH)]

    def draw(self):
        for y in reversed(range(Board.HEIGHT)):
            for x in range(Board.WIDTH):
                print(self.grid[x][y], end=' ')
            print('')
        print('\n')

    def place(self, col_no, player_piece):
        for y in range(Board.HEIGHT):
            if self.grid[col_no][y] == Board.EMPTY:
                self.grid[col_no][y] = player_piece
                return True
        return False

    def get_value(self, x, y):
        return self.grid[x][y]