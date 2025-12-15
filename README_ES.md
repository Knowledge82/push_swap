*Este proyecto ha sido creado como parte del currículum de 42 por vdarsuye*

# 🔄 Push_swap

## 📋 Descripción

**Push_swap** es un proyecto de algoritmos de ordenación que te desafía a ordenar una pila de números enteros usando un conjunto limitado de operaciones con el mínimo número de movimientos posible.

El proyecto consiste en dos programas: 
- **push_swap**:  Genera una secuencia de instrucciones para ordenar la pila
- **checker** (bonus): Valida si una secuencia de instrucciones ordena correctamente la pila

### El Desafío

Tienes dos pilas:
- **Pila A**: Contiene los números enteros iniciales sin ordenar
- **Pila B**: Inicialmente vacía, se usa como almacenamiento auxiliar

Solo puedes usar estas operaciones: 

| Operación | Descripción |
|-----------|-------------|
| `sa` | Intercambiar los primeros 2 elementos de la pila A |
| `sb` | Intercambiar los primeros 2 elementos de la pila B |
| `ss` | Ejecutar `sa` y `sb` simultáneamente |
| `pa` | Mover el elemento superior de B a A |
| `pb` | Mover el elemento superior de A a B |
| `ra` | Rotar la pila A (el primer elemento pasa al final) |
| `rb` | Rotar la pila B (el primer elemento pasa al final) |
| `rr` | Ejecutar `ra` y `rb` simultáneamente |
| `rra` | Rotación inversa de A (el último elemento pasa al principio) |
| `rrb` | Rotación inversa de B (el último elemento pasa al principio) |
| `rrr` | Ejecutar `rra` y `rrb` simultáneamente |

---

## 🧠 Algoritmo: Turk Sort

Esta implementación utiliza el algoritmo **Turk Sort**, un enfoque eficiente que minimiza el número total de operaciones.

### Cómo Funciona

#### Fase 1: Mover a la Pila B (Orden Descendente)

1. Mover los primeros dos elementos de A a B
2. Para cada elemento restante en A: 
   - Calcular el **coste** de moverlo a la posición correcta en B
   - Coste = rotaciones necesarias en A + rotaciones necesarias en B
   - Encontrar el elemento con el **coste mínimo**
   - Ejecutar el movimiento (usando rotaciones combinadas `rr`/`rrr` cuando sea posible)
3. B ahora está ordenada en **orden descendente**

#### Fase 2: Devolver a la Pila A

1. Encontrar el elemento **máximo** en B
2. Rotar B para llevar el máximo arriba
3. Mover todos los elementos de B a A
4. A ahora está ordenada en **orden ascendente**

#### Fase 3: Rotación Final

1. Encontrar la posición del elemento mínimo en A
2. Rotar A para llevar el mínimo arriba

### Cálculo del Coste

Para cada elemento en A, calculamos:
```
coste = coste_a + coste_b
```

Donde:
- `coste_a` = rotaciones para llevar el elemento arriba de A
- `coste_b` = rotaciones para llevar la posición objetivo arriba de B

**Optimización**: Si ambas rotaciones son en la misma dirección, usamos `rr` o `rrr` para reducir el total de movimientos.

### Complejidad

| Tamaño de Pila | Operaciones (aprox.) | Requisito |
|----------------|----------------------|-----------|
| 3 | ≤ 3 | ≤ 3 |
| 5 | ≤ 8 | ≤ 12 |
| 100 | ≤ 550 | ≤ 700 |
| 500 | ≤ 5000 | ≤ 5500 |

---

## 🛠️ Instrucciones

### Compilación

```bash
# Compilar push_swap
make

# Compilar checker (bonus)
make bonus

# Limpiar archivos objeto
make clean

# Limpieza completa (incluyendo ejecutables)
make fclean

# Recompilar
make re
```

### Uso

#### push_swap

```bash
# Uso básico
./push_swap 3 2 1

# Con más números
./push_swap 5 2 8 1 9 3 7 4 6

# Generar números aleatorios con shell
./push_swap $(seq 1 100 | shuf | xargs)

# Contar operaciones
./push_swap $(seq 1 100 | shuf | xargs) | wc -l
```

#### checker (bonus)

```bash
# Validar la salida de push_swap
./push_swap 3 2 1 | ./checker 3 2 1
# Salida: OK

# Entrada manual (terminar con Ctrl+D)
./checker 3 2 1 0
rra
pb
sa
rra
pa
# Ctrl+D
# Salida: OK o KO

# Test con números aleatorios
ARG=$(seq 1 100 | shuf | xargs); ./push_swap $ARG | ./checker $ARG
```

### Pruebas

```bash
# Test con 100 números aleatorios
ARG=$(seq 1 100 | shuf | xargs)
echo "Operaciones: $(./push_swap $ARG | wc -l)"
./push_swap $ARG | ./checker $ARG

# Test con 500 números aleatorios
ARG=$(seq 1 500 | shuf | xargs)
echo "Operaciones: $(./push_swap $ARG | wc -l)"
./push_swap $ARG | ./checker $ARG

# Ejecutar múltiples tests
for i in {1..10}; do
    ARG=$(seq 1 100 | shuf | xargs)
    OPS=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker $ARG)
    echo "Test $i: $OPS operaciones - $RESULT"
done
```

---

## 📁 Estructura del Proyecto

```
push_swap/
├── push_swap.c           # Punto de entrada principal del programa
├── checker_bonus. c       # Bonus: programa checker
├── checker_utils_bonus.c # Bonus: parseo de instrucciones
├── parsing. c             # Parseo y validación de argumentos
├── stack.c               # Creación y gestión de la pila
├── utils.c               # Funciones auxiliares
├── check_utils.c         # Validación de entrada
├── sorting.c             # Ordenación para pilas pequeñas (≤5)
├── turk.c                # Algoritmo Turk sort
├── cost.c                # Cálculo de costes
├── cost_utils.c          # Utilidades de coste
├── move.c                # Ejecución de movimientos
├── op_swap.c             # Operaciones sa, sb, ss
├── op_push.c             # Operaciones pa, pb
├── op_rotate.c           # Operaciones ra, rb, rr
├── op_reverse_rotate. c   # Operaciones rra, rrb, rrr
├── push_swap.h           # Archivo de cabecera
├── Makefile              # Configuración de compilación
├── libft/                # Biblioteca C propia
└── README.md             # Este archivo
```

---

## 📚 Recursos

### Documentación y Artículos

- [Push_swap Tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — Guía completa del proyecto
- [Explicación del Algoritmo Turk](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — Desglose detallado de Turk sort
- [Visualizador](https://github.com/o-reo/push_swap_visualizer) — Herramienta útil para depuración

### Uso de IA

Se utilizó IA (GitHub Copilot) en este proyecto para:

- **Aprendizaje y Comprensión**: Explicación del concepto del algoritmo Turk sort y estrategias de optimización
- **Depuración**: Identificación de problemas en la configuración del Makefile y errores de enlazado
- **Revisión de Código**: Discusión de enfoques alternativos y mejores prácticas
- **Documentación**: Asistencia en la estructuración de este README

Todo el código fue escrito, comprendido y probado por el autor. La IA sirvió como herramienta educativa y asistente de programación, similar a consultar documentación o discusiones con compañeros.

---

## 👤 Autor

- **Login**: vdarsuye
- **Campus**:  42 Barcelona

---

## 📄 Licencia

Este proyecto es parte del currículum de la escuela 42 y está destinado a fines educativos. 
