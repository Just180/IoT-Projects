// #include <WiFi.h>
// #include "esp_wifi.h"
// #include "esp_netif_sta_list.h"

// const char* ssid = "Ikrom_180";
// const char* password = "123456789";

// WiFiServer server(80);

// unsigned long lastPrintTime = 0;
// const unsigned long interval = 20000;  // 20 seconds

// void printConnectedClients() {
//   wifi_sta_list_t wifi_sta_list;
//   tcpip_adapter_sta_list_t adapter_sta_list;

//   if (esp_wifi_ap_get_sta_list(&wifi_sta_list) == ESP_OK &&
//       tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list) == ESP_OK) {

//     Serial.println("==== Connected Clients ====");
//     for (int i = 0; i < adapter_sta_list.num; i++) {
//       tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];

//       // MAC Address
//       char macStr[18];
//       sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X",
//               station.mac[0], station.mac[1], station.mac[2],
//               station.mac[3], station.mac[4], station.mac[5]);

//       // IP Address
//       IPAddress ip = IPAddress(station.ip.addr);

//       Serial.print("Client ");
//       Serial.print(i + 1);
//       Serial.print(" | MAC: ");
//       Serial.print(macStr);
//       Serial.print(" | IP: ");
//       Serial.println(ip);
//     }
//     if (adapter_sta_list.num == 0) {
//       Serial.println("No clients connected.");
//     }
//     Serial.println("===========================\n");
//   } else {
//     Serial.println("Failed to get client list.");
//   }
// }

// void setup() {
//   Serial.begin(115200);
//   delay(1000);
//   Serial.println("Starting Access Point...");

//   WiFi.softAP(ssid, password);
//   Serial.print("AP IP address: ");
//   Serial.println(WiFi.softAPIP());

//   server.begin();
// }

// void loop() {
//   unsigned long currentMillis = millis();
//   if (currentMillis - lastPrintTime >= interval) {
//     lastPrintTime = currentMillis;
//     printConnectedClients();  // Print clients every 20 seconds
//   }

  

//   // Optional: Handle incoming HTTP clients here (if needed)
// }
