# String
- _string_ é um vetor de tipo ```char```
  - um vetor organizaza as suas posições de maneira contígua na memória
- sua última posição é indicada pelo __caractere nulo__ ('\0')
  - logo, para uma _string_ de ```n``` bits, são necessárias ```n+1``` posições devido ao caractere nulo

## Inicializando uma string
- uma _string_ pode ser inicializada da mesma forma que qualquer outro tipo de vetor, ou informando a cadeia:
```C
char example[] = {'a', 'b', 'c'};
char example2[] = 'abc';
```

## Obtendo uma string
### ```scanf```
- ```%s``` é o código para formatação de _strings_ em C, sendo que, no ```scanf```, é colocado automaticamente '\0' ao final da variável
- ```scanf``` possui limitações para leitura de _strings_

### ```fgets(endereco, tamanho, arquivo)```
- é a forma mais segura de obter uma _string_
- é informada o endereço de armazenamento, o tamanho máximo e o local de onde a _string_ será obtida

## Limpando _buffer_
- sempre após obter caracteres, é importante limpar o _buffer_ do teclado com ```setbuf(stdin, NULL)```, que é a forma mais eficiente de fazer esta tarefa

## Tratamento de _Strings_
- usando a biblioteca [```string.h```](https://manual.cs50.io/#string.h) é possível realizar várias operações com _strings_