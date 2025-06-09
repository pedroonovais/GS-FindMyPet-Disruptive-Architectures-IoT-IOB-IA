# GS-FindMyPet-Disruptive-Architectures-IoT-IOB-IA
Entrega da GS 1/2025 - Eventos Extremos 

Solução baseada em um IOT que será utilizado para leitura de um microchip de identificação em um animal (pet), implantado sob a pele ou na coleira do animal.

A solução foi integrada com sensores para coletar, processar e exibir os dados em tempo real, utilizando plataformas (Arduino ESP32) e protocolos para a comunicação entre os dispositivos. A solução foi desenvolvida e testada no simulador Wokwi no VSCode.

A solução contém o painel de controle no ThingSpeak para monitorar o dispositivos em tempo real, gerenciando a comunicação entre os dispositivos IoT e o dashboard, incluindo fluxos de processamento, análise e visualização de dados.

A comunicação com o aplicação ocorrerá através de uma API desenvolvida em Python, que irá coletar os dados de identificação do pet (ID), da sua localização (Latitude e Longitude) e a identificação se o pet está parado ou em movimento no momento da coleta dos dados.
