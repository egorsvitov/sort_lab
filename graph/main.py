from matplotlib import pyplot

t = []
n = []
with open('C:\\bootcamp\\2\\merge_sort_output.txt', 'r') as file:
    for line in file.readlines():
        if (line != '\n'):
            x, y = tuple([float(item) for item in line.split()])
            n.append(x)
            t.append(y)

pyplot.plot(n, t)
pyplot.show()
