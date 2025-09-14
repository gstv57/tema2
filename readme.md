# Anotações

Foi utilizado 2x uma regex para capturar o input de nome de cada cidade, sem a utilização estava quebrando o programa por colocar strings possuindo um espaço entre as palavras.

```c
scanf(" %[^\n]", cidade_nome_carta_um);
```