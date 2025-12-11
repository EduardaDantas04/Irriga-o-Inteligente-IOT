// 1. Dados recebidos
var umidade = msg.umidade;
var tempo = msg.payload;   // JSON da API

// 2. Extrai o status principal do clima
var climaPrincipal = (tempo && tempo.weather && tempo.weather[0]) 
    ? tempo.weather[0].main 
    : "API Falhou";

// 3. Regra de decisão inteligente
var comando = "DESLIGAR";

if (umidade < 30 && climaPrincipal !== "Rain" && climaPrincipal !== "Thunderstorm") {
    comando = "LIGAR";
}

// 4. Envio das saídas
var msgBomba = { payload: comando };
var logDecisao = climaPrincipal + " - Decisao: " + comando;

var sql = "INSERT INTO leituras (umidade, previsao_tempo) VALUES (" + 
           umidade + ", '" + logDecisao + "')";

var msgBanco = { topic: sql };

return [msgBomba, msgBanco];
