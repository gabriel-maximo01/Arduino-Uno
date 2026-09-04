## Começo de programação em c/c++



\------------------------------------------------------------------------------

# Guia geral da programação Arduino:

\------------------------------------------------------------------------------





#### No geral lembra java:



\_ Usa ponto e vírgula no final das linhas de código

\_abre funções com e fecha assim {};

\_if e else são iguais ao java

\_comentários são assim: /\* pra abrir \*/ pra várias linhas e // pra uma só





#### Suas funções base são:



&#x20;void setup(){}

\_essa funão serve pra vc por dentro tudo oque vc quer que seja feito só uma vez

Exemplo:

declarar uma variável

declarar um pino pra alguma coisa



&#x20;void loop(){}

\_como o nome sugere é pra poder colocae as coisas que você quer que rode mais de uma vez

Exemplo:

uma função que você quer que rode o tempo todo

seu código em geral deve ficar alí





#### Códigos e dicas:



**para "declarar um pino":**

pinMode(número do pino, estado com letra maiúscula);

\-Um pino pode ser de entrada "input" ou saída "output"

\-input é pra falar que o Arduino vai receber algo, tipo o sinal de apertar um botão etc.

\-output é pra dizer que ele vai mandar algo pra lá, como um LED



**para ligar/desligar um pino de saída:**

digitalWrite(número do pino, liga/desliga maiúsculo);

\-isso sendo HIGH pra ligado, LOW pra desligado



para ler uma entrada digital/ analógica:

\-digitalRead(número do pino); ou analogRead(A, numero do pino);

\-isso é pra ver se um botão, sensor etc está recebendo energia(ligado ou não)



**códigos de tempo:**

Eles em geral servem para dar um tempo entre uma ação e outra

delay(tempo em milissegundos)

\-é o mais usado, dá, como o nome diz, um delay, uma pausa pelo tempo que você colocar lá

delayMicroseconds(tempo em microssegundos)

\-esse é igual o delay normal mas em microssegundos que menos que um milissegundo

millis()

\-esse é um cronómetro, começa a marcar o tempo assim que o código começa.





## Variáveis:



**temos três tipos:**

\-globais

\-locais

\-estáticas



**globais**

são aquelas que são declaradas antes mesmo do void setup{} (lá encima do código) e são reconhecidas por todo o programa



**locais**

são as que estão dentro das chaves{}, sejam em funções ou if/else etc, essas variáveis não podem ser usadas fora de onde foram declaradas pois o programa não reconhece



**estáticas**

são tipo as globais mas só funcionam dentro das funções onde foram declaradas



tipos de dados (não são todos) e suas declarações



\_int (inteiro)

int i = 10;



\_char(caractere 'letra')

char letra = 'A'



\_float (numero com virgula)

float valor = 5.4;



\_void (vazia)

void loop() etc, essa serve mais pra falar que uma função não var retornar nada



\_boolean (condicional)

bool condição = false; bool condição = true;



\_string (palavra/frase)

char str\[8] = {qwertyui} é um vetor, então lembra que o 0 conta!





\--------------------------------------------------------------------------------------



## Funções:





**No geral** uma função nada mais é que a forma como você pode dixar o seu código mais limpo e fácil de entender. Com ele você pode por exemplo, programar uma ação de sua escolha que vai ser usada varias vezes ao longo do projeto/programa e assim, sempre que você chama-la ela vai ser executada.





**ela tem dois tipos:**



\-com retorno

Essa vai retornar como o próprio nome diz, algo para a quem a chamou.

exemplo:

int checarSensor{

&#x09;if(alguma coisa){

&#x09;	return 1;}



&#x09;else{

&#x09;	return 2;

}

}



\-sem retorno:

Essa não manda nada de volta, só faz a ação.

exemplo:

void fazAlgo{

faz

}



**OBS**: uma função só é executada uma vez mesmo com void, oque diz quantas vezes ou se vai acontecer sempre a estrutura do seu código, mesmo no loop o Arduino lê a função uma vez, faz tudo e parra para os próximos, ele só volta depois que leu todo o resto do código se você não chamar ele.





\--------------------------------------------------------------------------------------



## If e else:



if(){}, else{} e else if(){} são condicionais e significam se, senão e se senão respectivamente.



**Como se usa** cada **um:**



**if:**

você deve usar o if e a condição dele. Um exemplo seria: se está chovendo, eu uso guarda chuva

EXEMPLO DE CÓdigo:

if(condição){

código aqui

}



**else**:

esse é pra negar, senão esta chovendo, não levo. não usa condição, geralmente se usa no final, como uma última condicional

EXEMPLO DE CÓdigo:

else{

código aqui

}



**else if:**

esse serve mais para otimizar código, digamos que o código entrou em um if que vc colocou, depois que acabar de ler ele, o programa ainda vai ler todos os outros if's que tiverem alí. mas se você colocar um (else if) é como dizer: só se isso não aconteceu faz isso. Ele deve vir sempre depois de um if. e ele deve ter condição.

EXEMPLO DE CÓdigo:

else if(condição){

código aqui

}





\--------------------------------------------------------------------------------------



## Comparações, Booleanos, Incremento e Decremento



**para comparação de valores:**

x==y| igual (se colocar só = é o mesmo que recebe)

x!=y| diferente (tem que ser nessa ordem, se colocar =! dá erro)

x<y | menor que

X>y | maior que

x>=y| maior ou igual à

x<=y| menor ou igual à





**Booleanos:**

são complementos das comparações



\&\& significa e alguma coisa

|| significa ou alguma coisa

Eles são usados para casos de tipo, x==0 \&\& y==2, ele junta comparações



**incremento e decremento:**

são facilitadores de contas



x++  |significa x mais um

x--  |significa x menos um

x-=y |significa x igual a x menos y

x+=y |significa x igual a x mais y

x\*=y |significa x igual a x vezes y

x/=y |significa x igual a x dividido por y



\--------------------------------------------------------------------------------------



## Usando for (para) no Arduino





o for é tipo o loop mas com condição, ele repete determinada ação dentro dele até que essa condição seja atingida



**Exemplo de utilização:**

for (int i = 0; i<=10; i++){

código aqui

}

\-isso basicamente tá falando que é pra repetir tudo oque tá aí dentro dele até que i seja 10, dá pra usar a criatividade dentro dessas condições dependendo de como você quer que funcione.



\--------------------------------------------------------------------------------------



## switch case (escolha de caso)



switch podem ser ditos como portas, pensando nisso o switch case nada mais é que programar a escolha de uma porta



Para funcionar ele precisa de um valor (que é tipo uma chave) e vai testar esse valor em valor em todos os casos (que são tipo as portas) até achar uma que encaixe, e caso não achar, deve ter uma porta coringa (padrão ou default), e ela só é usada em caso de nenhuma ser a certa



**Exemplo de utilização:**



valor = Serial.read("insira um valor"):



switch(valor){

&#x09;case 1:

&#x09;faz algo;

&#x09;break;

&#x09;case 2:

&#x09;faz algo;

&#x09;break;

&#x09;case 3:

&#x09;faz algo;

&#x09;break;

&#x09;default:

&#x09;faz algo;

&#x09;break;

}



**OBS:** só se pode usar ou inteiros, ou caracteres







\--------------------------------------------------------------------------------------





## While (um loop de repetição)



em resumo, ele serve para falar que: **enquanto** algo é verdade faça isso. Assim ele fica no código dentro dele até que se torne falso



**como usar:**



while(condição){

coloca o código

}





Dá pra usar a criatividade pra criar as coisas usando isso, pois a condição poder uma ação física do seu projeto, o valor de uma variável etc.











\--------------------------------------------------------------------------------------



## Referências:



**Vídeo aulas usadas para escrever este arquivo:**



https://youtu.be/sxrlGhDJIPI?si=ep0AOa1cGIp1xwe1



https://youtu.be/3dLz1h6b9Rk?si=Jsl9gx8zTodM-V4p



https://youtu.be/sTe7tPhAMPY?si=\_6LcS4pTf2LMAHuh



https://youtu.be/VytQGECv5FE?si=4e4CjrcQNoaxFgj-



https://youtu.be/F4-w4L8PdeI?si=0YibM4NFdojAXJc7



https://youtu.be/Ea\_iu6hu6f0?si=QUj3juijjO\_quZfr



https://youtu.be/xOggvy4FmDc?si=YSK6iwPREyaxRIcN



https://youtu.be/ddHsD0w7\_1g?si=KrcBTwK9REaTE6rz

