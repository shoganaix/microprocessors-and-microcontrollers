# 1. Print:
print("EXO1")
print("------------------------------------------------------------")
print("Hola mundo")                             # Hola mundo
print("------------------------------------------------------------")

# 2. Variable: [string]
print("EXO2")
print("------------------------------------------------------------")
message = "Nivel dos (dobles)"
message2 = 'Nivel dos (simples)'
print(message)                                  # Nivel dos (dobles)
print(message2)                                 # Nivel dos (simples)
print("------------------------------------------------------------")

# 3. Types of variable:
print("EXO3")
print("------------------------------------------------------------")
print(type(message))                            # str
print(type(message2))                           # str
print("------------------------------------------------------------")

# 4. Variable: [integer]
print("EXO4")
print("------------------------------------------------------------")
a = 123
b = 654
c = a + b
print(type(c))                                  # int
print(c)                                        # 777
print("------------------------------------------------------------")

# 5. Operators: [-] and [*]
print("EXO5")
print("------------------------------------------------------------")
print(a * b)                                    # 80442
print(b - a)                                    # 531
print(12 * 4)                                   # 48
print(103 + 999)                                # 1102
print("------------------------------------------------------------")

# 6. Variables keep their value until stated otherwise:
print("EXO6")
print("------------------------------------------------------------")
a = 100
print(a)                                        # 100
c = 50
print(c)                                        # 50
d = 10 + a - c
print(d)                                        # 60
print("------------------------------------------------------------")

# 7. Use '+' to join strings:
print("EXO7")
print("------------------------------------------------------------")
greeting = 'Hola '
name = 'Shoga'
message3 = greeting + name
print(message3)                                 # Hola Shoga
print("------------------------------------------------------------")

# 8. Printing different variables: [ ERROR ]
print("EXO8")
print("------------------------------------------------------------")
age = 25
# print(name + ' tiene ' + age + ' años')       # ERROR
print("------------------------------------------------------------")

# 9. Casting: [type(var)]
print("EXO9")
print("------------------------------------------------------------")
print(name + ' tiene ' + str(age) + ' años')    # Shoga tiene 25 años

# OR (using only str)
str_age = "25"
print(name + ' tiene ' + str_age + ' años')     # Shoga tiene 25 años
print("------------------------------------------------------------")

# 10. Variable: [boolean]
print("EXO10")
print("------------------------------------------------------------")
raspberry_pi_is_fun = True
raspberry_pi_is_expensive = False
print(raspberry_pi_is_fun)                      # True
print(raspberry_pi_is_expensive)                # False
print("------------------------------------------------------------")

# 11. Comparations: [>], [<] and [==]
print("EXO11")
print("------------------------------------------------------------")
bobs_age = 15
bob_is_older = bobs_age > age
print(bob_is_older)                             # False
print(bobs_age < age)                           # True
print(age == bobs_age)                          # False
print("------------------------------------------------------------")

# 12. Condition: [if]
print("EXO12")
print("------------------------------------------------------------")
dinero = 500
coste_telefono = 240
coste_tablet = 200
caramelito = 61

coste_total = coste_telefono + coste_tablet
puedo_permitirmelo = dinero > coste_total
puedo_permitirmelo_todo = dinero > (coste_total + caramelito)

if puedo_permitirmelo:
    message = "Tienes suficiente dinero para ambos"
else:
    message = "No puedes permitirte ambos dispositivos"

if puedo_permitirmelo_todo:
    message2 = "Sigues teniendo suficiente dinero para todo"
else:
    message2 = "Ahora no puedes permitirtelo"

print(message)                              # Tienes suficiente dinero para ambos
print(message2)                             # Ahora no puedes permitirtelo

raspberry_pi = 25
pies = 3 * raspberry_pi
coste_total = coste_total + pies

if coste_total <= dinero:
    message = "Tienes suficiente dinero para 3 raspberry pies también"
else:
    message = "No puedes permitirte 3 raspberry pies"

print(message)                              # No puedes permitirte 3 raspberry pies
print("------------------------------------------------------------")

# 13. Variable: [list] (in, append and extend)
print("EXO13")
print("------------------------------------------------------------")
colours = ['Red', 'Orange', 'Yellow', 'Green', 'Blue', 'Indigo', 'Violet']
print('Black' in colours)                   # False
colours.append('Black')
colours.append('White')
print('Black' in colours)                   # True
more_colours = ['Gray', 'Navy', 'Pink']
colours.extend(more_colours)
print(colours)                              # ['Red', 'Orange', 'Yellow', 'Green', 'Blue', 'Indigo', 'Violet', 'Black', 'White', 'Gray', 'Navy', 'Pink']
print("------------------------------------------------------------")

# 14. Join list using
print("EXO14")
print("------------------------------------------------------------")
primary_colours = ['Red', 'Blue', 'Yellow']
secondary_colours = ['Purple', 'Orange', 'Green']
main_colours = primary_colours + secondary_colours
print(main_colours)                         # ['Red', 'Blue', 'Yellow', 'Purple', 'Orange', 'Green']
print("------------------------------------------------------------")

# 15. Ext functions: [len(list)]
print("EXO15")
print("------------------------------------------------------------")
all_colours = colours + main_colours
print(len(all_colours))                     # 18

# 16. Ext functions: [set(list)] -> Deletes duplicates
print("EXO16")
print("------------------------------------------------------------")
even_numbers = [2, 4, 6, 8, 10, 12]
multiples_of_three = [3, 6, 9, 12]

numbers = even_numbers + multiples_of_three
print(numbers, len(numbers))                # [2,4,6,8,10,12,3,6,9,12] 10
numbers_set = set(numbers)
print(numbers_set, len(numbers_set))        # {2,3,4,6,8,9,10,12} 8

colour_set = set(all_colours)
print(colour_set)                           # ['Red', 'Orange', 'Yellow', 'Green', 'Blue', 'Indigo', 'Violet', 'Black', 'White', 'Gray', 'Navy', 'Pink', 'Purple']
print(len(colour_set))                      # 13
print("------------------------------------------------------------")

# 17. Loops: [for:]
print("EXO17")
print("------------------------------------------------------------")
my_class = ['Sarah', 'Bob', 'Jim', 'Tom', 'Lucy', 'Sophie', 'Liz', 'Ed']
for student in my_class:
    print(student + '\n')                           # Sarah \n\n Bob \n\n Jim \n\n Tom \n\n Lucy \n\n Sophie \n\n Liz \n\n Ed \n

my_class.append('Pablo')
your_class = ['Maria', 'Belen', 'Elena']
my_class.extend(your_class)                         # ['Sarah', 'Bob', 'Jim', 'Tom', 'Lucy', 'Sophie', 'Liz', 'Ed', 'Pablo', 'Maria', 'Belen', 'Elena']
print(my_class)                             
print('\n')                                         # \n

# Indexed loop
for i in range(1, len(my_class) + 1):
    print(str(i) + ". " + my_class[i - 1] + '\n')   # 1. Sarah \n\n 2. Bob \n\n 3. Jim \n\n 4. Tom \n\n 5. Lucy \n\n 6. Sophie \n\n 7. Liz \n\n 8. Ed \n\n 9. Pablo 10 \n\n Maria 11 \n\n Belen \n\n 12. Elena

print("------------------------------------------------------------")

# 18. Subdivide string using index:
print("EXO18")
print("------------------------------------------------------------")
full_name = 'Sergio Martin Gutierrez'
first_letter = full_name[0]
print(first_letter)                                 # S

last_letter = full_name[19]
print(last_letter)                                  # r

first_three = full_name[:3]
print(first_three)                                  # Ser

last_three = full_name[-3:]
print(last_three)                                   # rez

middle = full_name[8:14]

print('\n')                                         # \n
print(full_name[0])                                 # S
print(full_name[8:9])                               # a
print(full_name[0])                                 # S
print("------------------------------------------------------------")

# 19. Subdivide string using specific chars:
print("EXO19")
print("------------------------------------------------------------")
my_sentence = "Hola, mi nombre es Sergio"
parts = my_sentence.split(',')
print(parts)                                         # ['Hola', ' mi nombre es Sergio']
print(type(parts))                                   # list

my_long_sentence = "Esta es una frase muy muy muy muy muy muy larga"
words = my_long_sentence.split(' ')
print(words)                                         # ['Esta', 'es', 'una', 'frase', 'muy', 'muy', 'muy', 'muy', 'muy', 'muy', 'larga']
print("------------------------------------------------------------")

# 20. Group data in tuple:
print("EXO20")
print("------------------------------------------------------------")
person = ('Bobby', 26)
print(person[0] + ' tiene ' + str(person[1]) + ' años')

students = [
    ('Dave', 12),
    ('Sophia', 13),
    ('Sam', 12),
    ('Kate', 11),
    ('Daniel', 10)
]

for stud in students:
    print(stud[0] + ' tiene ' + str(stud[1]) + ' años') # Bobby tiene 26 años \n...

print("------------------------------------------------------------")

# 21. Tuples with larger sizes:
print("EXO21")
print("------------------------------------------------------------")
f_students = [
    ('Dave', 21, "Maths", "Golf"),
    ('Maria', 25, "Art", "Voleyball"),
    ('Pablo', 24, "Mechanics", "Racing"),
    ('Belen', 20, "Physics", "Running"),
    ('Daniel', 22, "Psychology", "Basketball")
]

for f_stud in f_students:
    print(f_stud[0] + ' is ' + str(f_stud[1]) + ' years old, likes ' + f_stud[2] + ' and ' + f_stud[3]) # Dave is 21 years old, likes Maths and Golf \n...

print('\n')                                             # \n 

for f_stud in f_students:
    if f_stud[1] > 22:
        print(f_stud[0] + ' is older than 22')          # Maria is older than 22 \n Pablo...

print("------------------------------------------------------------")

# 22. Structs: [dictionary] = map in c++
print("EXO22")
print("------------------------------------------------------------")

addresses = {
    'Lauren': '0161 5673 890',
    'Amy': '0115 8901 165',
    'Daniel': '0114 2290 542',
    'Emergency': '999'
}

print(addresses['Amy'])                                 # 0115 8901 165
print('David' in addresses)                             # False
print('Daniel' in addresses.keys())                     # True
print('999' in addresses)                               # False
print('999' in addresses.values())                      # True
print(999 in addresses.values())                        # False (999 as str not int)

addresses['Amy'] = '0115 236 359'
print(addresses['Amy'])                                 # 0115 236 359
print('Daniel' in addresses)                            # True

del addresses['Daniel']
print('Daniel' in addresses)                            # False

for name in addresses:
    print(name, addresses[name])                        # Lauren 0161 5673 890 \n Amy...

print("------------------------------------------------------------")

# 23. Add numbers from 1-1000
print("EXO23")
print("------------------------------------------------------------")
big_numbers = range(1001)
j = -1
for i in big_numbers:
    j = i + j

print(j + 1)                                           # 500500
print("------------------------------------------------------------")