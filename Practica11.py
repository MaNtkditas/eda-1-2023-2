def decimal_a_binario(numero):
    if numero == 0:
        return '0'
    resultado = ''
    while numero > 0:
        resultado = str(numero % 2) + resultado
        numero //= 2
    return resultado

def recur_fibo(n): 
    if n <= 1: 
        return n
    else:
        return recur_fibo(n-1) + recur_fibo(n-2)

while True:
    menu = """
    Bienvenidos, por favor elija la opción que desee:
    1) Conversión a base dos
    2) Serie de Fibonacci
    3) Salir
    """ 
    print(menu)

    opcion = input('Elija una opción: ')

    if opcion == '1':
        numero = int(input("Ingrese un número para convertir a base dos: "))
        resultado = decimal_a_binario(numero)
        print("El número", numero, "en base dos es:", resultado)
    elif opcion == '2':
        nterms = int(input("Ingrese el número de términos para generar la secuencia de Fibonacci: "))
        if nterms <= 0:
            print("Ingrese un entero positivo")
        else:
            print("Secuencia Fibonacci:")
            for i in range(nterms):
                print(recur_fibo(i))
    elif opcion == '3':
        break
    else:
        print('Debes digitar un número entre 1 y 3')
    print('=-='*20)
