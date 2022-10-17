from matplotlib import pyplot

t1 = []
n1 = []
t2 = []
n2 = []
t3 = []
n3 = []
t4 = []
n4 = []

with open('c:\\users\\egor\\sort_lab\\logs\\bubble_sort_output_vs.txt', 'r') as file:
    for line in file.readlines():
        if (line != '\n'):
            x, y = tuple([float(item) for item in line.split()])
            n1.append(x)
            t1.append(y)


with open('c:\\users\\egor\\sort_lab\\logs\\bubble_sort_output_vso1.txt', 'r') as file:
    for line in file.readlines():
        if (line != '\n'):
            x, y = tuple([float(item) for item in line.split()])
            n2.append(x)
            t2.append(y)

with open('c:\\users\\egor\\sort_lab\\logs\\bubble_sort_output_vso2.txt', 'r') as file:
    for line in file.readlines():
        if (line != '\n'):
            x, y = tuple([float(item) for item in line.split()])
            n3.append(x)
            t3.append(y)

with open('c:\\users\\egor\\sort_lab\\logs\\bubble_sort_output_vsox.txt', 'r') as file:
    for line in file.readlines():
        if (line != '\n'):
            x, y = tuple([float(item) for item in line.split()])
            n4.append(x)
            t4.append(y)


pyplot.plot(n1, t1, color='0')
pyplot.plot(n2, t2, color='r')
pyplot.plot(n3, t3, color='g')
pyplot.plot(n4, t4, color='b')

pyplot.show()
