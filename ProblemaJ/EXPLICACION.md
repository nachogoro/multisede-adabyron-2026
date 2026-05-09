# Introducción a la solución

Por cada boleto $s$ jugado, su premio es la suma sobre todos los
boletos premiados $w$ de la longitud del prefijo común entre $s$ y
$w$. Hay que calcular ese premio para cada boleto vendido y, al
final, sumar todos los premios.

# La idea: contar prefijos

Una observación útil: para un boleto premiado $w$, la longitud del
prefijo común entre $s$ y $w$ se puede expresar como

$$ \mathrm{LCP}(s, w) = \sum_{d=1}^{D} [s[1..d] = w[1..d]] $$

donde $D$ es la longitud de los boletos. Sumando sobre los $m$
boletos premiados,

$$ \mathrm{premio}(s) = \sum_{w}\sum_{d=1}^{D} [s[1..d] = w[1..d]]
   = \sum_{d=1}^{D} \mathrm{cont}(s[1..d]) $$

donde $\mathrm{cont}(p)$ es el número de boletos premiados cuyo
prefijo de longitud $|p|$ coincide con $p$.

Eso reduce el problema a:

1. Construir una tabla $\mathrm{cont}$ que, para cada prefijo
   posible, dé el número de boletos premiados que lo tienen.
2. Para cada boleto vendido, ir avanzando dígito a dígito y sumar el
   contador de cada prefijo.

Esa estructura "prefijo $\to$ contador" es precisamente un *trie* con
una cuenta por nodo. La pregunta es solo cómo implementarlo.

# Implementación: hashmap de prefijos codificados

La forma más directa, sin clases ni nodos explícitos, es un
`unordered_map<long long, int>` indexado por una codificación entera
del prefijo. Como los dígitos son siempre primos $\{2, 3, 5, 7\}$
(cuatro símbolos), cada uno cabe en $2$ bits, y un prefijo de hasta
$30$ dígitos cabe holgadamente en un `long long`.

La codificación arranca en $1$ (un bit "raíz" que evita colisiones
entre prefijos de distinta longitud) y por cada dígito desplaza dos
bits a la izquierda y mete los del dígito:

```
v = 1
para cada dígito c en s:
    v = (v << 2) | índice(c)
```

Así, dos prefijos distintos producen siempre claves distintas en el
*hashmap*.

Por cada boleto premiado, recorremos sus dígitos incrementando
$\mathrm{cont}[v]$ a medida que avanzamos, por cada boleto vendido recorremos
sus dígitos calculando el mismo $v$ y sumando $\mathrm{cont}[v]$. Si en algún
paso $v$ no está en el mapa, paramos: ningún prefijo más largo va a aparecer.

# Variante: trie

Podemos también modelar el problema con un trie:

- Un `vector<array<int, 4>> hijos`, donde la posición $u$ guarda los
  cuatro punteros (índices) a sus hijos por dígito $\{2, 3, 5, 7\}$
  ($0$ = "no hay hijo").
- Un `vector<int> cnt` paralelo con la cuenta de cada nodo.

Cada acceso "bajar al hijo correspondiente al dígito $c$" pasa de
ser un *hash + lookup* a una indexación en arrays contiguos, lo que
acelera bastante la construcción y la consulta. En memoria, además,
gasta menos: cada nodo ocupa $20$ bytes, frente a los $\sim 40$ del
*hashmap* por entrada.

# Variante: trie con consulta encapsulada

En la versión "básica" del trie, el estado de la consulta (el nodo
en curso y el premio acumulado) vive como variables locales del
bucle de `main`. Cada vez que avanzamos un dígito, el llamante tiene
que arrastrar y actualizar esas variables a mano. Una variante más
limpia es darle al trie una pequeña API con estado interno:

- `insertar(s)`: añade el boleto premiado $s$ al trie.
- `reset()`: deja el cursor en la raíz, con premio acumulado $0$.
- `step(c)`: avanza un dígito desde donde estaba; actualiza el
  acumulado sumando `cnt` del nuevo nodo. Si en ese punto no había
  hijo, marca el cursor como "atascado" y los siguientes `step` no
  hacen nada.
- `premio()`: devuelve el acumulado actual.

Para responder un boleto vendido se hace `reset()`, se va alimentando
el trie dígito a dígito con `step(c)`, y al terminar se lee el
`premio()`. Así, el trie no tiene que volver a la raíz ni tenemos que construir
todos los prefijos para las consultas de un boleto comprado.

# Coste

Llamemos $D \le 30$ a la longitud común de los boletos. Tanto la
construcción como las consultas hacen un trabajo lineal en el número
total de dígitos:

- Inserción de los $m$ boletos premiados: $O(m \cdot D)$ operaciones.
- Consulta de los $n$ boletos vendidos: $O(n \cdot D)$ operaciones.

Con $m, n \le 10^5$ y $D \le 30$, son del orden de $6 \cdot 10^6$
operaciones por caso, en ambas implementaciones.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [J.cpp](src/J.cpp)                             | *Hashmap* de prefijos codificados como `long long`. | :x: |
| [J_trie.cpp](src/J_trie.cpp)                   | Trie en arena de nodos con índices. | :x: |
| [J_trie_stateful.cpp](src/J_trie_stateful.cpp) | Trie en arena con `reset` / `step(c)` / `premio()` | :x: |
