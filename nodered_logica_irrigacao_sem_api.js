// Estratégia sem chamadas externas para máximo desempenho
var umidade = msg.umidade;
var climaSimulado = "Simulação Local";

var comando = "DESLIGAR";

// Regra básica
if (umidade < 30) {
    comando = "LIGAR";
}

var msgBomba = { payload: comando };
var logDecisao = climaSimulado + " - Decisao: " + comando;

var sql = "INSERT INTO leituras (umidade, previsao_tempo) VALUES (" + 
           umidade + ", '" + logDecisao + "')";

var msgBanco = { topic: sql };

return [msgBomba, msgBanco];
