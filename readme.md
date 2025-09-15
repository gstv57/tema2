# Anotações

Foi utilizado 2x uma regex para capturar o input de nome de cada cidade, sem a utilização estava quebrando o programa por colocar strings possuindo um espaço entre as palavras.

```c
scanf(" %[^\n]", cidade_nome_carta_um);
```

# Como executar o programa ?

```bash
# Compilando o programa
gcc super_trunfo.c -o super_trunfo
```

```bash
# Executando o programa caso queira usar inputs manuais
./super_trunfo
```

```bash
# Executando o programa caso queira usar inputs programáticos
./super_trunfo < inputs.txt
```