import sys

def bubblesort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j]['nombre'] > arr[j + 1]['nombre']:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


def añadir_suministros(inventario, suministro):
    inventario.append(suministro)
    return inventario


'''def quitar_suministros(inventario, nombre_suministro):
    for suministro in inventario:
        if suministro["nombre"] == nombre_suministro:
            inventario.remove(suministro)
            break
    return inventario'''


def quitar_suministros(inventario, nombre_producto):
    for suministro in inventario:
        if suministro['nombre'] == nombre_producto:
            inventario.remove(suministro)
            break
    return inventario



def mostrar_inventario(inventario):
    for suministro in inventario:
        print(f"{suministro['nombre']}, Precio: {suministro['precio']}")


def administrarInventario(inventario):
    while True:
        print("\nAdministracion de Inventario\n\nMenu: \n")
        print("1) Agregar suministros")
        print("2) Quitar suministros")
        print("3) Ordenar suministros")
        print("4) Mostrar inventarios")
        print("\n5) Volver al menu principal")

        opc = input("\nIngrese una opción: ")

        if opc == "1":
            nombre = input("Ingresa el suministro de la siguiente manera: Codigo-Nombre (Ejemplo: Agua)\n ")
            precio = float(input("Ingresa el precio del suministro: "))
            suministro = {'nombre': nombre, 'precio': precio}
            añadir_suministros(inventario, suministro)
            #inventario
            print("suministro agregado.")
        elif opc == "2":
            nombre = input("Nombre del suministro a eliminar: ")
            quitar_suministros(inventario, nombre)
            #inventario = 
            print("Producto eliminado.")
        elif opc == "3":
            tienda = bubblesort(inventario)
            print("Suministros ordenados.")
        elif opc == "4":
            if len(inventario) == 0:
                print("Sin inventario.")
            else:
                print("Suministros en inventario:")
                mostrar_inventario(inventario)
        elif opc == "5":
            break
        else:
            print("Por favor, ingrese una opción válida.")


def altas(personal):
    nombre = input("Cual es su nombre: ")
    apellido = input("Dame solo un apellido: ")
    puesto = input("Que puesto ocupara: ")
    codigo_t = input("Codigo de trabajador (ejem. T0000): ")

    persona = {'nombre': nombre, 'apellido': apellido, 'puesto': puesto, 'codigo_t': codigo_t}

    personal.append(persona)
    
    print("Personal contratado.\n")


def bajas(personal):
    nombre = input("Ingrese el nombre de la persona: ")

    encontrado = False

    for i, diccionario in enumerate(personal):
        if diccionario.get('nombre') == nombre:
            personal.pop(i)
            encontrado = True
            break

    if encontrado:
        print("Personal despedido.\n")
    else:
        print("No tenemos dado de alta a dicho persona.\n")


def cambio_puesto(personal):
    nombre = input("Ingrese el nombre de la persona: ")
    nuevo_puesto = input("Ingrese su nuevo puesto: ")

    encontrado = False

    for diccionario in personal:
        if diccionario.get('nombre') == nombre:
            diccionario['puesto'] = nuevo_puesto
            encontrado = True
            break

    if encontrado:
        print("Felicidades a cambiado de puesto.\n")
    else:
        print("No tenemos dado de alta a dicho persona.\n")


def administracionPersonal(personal):
    while True:
        print("\nAdministracion de Personal\n\nMenu: \n")
        print("1) Altas")
        print("2) Bajas")
        print("3) Cambios de puesto")
        print("\n4) Volver al menu principal")

        opc = input("\nIngrese una opción: ")

        if opc == "1":
            altas(personal)
        elif opc == "2":
            bajas(personal)
        elif opc == "3":
            for i in personal:
                print(i)
                print(("\n"))
            cambio_puesto(personal)
        elif opc == "4":
            break
        else:
            print("Por favor, ingrese una opción válida.")


def compra(inventario):
    for suministro in inventario:
        print(f"{suministro['nombre']}, Precio: {suministro['precio']}")


def atencionClientes(inventario):

    carrito = []

    while True:
        print("\nAtención a Clientes\n")
        print("1) Comprar Producto")
        print("2) Quejas")
        print("3) Volver al Menú Principal")

        opc = input("\nIngrese una opción: ")

        if opc == "1":
            '''if len(inventario) == 0:
            print("Sin inventario.")
            else:'''
            print("Suministros en inventario:")
            mostrar_inventario(inventario)
            nombre_producto = input("Ingrese el nombre del producto que desea comprar: ")

                # Buscar el producto en el inventario
            producto = None
            for suministro in inventario:
                if suministro["nombre"] == nombre_producto:
                    producto = suministro
                    break

            if producto is not None:
                # Quitar el producto del inventario
                inventario.remove(producto)
                # Agregar el producto al carrito
                carrito.append(producto)
                print("Producto agregado al carrito.")
            else:
                print("Producto no encontrado.")

            # Calcular el precio total del carrito
            precio_total = sum(suministro["precio"] for suministro in carrito)
            print("Precio total del carrito:", precio_total)

        elif opc == "2":
            print("Opción: Quejas")
            entrada = input("Por favor ingrese el codigo del producto con el que tuvo problemas: ")
            entrada = input("Cual fue el problema: ")
        elif opc == "3":
            break
        else:
            print("Por favor, ingrese una opción válida.")


def menu(intOption):
    inventario = [{'nombre': "Huevos", 'precio': 50}, {'nombre': "Agua", 'precio': 15}, {'nombre': "Jugo", 'precio': 24}]
    personal = [{'nombre': "Alexis", 'apellido': "Martinez", 'puesto': "CEO", 'codigo_t': "T9999"}]

    if intOption == 1:
        administrarInventario(inventario)
    elif intOption == 2:
        atencionClientes(inventario)
    elif intOption == 3:
        administracionPersonal(personal)
    elif intOption == 4:
        print("\nVuelva pronto\n")
        sys.exit()
    else:
        print("Opción no válida.\n")


if __name__ == '__main__':
    while True:
        print("\n---Sistema de Administración de Supermercado---")
        print("\n\tMenu Principal: \n")
        print("\t1) Administracion de inventario\n")
        print("\t2) Atencion a Clientes\n")
        print("\t3) Administracion de Personal\n")
        print("\t4) Salir\n")

        option = int(input("Ingrese una opción: "))

        menu(option)
