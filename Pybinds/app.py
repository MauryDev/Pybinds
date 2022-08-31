import fast_mathcpp
import timeit


def F():
    for i in range(10):
        fast_mathcpp.Not(True)

d = True        
def E():
    global d
    for i in range(10):
        d = not(d)

    
c = timeit.timeit(F)

print(c)

c = timeit.timeit(F)

print(c)

