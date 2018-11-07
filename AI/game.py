import board
import player

class Game:
    
    def __init__(self, player_x, player_o):
        self.player_x = player_x
        self.player_o = player_o
        self.board = board.Board()
        self.winner = None
        self.current_player = True

    def has_player_won(self):
        # check horizontal spaces
        for x in range(board.Board.WIDTH - 3):
            for y in range(board.Board.HEIGHT):
                if self.board.get_value(x, y) == self.board.get_value(x+1, y) == self.board.get_value(x+2, y) == self.board.get_value(x+3, y) != board.Board.EMPTY:
                    self.winner = self.board.get_value(x, y)
                    return True

        # check vertical spaces
        for x in range(board.Board.WIDTH):
            for y in range(board.Board.HEIGHT - 3):
                if self.board.get_value(x, y) == self.board.get_value(x, y+1) == self.board.get_value(x, y+2) == self.board.get_value(x, y+3) != board.Board.EMPTY:
                    self.winner = self.board.get_value(x, y)
                    return True

        # check / diagonal spaces
        for x in range(board.Board.WIDTH - 3):
            for y in range(3, board.Board.HEIGHT):
                if self.board.get_value(x, y) == self.board.get_value(x+1, y-1) == self.board.get_value(x+2, y-2) == self.board.get_value(x+3, y-3) != board.Board.EMPTY:
                    self.winner = self.board.get_value(x, y)
                    return True

        # check \ diagonal spaces
        for x in range(board.Board.WIDTH - 3):
            for y in range(board.Board.HEIGHT - 3):
                if self.board.get_value(x, y) == self.board.get_value(x+1, y+1) == self.board.get_value(x+2, y+2) == self.board.get_value(x+3, y+3) != board.Board.EMPTY:
                    self.winner = self.board.get_value(x, y)
                    return True

        return False

    def is_board_full(self):
        #check is every thing is different than board.EMPTY
        for x in range(board.Board.WIDTH):
            for y in range(board.Board.HEIGHT):
                if self.board.get_value(x, y) == board.Board.EMPTY:
                    return False

        return True


    def start(self):
        # game loop
        while True:
            # play move if legal, else will disqualify the player
            if not self.board.place(self.player_x.play(board) if self.current_player else self.player_o.play(board), self.board.PLAYER_X_PIECE if self.current_player else self.board.PLAYER_O_PIECE):
                print('Player', self.board.PLAYER_X_PIECE if self.current_player else self.board.PLAYER_O_PIECE, 'is disqualified for attempting an illegal move.')
                exit()

            # print board for user
            self.board.draw()
            
            # check is player has won the game
            if self.has_player_won():
                print('Player', self.board.PLAYER_X_PIECE if self.current_player else self.board.PLAYER_O_PIECE, 'has won the game!')
                exit()

            #check if board is full and declare game over if it is
            if self.is_board_full():
                print('Tie : the board is full and no one has won!')
                exit()

            # change player for next turn
            self.current_player = not self.current_player