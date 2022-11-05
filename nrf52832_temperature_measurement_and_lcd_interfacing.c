#include "mbed.h"
#include "pretty_printer.h"
#include <iostream>
#include "ble/BLE.h"
#include "ble/Gap.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <events/mbed_events.h>
#include <ratio>
#include <nrf_temp.h>
#include "NRFLCD.h"

//specify different pins to test printing on UART other than the console UART.
#define TARGET_TX_PIN USBTX
#define TARGET_RX_PIN USBRX


static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 115200);//create a BufferedSerial object to be used by the system I/O retarget code.
FileHandle *mbed::mbed_override_console(int fd) { return &serial_port; }//printf and cout will be redirected to this port.
static uint32_t die_temp;

TextLCD lcd(p12, p13, p14, p15, p16, p17);//RS, EN, D4, D5, D6, D7


void nrf52_die_temperature_read(void)
{
    NRF_TEMP->TASKS_START = 1;//Start temperature measurement
    while (NRF_TEMP->EVENTS_DATARDY == 0) {}
    NRF_TEMP->EVENTS_DATARDY = 0;//Temperature measurement complete, data ready
    die_temp = NRF_TEMP->TEMP ;
    NRF_TEMP->TASKS_STOP = 1;  //Stop temperature measurement
}

int main()
{
    while (true) {
        nrf52_die_temperature_read();
        printf("temperatured = %d \r\n ",nrf_temp_read());
        die_temp = nrf_temp_read()*0.25;//Temperature in °C (0.25° steps)
        printf("die temperatured = %d \r\n ",die_temp);
        lcd.locate(0,0);       
        lcd.printf("Temperature:%d C",die_temp);
        thread_sleep_for(1);
        }
        }

