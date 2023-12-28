// //NRFLite is used to make communication easy
// //https://github.com/dparson55/NRFLite
// #include <SPI.h>
// #include <NRFLite.h>
// #include "datatypes.h"

// NRFLite controller_radio;
// ControllerPacket controller_packet;

// const static uint8_t CONTROLLER_ID = 1;
// const static uint8_t TANK_BOT_ID = 0;
// const static uint8_t REVCIEVER_ID = 0;
// const static uint8_t RADIO_CE = 10;
// const static uint8_t RADIO_CSN = 9;

// bool radio_init() {
//   return controller_radio.init(CONTROLLER_ID, RADIO_CE, RADIO_CSN);
// }

// void radio_send_joysticks(struct JoyStickValues &packet) {
//   controller_radio.send(REVCIEVER_ID, &packet, sizeof(packet));
// }

// void radio_send_tankbot(struct TankBotPacket &packet) {  
//   controller_radio.send(TANK_BOT_ID, &packet, sizeof(packet));
// }
