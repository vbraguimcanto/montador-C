#Montador em C
*Montador da Linguagem Assembly para Linguagem de Máquina*

> #####Exemplo:

#####Entrada via arquivo (_.asm_):

`MOV A,[50]`
`MOV [60],A`
`MOV A,50`
`MOV [61],A`

#####Saída via arquivo (_.opc_):

`a0h`
`50`
`a2h`
`60`
`80h`
`50`
`a2h`
`61`

#####Como Compilar?

`$ gcc arquivo.c`


#####Como executar?

###### No Linux
`$ ./a.out arquivo.asm`

###### No Windows (Prompt de Comando)
`c:\> arquivo.exe arquivo.asm`

