# Introducción a la solución

Buscamos el menor valor $v \ge V$ que cumpla dos condiciones:

- Acaba en $5$ (su última cifra es $5$).
- No acaba en $15$ (sus dos últimas cifras no son $15$, porque
  "quince" no rima con "cinco").

# La idea

Una vez sabemos que solo nos interesan números que acaben en $5$,
no merece la pena ir probando uno a uno desde $V$ subiendo de $1$
en $1$. Saltamos directamente al primer número $\ge V$ que acabe en
$5$ y, a partir de ahí, subimos de $10$ en $10$. De este modo,
cualquier candidato que visitemos cumple ya las dos primeras
restricciones (es $\ge V$ y acaba en $5$) y solo queda esquivar los
finales en $15$.

El punto de partida es

$$ v_0 = \left\lfloor V / 10 \right\rfloor \cdot 10 + 5 $$

Si esa expresión cae por debajo de $V$ (si $V$ acaba en $6, 7, 8$ o $9$),
sumamos $10$ para volver a quedarnos por encima. Después, mientras
$v \bmod 100 = 15$, avanzamos $v \mathrel{+}= 10$. La primera vez que $v$
no acabe en $15$, es la respuesta.

Como mucho damos un salto (uno solo, porque después de un $\ldots15$
viene siempre un $\ldots25$, que sí vale), así que el coste es
$O(1)$.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [E.cpp](src/E.cpp) | :x: |
