====
TODO
====

- [ ] <++>


- [ ] Create spec for ``engine-lib``.
- [ ] Create spec for ``uci-interface``.
- [ ] Create spec for ``engine``.
- [ ] Create spec for ``tui``.

Diseño
======

Overview
--------

El tablero se representara con una mezcla de un ``mailbox`` y una
``Piece-List``.

Se generaran las jugadas legales, y se usa un algoritmo minimax para determinar
cual de las jugadas se tienen que hacer.

Layout del proyecto
-------------------

Cada proyecto tiene en su documentacion:

* introduction.rst: Con una guia rapida
* spec.rst: Describiendo la interfaz
* Y explicaciones de las cosas que lo necesiten.

engine-lib
  Representacion del tablero, busqueda de jugadas, y evaluacion

uci-interface
  Libreria (single header?) que se puede usar para hacer una interfaz entre
  cualquier motor, y el protocolo uci.

engine
  El ejecutable usando la uci-interface, y el engine-lib, en un futuro puede
  que tome mas interfaces.

tui
  Un programa de terminal que siga el protocolo uci para jugar ajedrez.

engine-lib
~~~~~~~~~~

Tiene que representar al tablero de ajedrez y todas sus reglas. Tiene que poder
generar todas las jugadas legales y evaluar las posiciones que salgan de ella.

Requisitos de la interfaz al exterior:

* 
