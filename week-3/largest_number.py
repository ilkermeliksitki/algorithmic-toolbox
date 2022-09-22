def get_first_digit(n: int) -> int:
    while n >= 10:
        n = n // 10
    return n

def is_better(number: int, max_number: int) -> bool:
    """
    function make a choice about largest possible concatenation between 
    `number` and `max_number`.
    """
    if max_number == -1:
        # `number` is assumed to be positive, so if `max_number` is -1, 
        # it is always better to choose `number`, i.e the function yield
        # True.
        return True
    num_at_left = int(str(number) + str(max_number))
    max_at_left = int(str(max_number) + str(number))
    if num_at_left > max_at_left:
        return True
    return False

def largest_concatenate(numbers: list, size: int) -> int:
    your_salary = ""
    while len(numbers) != 0:
        max_number = -1
        for i in range(size):
            if is_better(numbers[i], max_number):
                max_number = numbers[i]
        your_salary += str(max_number)
        idx = numbers.index(max_number)
        numbers.pop(idx)
        size -= 1
    return your_salary

size = int(input())
numbers = [int(i) for i in input().split()]
print(largest_concatenate(numbers, size))

