# Introducción a la solución

Tenemos $T$ instrumentos, cada uno con $c_i$ partes a grabar, y $M$
músicos donde cada uno sabe tocar un subconjunto concreto. En cada
grabación cada músico puede grabar como mucho una parte —
la de uno de sus instrumentos — o no tocar. Queremos el número
mínimo de tomas para grabar todas las partes.

# Caso degenerado: `IMPOSIBLE`

Si algún instrumento $i$ tiene partes que grabar ($c_i > 0$) pero
ningún músico sabe tocarlo, no hay forma de cubrirlo y el caso es
imposible directamente. Lo filtramos antes de meternos en el modelado.

# La idea: búsqueda binaria sobre el número de tomas

Si $R$ tomas son suficientes, $R + 1$ también lo son: basta con no
usar la última. Eso hace que la respuesta sea monótona en $R$, así
que podemos buscarla binariamente. Para un $R$ dado solo hay que
saber decidir si es factible.

# Comprobación de factibilidad: flujo máximo

Fijado $R$, llamemos $x_{j,i}$ al número de partes del instrumento
$i$ que graba el músico $j$. Una asignación válida tiene que cumplir:

- $x_{j,i} = 0$ si $j$ no sabe tocar $i$.
- $x_{j,i} \le R$, porque $j$ no puede tocar dos partes del mismo
  instrumento en la misma toma (a lo sumo, una en cada una de las
  $R$ tomas).
- $\sum_i x_{j,i} \le R$, porque en cada toma $j$ graba como mucho
  una parte.
- $\sum_j x_{j,i} = c_i$, hay que grabar todas las partes de cada
  instrumento.

Con esas reglas, basta con encontrar valores $x_{j,i}$ que las
satisfagan; el calendario por tomas se construiría después. Cada
músico $j$ tiene a lo sumo $R$ partes asignadas y las puede repartir
en $R$ tomas distintas (una por toma). Y dentro de una misma toma,
dos músicos distintos *sí* pueden tocar partes diferentes del mismo
instrumento (el enunciado solo prohíbe que un mismo músico toque
dos partes a la vez), así que no aparece ningún conflicto adicional
al consolidar el calendario.

Las cuatro restricciones anteriores son justo las capacidades de una
red de flujo dirigida. Construimos:

- Una **fuente** $s$ y un **sumidero** $t$.
- Un nodo por cada músico $j = 1, \dots, M$.
- Un nodo por cada instrumento $i = 1, \dots, T$.

Y las siguientes aristas:

| Arista | Capacidad | Significado |
| :----- | :-------: | :---------- |
| $s \rightarrow j$ para cada músico        | $R$   | El músico $j$ graba a lo sumo $R$ partes en total. |
| $j \rightarrow i$ si $j$ sabe tocar $i$  | $R$   | $j$ graba a lo sumo $R$ partes del instrumento $i$ (una por toma). |
| $i \rightarrow t$ para cada instrumento  | $c_i$ | Hay que grabar exactamente $c_i$ partes de $i$. |

El $R$ buscado es factible si y solo si el flujo máximo de $s$ a $t$
iguala $\sum_i c_i$ (todas las partes saturan el sumidero).

# Coste

El grafo tiene a lo sumo $M + T + 2 \le 142$ nodos y unas pocas
miles de aristas, así que cada llamada a Dinic es prácticamente
instantánea. La búsqueda binaria recorre como mucho $\log_2(\sum
c_i) \le \log_2(70 \cdot 10^9) \approx 37$ valores de $R$, así que
cada caso de prueba supone unos pocos cálculos de flujo sobre un
grafo pequeño.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [F.cpp](src/F.cpp) | Búsqueda binaria sobre el número de tomas con comprobación de factibilidad por flujo máximo (Dinic). | :x: |
