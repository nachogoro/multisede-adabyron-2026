# Introducción a la solución

Tenemos una secuencia de rondas; cada ronda da $|x|$ puntos a uno de
los dos equipos (a nosotros si $x > 0$, al rival si $x < 0$, a nadie
si $x = 0$). Una *partida* arranca en alguna ronda, va sumando
puntos para los dos equipos en paralelo, y termina cuando uno
cualquiera alcanza $T$ puntos: el equipo que llega primero gana esa
partida y la siguiente arranca con marcador $0 - 0$ en la ronda
inmediata posterior.

Podemos elegir libremente la ronda en la que arranca la primera
partida. Hay que decir cuántas partidas seguidas podríamos ganar
nosotros como máximo.

# La idea: DP desde el final

Sea $\mathrm{dp}[i]$ = número máximo de partidas que ganamos
*seguidas* si la primera empieza en la ronda $i$. La recurrencia es
simple:

- Si la partida que empieza en $i$ la ganamos nosotros y termina en
  la ronda $k$, entonces $\mathrm{dp}[i] = 1 + \mathrm{dp}[k + 1]$.
- Si la gana el rival, $\mathrm{dp}[i] = 0$.

La respuesta es $\max_i \mathrm{dp}[i]$.

Como es un cálculo que solo mira hacia delante, conviene rellenar el DP de
derecha a izquierda.

# Detectar quién gana la partida que comienza en $i$

Sólo nos queda ahora, para una posición $i$, calcular eficientemente el
resultado de la primera partida que empieza en $i$, y el número de rondas $k$
que componen esa primera partida para poder aplicar la fórmula.

Siempre podríamos simular la partida procesando ronda a ronda hasta que uno
de los dos equipos alcance $T$ puntos. Pero esto tiene un coste $N$ para
cada posición $i$ consultada, y como debemos consultarlas todas tiene un
coste $O(N^2)$.

Existen dos alternativas que permiten un coste sublineal para cada consulta.

## Opción 1: Búsqueda binaria sobre arrays de sumas prefijas

Sea $a[i]$ la suma de puntos *nuestros* hasta la ronda $i$ y $b[i]$
la suma de puntos del *rival* hasta la ronda $i$. Una partida que
arranca en la ronda $i$ tiene marcador, en la ronda $k \ge i$,

$$ \text{nosotros} = a[k] - a[i-1], \qquad
   \text{rival}    = b[k] - b[i-1]. $$

La partida termina en la ronda $k$ más pequeña en la que alguno de
los dos marcadores cruce $T$. Como $a$ y $b$ son no decrecientes
(cada ronda suma 0 o positivo a una de las dos), encontrar esa $k$
es una *búsqueda binaria*:

- $k_{\text{nuestro}}$ = primer $k \ge i$ con $a[k] \ge a[i-1] + T$.
- $k_{\text{rival}}$   = primer $k \ge i$ con $b[k] \ge b[i-1] + T$.

Ganamos nosotros si $k_{\text{nuestro}} < k_{\text{rival}}$, y la
partida termina en $k_{\text{nuestro}}$. (Las dos $k$ no pueden
coincidir: en una misma ronda solo uno de los dos marcadores puede
cambiar, así que solo uno puede cruzar el umbral por primera vez en
esa ronda.)

Cada consulta cuesta $O(\log N)$.

## Opción 2: Ventana deslizante

La búsqueda binaria nos da $O(\log N)$ por partida, pero podemos
afinar a tiempo amortizado constante. Tanto $k_{\text{nuestro}}$
como $k_{\text{rival}}$ son funciones no decrecientes de $i$: si
adelantamos $i$, los umbrales $a[i-1] + T$ y $b[i-1] + T$ crecen y,
por tanto, los índices donde cada equipo los cruza solo pueden
quedarse o avanzar. Eso nos permite mantener los dos índices como
*punteros* que únicamente avanzan, recorriendo cada uno como mucho
$O(N)$ pasos a lo largo de todo el barrido.

El resultado se vuelca en un solo vector indexado por $i$:

- Si la partida que arranca en $i$ la ganamos, `nextAfterWin[i]`
  es el índice de la ronda donde empieza la siguiente partida:
  exactamente lo que necesita la recurrencia del DP.
- Si la perdemos, `nextAfterWin[i] = -1`.

Con esa convención no hacen falta dos vectores separados (uno con
"quién gana" y otro con "dónde sigue"): el $-1$ codifica el
resultado de derrota, y para el resto de entradas el propio índice
de continuación implica ya que la partida se ha ganado. La
recurrencia queda

$$ \mathrm{dp}[i] = \begin{cases}
0 & \text{si } \mathrm{nextAfterWin}[i] = -1 \\
1 + \mathrm{dp}[\mathrm{nextAfterWin}[i]] & \text{en otro caso}
\end{cases} $$


# Técnica para evitar tratar una partida inacabada de manera especial

Hay un caso especial: si la última partida empieza muy cerca del
final, puede que ningún equipo llegue a $T$ antes de quedarse sin
rondas. Como a efectos prácticos no ganar es lo mismo que perder,
podemos evitar tratarlo aparte añadiendo *dos* rondas centinela
detrás del último dato:

1. En la posición $N + 1$, una ronda que regala $T$ puntos al
   rival.
2. En la posición $N + 2$, una ronda que nos regala $T$ puntos a
   nosotros.

Así, cualquier partida que empiece dentro de los límites $[0, N)$
acabará con un claro vencedor, y no tendremos ninguna partida
inacabada que tratar como caso especial a la hora de definir las
estructuras que nos indican en qué posición acaba cada partida.

Además, obtendremos siempre un valor para $k_{nuestro}$ y
$k_{rival}$, que nos evita tener que lidiar con casos especiales.

# Coste

Con búsqueda binaria, cada $\mathrm{dp}[i]$ cuesta $O(\log N)$, lo
que da $O(N \log N)$ por caso de prueba.

Con la variante de ventana deslizante, los dos punteros barren
$O(N)$ pasos en total y el coste baja a $O(N)$ por caso.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [L_binaria.cpp](src/L_binaria.cpp) | Búsqueda binaria sobre las prefijas. | :x: |
| [L_ventana.cpp](src/L_ventana.cpp) | Ventana deslizante. | :x: |
