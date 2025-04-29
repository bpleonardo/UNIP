def conta_vogais(palavra):
    cont = 0
    for c in palavra:
        if c in 'aeiou':
            cont += 1
    return cont


def main():
    palavra = input('Digite uma palavra: ').strip()
    print(f'A palavra tem {conta_vogais(palavra)} vogais!')


if __name__ == '__main__':
    main()
