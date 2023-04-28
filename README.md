# Orange Pi 5: Treshold Fan Control
The repo is based on: https://github.com/bastilmr/opi5-fan-control

This script written in C language reads the CPU temperature and toggle the fan based on that information. Before the script can work, wiringOP needs to be downloaded and installed from Git to enable the use of GPIO pins. Additionally, the script needs to be compiled after it's downloaded.

## Requirements

- Orange Pi 5
- wiringOP (https://github.com/orangepi-xunlong/wiringOP.git)
- 5V Fan (e.g. Noctua)
- PNP/NPN transistor

## Installation

1. Download wiringOP from Git:
```
git clone --branch next https://github.com/orangepi-xunlong/wiringOP.git
```

2. Navigate to the wiringOP directory and run the installation command:
```
cd wiringOP
./build clean
./build
```

3. Download the C script and save it to the directory of your choice.
```
git clone https://github.com/ASDosjani/opi5-fan-control.git
```

4. Compile the script using the following command:
```
gcc -o fan-control fan-control.c -lwiringPi
```

5. Make the script executable:
```
chmod +x fan-control
```

6. Add the script to your crontab to run at boot using the following command:
```
crontab -e
```

7. Add the following line to your crontab to run the script at boot:
```
@reboot /path/to/fan-control
```

Be sure to replace `/path/to/` with the actual path to the directory where the script is located.

## Configuration

You can customize the configuration to your needs by changing the following variables in the script:

- `FAN_PIN`: The GPIO pin where the fan is connected.
- `CPU_TEMP_FILE`: The file that contains the CPU temperature.
- `THRESHOLD_TEMP`: The minimum CPU temperature at which the fan start spinning.
- `PNP`: 1 if PNP transistor used, 0 if NPN

In this example, the fan 5V pin was connected to 5V on OPi, Ground to a BC327 emitter pin, collector to Ground and base to GPIO4_A3 (UART0_TX_M2) Pin of the Orange Pi 5. Like in the picture:

![image](https://user-images.githubusercontent.com/62965528/235144283-13e8825a-af22-48e3-85d1-1ecaf23eeb8a.png)

## Note

This script has been successfully tested on an Orange Pi 5. However, it should also work on other Orange Pi's.
I use this small fan included with the heatsink like this:

![IMG_20230428_141843](https://user-images.githubusercontent.com/62965528/235149194-7ac6dd79-4b05-42cf-96f8-d6e418e68895.jpg)
