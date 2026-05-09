# Introducción a la solución

El año del planeta de *ForatNegre* dura exactamente $7 \cdot 10^6$
días, así que cabe un número entero de semanas. Como además todos
los años empiezan en jueves, el día de la semana en el que cae un
día concreto del año $a$ depende solo de $a \bmod 7$. Hay que decir
cuántos días distintos de la semana se celebran (y, si son los $7$,
imprimir `LINEA`).

# La idea

Reservamos un vector de booleanos de tamaño $7$, `dias`. Por cada
fecha de nacimiento $a_i$ marcamos `dias[a_i % 7] = true`. Al
terminar, contamos cuántas posiciones del vector quedaron a `true`.
Si son $7$, salida `LINEA`; si no, el número.

El que el primer día del año caiga en jueves (o en cualquier otro
día) no afecta a la cuenta: solo desplaza la correspondencia entre
el residuo módulo $7$ y el nombre del día, y nosotros solo contamos
residuos distintos.

# Coste

Cada caso es $O(N)$ y el vector es de tamaño constante. Con $t \le
1000$ y $N \le 5000$, el total cabe sobradamente.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [K.cpp](src/K.cpp) | :x: |
