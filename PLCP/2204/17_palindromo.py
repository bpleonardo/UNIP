def e_palindromo(palavra):
    # return palavra == palavra[::-1]
    n = len(palavra) - 1
    i = 0
    while n >= 0:
        if palavra[n] != palavra[i]:
            return False
        n -= 1
        i += 1
    return True


def main():
    palavra = input('Digite uma palavra: ').strip()
    if e_palindromo(palavra):
        print(f'"{palavra}" é um palíndromo!')
    else:
        print(f'"{palavra}" não é um palíndromo!')


if __name__ == '__main__':
    main()
