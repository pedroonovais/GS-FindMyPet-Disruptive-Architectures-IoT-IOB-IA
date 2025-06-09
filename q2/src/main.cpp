#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// Configurações Wi-Fi
const char* SSID = "Wokwi-GUEST";
const char* PASSWORD = "";

// ThingSpeak
WiFiClient client;
unsigned long myChannelNumber = 2982389; // Seu Channel ID
const char* myWriteAPIKey = "WJ6KEZR6X3IPGUKC";

// Sensor DHT
#define DHTPIN 12
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Potenciômetro
const int potPin = 34;

// Simulação de Leitura de Microchip PET
int gerarIDPet() {
  int id;
  for (int i = 0; i < 5; i++) {
    id = random(1000, 9999);
  }
  return id;
}

void conectarWiFi() {
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Conectando ao Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" conectado!");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  conectarWiFi();
  ThingSpeak.begin(client);
  dht.begin();
  delay(1000);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    conectarWiFi();
  }

  // Leitura dos sensores
  int microchipID = gerarIDPet();
  float latitude = -23.55 + random(-100, 100) / 10000.0;   
  float longitude = -46.63 + random(-100, 100) / 10000.0;
  bool emMovimento = random(0, 2);
  
  // Debug e "Painel de Controle" via Serial
  Serial.println("===== Painel de Controle IoT =====");
  Serial.print("ID do Pet: "); Serial.println(microchipID);
  Serial.print("Latitude: "); Serial.println(latitude);
  Serial.print("Longitude: "); Serial.println(longitude);
  Serial.print("Em movimento: "); Serial.println(emMovimento ? "Sim" : "Não");
  Serial.println("===================================");

  // Envio para ThingSpeak
  ThingSpeak.setField(1, latitude);
  ThingSpeak.setField(2, longitude);
  ThingSpeak.setField(3, emMovimento ? 1 : 0); // 1 para em movimento, 0 para parado
  ThingSpeak.setField(4, microchipID); // Aqui armazena o ID como texto

  int status = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if (status == 200) {
    Serial.println("✅ Dados enviados com sucesso!");
  } else {
    Serial.print("❌ Erro ao enviar: ");
    Serial.println(status);
  }

  delay(20000);
}
