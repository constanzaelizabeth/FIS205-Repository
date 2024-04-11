import numpy as np
import matplotlib.pyplot as plt

#Se define el rango de valores para x
x = np.linspace(0, 100, 100)
#Calcula los valores de f(x)
t = 2**x - 1

#Grafica la función
plt.plot(x, t)
plt.title('Tiempo de ejecución en función de la cantidad de anillos')
plt.xlabel('x')
plt.ylabel('t(x)= 2^x -1')
plt.grid(True)
plt.show()
