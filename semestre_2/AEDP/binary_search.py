import random
import timeit


def binary_search(array, target) -> int:
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = low + (high - low) // 2

        element = array[mid]

        if element == target:
            return mid

        if target < element:
            high = mid - 1
        else:
            low = mid + 1

    return -1


def linear_search(array, target) -> int:
    for index, element in enumerate(array):
        if element == target:
            return index
    return -1


if __name__ == '__main__':
    size = 200_000

    array = random.sample(range(1, size * 4), size)
    array.sort()
    if size >= 22:
        print(
            f'array = [ {", ".join(map(str, array[:9]))}, ..., {", ".join(map(str, array[-9:]))} ]'
        )
    else:
        print(f'{array = }')

    target = array[random.randint(0, size - 1)]
    print(f'{target = }')

    elapsed = timeit.timeit(
        'binary_search(array, target)', globals=locals(), number=50_000
    )

    print(f'{binary_search(array, target) = }')
    print(f'Média de {elapsed:.2f} segundos')

    elapsed = timeit.timeit(
        'linear_search(array, target)',
        setup='import random; random.shuffle(array)',
        globals=locals(),
        number=50_000,
    )
    print(f'{linear_search(array, target) = }')
    print(f'Média de {elapsed:.2f} segundos')
