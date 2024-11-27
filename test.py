import random

def flood_fill(matrix, start_row, start_col, new_char):
    # Get the character to replace
    target_char = matrix[start_row][start_col]

    # If the target_char is already the new_char, do nothing
    if target_char == new_char:
        return

    # Dimensions of the matrix
    rows = len(matrix)
    cols = len(matrix[0])

    # Helper function for the flood-fill process
    def fill(r, c):
        # Base case: check bounds and target match
        if r < 0 or r >= rows or c < 0 or c >= cols or matrix[r][c] != target_char:
            return
        
        # Replace character
        matrix[r][c] = new_char

        # Recursively fill neighboring cells
        fill(r + 1, c)  # Down
        fill(r - 1, c)  # Up
        fill(r, c + 1)  # Right
        fill(r, c - 1)  # Left

    # Start flood-fill
    fill(start_row, start_col)


def generate_matrix(rows, cols):
    """Generates a 2D matrix filled with random 0's and 1's."""
    return [[random.choice([0, 1]) for _ in range(cols)] for _ in range(rows)]


# Main program
if __name__ == "__main__":
    # Generate a random 2D array
    rows = int(input("Enter the number of rows for the matrix: "))
    cols = int(input("Enter the number of columns for the matrix: "))
    matrix = generate_matrix(rows, cols)

    # Display the generated matrix
    print("\nGenerated Matrix:")
    for row in matrix:
        print(row)

    # User input
    start_row = int(input("\nEnter the starting row: "))
    start_col = int(input("Enter the starting column: "))
    new_char = int(input("Enter the new character to replace with (0 or 1): "))

    # Perform flood-fill
    flood_fill(matrix, start_row, start_col, new_char)

    # Display the modified matrix
    print("\nModified Matrix:")
    for row in matrix:
        print(row)
