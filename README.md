# Irriga-o-Inteligente-IOT
Sistema de Irrigação Inteligente Baseado em IoT para Agricultura Sustentável

Este repositório apresenta o desenvolvimento de um Sistema de Irrigação Inteligente baseado em IoT, cujo objetivo é otimizar o uso de recursos hídricos a partir do monitoramento automatizado da umidade do solo e do suporte à tomada de decisão por meio de dados meteorológicos.

O projeto foi inteiramente modelado e simulado na plataforma Wokwi, permitindo validar o comportamento do sensor, a transmissão de dados via MQTT e a lógica de automação implementada no Node-RED.


Objetivo do Projeto

O sistema foi desenvolvido com a finalidade de:

Monitorar continuamente a umidade do solo por meio de sensores;

Processar dados transmitidos via MQTT em tempo real;

Integrar uma API de previsão do tempo para evitar acionamentos desnecessários;

Simular o acionamento da irrigação conforme regras de negócio definidas;

Reduzir desperdícios hídricos e promover práticas agrícolas mais eficientes;

Contribuir para iniciativas sustentáveis alinhadas aos ODS 2, 6 e 13 da ONU.



---

Tecnologias e Componentes Utilizados

Wokwi – ambiente de simulação do hardware;

ESP32 – microcontrolador utilizado na simulação;

Sensor de Umidade do Solo (simulado);

Protocolo MQTT – comunicação entre o dispositivo e o servidor;

Node-RED – plataforma para lógica de automação e criação do dashboard;

API OpenWeather – responsável pela coleta dos dados meteorológicos;

Ferramenta de Dashboard – para exibição e análise dos dados coletados.


Arquitetura e Funcionamento

A arquitetura do sistema foi projetada para operar de maneira totalmente integrada:

1. O sensor de umidade (simulado no Wokwi) envia dados contínuos ao ESP32.


2. O ESP32 transmite essas informações ao servidor por meio do protocolo MQTT.


3. O Node-RED recebe os dados e processa a lógica central:

Se a umidade estiver abaixo do limiar estipulado;

E não houver previsão de chuva, conforme dados obtidos na API;

Então o sistema simula a ativação do processo de irrigação.



4. Os dados e resultados passam a ser exibidos em um dashboard analítico para avaliação e validação.



Essa arquitetura permite validar, ainda em ambiente simulado, a eficiência do sistema e sua capacidade de otimizar processos decisórios na agricultura.




Resultados Obtidos

A partir da simulação, foi possível realizar um experimento comparativo entre um cenário de irrigação manual fixa e o modelo inteligente baseado em IoT.

Os principais resultados foram:

Economia de 48,4% no consumo hídrico simulado, evidenciando o potencial da solução;

A irrigação simulada foi acionada apenas quando a umidade atingiu níveis críticos;

Em dias com umidade adequada, o consumo simulado foi zero, demonstrando funcionamento consistente;

A integração com a API meteorológica evitou acionamentos em períodos próximos a chuva;

Os gráficos de consumo, umidade e temperatura apresentados no dashboard confirmaram a eficácia da regra de negócio implementada.


Contribuição aos Objetivos de Desenvolvimento Sustentável

O projeto está alinhado diretamente aos seguintes Objetivos da Agenda 2030:

ODS 2 – Fome Zero e Agricultura Sustentável

ODS 6 – Água Potável e Saneamento

ODS 13 – Ação Contra a Mudança do Clima


A solução visa promover a gestão racional da água por meio da tecnologia, contribuindo para práticas agrícolas mais eficientes.

Considerações Finais

O Sistema de Irrigação Inteligente simulado no Wokwi demonstrou que a combinação de sensores, IoT, automação e dados meteorológicos possibilita reduzir significativamente o consumo hídrico e melhorar o manejo agrícola.

Embora implementado em ambiente virtual, o projeto comprova a viabilidade da solução e estabelece uma base sólida para uma futura implementação física, caso desejado.
