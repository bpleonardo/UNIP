print('-=-= Exercício 1 (soma.py) =-=-')

n1 = int(input('Digite o 1º número: '))
n2 = int(input('Digite o 2º número: '))
soma = n1 + n2
print(f'A soma é {soma}')


print()
print('-=-= Exercício 2 (media.py) =-=-')

n1 = int(input('Digite o 1º número: '))
n2 = int(input('Digite o 2º número: '))
n3 = int(input('Digite o 3º número: '))
media = (n1 + n2 + n3) / 3
print(f'A média é: {media}')


print()
print('-=-= Exercício 3 (paridade.py) =-=-')

n = int(input('Insira um número: '))
if n % 2 == 0:
    print('O número é par!')
else:
    print('O número é ímpar!')

print()
print('-=-= Exercício 4 (maior.py) =-=-')

n1 = int(input('Digite o 1º número: '))
n2 = int(input('Digite o 2º número: '))
if n1 > n2:
    print(f'{n1} é o maior número!')
elif n1 < n2:
    print(f'{n2} é o maior número!')
else:
    print(f'Os números são iguais!')
    
print()
print('-=-= Exercício 5 (sinal.py) =-=-')

n = int(input('Digite um número: '))
if n == 0:
    print('O número é zero!')
elif n < 0:
    print(f'O número é negativo!')
else:
    print(f'O número é positivo!')

print()
print('-=-= Exercício 6 (tabuada.py) =-=-')

n = int(input('Digite um número: '))
for cont in range(1, 11):
    print(f'{n}x{cont} = {n * cont}')

print()
print('-=-= Exercício 7 (soma.py) =-=-')

n = int(input('Digite um número: '))
soma = 0
for cont in range(1, n + 1):
    soma = soma + cont

print(f'A soma é: {soma}')

print()
print('-=-= Exercício 8 (regressivo.py) =-=-')

n = int(input('Digite um número: '))
for cont in range(n, 0, -1):
    print(cont)

print()
print('-=-= Exercício 9 (pares.py) =-=-')

n = int(input('Digite um número: '))
for cont in range(2, n, 2):
    print(cont)

print()
print('-=-= Exercício 10 (fatorial.py) =-=-')

n = int(input('Digite um número: '))
produto = 1
for cont in range(n, 1, -1):
    produto *= cont
print(produto)

print()
print('-=-= Exercício 11 (fibonacci.py) =-=-')

n = int(input('Digite um número: '))
anter = 0
atual = 1
print(anter)
print(atual)
for _ in range(n):
    prox = anter + atual
    print(prox)
    anter = atual
    atual = prox

print()
print('-=-= Exercício 12 (primos.py) =-=-')

n = int(input('Digite um número: '))
soma = 0
# Elevar um número a meio é o mesmo que tirar a raiz quadrada.
for i in range(1, n + 1):
    if n % i == 0:
        soma += 1

if soma == 2:
    print('É primo!')
else:
    print('Não é primo!')
    
print()
