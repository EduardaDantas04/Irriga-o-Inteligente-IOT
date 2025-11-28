// 1. Recupera os dados
var umidade = msg.umidade; 
var tempo = msg.payload; // JSON da API do tempo

// Tenta pegar a descrição do tempo (se a API falhar, usa um texto padrão)
var descricao = "Sem dados da API";
if (tempo && tempo.weather && tempo.weather[0]) {
    descricao = tempo.weather[0].description;
}

// --- LÓGICA DA INTELIGÊNCIA ---
var comando = "DESLIGAR";

// Se estiver SECO (menos de 30%), manda LIGAR
// (Aqui você pode adicionar && descricao != "rain" se quiser bloquear na chuva)
if (umidade < 30) {
    comando = "LIGAR";
}

// --- SAÍDAS ---

// Saída 1: Manda para a Bomba (ESP32 Atuador)
var msgBomba = { payload: comando };

// Saída 2: Manda para o Banco de Dados (MySQL)
// Salva: Umidade, Clima e a Decisão tomada
var sql = "INSERT INTO leituras (umidade, previsao_tempo) VALUES (" + umidade + ", '" + descricao + " - Decisao: " + comando + "')";
var msgBanco = { topic: sql };

// Envia as duas mensagens
return [msgBomba, msgBanco];
