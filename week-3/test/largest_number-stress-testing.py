import random 

def get_first_digit(n):
    while n >= 10:
        n = n // 10
    return n

def is_better(number, max_number):
    if max_number == -1:
        return True
    option1 = int(str(number) + str(max_number))
    option2 = int(str(max_number) + str(number))
    if option1 > option2:
        return True
    return False


def is_better2(number, max_number):
    # this approach is not correct, fails at some cases, needs to be 
    # improved.
    if max_number == -1:
        return True
    number_first_digit = get_first_digit(number)
    max_number_first_digit = get_first_digit(max_number)
    if number_first_digit > max_number_first_digit:
        return True
    elif number_first_digit == max_number_first_digit:
        if number > max_number:
            return True
        elif number_first_digit % 10 > max_number % 10:
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

def largest_concatenate2(numbers: list, size: int) -> int:
    your_salary = ""
    while len(numbers) != 0:
        max_number = -1
        for i in range(size):
            if is_better2(numbers[i], max_number): 
                max_number = numbers[i]
        your_salary += str(max_number)
        idx = numbers.index(max_number)
        numbers.pop(idx)
        size -= 1
    return your_salary

while(True):
    size = 4
    numbers = [random.randint(1, 22) for i in range(size)]

    # pop operation will be done, so we need two of the lists.
    nums = numbers.copy()
    nums2 = numbers.copy()
    r1 = largest_concatenate(numbers, size)
    r2 = largest_concatenate2(nums2, size)

    print()
    print(size)
    print(nums)
    if r1 != r2:
        print(f"result1: {r1}, result2:  {r2} ... FAILED.")
    else:
        print(f"result: {r1} ... PASSED")

