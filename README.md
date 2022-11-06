# Temperature Measuring Without Any Sensors in NRF52832

![alt text](https://hackster.imgix.net/uploads/attachments/1518006/img20221105190824_mSZ69Mb9fr.jpg?auto=compress%2Cformat&w=740&h=555&fit=max)

In this project, we have made a circuit that is capable of measuring its surrounding temperature withour using any additional sensor. When you want to measure the temperature of the surroundings while developing Bluetooth low-energy projects you require an external temperature sensor. implementing external sensors increases the BOM Cost and requires a bit more space. you can avoid these problems by using NRF52832 for your BLE Projects.
In this project, I am measuring the temperature using NRF52DK And displaying the temperature on the LCD Display. For developing the firmware I have used the Arm Mbed.

![alt text](https://hackster.imgix.net/uploads/attachments/1518018/image_4JoSZ5OirI.png?auto=compress%2Cformat&w=740&h=555&fit=max)

The nRF52 Development Kit is a single-board development kit for Bluetooth Smart, ANT, and 2.4GHz proprietary applications using the nRF52 Series SoC. This kit supports both developments for nRF52832 SoCs. The kit is compatible with the Arduino Uno Revision 3 standard, making it possible to use third-party shields that are compatible with this standard with the kit.
The kit supports the standard Nordic Software Development Toolchain using Keil, IAR, and GCC. The kit also supports ARM mbed tool-chain for rapid prototyping and development using mbed’s cloud-based IDE and tool-chain with an extensive range of open-source software libraries. Program/Debug options on the kit are Segger J-Link Lite for the standard toolchain and CMSIS-DAP for mbed. The kit gives access to all I/O and interfaces via connectors and has 4 LEDs and 4 buttons which are user-programmable. A range of software examples is available from the nRF5 SDK to support Bluetooth Smart, ANT, and 2.4GHz applications.

![alt text](https://hackster.imgix.net/uploads/attachments/1518009/bd_fXAfR4sKOV.jpg?auto=compress%2Cformat&w=740&h=555&fit=max)

NRF52832 Contains an internal temperature sensor with 0.25 °Celcius Resolution. it can measure the die temperature over the temperature range of the device. Linearity compensation can be implemented if required by the application.

Main Features of the temperature sensor

The temperature range is greater than or equal to the device's operating temperature.
The resolution is 0.25 degrees
TEMP register stores measured temperature values, the following steps need to be used while developing firmware.

1. Enable the TASKS_START Register to Start temperature measurement.

2. Check EVENTS_DATARDY Register Temperature measurement complete, data ready

3. Collect the Temperature details from theTEMP register.

The temperature is °C (0.25° steps).
Result of temperature measurement. Die temperature in °C, 2's complement format, 0.25 °C steps.
Decision point: DATARDY
4. Enable TASKS_STOP Register to Stop temperature measurement.

![alt text](https://hackster.imgix.net/uploads/attachments/1518136/8_tJuwoRM3dI.JPG?auto=compress%2Cformat&w=740&h=555&fit=max)

You must check out [PCBWAY](https://www.pcbway.com/) for ordering PCBs online for cheap!

You get 10 good-quality PCBs manufactured and shipped to your doorstep for cheap. You will also get a discount on shipping on your first order. Upload your Gerber files onto PCBWAY to get them manufactured with good quality and quick turnaround time. [PCBWay](https://www.pcbway.com/) now could provide a complete product solution, from design to enclosure production. Check out their online Gerber viewer function. With reward points, you can get free stuff from their gift shop.
