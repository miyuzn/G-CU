# G-CU
## Contents
 - [Working Status](#working-status)
 - [Data Format](#data-format)
 - [Attention](#attention)

## Working Status

| Indicator    | Status                         | Meaning                                            |
| ------------ | ------------------------------ | -------------------------------------------------- |
| LED1         | Red                            | System is powered on     |
|              | Off                            | System is powered off    |
| LED2         | Green                          | Battery is charging      |
|              | Off                            | Battery is fully charged / Battery not installed   |
| RGB LED (U6) | Off                            | System is powered off / System is initializing     |
|              | White                          | Unable to Init the IMU Sensor |
|              | Red-Green-Blue (Cycle)         | System is starting / Low Battery     |
|              | Red                            | Connecting to WiFi / Unable to connect to WiFi  |
|              | Red (Blink)                    | Unable to set RTC     |
|              | Cyan                           | Setting RTC using NTP Server    |
|              | Cyan (Blink 3 Times)           | Unable to set RTC from NTP Server / Setting RTC using extern Chip(BQ32002)   |
|              | Yellow                         | Waitting for transfer data / [TCP Mode]Waiting for connect to TCP Server |
|              | Green                          | Transferring data   |



## Data Format(Little-endian)

### Four_Bytes_Sensors_Data
<table>
 <tr>
  <th colspan="2">START</th>
  <th>DN</th>
  <th>SN</th>
  <th colspan="4">TIME</th>
  <th colspan="2">TIMEMS</th>
  <th colspan="4">S_1</th>
 </tr>
 <tr>
  <td>0x5a</td>
  <td>0x5a</td>
  <td>0x00</td>
  <td>0x04</td>
  <td>0x64</td>
  <td>0xac</td>
  <td>0xd6</td>
  <td>0xe1</td>
  <td>0x01</td>
  <td>0xf4</td>
  <td>0x30</td>
  <td>0x8e</td>
  <td>0x00</td>
  <td>0x00</td>
 </tr>
 <tr>
  <th colspan="4">S_...</th>
  <th colspan="4">Magnetometer_x</th>
  <th colspan="4">Magnetometer_y</th>
 <tr>
  <td colspan="4" align="center">...</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  
  
 </tr>
 <tr>
  <th colspan="4">Magnetometer_z</th>
  <th colspan="4">Gyroscope_x</th>
  <th colspan="4">Gyroscope_y</th>
 </tr>
 <tr>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
 </tr>
 <tr>
  <th colspan="4">Gyroscope_z</th>
  <th colspan="4">Accelerometer_x</th>
  <th colspan="4">Accelerometer_y</th>
 </tr>
 <tr>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
 </tr>
 <tr>
  <th colspan="4">Accelerometer_z</th>
  <th colspan="2">END</th>
  <th colspan="6"></th>
 </tr>
 <tr>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <th colspan="6"></th>
 </tr>
</table>

### Two_Bytes_Sensors_Data
<table>
 <tr>
  <th colspan="2">START</th>
  <th>DN</th>
  <th>SN</th>
  <th colspan="4">TIME</th>
  <th colspan="2">TIMEMS</th>
  <th colspan="2">S_1</th>
 </tr>
 <tr>
  <td>0x5a</td>
  <td>0x5a</td>
  <td>0x00</td>
  <td>0x04</td>
  <td>0x64</td>
  <td>0xac</td>
  <td>0xd6</td>
  <td>0xe1</td>
  <td>0x01</td>
  <td>0xf4</td>
  <td>0x30</td>
  <td>0x8e</td>
 </tr>
 <tr>
  <th colspan="2">S_2</th>
  <th colspan="2">S_...</th>
  <th colspan="4">Magnetometer_x</th>
  <th colspan="4">Magnetometer_y</th>
 <tr>
  <td>0x31</td>
  <td>0x66</td>
  <td colspan="2" align="center">...</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  
  
 </tr>
 <tr>
  <th colspan="4">Magnetometer_z</th>
  <th colspan="4">Gyroscope_x</th>
  <th colspan="4">Gyroscope_y</th>
 </tr>
 <tr>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
 </tr>
 <tr>
  <th colspan="4">Gyroscope_z</th>
  <th colspan="4">Accelerometer_x</th>
  <th colspan="4">Accelerometer_y</th>
 </tr>
 <tr>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
 </tr>
 <tr>
  <th colspan="4">Accelerometer_z</th>
  <th colspan="2">END</th>
  <th colspan="6"></th>
 </tr>
 <tr>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0x0b</td>
  <td>0xb8</td>
  <td>0xa5</td>
  <td>0xa5</td>
  <th colspan="6"></th>
 </tr>
</table>

### Fields of the Data Packet
| Field Name        | Size (Bytes) | Description                                         |
| ----------------- | ------------ | -------------------------------------------------- |
| START             | 2            | Two 0x5a identifying the packet    |
| DN                | 1            | Device NO.    |
| SN                | 1            | Total number of the Pressure Sensors      |
| TIME              | 4            | Unix Time   |
| TIMEMS            | 2            | Million Seconds     |
| S_***x***         | 4 or 2       | Value of the Pressure Sensor NO. ***x***    |
| Magnetometer_xyz  | 12           | Value of the Magnetometer_xyz(Float)  |
| Gyroscope_xyz     | 12           | Value of the Gyroscope_xyz(Float)  |
| Accelerometer_xyz | 12           | Value of the Accelerometer_xyz(Float)  |
| END               | 2            | Two 0xa5 ending the packet   |

\* The packet format can be customized by [changing the value of the function flag](Arduino/README.md#function-flag).

### IO port(Chip on top)(board v2.0.B)
| Left(2 pin)       | Right(2 pin)      |
| ----------------- | ----------------- |
| GPIO1(GIN0)       | GPIO7(GIN6)       |
| GPIO2(GIN1)       | GPIO19            |
| GPIO3(GIN2)       | GPIO20            |
| GPIO4(GIN3)       | GPIO21            |
| GPIO5(GIN4)       | GPIO35            |
| GPIO6(GIN5)       | GPIO36            |

\* Please change the value of analogReadIO[] and SelectIO[] in [Conector IO](Arduino/README.md#conector-io).



## Attention
### For code v2.0
Due to changes in IMU sensor, the following matters need to be noted.
 - New Library in Arduino must be installed, please check [Arduino Library](Arduino/README.md#arduino-library).

### For board v2.0.B
Due to changes in IMU sensors and the removal of the RTC chip, the following matters need to be noted.
- When using [code v2.0](Arduino/v2.0/README.md), the value of IMU_chip must set to GCU_BMI270_BMM150.
- When using [code v2.0](Arduino/v2.0/README.md), the value of RTC_chip must set to GCU_FLAG_OFF.
- IF you need 2 bytes sensors data, please set the value of sensors_dataformat_define to Two_Bytes_Sensors_Data in [code v2.0](Arduino/v2.0/README.md).
- It is not recommended to use versions of the code earlier than [code v2.0](Arduino/v2.0/README.md).


### For board v1.0
Due to I2C Address Conflict, the following matters need to be noted.
 - If you want to use IMU Sensor, board v1.0 must update to [board v1.1](PCB%20Design/README.md) （Contact YU） or board v1.0.R.
 - If you choose to remove the RTC chip, you need to disable the RTC Function from [code v1.1](Arduino/v1.1/README.md).
 - If you want to use the board v1.0(Don't use IMU Sensor), you need to set the IMU_flag to 0 using [code v1.1](Arduino/v1.1/README.md).

### For code v1.0
Due to data structure, the following matters need to be noted.
 - Now all data transmission changed to Little-endian.

### For board v0.0 or v0.1
Due to issues such as hardware design, the following matters need to be noted.
 - GPIO38 (In the middle of U11) cannot be used.
 - Switch status is negetive.


