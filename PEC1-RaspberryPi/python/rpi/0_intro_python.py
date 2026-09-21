# ¡Bienvenido! Este es un archivo de programa Python

# Las líneas que comienzan con un hash (#) son comentarios
# Son para que los leas y Python los ignora

# Cuando veas 'GO!', Guarda y ejecuta el archivo para ver la salida
# Cuando veas una línea que comienza con # sigue las instrucciones
# Algunas líneas son código python con un # delante
# Esto significa que están comentados: elimine el # para descomentar
# ¡Haz un desafío a la vez, salva y ejecuta tras cada uno!

# 1. Esta es la declaración print
print("Hola mundo")

# GO!

# 2. Esta es una variable

message = "Nivel dos"

# Añade una linea debajo para imprimir esta variable 
print (message)
# GO!

# 3. La variable de arriba es una cadena (string)
# Puedes usar comillas sencillas o dobles (pero debes cerrar con las mismas)
# Puedes preguntar a Python qué tipo de variable es. Descomenta la siguiente línea:
print(type(message))
# GO!

# 4. Otro tipo de variable es un número entero (integer)
a = 123
b = 654
c = a + b

# Imprime el valor de c más abajo para ver la respuesta 
# GO!
print c

# 5. Puedes usar otros operadores como la resta (-) y multiplicación (*)
# Mira más abajo algunos ejemplos

print a * b
print b - a
print 12 * 4
print 103 + 999

# GO!

# 6. Variables guardan su valor hasta que lo cambias 

a = 100
# print(a)  # piensa - ¿debería esto ser 123 o 100?

c = 50
# print(c)  # piensa - ¿debería esto ser 50 o 777?

d = 10 + a - c
# print(d)  # piensa - ¿que debería ser ahora?

# GO!

# 7. También puedes usar '+' para concatenar dos cadenas (strings) 

greeting = 'Hola '
name = 'Sergio'  # pon tu nombre en esta cadena 

message = greeting + name
# print(message)

# GO!

# 8. Intenta sumar un número y una cadena y obtendrás un error: 

age =  18 # pon tu edad aquí (aquí como un número )

#print(name + ' tiene ' + age + ' años')

# GO!

# ¿Has visto el error? No puedes mezclar tipos de esa manera.
# Pero ves como te dice en qué línea estaba el error?
# Ahora comenta esa linea para que no haya error

# 9. Podemos convertir números a cadena así:

print(name + ' tiene ' + str(age) + ' años')

# GO!

# No hay error esta vez, espero

# O podriamos asegurarnos de que lo introducimos como cadena:

# age =  # mete tu edad aquí, como una cadena 

# print(name + ' tiene ' + age + ' años')

# GO!

# No hay error esta vez, espero

# 10. Otra tipo de variable es el llamado booleano (boolean)
# Esto quiere decir verdadero (True) o falso (False)

raspberry_pi_is_fun = True
raspberry_pi_is_expensive = False

# Podemos también comparar dos variables cadena usando ==

bobs_age = 15
# your_age =  # rellena de nuevo tu edad

# print(your_age == bobs_age)  # Esto imprime si es True o False

# GO!

# 11. Podemos usar también "menor que" (<)o "mayor que" (>)

# bob_is_older = bobs_age > your_age

# print(bob_is_older)  # ¿Qué esperas True or False?

# GO!

# 12. Podemos hacer preguntas antes de imprimir con una sentencia condicional if 

dinero = 500
coste_telefono = 240
coste_tablet = 200

coste_total = coste_telefono + coste_tablet
puedo_permitirmelo = dinero > coste_total

if puedo_permitirmelo:
    message = "Tienes suficiente dinero para ambos"
else:
    message = "No puedes permitirte ambos dispositivos"

# print(message)  # ¿Qué esperas ver aquí?

# GO!

# Ahora cambia el valor de coste_tablet a 260 y ejecútalo de nuevo
# ¿Qué mensaje debería salir esta vez?

# GO!

# ¿Es esto correcto? Puede ser que necesites cambiar el operador de comparación por  >=
# Esto significa 'mayor o igual que'

raspberry_pi = 25
pies = 3 * raspberry_pi

coste_total = coste_total + pies

if coste_total <= dinero:
    message = "Tienes suficiente dinero para 3 raspberry pies también"
else:
    message = "No puedes permitirte 3 raspberry pies"

# print(message)  # ¿Qué esperas ver aquí?

# GO!

# 13. Puedes almacenar muchos elementos en un tipo de variable llamado lista

colours = ['Red', 'Orange', 'Yellow', 'Green', 'Blue', 'Indigo', 'Violet']

# Puedes comprobar si un color está en la lista 

# print('Black' in colours)  # Imprime True o False

# GO!

# Puedes añadir a la lista con "append"

colours.append('Black')
colours.append('White')

# print('Black' in colours)  # ¿Debería dar esto ahora un resultado distinto?

# GO!

# Puedes añadir una lista a la lista con "extend"

more_colours = ['Gray', 'Navy', 'Pink']

colours.extend(more_colours)

# Intenta imprimir la lista para ver que hay en ella

# GO!

# 14. Puedes añadir 2 listas juntas en una nueva lista usando +

primary_colours = ['Red', 'Blue', 'Yellow']
secondary_colours = ['Purple', 'Orange', 'Green']

main_colours = primary_colours + secondary_colours

# Intenta a imprimir main_colours

# 15. Puedes encontrar cuantos hay con la instrucción len(your_list). Intentalo más abajo

# ¿Cuantos colores hay en main_colours?

# GO!

all_colours = colours + main_colours

# ¿Cuántos colores hay en all_colours?
# Hazlo aquí. Intenta pensar qué esperas obtener antes de ejecutarlo

# GO!

# ¿Obtuviste lo que esperabas? Si no, ¿por que no?

# 16. Puedes asegurarte de que no tienes duplicados añadiendo a un conjunto

even_numbers = [2, 4, 6, 8, 10, 12]
multiples_of_three = [3, 6, 9, 12]

numbers = even_numbers + multiples_of_three
# print(numbers, len(numbers))
numbers_set = set(numbers)
# print(numbers_set, len(numbers_set))

# GO!

colour_set = set(all_colours)
# ¿Cuántos colores esperas esta vez?
# ¿Esperas lo mismo o no? Piensa a cerca de ello primero

# 17. Puedes usar un bucle para revisar todos los items en una lista

my_class = ['Sarah', 'Bob', 'Jim', 'Tom', 'Lucy', 'Sophie', 'Liz', 'Ed']

# Más abajo hay un comentario multilinea
# Borra ''' de antes y después para descomenar el bloque

'''
for student in my_class:
    print(student)
'''

# Añade todos los nombres de gente que quieras en esta linea

# Recuerda la diferencia entre append y extend. Puedes usar cualquiera de ellos.

# Ahora escribe un bucle para imprimir un número (empezando desde el 1) antes de cada nombre

# 18. Puedes dividir una cadena por el índice

full_name = 'Sergio Martin Gutierrez'

first_letter = full_name[0]
last_letter = full_name[19]
first_three = full_name[:3]  # [0:3 también funciona]
last_three = full_name[-3:]  # [17:] y [17:20] también funciona
middle = full_name[8:14]

# Prueba a imprimir estos, y prueba a hacer una palabra con las letras individuales

# 19. Puedes también dividir la cadena por un caracter específico

my_sentence = "Hola, mi nombre es Sergio"
parts = my_sentence.split(',')

# print(parts)
# print(type(parts))  # ¿Qué tipo es esta variable? ¿Qué puedes hacer con ella?

# GO!

my_long_sentence = "Esta es una frase muy muy muy muy muy muy larga"

# Ahora divide la frase y usala para imprimir el número de palabras

# GO! (Pistas debajo si te atascas)

# Pista: ¿Qué tipo de caracter usas para dividir las palabras?
# Pista: ¿Qué tipo es la variable dividida?
# Pista: ¿Qué puedes hacer para contarlas?

# 20. Puedes agrupar datos juntos en una tupla

person = ('Bobby', 26)

# print(person[0] + ' tiene ' + str(person[1]) + ' años')

# GO!

# (name, age)
students = [
    ('Dave', 12),
    ('Sophia', 13),
    ('Sam', 12),
    ('Kate', 11),
    ('Daniel', 10)
]

# Ahora escribe un bucle para imprimir cada uno de los nombres y edad de los estudiantes

# GO!

# 21. Tuplas pueden ser de cualquier longitud. Los ejemplos de arriba son tuplas de 2 elementos.

# Prueba a hacer una lista de estudiantes con (nombre, edad, asignatura favorita y deporte)

# Ahora imprime cada uno de ellos en el bucle

# Ahora elige un número (en el rango de edad de los estudiantes)
# Haz que el bucle solo imprima los estudiantes mayores que ese número

# GO!

# 22. Otra estructura de datos útil es un diccionario

# Diccionarios contienen pares clave-valor como una agenda de teléfonos asocia nombres y teléfonos

addresses = {
    'Lauren': '0161 5673 890',
    'Amy': '0115 8901 165',
    'Daniel': '0114 2290 542',
    'Emergency': '999'
}

# Puedes acceder a los elementos del diccionario buscando por la clave:

# print(addresses['Amy'])

# Puedes comprobar si una clave o valor existen en dicho diccionario:

# print('David' in addresses)  # [False]
# print('Daniel' in addresses)  # [True]
# print('999' in addresses)  # [False]
# print('999' in addresses.values())  # [True]
# print(999 in addresses.values())  # [False]

# GO!

# Fíjate que 999 ha sido introducido en el diccionario como una cadena, no un número entero

# Piensa: ¿qué ocurriría si los números de teléfono fueran almacenados como enteros?

# Prueba a cambiar el número de teléfono de Amy a un nuevo número

# addresses['Amy'] = '0115 236 359'
# print(addresses['Amy'])

# GO!

# Borra Daniel del diccionario

# print('Daniel' in addresses)  # [True]
# del addresses['Daniel']
# print('Daniel' in addresses)  # [False]

# GO!

# Puedes también acceder al contenido de un diccionario iterando en un bucle:

'''
for name in addresses:
    print(name, addresses[name])
'''

# GO!

# 23. Un reto final usando las habilidades que has aprendido:
# ¿Cuál es la suma de todos los dígitos en todos los números del 1 al 1000?

# GO!

# Pista: range(10) => [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# Pista: str(87) => '87'
# Pista: int('9') => 9
